/**
* @file WindGmmick_Cntrol.cpp
* @breif 風ギミックのファイル

* 風ギミックの操作に必要な処理を書いている

*/

#include "../GameScene/GameSceneControl.h"
#include "../GameScene/GameSceneInit.h"
#include "../Player/PlayerControl.h"
#include "../Enemy/EnemyControl.h"
#include "WindGimmick_Draw.h"
#include "WindGimmick_Control.h"


void WindGimmick_Control()
{
	int windblockcount = 0;

	for (int i = 0; i < KODORA_MAX; i++)
	{
		if (g_gimmick.outbreakFlag == true && g_gimmick.drawFlag == true && g_kodora[i].e_element == WIND)
		{
			CUSTOMVERTEX drawgimmick[4];

			for (int j = 0; j < 4; j++)
			{
				drawgimmick[j] = g_windgimmick[j];
				drawgimmick[j].x += g_kodora[i].posX;
				drawgimmick[j].y += g_kodora[i].posY;
			}

			// うぃんどうギミックの範囲確定
			// 例：マップの[1][1]～[3][3]までなど
			int windfirstvertexX = (int)(drawgimmick[0].x / TIPSIZE);
			int windfirstvertexY = (int)(drawgimmick[0].y / TIPSIZE);

			int windthirdvertexX = (int)(drawgimmick[2].x / TIPSIZE);
			int windthirdvertexY = (int)(drawgimmick[2].y / TIPSIZE);


			// 上の計算結果でマップチェック(ブロック消去と消去数のカウント)

			for (int y = windfirstvertexY; y <= windthirdvertexY; y++)
			{
				for (int x = windfirstvertexX; x <= windthirdvertexX; x++)
				{
					if (map[y][x] == WIND_BLOCK)
					{
						map[y][x] = 0;
						windblockcount++;
					}
				}
			}

			// うぃんどうギミックの範囲の中心を出す
			int centerpositionX = ((windfirstvertexX + windthirdvertexX) / 2);
			int centerpositionY = ((windfirstvertexY + windthirdvertexY) / 2);

			// 上の計算結果でマップチェック(点線ブロックの入れ替え)

			int step = Right;
			int max_x = 1;
			int max_y = 1;
			bool endflag = false;

			while ((max_x <= 20 && max_y <= 20) && endflag == false)
			{
				switch (step)
				{
				case Left:
					
					for (int i = 0; i < max_x; i++)
					{
						if (map[centerpositionY][centerpositionX] == WIND_POS_BLOCK)
						{
							map[centerpositionY][centerpositionX] = WIND_BLOCK;
							windblockcount--;

							if (windblockcount <= 0)
							{
								endflag = true;
								break;
							}
						}
						centerpositionX--;
					}
					max_x++;

					step = Up;

					break;

				case Right:

					for (int i = 0; i < max_x; i++)
					{
						if (map[centerpositionY][centerpositionX] == WIND_POS_BLOCK)
						{
							map[centerpositionY][centerpositionX] = WIND_BLOCK;
							windblockcount--;

							if (windblockcount <= 0)
							{
								endflag = true;
								break;
							}
						}
						centerpositionX++;
					}
					max_x++;

					step = Down;
					break;

				case Up:

					for (int i = 0; i < max_y; i++)
					{
						if (map[centerpositionY][centerpositionX] == WIND_POS_BLOCK)
						{
							map[centerpositionY][centerpositionX] = WIND_BLOCK;
							windblockcount--;

							if (windblockcount <= 0)
							{
								endflag = true;
								break;
							}
						}
						centerpositionY--;
					}
					max_y++;

					step = Right;

					break;

				case Down:


					for (int i = 0; i < max_y; i++)
					{
						if (map[centerpositionY][centerpositionX] == WIND_POS_BLOCK)
						{
							map[centerpositionY][centerpositionX] = WIND_BLOCK;
							windblockcount--;

							if (windblockcount <= 0)
							{
								endflag = true;
								break;
							}
						}
						centerpositionY++;
					}
					max_y++;

					step = Left;

					break;
				}
			}

			g_gimmick.outbreakFlag = false;

		}
	}
}