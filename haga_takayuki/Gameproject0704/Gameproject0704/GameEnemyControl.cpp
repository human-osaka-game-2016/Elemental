/**
*@file GameEnemyControl.cpp
*@brief ゲームにおける敵の操作、及び敵の弾の関数をまとめたファイルです.
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


//敵のコントロール関数
void EnemyControl(ENEMYSTATE* enemyState, BULLETSTATE* playerBulletState, PLAYERSTATE* playerState, FLAGSTATE* flags)
{
	//敵の動きと動ける範囲指定処理
	for (int i = 0; i < ENEMYMAX; i++)
	{
			if (enemyState[i].moveDown && enemyState[i].animeExplosion == false)
			{
				if ((enemyState[i].posY + (TEXSIZE / 2)) >= 0)
				{
					enemyState[i].drawFlag = true;
				}

				enemyState[i].posY += ENEMY_DOWN_MOVESPEED;

				if (enemyState[i].posY == ENEMY_Y_DEFU + (ENEMY_POS_Y * i))
				{
					enemyState[i].moveDown = false;
				}

			}
			else if (enemyState[i].drawFlag)
			{
				if (enemyState[i].moveRight)
				{
					enemyState[i].posX += ENEMY_MOVESPEED;
				}
				else
				{
					enemyState[i].posX -= ENEMY_MOVESPEED;
				}

				if (enemyState[i].posX < (BG_X_LEFT_LIMIT + TEXSIZE / 2.0))
				{
					enemyState[i].moveRight = true;
				}
				else if (enemyState[i].posX >(BG_X_RIGHT_LIMIT - TEXSIZE / 2.0f))
				{
					enemyState[i].moveRight = false;
				}
			}
	}

	for (int i = 0; i < ENEMYMAX; i++)
	{

		//当たり判定	
		for (int j = 0; j < BULLETMAX; j++)
		{
			for (int k = 0; k < 4; k++)
			{
				/*矩形で当たり判定をとる
				if ((enemyState[i].posY - (TEXSIZE / 2)  ) <= ((playerBulletState[j].bullet[k].y - (TEXSIZE / 2)) + TEXSIZE)
				&& (playerBulletState[j].bullet[k].y - (TEXSIZE / 2)) <= ((enemyState[i].posY - (TEXSIZE / 2)) + TEXSIZE)
				&& (enemyState[i].posX - (TEXSIZE / 2)) <= ((playerBulletState[j].bullet[k].x - (TEXSIZE / 2) ) + TEXSIZE)
				&& (playerBulletState[j].bullet[k].x - (TEXSIZE  / 2)) <= ((enemyState[i].posX - (TEXSIZE / 2)) + TEXSIZE)
				&& playerBulletState[j].drawFlag == true && enemyState[i].drawFlag == true)*/
				if (((abs(enemyState[i].posY - playerBulletState[j].bullet[k].y)) < (TEXSIZE / 2))
					&& ((abs(enemyState[i].posX - playerBulletState[j].bullet[k].x)) < (TEXSIZE / 2))
					&& playerBulletState[j].drawFlag == true && enemyState[i].drawFlag == true)

				{
					//ゲームをクリアしていないならスコアを加算する
					if (!(flags->gameComplete))
					{
						//プレイヤーに得点加算
						playerState->SCORE += enemyState[i].SCORE;
					}
					//敵の描画を消すs
					enemyState[i].drawFlag = false;
					enemyState[i].animeExplosion = true;

					//プレイヤーの弾の描画を消して、位置を元に戻す
					playerBulletState[j].drawFlag = false;
					playerBulletState[j].initFlag = true;
					break;
				}
			}
			//敵が消えていたらループを抜ける
			if (enemyState[i].drawFlag == false)
			{
				break;
			}
		}
	}

}

//敵の弾のコントロール関数
void EnemyBulletControl(BULLETSTATE* enemyBulletState, ENEMYSTATE* enemyState)
{

	//弾の発射
	for (int j = 0; j < ENEMYBULLETMAX; j++)
	{

		if (enemyBulletState[j].drawFlag == false && enemyState[j].drawFlag == true && enemyState[j].moveDown == false)
		{
			enemyBulletState[j].posX = enemyState[j].posX;
			enemyBulletState[j].posY = enemyState[j].posY;
			enemyBulletState[j].drawFlag = true;
			enemyBulletState[j].initFlag = false;

			break;
		}

	}


	//弾が飛んでいく処理
	for (int j = 0; j < ENEMYBULLETMAX; j++)
	{
		if (enemyBulletState[j].drawFlag == true)
		{

			enemyBulletState[j].posY += ENEMY_BULLET_MOVESPEED;

			for (int k = 0; k < 4; k++)
			{
				enemyBulletState[j].bullet[k].y += ENEMY_BULLET_MOVESPEED;
			}
		}
	}


	//画面の端まで言ったら消える
	for (int j = 0; j < ENEMYBULLETMAX; j++)
	{
		if (enemyBulletState[j].posY >= (BG_Y_DOWN_LIMIT + (TEXSIZE / 2)))
		{
			enemyBulletState[j].initFlag = true;
			enemyBulletState[j].drawFlag = false;

		}
	}



}


