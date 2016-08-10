/**
@file config.cpp
@brief Windows関連、及びDirectx初期化関数などをまとめているcppファイルです.
@author 芳我貴之
@data 2016/06/18
*/
#include <d3dx9.h>
#include <d3dx9tex.h>
#include"config.h"

/*
IDirect3D9*			pDirect3D;		//	Direct3Dのインターフェイス
IDirect3DDevice9*	pD3Device;		//	Direct3Dのデバイス
LPDIRECT3DTEXTURE9	pTexture[];		//	画像の情報を入れておく為のポインタ配列
D3DDISPLAYMODE d3ddm;               // ディスプレイ
D3DPRESENT_PARAMETERS d3dpp;		//	パラメーター
*/

/*個人用コメント
ウィンドウプロシージャ関数をメインに書くことを忘れずに
LRESULT CALLBACK WndProc(HWND hWnd, UINT msg, WPARAM wp, LPARAM lp)
{

	switch (msg)
	{
	case WM_DESTROY:	//	ウインドウが閉じられた時とか
		PostQuitMessage(0);
		break;

	case WM_KEYDOWN:
		switch ((CHAR)wp)
		{
		case VK_ESCAPE:
			PostQuitMessage(0);
			break;
		}
		break;
	}
	return DefWindowProc(hWnd, msg, wp, lp);
}
*/

/*以下のソースをメインへ
MSG msg;
HWND hWnd;
WNDCLASS winc;
*/

//Windows関数
int MakeWindows(HINSTANCE hInstance, WNDCLASS* winc, HWND* hWnd, char text[256], int Window_Widgh, int Window_Height, LRESULT CALLBACK WndProc(HWND hWnd, UINT msg, WPARAM wp, LPARAM lp))
{
	//Windows情報の設定
	winc->style = CS_HREDRAW | CS_VREDRAW;
	winc->lpfnWndProc = WndProc;
	winc->cbClsExtra = winc->cbWndExtra = 0;
	winc->hInstance = hInstance;
	winc->hIcon = LoadIcon(NULL, IDI_APPLICATION);
	winc->hCursor = LoadCursor(NULL, IDC_ARROW);
	winc->hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);
	winc->lpszMenuName = NULL;
	winc->lpszClassName = text;	//クラス名
	//Windowsの登録
	if (!RegisterClass(winc)) return ERROR_VALUE;
	//Windowsの生成
	//int dH = GetSystemMetrics(SM_CYCAPTION) + GetSystemMetrics(SM_CYFRAME) * 2;
	//int dW = GetSystemMetrics(SM_CXFRAME) * 2;
	//	ウィンドウを作る				
	*hWnd = CreateWindow(
		text,								//ウィンドウのクラス名
		text, 							//ウィンドウのタイトル
		WS_OVERLAPPEDWINDOW | WS_VISIBLE,	//ウィンドウスタイル
		CW_USEDEFAULT,						// ウィンドウの横方向の位置x
		CW_USEDEFAULT,						// ウィンドウの縦方向の位置y
		Window_Widgh ,							// Width（幅）　
		Window_Height,							// Height（高さ)
		NULL,
		NULL,
		hInstance,							// アプリケーションインスタンスのハンドル
		NULL
		);

	RECT client_rect;
	RECT widow_rect;
	GetWindowRect(*hWnd, &widow_rect);
	GetClientRect(*hWnd, &client_rect);


	//正しいウィンドウ間隔を求める(幅)
	widow_rect.right -= widow_rect.left;
	client_rect.right -= client_rect.left;

	//正しいウィンドウ間隔を求める(高さ)
	widow_rect.bottom -= widow_rect.top;
	client_rect.bottom -= client_rect.top;

	SetWindowPos(*hWnd, HWND_TOP, 0,0, (Window_Widgh + (widow_rect.right - client_rect.right)), (Window_Height + (widow_rect.bottom - client_rect.bottom)), SWP_NOMOVE);

	//再度確認用
	GetWindowRect(*hWnd, &widow_rect);
	GetClientRect(*hWnd, &client_rect);
	if (!hWnd) return ERROR_VALUE;

	return SUCCESS_VALUE;

}



//DirectX オブジェクトの生成
void InitGameObject(IDirect3D9**	pDirect3D, int version)
{

	*pDirect3D = Direct3DCreate9(version);

}

//デバイス作成
void InitGameDevice(IDirect3D9*	pDirect3D, IDirect3DDevice9** pD3Device, D3DPRESENT_PARAMETERS* d3dpp, D3DDISPLAYMODE* d3ddm, HWND hWnd)
{
	pDirect3D->GetAdapterDisplayMode(
		D3DADAPTER_DEFAULT,
		d3ddm);
	ZeroMemory(d3dpp,
			   sizeof(D3DPRESENT_PARAMETERS));

	d3dpp->BackBufferFormat = d3ddm->Format;
	d3dpp->BackBufferCount = 1;
	d3dpp->SwapEffect = D3DSWAPEFFECT_DISCARD;
	d3dpp->Windowed = TRUE;

	//デバイスを作る
	pDirect3D->CreateDevice(
		D3DADAPTER_DEFAULT,
		D3DDEVTYPE_HAL,
		hWnd,
		D3DCREATE_SOFTWARE_VERTEXPROCESSING,
		d3dpp, pD3Device);
}