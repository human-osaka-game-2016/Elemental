/**
*@file draw_config.cpp
*@brief Directxの描画関連の関数をまとめているcppファイルです.
*@author 芳我貴之
*@date 2016/06/18
*/
#include <d3dx9.h>
#include <d3dx9tex.h>
#include"draw_config.h"
#include"config.h"



/*以下のソースをメインへ
IDirect3D9*			pDirect3D;		//	Direct3Dのインターフェイス
IDirect3DDevice9*	pD3Device;		//	Direct3Dのデバイス
LPDIRECT3DTEXTURE9	pTexture[];	//	画像の情報を入れておく為のポインタ配列
D3DDISPLAYMODE d3ddm;               //ディスプレイ
D3DPRESENT_PARAMETERS d3dpp;		//	パラメーター
*/

//描画方法の設定(この関数はデバイス作成関数の下に書く)
void RenderState(IDirect3DDevice9*	pD3Device)
{
	pD3Device->SetRenderState(D3DRS_ALPHABLENDENABLE, true);
	pD3Device->SetRenderState(D3DRS_SRCBLEND, D3DBLEND_SRCALPHA);  //SRCの設定
	pD3Device->SetRenderState(D3DRS_DESTBLEND, D3DBLEND_INVSRCALPHA);
	pD3Device->SetRenderState(D3DRS_DIFFUSEMATERIALSOURCE, D3DMCS_COLOR1);

	pD3Device->SetTextureStageState(0, D3DTSS_COLORARG1, D3DTA_TEXTURE);
	pD3Device->SetTextureStageState(0, D3DTSS_COLORARG2, D3DTA_DIFFUSE);

	pD3Device->SetTextureStageState(0, D3DTSS_COLOROP, D3DTOP_MODULATE);

	pD3Device->SetTextureStageState(0, D3DTSS_ALPHAARG1, D3DTA_TEXTURE);
	pD3Device->SetTextureStageState(0, D3DTSS_ALPHAARG2, D3DTA_DIFFUSE);

	pD3Device->SetTextureStageState(0, D3DTSS_ALPHAOP, D3DTOP_MODULATE);

}


//描画スタート　FVFは柔軟な頂点フォーマットのこと
void DrawStart(IDirect3DDevice9*	pD3Device, DWORD FVF)
{

	
	//画面の消去
	pD3Device->Clear(0, NULL,
		D3DCLEAR_TARGET,
		D3DCOLOR_XRGB(0x00, 0x00, 0x00),
		1.0, 0);
	//描画の開始
	pD3Device->BeginScene();

	//描画のフォーマットを設定
	pD3Device->SetFVF(FVF);
}

//描画
void DrawPicture(IDirect3DDevice9*	pD3Device, LPDIRECT3DTEXTURE9 pTexture, CUSTOMVERTEX setdraw[])
{

	pD3Device->SetTexture(0, pTexture);
	pD3Device->DrawPrimitiveUP(
		D3DPT_TRIANGLEFAN,
		2,
		setdraw,
		sizeof(CUSTOMVERTEX));
}

//描画エンド
void DrawEnd(IDirect3DDevice9*	pD3Device)
{
	//描画の終了 
	pD3Device->EndScene();

	//表示
	pD3Device->Present(NULL, NULL, NULL, NULL);
}

//画像読み込み
int LoadPicture(IDirect3DDevice9* pD3Device, char text[256], LPDIRECT3DTEXTURE9*	pTexture)
{
	if (FAILED(D3DXCreateTextureFromFile(pD3Device, text, pTexture)))
	{

		return ERROR_VALUE;
	}
	
	return SUCCESS_VALUE;
}

//画像読み込みEx
int LoadPicture_Ex(IDirect3DDevice9* pD3Device, char text[256], LPDIRECT3DTEXTURE9*	pTexture)
{
	if (FAILED(D3DXCreateTextureFromFileEx(
		pD3Device,
		text,
		D3DX_DEFAULT_NONPOW2,
		D3DX_DEFAULT_NONPOW2,
		D3DX_DEFAULT,
		0,
		D3DFMT_UNKNOWN,
		D3DPOOL_MANAGED,
		D3DX_FILTER_NONE,
		D3DX_FILTER_NONE,
		D3DCOLOR_ARGB(255, 0, 0, 0),
		NULL, NULL,
		pTexture)))
	{
		return ERROR_VALUE;
	}

	return SUCCESS_VALUE;
}