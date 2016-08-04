/**
* @file Direct_Sound.cpp
* @brief DirectX�̃T�E���h�Ɋ֌W����֐��̒��g�������Ă���
* @brief Wave�t�@�C�����Đ�����Ƃ������Ɏg����
* @author �ēc�N��
* @date 2016�N7��2��
*/

#include <tchar.h>
#include "Direct_Sound.h"


#pragma comment ( lib, "dxguid.lib" )
#pragma comment ( lib, "dsound.lib" )

static IDirectSound8*			g_pDsound8 = NULL;			///< �T�E���h�f�o�C�X�̃|�C���^

// Wave�t�@�C���I�[�v���֐�
bool Open_Wave(TCHAR* _filename, WAVEFORMATEX* _waveFormat, char** _ppData, DWORD* _dataSize) 
{
	// �����t�@�C���̖��O
	if (_filename == 0)
	{
		return false;
	}

	HMMIO hmmio = NULL;
	MMIOINFO mmioinfo;			//�t�@�C�����I�[�v������Ƃ��̓[���ŏ��������ēn���K�v������

	// Wave�t�@�C���I�[�v��
	memset(&mmioinfo, NULL, sizeof(MMIOINFO));
	hmmio = mmioOpen(_filename, &mmioinfo, MMIO_READ);
	if (!hmmio)
	{
		MessageBox(NULL, "�t�@�C���̃I�[�v���Ɏ��s���܂����B", NULL, MB_ICONWARNING);
		return false; // �t�@�C���I�[�v�����s
	}

	// RIFF�`�����N����
	MMRESULT mmres;
	MMCKINFO riffchunk;
	riffchunk.fccType = mmioFOURCC('W', 'A', 'V', 'E');
	mmres = mmioDescend(hmmio, &riffchunk, NULL, MMIO_FINDRIFF);
	if (mmres != MMSYSERR_NOERROR) 
	{
		mmioClose(hmmio, 0);
		return false;
	}

	// �t�H�[�}�b�g�`�����N����
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

	// �f�[�^�`�����N����
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

	// �n���h���N���[�Y
	mmioClose(hmmio, 0);

	return true;
}


// �T�E���h�I�u�W�F�N�g�̐���
HRESULT Init_Sound_Device(HWND _hWnd)
{

	if (FAILED(DirectSoundCreate8(NULL, &g_pDsound8, NULL)))			// �I�u�W�F�N�g�̐����Ə�����
	{
		MessageBox(NULL, "�I�u�W�F�N�g�������ł��܂���ł����B", NULL, MB_OK);
		return E_FAIL;
	}
	if (FAILED(g_pDsound8->SetCooperativeLevel(_hWnd, DSSCL_PRIORITY)))		// �������x���̐ݒ�
	{
		MessageBox(NULL, "�������x�����ݒ�ł��܂���ł����B", NULL, MB_OK);
		return E_FAIL;
	}

	return S_OK;
}

// �T�E���h�o�b�t�@�̐���
HRESULT Create_Sound_Buffer(TCHAR* _filename, IDirectSoundBuffer8** _ppDSBuffer)
{
	WAVEFORMATEX waveformat;
	char *pwavedata = 0;
	DWORD wavesize = 0;
	if (!Open_Wave(_T(_filename), &waveformat, &pwavedata, &wavesize))
	{
		return E_FAIL;
	}

	DSBUFFERDESC			DSBufferDesc;				// �V�����o�b�t�@�I�u�W�F�N�g�̓����������Ă����\����
	DSBufferDesc.dwSize = sizeof(DSBUFFERDESC);
	DSBufferDesc.dwFlags = 0;
	DSBufferDesc.dwBufferBytes = wavesize;
	DSBufferDesc.dwReserved = 0;						//0�łȂ���΂Ȃ�Ȃ�
	DSBufferDesc.lpwfxFormat = &waveformat;				//WAVEFORMATEX�̃A�h���X
	DSBufferDesc.guid3DAlgorithm = GUID_NULL;			//�f�t�H���g�̃A���S���Y�����g��

	IDirectSoundBuffer*		ptempBuf = NULL;			// �v���C�}���o�b�t�@�̏ꍇ�͎g���K�v������
	g_pDsound8->CreateSoundBuffer(&DSBufferDesc, &ptempBuf, NULL);
	ptempBuf->QueryInterface(IID_IDirectSoundBuffer8, (void**)_ppDSBuffer);
	ptempBuf->Release();

	// �Z�J���_���o�b�t�@��Wave�f�[�^��������
	LPVOID lpvwrite = NULL;
	DWORD dwlength = NULL;
	if (DS_OK == (*_ppDSBuffer)->Lock(0, 0, &lpvwrite, &dwlength, NULL, NULL, DSBLOCK_ENTIREBUFFER))
	{
		memcpy(lpvwrite, pwavedata, dwlength);
		(*_ppDSBuffer)->Unlock(lpvwrite, dwlength, NULL, 0);
	}

	return S_OK;
}

// �T�E���h�̉���֐�
void Sound_Free()
{
	g_pDsound8->Release();
}