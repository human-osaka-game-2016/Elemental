/**
* @file FlameGmmick_Control.cpp
* @breif 火のギミックファイル

* 火ギミックの操作に必要な処理を書いている

*/

#include "FlameGimmick_Draw.h"
#include "FlameGimmick_Control.h"
#include "../GameScene/GameSceneInit.h"
#include "../GameScene/GameSceneDraw.h"
#include "../GameScene/GameSceneControl.h"

void FlameGimmick_Control()
{
	for (int j = 0; j < KODORA_MAX; j++)
	{
		if (g_kodora[j].hitFlag == true && g_kodora[j].e_element == FLAME)
		{
			static int fr_blook_count[KODORA_MAX] = { 0 };

			fr_blook_count[j]++;

			for (int y = 0; y < MAP_HEIGHT; y++)
			{
				for (int x = 0; x < MAP_WIDTH; x++)
				{
					if (map[y][x] == FLAME_BLOCK)
					{

						CUSTOMVERTEX flame_draw[4];
						CUSTOMVERTEX FR_blook[4];

						for (int i = 0; i < 4; i++)
						{
							FR_blook[i].x = (float)(x * TIPSIZE);
							FR_blook[i].y = (float)(y * TIPSIZE);

							flame_draw[i] = g_flamegimmick[i];
							flame_draw[i].x += g_kodora[j].posX;
							flame_draw[i].y += g_kodora[j].posY;
						}

						FR_blook[1].x += TIPSIZE;
						FR_blook[2].x += TIPSIZE;
						FR_blook[2].y += TIPSIZE;
						FR_blook[3].y += TIPSIZE;

						if (Collision_Check_CustomVertex(flame_draw, FR_blook))
						{
							if (fr_blook_count[j] >= 240)
							{

								if (map[y][x] = 0)
								{
									fr_blook_count[j] = 0;
									g_kodora[j].hitFlag = false;
								}
							}
						}
					}
				}
			}
		}
	}
}