/**
 * @file WindGmmick_Draw.cpp
 * @breif 風ギミックのファイル

 * 風ギミックの描画に必要な処理を書いている

 */

#include <Direct_Draw.h>
#include "../GameScene/GameSceneInit.h"
#include "WindGimmick_Draw.h"
#include "WindGimmick_Control.h"

void WindGimmick_Draw()
{
	CUSTOMVERTEX windgimmick[4] =
	{
		{ 0.0f, 0.0f, 0.5f, 1.0f, 0xFFFFFFFF, 0.0f, 0.0f },
		{ 512.f, 0.0f, 0.5f, 1.0f, 0xFFFFFFFF, 0.25f, 0.0f },
		{ 512.f, 512.f, 0.5f, 1.0f, 0xFFFFFFFF, 0.25f, 0.25f },
		{ 0.0f, 512.f, 0.5f, 1.0f, 0xFFFFFFFF, 0.0f, 0.25f },
	};

	if (g_enemy.hitFlag == true)
	{
		CUSTOMVERTEX drawgimmick[4];

		for (int i = 0; i < 4; i++)
		{
			drawgimmick[i] = windgimmick[i];
 			drawgimmick[i].x += g_enemy.posX;
			drawgimmick[i].y += g_enemy.posY;
		}

		Draw_Obj(g_pTexture[WINDGIMMICK_TEX], drawgimmick);
	}
}