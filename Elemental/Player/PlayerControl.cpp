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
#include "PlayerDraw.h"
#include "PlayerControl.h"

int g_rightdashcount = 0;
int g_leftdashcount = 0;

void Player_Control()
{
	if (g_Key[LEFT] == ON)
	{
		if (g_leftdashcount > 0 && g_leftdashcount < 29)
		{
			g_player.leftdashFlag = true;		// 1～28秒の間に左のキーが押されたらtrue
		}
	}
	else
	{
		g_player.leftdashFlag = false;			// 押されなければfalse
	}

	if (g_Key[LEFT] == ON)
	{
		g_leftdashcount = 30;
	}

	g_leftdashcount--;


	if (g_Key[LEFT] == ON)
	{
		if (g_player.leftdashFlag == true)
		{
			// 次に動いた値で左にブロックがあるかどうか先に調べている
			if (!Map_Collision_Check(g_player.posX - RUN_SPEED, g_player.posY, 2, 2))
			{
				// なければ移動を続ける
				g_player.posX -= RUN_SPEED;
			}
		}
		else
		{
			// 次に動いた値で左にブロックがあるかどうか先に調べている
			if (!Map_Collision_Check(g_player.posX - WALK_SPEED, g_player.posY, 2, 2))
			{
				// なければ移動を続ける
				g_player.posX -= WALK_SPEED;
			}
		}
	}

	if (g_Key[RIGHT] == ON)
	{
		if (g_rightdashcount > 0 && g_rightdashcount < 29)
		{
			g_player.rightdashFlag = true;
		}
	}
	else
	{
		g_player.rightdashFlag = false;
	}

	if (g_Key[RIGHT] == ON)
	{
		g_rightdashcount = 30;
	}

	g_rightdashcount--;
		
	if (g_Key[RIGHT] == ON)
	{
		if (g_player.rightdashFlag == true)
		{
			// 次に動いた値で左にブロックがあるかどうか先に調べている
			if (!Map_Collision_Check(g_player.posX + RUN_SPEED, g_player.posY, 2, 2))
			{
				// なければ移動を続ける
				g_player.posX += RUN_SPEED;
			}
		}
		else
		{
			// 次に動いた値で左にブロックがあるかどうか先に調べている
			if (!Map_Collision_Check(g_player.posX + WALK_SPEED, g_player.posY, 2, 2))
			{
				// なければ移動を続ける
				g_player.posX += WALK_SPEED;
			}
		}
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
		g_player.posY += g_player.acceleration;		// プラスされた加速度をさらに主人公のY座標にプラスしていく

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
		if (!Map_Collision_Check(g_player.posX, g_player.posY + WALK_SPEED, 2, 2))
		{
			// なければ移動を続ける
			g_player.posY += WALK_SPEED;
		}
	}
}

void Player_Flame_Control()
{
	if (g_Key[Z] == ON && g_player.flamedrawFlag == false)
	{
		g_player.flamedrawFlag = true;
		g_player.drawFlag = false;
	}

	if (g_Key[Z] == OFF && g_player.flamedrawFlag == true)
	{
		g_player.flamedrawFlag = false;
		g_player.drawFlag = true;
	}
}

void Player_Ice_Control()
{
	if (g_Key[X] == ON && g_player.icedrawFlag == false)
	{
		g_player.icedrawFlag = true;
		g_player.drawFlag = false;
	}

	if (g_Key[X] == OFF && g_player.icedrawFlag == true)
	{
		g_player.icedrawFlag = false;
		g_player.drawFlag = true;
	}
}

void Player_Wind_Control()
{
	if (g_Key[C] == ON && g_player.winddrawFlag == false)
	{
		g_player.winddrawFlag = true;
		g_player.drawFlag = false;
	}

	if (g_Key[C] == OFF && g_player.winddrawFlag == true)
	{
		g_player.winddrawFlag = false;
		g_player.drawFlag = true;
	}
}
/*
void Player_aura_Control(KEYKIND _key, bool _auraflag)
{
	if (g_Key[_key] == ON && _auraflag == false)
	{
		_auraflag = true;
		g_player.drawFlag = false;
	}

	if (g_Key[_key] == OFF && _auraflag == true)
	{
		_auraflag = false;
		g_player.drawFlag = true;
	}
}
*/

// 主人公の弾出しの関数
void Player_Bullet_Control()
{
	// 出せる弾の最大値だけforで回してる
	for (int i = 0; i < BULLET_MAX; i++)
	{
		if (g_Key[SPACE] == PUSH && g_bullet[i].drawFlag == false/*&& g_player.fjamedrawFlag == true || g_player.icedrawFlag =- true || g_player.winddrawFlag == true*/)
		{
			g_bullet[i].posX = g_player.posX;
			g_bullet[i].posY = g_player.posY;
			g_bullet[i].drawFlag = true;
			g_bullet[i].initFlag = false;
			break;
		}
	}

	// 出した弾の座標を動かしている
	for (int i = 0; i < BULLET_MAX; i++)
	{
		if (g_bullet[i].drawFlag == true)
		{
			g_bullet[i].posX += BULLET_SPEED;

			for (int j = 0; j < 4; j++)
			{
				g_bullet[i].bullet[j].x += BULLET_SPEED;
			}
		}
	}
}



