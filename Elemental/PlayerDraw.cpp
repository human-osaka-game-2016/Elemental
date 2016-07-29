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
		drawplayer[i].m_x += g_player.posX;
		drawplayer[i].m_y += g_player.posY;
	}
	Draw_Obj(g_pTexture[PLAYER_TEX], drawplayer);
}