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

			if (abs(g_kodora[i].posX - g_player.posX) < (TIPSIZE * 4))		// コドラは主人公の前方4マスまで移動してくる
			{
				// 敵の攻撃処理をここに入れる予定
			}
			else if (abs(g_kodora[i].posX - g_player.posX) < (TIPSIZE * 8))		// 主人公が前方8マス以内になると動く
			{
				if (g_kodora[i].directionID == Left)
				{
					g_kodora[i].posX -= ENEMY_WALK;
					g_kodora[i].stateID = Move;
				}
				else if (g_kodora[i].directionID == Right)
				{
					g_kodora[i].posX += ENEMY_WALK;
					g_kodora[i].stateID = Move;
				}
			}
			else
			{
				g_kodora[i].stateID = Wait;
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
		if (g_skeleton[i].drawFlag == true)
		{
			//敵の方向を確認する
			if (g_skeleton[i].posX - g_player.posX < 0)
			{
				g_skeleton[i].directionID = Right;
			}
			else
			{
				g_skeleton[i].directionID = Left;
			}

			if (abs(g_skeleton[i].posX - g_player.posX) < (TIPSIZE * 4))	// スケルトンは主人公の前方4マスまで移動してくる
			{
				// 敵の攻撃処理をここに入れる予定
			}
			else if (abs(g_skeleton[i].posX - g_player.posX) < (TIPSIZE * 8))// 主人公が前方8マス以内になると動く
			{
				if (g_skeleton[i].directionID == Left)
				{
					g_skeleton[i].posX -= ENEMY_WALK;
					g_skeleton[i].stateID = Move;
				}
				else if (g_skeleton[i].directionID == Right)
				{
					g_skeleton[i].posX += ENEMY_WALK;
					g_skeleton[i].stateID = Move;
				}
			}
			else
			{
				g_skeleton[i].stateID = Wait;
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

			if (abs(g_slime[i].posX - g_player.posX) < (TIPSIZE * 4))	// スライムは主人公の前方4マスまで移動してくる
			{
				// 敵の攻撃処理をここに入れる予定
			}
			else if (abs(g_slime[i].posX - g_player.posX) < (TIPSIZE * 8))// 主人公が前方8マス以内になると動く
			{
				if (g_slime[i].directionID == Left)
				{
					g_slime[i].posX -= ENEMY_WALK;
					g_slime[i].stateID = Move;
				}
				else if (g_slime[i].directionID == Right)
				{
					g_slime[i].posX += ENEMY_WALK;
					g_slime[i].stateID = Move;
				}
			}
			else
			{
				g_slime[i].stateID = Wait;
			}
		}
	}
}

