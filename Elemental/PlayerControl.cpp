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
#include "GameSceneControl.h"
#include "GameSceneInit.h"

#define JUMP_POWER 16.f
#define GRAVITY 0.4f

void Player_Control()
{

	if (g_Key[LEFT] == ON)
	{
		if (!Map_Collision_Check(g_player.posX - MOVE_SPEED, g_player.posY, 2, 2))
		{
			g_player.posX -= MOVE_SPEED;
		}
	}
	if (g_Key[RIGHT] == ON)
	{
		if (!Map_Collision_Check(g_player.posX + MOVE_SPEED, g_player.posY, 2, 2))
		{
			g_player.posX += MOVE_SPEED;
		}

	}
	if (g_Key[UP] == PUSH && g_player.skyFlag == false)
	{
		g_player.jumpFlag = true;
		g_player.skyFlag = true;
		g_player.speed -= JUMP_POWER;
	}
	if (g_player.jumpFlag == true)
	{
		if (!Map_Collision_Check(g_player.posX, g_player.posY + JUMP_POWER, 2, 2))
		{
			g_player.speed += GRAVITY;
			g_player.posY += g_player.speed;
		}
	}


	if (g_Key[DOWN] == ON)
	{
		if (!Map_Collision_Check(g_player.posX, g_player.posY + MOVE_SPEED, 2, 2))
		{
			g_player.posY += MOVE_SPEED;
		}
	}
}



