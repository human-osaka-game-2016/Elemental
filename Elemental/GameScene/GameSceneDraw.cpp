/**
 * @file GameSceneDraw.cpp
 * @breif 描画の基盤になるファイル

 * ゲーム全体の描画に必要な処理を書いている

 */

#include <stdio.h>
#include <stdlib.h>
#include "GameSceneDraw.h"
#include "../GameScene/GameSceneInit.h"
#include "../Player/PlayerDraw.h"
#include "../Enemy/EnemyDraw.h"
#include "../Gmmick/WindGimmick_Draw.h"

float g_ScreenOriginX = 0.0f;	// X座標の画面端を原点としている
float g_ScreenOriginY = 0.0f;	// Y座標の画面端を原点としている

LPDIRECT3DTEXTURE9 g_pTexture[TEX_MAX];	

// csvで読み込む範囲
int map[MAP_HEIGHT][MAP_WIDTH];

// マップチップの頂点情報
CUSTOMVERTEX g_Maptip[4] =
{
	{ 0.0f, 0.0f, 0.5f, 1.0f, 0xFFFFFFFF, 0.0f, 0.0f },
	{ TIPSIZE, 0.0f, 0.5f, 1.0f, 0xFFFFFFFF, 1.0f, 0.0f },
	{ TIPSIZE, TIPSIZE, 0.5f, 1.0f, 0xFFFFFFFF, 1.0f, 1.0f },
	{ 0.0f, TIPSIZE, 0.5f, 1.0f, 0xFFFFFFFF, 0.0f, 1.0f },

};

// 描画関数
void Render()
{
	
	CUSTOMVERTEX background[4] =
	{
		{ 0.0f, 0.0f, 0.5f, 1.0f, 0xFFFFFFFF, 0.0f, 0.0f },
		{ 6400.f, 0.0f, 0.5f, 1.0f, 0xFFFFFFFF, 1.0f, 0.0f },
		{ 6400.f, 1408.f, 0.5f, 1.0f, 0xFFFFFFFF, 1.0f, 1.0f },
		{ 0.0f, 1408.f, 0.5f, 1.0f, 0xFFFFFFFF, 0.0f, 1.0f },

	};
	

	Draw_Start();

	Draw_Obj(g_pTexture[BACKGROUND_TEX], background);
	Draw_Map();

	Kodora_Walk_Draw();
	Kodora_Stay_Draw();
	Skeleton_Draw();
	Slime_Draw();

	Player_Draw();
	Player_Sky_Draw();
	Player_Bullet_Draw();

	WindGimmick_Draw();

	Goal_Draw();

	Draw_End();
}




// ファイルを読み込むための関数
void Load_Map(const char* _mapdata)
{
	FILE*  fp;
	fopen_s(&fp, _mapdata, "r");	// _mapdateに書かれたファイルを読み取っているだけ

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
			if (map[y][x] == NORMAL_BLOCK)						// 読みこんだファイルに1と書かれている所は指定した画像を描画するようにしている
			{
				CUSTOMVERTEX drawmap[4];			// 空のCUSTOMVERTEX用意
				for (int i = 0; i < 4; i++)
				{
					drawmap[i] = g_Maptip[i];		// マップチップの頂点情報を空のCUSTOMVERTEXに代入している
				}

				// このままだと1個しか描画されないので下の処理で指定した範囲分すべて描画するようにしている
				for (int i = 0; i < 4; i++)
				{
					drawmap[i].x += (x * TIPSIZE);	// 次のチップを描画するためにチップの大きさ分動かして描画している
					drawmap[i].y += (y * TIPSIZE);	// 上に同じ
				}
				Draw_Obj(g_pTexture[MAP_BLOCK_TEX], drawmap);
			}
			else if (map[y][x] == FLAME_BLOCK)
			{
				CUSTOMVERTEX drawmap[4];			// 空のCUSTOMVERTEX用意
				for (int i = 0; i < 4; i++)
				{
					drawmap[i] = g_Maptip[i];		// マップチップの頂点情報を空のCUSTOMVERTEXに代入している
				}

				for (int i = 0; i < 4; i++)
				{
					drawmap[i].x += (x * TIPSIZE);	// 次のチップを描画するためにチップの大きさ分動かして描画している
					drawmap[i].y += (y * TIPSIZE);	// 上に同じ
				}
				Draw_Obj(g_pTexture[FLAME_BLOCK_TEX], drawmap);
			}
			else if (map[y][x] == WIND_BLOCK)
			{
				CUSTOMVERTEX drawmap[4];			// 空のCUSTOMVERTEX用意
				for (int i = 0; i < 4; i++)
				{
					drawmap[i] = g_Maptip[i];		// マップチップの頂点情報を空のCUSTOMVERTEXに代入している
				}

				for (int i = 0; i < 4; i++)
				{
					drawmap[i].x += (x * TIPSIZE);	// 次のチップを描画するためにチップの大きさ分動かして描画している
					drawmap[i].y += (y * TIPSIZE);	// 上に同じ
				}
				Draw_Obj(g_pTexture[WIND_BLOCK_TEX], drawmap);
			}
			else if (map[y][x] == WIND_POS_BLOCK)
			{
				CUSTOMVERTEX drawmap[4];			// 空のCUSTOMVERTEX用意
				for (int i = 0; i < 4; i++)
				{
					drawmap[i] = g_Maptip[i];		// マップチップの頂点情報を空のCUSTOMVERTEXに代入している
				}

				for (int i = 0; i < 4; i++)
				{
					drawmap[i].x += (x * TIPSIZE);	// 次のチップを描画するためにチップの大きさ分動かして描画している
					drawmap[i].y += (y * TIPSIZE);	// 上に同じ
				}
				Draw_Obj(g_pTexture[WIND_POS_BLOCK_TEX], drawmap);
			}
		}
	}
}

void Goal_Draw()
{
	CUSTOMVERTEX goal[4] =
	{
		{ 0.0f, 0.0f, 0.5f, 1.0f, 0xFFFFFFFF, 0.0f, 0.0f },
		{ 128, 0.0f, 0.5f, 1.0f, 0xFFFFFFFF, 0.25f, 0.0f },
		{ 128, 128, 0.5f, 1.0f, 0xFFFFFFFF, 0.25f, 1.0f },
		{ 0.0f, 128, 0.5f, 1.0f, 0xFFFFFFFF, 0.0f, 1.0f },

	};

	for (int y = 0; y < MAP_HEIGHT; y++)
	{
		for (int x = 0; x < MAP_WIDTH; x++)
		{
			if (map[y][x] == TREASURE_BOX)
			{
				for (int i = 0; i < 4; i++)
				{
					goal[i].x += (x * TIPSIZE);	
					goal[i].y += (y * TIPSIZE);
				}

				Draw_Obj(g_pTexture[GOAL], goal);
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
		drawobj[i].x -= g_ScreenOriginX;
		drawobj[i].y -= g_ScreenOriginY;
	}

	Draw_Display(_pTexture, drawobj);
}
