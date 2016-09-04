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

			if (abs(g_kodora[i].posX - g_player.posX) < (TIPSIZE * 4))		// �R�h���͎�l���̑O��4�}�X�܂ňړ����Ă���
			{
				// �G�̍U�������������ɓ����\��
			}
			else if (abs(g_kodora[i].posX - g_player.posX) < (TIPSIZE * 8))		// ��l�����O��8�}�X�ȓ��ɂȂ�Ɠ���
			{
				if (g_kodora[i].directionID == Left)
				{
					g_kodora[i].posX -= ENEMY_WALK;
					g_kodora[i].stateID = Move;
				}
				else if (g_kodora[i].directionID == Right)
				{
					g_kodora[i].posX += ENEMY_WALK;
					g_kodora[i].stateID = Move;
				}
			}
			else
			{
				g_kodora[i].stateID = Wait;
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
		if (g_skeleton[i].drawFlag == true)
		{
			//�G�̕������m�F����
			if (g_skeleton[i].posX - g_player.posX < 0)
			{
				g_skeleton[i].directionID = Right;
			}
			else
			{
				g_skeleton[i].directionID = Left;
			}

			if (abs(g_skeleton[i].posX - g_player.posX) < (TIPSIZE * 4))	// �X�P���g���͎�l���̑O��4�}�X�܂ňړ����Ă���
			{
				// �G�̍U�������������ɓ����\��
			}
			else if (abs(g_skeleton[i].posX - g_player.posX) < (TIPSIZE * 8))// ��l�����O��8�}�X�ȓ��ɂȂ�Ɠ���
			{
				if (g_skeleton[i].directionID == Left)
				{
					g_skeleton[i].posX -= ENEMY_WALK;
					g_skeleton[i].stateID = Move;
				}
				else if (g_skeleton[i].directionID == Right)
				{
					g_skeleton[i].posX += ENEMY_WALK;
					g_skeleton[i].stateID = Move;
				}
			}
			else
			{
				g_skeleton[i].stateID = Wait;
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

			if (abs(g_slime[i].posX - g_player.posX) < (TIPSIZE * 4))	// �X���C���͎�l���̑O��4�}�X�܂ňړ����Ă���
			{
				// �G�̍U�������������ɓ����\��
			}
			else if (abs(g_slime[i].posX - g_player.posX) < (TIPSIZE * 8))// ��l�����O��8�}�X�ȓ��ɂȂ�Ɠ���
			{
				if (g_slime[i].directionID == Left)
				{
					g_slime[i].posX -= ENEMY_WALK;
					g_slime[i].stateID = Move;
				}
				else if (g_slime[i].directionID == Right)
				{
					g_slime[i].posX += ENEMY_WALK;
					g_slime[i].stateID = Move;
				}
			}
			else
			{
				g_slime[i].stateID = Wait;
			}
		}
	}
}

