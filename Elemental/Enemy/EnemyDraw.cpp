/**
 * @file EnemyDraw.cpp
 * @breif 全ての敵の描画ファイル

 * 全ての敵の描画に必要な処理を書いている

 */

#include "../GameScene/GameSceneDraw.h"
#include "../GameScene/GameSceneInit.h"

// コドラの描画関数
void Kodora_Draw()
{
	// コドラの頂点情報
	CUSTOMVERTEX Kodora[4] =
	{
		{ 0.0f, 0.0f, 0.5f, 1.0f, 0xFFFFFFFF, 0.0f, 0.0f },
		{ 128.0f, 0.0f, 0.5f, 1.0f, 0xFFFFFFFF, 0.5f, 0.0f },
		{ 128.0f, 128.0f, 0.5f, 1.0f, 0xFFFFFFFF, 0.5f, 1.0f },
		{ 0.0f, 128.0f, 0.5f, 1.0f, 0xFFFFFFFF, 0.0f, 1.0f },
	};

	static int animationtime = 0;


	CUSTOMVERTEX drawkodora[4];

	for (int j = 0; j < KODORA_MAX; j++)
	{
		for (int i = 0; i < 4; i++)
		{
			drawkodora[i] = Kodora[i];
			drawkodora[i].x += g_kodora[j].posX;
			drawkodora[i].y += g_kodora[j].posY;
		}

		animationtime++;

		if (animationtime <= 60)
		{
			for (int i = 0; i < 4; i++)
			{
				drawkodora[i].tu += 0.5f;
			}
		}
		else if (animationtime >= 120)
		{
			for (int i = 0; i < 4; i++)
			{
				drawkodora[i].tu -= 0.5f;
			}

			animationtime = 0;
		}


		if (g_kodora[j].drawFlag == true)
		{
			if (g_kodora[j].directionID == Left || g_kodora[j].directionID == Normal)
			{
				Draw_Obj(g_pTexture[KODORA_FLAME_LEFT_MOVE_TEX], drawkodora);
			}
			else if (g_kodora[j].directionID == Right)
			{
				Draw_Obj(g_pTexture[KODORA_FLAME_RIGHT_MOVE_TEX], drawkodora);
			}
		}
	}
}

// スケルトンの描画関数

void Skeleton_Draw()
{

}

void Slime_Draw()
{
	// スライムの頂点情報
	CUSTOMVERTEX Slime[4] =
	{
		{ 0.0f, 0.0f, 0.5f, 1.0f, 0xFFFFFFFF, 0.0f, 0.0f },
		{ 128.0f, 0.0f, 0.5f, 1.0f, 0xFFFFFFFF, 0.5f, 0.0f },
		{ 128.0f, 128.0f, 0.5f, 1.0f, 0xFFFFFFFF, 0.5f, 1.0f },
		{ 0.0f, 128.0f, 0.5f, 1.0f, 0xFFFFFFFF, 0.0f, 1.0f },
	};
	static int animationtime = 0;


	CUSTOMVERTEX drawslime[4];
	for (int j = 0; j < SLIME_MAX; j++)
	{
		for (int i = 0; i < 4; i++)
		{
			drawslime[i] = Slime[i];
			drawslime[i].x += g_slime[j].posX;
			drawslime[i].y += g_slime[j].posY;
		}
		animationtime++;

		if (animationtime <= 60)
		{
			for (int i = 0; i < 4; i++)
			{
				drawslime[i].tu += 0.5f;
			}
		}
		else if (animationtime >= 120)
		{
			for (int i = 0; i < 4; i++)
			{
				drawslime[i].tu -= 0.5f;
			}
			animationtime = 0;
		}

		if (g_slime[j].drawFlag == true)
		{
			if (g_slime[j].directionID == Left || g_slime[j].directionID == Normal)
			{
				Draw_Obj(g_pTexture[SLIME_FLAME_LEFT_MOVE_TEX], drawslime);
			}
			else if (g_slime[j].directionID == Right)
			{
				Draw_Obj(g_pTexture[SLIME_FLAME_RIGHT_MOVE_TEX], drawslime);
			}
		}
	}
}