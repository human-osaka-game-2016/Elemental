/**
 * @file PlayerDraw.cpp
 * @breif 主人公の描画ファイル

 * 主人公の描画に必要な処理を書いている

 */

#include "GameSceneDraw.h"
#include "GameSceneInit.h"

// 主人公の頂点情報
CUSTOMVERTEX g_main_charcter[4] =
{
	{   0.0f,  0.0f, 0.5f, 1.0f, 0xFFFFFFFF, 0.0f, 0.0f },
	{ 128.0f,  0.0f, 0.5f, 1.0f, 0xFFFFFFFF, 1.0f, 0.0f },
	{ 128.0f, 128.0f, 0.5f, 1.0f, 0xFFFFFFFF, 1.0f, 1.0f },
	{   0.0f, 128.0f, 0.5f, 1.0f, 0xFFFFFFFF, 0.0f, 1.0f },

};

// 主人公の描画関数
void Draw_Player()
{
	CUSTOMVERTEX drawplayer[4];					// 空のCUSTOMVERTEXを用意
	for (int i = 0; i < 4; i++)
	{
		drawplayer[i] = g_main_charcter[i];		// main_charcterの頂点情報を空のCUSTOMVERTEXに代入
		drawplayer[i].x += g_player.posX;		// 主人公の現在位置をX軸に代入
		drawplayer[i].y += g_player.posY;		// 主人公の現在位置をY軸に代入
	}
	Draw_Obj(g_pTexture[PLAYER_TEX], drawplayer);

}