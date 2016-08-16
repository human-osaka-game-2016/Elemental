/**
 * @file PlayerCntrol.cpp
 * @breif ��l���̑���t�@�C��

 *  ��l���̑���ɕK�v�ȏ����������Ă���

 */

#define DIRECTINPUT_VERSION 0x0800

#include <dinput.h>
#include <Direct_Key_Input.h>
#include "../GameScene/GameSceneDraw.h"
#include "../GameScene/GameSceneControl.h"
#include "../GameScene/GameSceneInit.h"
#include "PlayerControl.h"

int g_rightdashcount = 0;
int g_leftdashcount = 0;

void Player_Control()
{
	if (g_Key[LEFT] == ON)
	{
		if (g_leftdashcount > 0 && g_leftdashcount < 29)
		{
			g_player.leftdashFlag = true;		// 1�`28�b�̊Ԃɍ��̃L�[�������ꂽ��true
		}
	}
	else
	{
		g_player.leftdashFlag = false;			// ������Ȃ����false
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
			// ���ɓ������l�ō��Ƀu���b�N�����邩�ǂ�����ɒ��ׂĂ���
			if (!Map_Collision_Check(g_player.posX - 6, g_player.posY, 2, 2))
			{
				// �Ȃ���Έړ��𑱂���
				g_player.posX -= 6;
			}
		}
		else
		{
			// ���ɓ������l�ō��Ƀu���b�N�����邩�ǂ�����ɒ��ׂĂ���
			if (!Map_Collision_Check(g_player.posX - 4, g_player.posY, 2, 2))
			{
				// �Ȃ���Έړ��𑱂���
				g_player.posX -= 4;
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
			// ���ɓ������l�ō��Ƀu���b�N�����邩�ǂ�����ɒ��ׂĂ���
			if (!Map_Collision_Check(g_player.posX + 6, g_player.posY, 2, 2))
			{
				// �Ȃ���Έړ��𑱂���
				g_player.posX += 6;
			}
		}
		else
		{
			// ���ɓ������l�ō��Ƀu���b�N�����邩�ǂ�����ɒ��ׂĂ���
			if (!Map_Collision_Check(g_player.posX + 4, g_player.posY, 2, 2))
			{
				// �Ȃ���Έړ��𑱂���
				g_player.posX += 4;
			}
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
		g_player.posY += g_player.acceleration;	// �v���X���ꂽ�����x������Ɏ�l����Y���W�Ƀv���X���Ă���

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
		// ���ɓ������l�ŉ��Ƀu���b�N�����邩�ǂ�����ɒ��ׂĂ���
		if (!Map_Collision_Check(g_player.posX, g_player.posY + MOVE_SPEED, 2, 2))
		{
			// �Ȃ���Έړ��𑱂���
			g_player.posY += MOVE_SPEED;
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
void Player_Bullet_Control()
{

}


