/**
 * @file EnemyControl.cpp
 * @breif �S�Ă̓G�̑���t�@�C��
 
 * �S�Ă̓G�̑���ɕK�v�ȏ����������Ă���

 */


#include "../GameScene/GameSceneDraw.h"
#include "../GameScene/GameSceneControl.h"
#include "../GameScene/GameSceneInit.h"
#include "../Player/PlayerControl.h"
#include "../Enemy/EnemyControl.h"
#include "../Gmmick/WindGimmick_Draw.h"

// �R�h���̑���֐�
void Kodora_Control()
{
	for (int i = 0; i < KODORA_MAX; i++)
	{
		if (g_kodora[i].drawFlag == true)
		{
			//�G�̕������m�F����
			if (g_kodora[i].posX - g_player.posX < 0)
			{
				g_kodora[i].directionID = Right;
			}
			else
			{
				g_kodora[i].directionID = Left;
			}

			if (abs(g_kodora[i].posX - g_player.posX) < (TIPSIZE * 4))	// �R�h���͎�l���̑O��4�}�X�܂ňړ����Ă���
			{
				// �G�̍U�������������ɓ����\��
			}
			else if (abs(g_kodora[i].posX - g_player.posX) < (TIPSIZE * 8))// ��l�����O��8�}�X�ȓ��ɂȂ�Ɠ���
			{
				if (g_kodora[i].directionID == Left)
				{
					g_kodora[i].posX -= ENEMY_WALK;
				}
				else if (g_kodora[i].directionID == Right)
				{
					g_kodora[i].posX += ENEMY_WALK;
				}
			}

			for (int k = 0; k < BULLET_MAX; k++)
			{
				for (int j = 0; j < 4; j++)
				{
					if (Collision_Check(g_bullet[k].bullet[j].x, g_kodora[i].posX, g_bullet[k].bullet[j].y, g_kodora[i].posY, TIPSIZE))
					{
						g_kodora[i].hitFlag = true;			// ���肵����`�͈̔͂ɓ����Ă�����e�ɓ��������t���O��true�ɂ��Ă���
						g_gimmick.drawFlag = true;
						g_bullet[k].drawFlag = false;	// ������΂����e�̕b������Ȃ��̂�false�ɂ���
						g_bullet[k].initFlag = true;	// �������t���O��true�ɂ��Ȃ��Ǝ��̒e���o�Ȃ��Ȃ�
					}
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
		if (g_skereton[i].drawFlag == true)
		{
			//�G�̕������m�F����
			if (g_skereton[i].posX - g_player.posX < 0)
			{
				g_skereton[i].directionID = Right;
			}
			else
			{
				g_skereton[i].directionID = Left;
			}

			if (abs(g_skereton[i].posX - g_player.posX) < (TIPSIZE * 4))	// �R�h���͎�l���̑O��4�}�X�܂ňړ����Ă���
			{
				// �G�̍U�������������ɓ����\��
			}
			else if (abs(g_skereton[i].posX - g_player.posX) < (TIPSIZE * 8))// ��l�����O��8�}�X�ȓ��ɂȂ�Ɠ���
			{
				if (g_skereton[i].directionID == Left)
				{
					g_skereton[i].posX -= ENEMY_WALK;
				}
				else if (g_skereton[i].directionID == Right)
				{
					g_skereton[i].posX += ENEMY_WALK;
				}
			}
		}
	}
}


// �X���C���̑���֐�
void Slime_Control()
{
	for (int i = 0; i < SLIME_MAX; i++)
	{
		if (g_slime[i].drawFlag == true)
		{
			//�G�̕������m�F����
			if (g_slime[i].posX - g_player.posX < 0)
			{
				g_slime[i].directionID = Right;
			}
			else
			{
				g_slime[i].directionID = Left;
			}

			if (abs(g_slime[i].posX - g_player.posX) < (TIPSIZE * 4))	// �R�h���͎�l���̑O��4�}�X�܂ňړ����Ă���
			{
				// �G�̍U�������������ɓ����\��
			}
			else if (abs(g_slime[i].posX - g_player.posX) < (TIPSIZE * 8))// ��l�����O��8�}�X�ȓ��ɂȂ�Ɠ���
			{
				if (g_slime[i].directionID == Left)
				{
					g_slime[i].posX -= ENEMY_WALK;
				}
				else if (g_slime[i].directionID == Right)
				{
					g_slime[i].posX += ENEMY_WALK;
				}
			}
			if (g_slime[i].directionID == Left)
			{
				if (g_windgimmick[1].x < g_slime[i].posX && g_gimmick.outdreakFlag == true && g_gimmick.drawFlag == true)
				{
					g_gimmick.hitFlag = true;
				}
			}
			else if (g_slime[i].directionID == Right)
			{
				if (g_windgimmick[0].x < g_slime[i].posX && g_gimmick.outdreakFlag == true && g_gimmick.drawFlag == true)
				{
					g_gimmick.hitFlag = true;
				}
			}
		}
	}
}

void Kodora_Init()
{
	for (int y = 0; y < MAP_HEIGHT; y++)
	{
		for (int x = 0; x < MAP_WIDTH; x++)
		{
			if (map[y][x] == 10)
			{
				for (int i = 0; i < KODORA_MAX; i++)
				{
					g_kodora[i].posX = (float)(x * TIPSIZE);
					g_kodora[i].posY = (float)(y * TIPSIZE);
				}
			}
		}
	}
}

void Slime_Init()
{
	for (int y = 0; y < MAP_HEIGHT; y++)
	{
		for (int x = 0; x < MAP_WIDTH; x++)
		{
			if (map[y][x] == 20)
			{
				for (int i = 0; i < SLIME_MAX; i++)
				{
					g_slime[i].posX = (float)(x * TIPSIZE);
					g_slime[i].posY = (float)(y * TIPSIZE);
				}
			}
		}
	}
}