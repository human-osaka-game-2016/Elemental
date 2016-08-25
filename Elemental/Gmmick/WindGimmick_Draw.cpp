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
		{ 512.f, 512.f, 0.5f, 1.0f, 0xFFFFFFFF, 0.25f, 1.0f },
		{ 0.0f, 512.f, 0.5f, 1.0f, 0xFFFFFFFF, 0.0f, 1.0f },
	};

	static int animatime = 0;
	static int animacount = 0;

	for (int j = 0; j < KODORA_MAX; j++)
	{
		if (g_kodora[j].hitFlag == true)
		{
			CUSTOMVERTEX drawgimmick[4];

			for (int i = 0; i < 4; i++)
			{
				drawgimmick[i] = windgimmick[i];
				drawgimmick[i].x += g_kodora[j].posX;
				drawgimmick[i].y += g_kodora[j].posY;
				drawgimmick[i].x -= 128;
				drawgimmick[i].y -= 350;
			}
			animatime++;

			if (animatime % 60 == 0)
			{
				for (int i = 0; i < 4; i++)
				{
					windgimmick[i].tu += (0.25f * animacount);
				}
				animacount++;
			}

			

			if (animacount == 4)
			{
				animacount = 0;
			}

			Draw_Obj(g_pTexture[WINDGIMMICK_TEX], drawgimmick);
		}
	}
}