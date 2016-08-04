
#include "GameSceneDraw.h"
#include "EnemyDraw.h"

CUSTOMVERTEX g_Enemy[4] =
{
	{ 0.0f, 0.0f, 0.5f, 1.0f, 0xFFFFFFFF, 0.0f, 0.0f },
	{ 128.0f, 0.0f, 0.5f, 1.0f, 0xFFFFFFFF, -1.0f, 0.0f },
	{ 128.0f, 128.0f, 0.5f, 1.0f, 0xFFFFFFFF, -1.0f, 1.0f },
	{ 0.0f, 128.0f, 0.5f, 1.0f, 0xFFFFFFFF, 0.0f, 1.0f },

};



ENEMY_STATE g_enemy = { 1200.f, 320.f,};


void Draw_Enemy()
{
	CUSTOMVERTEX drawenemy[4];
	for (int i = 0; i < 4; i++)
	{
		drawenemy[i] = g_Enemy[i];
		drawenemy[i].x += g_enemy.posX;
		drawenemy[i].y += g_enemy.posY;
	}
	Draw_Obj(g_pTexture[ENEMY_TEX], drawenemy);
}