/**
 * @file PlayerDraw.cpp
 * @breif ��l���̕`��t�@�C��

 * ��l���̕`��ɕK�v�ȏ����������Ă���

 */
#define DIRECTINPUT_VERSION 0x0800

#include <dinput.h>
#include <Direct_Key_Input.h>
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

	CUSTOMVERTEX playerdraw[4];


	for (int i = 0; i < 4; i++)
	{
		playerdraw[i] = main_charcter[i];
		playerdraw[i].x += g_player.posX;
		playerdraw[i].y += g_player.posY;
	}

	animationtime++;

	if (animationtime <= 30)
	{
		for (int i = 0; i < 4; i++)
		{
			playerdraw[i].tu += 0.5f;
		}
	}
	else if (animationtime >= 60)
	{
		for (int i = 0; i < 4; i++)
		{
			playerdraw[i].tu -= 0.5f;
		}

		animationtime = 0;
	}

	Player_Case_Draw(playerdraw);
}
	
	


void Player_Sky_Draw()
{
	// ��l���̒��_���
	CUSTOMVERTEX sky_charcter[4] =
	{
		{ 0.0f, 0.0f, 0.5f, 1.0f, 0xFFFFFFFF, 0.0f, 0.0f },
		{ 128.0f, 0.0f, 0.5f, 1.0f, 0xFFFFFFFF, 1.0f, 0.0f },
		{ 128.0f, 128.0f, 0.5f, 1.0f, 0xFFFFFFFF,1.0f, 1.0f },
		{ 0.0f, 128.0f, 0.5f, 1.0f, 0xFFFFFFFF, 0.0f, 1.0f },

	};

	CUSTOMVERTEX playerskydraw[4];

	for (int i = 0; i < 4; i++)
	{
		playerskydraw[i] = sky_charcter[i];
		playerskydraw[i].x += g_player.posX;
		playerskydraw[i].y += g_player.posY;
	}

	Player_Sky_Case_Draw(playerskydraw);
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
		if (g_bullet[i].bullet[0].x == g_player.posX + BULLET_DISTAMCE)
		{
			g_bullet[i].drawFlag = false;
			g_bullet[i].initFlag = true;
		}

		// �`�悵���e�̑�0���_��X���W����ʉE�[�𒴂���Ε`�悵�Ȃ��悤�ɂ���
		if (g_bullet[i].bullet[0].x == g_player.posX - BULLET_DISTAMCE)
		{
			g_bullet[i].drawFlag = false;
			g_bullet[i].initFlag = true;
		}

		// �e���������ɏ�Q�����Ȃ����`�F�b�N���Ă���
		if (Map_Collision_Check(g_bullet[i].posX - BULLET_SPEED, g_bullet[i].posY, 2, (g_player.skyFlag) ? 2 : 1))
		{
			g_bullet[i].drawFlag = false;
			g_bullet[i].initFlag = true;
		}

		// �e���E�����ɏ�Q�����Ȃ����`�F�b�N���Ă���
		if (Map_Collision_Check(g_bullet[i].posX + BULLET_SPEED, g_bullet[i].posY, 2, (g_player.skyFlag) ? 2 : 1))
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
				g_bullet[i].animationFlag = false;
				g_bullet[i].bullet[j].x += g_player.posX;
				g_bullet[i].bullet[j].y += g_player.posY;
			}
		}

		static int animatime = 0;
		static int animacount = 0;

		animatime++;

		if ((animatime % 10) == 0)
		{
			if (g_bullet[i].animationFlag == true)
			{
				for (int j = 0; j < 4; j++)
				{
					g_bullet[i].bullet[j].tu -= 0.25f;
				}
			}
			else
			{
				for (int j = 0; j < 4; j++)
				{
					g_bullet[i].bullet[j].tu += 0.25f;
				}
			}

			if (g_bullet[i].bullet[2].tu == 1.0f && g_bullet[i].animationFlag == false)
			{
				g_bullet[i].animationFlag = true;
			}
			else if (g_bullet[i].bullet[0].tu == 0.25f && g_bullet[i].animationFlag == true)
			{
				g_bullet[i].animationFlag = false;
			}
		}

		if (g_bullet[i].drawFlag == true)
		{
			switch (g_player.p_elerent)
			{
			case FLAME:

				if (g_player.leftFlag == true)
				{
					Draw_Obj(g_pTexture[PLAYER_FLAME_LEFT_BULLET_TEX], g_bullet[i].bullet);
				}
				else
				{
					Draw_Obj(g_pTexture[PLAYER_FLAME_RIGHT_BULLET_TEX], g_bullet[i].bullet);
				}

				break;

			case ICE:

				if (g_player.leftFlag == true)
				{
					Draw_Obj(g_pTexture[PLAYER_ICE_LEFT_BULLET_TEX], g_bullet[i].bullet);
				}
				else
				{
					Draw_Obj(g_pTexture[PLAYER_ICE_RIGHT_BULLET_TEX], g_bullet[i].bullet);
				}

				break;

			case WIND:

				if (g_player.leftFlag == true)
				{
					Draw_Obj(g_pTexture[PLAYER_WIND_LEFT_BULLET_TEX], g_bullet[i].bullet);
				}
				else
				{
					Draw_Obj(g_pTexture[PLAYER_WIND_RIGHT_BULLET_TEX], g_bullet[i].bullet);
				}

				break;
			}
		}
	}
}

