/**
* @file Direct_Sound.cpp
* @brief DirectXのサウンドに関係する関数の中身を書いている
* @brief Waveファイルを再生するときだけに使える
* @author 柴田哲良
* @date 2016年7月2日
*/

#include <tchar.h>
#include "Direct_Sound.h"


#pragma comment ( lib, "dxguid.lib" )
#pragma comment ( lib, "dsound.lib" )

static IDirectSound8*			g_pDsound8 = NULL;			///< サウンドデバイスのポインタ

// Waveファイルオープン関数
bool Open_Wave(TCHAR* _filename, WAVEFORMATEX* _waveFormat, char** _ppData, DWORD* _dataSize) 
{
	// 音声ファイルの名前
	if (_filename == 0)
	{
		return false;
	}

	HMMIO hmmio = NULL;
	MMIOINFO mmioinfo;			//ファイルをオープンするときはゼロで初期化して渡す必要がある

	// Waveファイルオープン
	memset(&mmioinfo, NULL, sizeof(MMIOINFO));
	hmmio = mmioOpen(_filename, &mmioinfo, MMIO_READ);
	if (!hmmio)
	{
		MessageBox(NULL, "ファイルのオープンに失敗しました。", NULL, MB_ICONWARNING);
		return false; // ファイルオープン失敗
	}

	// RIFFチャンク検索
	MMRESULT mmres;
	MMCKINFO riffchunk;
	riffchunk.fccType = mmioFOURCC('W', 'A', 'V', 'E');
	mmres = mmioDescend(hmmio, &riffchunk, NULL, MMIO_FINDRIFF);
	if (mmres != MMSYSERR_NOERROR) 
	{
		mmioClose(hmmio, 0);
		return false;
	}

	// フォーマットチャンク検索
	MMCKINFO formatchunk;
	formatchunk.ckid = mmioFOURCC('f', 'm', 't', ' ');
	mmres = mmioDescend(hmmio, &formatchunk, &riffchunk, MMIO_FINDCHUNK);
	if (mmres != MMSYSERR_NOERROR)
	{
		mmioClose(hmmio, 0);
		return false;
	}
	DWORD fmsize = formatchunk.cksize;
	DWORD size = mmioRead(hmmio, (HPSTR)_waveFormat, fmsize);
	if (size != fmsize)
	{
		mmioClose(hmmio, 0);
		return false;
	}

	mmioAscend(hmmio, &formatchunk, 0);

	// データチャンク検索
	MMCKINFO datachunk;
	datachunk.ckid = mmioFOURCC('d', 'a', 't', 'a');
	mmres = mmioDescend(hmmio, &datachunk, &riffchunk, MMIO_FINDCHUNK);
	if (mmres != MMSYSERR_NOERROR)
	{
		mmioClose(hmmio, 0);
		return false;
	}
	*_ppData = new char[datachunk.cksize];
	size = mmioRead(hmmio, (HPSTR)*_ppData, datachunk.cksize);
	if (size != datachunk.cksize) 
	{
		delete[] *_ppData;
		return false;
	}
	*_dataSize = size;

	// ハンドルクローズ
	mmioClose(hmmio, 0);

	return true;
}


// サウンドオブジェクトの生成
HRESULT Init_Sound_Device(HWND _hWnd)
{

	if (FAILED(DirectSoundCreate8(NULL, &g_pDsound8, NULL)))			// オブジェクトの生成と初期化
	{
		MessageBox(NULL, "オブジェクトが生成できませんでした。", NULL, MB_OK);
		return E_FAIL;
	}
	if (FAILED(g_pDsound8->SetCooperativeLevel(_hWnd, DSSCL_PRIORITY)))		// 協調レベルの設定
	{
		MessageBox(NULL, "協調レベルが設定できませんでした。", NULL, MB_OK);
		return E_FAIL;
	}

	return S_OK;
}

// サウンドバッファの生成
HRESULT Create_Sound_Buffer(TCHAR* _filename, IDirectSoundBuffer8** _ppDSBuffer)
{
	WAVEFORMATEX waveformat;
	char *pwavedata = 0;
	DWORD wavesize = 0;
	if (!Open_Wave(_T(_filename), &waveformat, &pwavedata, &wavesize))
	{
		return E_FAIL;
	}

	DSBUFFERDESC			DSBufferDesc;				// 新しいバッファオブジェクトの特性を書いておく構造体
	DSBufferDesc.dwSize = sizeof(DSBUFFERDESC);
	DSBufferDesc.dwFlags = 0;
	DSBufferDesc.dwBufferBytes = wavesize;
	DSBufferDesc.dwReserved = 0;						//0でなければならない
	DSBufferDesc.lpwfxFormat = &waveformat;				//WAVEFORMATEXのアドレス
	DSBufferDesc.guid3DAlgorithm = GUID_NULL;			//デフォルトのアルゴリズムを使う

	IDirectSoundBuffer*		ptempBuf = NULL;			// プライマリバッファの場合は使う必要がある
	g_pDsound8->CreateSoundBuffer(&DSBufferDesc, &ptempBuf, NULL);
	ptempBuf->QueryInterface(IID_IDirectSoundBuffer8, (void**)_ppDSBuffer);
	ptempBuf->Release();

	// セカンダリバッファにWaveデータ書き込み
	LPVOID lpvwrite = NULL;
	DWORD dwlength = NULL;
	if (DS_OK == (*_ppDSBuffer)->Lock(0, 0, &lpvwrite, &dwlength, NULL, NULL, DSBLOCK_ENTIREBUFFER))
	{
		memcpy(lpvwrite, pwavedata, dwlength);
		(*_ppDSBuffer)->Unlock(lpvwrite, dwlength, NULL, 0);
	}

	return S_OK;
}

// サウンドの解放関数
void Sound_Free()
{
	g_pDsound8->Release();
}