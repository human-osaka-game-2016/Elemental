/**
 * @file PlayerDraw.cpp
 * @breif εlφΜ`ζΙΦW·ιΜΰeπ’Δ’ι
 * @author ΔcNΗAR{ΟΎYAέ{εΝAλGΎAcMεA|ΊγΔ½AΡcξ
 * @date 2016NXYϊ
 */
#include "GameSceneDraw.h"
#include "PlayerDraw.h"

CUSTOMVERTEX g_charcter[4] =
{
	{   0.0f,  0.0f, 0.5f, 1.0f, 0xFFFFFFFF, 0.0f, 0.0f },
	{ 64.0f,  0.0f, 0.5f, 1.0f, 0xFFFFFFFF, 1.0f, 0.0f },
	{ 64.0f, 128.0f, 0.5f, 1.0f, 0xFFFFFFFF, 1.0f, 1.0f },
	{   0.0f, 128.0f, 0.5f, 1.0f, 0xFFFFFFFF, 0.0f, 1.0f },

};

PLAYER_STATE g_player = { 200.f, 448.f, false, false };

void Draw_Player()
{
	CUSTOMVERTEX drawplayer[4];
	for (int i = 0; i < 4; i++)
	{
		drawplayer[i] = g_charcter[i];
		drawplayer[i].x += g_player.posX;
		drawplayer[i].y += g_player.posY;
	}
	Draw_Obj(g_pTexture[PLAYER_TEX], drawplayer);
}