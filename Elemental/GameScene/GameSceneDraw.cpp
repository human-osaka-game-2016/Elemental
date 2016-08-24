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

// 描画関数
void Render()
{
	
	CUSTOMVERTEX background[4] =
	{
		{ 0.0f, 0.0f, 0.5f, 1.0f, 0xFFFFFFFF, 0.0f, 0.0f },
		{ 1440.f, 0.0f, 0.5f, 1.0f, 0xFFFFFFFF, 1.0f, 0.0f },
		{ 1440.f, 810, 0.5f, 1.0f, 0xFFFFFFFF, 1.0f, 1.0f },
		{ 0.0f, 810, 0.5f, 1.0f, 0xFFFFFFFF, 0.0f, 1.0f },

	};
	
	Draw_Start();
	Draw_Obj(g_pTexture[BACKGROUND_TEX], background);
	Draw_Map();
	Draw_Kodora();
	Player_Draw();
	Player_Aura_Draw(g_player.flamedrawFlag, PLAYER_FLAME_TEX);
	Player_Aura_Draw(g_player.icedrawFlag, PLAYER_ICE_TEX);
	Player_Aura_Draw(g_player.winddrawFlag, PLAYER_WIND_TEX);
	Player_Bullet_Draw();
	WindGimmick_Draw();
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
	// マップチップの頂点情報
	CUSTOMVERTEX Maptip[4] =
	{
		{ 0.0f, 0.0f, 0.5f, 1.0f, 0xFFFFFFFF, 0.0f, 0.0f },
		{ TIPSIZE, 0.0f, 0.5f, 1.0f, 0xFFFFFFFF, 1.0f, 0.0f },
		{ TIPSIZE, TIPSIZE, 0.5f, 1.0f, 0xFFFFFFFF, 1.0f, 1.0f },
		{ 0.0f, TIPSIZE, 0.5f, 1.0f, 0xFFFFFFFF, 0.0f, 1.0f },

	};

	for (int y = 0; y < MAP_HEIGHT; y++)
	{
		for (int x = 0; x < MAP_WIDTH; x++)
		{
			if (map[y][x] == 1)						// 読みこんだファイルに1と書かれている所は指定した画像を描画するようにしている
			{
				CUSTOMVERTEX drawmap[4];			// 空のCUSTOMVERTEX用意
				for (int i = 0; i < 4; i++)
				{
					drawmap[i] = Maptip[i];		// マップチップの頂点情報を空のCUSTOMVERTEXに代入している
				}

				// このままだと1個しか描画されないので下の処理で指定した範囲分すべて描画するようにしている
				for (int i = 0; i < 4; i++)
				{
					drawmap[i].x += (x * TIPSIZE);	// 次のチップを描画するためにチップの大きさ分動かして描画している
					drawmap[i].y += (y * TIPSIZE);	// 上に同じ
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
		drawobj[i].x -= g_ScreenOriginX;
		drawobj[i].y -= g_ScreenOriginY;
	}

	Draw_Display(_pTexture, drawobj);
}
