/**
*@file sound_config_wave.cpp
*@brief Wave�`���̃T�E���h���g�p����ׂ̊֐����܂Ƃ߂Ă���cpp�t�@�C���ł�.
*@attention wave�t�@�C���̂ݑΉ�
*@author �F��M�V
*@date 2016/06/25
*/
#include <dsound.h>
#include <dshow.h>
#include"config.h"
#include"sound_config_wave.h"

/*
���C�u����
#pragma comment ( lib, "dxguid.lib" )
#pragma comment ( lib, "dsound.lib" )
#pragma comment	(lib,"strmiids.lib")
*/




//--------------------------------------------------------------------------------
//
//DirectSound���g�p���Ẳ��y�Đ�
//������̊֐���wave�t�@�C���̂ݍĐ��\
//���LOpenWave��SoundWave�֐��̓Z�b�g�ŉ^�p���邱��
//
//--------------------------------------------------------------------------------

/*
�ȉ��̕ϐ������C���ɏ���
WAVEFORMATEX wFmt; wave�̍\����
char *pwaveData = 0; �g�`�f�[�^���i�[����ϐ�
DWORD dataSize = 0; wave�f�[�^�̃T�C�Y���i�[����ϐ�
*/


// wave�t�@�C���I�[�v���֐�
int OpenWave(TCHAR* filepath, WAVEFORMATEX* waveFormatEx, char** pwaveData, DWORD* dataSize)
{
	if (filepath == 0)
		return false;

	HMMIO hMmio = NULL;
	MMIOINFO mmioInfo;

	// wave�t�@�C���I�[�v��
	memset(&mmioInfo, 0, sizeof(MMIOINFO));
	hMmio = mmioOpen(filepath, &mmioInfo, MMIO_READ);
	if (!hMmio)
		return false; // �t�@�C���I�[�v�����s

	// RIFF�`�����N����
	MMRESULT mmRes;
	MMCKINFO riffChunk;
	riffChunk.fccType = mmioFOURCC('W', 'A', 'V', 'E');
	mmRes = mmioDescend(hMmio, &riffChunk, NULL, MMIO_FINDRIFF);
	if (mmRes != MMSYSERR_NOERROR) {
		mmioClose(hMmio, 0);
		return false;
	}

	// �t�H�[�}�b�g�`�����N����
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

	// �f�[�^�`�����N����
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

	// �n���h���N���[�Y
	mmioClose(hMmio, 0);

	return true;
}
//�T�E���h�f�o�C�X�쐬&�Z�J���_���o�b�t�@��Wave�f�[�^��������&�Đ� playback_method�͍Đ����@(��FDSBPLAY_LOOPING)
void SoundWave(HWND hWnd, char** pwaveData, DWORD* dataSize, WAVEFORMATEX* waveFormatEx, int playback_method)
{
	IDirectSound8 *pDS8;
	DirectSoundCreate8(NULL, &pDS8, NULL);
	//�������x���ݒ�
	pDS8->SetCooperativeLevel(hWnd, DSSCL_NORMAL);

	//�Z�J���_���o�b�t�@�쐬
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

	// �Z�J���_���o�b�t�@��Wave�f�[�^��������
	LPVOID lpvWrite = 0;
	DWORD dwLength = 0;
	if (DS_OK == pDSBuffer->Lock(0, 0, &lpvWrite, &dwLength, NULL, NULL, DSBLOCK_ENTIREBUFFER)) {
		memcpy(lpvWrite, *pwaveData, dwLength);
		pDSBuffer->Unlock(lpvWrite, dwLength, NULL, 0);
	}

	pDSBuffer->Play(0, 0, playback_method);
}