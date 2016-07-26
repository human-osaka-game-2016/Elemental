#include <dinput.h>
#include <Direct_Draw.h>
#include <Direct_Key_Input.h>
#include "GameSceneDraw.h"
#include "GameSceneCntrol.h"

void Control()
{
	Get_Key_State();
	Check_Key(DIK_LEFT, LEFT);
	Check_Key(DIK_RIGHT, RIGHT);
	Player_Control();
}

void Player_Control()
{
	if (g_Key[LEFT] == ON)
	{
		for (int i = 0; i < 4; i++)
		{
			g_maptip[i].m_x += MOVE_SPEED;
		}
	}

	if (g_Key[RIGHT] == ON)
	{
		for (int i = 0; i < 4; i++)
		{
			g_maptip[i].m_x -= MOVE_SPEED;
		}
	}
}
