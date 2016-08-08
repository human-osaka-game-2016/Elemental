/**
 * @file PlayerCntrol.cpp
 * @breif ��l���̑���t�@�C��

 *  ��l���̑���ɕK�v�ȏ����������Ă���

 */

#define DIRECTINPUT_VERSION 0x0800

#include <dinput.h>
#include <Direct_Key_Input.h>
#include "GameSceneDraw.h"
#include "GameSceneControl.h"
#include "GameSceneInit.h"
#include "PlayerControl.h"

void Player_Control()
{

	if (g_Key[LEFT] == ON)
	{
		// ���ɓ������l�ō��Ƀu���b�N�����邩�ǂ�����ɒ��ׂĂ���
		if (!Map_Collision_Check(g_player.posX - MOVE_SPEED, g_player.posY, 2, 2))
		{
			// �Ȃ���Έړ��𑱂���
			g_player.posX -= MOVE_SPEED;
		}
	}

	if (g_Key[RIGHT] == ON)
	{
		// ���ɓ������l�ŉE�Ƀu���b�N�����邩�ǂ�����ɒ��ׂĂ���
		if (!Map_Collision_Check(g_player.posX + MOVE_SPEED, g_player.posY, 2, 2))
		{
			// �Ȃ���Έړ��𑱂���
			g_player.posX += MOVE_SPEED;
		}

	}



	if (g_Key[UP] == PUSH && g_player.skyFlag == false)
	{
		g_player.jumpFlag = true;			// �W�����v����̂Ńt���O��true��
		g_player.skyFlag = true;			// �󒆂ɂ�����̂Ńt���O��true��
		g_player.acceleration = JUMP_POWER;	// �����x�ɃW�����v�̌��E�l����
	}

	// �t���O��true�Ȃ珈��������
	if (g_player.jumpFlag == true)
	{
		/*
		����𔲂��Ə�̔��肪�Ȃ��Ȃ̂Ŕ�������݂����Ȃ̂������ł���(��ɍs���Ƃ��̂�)
		if (Map_Collision_Check(g_player.posX, g_player.posY + JUMP_POWER, 2, 2))
		{
			if (g_player.acceleration < 0)
			{
				g_player.acceleration = 0.4f;
			}
		}
		*/

		// �󒆂���Ԏ�l���̏�Ƀu���b�N�����邩�ǂ������ׂĂ���
		if (Map_Collision_Check(g_player.posX, g_player.posY + JUMP_POWER, 2, 2))
		{
			if (g_player.acceleration < 0)
			{
				g_player.acceleration = 0;
			}
		}

		g_player.acceleration += GRAVITY;			// ����Ƀu���b�N���Ȃ���Ή����x��GRAVITY�̒l���v���X���Ăǂ�ǂ��ɓ�����
		g_player.posY += g_player.acceleration;		// �v���X���ꂽ�����x������Ɏ�l����Y���W�Ƀv���X���Ă���

		// ��l���̎���Ƀu���b�N�����邩�ǂ������ׂĂ���
		if (Map_Collision_Check(g_player.posX, g_player.posY - JUMP_POWER, 2, 2))
		{

			if (g_player.acceleration > 0)
			{
				g_player.skyFlag = false;
				g_player.jumpFlag = false;
			}
		}
	}

	// ���R�����̏���
	if (!Map_Collision_Check(g_player.posX, g_player.posY - JUMP_POWER, 2, 2))
	{
		// �����Ă����玩���Ŕ���̂���Ƃ���܂ŉ�����
		if (g_player.jumpFlag == false)
		{
			g_player.acceleration += GRAVITY;
			g_player.posY += g_player.acceleration;
		}
	}
	// ���n�����Ƃ��̏���
	if (Map_Collision_Check(g_player.posX, g_player.posY - JUMP_POWER, 2, 2))
	{
		g_player.acceleration = 0.f;
		// �t���O��false�ɂ��Ă�����x�W�����v�ł���悤�ɂ��Ă���
		g_player.skyFlag = false;
	}

	if (g_Key[DOWN] == ON)
	{
		// ���ɓ������l�ŉ��Ƀu���b�N�����邩�ǂ�����ɒ��ׂĂ���
		if (!Map_Collision_Check(g_player.posX, g_player.posY + MOVE_SPEED, 2, 2))
		{
			// �Ȃ���Έړ��𑱂���
			g_player.posY += MOVE_SPEED;
		}
	}
}



