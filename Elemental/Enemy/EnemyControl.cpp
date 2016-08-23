/**
 * @file EnemyControl.cpp
 * @breif �S�Ă̓G�̑���t�@�C��
 
 * �S�Ă̓G�̑���ɕK�v�ȏ����������Ă���

 */


#include "../GameScene/GameSceneDraw.h"
#include "../GameScene/GameSceneControl.h"
#include "../GameScene/GameSceneInit.h"
#include "../Player/PlayerControl.h"

// �R�h���̑���֐�
void Kodora_Control()
{
	// ��l�����O��8�}�X�ȓ��ɂȂ�Ɠ���
	if (abs(g_enemy.posX - g_player.posX) < (TIPSIZE * 8))
	{
		g_enemy.posX -= WALK_SPEED;
	}

	// �R�h���͎�l���̑O��4�}�X�܂ňړ����Ă���
	if (abs(g_enemy.posX - g_player.posX) < (TIPSIZE * 4))
	{
		g_enemy.posX += WALK_SPEED;
	}

	// �ŏ���for�ŏo�����e�̐������������Ă��邩���`�F�b�N���Ă���
	for (int i = 0; i < BULLET_MAX; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (Collision_Check(g_bullet[i].bullet[j].x, g_enemy.posX, g_bullet[i].bullet[j].y, g_enemy.posY, TIPSIZE))
			{
				g_enemy.hitFlag = true;			// ���肵����`�͈̔͂ɓ����Ă�����e�ɓ��������t���O��true�ɂ��Ă���
				g_bullet[i].drawFlag = false;	// ������΂����e�̕b������Ȃ��̂�false�ɂ���
				g_bullet[i].initFlag = true;	// �������t���O��true�ɂ��Ȃ��Ǝ��̒e���o�Ȃ��Ȃ�
			}
		}
	}
}

// �X�P���g���̑���֐�
void skeleton_Control()
{
	// ��l�����O��8�}�X�ȓ��ɂȂ�Ɠ���
	if (abs(g_enemy.posX - g_player.posX) < (TIPSIZE * 8))
	{
		g_enemy.posX -= WALK_SPEED;
	}

	// �X�P���g���͎�l���̑O��2�}�X�܂ňړ����Ă���
	if (abs(g_enemy.posX - g_player.posX) < (TIPSIZE * 2))
	{
		g_enemy.posX += WALK_SPEED;
	}
}

// �X���C���̑���֐�
void Slime_Control()
{
	// ��l�����O��8�}�X�ȓ��ɂȂ�Ɠ���
	if (abs(g_enemy.posX - g_player.posX) < (TIPSIZE * 8))
	{
		g_enemy.posX -= WALK_SPEED;
	}

	// �X�P���g���͎�l���̑O��2�}�X�܂ňړ����Ă���
	if (abs(g_enemy.posX - g_player.posX) < (TIPSIZE * 3))
	{
		g_enemy.posX += WALK_SPEED;
	}
}