// ファイルを読み込むためにはインクルードしなければならない
#include <stdio.h>
//　ただのヘッダー
#include "GameSceneDraw.h"

/* 
テクスチャを貼るためにはこれを宣言しなければならない
グローバルにしてるのでg_をつけている
*/

LPDIRECT3DTEXTURE9 g_pTexture[TEX_MAX];

/*
マップチップの頂点情報を入れている
他のcppで使うためグローバルにおいている
グルーバルにしているのでg_をつけている
*/
CUSTOMVERTEX g_maptip[4] =
{
	{ 0.0f, 0.0f, 0.5f, 1.0f, 0xFFFFFFFF, 0.0f, 0.0f },
	{ TIPSIZE, 0.0f, 0.5f, 1.0f, 0xFFFFFFFF, 1.0f, 0.0f },
	{ TIPSIZE, TIPSIZE, 0.5f, 1.0f, 0xFFFFFFFF, 1.0f, 1.0f },
	{ 0.0f, TIPSIZE, 0.5f, 1.0f, 0xFFFFFFFF, 0.0f, 1.0f },

};

// csvで読み込む範囲
int map[MAP_HEIGHT][MAP_WIDTH];

void Render()
{
	// 背景の頂点情報
	CUSTOMVERTEX background[4] =
	{
		{ 0.0f, 0.0f, 0.5f, 1.0f, 0xFFFFFFFF, 0.0f, 0.0f },
		{ 1280.f, 0.0f, 0.5f, 1.0f, 0xFFFFFFFF, 1.0f, 0.0f },
		{ 1280.f, 720, 0.5f, 1.0f, 0xFFFFFFFF, 1.0f, 1.0f },
		{ 0.0f, 720, 0.5f, 1.0f, 0xFFFFFFFF, 0.0f, 1.0f },

	};
	// この関数を呼べば描画の前の準備をする(ライブラリ関数)
	Draw_Start();
	// この関数を呼べば描画できる(ライブラリ関数)
	Draw_Display(g_pTexture[BACKGROUND_TEX], background);
	Map_Draw();
	// 描画を終わらせる(ライブラリ関数)
	Draw_End();
}


// ファイルを読み込むための関数
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

// csvに書いたマップ情報を反映させている
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