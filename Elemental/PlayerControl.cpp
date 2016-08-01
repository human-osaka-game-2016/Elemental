/**
 * @file PlayerCntrol.cpp
 * @breif 主人公の操作に関係する処理の内容を書いている
 * @author 柴田哲良、山本倫太郎、岸本大河、水瀧秀明、田中貴大、竹村翔平、飯田純矢
 * @date 2016年X月Y日
 */

#define DIRECTINPUT_VERSION 0x0800

#include <dinput.h>
#include <Direct_Key_Input.h>
#include "GameSceneDraw.h"
#include "GameSceneCntrol.h"
#include "PlayerDraw.h"
#include "PlayerControl.h"

#define JUMP_POWER -20.f
#define GRAVITY 0.6f

void Player_Control()
{
	if (g_Key[LEFT] == ON)
	{
		if (!Collision_Check(g_player.posX - MOVE_SPEED, g_player.posY, 1, 2)) 
		{
			g_player.posX -= MOVE_SPEED;

			if (g_player.posX < 400.f)
			{
				g_ScreenOriginX -= MOVE_SPEED;
			}
		}
	}

	if (g_Key[RIGHT] == ON)
	{
		if (!Collision_Check(g_player.posX + MOVE_SPEED, g_player.posY, 1, 2)) 
		{
			g_player.posX += MOVE_SPEED;

			if (g_player.posX > 820.f)
			{
				g_ScreenOriginX += MOVE_SPEED;
			}
		}
	}
	if (g_Key[UP] == ON)
	{
		if (!Collision_Check(g_player.posX, g_player.posY - MOVE_SPEED, 1, 2))
		{
			g_player.posY -= MOVE_SPEED;

		}
	}
	if (g_Key[DOWN] == ON)
	{
		if (!Collision_Check(g_player.posX, g_player.posY + MOVE_SPEED, 1, 2))
		{
			g_player.posY += MOVE_SPEED;
		}
	}
}



