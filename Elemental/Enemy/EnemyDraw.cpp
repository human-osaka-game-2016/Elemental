/**
 * @file EnemyDraw.cpp
 * @breif 全ての敵の描画ファイル

 * 全ての敵の描画に必要な処理を書いている

 */

#include "../GameScene/GameSceneDraw.h"
#include "../GameScene/GameSceneInit.h"

// コドラの描画関数
void Kodora_Walk_Draw()
{
	// コドラの頂点情報
	CUSTOMVERTEX Kodora[4] =
	{
		{ 0.0f, 0.0f, 0.5f, 1.0f, 0xFFFFFFFF, 0.0f, 0.0f },
		{ 128.0f, 0.0f, 0.5f, 1.0f, 0xFFFFFFFF, 0.5f, 0.0f },
		{ 128.0f, 128.0f, 0.5f, 1.0f, 0xFFFFFFFF, 0.5f, 1.0f },
		{ 0.0f, 128.0f, 0.5f, 1.0f, 0xFFFFFFFF, 0.0f, 1.0f },
	};

	static int animationtime = 0;


	CUSTOMVERTEX drawkodora[4];

	for (int j = 0; j < KODORA_MAX; j++)
	{
		for (int i = 0; i < 4; i++)
		{
			drawkodora[i] = Kodora[i];
			drawkodora[i].x += g_kodora[j].posX;
			drawkodora[i].y += g_kodora[j].posY;
		}

		animationtime++;

		if (animationtime <= 60)
		{
			for (int i = 0; i < 4; i++)
			{
				drawkodora[i].tu += 0.5f;
			}
		}
		else if (animationtime >= 120)
		{
			for (int i = 0; i < 4; i++)
			{
				drawkodora[i].tu -= 0.5f;
			}

			animationtime = 0;
		}

		if (g_kodora[j].drawFlag == true)
		{
			switch (g_kodora[j].e_element)
			{
			case FLAME:

				if (g_kodora[j].directionID == Left && g_kodora[j].stateID == Move)
				{
					Draw_Obj(g_pTexture[KODORA_FLAME_LEFT_MOVE_TEX], drawkodora);
				}
				else if (g_kodora[j].directionID == Right && g_kodora[j].stateID == Move)
				{
					Draw_Obj(g_pTexture[KODORA_FLAME_RIGHT_MOVE_TEX], drawkodora);
				}

				break;

			case ICE:

				if (g_kodora[j].directionID == Left && g_kodora[j].stateID == Move)
				{
					Draw_Obj(g_pTexture[KODORA_ICE_LEFT_MOVE_TEX], drawkodora);
				}
				else if (g_kodora[j].directionID == Right && g_kodora[j].stateID == Move)
				{
					Draw_Obj(g_pTexture[KODORA_ICE_RIGHT_MOVE_TEX], drawkodora);
				}

				break;

			case WIND:

				if (g_kodora[j].directionID == Left && g_kodora[j].stateID == Move)
				{
					Draw_Obj(g_pTexture[KODORA_WIND_LEFT_MOVE_TEX], drawkodora);
				}
				else if (g_kodora[j].directionID == Right && g_kodora[j].stateID == Move)
				{
					Draw_Obj(g_pTexture[KODORA_WIND_RIGHT_MOVE_TEX], drawkodora);
				}

				break;
			}
		}
	}
}

