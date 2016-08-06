/**
 * @file Direct_Key_Input.cpp
 * @brief DirectX�̃L�[����Ɋ֌W����֐��̒��g
 * @author �ēc�N��
 * @date 2016�N7��1��
 */

#define DIRECTINPUT_VERSION 0x0800

#include <dinput.h>
#include "Direct_Key_Input.h"

static LPDIRECTINPUT8		    g_pDinput = NULL;					///< DirectInput�̃I�u�W�F�N�g�̃|�C���^
static LPDIRECTINPUTDEVICE8		g_pKeyDevice = NULL;				///< DirectInput�f�o�C�X�E�I�u�W�F�N�g�̃|�C���^
static BYTE						g_Diks[256];						///< DirectInput�ɓ��͏����i�[���Ă���
static int						g_PreKey[KEYMAX] = { 0 };			///< KEYKIND�Ɋi�[����Ă��钆�̉��������ꂽ���̊m�F
KEYSTATE						g_Key[KEYMAX];						///< KEYSTATE��KEYKIND�̑S�Ă�z��Ƃ��Ċi�[���Ă���

// �_�C���N�g�C���v�b�g�̏������֐�
HRESULT Init_Direct_Input(HWND _hWnd)
{
	HRESULT hr;

	// DirectInput�̃I�u�W�F�N�g�̐���
	if (FAILED(hr = DirectInput8Create(
		GetModuleHandle(NULL),
		DIRECTINPUT_VERSION,
		IID_IDirectInput8, 
		(VOID**)&g_pDinput, NULL)))
	{
		MessageBox(NULL, "�I�u�W�F�N�g�͂������ł��܂���ł����B", NULL, MB_OK);

		return hr;
	}

	// DirectInput�̃f�o�C�X�̃I�u�W�F�N�g�̐���
	if (FAILED(hr = g_pDinput->CreateDevice(
		GUID_SysKeyboard,
		&g_pKeyDevice,
		NULL)))
	{
		MessageBox(NULL, "�f�o�C�X�̃I�u�W�F�N�g�������ł��܂���ł����B", NULL, MB_OK);

		return hr;
	}

	// �f�o�C�X���L�[�{�[�h�ɐݒ�
	if (FAILED(hr = g_pKeyDevice->SetDataFormat(&c_dfDIKeyboard)))
	{
		MessageBox(NULL, "�f�o�C�X���L�[�{�[�h�ɐݒ�ł��܂���ł����B", NULL, MB_OK);

		return hr;
	}

	// �������x���̐ݒ�
	if (FAILED(hr = g_pKeyDevice->SetCooperativeLevel(
		_hWnd, DISCL_NONEXCLUSIVE | DISCL_BACKGROUND)))
	{
		MessageBox(NULL, "�������x�����ݒ�ł��܂���ł����B", NULL, MB_OK);
		return hr;
	}

	// �f�o�C�X���擾����
	g_pKeyDevice->Acquire();
	return S_OK;
}

// �L�[�̏�Ԃ��擾���Ă���
void Get_Key_State()
{
	HRESULT hr = g_pKeyDevice->Acquire();
	if ((hr == DI_OK) || (hr == S_FALSE))
	{
		g_pKeyDevice->GetDeviceState(sizeof(g_Diks), &g_Diks);
	}
}

// ������Ă���L�[�̊m�F
void Check_Key(int _dik, KEYKIND _st)
{

	if ((g_Diks[_dik] & 0x80))			// �擪�r�b�g�������Ă��邩�`�F�b�N���Ă���
	{
		if (g_PreKey[_st] == 0)
		{
			g_Key[_st] = PUSH;			// ��u����������
		}
		else
		{
			g_Key[_st] = ON;			// ���������Ă���
		}
		g_PreKey[_st] = 1;
	}
	else
	{
		if (g_PreKey[_st] == 0)
		{
			g_Key[_st] = OFF;			// ���������Ă���
		}
		else
		{
			g_Key[_st] = RELEASE;		// ��u����������
		}
		g_PreKey[_st] = 0;
	}
}

// ����֐�
void Key_Free()
{
	g_pKeyDevice->Release();
	g_pDinput->Release();
}