/**
 * @file EnemyDraw
 * @breif 全ての敵の描画ファイル

 * 全ての敵の描画に必要な処理を書いている

 */

#include "GameSceneDraw.h"
#include "GameSceneInit.h"

// コドラの頂点情報
CUSTOMVERTEX g_Kodora[4] =
{
	{ 0.0f, 0.0f, 0.5f, 1.0f, 0xFFFFFFFF, 0.0f, 0.0f },
	{ 128.0f, 0.0f, 0.5f, 1.0f, 0xFFFFFFFF, -1.0f, 0.0f },
	{ 128.0f, 128.0f, 0.5f, 1.0f, 0xFFFFFFFF, -1.0f, 1.0f },
	{ 0.0f, 128.0f, 0.5f, 1.0f, 0xFFFFFFFF, 0.0f, 1.0f },

};

// コドラの描画関数
void Draw_Kodora()
{
	CUSTOMVERTEX drawkodora[4];
	for (int i = 0; i < 4; i++)
	{
		drawkodora[i] = g_Kodora[i];
		drawkodora[i].x += g_enemy.posX;
		drawkodora[i].y += g_enemy.posY;
	}
	Draw_Obj(g_pTexture[ENEMY_TEX], drawkodora);
}