/**
 * @file GameSceneInit.cpp
 * @breif 初期化ファイル
 
 * 初期化に必要な処理を書いている

 */

#include <Direct_Draw.h>
#include "GameSceneDraw.h"
#include "GameSceneInit.h"



PLAYER_STATE g_player = { 300.f, 350.f, 0.f, false, false, true, false, false };	

ENEMY_STATE g_enemy = { 1200.f, 320.f };

void Init()
{
	// 描画の初期化
	Init_Draw();

	//統合ファイルの画像を読み込むときResource/Texture/

	// 画像を読み込みどこかに割り当てている
	Load_Texture("ワールドチップ.png", &g_pTexture[MAP_GROUND_TEX]);
	//Load_Texture("", &g_pTexture[BACKGROUND_TEX]);
	Load_Texture("ストレンジ先生どっと絵.png", &g_pTexture[PLAYER_TEX]);
	Load_Texture("ゴジラ.png", &g_pTexture[ENEMY_TEX]);
	Load_Map("Resource/file/ElementalWorld.csv");

}