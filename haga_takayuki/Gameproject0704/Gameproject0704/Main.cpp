/**
*@file Main.cpp
*@brief ゲームのエントリーポイントのcpp.
*/
#include <windows.h>
#include <d3d9.h>
#include <dinput.h>
#include"key_operation.h"
#include"config.h"
#include"Main.h"
#include"GameSceneInit.h"
#include"GameSceneDraw.h"
#include"GameSceneControl.h"
#include"GameSceneFree.h"

//-----------------------------------------------------------------------------
//							グローバル変数群
//-----------------------------------------------------------------------------

LPDIRECT3D9				g_pDirect3D		= NULL;				// DirectXオブジェクトのポインタ
LPDIRECT3DDEVICE9		g_pDirect3DDevice = NULL;			// DirectXデバイスのポインタ
LPDIRECT3DTEXTURE9		g_pGameTexture[GAME_TEX_MAX];		//画像情報をいれおくための配列
LPDIRECTINPUT8			g_pDInput = NULL;					//DirectInput8 インターフェイス
LPDIRECTINPUTDEVICE8	g_pkeyDevice = NULL;				//キーボードデバイス

// ウィンドウプロシージャ
LRESULT CALLBACK WndProc(HWND hWnd, UINT mes, WPARAM wParam, LPARAM lParam)
{
	if (mes == WM_DESTROY)
	{
		PostQuitMessage(0);
		return 0;
	}

	return DefWindowProc(hWnd, mes, wParam, lParam);
}


// エントリポイント
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int nCmdShow)
{
	//-----------------------------------------------------------------------------
	//								変数群
	//-----------------------------------------------------------------------------

	/*-------------------------ウィンドウ関連--------------------------------------*/
	MSG msg;											// メッセージを格納する構造体
	HWND hWnd;											// ウィンドウハンドル
	WNDCLASS winc;										//ウィンドウクラス
	/*------------------------DirectX初期化関連------------------------------------*/
					
	D3DDISPLAYMODE		D3DdisplayMode;					//ディスプレイモード
	D3DPRESENT_PARAMETERS d3dpp;						// DirectXのデバイスを生成する際に必要なパラメーターを用意

	/*---------------------ゲームで使用する変数------------------------------------*/
	PLAYERSTATE playerState;							//プレイヤー情報
	BULLETSTATE playerBulletState[BULLETMAX];			//プレイヤーの弾情報
	ENEMYSTATE enemyState[ENEMYMAX];					//敵の弾情報
	BULLETSTATE enemyBulletState[ENEMYBULLETMAX];		//敵の弾の情報
	BACKGROUNDSTATE backgroundState[BG_MAX];            //背景
	SCORESTATE hiscore[RANKING_SCORE_MAX];				//ハイスコア
	FLAGSTATE flags;									//フラグをまとめたもの
	//----------------------------------------------------------------------------
	//							ウィンドウ生成処理
	//----------------------------------------------------------------------------

	if ((MakeWindows(hInstance, &winc, &hWnd, WINDOW_TITLE, WINDOW_W, WINDOW_H, WndProc)) == ERROR_VALUE)
	{
		return ERROR_VALUE;
	}

	ShowWindow(hWnd, SW_SHOW);

	//--------------------------------------------------------------------------
	//							DirectX初期化処理
	//--------------------------------------------------------------------------

	// DirectXオブジェクト生成
	InitGameObject(&g_pDirect3D, D3D_SDK_VERSION);
	// オブジェクトの生成に成功したかチェック
	if (g_pDirect3D == NULL)
	{
		// 生成に失敗したら終了する
		return ERROR_VALUE;
	}
	
	//デバイス生成
	InitGameDevice(g_pDirect3D, &g_pDirect3DDevice, &d3dpp, &D3DdisplayMode, hWnd);

	if (g_pDirect3DDevice == NULL)
	{
		// 生成に失敗したらDirectXオブジェクトを解放して終了する
		SAFE_RELEASE(g_pDirect3D);
		return ERROR_VALUE;
	}
	//-----------------------------------------------------------------------
	//						DirectInput初期化処理
	//-----------------------------------------------------------------------
	if (FAILED(InitDinput(hWnd, &g_pDInput, &g_pkeyDevice)))
	{
		// 生成に失敗したらDirectXオブジェクトを解放して終了する
		SAFE_RELEASE(g_pDirect3D);
		SAFE_RELEASE(g_pDirect3DDevice);
		return ERROR_VALUE;
	}
	//----------------------------------------------------------------------
	//							ゲームループ
	//----------------------------------------------------------------------

	//ゲームの初期化
	InitGameScene(&playerState, playerBulletState, enemyState, enemyBulletState, backgroundState, hiscore,&flags);

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
				//ゲーム
				GameControl(&playerState, playerBulletState, enemyState, enemyBulletState, hiscore, backgroundState,&flags);

				GameDraw(&playerState, playerBulletState, enemyState, enemyBulletState, backgroundState, hiscore, &flags);

				SyncOld = SyncNow;
			}
		}
	}
	timeEndPeriod(1);

	//メモリ開放
	Free();
	return 0;
}