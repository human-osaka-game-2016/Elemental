#include <stdio.h>

#include "GameSceneDraw.h"

LPDIRECT3DTEXTURE9 g_pTexture[TEX_MAX];

CUSTOMVERTEX g_maptip[4] =
{
	{ 0.0f, 0.0f, 0.5f, 1.0f, 0xFFFFFFFF, 0.0f, 0.0f },
	{ TIPSIZE, 0.0f, 0.5f, 1.0f, 0xFFFFFFFF, 1.0f, 0.0f },
	{ TIPSIZE, TIPSIZE, 0.5f, 1.0f, 0xFFFFFFFF, 1.0f, 1.0f },
	{ 0.0f, TIPSIZE, 0.5f, 1.0f, 0xFFFFFFFF, 0.0f, 1.0f },

};

int map[MAP_HEIGHT][MAP_WIDTH];

void Render()
{
	CUSTOMVERTEX background[4] =
	{
		{ 0.0f, 0.0f, 0.5f, 1.0f, 0xFFFFFFFF, 0.0f, 0.0f },
		{ 1280.f, 0.0f, 0.5f, 1.0f, 0xFFFFFFFF, 1.0f, 0.0f },
		{ 1280.f, 720, 0.5f, 1.0f, 0xFFFFFFFF, 1.0f, 1.0f },
		{ 0.0f, 720, 0.5f, 1.0f, 0xFFFFFFFF, 0.0f, 1.0f },

	};

	Draw_Start();
	Draw_Display(g_pTexture[BACKGROUND_TEX], background);
	Map_Draw();
	Draw_End();
}

void Map_Load(const char* mapdata)
{
	FILE*  fp;
	fopen_s(&fp, mapdata, "r");

	for (int i = 0; i < MAP_HEIGHT; i++)
	{
		for (int j = 0; j < MAP_WIDTH; j++)
		{
			fscanf_s(fp, "%d,", &map[i][j], _countof(map));
		}
	}
}

void Map_Draw()
{
	for (int y = 0; y < MAP_HEIGHT; y++)
	{
		for (int x = 0; x < MAP_WIDTH; x++)
		{
			if (map[y][x] == 1)
			{
				CUSTOMVERTEX drawmap[4];
				for (int i = 0; i < 4; i++)
				{
					drawmap[i] = g_maptip[i];
				}

				for (int i = 0; i < 4; i++)
				{
					drawmap[i].m_x += (x * TIPSIZE);
					drawmap[i].m_y += (y * TIPSIZE);
				}
				Draw_Display(g_pTexture[MAP_GROUND_TEX], drawmap);
			}
		}
	}
}