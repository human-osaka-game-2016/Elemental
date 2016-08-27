/**
 * @file PlayerDraw.cpp
 * @breif ��l���̕`��t�@�C��

 * ��l���̕`��ɕK�v�ȏ����������Ă���

 */

#include "../GameScene/GameSceneControl.h"
#include "../GameScene/GameSceneInit.h"
#include "PlayerDraw.h"
#include "PlayerControl.h"

// �I�[�����܂Ƃ�����l����`��ł���悤�ɂ���֐�
void Player_Draw()
{
	// ��l���̒��_���
	CUSTOMVERTEX main_charcter[4] =
	{
		{ 0.0f, 0.0f, 0.5f, 1.0f, 0xFFFFFFFF, 0.0f, 0.0f },
		{ 128.0f, 0.0f, 0.5f, 1.0f, 0xFFFFFFFF, 0.5f, 0.0f },
		{ 128.0f, 128.0f, 0.5f, 1.0f, 0xFFFFFFFF, 0.5f, 1.0f },
		{ 0.0f, 128.0f, 0.5f, 1.0f, 0xFFFFFFFF, 0.0f, 1.0f },

	};

	static int animationtime = 0;

	CUSTOMVERTEX playerauradraw[4];

		for (int i = 0; i < 4; i++)
		{
			playerauradraw[i] = main_charcter[i];
			playerauradraw[i].x += g_player.posX;
			playerauradraw[i].y += g_player.posY;
		}
	
	animationtime++;

	if (animationtime <= 60)
	{
		for (int i = 0; i < 4; i++)
		{
			playerauradraw[i].tu += 0.5f;
		}
	}
	else if (animationtime >= 120)
	{
		for (int i = 0; i < 4; i++)
		{
			playerauradraw[i].tu -= 0.5f;
		}

		animationtime = 0;
	}

	switch (g_player.p_elerent)
	{
	case NORMAL:

		if (g_player.leftFlag == true)
		{
			if (g_player.moveFlag == true)
			{
				Draw_Obj(g_pTexture[PLAYER_LEFT_MOVE_TEX], playerauradraw);
			}
			else
			{
				Draw_Obj(g_pTexture[PLAYER_LEFT_TEX], playerauradraw);
			}

		}
		else
		{
			if (g_player.moveFlag == true)
			{
				Draw_Obj(g_pTexture[PLAYER_RIGHT_MOVE_TEX], playerauradraw);
			}
			else
			{
				Draw_Obj(g_pTexture[PLAYER_RIGHT_TEX], playerauradraw);
			}
		}

		break;

	case FLAME:
		
		if (g_player.leftFlag == true)
		{
			if (g_player.moveFlag == true)
			{
				Draw_Obj(g_pTexture[PLAYER_FLAME_LEFT_MOVE_TEX], playerauradraw);
			}
			else
			{
				Draw_Obj(g_pTexture[PLAYER_FLAME_LEFT_TEX], playerauradraw);
			}

		}
		else
		{
			if (g_player.moveFlag == true)
			{
				Draw_Obj(g_pTexture[PLAYER_FLAME_RIGHT_MOVE_TEX], playerauradraw);
			}
			else
			{
				Draw_Obj(g_pTexture[PLAYER_FLAME_RIGHT_TEX], playerauradraw);
			}
		}

		break;

	case ICE:

		if (g_player.leftFlag == true)
		{
			if (g_player.moveFlag == true)
			{
				Draw_Obj(g_pTexture[PLAYER_ICE_LEFT_MOVE_TEX], playerauradraw);
			}
			else
			{
				Draw_Obj(g_pTexture[PLAYER_ICE_LEFT_TEX], playerauradraw);
			}

		}
		else
		{
			if (g_player.moveFlag == true)
			{
				Draw_Obj(g_pTexture[PLAYER_ICE_RIGHT_MOVE_TEX], playerauradraw);
			}
			else
			{
				Draw_Obj(g_pTexture[PLAYER_ICE_RIGHT_TEX], playerauradraw);
			}
		}

		break;

	case WIND:

		if (g_player.leftFlag == true)
		{
			if (g_player.moveFlag == true)
			{
				Draw_Obj(g_pTexture[PLAYER_WIND_LEFT_MOVE_TEX], playerauradraw);
			}
			else
			{
				Draw_Obj(g_pTexture[PLAYER_WIND_LEFT_TEX], playerauradraw);
			}

		}
		else
		{
			if (g_player.moveFlag == true)
			{
				Draw_Obj(g_pTexture[PLAYER_WIND_RIGHT_MOVE_TEX], playerauradraw);
			}
			else
			{
				Draw_Obj(g_pTexture[PLAYER_WIND_RIGHT_TEX], playerauradraw);
			}
		}

		break;
	}
	
}

// ��l���̏o���e�̕`��֐�
void Player_Bullet_Draw()
{
	CUSTOMVERTEX bullet[4] =
	{
		{ 0.0f, 0.0f, 0.5f, 1.0f, 0xFFFFFFFF, 0.0f, 0.0f },
		{ 128.f, 0.0f, 0.5f, 1.0f, 0xFFFFFFFF, 0.25f, 0.0f },
		{ 128.f, 128.f, 0.5f, 1.0f, 0xFFFFFFFF, 0.25f, 1.0f },
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
			switch (g_player.p_elerent)
			{
			case FLAME:

				Draw_Obj(g_pTexture[PLAYER_FLAME_RIGHT_ATTACK_TEX], g_bullet[i].bullet);

				break;

			case ICE:

				Draw_Obj(g_pTexture[PLAYER_ICE_RIGHT_ATTACK_TEX], g_bullet[i].bullet);

				break;

			case WIND:

				Draw_Obj(g_pTexture[PLAYER_WIND_RIGHT_ATTACK_TEX], g_bullet[i].bullet);

				break;
			}
		}

			

	}
}

