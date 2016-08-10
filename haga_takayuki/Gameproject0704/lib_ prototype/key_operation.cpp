/**
@file key_operation.cpp
@brief DirectInput初期化関数な、及び操作関連関数をまとめているcppファイルです.
@author 芳我貴之
@data 2016/06/18
*/
#include <dinput.h>
#include"key_operation.h"



/*
以下をMAIN.cppのソースに追加
LPDIRECTINPUT8 g_pDInput = NULL; //DirectInput生成

LPDIRECTINPUTDEVICE8 g_pkeyDevice = NULL;//デバイス生成
*/

//DirectInputの初期化関数
HRESULT InitDinput(HWND hWnd, LPDIRECTINPUT8* g_pDInput, LPDIRECTINPUTDEVICE8* g_pkeyDevice)
{
	HRESULT hr;

	//オブジェクト作成
	if(FAILED(DirectInput8Create(
		GetModuleHandle(NULL),	// インスタンス ハンドル
		DIRECTINPUT_VERSION,	// DirectInputのバージョ2ン
		IID_IDirectInput8,				// 取得インターフェイスのタイプ
		(VOID**)&(*g_pDInput),			// インターフェイスポインタ
		NULL)))					// 使わない
	{
		return FALSE;
	}

	//デバイス作成
	if(FAILED((*g_pDInput)->CreateDevice(
		GUID_SysKeyboard,	// キーボードを受け付ける
		&(*g_pkeyDevice),		// IDirectInputDevice8ポインタ
		NULL)))			// 使わない
	{
		return FALSE;
	}

				// デバイスをキーボードに設定
	if(FAILED(hr = (*g_pkeyDevice)->SetDataFormat(&c_dfDIKeyboard)))
	{
		return FALSE;
	}


	//協調レベル設定
	if(FAILED(hr = (*g_pkeyDevice)->SetCooperativeLevel(
		hWnd,	// ウィンドウハンドル
		DISCL_NONEXCLUSIVE | DISCL_BACKGROUND)))	// 協調レベル
	{
		return FALSE;
	}


	(*g_pkeyDevice)->Acquire();

	return S_OK;
}




//DIKを格納する変数
BYTE diks[256];

//キー状態のチェック関数

//キーの種類格納変数
KEYSTATE Key[KEYMAX];
//押す前の状態
int PreKey[KEYMAX] = { 0 };

/*以下のソースをメインにかく

アクセス権が獲得されているか再度確認
HRESULT hr = g_pkeyDevice->Acquire();
if ((hr == DI_OK) || (hr == S_FALSE))
{
	g_pkeyDevice->GetDeviceState(sizeof(diks), &diks);
*/

//キー状態確認関数
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
