/**
 * @file PlayerDraw.cpp
 * @breif 主人公の描画ファイル

 * 主人公の描画に必要な処理を書いている

 */

#include "../GameScene/GameSceneDraw.h"
#include "../GameScene/GameSceneInit.h"

// 主人公の頂点情報
CUSTOMVERTEX main_charcter[4] =
{
	{ 0.0f, 0.0f, 0.5f, 1.0f, 0xFFFFFFFF, 0.0f, 0.0f },
	{ 128.0f, 0.0f, 0.5f, 1.0f, 0xFFFFFFFF, 1.0f, 0.0f },
	{ 128.0f, 128.0f, 0.5f, 1.0f, 0xFFFFFFFF, 1.0f, 1.0f },
	{ 0.0f, 128.0f, 0.5f, 1.0f, 0xFFFFFFFF, 0.0f, 1.0f },

};

// オーラ主人公の頂点情報
CUSTOMVERTEX g_main_auracharcter[4] =
{
	{ 0.0f, 0.0f, 0.5f, 1.0f, 0xFFFFFFFF, 0.0f, 0.0f },
	{ 128.0f, 0.0f, 0.5f, 1.0f, 0xFFFFFFFF, 0.25f, 0.0f },
	{ 128.0f, 128.0f, 0.5f, 1.0f, 0xFFFFFFFF, 0.25f, 0.25f },
	{ 0.0f, 128.0f, 0.5f, 1.0f, 0xFFFFFFFF, 0.0f, 0.25f },
};

// 主人公の描画関数
void Draw_Player()
{
	CUSTOMVERTEX drawplayer[4];					// 空のCUSTOMVERTEXを用意

	if (g_player.drawFlag == true)
	{
		for (int i = 0; i < 4; i++)
		{
			drawplayer[i] = main_charcter[i];		// main_charcterの頂点情報を空のCUSTOMVERTEXに代入
			drawplayer[i].x += g_player.posX;		// 主人公の現在位置をX軸に代入
			drawplayer[i].y += g_player.posY;		// 主人公の現在位置をY軸に代入
		}

		Draw_Obj(g_pTexture[PLAYER_TEX], drawplayer);
	}
}

void Player_Aura_Draw(bool _auraFlag, GAMETEX _auratex, float _texsize)
{
	if (_auraFlag == true)
	{
		CUSTOMVERTEX playerauradraw[4];
		for (int i = 0; i < 4; i++)
		{
			playerauradraw[i] = g_main_auracharcter[i];
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