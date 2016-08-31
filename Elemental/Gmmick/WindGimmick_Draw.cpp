/**
 * @file WindGmmick_Draw.cpp
 * @breif 風ギミックのファイル

 * 風ギミックの描画に必要な処理を書いている

 */

#include <Direct_Draw.h>
#include "../GameScene/GameSceneInit.h"
#include "WindGimmick_Draw.h"
#include "WindGimmick_Control.h"

CUSTOMVERTEX g_windgimmick[4] =
{
	{ -128.0f, -128.0f, 0.5f, 1.0f, 0xFFFFFFFF, 0.0f, 0.0f },
	{ 384.f, -128.0f, 0.5f, 1.0f, 0xFFFFFFFF, 0.25f, 0.0f },
	{ 384.f, 384.f, 0.5f, 1.0f, 0xFFFFFFFF, 0.25f, 1.0f },
	{ -128.0f, 384.f, 0.5f, 1.0f, 0xFFFFFFFF, 0.0f, 1.0f },
};

void WindGimmick_Draw()
{

	for (int j = 0; j < KODORA_MAX; j++)
	{
		if (g_kodora[j].hitFlag == true)
		{
			static int animatime = 0;
			static int animacount = 0;
			static int getcount = 0;

			CUSTOMVERTEX drawgimmick[4];

			for (int i = 0; i < 4; i++)
			{
				drawgimmick[i] = g_windgimmick[i];
				drawgimmick[i].x += g_kodora[j].posX;
				drawgimmick[i].y += g_kodora[j].posY;
			}
			getcount++;

			if (getcount >= 240 && g_gimmick.drawFlag == true)
			{
				for (int i = 0; i < 4; i++)
				{
					drawgimmick[i].tu += (0.25f * animacount);
				}

				animatime++;

				if (animatime % 60 == 0)
				{
					animacount++;

					if (animacount == 4)
					{
						animacount = 0;
						getcount = 0;
					}
				}
				g_gimmick.outdreakFlag = true;
				Draw_Obj(g_pTexture[WINDGIMMICK_TEX], drawgimmick);
			}
		}
	}
}