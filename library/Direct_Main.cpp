/**
 * @file Direct_Main.cpp
 * @brief DirectXオブジェクトやデバイスに関係する関数の中身
 * @author 柴田哲良
 * @date 2016年7月1日
*/

#include <d3dx9.h>
#include "Direct_Main.h"
#include "Direct_Draw.h"


static IDirect3D9*				g_pDirect3D = NULL;			///< DirectXオブジェクトのポインタ

// DirectXの初期化関数
HRESULT Init_Direct(HWND _hWnd)
{
	// DirectXオブジェクト生成
	g_pDirect3D = Direct3DCreate9(D3D_SDK_VERSION);		// D3D_SDK_VERSIONは変えてはいけない

	// オブジェクトの生成に成功したかチェック
	if (g_pDirect3D == NULL)
	{
		MessageBox(NULL, "オブジェクトが生成できませんでした。", NULL, MB_OK);
		// 生成に失敗したら終了する
		return E_FAIL;
	}

	// DisplayModeの取得
	D3DDISPLAYMODE			D3DdisplayMode;				// ディスプレイモード
	g_pDirect3D->GetAdapterDisplayMode(					// アダプタの現在のディスプレイ モードを取得する
		D3DADAPTER_DEFAULT,					
		 &D3DdisplayMode);
	
	if (FAILED(Create_Direct_Device(g_pDirect3D, _hWnd)))
	{
		MessageBox(NULL, "オブジェクトが生成できませんでした。", NULL, MB_OK);
		return E_FAIL;
	}
	
	
	return S_OK;
}

// 解放関数
void Free()
{
	g_pDirect3D->Release();
}