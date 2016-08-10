/**
@file key_operation.cpp
@brief DirectInput�������֐��ȁA�y�ё���֘A�֐����܂Ƃ߂Ă���cpp�t�@�C���ł�.
@author �F��M�V
@data 2016/06/18
*/
#include <dinput.h>
#include"key_operation.h"



/*
�ȉ���MAIN.cpp�̃\�[�X�ɒǉ�
LPDIRECTINPUT8 g_pDInput = NULL; //DirectInput����

LPDIRECTINPUTDEVICE8 g_pkeyDevice = NULL;//�f�o�C�X����
*/

//DirectInput�̏������֐�
HRESULT InitDinput(HWND hWnd, LPDIRECTINPUT8* g_pDInput, LPDIRECTINPUTDEVICE8* g_pkeyDevice)
{
	HRESULT hr;

	//�I�u�W�F�N�g�쐬
	if(FAILED(DirectInput8Create(
		GetModuleHandle(NULL),	// �C���X�^���X �n���h��
		DIRECTINPUT_VERSION,	// DirectInput�̃o�[�W��2��
		IID_IDirectInput8,				// �擾�C���^�[�t�F�C�X�̃^�C�v
		(VOID**)&(*g_pDInput),			// �C���^�[�t�F�C�X�|�C���^
		NULL)))					// �g��Ȃ�
	{
		return FALSE;
	}

	//�f�o�C�X�쐬
	if(FAILED((*g_pDInput)->CreateDevice(
		GUID_SysKeyboard,	// �L�[�{�[�h���󂯕t����
		&(*g_pkeyDevice),		// IDirectInputDevice8�|�C���^
		NULL)))			// �g��Ȃ�
	{
		return FALSE;
	}

				// �f�o�C�X���L�[�{�[�h�ɐݒ�
	if(FAILED(hr = (*g_pkeyDevice)->SetDataFormat(&c_dfDIKeyboard)))
	{
		return FALSE;
	}


	//�������x���ݒ�
	if(FAILED(hr = (*g_pkeyDevice)->SetCooperativeLevel(
		hWnd,	// �E�B���h�E�n���h��
		DISCL_NONEXCLUSIVE | DISCL_BACKGROUND)))	// �������x��
	{
		return FALSE;
	}


	(*g_pkeyDevice)->Acquire();

	return S_OK;
}




//DIK���i�[����ϐ�
BYTE diks[256];

//�L�[��Ԃ̃`�F�b�N�֐�

//�L�[�̎�ފi�[�ϐ�
KEYSTATE Key[KEYMAX];
//�����O�̏��
int PreKey[KEYMAX] = { 0 };

/*�ȉ��̃\�[�X�����C���ɂ���

�A�N�Z�X�����l������Ă��邩�ēx�m�F
HRESULT hr = g_pkeyDevice->Acquire();
if ((hr == DI_OK) || (hr == S_FALSE))
{
	g_pkeyDevice->GetDeviceState(sizeof(diks), &diks);
*/

//�L�[��Ԋm�F�֐�
void KeyCheck(BYTE DIK, KEYKIND st)
{
	if (DIK & 0x80)
	{
		if (PreKey[st] == 0)
		{
			Key[st] = PUSH;
		}
		else
		{
			Key[st] = ON;
		}
		PreKey[st] = 1;
	}
	else
	{
		if (PreKey[st] == 0)
		{
			Key[st] = OFF;
		}
		else
		{
			Key[st] = RELEASE;
		}
		PreKey[st] = 0;
	}
}
