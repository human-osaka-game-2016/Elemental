/**
 * @file GameSceneCntrol.cpp
 * @breif ����̊�ՂɂȂ�t�@�C��

 * �Q�[���S�̂̑���ɕK�v�ȏ����������Ă���

 */

//! dinput.h���g���Ƃ���h����ɂ�������Ȃ���΂Ȃ�Ȃ�
#define DIRECTINPUT_VERSION 0x0800	

#include <dinput.h>
#include <Direct_Key_Input.h>
#include "GameSceneDraw.h"
#include "GameSceneControl.h"
#include "GameSceneInit.h"
#include "../Player/PlayerDraw.h"
#include "../Player/PlayerControl.h"
#include "../Enemy/EnemyControl.h"

// ����֐�
void Control()
{
	Get_Key_State();

	Check_Key(DIK_LEFT, LEFT);
	Check_Key(DIK_RIGHT, RIGHT);
	Check_Key(DIK_UP, UP);
	Check_Key(DIK_DOWN, DOWN);
	Check_Key(DIK_A, A);

	Player_Control();
	Map_Control();

}

// �ڂ̃V�X�e���̊֐�
void Map_Control()
{
	if (g_Key[A] == ON)
	{
		if (g_Key[LEFT] == ON)
		{
			g_ScreenOriginX -= MOVE_SPEED;
		}
		if (g_Key[RIGHT] == ON)
		{
			g_ScreenOriginX += MOVE_SPEED;
		}
	}
}

bool Map_Collision_Check(float _x, float _y, int _sx, int _sy)
{
	bool ret = false;		// �}�b�v�`�b�v�ɂ������Ă��Ȃ�������false
	int ix, iy;			

	if ((int)_x % TIPSIZE != 0)
	{
		_sx++;
	}

	if ((int)_y % TIPSIZE != 0)
	{
		_sy++;
	}

	ix = (int)_x / TIPSIZE;			// ���݂�X���̏ꏊ
	iy = (int)_y / TIPSIZE;			// ���݂�Y���̏ꏊ

	for (int i = 0; i < _sx; i++)
	{
		for (int j = 0; j < _sy; j++)
		{
			if (map[iy + j][ix + i] == 1)
			{
				ret = true;		// �}�b�v�`�b�v�ɂ������Ă�����true
				break;			// �������Ă���Ƃ킩�������炱��ȏ�̏���������K�v�͂Ȃ�
			}
		}
	}

	return ret;		//�@�^(�������Ă�)���U(�������ĂȂ�)�̒l��Ԃ��Ă���
}

// ��`�̓����蔻��̊֐�
bool Collision_Check(float _rectAX, float _rectBX, float _rectAY, float _rectBY, int _size)
{
	bool hit = false;

	// abs��()���̌v�Z�̐�Βl��Ԃ��Ă����
	if ((abs(_rectAX - _rectBX) < _size) && (abs(_rectAY - _rectBY) < _size))
	{
		hit = true;
	}

	return hit;
}