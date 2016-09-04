/**
 * @file FlameGmmick_Draw.cpp
 * @breif 火のギミックファイル

 * 火ギミックの描画に必要な処理を書いている

 */

#include "FlameGimmick_Draw.h"
#include "FlameGimmick_Control.h"
#include "../GameScene/GameSceneInit.h"
#include "../GameScene/GameSceneDraw.h"
#include "../GameScene/GameSceneControl.h"

int g_count[KODORA_MAX] = { 0 };

CUSTOMVERTEX g_flamegimmick[4] =
{
	{ -128.0f, -128.0f, 0.5f, 1.0f, 0xFFFFFFFF, 0.0f, 0.0f },
	{ 256.f, -128.0f, 0.5f, 1.0f, 0xFFFFFFFF, 0.25f, 0.0f },
	{ 256.f, 256.f, 0.5f, 1.0f, 0xFFFFFFFF, 0.25f, 1.0f },
	{ -128.0f, 256.f, 0.5f, 1.0f, 0xFFFFFFFF, 0.0f, 1.0f },
};

void FlameGimmick_Draw()
{
	for (int j = 0; j < KODORA_MAX; j++)
	{
		if (g_kodora[j].hitFlag == true && g_kodora[j].e_element == FLAME)
		{
			//ゲーム時間をカウント
			static int explosiontime[KODORA_MAX] = { 0 };
			static int bakuha_count[KODORA_MAX] = { 0 };

			CUSTOMVERTEX flame_draw[4];

			for (int i = 0; i < 4; i++)
			{
				flame_draw[i] = g_flamegimmick[i];
				flame_draw[i].x += g_kodora[j].posX;
				flame_draw[i].y += g_kodora[j].posY;
			}

			bakuha_count[j]++;

			if (bakuha_count[j] >= 240)
			{

				for (int i = 0; i < 4; i++)
				{
					flame_draw[i].tu += (0.25f * g_count[j]);
				}
				explosiontime[j]++;

				if (explosiontime[j] % 60 == 0)
				{
					g_count[j]++;

					if (g_count[j] == 4)
					{
						g_count[j] = 0;
						bakuha_count[j] = 0;
						g_kodora[j].hitFlag = false;
					}
				}

				Draw_Obj(g_pTexture[FLAMEGIMMICK_TEX], flame_draw);
			}

		}
	}
}