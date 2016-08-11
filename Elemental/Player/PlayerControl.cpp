/**
 * @file PlayerCntrol.cpp
 * @breif 主人公の操作ファイル

 *  主人公の操作に必要な処理を書いている

 */

#define DIRECTINPUT_VERSION 0x0800

#include <dinput.h>
#include <Direct_Key_Input.h>
#include "../GameScene/GameSceneDraw.h"
#include "../GameScene/GameSceneControl.h"
#include "../GameScene/GameSceneInit.h"
#include "PlayerControl.h"

int dashcount = 0;

void Player_Control()
{

	if (g_Key[LEFT] == ON)
	{
		if (g_player.dashFlag == true)
		{
			// 次に動いた値で左にブロックがあるかどうか先に調べている
			if (!Map_Collision_Check(g_player.posX - 6, g_player.posY, 2, 2))
			{
				// なければ移動を続ける
				g_player.posX -= 6;
			}
		}
		else
		{
			// 次に動いた値で左にブロックがあるかどうか先に調べている
			if (!Map_Collision_Check(g_player.posX - 4, g_player.posY, 2, 2))
			{
				// なければ移動を続ける
				g_player.posX -= 4;
			}
		}
	}



	if (g_Key[RIGHT] == ON)
	{
		if (dashcount > 0 && dashcount < 29)
		{
			g_player.dashFlag = true;
		}
	}


	if (g_Key[RIGHT] == ON)
	{
		dashcount = 30;
	}

	dashcount--;

	if (g_Key[RIGHT] == ON)
	{
		if (g_player.dashFlag == true)
		{
			// 次に動いた値で左にブロックがあるかどうか先に調べている
			if (!Map_Collision_Check(g_player.posX + 6, g_player.posY, 2, 2))
			{
				// なければ移動を続ける
				g_player.posX += 6;
			}
		}
		else
		{
			// 次に動いた値で左にブロックがあるかどうか先に調べている
			if (!Map_Collision_Check(g_player.posX + 4, g_player.posY, 2, 2))
			{
				// なければ移動を続ける
				g_player.posX += 4;
			}
		}
	}
	else
	{
		g_player.dashFlag = false;
	}



	


	if (g_Key[UP] == PUSH && g_player.skyFlag == false)
	{
		g_player.jumpFlag = true;			// ジャンプするのでフラグをtrueに
		g_player.skyFlag = true;			// 空中にもいるのでフラグをtrueに
		g_player.acceleration = JUMP_POWER;	// 加速度にジャンプの限界値を代入
	}

	// フラグがtrueなら処理をする
	if (g_player.jumpFlag == true)
	{
		/*
		これを抜くと上の判定がなくなので薄い足場みたいなのが実装できる(上に行くときのみ)
		if (Map_Collision_Check(g_player.posX, g_player.posY + JUMP_POWER, 2, 2))
		{
			if (g_player.acceleration < 0)
			{
				g_player.acceleration = 0.4f;
			}
		}
		*/

		// 空中いる間主人公の上にブロックがあるかどうか調べている
		if (Map_Collision_Check(g_player.posX, g_player.posY + JUMP_POWER, 2, 2))
		{
			if (g_player.acceleration < 0)
			{
				g_player.acceleration = 0;
			}
		}

		g_player.acceleration += GRAVITY;			// 周りにブロックがなければ加速度にGRAVITYの値をプラスしてどんどん上に動かす
		g_player.posY += g_player.acceleration;	// プラスされた加速度をさらに主人公のY座標にプラスしていく

		// 主人公の周りにブロックがあるかどうか調べている
		if (Map_Collision_Check(g_player.posX, g_player.posY - JUMP_POWER, 2, 2))
		{

			if (g_player.acceleration > 0)
			{
				g_player.skyFlag = false;
				g_player.jumpFlag = false;
			}
		}
	}

	// 自由落下の処理
	if (!Map_Collision_Check(g_player.posX, g_player.posY - JUMP_POWER, 2, 2))
	{
		// 浮いていたら自動で判定のあるところまで下がる
		if (g_player.jumpFlag == false)
		{
			g_player.acceleration += GRAVITY;
			g_player.posY += g_player.acceleration;
			g_player.skyFlag = true;
		}
	}

	if (Map_Collision_Check(g_player.posX, g_player.posY - JUMP_POWER, 2, 2))
	{
		g_player.acceleration = 0.f;
		g_player.skyFlag = false;
	}
	

	if (g_Key[DOWN] == ON)
	{
		// 次に動いた値で下にブロックがあるかどうか先に調べている
		if (!Map_Collision_Check(g_player.posX, g_player.posY + MOVE_SPEED, 2, 2))
		{
			// なければ移動を続ける
			g_player.posY += MOVE_SPEED;
		}
	}
}



