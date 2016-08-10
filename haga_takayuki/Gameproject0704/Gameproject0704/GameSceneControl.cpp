/**
*@file GameSceneControl.cpp
*@brief ゲームの操作や動きに関する関数をまとめているcpp.
*/
#include <d3dx9.h>
#include <d3dx9tex.h>
#include <dinput.h>
#include"config.h"
#include"key_operation.h"
#include"Main.h"
#include"GameSceneInit.h"
#include"GameSceneDraw.h"
#include"GameSceneControl.h"
#include"GameScore.h"
#include"GamePlayerControl.h"
#include"GameEnemyControl.h"


//デバック機能
//#define USE_DEBUG


void GameControl(PLAYERSTATE* playerState, BULLETSTATE* playerBulletState, ENEMYSTATE* enemyState, BULLETSTATE* enemyBulletState, SCORESTATE* hiscore
	, BACKGROUNDSTATE*	backgroundState, FLAGSTATE* flags)
{
	g_pkeyDevice->GetDeviceState(sizeof(diks), &diks);
	//キー動作チェック
	KeyCheck(diks[DIK_LEFT], LEFT);
	KeyCheck(diks[DIK_RIGHT], RIGHT);
	KeyCheck(diks[DIK_UP], UP);
	KeyCheck(diks[DIK_DOWN], DOWN);
	KeyCheck(diks[DIK_Z], Z);

#ifdef USE_DEBUG
#define USE_DEBUG
	//デバック用処理
	GameDbug(playerState,hiscore,gameEnd);
#endif
	if (flags->titleScene)
	{
		if (flags->loadScore)
		{
			//ファイルを読み込む
			LoadScore(hiscore,flags);
		}
		//タイトル
		TitleSceneControl(flags, playerState, enemyState, playerBulletState, enemyBulletState);
	}
	else
	{
		//敵の動き
		EnemyControl(enemyState, playerBulletState,playerState,flags);
		//敵の弾の動き
		EnemyBulletControl(enemyBulletState,enemyState);
		
		//プレイヤーの動き
		PlayerControl(playerState, enemyState, enemyBulletState, flags);
		//プレイヤー弾の動き
		PlayerBulletControl(playerBulletState, playerState);
		
		//背景の動き
		BgControl(backgroundState);
	
		if (playerState->SCORE >= HI_SCORE_MAX)
		{
			//スコアの上限を入れる
			playerState->SCORE = HI_SCORE_MAX;
			flags->gameComplete = true;
		}
	}
	if (flags->saveScore)
	{
		//ランキングチェック
		ScoreRankingCheck(hiscore,playerState);
		//スコアを記録する
		SaveScore(hiscore);
		flags->gameEnd = false;
		flags->titleScene = true;
		flags->saveScore = false;
		flags->gameComplete = false;
	}

	
}


//背景の動き
void BgControl(BACKGROUNDSTATE*	backgroundState)
{
	//背景の動く速度
	backgroundState[BG_ONE].posY += BG_MOVESPEED;
	backgroundState[BG_TWO].posY += BG_MOVESPEED;

	//画面の下までいったら上へシフトする
	if (backgroundState[BG_ONE].posY >= 640.f)
	{
		backgroundState[BG_ONE].posY = -640.f;
	}

	if (backgroundState[BG_TWO].posY >= 640.f)
	{
		backgroundState[BG_TWO].posY = -640.f;
	}
}

//タイトルコントロール
void TitleSceneControl(FLAGSTATE* flags, PLAYERSTATE* playerState, ENEMYSTATE* enemyState, BULLETSTATE* playerBulletState, BULLETSTATE* enemyBulletState)
{
	
	//背景・プレイヤー・敵・弾の位置やフラグなどを初期化
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


	//タイトルからゲームへ移行
	if (Key[Z] == PUSH || Key[Z] == ON)
	{
		flags->titleScene = false;
	}
}


//ゲームデバック用関数　
void GameDbug(PLAYERSTATE* playerState, SCORESTATE* hiscore,bool* gameEnd)
{

	//プレイヤー残機回復
	KeyCheck(diks[DIK_Q], Q);
	if (Key[Q] == PUSH)
	{
		playerState->LIFE = PLAYER_LIFE_DEFU;
	}

	//ランキングスコア初期化
	KeyCheck(diks[DIK_D], D);
	if (Key[D] == PUSH)
	{
		
		for (int i = 0; i < RANKING_SCORE_MAX; i++)
		{
			hiscore[i].score = 0;
		}
	}

	//スコア加算
	KeyCheck(diks[DIK_P], P);
	if (Key[P] == PUSH)
	{
		playerState->SCORE = HI_SCORE_MAX;
	}

	//プレイヤースコア初期化
	KeyCheck(diks[DIK_U], U);
	if (Key[U] == PUSH)
	{
		playerState->SCORE = 0;
	}


	//強制終了ボタン
	KeyCheck(diks[DIK_E], E);
	if (Key[E] == PUSH)
	{
		*gameEnd = true;
	}
}