// コドラの待機の描画関数
void Kodora_Stay_Draw()
{
	// コドラの頂点情報
	CUSTOMVERTEX Kodora[4] =
	{
		{ 0.0f, 0.0f, 0.5f, 1.0f, 0xFFFFFFFF, 0.0f, 0.0f },
		{ 128.0f, 0.0f, 0.5f, 1.0f, 0xFFFFFFFF, 1.0f, 0.0f },
		{ 128.0f, 128.0f, 0.5f, 1.0f, 0xFFFFFFFF, 1.0f, 1.0f },
		{ 0.0f, 128.0f, 0.5f, 1.0f, 0xFFFFFFFF, 0.0f, 1.0f },
	};

	CUSTOMVERTEX drawkodora[4];

	for (int j = 0; j < KODORA_MAX; j++)
	{
		for (int i = 0; i < 4; i++)
		{
			drawkodora[i] = Kodora[i];
			drawkodora[i].x += g_kodora[j].posX;
			drawkodora[i].y += g_kodora[j].posY;
		}

		if (g_kodora[j].drawFlag == true)
		{
			switch (g_kodora[j].e_element)
			{
			case FLAME:

				if (g_kodora[j].directionID == Left && g_kodora[j].stateID == Wait)
				{
					Draw_Obj(g_pTexture[KODORA_FLAME_LEFT_STATE_TEX], drawkodora);
				}
				else if (g_kodora[j].directionID == Right && g_kodora[j].stateID == Wait)
				{
					Draw_Obj(g_pTexture[KODORA_FLAME_RIGHT_STATE_TEX], drawkodora);
				}

				break;

			case ICE:

				if (g_kodora[j].directionID == Left && g_kodora[j].stateID == Wait)
				{
					Draw_Obj(g_pTexture[KODORA_ICE_LEFT_STATE_TEX], drawkodora);
				}
				else if (g_kodora[j].directionID == Right && g_kodora[j].stateID == Wait)
				{
					Draw_Obj(g_pTexture[KODORA_ICE_RIGHT_STATE_TEX], drawkodora);
				}

				break;

			case WIND:

				if (g_kodora[j].directionID == Left && g_kodora[j].stateID == Wait)
				{
					Draw_Obj(g_pTexture[KODORA_WIND_LEFT_STATE_TEX], drawkodora);
				}
				else if (g_kodora[j].directionID == Right && g_kodora[j].stateID == Wait)
				{
					Draw_Obj(g_pTexture[KODORA_WIND_RIGHT_STATE_TEX], drawkodora);
				}

				break;
			}
		}
	}
}

// スケルトンの描画関数

void Skeleton_Draw()
{

}

void Slime_Draw()
{
	// スライムの頂点情報
	CUSTOMVERTEX Slime[4] =
	{
		{ 0.0f, 0.0f, 0.5f, 1.0f, 0xFFFFFFFF, 0.0f, 0.0f },
		{ 128.0f, 0.0f, 0.5f, 1.0f, 0xFFFFFFFF, 0.5f, 0.0f },
		{ 128.0f, 128.0f, 0.5f, 1.0f, 0xFFFFFFFF, 0.5f, 1.0f },
		{ 0.0f, 128.0f, 0.5f, 1.0f, 0xFFFFFFFF, 0.0f, 1.0f },
	};
	static int animationtime = 0;


	CUSTOMVERTEX drawslime[4];
	for (int j = 0; j < SLIME_MAX; j++)
	{
		for (int i = 0; i < 4; i++)
		{
			drawslime[i] = Slime[i];
			drawslime[i].x += g_slime[j].posX;
			drawslime[i].y += g_slime[j].posY;
		}
		animationtime++;

		if (animationtime <= 60)
		{
			for (int i = 0; i < 4; i++)
			{
				drawslime[i].tu += 0.5f;
			}
		}
		else if (animationtime >= 120)
		{
			for (int i = 0; i < 4; i++)
			{
				drawslime[i].tu -= 0.5f;
			}
			animationtime = 0;
		}

		if (g_slime[j].drawFlag == true)
		{
			switch (g_slime[j].e_element)
			{
			case FLAME:

				if (g_slime[j].directionID == Left && g_slime[j].stateID == Wait)
				{
					Draw_Obj(g_pTexture[SLIME_FLAME_LEFT_STATE_TEX], drawslime);
				}
				else if (g_slime[j].directionID == Left && g_slime[j].stateID == Move)
				{
					Draw_Obj(g_pTexture[SLIME_FLAME_LEFT_MOVE_TEX], drawslime);
				}
				else if (g_slime[j].directionID == Right && g_slime[j].stateID == Wait)
				{
					Draw_Obj(g_pTexture[SLIME_FLAME_RIGHT_STATE_TEX], drawslime);
				}
				else if (g_slime[j].directionID == Right && g_slime[j].stateID == Move)
				{
					Draw_Obj(g_pTexture[SLIME_FLAME_RIGHT_MOVE_TEX], drawslime);
				}

				break;

			case ICE:

				if (g_slime[j].directionID == Left && g_slime[j].stateID == Wait)
				{
					Draw_Obj(g_pTexture[SLIME_ICE_LEFT_STATE_TEX], drawslime);
				}
				else if (g_slime[j].directionID == Left && g_slime[j].stateID == Move)
				{
					Draw_Obj(g_pTexture[SLIME_ICE_LEFT_MOVE_TEX], drawslime);
				}
				else if (g_slime[j].directionID == Right && g_slime[j].stateID == Wait)
				{
					Draw_Obj(g_pTexture[SLIME_ICE_RIGHT_STATE_TEX], drawslime);
				}
				else if (g_slime[j].directionID == Right && g_slime[j].stateID == Move)
				{
					Draw_Obj(g_pTexture[SLIME_ICE_RIGHT_MOVE_TEX], drawslime);
				}

				break;

			case WIND:

				if (g_slime[j].directionID == Left && g_slime[j].stateID == Wait)
				{
					Draw_Obj(g_pTexture[SLIME_WIND_LEFT_STATE_TEX], drawslime);
				}
				else if (g_slime[j].directionID == Left && g_slime[j].stateID == Move)
				{
					Draw_Obj(g_pTexture[SLIME_WIND_LEFT_MOVE_TEX], drawslime);
				}
				else if (g_slime[j].directionID == Right && g_slime[j].stateID == Wait)
				{
					Draw_Obj(g_pTexture[SLIME_WIND_RIGHT_STATE_TEX], drawslime);
				}
				else if (g_slime[j].directionID == Right && g_slime[j].stateID == Move)
				{
					Draw_Obj(g_pTexture[SLIME_WIND_RIGHT_MOVE_TEX], drawslime);
				}

				break;				
			}
		}
	}
}

