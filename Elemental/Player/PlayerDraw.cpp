/**
 * @file PlayerDraw.cpp
 * @breif ��l���̕`��t�@�C��

 * ��l���̕`��ɕK�v�ȏ����������Ă���

 */

#include "../GameScene/GameSceneDraw.h"
#include "../GameScene/GameSceneInit.h"

// ��l���̕`��֐�
void Draw_Player()
{
	// ��l���̒��_���
	CUSTOMVERTEX main_charcter[4] =
	{
		{ 0.0f, 0.0f, 0.5f, 1.0f, 0xFFFFFFFF, 0.0f, 0.0f },
		{ 128.0f, 0.0f, 0.5f, 1.0f, 0xFFFFFFFF, 1.0f, 0.0f },
		{ 128.0f, 128.0f, 0.5f, 1.0f, 0xFFFFFFFF, 1.0f, 1.0f },
		{ 0.0f, 128.0f, 0.5f, 1.0f, 0xFFFFFFFF, 0.0f, 1.0f },

	};

	if (g_player.drawFlag == true)
	{
		CUSTOMVERTEX drawplayer[4];					// ���CUSTOMVERTEX��p��

		for (int i = 0; i < 4; i++)
		{
			drawplayer[i] = main_charcter[i];		// main_charcter�̒��_�������CUSTOMVERTEX�ɑ��
			drawplayer[i].x += g_player.posX;		// ��l���̌��݈ʒu��X���ɑ��
			drawplayer[i].y += g_player.posY;		// ��l���̌��݈ʒu��Y���ɑ��
		}

		Draw_Obj(g_pTexture[PLAYER_TEX], drawplayer);
	}
}

void Player_Aura_Draw(bool _auraFlag, GAMETEX _auratex, float _texsize)
{
	// �I�[����l���̒��_���
	CUSTOMVERTEX main_auracharcter[4] =
	{
		{ 0.0f, 0.0f, 0.5f, 1.0f, 0xFFFFFFFF, 0.0f, 0.0f },
		{ 128.0f, 0.0f, 0.5f, 1.0f, 0xFFFFFFFF, 0.25f, 0.0f },
		{ 128.0f, 128.0f, 0.5f, 1.0f, 0xFFFFFFFF, 0.25f, 0.25f },
		{ 0.0f, 128.0f, 0.5f, 1.0f, 0xFFFFFFFF, 0.0f, 0.25f },
	};

	if (_auraFlag == true)
	{
		CUSTOMVERTEX playerauradraw[4];
		for (int i = 0; i < 4; i++)
		{
			playerauradraw[i] = main_auracharcter[i];
			playerauradraw[i].x += g_player.posX;
			playerauradraw[i].y += g_player.posY;
			playerauradraw[i].tu += _texsize;
		}
		Draw_Obj(g_pTexture[_auratex], playerauradraw);
	}
}

void Player_Bullet_Draw()
{
	CUSTOMVERTEX bullet[4] = 
	{
		{ -TIPSIZE / 2.0f, -TIPSIZE / 2.0f, 0.5f, 1.0f, 0xFFFFFFFF, 0.0f, 0.0f},
		{  TIPSIZE / 2.0f, -TIPSIZE / 2.0f, 0.5f, 1.0f, 0xFFFFFFFF, 0.25f, 0.0f},
		{  TIPSIZE / 2.0f,  TIPSIZE / 2.0f, 0.5f, }
	};
}