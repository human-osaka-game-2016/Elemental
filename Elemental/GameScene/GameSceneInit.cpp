/**
 * @file GameSceneInit.cpp
 * @breif 初期化ファイル
 
 * 初期化に必要な処理を書いている

 */

#include <Direct_Draw.h>
#include "GameSceneDraw.h"
#include "GameSceneInit.h"
#include "../Player/PlayerDraw.h"


PLAYER_STATE g_player = { 150.f, 350.f, 0.f, true, false, false, false, false, false, false, false, false };

ENEMY_STATE g_enemy = { 730.f, 350.f, false };

BULLET_STATE g_bullet[BULLET_MAX];

void Init()
{
	// 描画の初期化
	Init_Draw();

	//統合ファイルの画像を読み込むときResource/Texture/

	// 画像を読み込みどこかに割り当てている
	Load_Texture("ワールドチップ.png", &g_pTexture[MAP_GROUND_TEX]);
	Load_Texture("Resource/Texture/Background/inside.png", &g_pTexture[BACKGROUND_TEX]);
	Load_Texture("ストレンジ先生どっと絵.png", &g_pTexture[PLAYER_TEX]);
	Load_Texture("Resource/Texture/Player/player_attack.png", &g_pTexture[PLAYER_FLAME_TEX]);
	Load_Texture("Resource/Texture/Player/player_attack.png", &g_pTexture[PLAYER_ICE_TEX]);
	Load_Texture("Resource/Texture/Player/player_attack.png", &g_pTexture[PLAYER_WIND_TEX]);
	Load_Texture("ゴジラ.png", &g_pTexture[ENEMY_TEX]);
	Load_Texture("Bubble.png", &g_pTexture[BULLET_TEX]);
	Load_Texture("Resource/Texture/Gimmick/tornado.png", &g_pTexture[WINDGIMMICK_TEX]);
	Load_Map("Resource/file/ElementalWorld.csv");

	for (int i = 0; i < BULLET_MAX; i++)
	{
		g_bullet[i].drawFlag = false;
		g_bullet[i].initFlag = true;
		g_bullet[i].posX = 0.0f;
		g_bullet[i].posY = 0.0f;
	}

}