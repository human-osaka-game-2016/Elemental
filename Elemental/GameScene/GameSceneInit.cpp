/**
 * @file GameSceneInit.cpp
 * @breif 初期化ファイル
 
 * 初期化に必要な処理を書いている

 */

#include <Direct_Draw.h>
#include "GameSceneDraw.h"
#include "GameSceneInit.h"
#include "../Player/PlayerDraw.h"


PLAYER_STATE g_player = { 150.f, 350.f, 0.f, NORMAL , true, false, false, false, false, false, false, false, false };

ENEMY_STATE g_kodora[KODORA_MAX];

ENEMY_STATE g_skereton[SKERETON_MAX];

BULLET_STATE g_bullet[BULLET_MAX];



void Init()
{
	// 描画の初期化
	Init_Draw();

	//統合ファイルの画像を読み込むときResource/Texture/フォルダ名/フォルダ名/ファイル名と書けば画像が読みこまれるようになる

	// 画像を読み込みどこかに割り当てている
	Load_Texture("ワールドチップ.png", &g_pTexture[MAP_GROUND_TEX]);
	Load_Texture("Resource/Texture/Background/inside.png", &g_pTexture[BACKGROUND_TEX]);

	// 通常の主人公の画像
	Load_Texture("Resource/Texture/Player/normal_player/player_state.png", &g_pTexture[PLAYER_RIGHT_TEX]);
	Load_Texture("Resource/Texture/Player/normal_player/player_move.png", &g_pTexture[PLAYER_RIGHT_MOVE_TEX]);
	Load_Texture("Resource/Texture/Player/normal_player_reverse/r_player_state.png", &g_pTexture[PLAYER_LEFT_TEX]);
	Load_Texture("Resource/Texture/Player/normal_player_reverse/r_player_move.png", &g_pTexture[PLAYER_LEFT_MOVE_TEX]);

	// 炎のオーラをまとった主人公の画像
	Load_Texture("Resource/Texture/Player/fire_player/f_player_state.png", &g_pTexture[PLAYER_FLAME_RIGHT_TEX]);
	Load_Texture("Resource/Texture/Player/fire_player/f_player_move.png", &g_pTexture[PLAYER_FLAME_RIGHT_MOVE_TEX]);
	Load_Texture("Resource/Texture/Player/fire_player_reverse/r_f_player_state.png", &g_pTexture[PLAYER_FLAME_LEFT_TEX]);
	Load_Texture("Resource/Texture/Player/fire_player_reverse/r_f_player_move.png", &g_pTexture[PLAYER_FLAME_LEFT_MOVE_TEX]);

	// 氷のオーラをまとった主人公の画像
	Load_Texture("Resource/Texture/Player/ice_player/i_player_state.png", &g_pTexture[PLAYER_ICE_RIGHT_TEX]);
	Load_Texture("Resource/Texture/Player/ice_player/i_player_move.png", &g_pTexture[PLAYER_ICE_RIGHT_MOVE_TEX]);
	Load_Texture("Resource/Texture/Player/ice_player_reverse/r_i_player_state.png", &g_pTexture[PLAYER_ICE_LEFT_TEX]);
	Load_Texture("Resource/Texture/Player/ice_player_reverse/r_i_player_move.png", &g_pTexture[PLAYER_ICE_LEFT_MOVE_TEX]);

	// 風のオーラをまとった主人公の画像
	Load_Texture("Resource/Texture/Player/wind_player/w_player_state.png", &g_pTexture[PLAYER_WIND_RIGHT_TEX]);
	Load_Texture("Resource/Texture/Player/wind_player/w_player_move.png", &g_pTexture[PLAYER_WIND_RIGHT_MOVE_TEX]);
	Load_Texture("Resource/Texture/Player/wind_player_reverse/r_w_player_state.png", &g_pTexture[PLAYER_WIND_LEFT_TEX]);
	Load_Texture("Resource/Texture/Player/wind_player_reverse/r_w_player_move.png", &g_pTexture[PLAYER_WIND_LEFT_MOVE_TEX]);

	// コドラの画像
	Load_Texture("Resource/Texture/Enemy/Kodora/flame_kodora/f_kodora_move.png", &g_pTexture[KODORA_MOVE_TEX]);

	// スケルトンの画像
	Load_Texture("Resource/Texture/Enemy/skereton/skereton_walk.png", &g_pTexture[SKERETON_TEX]);

	// スライムの画像

	// 炎の弾の画像
	Load_Texture("Resource/Texture/Player/fire_player/f_player_attack.png", &g_pTexture[PLAYER_FLAME_RIGHT_ATTACK_TEX]);

	// 氷の弾の画像
	Load_Texture("Resource/Texture/Player/ice_player/i_player_ice_magic.png", &g_pTexture[PLAYER_ICE_RIGHT_ATTACK_TEX]);

	// 風の弾の画像
	Load_Texture("Resource/Texture/Player/wind_player/w_player_magic.png", &g_pTexture[PLAYER_WIND_RIGHT_ATTACK_TEX]);
	
	// 炎のギミックの画像

	// 氷のギミックの画像

	// 風のギミックの画像
	Load_Texture("Resource/Texture/Gimmick/tornado.png", &g_pTexture[WINDGIMMICK_TEX]);

	//マップの読み込み
	Load_Map("Resource/file/ElementalWorld.csv");

	// コドラの初期化
	for (int i = 0; i < KODORA_MAX; i++)
	{
		g_kodora[i].drawFlag = true;
		g_kodora[i].hitFlag = false;
		g_kodora[i].posX = 730.f;
		g_kodora[i].posY = 350.f;
	}

	// スケルトンの初期化
	for (int i = 0; i < SKERETON_MAX; i++)
	{
		g_skereton[i].drawFlag = true;
		g_skereton[i].hitFlag = false;
		g_skereton[i].posX = 1000.f;
		g_skereton[i].posY = 350.f;
	}

	// 弾の初期化
	for (int i = 0; i < BULLET_MAX; i++)
	{
		g_bullet[i].drawFlag = false;
		g_bullet[i].initFlag = true;
		g_bullet[i].posX = 0.0f;
		g_bullet[i].posY = 0.0f;
	}

}