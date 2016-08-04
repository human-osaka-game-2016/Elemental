/**
 * @file Direct_Key_Input.cpp
 * @brief DirectXのキー操作に関係する関数の中身
 * @author 柴田哲良
 * @date 2016年7月1日
 */

#define DIRECTINPUT_VERSION 0x0800

#include <dinput.h>
#include "Direct_Key_Input.h"

static LPDIRECTINPUT8		    g_pDinput = NULL;					///< DirectInputのオブジェクトのポインタ
static LPDIRECTINPUTDEVICE8		g_pKeyDevice = NULL;				///< DirectInputデバイス・オブジェクトのポインタ
static BYTE						g_Diks[256];						///< DirectInputに入力情報を格納している
static int						g_PreKey[KEYMAX] = { 0 };			///< KEYKINDに格納されている中の何が押されたかの確認
KEYSTATE						g_Key[KEYMAX];						///< KEYSTATEにKEYKINDの全てを配列として格納している

// ダイレクトインプットの初期化関数
HRESULT Init_Direct_Input(HWND _hWnd)
{
	HRESULT hr;

	// DirectInputのオブジェクトの生成
	if (FAILED(hr = DirectInput8Create(
		GetModuleHandle(NULL),
		DIRECTINPUT_VERSION,
		IID_IDirectInput8, 
		(VOID**)&g_pDinput, NULL)))
	{
		MessageBox(NULL, "オブジェクトはが生成できませんでした。", NULL, MB_OK);

		return hr;
	}

	// DirectInputのデバイスのオブジェクトの生成
	if (FAILED(hr = g_pDinput->CreateDevice(
		GUID_SysKeyboard,
		&g_pKeyDevice,
		NULL)))
	{
		MessageBox(NULL, "デバイスのオブジェクトが生成できませんでした。", NULL, MB_OK);

		return hr;
	}

	// デバイスをキーボードに設定
	if (FAILED(hr = g_pKeyDevice->SetDataFormat(&c_dfDIKeyboard)))
	{
		MessageBox(NULL, "デバイスをキーボードに設定できませんでした。", NULL, MB_OK);

		return hr;
	}

	// 協調レベルの設定
	if (FAILED(hr = g_pKeyDevice->SetCooperativeLevel(
		_hWnd, DISCL_NONEXCLUSIVE | DISCL_BACKGROUND)))
	{
		MessageBox(NULL, "協調レベルが設定できませんでした。", NULL, MB_OK);
		return hr;
	}

	// デバイスを取得する
	g_pKeyDevice->Acquire();
	return S_OK;
}

// キーの状態を取得している
void Get_Key_State()
{
	HRESULT hr = g_pKeyDevice->Acquire();
	if ((hr == DI_OK) || (hr == S_FALSE))
	{
		g_pKeyDevice->GetDeviceState(sizeof(g_Diks), &g_Diks);
	}
}

// 押されているキーの確認
void Check_Key(int _dik, KEYKIND _st)
{

	if ((g_Diks[_dik] & 0x80))			// 先頭ビットがたっているかチェックしている
	{
		if (g_PreKey[_st] == 0)
		{
			g_Key[_st] = PUSH;			// 一瞬だけ押した
		}
		else
		{
			g_Key[_st] = ON;			// 押し続けている
		}
		g_PreKey[_st] = 1;
	}
	else
	{
		if (g_PreKey[_st] == 0)
		{
			g_Key[_st] = OFF;			// 離し続けている
		}
		else
		{
			g_Key[_st] = RELEASE;		// 一瞬だけ離した
		}
		g_PreKey[_st] = 0;
	}
}

// 解放関数
void Key_Free()
{
	g_pKeyDevice->Release();
	g_pDinput->Release();
}