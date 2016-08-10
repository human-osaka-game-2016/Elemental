/**
*@file GameSceneFree.h
*@brief メモリ開放関数のcpp.
*/
#include <d3d9.h>
#include <dinput.h>
#include"config.h"
#include"Main.h"

//メモリ開放関数
void Free()
{
	//開放
	// テクスチャを解放
	for (int i = 0; i < GAME_TEX_MAX; i++)
	{
		SAFE_RELEASE(g_pGameTexture[i]);
	}

	SAFE_RELEASE(g_pkeyDevice);
	SAFE_RELEASE(g_pDInput);
	SAFE_RELEASE(g_pDirect3DDevice);
	SAFE_RELEASE(g_pDirect3D);
	
	
}