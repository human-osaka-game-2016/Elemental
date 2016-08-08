/**
 * @file EnemyDraw
 * @breif �S�Ă̓G�̕`��t�@�C��

 * �S�Ă̓G�̕`��ɕK�v�ȏ����������Ă���

 */

#include "GameSceneDraw.h"
#include "GameSceneInit.h"

// �R�h���̒��_���
CUSTOMVERTEX g_Kodora[4] =
{
	{ 0.0f, 0.0f, 0.5f, 1.0f, 0xFFFFFFFF, 0.0f, 0.0f },
	{ 128.0f, 0.0f, 0.5f, 1.0f, 0xFFFFFFFF, -1.0f, 0.0f },
	{ 128.0f, 128.0f, 0.5f, 1.0f, 0xFFFFFFFF, -1.0f, 1.0f },
	{ 0.0f, 128.0f, 0.5f, 1.0f, 0xFFFFFFFF, 0.0f, 1.0f },

};

// �R�h���̕`��֐�
void Draw_Kodora()
{
	CUSTOMVERTEX drawkodora[4];
	for (int i = 0; i < 4; i++)
	{
		drawkodora[i] = g_Kodora[i];
		drawkodora[i].x += g_enemy.posX;
		drawkodora[i].y += g_enemy.posY;
	}
	Draw_Obj(g_pTexture[ENEMY_TEX], drawkodora);
}