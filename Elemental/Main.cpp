/**
 * @file Main.cpp
 * @breif ゲームのエントリーポイント
 * @author 柴田哲良、山本倫太郎、岸本大河、水瀧秀明、田中貴大、竹村翔平、飯田純矢
 * @date 2016年X月Y日
 */


#include <windows.h>
#include <d3dx9tex.h>
#include "GameSceneDraw.h"
#include "GameSceneCntrol.h"


#include <Direct_Draw.h>
#include <Direct_Key_Input.h>
#include <Direct_Main.h>

#define WINDOW_W 1280					// ウィンドウ幅
#define WINDOW_H 736					// ウィンドウ高さ
#define WINDOW_TITLE TEXT("Elemental")	// ウィンドウ名

LRESULT CALLBACK WndProc(HWND hWnd, UINT mes, WPARAM wParam, LPARAM lParam)
{
	if (mes == WM_DESTROY)
	{
		PostQuitMessage(0);
		return 0;
	}

	return DefWindowProc(hWnd, mes, wParam, lParam);
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int nCmdShow)
{
	//---------------------------------------------------------------------
	//							ウィンドウ生成処理
	//---------------------------------------------------------------------

	MSG msg;			// メッセージを格納する構造体
	HWND hWnd;			// ウィンドウハンドル
	WNDCLASS winc;

	//Windows情報の設定
	winc.style = CS_HREDRAW | CS_VREDRAW;
	winc.lpfnWndProc = WndProc;
	winc.cbClsExtra = winc.cbWndExtra = 0;
	winc.hInstance = hInstance;
	winc.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	winc.hCursor = LoadCursor(NULL, IDC_ARROW);
	winc.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	winc.lpszMenuName = NULL;
	winc.lpszClassName = WINDOW_TITLE;	//クラス名

	//Windowの登録
	if (!RegisterClass(&winc)) return 0;
	//Windowの生成
	hWnd = CreateWindow(
		WINDOW_TITLE,						//ウィンドウのクラス名
		WINDOW_TITLE, 						//ウィンドウのタイトル
		WS_OVERLAPPEDWINDOW | WS_VISIBLE,	//ウィンドウスタイル
		CW_USEDEFAULT,						// ウィンドウの横方向の位置x
		CW_USEDEFAULT,						// ウィンドウの縦方向の位置y
		WINDOW_W,							// Width（幅）
		WINDOW_H,							// Height（高さ）
		NULL,
		NULL,
		hInstance,							// アプリケーションインスタンスのハンドル
		NULL
		);
	if (!hWnd) return 0;

	ShowWindow(hWnd, SW_SHOW);

	Init_Direct(hWnd);

	Init_Direct_Input(hWnd);

	Init_Draw();

	Load_Texture("normal_1.png", &g_pTexture[MAP_GROUND_TEX]);
	Load_Texture("RabbitHouse.png", &g_pTexture[BACKGROUND_TEX]);
	Load_Texture("キャラクター_仮.png", &g_pTexture[PLAYER_TEX]);

	Load_Map("ElementalWorld.csv");

	DWORD SyncOld = timeGetTime();	//	システム時間を取得
	DWORD SyncNow;

	timeBeginPeriod(1);
	ZeroMemory(&msg, sizeof(msg));
	while (msg.message != WM_QUIT)
	{
		Sleep(1);
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
		else
		{
			SyncNow = timeGetTime();
			if (SyncNow - SyncOld >= 1000 / 60) //	1秒間に60回この中に入る
			{
				Render();
				Control();
				SyncOld = SyncNow;
			}
		}
	}
	timeEndPeriod(1);

	for (int i = 0; i < TEX_MAX; i++)
	{
		g_pTexture[i]->Release();
	}

	Draw_Free();
	Key_Free();
	Free();

	return 0;
}