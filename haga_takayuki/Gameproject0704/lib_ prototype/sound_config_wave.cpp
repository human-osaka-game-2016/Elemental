/**
*@file sound_config_wave.cpp
*@brief Wave形式のサウンドを使用する為の関数をまとめているcppファイルです.
*@attention waveファイルのみ対応
*@author 芳我貴之
*@date 2016/06/25
*/
#include <dsound.h>
#include <dshow.h>
#include"config.h"
#include"sound_config_wave.h"

/*
ライブラリ
#pragma comment ( lib, "dxguid.lib" )
#pragma comment ( lib, "dsound.lib" )
#pragma comment	(lib,"strmiids.lib")
*/




//--------------------------------------------------------------------------------
//
//DirectSoundを使用しての音楽再生
//こちらの関数はwaveファイルのみ再生可能
//下記OpenWaveとSoundWave関数はセットで運用すること
//
//--------------------------------------------------------------------------------

/*
以下の変数をメインに書く
WAVEFORMATEX wFmt; waveの構造体
char *pwaveData = 0; 波形データを格納する変数
DWORD dataSize = 0; waveデータのサイズを格納する変数
*/


// waveファイルオープン関数
int OpenWave(TCHAR* filepath, WAVEFORMATEX* waveFormatEx, char** pwaveData, DWORD* dataSize)
{
	if (filepath == 0)
		return false;

	HMMIO hMmio = NULL;
	MMIOINFO mmioInfo;

	// waveファイルオープン
	memset(&mmioInfo, 0, sizeof(MMIOINFO));
	hMmio = mmioOpen(filepath, &mmioInfo, MMIO_READ);
	if (!hMmio)
		return false; // ファイルオープン失敗

	// RIFFチャンク検索
	MMRESULT mmRes;
	MMCKINFO riffChunk;
	riffChunk.fccType = mmioFOURCC('W', 'A', 'V', 'E');
	mmRes = mmioDescend(hMmio, &riffChunk, NULL, MMIO_FINDRIFF);
	if (mmRes != MMSYSERR_NOERROR) {
		mmioClose(hMmio, 0);
		return false;
	}

	// フォーマットチャンク検索
	MMCKINFO formatChunk;
	formatChunk.ckid = mmioFOURCC('f', 'm', 't', ' ');
	mmRes = mmioDescend(hMmio, &formatChunk, &riffChunk, MMIO_FINDCHUNK);
	if (mmRes != MMSYSERR_NOERROR) {
		mmioClose(hMmio, 0);
		return false;
	}
	DWORD fmsize = formatChunk.cksize;
	DWORD size = mmioRead(hMmio, (HPSTR)waveFormatEx, fmsize);
	if (size != fmsize) {
		mmioClose(hMmio, 0);
		return false;
	}

	mmioAscend(hMmio, &formatChunk, 0);

	// データチャンク検索
	MMCKINFO dataChunk;
	dataChunk.ckid = mmioFOURCC('d', 'a', 't', 'a');
	mmRes = mmioDescend(hMmio, &dataChunk, &riffChunk, MMIO_FINDCHUNK);
	if (mmRes != MMSYSERR_NOERROR) {
		mmioClose(hMmio, 0);
		return false;
	}
	*pwaveData = new char[dataChunk.cksize];
	size = mmioRead(hMmio, (HPSTR)*pwaveData, dataChunk.cksize);
	if (size != dataChunk.cksize) {
		delete[] * pwaveData;
		return false;
	}
	*dataSize = size;

	// ハンドルクローズ
	mmioClose(hMmio, 0);

	return true;
}
//サウンドデバイス作成&セカンダリバッファにWaveデータ書き込み&再生 playback_methodは再生方法(例：DSBPLAY_LOOPING)
void SoundWave(HWND hWnd, char** pwaveData, DWORD* dataSize, WAVEFORMATEX* waveFormatEx, int playback_method)
{
	IDirectSound8 *pDS8;
	DirectSoundCreate8(NULL, &pDS8, NULL);
	//協調レベル設定
	pDS8->SetCooperativeLevel(hWnd, DSSCL_NORMAL);

	//セカンダリバッファ作成
	DSBUFFERDESC DSBufferDesc;

	DSBufferDesc.dwSize = sizeof(DSBUFFERDESC);
	DSBufferDesc.dwFlags = 0;
	DSBufferDesc.dwBufferBytes = *dataSize;
	DSBufferDesc.dwReserved = 0;
	DSBufferDesc.lpwfxFormat = waveFormatEx;
	DSBufferDesc.guid3DAlgorithm = GUID_NULL;


	IDirectSoundBuffer *ptmpBuf = 0;
	IDirectSoundBuffer8 *pDSBuffer;
	pDS8->CreateSoundBuffer(&DSBufferDesc, &ptmpBuf, NULL);
	ptmpBuf->QueryInterface(IID_IDirectSoundBuffer8, (void**)&pDSBuffer);
	ptmpBuf->Release();

	// セカンダリバッファにWaveデータ書き込み
	LPVOID lpvWrite = 0;
	DWORD dwLength = 0;
	if (DS_OK == pDSBuffer->Lock(0, 0, &lpvWrite, &dwLength, NULL, NULL, DSBLOCK_ENTIREBUFFER)) {
		memcpy(lpvWrite, *pwaveData, dwLength);
		pDSBuffer->Unlock(lpvWrite, dwLength, NULL, 0);
	}

	pDSBuffer->Play(0, 0, playback_method);
}