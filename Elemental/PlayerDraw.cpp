/**
 * @file PlayerDraw.cpp
 * @breif ��l���̕`��Ɋ֌W���鏈���̓��e�������Ă���
 * @author �ēc�N�ǁA�R�{�ϑ��Y�A�ݖ{��́A����G���A�c���M��A�|���ĕ��A�ѓc����
 * @date 2016�NX��Y��
 */
#include "GameSceneDraw.h"
#include "PlayerDraw.h"

CUSTOMVERTEX g_charcter[4] =
{
	{   0.0f,  0.0f, 0.5f, 1.0f, 0xFFFFFFFF, 0.0f, 0.0f },
	{ 128.0f,  0.0f, 0.5f, 1.0f, 0xFFFFFFFF, 1.0f, 0.0f },
	{ 128.0f, 128.0f, 0.5f, 1.0f, 0xFFFFFFFF, 1.0f, 1.0f },
	{   0.0f, 128.0f, 0.5f, 1.0f, 0xFFFFFFFF, 0.0f, 1.0f },

};

PLAYER_STATE g_player = { 300.f, 300.f, false, false };

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