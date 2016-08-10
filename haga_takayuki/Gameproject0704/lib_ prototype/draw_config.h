/**
*@file draw_config.h
*@brief Directxの描画関連の関数をまとめているcppのヘッダーファイルです.
*@author 芳我貴之
*@date 2016/06/18
*/


#ifndef CUTOMVERTEX_CONFIG_H
#define CUTOMVERTEX_CONFIG_H
#include <d3dx9.h>
#include <d3dx9tex.h>

/**
*頂点データ(定番)<br>
*柔軟な頂点フォーマットの定番をdefineしております.
*@attention あくまでこれは定番です。これを使わずに頂点データを設定してもいいです
*/
#define D3DFVF_CUSTOMVERTEX (D3DFVF_XYZRHW | D3DFVF_DIFFUSE | D3DFVF_TEX1)

/**
*@par カスタムバーテックス
* 構造体でカスタムバーテックス型を定義しています。メンバーは以下の通りです.<br>
*x, y, z, rhw：画面上の座標情報<br>
*color：色情報<br>
*tu, tv：テクスチャ座標.<br>
*/
struct CUSTOMVERTEX
{
	FLOAT	x, y, z, rhw;
	DWORD	color;
	FLOAT	tu, tv;
};

/**
*描画方法の設定関数.
*@attentionこの関数はWinmain関数に書いてください
*@param[in] pD3Device	･Direct3Dのデバイス
*/
void RenderState(IDirect3DDevice9*	pD3Device);

/**
*描画を開始する為の関数.<br>
*・画面の消去<br>
*・描画の開始<br>
*・描画のフォーマットを設定<br>
*@param[in] pD3Device   ・Direct3Dのデバイス
*@param[in] FVF  ・FVF定数
*/
void DrawStart(IDirect3DDevice9* pD3Device, DWORD FVF);

/**
*画面に画像を描画する処理をおこなっている関数.
*@param[in] pD3Device	･Direct3Dのデバイス
*@param[in] pTexture	･読み込んだ画像情報
*@param[in] setdraw		･バーテックス（座標情報など）
*/
void DrawPicture(IDirect3DDevice9*	pD3Device, LPDIRECT3DTEXTURE9 pTexture, CUSTOMVERTEX setdraw[]);

/**
*描画を終了、表示する為の関数.<br>
*描画の終了<br>
*表示.<br>
*@param[in] pD3Device	･Direct3Dのデバイス
*/
void DrawEnd(IDirect3DDevice9*	pD3Device);

/**
*画像を読み込む関数.<br>
*D3DXCreateTextureFromFileを使用.
*@param[in] pD3Device	･Direct3Dのデバイス
*@param[in] text[256]	･画像
*@param[out] pTexture	･読み込んだ画像情報を格納する
*@retval SUCCESS_VALUE  読み込み成功
*@retval ERROR_VALUE	読み込み失敗
*/
int LoadPicture(IDirect3DDevice9* pD3Device, char text[256], LPDIRECT3DTEXTURE9* pTexture);

/**
*画像を読み込む関数.
*D3DXCreateTextureFromFileExを使用.
*@param[in] pD3Device	･Direct3Dのデバイス
*@param[in] text[256]	･画像
*@param[out] pTexture	･読み込んだ画像情報を格納する
*@retval SUCCESS_VALUE  読み込み成功
*@retval ERROR_VALUE	読み込み失敗
*/
int LoadPicture_Ex(IDirect3DDevice9* pD3Device, char text[256], LPDIRECT3DTEXTURE9*	pTexture);



#endif


