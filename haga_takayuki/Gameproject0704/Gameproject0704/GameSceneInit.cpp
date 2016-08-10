/**
*@file GameSceneInit.cpp
*@brief ゲームシーンにおける初期化関数をまとめたファイルです.
*/
#include <d3dx9.h>
#include <d3dx9tex.h>
#include <dinput.h>
#include"config.h"
#include"key_operation.h"
#include"Main.h"
#include"GameSceneInit.h"
#include"GameSceneControl.h"

//-----------------------------------------------------------------------------------------------------------
//
//描画設定と画像読み込みと初期化
//
//------------------------------------------------------------------------------------------------------------

void InitGameScene(PLAYERSTATE* playerState, BULLETSTATE* playerBulletState, ENEMYSTATE* enemyState, BULLETSTATE* enemyBulletState,  BACKGROUNDSTATE*  backgroundState, SCORESTATE* hiscore, FLAGSTATE* flags)
{
	//描画設定
	RenderState(g_pDirect3DDevice);

	//画像読み込み
	LoadPicture(g_pDirect3DDevice, "background01.jpg", &g_pGameTexture[BACKGROUND_TEX]);		//背景画像
	LoadPicture_Ex(g_pDirect3DDevice, "bullet32.png", &g_pGameTexture[BULLET_TEX]);				//プレイヤーの弾画像
	LoadPicture_Ex(g_pDirect3DDevice, "player32.png", &g_pGameTexture[PLAYER_TEX]);				//プレイヤー画像
	LoadPicture_Ex(g_pDirect3DDevice, "enemy32.png", &g_pGameTexture[ENEMY_TEX]);				//敵画像
	LoadPicture_Ex(g_pDirect3DDevice, "Effect.dds", &g_pGameTexture[EXPLOSION_TEX]);			//爆発画像
	LoadPicture(g_pDirect3DDevice, "title.png", &g_pGameTexture[TITLE_TEX]);					//タイトル画像
	LoadPicture_Ex(g_pDirect3DDevice, "text.png", &g_pGameTexture[TEXT01_TEX]);					//文字(押す・ゲームオーバー)
	LoadPicture_Ex(g_pDirect3DDevice, "enemybullet.png", &g_pGameTexture[BULLET_ENEMY_TEX]);	//敵の弾画像
	LoadPicture_Ex(g_pDirect3DDevice, "number.png", &g_pGameTexture[SCORE_TEX]);				//スコア表示文字
	LoadPicture_Ex(g_pDirect3DDevice, "text02.png", &g_pGameTexture[TEXT02_TEX]);				//文字(ゲームクリア・警告)

	//初期化
	//プレイヤーの初期化
	*playerState = { PLAYER_LIFE_DEFU, PLAYER_SCORE_DEFU, PLAYER_X_DEFU, PLAYER_Y_DEFU, false, true, false };

	//敵の初期化
	for (int i = 0; i < ENEMYMAX; i++)
	{
		enemyState[i].SCORE = ENEMY_SCORE_DEFU;
		enemyState[i].posX = ENEMY_X_DEFU + (ENEMY_POS_X * i);
		enemyState[i].posY = 0 - (ENEMY_POS_Y * i);
		enemyState[i].drawFlag = true;
		enemyState[i].animeExplosion = false;
		enemyState[i].moveRight = false;
		enemyState[i].moveDown = true;
	}

	//プレイヤー弾の初期化
	for (int i = 0; i < BULLETMAX; i++)
	{
		playerBulletState[i].posX = 0.0f;
		playerBulletState[i].posY = 0.0f;
		playerBulletState[i].initFlag = true;
		playerBulletState[i].drawFlag = false;
	}

	//敵の弾の初期化
	for (int i = 0; i < ENEMYBULLETMAX; i++)
	{
		enemyBulletState[i].posX = 0.0f;
		enemyBulletState[i].posY = 0.0f;
		enemyBulletState[i].initFlag = true;
		enemyBulletState[i].drawFlag = false;
	}
	

	//背景初期化
	backgroundState[BG_ONE] = { BACKGROUND_X_DEFU, 0.0f };	
	backgroundState[BG_TWO] = { BACKGROUND_X_DEFU, -BACKGROUND_Y_DEFU };

	//ランキングスコア初期化
	for (int i = 0; i < RANKING_SCORE_MAX; i++)
	{
		hiscore[i].score = 0;
	}
	
	//フラグ構造体初期化
	*flags = { true, false, true, false, false };

}