void Player_Case_Draw(CUSTOMVERTEX playerdraw[])
{
	switch (g_player.p_elerent)
	{
	case NORMAL:

		if (g_player.leftFlag == true)
		{
			if (g_player.moveFlag == true)
			{
				if (g_player.jumpFlag == false)
				{
					Draw_Obj(g_pTexture[PLAYER_LEFT_MOVE_TEX], playerdraw);
				}
			}
			else
			{
				if (g_player.jumpFlag == false)
				{
					Draw_Obj(g_pTexture[PLAYER_LEFT_TEX], playerdraw);
				}
			}

		}
		else
		{
			if (g_player.moveFlag == true)
			{
				if (g_player.jumpFlag == false)
				{
					Draw_Obj(g_pTexture[PLAYER_RIGHT_MOVE_TEX], playerdraw);
				}
			}
			else
			{
				if (g_player.jumpFlag == false)
				{
					Draw_Obj(g_pTexture[PLAYER_RIGHT_TEX], playerdraw);
				}
			}
		}

		break;

	case FLAME:

		if (g_player.leftFlag == true)
		{
			if (g_player.moveFlag == true)
			{
				if (g_player.jumpFlag == false)
				{
					Draw_Obj(g_pTexture[PLAYER_FLAME_LEFT_MOVE_TEX], playerdraw);
				}
			}
			else
			{
				if (g_player.jumpFlag == false)
				{
					Draw_Obj(g_pTexture[PLAYER_FLAME_LEFT_TEX], playerdraw);
				}
			}

		}
		else
		{
			if (g_player.moveFlag == true)
			{
				if (g_player.jumpFlag == false)
				{
					Draw_Obj(g_pTexture[PLAYER_FLAME_RIGHT_MOVE_TEX], playerdraw);
				}

				if (g_Key[SPACE] == PUSH)
				{
					Draw_Obj(g_pTexture[PLAYER_FLAME_RIGHT_ATTACK_TEX], playerdraw);
				}
			}
			else
			{
				if (g_player.jumpFlag == false)
				{
					Draw_Obj(g_pTexture[PLAYER_FLAME_RIGHT_TEX], playerdraw);					
				}				
			}
		}

		break;

	case ICE:

		if (g_player.leftFlag == true)
		{
			if (g_player.moveFlag == true)
			{
				if (g_player.jumpFlag == false)
				{
					Draw_Obj(g_pTexture[PLAYER_ICE_LEFT_MOVE_TEX], playerdraw);
				}
			}
			else
			{
				if (g_player.jumpFlag == false)
				{
					Draw_Obj(g_pTexture[PLAYER_ICE_LEFT_TEX], playerdraw);
				}
			}

		}
		else
		{
			if (g_player.moveFlag == true)
			{
				if (g_player.jumpFlag == false)
				{
					Draw_Obj(g_pTexture[PLAYER_ICE_RIGHT_MOVE_TEX], playerdraw);
				}
			}
			else
			{
				if (g_player.jumpFlag == false)
				{
					Draw_Obj(g_pTexture[PLAYER_ICE_RIGHT_TEX], playerdraw);
				}
			}
		}

		break;

	case WIND:

		if (g_player.leftFlag == true)
		{
			if (g_player.moveFlag == true)
			{
				if (g_player.jumpFlag == false)
				{
					Draw_Obj(g_pTexture[PLAYER_WIND_LEFT_MOVE_TEX], playerdraw);
				}

			}
			else
			{
				if (g_player.jumpFlag == false)
				{
					Draw_Obj(g_pTexture[PLAYER_WIND_LEFT_TEX], playerdraw);
				}
			}

		}
		else
		{
			if (g_player.moveFlag == true)
			{
				if (g_player.jumpFlag == false)
				{
					Draw_Obj(g_pTexture[PLAYER_WIND_RIGHT_MOVE_TEX], playerdraw);
				}
			}
			else
			{
				if (g_player.jumpFlag == false)
				{
					Draw_Obj(g_pTexture[PLAYER_WIND_RIGHT_TEX], playerdraw);
				}
			}
		}

		break;
	}
}

