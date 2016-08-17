/**
 * @file PlayerDraw.cpp
 * @breif 主人公の描画ファイル

 * 主人公の描画に必要な処理を書いている

 */

#include "../GameScene/GameSceneDraw.h"
#include "../GameScene/GameSceneControl.h"
#include "../GameScene/GameSceneInit.h"
#include "../Player/PlayerControl.h"

// 主人公の描画関数
void Player_Draw()
{
	// 主人公の頂点情報
	CUSTOMVERTEX main_charcter[4] =
	{
		{ 0.0f, 0.0f, 0.5f, 1.0f, 0xFFFFFFFF, 0.0f, 0.0f },
		{ 128.0f, 0.0f, 0.5f, 1.0f, 0xFFFFFFFF, 1.0f, 0.0f },
		{ 128.0f, 128.0f, 0.5f, 1.0f, 0xFFFFFFFF, 1.0f, 1.0f },
		{ 0.0f, 128.0f, 0.5f, 1.0f, 0xFFFFFFFF, 0.0f, 1.0f },

	};

	if (g_player.drawFlag == true)
	{
		CUSTOMVERTEX drawplayer[4];					// 空のCUSTOMVERTEXを用意

		for (int i = 0; i < 4; i++)
		{
			drawplayer[i] = main_charcter[i];		// main_charcterの頂点情報を空のCUSTOMVERTEXに代入
			drawplayer[i].x += g_player.posX;		// 主人公の現在位置をX軸に代入
			drawplayer[i].y += g_player.posY;		// 主人公の現在位置をY軸に代入
		}

		Draw_Obj(g_pTexture[PLAYER_TEX], drawplayer);
	}
}

void Player_Aura_Draw(bool _auraFlag, float _texsize, GAMETEX _auratex)
{
	// オーラ主人公の頂点情報
	CUSTOMVERTEX g_main_auracharcter[4] =
	{
		{ 0.0f, 0.0f, 0.5f, 1.0f, 0xFFFFFFFF, 0.0f, 0.0f },
		{ 128.0f, 0.0f, 0.5f, 1.0f, 0xFFFFFFFF, 0.25f, 0.0f },
		{ 128.0f, 128.0f, 0.5f, 1.0f, 0xFFFFFFFF, 0.25f, 0.25f },
		{ 0.0f, 128.0f, 0.5f, 1.0f, 0xFFFFFFFF, 0.0f, 0.25f },
	};

	if (_auraFlag == true)
	{
		CUSTOMVERTEX playerauradraw[4];
		for (int i = 0; i < 4; i++)
		{
			playerauradraw[i] = g_main_auracharcter[i];
			playerauradraw[i].x += g_player.posX;
			playerauradraw[i].y += g_player.posY;
			playerauradraw[i].tu += _texsize;
		}
		Draw_Obj(g_pTexture[_auratex], playerauradraw);
	}
}

void Player_Bullet_Draw()
{
	CUSTOMVERTEX bullet[4] =
	{
		{ -TIPSIZE / 2.0f, -TIPSIZE / 2.0f, 0.5f, 1.0f, 0xFFFFFFFF, 0.0f, 0.0f },
		{ TIPSIZE / 2.0f, -TIPSIZE / 2.0f, 0.5f, 1.0f, 0xFFFFFFFF, 1.0f, 0.0f },
		{ TIPSIZE / 2.0f, TIPSIZE / 2.0f, 0.5f, 1.0f, 0xFFFFFFFF, 1.0f, 1.0f },
		{ -TIPSIZE / 2.0f, TIPSIZE / 2.0f, 0.5f, 1.0f, 0xFFFFFFFF, 0.0f, 1.0f },
	};

	if (g_bullet.bullet[2].x <= 0.f)
	{
		g_bullet.drawFlag = false;
		g_bullet.initFlag = true;
	}

	if (g_bullet.bullet[0].x >= 1440.f)
	{
		g_bullet.drawFlag = false;
		g_bullet.initFlag = true;
	}

	if (Map_Collision_Check(g_bullet.poX - BULLET_SPEED, g_bullet.poY, 1, 1))
	{
		g_bullet.drawFlag = false;
		g_bullet.initFlag = true;
	}

	if (Map_Collision_Check(g_bullet.poX + BULLET_SPEED, g_bullet.poY, 1, 1))
	{
		g_bullet.drawFlag = false;
		g_bullet.initFlag = true;
	}

	if (g_bullet.initFlag == true)
	{
		for (int i = 0; i < 4; i++)
		{
			g_bullet.bullet[i] = bullet[i];
			g_bullet.bullet[i].x += g_player.posX;
			g_bullet.bullet[i].y += g_player.posY;
		}
	}

	if (g_bullet.drawFlag == true)
	{
		Draw_Obj(g_pTexture[BULLET_TEX], g_bullet.bullet);
	}

}