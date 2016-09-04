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
		g_player.moveFlag = true;
		g_player.leftFlag = true;

		if (g_player.leftdashFlag == true)
		{
			// ���ɓ������l�ō��Ƀu���b�N�����邩�ǂ�����ɒ��ׂĂ���
			if (!Map_Collision_Check(g_player.posX - RUN_SPEED, g_player.posY, 2, (g_player.skyFlag) ? 2 : 1))
			{
				// �Ȃ���Έړ��𑱂���
				g_player.posX -= RUN_SPEED;		
			}
		}
		else
		{
			// ���ɓ������l�ō��Ƀu���b�N�����邩�ǂ�����ɒ��ׂĂ���
			if (!Map_Collision_Check(g_player.posX - WALK_SPEED, g_player.posY, 2, (g_player.skyFlag) ? 2 : 1))
			{
				// �Ȃ���Έړ��𑱂���
				g_player.posX -= WALK_SPEED;
			}
		}
	}
	else
	{
		g_player.moveFlag = false;
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
		g_player.moveFlag = true;
		g_player.leftFlag = false;

		if (g_player.rightdashFlag == true)
		{
			// ���ɓ������l�ō��Ƀu���b�N�����邩�ǂ�����ɒ��ׂĂ���
			if (!Map_Collision_Check(g_player.posX + RUN_SPEED, g_player.posY, 2, (g_player.skyFlag) ? 2 : 1))
			{
				// �Ȃ���Έړ��𑱂���
				g_player.posX += RUN_SPEED;
			}
		}
		else
		{
			// ���ɓ������l�ō��Ƀu���b�N�����邩�ǂ�����ɒ��ׂĂ���
			if (!Map_Collision_Check(g_player.posX + WALK_SPEED, g_player.posY, 2, (g_player.skyFlag) ? 2 : 1))
			{
				// �Ȃ���Έړ��𑱂���
				g_player.posX += WALK_SPEED;
			}
		}
	}


	
	if (g_Key[UP] == PUSH && g_player.skyFlag == false)
	{
		g_player.jumpFlag = true;			// �W�����v����̂Ńt���O��true��
		g_player.skyFlag = true;			// �󒆂ɂ�����̂Ńt���O��true��
		g_player.acceleration = JUMP_POWER;	// �����x�ɃW�����v�̌��E�l����

		
	}

	// �󒆂ɂ���Ԏ�l���̈ړ���Ƀu���b�N�܂��̓M�~�b�N�����邩�ǂ������ׂĂ���
	if (Map_Collision_Check(g_player.posX, g_player.posY + g_player.acceleration, 2, 2) /*|| Gimmick_Collision_Check(g_player.posX, g_player.posY + g_player.acceleration)*/)
	{
		if (g_player.acceleration > 0.0f)
		{
			g_player.skyFlag = false;
			g_player.jumpFlag = false;
		}
		g_player.acceleration = 0.0f;
	}
	else
	{
		g_player.acceleration += GRAVITY;			// ����Ƀu���b�N���Ȃ���Ή����x��GRAVITY�̒l���v���X���Ăǂ�ǂ��ɓ�����	
	}

	g_player.posY += g_player.acceleration;
}

void Player_Aura_Control()
{
	if (g_Key[Z] == ON)
	{
		g_player.p_elerent = FLAME;
		g_player.drawFlag = false;

		return;
	}
	else if (g_Key[X] == ON)
	{
		g_player.p_elerent = ICE;
		g_player.drawFlag = false;

		return;
	}
	else if (g_Key[C] == ON)
	{
		g_player.p_elerent = WIND;
		g_player.drawFlag = false;

		return;
	}
	else
	{
		g_player.p_elerent = NORMAL;
		g_player.drawFlag = true;

		for (int i = 0; i < BULLET_MAX; i++)
		{
			g_bullet[i].drawFlag = false;
			g_bullet[i].initFlag = true;
		}
	}
}

// ��l���̒e�o���̊֐�
void Player_Bullet_Control()
{
	// �o����e�̍ő�l����for�ŉ񂵂Ă�
	for (int i = 0; i < BULLET_MAX; i++)
	{
		if (g_Key[SPACE] == PUSH && g_bullet[i].drawFlag == false && g_player.drawFlag == false)
		{
			g_bullet[i].posX = g_player.posX;
			g_bullet[i].posY = g_player.posY;
			g_bullet[i].drawFlag = true;
			g_bullet[i].initFlag = false;
			g_bullet[i].leftFlag = g_player.leftFlag;
			break;
		}
	}

	// �o�����e�̍��W�𓮂����Ă���
	for (int i = 0; i < BULLET_MAX; i++)
	{

		if (g_bullet[i].drawFlag == true)
		{
			if (g_bullet[i].leftFlag == true)
			{
				g_bullet[i].posX -= BULLET_SPEED;

				for (int j = 0; j < 4; j++)
				{
					g_bullet[i].bullet[j].x -= BULLET_SPEED;
				}
			}
			else 
			{
				g_bullet[i].posX += BULLET_SPEED;

				for (int j = 0; j < 4; j++)
				{
					g_bullet[i].bullet[j].x += BULLET_SPEED;

				}
			}
		}
	
	}
}