void Player_Sky_Case_Draw(CUSTOMVERTEX playerskydraw[])
{
	switch (g_player.p_elerent)
	{
	case NORMAL:

		if (g_player.leftFlag == true)
		{
			if (g_player.jumpFlag == true)
			{
				if (g_player.acceleration < 0)
				{
					Draw_Obj(g_pTexture[PLAYER_LEFT_JUMP_TEX], playerskydraw);
				}
				else
				{
					Draw_Obj(g_pTexture[PLAYER_LEFT_FALL_TEX], playerskydraw);
				}

			}

		}
		else
		{
			if (g_player.jumpFlag == true)
			{
				if (g_player.acceleration < 0)
				{
					Draw_Obj(g_pTexture[PLAYER_RIGHT_JUMP_TEX], playerskydraw);
				}
				else
				{
					Draw_Obj(g_pTexture[PLAYER_RIGHT_FALL_TEX], playerskydraw);
				}
			}
		}

		break;

	case FLAME:

		if (g_player.leftFlag == true)
		{
			if (g_player.jumpFlag == true)
			{
				if (g_player.acceleration < 0)
				{
					Draw_Obj(g_pTexture[PLAYER_FLAME_LEFT_JUMP_TEX], playerskydraw);
				}
				else
				{
					Draw_Obj(g_pTexture[PLAYER_FLAME_LEFT_FALL_TEX], playerskydraw);
				}
			}
		}
		else
		{
			if (g_player.jumpFlag == true)
			{
				if (g_player.acceleration < 0)
				{
					Draw_Obj(g_pTexture[PLAYER_FLAME_RIGHT_JUMP_TEX], playerskydraw);
				}
				else
				{
					Draw_Obj(g_pTexture[PLAYER_FLAME_RIGHT_FALL_TEX], playerskydraw);
				}
			}
		}

		break;

	case ICE:

		if (g_player.leftFlag == true)
		{
			if (g_player.jumpFlag == true)
			{
				if (g_player.acceleration < 0)
				{
					Draw_Obj(g_pTexture[PLAYER_ICE_LEFT_JUMP_TEX], playerskydraw);
				}
				else
				{
					Draw_Obj(g_pTexture[PLAYER_ICE_LEFT_FALL_TEX], playerskydraw);
				}
			}
		}
		else
		{
			if (g_player.jumpFlag == true)
			{
				if (g_player.acceleration < 0)
				{
					Draw_Obj(g_pTexture[PLAYER_ICE_RIGHT_JUMP_TEX], playerskydraw);
				}
				else
				{
					Draw_Obj(g_pTexture[PLAYER_ICE_RIGHT_FALL_TEX], playerskydraw);
				}
			}
		}

		break;

	case WIND:

		if (g_player.leftFlag == true)
		{
			if (g_player.jumpFlag == true)
			{
				if (g_player.acceleration < 0)
				{
					Draw_Obj(g_pTexture[PLAYER_WIND_LEFT_JUMP_TEX], playerskydraw);
				}
				else
				{
					Draw_Obj(g_pTexture[PLAYER_WIND_LEFT_FALL_TEX], playerskydraw);
				}
			}
		}
		else
		{
			if (g_player.jumpFlag == true)
			{
				if (g_player.acceleration < 0)
				{
					Draw_Obj(g_pTexture[PLAYER_WIND_RIGHT_JUMP_TEX], playerskydraw);
				}
				else
				{
					Draw_Obj(g_pTexture[PLAYER_WIND_RIGHT_FALL_TEX], playerskydraw);
				}
			}
		}

		break;

	}
}

void Player_Init()
{
	for (int y = 0; y < MAP_HEIGHT; y++)
	{
		for (int x = 0; x < MAP_WIDTH; x++)
		{
			if (map[y][x] == PLAYER_START)
			{
				g_player.posX = (float)(x * TIPSIZE);
				g_player.posY = (float)(y * TIPSIZE);
			}
		}
	}
}