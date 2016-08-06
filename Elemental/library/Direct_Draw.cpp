/**
 * @file Direct_Draw.cpp
 * @brief DirectXの描画に関係する関数の中身
 * @author 柴田哲良
 * @date 2016年7月1日
 */

#include <d3dx9.h>
#include "Direct_Draw.h"

/**
* 柔軟な頂点フォーマットとして定義している<br>
* D3DFVF_XYZRHWは座標<br>
* D3DFVF_DIFFUSEは色成分<br>
* D3DFVF_TEX1は座標セットのテクスチャ番号
*/
#define D3DFVF_CUSTOMVERTEX (D3DFVF_XYZRHW | D3DFVF_DIFFUSE | D3DFVF_TEX1)

static IDirect3DDevice9*		g_pD3Device = NULL;			///<DirectXデバイスのポインタ

// 描画初期化関数
void Init_Draw()
{
	// 描画の設定
	g_pD3Device->SetRenderState(D3DRS_ALPHABLENDENABLE, true);

	g_pD3Device->SetRenderState(D3DRS_DESTBLEND, D3DBLEND_INVSRCALPHA);
	g_pD3Device->SetRenderState(D3DRS_SRCBLEND, D3DBLEND_SRCALPHA);
	//	g_pD3Device->SetRenderState(D3DRS_DIFFUSEMATERIALSOURCE, D3DMCS_COLOR1);

	g_pD3Device->SetTextureStageState(0, D3DTSS_COLORARG1, D3DTA_TEXTURE);
	g_pD3Device->SetTextureStageState(0, D3DTSS_COLORARG2, D3DTA_DIFFUSE);

	g_pD3Device->SetTextureStageState(0, D3DTSS_COLOROP, D3DTOP_MODULATE);

	g_pD3Device->SetTextureStageState(0, D3DTSS_ALPHAARG1, D3DTA_TEXTURE);
	g_pD3Device->SetTextureStageState(0, D3DTSS_ALPHAARG2, D3DTA_DIFFUSE);

	g_pD3Device->SetTextureStageState(0, D3DTSS_ALPHAOP, D3DTOP_MODULATE);
}

// 描画始め
void Draw_Start()
{
	// 頂点情報の指定
	g_pD3Device->SetFVF(D3DFVF_CUSTOMVERTEX);

	// 画面の消去
	g_pD3Device->Clear(0, NULL,				
		D3DCLEAR_TARGET,					
		D3DCOLOR_XRGB(0x00, 0x00, 0x00)		// RGB色を初期化
		, 1.0, 0);

	// 描画を開始
	g_pD3Device->BeginScene();
}


// 描画関数		  // DirectXテクスチャ・オブジェクトへのポインタ
void Draw_Display(LPDIRECT3DTEXTURE9   _pTexture, CUSTOMVERTEX _setdraw[])
{
	g_pD3Device->SetTexture(0, _pTexture);		// SetTexture:テクスチャをデバイスのステージに割り当てる
	g_pD3Device->DrawPrimitiveUP				// ()の中の指定した画像の表示
		(D3DPT_TRIANGLEFAN, 2,				// 三角形のテクスチャを２枚用意している
		_setdraw, sizeof(CUSTOMVERTEX));
}

// 画像の読み込み			//画像
HRESULT Load_Texture(TCHAR _filePath[256], LPDIRECT3DTEXTURE9*   _ppTexture)
{

	if (FAILED(D3DXCreateTextureFromFile(g_pD3Device, _filePath, _ppTexture)))
	{
		MessageBox(NULL, "画像が読み込めませんでした。", NULL, MB_OK);
		return E_FAIL;
	}

	return S_OK;
}

// 画像の読み込みEX
HRESULT Load_Texture_EX(TCHAR _filePath[256], LPDIRECT3DTEXTURE9* _ppTexture)
{
	if (FAILED(D3DXCreateTextureFromFileEx(
		g_pD3Device,			
		_filePath,				// 画像ファイルへの絶対パス、相対パスを表す文字列　扱える画像ファイル→ bmp, dds, dib, jpg, png(α(透明度)情報あり), tga(α(透明度)情報あり)
		D3DX_DEFAULT,		// 画像の幅を取得
		D3DX_DEFAULT,		// 画像の高さを取得
		D3DX_DEFAULT,		// ミップマップレベルをデフォルトに設定　ミニマップについてはメモ帳参照
		0,					
		D3DFMT_UNKNOWN,
		D3DPOOL_DEFAULT,	
		D3DX_FILTER_NONE,	
		D3DX_DEFAULT,
		D3DCOLOR_ARGB(255, 0, 0, 0),
		NULL,
		NULL,
		_ppTexture
		)))
	{
		MessageBox(0, "画像が読み込めませんでした。", NULL, MB_OK);
		return E_FAIL;
	}
	return S_OK;
}

// 描画終わり
void Draw_End()
{
	// 描画を終了
	g_pD3Device->EndScene();

	// 画面に表示
	g_pD3Device->Present(NULL, NULL, NULL, NULL);		//次のバッファのコンテンツを提示する
}

// DirectXのデバイス生成の関数
HRESULT Create_Direct_Device(IDirect3D9* _pDirect3D, HWND _hWnd)
{
	// DirectXのデバイスを生成する際に必要な情報を用意
	D3DPRESENT_PARAMETERS	d3dpp;							// Direct3DPresentParameters
	ZeroMemory(&d3dpp, sizeof(D3DPRESENT_PARAMETERS));		// 指定している場所のメモリを初期化する

	/*
	* 画面表示は普通「フロントバッファ」と「バックバッファ」の2つがある
	*/
	d3dpp.BackBufferFormat = D3DFMT_UNKNOWN;	// D3DFMT_UNKNOWNで現在のディスプレイモードフォーマットを自動で設定してくれる
	d3dpp.BackBufferCount = 1;					// バックバッファの数
	d3dpp.SwapEffect = D3DSWAPEFFECT_DISCARD;	// フロントとバックの切り替え
	d3dpp.Windowed = TRUE;						// TRUEならウィンドウ・モード、FALSEならフルスクリーン・モード(書き直す必要あり)

	// DirectXのデバイス生成
	_pDirect3D->CreateDevice(					// ディスプレイアダプタを表すためのデバイスを作成する
		D3DADAPTER_DEFAULT,
		D3DDEVTYPE_HAL,							// ハードウェアで実現させている(ソフトウェアでも実現できる)
		_hWnd,
		D3DCREATE_HARDWARE_VERTEXPROCESSING,	//High(高さ), Width(幅),の頂点処理
		&d3dpp,
		&g_pD3Device);

	// DirectXのデバイスを生成できたかチェック
	if (g_pD3Device == NULL)
	{
		MessageBox(NULL, "デバイスが生成できませんでした。", NULL, MB_OK);

		// 生成に失敗したらDirectXオブジェクトを解放して終了する
		_pDirect3D->Release();
		return E_FAIL;
	}
	return S_OK;
}


// 解放関数
void Draw_Free()
{
	g_pD3Device->Release();
}

