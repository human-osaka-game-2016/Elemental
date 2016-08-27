/**
 * @file EnemyControl.cpp
 * @breif 全ての敵の操作ファイル
 
 * 全ての敵の操作に必要な処理を書いている

 */


#include "../GameScene/GameSceneDraw.h"
#include "../GameScene/GameSceneControl.h"
#include "../GameScene/GameSceneInit.h"
#include "../Player/PlayerControl.h"
#include "../Gmmick/WindGimmick_Draw.h"

// コドラの操作関数
void Kodora_Control()
{
	for (int i = 0; i < KODORA_MAX; i++)
	{
		if (g_kodora[i].drawFlag == true)
		{
			// 主人公が前方8マス以内になると動く
			if (abs(g_kodora[i].posX - g_player.posX) < (TIPSIZE * 8))
			{
				g_kodora[i].posX -= WALK_SPEED;
			}

			// コドラは主人公の前方4マスまで移動してくる
			if (abs(g_kodora[i].posX - g_player.posX) < (TIPSIZE * 4))
			{
				g_kodora[i].posX += WALK_SPEED;
			}
		}
	}

	for (int k = 0; k < KODORA_MAX; k++)
	{
		for (int i = 0; i < BULLET_MAX; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				if (Collision_Check(g_bullet[i].bullet[j].x, g_kodora[k].posX, g_bullet[i].bullet[j].y, g_kodora[k].posY, TIPSIZE))
				{
					g_kodora[k].drawFlag = false;
					g_kodora[k].hitFlag = true;			// 判定した矩形の範囲に入っていたら弾に当たったフラグをtrueにしている
					g_bullet[i].drawFlag = false;	// 当たればもう弾の秒が入らないのでfalseにする
					g_bullet[i].initFlag = true;	// 初期化フラグをtrueにしないと次の弾が出なくなる
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
		// 主人公が前方8マス以内になると動く
		if (abs(g_skereton[i].posX - g_player.posX) < (TIPSIZE * 8))
		{
			g_skereton[i].posX -= WALK_SPEED;
		}

		// スケルトンは主人公の前方2マスまで移動してくる
		if (abs(g_skereton[i].posX - g_player.posX) < (TIPSIZE * 2))
		{
			g_skereton[i].posX += WALK_SPEED;
		}
	}

	for (int i = 0; i < SKERETON_MAX; i++)
	{
		for (int j = 0; j < 4; j++)
		{
	
		}
	}
}

/*
// スライムの操作関数
void Slime_Control()
{
	// 主人公が前方8マス以内になると動く
	if (abs(g_kodora.posX - g_player.posX) < (TIPSIZE * 8))
	{
		g_kodora.posX -= WALK_SPEED;
	}

	// スケルトンは主人公の前方2マスまで移動してくる
	if (abs(g_kodora.posX - g_player.posX) < (TIPSIZE * 3))
	{
		g_kodora.posX += WALK_SPEED;
	}
}*/