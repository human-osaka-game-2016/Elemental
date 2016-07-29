#include <stdio.h>
#include "GameSceneDraw.h"
#include "PlayerDraw.h"

float g_ScreenOriginX = 0.0f;
float g_ScreenOriginY = 0.0f;

LPDIRECT3DTEXTURE9 g_pTexture[TEX_MAX];

CUSTOMVERTEX g_maptip[4] =
{
	{ 0.0f, 0.0f, 0.5f, 1.0f, 0xFFFFFFFF, 0.0f, 0.0f },
	{ TIPSIZE, 0.0f, 0.5f, 1.0f, 0xFFFFFFFF, 1.0f, 0.0f },
	{ TIPSIZE, TIPSIZE, 0.5f, 1.0f, 0xFFFFFFFF, 1.0f, 1.0f },
	{ 0.0f, TIPSIZE, 0.5f, 1.0f, 0xFFFFFFFF, 0.0f, 1.0f },

};

// csvで読み込む範囲
int map[MAP_HEIGHT][MAP_WIDTH];

// 描画関数
void Render()
{
	CUSTOMVERTEX background[4] =
	{
		{ 0.0f, 0.0f, 0.5f, 1.0f, 0xFFFFFFFF, 0.0f, 0.0f },
		{ 1280.f, 0.0f, 0.5f, 1.0f, 0xFFFFFFFF, 1.0f, 0.0f },
		{ 1280.f, 736, 0.5f, 1.0f, 0xFFFFFFFF, 1.0f, 1.0f },
		{ 0.0f, 736, 0.5f, 1.0f, 0xFFFFFFFF, 0.0f, 1.0f },

	};
	Draw_Start();
	Draw_Obj(g_pTexture[BACKGROUND_TEX], background);
	Draw_Map();
	Draw_Player();
	Draw_End();
}


// ファイルを読み込むための関数
void Load_Map(const char* mapdata)
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

// csvに書いたマップ情報を反映させている
void Draw_Map()
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
				Draw_Obj(g_pTexture[MAP_GROUND_TEX], drawmap);
			}
		}
	}
}

void Draw_Obj(LPDIRECT3DTEXTURE9   _pTexture, CUSTOMVERTEX _setdraw[]) 
{
	CUSTOMVERTEX drawobj[4];

	for (int i = 0; i < 4; i++) 
	{
		drawobj[i] = _setdraw[i];
		drawobj[i].m_x -= g_ScreenOriginX;
		drawobj[i].m_y -= g_ScreenOriginY;
	}

	Draw_Display(_pTexture, drawobj);
}
