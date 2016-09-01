/**
 * @file EnemyControl.cpp
 * @breif 全ての敵の操作ファイル
 
 * 全ての敵の操作に必要な処理を書いている

 */


#include "../GameScene/GameSceneDraw.h"
#include "../GameScene/GameSceneControl.h"
#include "../GameScene/GameSceneInit.h"
#include "../Player/PlayerControl.h"
#include "../Enemy/EnemyControl.h"
#include "../Gmmick/WindGimmick_Draw.h"

// コドラの操作関数
void Kodora_Control()
{
	for (int i = 0; i < KODORA_MAX; i++)
	{
		if (g_kodora[i].drawFlag == true)
		{
			//敵の方向を確認する
			if (g_kodora[i].posX - g_player.posX < 0)
			{
				g_kodora[i].directionID = Right;
			}
			else
			{
				g_kodora[i].directionID = Left;
			}

			if (abs(g_kodora[i].posX - g_player.posX) < (TIPSIZE * 4))	// コドラは主人公の前方4マスまで移動してくる
			{
				// 敵の攻撃処理をここに入れる予定
			}
			else if (abs(g_kodora[i].posX - g_player.posX) < (TIPSIZE * 8))// 主人公が前方8マス以内になると動く
			{
				if (g_kodora[i].directionID == Left)
				{
					g_kodora[i].posX -= ENEMY_WALK;
				}
				else if (g_kodora[i].directionID == Right)
				{
					g_kodora[i].posX += ENEMY_WALK;
				}
			}

			for (int k = 0; k < BULLET_MAX; k++)
			{
				for (int j = 0; j < 4; j++)
				{
					if (Collision_Check(g_bullet[k].bullet[j].x, g_kodora[i].posX, g_bullet[k].bullet[j].y, g_kodora[i].posY, TIPSIZE))
					{
						g_kodora[i].hitFlag = true;			// 判定した矩形の範囲に入っていたら弾に当たったフラグをtrueにしている
						g_gimmick.drawFlag = true;
						g_bullet[k].drawFlag = false;	// 当たればもう弾の秒が入らないのでfalseにする
						g_bullet[k].initFlag = true;	// 初期化フラグをtrueにしないと次の弾が出なくなる
					}
				}
			}
		}
	}
}

// スケルトンの操作関数
void skeleton_Control()
{
	for (int i = 0; i < SKERETON_MAX; i++)
	{
		if (g_skereton[i].drawFlag == true)
		{
			//敵の方向を確認する
			if (g_skereton[i].posX - g_player.posX < 0)
			{
				g_skereton[i].directionID = Right;
			}
			else
			{
				g_skereton[i].directionID = Left;
			}

			if (abs(g_skereton[i].posX - g_player.posX) < (TIPSIZE * 4))	// コドラは主人公の前方4マスまで移動してくる
			{
				// 敵の攻撃処理をここに入れる予定
			}
			else if (abs(g_skereton[i].posX - g_player.posX) < (TIPSIZE * 8))// 主人公が前方8マス以内になると動く
			{
				if (g_skereton[i].directionID == Left)
				{
					g_skereton[i].posX -= ENEMY_WALK;
				}
				else if (g_skereton[i].directionID == Right)
				{
					g_skereton[i].posX += ENEMY_WALK;
				}
			}
		}
	}
}


// スライムの操作関数
void Slime_Control()
{
	for (int i = 0; i < SLIME_MAX; i++)
	{
		if (g_slime[i].drawFlag == true)
		{
			//敵の方向を確認する
			if (g_slime[i].posX - g_player.posX < 0)
			{
				g_slime[i].directionID = Right;
			}
			else
			{
				g_slime[i].directionID = Left;
			}

			if (abs(g_slime[i].posX - g_player.posX) < (TIPSIZE * 4))	// コドラは主人公の前方4マスまで移動してくる
			{
				// 敵の攻撃処理をここに入れる予定
			}
			else if (abs(g_slime[i].posX - g_player.posX) < (TIPSIZE * 8))// 主人公が前方8マス以内になると動く
			{
				if (g_slime[i].directionID == Left)
				{
					g_slime[i].posX -= ENEMY_WALK;
				}
				else if (g_slime[i].directionID == Right)
				{
					g_slime[i].posX += ENEMY_WALK;
				}
			}
			if (g_slime[i].directionID == Left)
			{
				if (g_windgimmick[1].x < g_slime[i].posX && g_gimmick.outdreakFlag == true && g_gimmick.drawFlag == true)
				{
					g_gimmick.hitFlag = true;
				}
			}
			else if (g_slime[i].directionID == Right)
			{
				if (g_windgimmick[0].x < g_slime[i].posX && g_gimmick.outdreakFlag == true && g_gimmick.drawFlag == true)
				{
					g_gimmick.hitFlag = true;
				}
			}
		}
	}
}

void Kodora_Init()
{
	for (int y = 0; y < MAP_HEIGHT; y++)
	{
		for (int x = 0; x < MAP_WIDTH; x++)
		{
			if (map[y][x] == 10)
			{
				for (int i = 0; i < KODORA_MAX; i++)
				{
					g_kodora[i].posX = (float)(x * TIPSIZE);
					g_kodora[i].posY = (float)(y * TIPSIZE);
				}
			}
		}
	}
}

void Slime_Init()
{
	for (int y = 0; y < MAP_HEIGHT; y++)
	{
		for (int x = 0; x < MAP_WIDTH; x++)
		{
			if (map[y][x] == 20)
			{
				for (int i = 0; i < SLIME_MAX; i++)
				{
					g_slime[i].posX = (float)(x * TIPSIZE);
					g_slime[i].posY = (float)(y * TIPSIZE);
				}
			}
		}
	}
}