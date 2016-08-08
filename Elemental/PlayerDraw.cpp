/**
 * @file PlayerDraw.cpp
 * @breif ��l���̕`��t�@�C��

 * ��l���̕`��ɕK�v�ȏ����������Ă���

 */

#include "GameSceneDraw.h"
#include "GameSceneInit.h"

// ��l���̒��_���
CUSTOMVERTEX g_main_charcter[4] =
{
	{   0.0f,  0.0f, 0.5f, 1.0f, 0xFFFFFFFF, 0.0f, 0.0f },
	{ 128.0f,  0.0f, 0.5f, 1.0f, 0xFFFFFFFF, 1.0f, 0.0f },
	{ 128.0f, 128.0f, 0.5f, 1.0f, 0xFFFFFFFF, 1.0f, 1.0f },
	{   0.0f, 128.0f, 0.5f, 1.0f, 0xFFFFFFFF, 0.0f, 1.0f },

};

// ��l���̕`��֐�
void Draw_Player()
{
	CUSTOMVERTEX drawplayer[4];					// ���CUSTOMVERTEX��p��
	for (int i = 0; i < 4; i++)
	{
		drawplayer[i] = g_main_charcter[i];		// main_charcter�̒��_�������CUSTOMVERTEX�ɑ��
		drawplayer[i].x += g_player.posX;		// ��l���̌��݈ʒu��X���ɑ��
		drawplayer[i].y += g_player.posY;		// ��l���̌��݈ʒu��Y���ɑ��
	}
	Draw_Obj(g_pTexture[PLAYER_TEX], drawplayer);

}