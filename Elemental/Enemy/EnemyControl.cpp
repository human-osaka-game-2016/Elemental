/**
 * @file EnemyControl.cpp
 * @breif 全ての敵の操作ファイル
 
 * 全ての敵の操作に必要な処理を書いている

 */


#include "../GameScene/GameSceneDraw.h"
#include "../GameScene/GameSceneControl.h"
#include "../GameScene/GameSceneInit.h"
#include "../Player/PlayerControl.h"

// コドラの操作関数
void Kodora_Control()
{
	// 主人公が前方8マス以内になると動く
	if (abs(g_enemy.posX - g_player.posX) < (TIPSIZE * 8))
	{
		g_enemy.posX -= WALK_SPEED;
	}

	// コドラは主人公の前方4マスまで移動してくる
	if (abs(g_enemy.posX - g_player.posX) < (TIPSIZE * 4))
	{
		g_enemy.posX += WALK_SPEED;
	}

	// 最初のforで出した弾の数だけ当たっているかをチェックしている
	for (int i = 0; i < BULLET_MAX; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (Collision_Check(g_bullet[i].bullet[j].x, g_enemy.posX, g_bullet[i].bullet[j].y, g_enemy.posY, TIPSIZE))
			{
				g_enemy.hitFlag = true;			// 判定した矩形の範囲に入っていたら弾に当たったフラグをtrueにしている
				g_bullet[i].drawFlag = false;	// 当たればもう弾の秒が入らないのでfalseにする
				g_bullet[i].initFlag = true;	// 初期化フラグをtrueにしないと次の弾が出なくなる
			}
		}
	}
}

// スケルトンの操作関数
void skeleton_Control()
{
	// 主人公が前方8マス以内になると動く
	if (abs(g_enemy.posX - g_player.posX) < (TIPSIZE * 8))
	{
		g_enemy.posX -= WALK_SPEED;
	}

	// スケルトンは主人公の前方2マスまで移動してくる
	if (abs(g_enemy.posX - g_player.posX) < (TIPSIZE * 2))
	{
		g_enemy.posX += WALK_SPEED;
	}
}

// スライムの操作関数
void Slime_Control()
{
	// 主人公が前方8マス以内になると動く
	if (abs(g_enemy.posX - g_player.posX) < (TIPSIZE * 8))
	{
		g_enemy.posX -= WALK_SPEED;
	}

	// スケルトンは主人公の前方2マスまで移動してくる
	if (abs(g_enemy.posX - g_player.posX) < (TIPSIZE * 3))
	{
		g_enemy.posX += WALK_SPEED;
	}
}