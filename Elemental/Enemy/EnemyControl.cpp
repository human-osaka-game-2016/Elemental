/**
 * @file EnemyControl.cpp
 * @breif 全ての敵の操作ファイル
 
 * 全ての敵の操作に必要な処理を書いている

 */


#include "../GameScene/GameSceneDraw.h"
#include "../GameScene/GameSceneControl.h"
#include "../GameScene/GameSceneInit.h"
#include "../Player/PlayerDraw.h"
#include "../Player/PlayerControl.h"
#include "EnemyDraw.h"

// コドラの操作関数
void Kodora_Control()
{
	if (abs(g_enemy.posX - g_player.posX) < (TIPSIZE * 8))
	{
		g_enemy.posX -= WALK_SPEED;
	}
	if (abs(g_enemy.posX - g_player.posX) < (TIPSIZE * 4))
	{
		g_enemy.posX += WALK_SPEED;
	}
}

// スケルトンの操作関数
void skeleton_Control()
{
	if (abs(g_enemy.posX - g_player.posX) < (TIPSIZE * 8))
	{
		g_enemy.posX -= WALK_SPEED;
	}
	if (abs(g_enemy.posX - g_player.posX) < (TIPSIZE * 2))
	{
		g_enemy.posX += WALK_SPEED;
	}
}

// スライムの操作関数
void Slime_Control()
{
	if (abs(g_enemy.posX - g_player.posX) < (TIPSIZE * 8))
	{
		g_enemy.posX -= WALK_SPEED;
	}
	if (abs(g_enemy.posX - g_player.posX) < (TIPSIZE * 3))
	{
		g_enemy.posX += WALK_SPEED;
	}
}