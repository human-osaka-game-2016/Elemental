/**
 * @file GameSceneCntrol.cpp
 * @breif �Q�[���S�̂̑���Ɋ֌W���鏈���̓��e�������Ă���
 * @author �ēc�N�ǁA�R�{�ϑ��Y�A�ݖ{��́A����G���A�c���M��A�|���ĕ��A�ѓc����
 * @date 2016�NX��Y��
 */

#define DIRECTINPUT_VERSION 0x0800

#include <dinput.h>
#include <Direct_Draw.h>
#include <Direct_Key_Input.h>
#include "GameSceneDraw.h"
#include "GameSceneCntrol.h"
#include "PlayerControl.h"


void Control()
{
	Get_Key_State();

	Check_Key(DIK_LEFT, LEFT);
	Check_Key(DIK_RIGHT, RIGHT);
	Check_Key(DIK_UP, UP);
	Check_Key(DIK_DOWN, DOWN);
	Check_Key(DIK_Z, Z);

	Player_Control();

}

bool Collision_Check(float _x, float _y, int _sx, int _sy)
{
	bool ret = false;
	int ix, iy;

	if ((int)_x % TIPSIZE != 0)
	{
		_sx++;
	}

	if ((int)_y % TIPSIZE != 0)
	{
		_sy++;
	}

	ix = (int)_x / TIPSIZE;
	iy = (int)_y / TIPSIZE;

	for (int i = 0; i < _sx; i++)
	{
		for (int j = 0; j < _sy; j++)
		{
			if (map[iy + j][ix + i] == 1)
			{
				ret = true;
				break;
			}
		}
	}

	return ret;
}

