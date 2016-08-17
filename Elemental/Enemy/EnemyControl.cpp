/**
 * @file EnemyControl.cpp
 * @breif �S�Ă̓G�̑���t�@�C��
 
 * �S�Ă̓G�̑���ɕK�v�ȏ����������Ă���

 */


#include "../GameScene/GameSceneDraw.h"
#include "../GameScene/GameSceneControl.h"
#include "../GameScene/GameSceneInit.h"
#include "../Player/PlayerDraw.h"
#include "../Player/PlayerControl.h"
#include "EnemyDraw.h"

// �R�h���̑���֐�
void Kodora_Control()
{
	if (abs(g_enemy.posX - g_player.posX) < (TIPSIZE * 8))
	{
		g_enemy.posX -= WALK_SPEED;
	}
	if (abs(g_enemy.posX - g_player.posX) < (TIPSIZE * 4))
	{
		g_enemy.posX += WALK_SPEED;
	}
}

// �X�P���g���̑���֐�
void skeleton_Control()
{
	if (abs(g_enemy.posX - g_player.posX) < (TIPSIZE * 8))
	{
		g_enemy.posX -= WALK_SPEED;
	}
	if (abs(g_enemy.posX - g_player.posX) < (TIPSIZE * 2))
	{
		g_enemy.posX += WALK_SPEED;
	}
}

// �X���C���̑���֐�
void Slime_Control()
{
	if (abs(g_enemy.posX - g_player.posX) < (TIPSIZE * 8))
	{
		g_enemy.posX -= WALK_SPEED;
	}
	if (abs(g_enemy.posX - g_player.posX) < (TIPSIZE * 3))
	{
		g_enemy.posX += WALK_SPEED;
	}
}