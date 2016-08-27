/**
 * @file EnemyControl.cpp
 * @breif �S�Ă̓G�̑���t�@�C��
 
 * �S�Ă̓G�̑���ɕK�v�ȏ����������Ă���

 */


#include "../GameScene/GameSceneDraw.h"
#include "../GameScene/GameSceneControl.h"
#include "../GameScene/GameSceneInit.h"
#include "../Player/PlayerControl.h"
#include "../Gmmick/WindGimmick_Draw.h"

// �R�h���̑���֐�
void Kodora_Control()
{
	for (int i = 0; i < KODORA_MAX; i++)
	{
		if (g_kodora[i].drawFlag == true)
		{
			// ��l�����O��8�}�X�ȓ��ɂȂ�Ɠ���
			if (abs(g_kodora[i].posX - g_player.posX) < (TIPSIZE * 8))
			{
				g_kodora[i].posX -= WALK_SPEED;
			}

			// �R�h���͎�l���̑O��4�}�X�܂ňړ����Ă���
			if (abs(g_kodora[i].posX - g_player.posX) < (TIPSIZE * 4))
			{
				g_kodora[i].posX += WALK_SPEED;
			}
		}
	}

	for (int k = 0; k < KODORA_MAX; k++)
	{
		for (int i = 0; i < BULLET_MAX; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				if (Collision_Check(g_bullet[i].bullet[j].x, g_kodora[k].posX, g_bullet[i].bullet[j].y, g_kodora[k].posY, TIPSIZE))
				{
					g_kodora[k].drawFlag = false;
					g_kodora[k].hitFlag = true;			// ���肵����`�͈̔͂ɓ����Ă�����e�ɓ��������t���O��true�ɂ��Ă���
					g_bullet[i].drawFlag = false;	// ������΂����e�̕b������Ȃ��̂�false�ɂ���
					g_bullet[i].initFlag = true;	// �������t���O��true�ɂ��Ȃ��Ǝ��̒e���o�Ȃ��Ȃ�
				}
			}
		}
	}
}

// �X�P���g���̑���֐�
void skeleton_Control()
{
	for (int i = 0; i < SKERETON_MAX; i++)
	{
		// ��l�����O��8�}�X�ȓ��ɂȂ�Ɠ���
		if (abs(g_skereton[i].posX - g_player.posX) < (TIPSIZE * 8))
		{
			g_skereton[i].posX -= WALK_SPEED;
		}

		// �X�P���g���͎�l���̑O��2�}�X�܂ňړ����Ă���
		if (abs(g_skereton[i].posX - g_player.posX) < (TIPSIZE * 2))
		{
			g_skereton[i].posX += WALK_SPEED;
		}
	}

	for (int i = 0; i < SKERETON_MAX; i++)
	{
		for (int j = 0; j < 4; j++)
		{
	
		}
	}
}

/*
// �X���C���̑���֐�
void Slime_Control()
{
	// ��l�����O��8�}�X�ȓ��ɂȂ�Ɠ���
	if (abs(g_kodora.posX - g_player.posX) < (TIPSIZE * 8))
	{
		g_kodora.posX -= WALK_SPEED;
	}

	// �X�P���g���͎�l���̑O��2�}�X�܂ňړ����Ă���
	if (abs(g_kodora.posX - g_player.posX) < (TIPSIZE * 3))
	{
		g_kodora.posX += WALK_SPEED;
	}
}*/