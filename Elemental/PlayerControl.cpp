/**
 * @file PlayerCntrol.cpp
 * @breif εlφΜμΙΦW·ιΜΰeπ’Δ’ι
 * @author ΔcNΗAR{ΟΎYAέ{εΝAλGΎAcMεA|ΊγΔ½AΡcξ
 * @date 2016NXYϊ
 */

#define DIRECTINPUT_VERSION 0x0800

#include <dinput.h>
#include <Direct_Key_Input.h>
#include "GameSceneDraw.h"
#include "GameSceneControl.h"
#include "PlayerDraw.h"
#include "PlayerControl.h"

#define JUMP_POWER -20.f
#define GRAVITY 0.6f

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
	if (g_Key[UP] == ON)
	{
		if (!Map_Collision_Check(g_player.posX, g_player.posY - MOVE_SPEED, 2, 2))
		{
			g_player.posY -= MOVE_SPEED;

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



