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
		if (!Map_Collision_Check(g_player.posX - MOVE_SPEED, g_player.posY, 1, 2)) 
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
		if (!Map_Collision_Check(g_player.posX + MOVE_SPEED, g_player.posY, 1, 2)) 
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
		if (!Map_Collision_Check(g_player.posX, g_player.posY - MOVE_SPEED, 1, 2))
		{
			g_player.posY -= MOVE_SPEED;
		}
	}
	if (g_Key[DOWN] == ON)
	{
		if (!Map_Collision_Check(g_player.posX, g_player.posY + MOVE_SPEED, 1, 2))
		{
			g_player.posY += MOVE_SPEED;
		}
	}
}

bool Map_Collision_Check(float x, float y, int sx, int sy)
{
	bool ret = false;
	int ix, iy;

	if ((int)x % TIPSIZE != 0)
	{
		sx++;
	}

	if ((int)y % TIPSIZE != 0)
	{
		sy++;
	}

	ix = (int)x / TIPSIZE;
	iy = (int)y / TIPSIZE;

	for (int i = 0; i < sx; i++)
	{
		for (int j = 0; j < sy; j++)
		{
			if (map[iy+j][ix+i] == 1) 
			{
				ret = true;
				break;
			}
		}
	}

	return ret;
}



