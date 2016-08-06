/**
 * @file Main.cpp
 * @breif ゲームのエントリーポイント
 */


#include <windows.h>
#include <d3dx9tex.h>
#include "GameSceneDraw.h"
#include "GameSceneControl.h"
#include "GameSceneInit.h"

#include <Direct_Draw.h>
#include <Direct_Key_Input.h>
#include <Direct_Main.h>

#define WINDOW_W 1440					// ウィンドウ幅
#define WINDOW_H 810					// ウィンドウ高さ
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
	MSG msg;			
	HWND hWnd;			
	WNDCLASS winc;

	winc.style = CS_HREDRAW | CS_VREDRAW;
	winc.lpfnWndProc = WndProc;
	winc.cbClsExtra = winc.cbWndExtra = 0;
	winc.hInstance = hInstance;
	winc.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	winc.hCursor = LoadCursor(NULL, IDC_ARROW);
	winc.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	winc.lpszMenuName = NULL;
	winc.lpszClassName = WINDOW_TITLE;	


	if (!RegisterClass(&winc)) return 0;

	hWnd = CreateWindow(
		WINDOW_TITLE,						
		WINDOW_TITLE, 					
		WS_OVERLAPPEDWINDOW | WS_VISIBLE,	
		CW_USEDEFAULT,					
		CW_USEDEFAULT,					
		WINDOW_W,							
		WINDOW_H,						
		NULL,
		NULL,
		hInstance,							
		NULL
		);
	if (!hWnd) return 0;

	ShowWindow(hWnd, SW_SHOW);

	Init_Direct(hWnd);

	Init_Direct_Input(hWnd);

	Init();

	DWORD SyncOld = timeGetTime();	
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
			if (SyncNow - SyncOld >= 1000 / 60) 
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