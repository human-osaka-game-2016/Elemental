/**
 * @file PlayerDraw.cpp
 * @breif ��l���̕`��t�@�C��

 * ��l���̕`��ɕK�v�ȏ����������Ă���

 */

#include "../GameScene/GameSceneControl.h"
#include "../GameScene/GameSceneInit.h"
#include "PlayerDraw.h"
#include "PlayerControl.h"

// ��l���̕`��֐�
void Player_Draw()
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

// �I�[�����܂Ƃ�����l����`��ł���悤�ɂ���֐�
void Player_Aura_Draw(bool _auraFlag, float _texsize, GAMETEX _auratex)
{
	// �I�[����l���̒��_���
	CUSTOMVERTEX auracharcter[4] =
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
			playerauradraw[i] = auracharcter[i];
			playerauradraw[i].x += g_player.posX;
			playerauradraw[i].y += g_player.posY;
			playerauradraw[i].tu += _texsize;
		}
		Draw_Obj(g_pTexture[_auratex], playerauradraw);
	}
}

// ��l���̏o���e�̕`��֐�
void Player_Bullet_Draw()
{
	CUSTOMVERTEX bullet[4] =
	{
		{ 0.0f, 0.0f, 0.5f, 1.0f, 0xFFFFFFFF, 0.0f, 0.0f },
		{ 128.f, 0.0f, 0.5f, 1.0f, 0xFFFFFFFF, 1.0f, 0.0f },
		{ 128.f, 128.f, 0.5f, 1.0f, 0xFFFFFFFF, 1.0f, 1.0f },
		{ 0.0f, 128.f, 0.5f, 1.0f, 0xFFFFFFFF, 0.0f, 1.0f },
	};

	// �o����e�̍ő�l��for�ŉ�
	for (int i = 0; i < BULLET_MAX; i++)
	{
		// �`�悵���e�̑�2���_��X���W����ʍ��[�𒴂���Ε`�悵�Ȃ��悤�ɂ���
		if (g_bullet[i].bullet[2].x <= 0.f)
		{
			g_bullet[i].drawFlag = false;
			g_bullet[i].initFlag = true;
		}

		// �`�悵���e�̑�0���_��X���W����ʉE�[�𒴂���Ε`�悵�Ȃ��悤�ɂ���
		if (g_bullet[i].bullet[0].x >= 1440.f)
		{
			g_bullet[i].drawFlag = false;
			g_bullet[i].initFlag = true;
		}

		// �e���������ɏ�Q�����Ȃ����`�F�b�N���Ă���
		if (Map_Collision_Check(g_bullet[i].posX - BULLET_SPEED, g_bullet[i].posY, 2, 2))
		{
			g_bullet[i].drawFlag = false;
			g_bullet[i].initFlag = true;
		}

		// �e���E�����ɏ�Q�����Ȃ����`�F�b�N���Ă���
		if (Map_Collision_Check(g_bullet[i].posX + BULLET_SPEED, g_bullet[i].posY, 2, 2))
		{
			g_bullet[i].drawFlag = false;
			g_bullet[i].initFlag = true;
		}
	}

	for (int i = 0; i < BULLET_MAX; i++)
	{
		if (g_bullet[i].initFlag == true)
		{
			for (int j = 0; j < 4; j++)
			{
				g_bullet[i].bullet[j] = bullet[j];
				g_bullet[i].bullet[j].x += g_player.posX;
				g_bullet[i].bullet[j].y += g_player.posY;
			}
		}

		if (g_bullet[i].drawFlag == true)
		{
			Draw_Obj(g_pTexture[BULLET_TEX], g_bullet[i].bullet);
		}
	}
}