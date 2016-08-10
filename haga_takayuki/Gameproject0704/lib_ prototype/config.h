/**
@file config.h
@brief Windows関連、及びDirectx初期化関数などをまとめているcppのヘッダーファイルです.
@author 芳我貴之
@data 2016/06/18
*/
#ifndef CONFIG_H
#define CONFIG_H
#include <d3dx9.h>


/**
*メモリ開放に使用.
*@note これを使用せずにメインソースでメモリ開放関数をつくってもいいです
*/
#define SAFE_RELEASE(p) {if(p){(p)->Release(); (p)=NULL;}}

/**
*サクセス(成功)の場合の戻り値<br>
*成功である戻り値の0をわかりやすくするためにSUCCESS_VALUEとしております.
*/
#define SUCCESS_VALUE 0

/**
*エラーの場合の戻り値<br>
*失敗である戻り値の-1をわかりやすくするためにERROR_VALUEとしております.
*/
#define ERROR_VALUE -1


/**
*Windowsに関する関数.<br>
*・ウィンドウ情報の設定･登録<br>
*・ウィンドウ作成<br>
*@param[in] hInstance	･アプリケーションへのポインタ
*@param[out] winc		･ウィンドウクラスの構造体
*@param[out] hWnd		･ウィンドウハンドル
*@param[in]	text[256]	･ウィンドウタイトル
*@param[in]	Window_Widgh　	･ウィンドウの幅
*@param[in]	Window_Height　	･ウィンドウの高さ
*@param[in]	WndProc			･ウィンドウプロシージャ関数　
*@retval SUCCESS_VALUE  成功
*@retval ERROR_VALUE	失敗
*/
int MakeWindows(HINSTANCE hInstance, WNDCLASS* winc, HWND* hWnd, char text[256], int Window_Widgh, int Window_Height, LRESULT CALLBACK WndProc(HWND hWnd, UINT msg, WPARAM wp, LPARAM lp));

/**
*DirectX オブジェクトを生成する関数.
*@param[in]	pDirect3D		･Direct3Dのデバイス	
*@param[in]	version			･バージョン情報
*/
void InitGameObject(IDirect3D9** pDirect3D, int version);

/**
*DirectXデバイスを作成する関数.
*@param[in] pDirect3D	･Direct3Dのインターフェイス
*@param[in]	pD3Device	･Direct3Dのデバイス
*@param[in]	d3dpp		･ディスプレイ
*@param[in]	d3ddm		･パラメーター
*/
void InitGameDevice(IDirect3D9*	pDirect3D, IDirect3DDevice9** pD3Device, D3DPRESENT_PARAMETERS* d3dpp, D3DDISPLAYMODE* d3ddm, HWND hWnd);


#endif