void Kodora_Init()
{
	int countkodora = 0;

	for (int y = 0; y < MAP_HEIGHT; y++)
	{
		for (int x = 0; x < MAP_WIDTH; x++)
		{
			if (map[y][x] == FLAME_KODORA && countkodora < KODORA_MAX)
			{
				g_kodora[countkodora].posX = (float)(x * TIPSIZE);
				g_kodora[countkodora].posY = (float)(y * TIPSIZE);
				g_kodora[countkodora].e_element = FLAME;
				countkodora++;
			}
			else if (map[y][x] == ICE_KODORA && countkodora < KODORA_MAX)
			{
				g_kodora[countkodora].posX = (float)(x * TIPSIZE);
				g_kodora[countkodora].posY = (float)(y * TIPSIZE);
				g_kodora[countkodora].e_element = ICE;
				countkodora++;
			}
			else if (map[y][x] == WIND_KODORA && countkodora < KODORA_MAX)
			{
				g_kodora[countkodora].posX = (float)(x * TIPSIZE);
				g_kodora[countkodora].posY = (float)(y * TIPSIZE);
				g_kodora[countkodora].e_element = WIND;
				countkodora++;
			}
		}
	}
}

void Slime_Init()
{
	int countslime = 0;

	for (int y = 0; y < MAP_HEIGHT; y++)
	{
		for (int x = 0; x < MAP_WIDTH; x++)
		{
			if (map[y][x] == FLAME_SLIME && countslime < SLIME_MAX)
			{
				g_slime[countslime].posX = (float)(x * TIPSIZE);
				g_slime[countslime].posY = (float)(y * TIPSIZE);
				g_slime[countslime].e_element = FLAME;
				countslime++;
			}
			else if (map[y][x] == ICE_SLIME && countslime < SLIME_MAX)
			{
				g_slime[countslime].posX = (float)(x * TIPSIZE);
				g_slime[countslime].posY = (float)(y * TIPSIZE);
				g_slime[countslime].e_element = ICE;
				countslime++;
			}
			else if (map[y][x] == WIND_SLIME && countslime < SLIME_MAX)
			{
				g_slime[countslime].posX = (float)(x * TIPSIZE);
				g_slime[countslime].posY = (float)(y * TIPSIZE);
				g_slime[countslime].e_element = WIND;
				countslime++;
			}
		}
	}
}