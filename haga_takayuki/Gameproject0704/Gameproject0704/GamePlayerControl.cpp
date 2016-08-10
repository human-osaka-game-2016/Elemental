/**
*@file GamePlayerControl.cpp
*@brief ゲームにおけるプレイヤーの操作、及びプレイヤーの弾の関数をまとめたファイルです.
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

//プレイヤー関数
void PlayerControl(PLAYERSTATE* playerState, ENEMYSTATE* enemyState, BULLETSTATE* enemyBulletState, FLAGSTATE* flags)
{

	//プレイヤーの描画されたから時間をカウント(無敵時間の為)
	static int gamePlayeTime = 0;

	//クリアしていればプレイヤーの無敵時間は継続(デバック中のゲームオーバーも無敵仕様)
	if (flags->gameComplete || flags->gameEnd)
	{
		gamePlayeTime = 0;
	}

	if (playerState->drawFlag)
	{
		gamePlayeTime++;
		//キー操作と動ける範囲指定処理
		if (Key[LEFT] == ON)
		{
			if (playerState->posX < (BG_X_LEFT_LIMIT + TEXSIZE / 2.0f))
			{
				playerState->posX += 0;
			}
			else
			{
				playerState->posX -= PLAYER_MOVESPEED;
			}

		}
		if (Key[RIGHT] == ON)
		{
			if (playerState->posX > (BG_X_RIGHT_LIMIT - TEXSIZE / 2.0f))
			{
				playerState->posX += 0;
			}
			else
			{
				playerState->posX += PLAYER_MOVESPEED;
			}
		}
		if (Key[UP] == ON)
		{
			if (playerState->posY < (BG_Y_UP_LIMIT + TEXSIZE / 2.0f))
			{
				playerState->posY += 0;
			}
			else
			{
				playerState->posY -= PLAYER_MOVESPEED;
			}
		}
		if (Key[DOWN] == ON)
		{
			if (playerState->posY > (BG_Y_DOWN_LIMIT - TEXSIZE / 2))
			{
				playerState->posY += 0;
			}
			else
			{
				playerState->posY += PLAYER_MOVESPEED;
			}
		}
	}
	//無敵時間を過ぎたら当たり判定をつける
	if (gamePlayeTime >= PLAYER_INVINCIBLE_TIME)
	{
		//敵の当たり判定	
		for (int i = 0; i < ENEMYMAX; i++)
		{

			if (((abs(enemyState[i].posY - playerState->posY))) < TEXSIZE && ((abs(enemyState[i].posX - playerState->posX))) < TEXSIZE
				&& playerState->drawFlag == true && enemyState[i].drawFlag == true)
			{
				playerState->LIFE -= LIFE_DAMEGE;

				if (playerState->LIFE < 0)
				{
					//プレイヤー描画が消えて爆発アニメーションへ切替
					playerState->drawFlag = false;
					playerState->animeExplosion = true;
					gamePlayeTime = 0;
					//ゲーム終了フラグ
					flags->gameEnd = true;
				}
				else
				{
					//プレイヤー描画が消えて爆発アニメーションへ切替
					playerState->drawFlag = false;
					playerState->animeExplosion = true;
					gamePlayeTime = 0;
					break;

				}
			}

			//敵の弾との当たり判定
			for (int j = 0; j < ENEMYBULLETMAX; j++)
			{
				if (((abs(enemyBulletState[j].posY - playerState->posY))) < (TEXSIZE / 2) && ((abs(enemyBulletState[j].posX - playerState->posX))) < (TEXSIZE / 2)
					&& playerState->drawFlag == true && enemyBulletState[j].drawFlag == true)
				{
					playerState->LIFE -= LIFE_DAMEGE;

					if (playerState->LIFE < 0)
					{
						//プレイヤー描画が消えて爆発アニメーションへ移行
						playerState->drawFlag = false;
						playerState->animeExplosion = true;
						gamePlayeTime = 0;

						//敵の弾が消えて元の位置に戻る
						enemyBulletState[j].initFlag = true;
						enemyBulletState[j].drawFlag = false;


						//ゲーム終了フラグ
						flags->gameEnd = true;
					}
					else
					{
						//プレイヤー描画が消えて爆発アニメーションへ移行
						playerState->drawFlag = false;
						playerState->animeExplosion = true;
						gamePlayeTime = 0;

						//敵の弾が消えて元の位置に戻る
						enemyBulletState[j].initFlag = true;
						enemyBulletState[j].drawFlag = false;




					}
				}
			}

		}
	}

}

//プレイヤー弾の関数
void PlayerBulletControl(BULLETSTATE* playerBulletState,PLAYERSTATE* playerState)
{

	//プレイヤー弾の時間をカウント
	static int gameTimeBulletP = 0;
	//弾の発射
	for (int i = 0; i < BULLETMAX; i++)
	{


		if (Key[Z] == PUSH && playerBulletState[i].drawFlag == false && playerState->drawFlag == true)
		{
			playerBulletState[i].posX = playerState->posX;
			playerBulletState[i].posY = playerState->posY;
			playerBulletState[i].drawFlag = true;
			playerBulletState[i].initFlag = false;
			gameTimeBulletP = 0;
			break;
		}


		if ((gameTimeBulletP % BULLET_INTERVAL) == 0 && Key[Z] == ON && playerBulletState[i].drawFlag == false && playerState->drawFlag == true)
		{
			playerBulletState[i].posX = playerState->posX;
			playerBulletState[i].posY = playerState->posY;
			playerBulletState[i].drawFlag = true;
			playerBulletState[i].initFlag = false;
			break;
		}
	}

	gameTimeBulletP++;

	//弾が飛んでいく処理
	for (int i = 0; i < BULLETMAX; i++)
	{
		if (playerBulletState[i].drawFlag == true)
		{

			playerBulletState[i].posY -= BULLET_MOVESPEED;

			for (int j = 0; j < 4; j++)
			{
				playerBulletState[i].bullet[j].y -= BULLET_MOVESPEED;
			}
		}
	}

	//画面の端まで言ったら消える
	for (int i = 0; i < BULLETMAX; i++)
	{
		if (playerBulletState[i].posY <= BG_Y_UP_LIMIT)
		{
			playerBulletState[i].initFlag = true;
			playerBulletState[i].drawFlag = false;

		}
	}


}
