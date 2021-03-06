/**
 * @file GameSceneDraw.h
 * @breif 描画の基盤になるファイル

 * ゲーム全体の描画に必要な定義・型・プロトタイプ宣言・externを書いている 

 */

#ifndef GAMESCENEDRAW
#define GAMESCENEDRAW

////////////////////////////////////////////////
// 定義
////////////////////////////////////////////////

#define NORMAL_BLOCK 1
#define FLAME_BLOCK 2
#define WIND_BLOCK 3
#define WIND_POS_BLOCK 4
#define TREASURE_BOX 6
#define ICESIZE 128		//! 氷のサイズ
#define ICESIZE2 192
#define ICESIZE3 256
#define TIPSIZE 64		//! マップチップのサイズ
#define MAP_HEIGHT 22	//! 描画するマップの縦の最大値
#define MAP_WIDTH 100	//! 描画するマップの横の最大値

#include <Direct_Draw.h>

////////////////////////////////////////////////
// 型
////////////////////////////////////////////////

/// 画像枚数
enum GAMETEX
{
	BACKGROUND_TEX,					//!< 背景画像を割り当てる

	MAP_BLOCK_TEX,					//!< マップチップを割り当てる
	FLAME_BLOCK_TEX,
	WIND_BLOCK_TEX,
	WIND_POS_BLOCK_TEX,

	PLAYER_RIGHT_TEX,						//!< 主人公の画像を割り当てる
	PLAYER_RIGHT_MOVE_TEX,				//!< 主人公が移動したときの画像を割り当てる
	PLAYER_RIGHT_JUMP_TEX,
	PLAYER_RIGHT_FALL_TEX,
	PLAYER_LEFT_TEX,				//!< 主人公が左を向いたときの画像を割り当てる
	PLAYER_LEFT_MOVE_TEX,			//!< 主人公が左向きで移動したときの画像を割り当てる
	PLAYER_LEFT_JUMP_TEX,
	PLAYER_LEFT_FALL_TEX,

	PLAYER_FLAME_RIGHT_TEX,				//!< 焔オーラの主人公の画像を割り当てる
	PLAYER_FLAME_RIGHT_MOVE_TEX,			//!< 炎オーラの主人公が移動している画像を割り当てる
	PLAYER_FLAME_RIGHT_JUMP_TEX,
	PLAYER_FLAME_RIGHT_FALL_TEX,
	PLAYER_FLAME_RIGHT_ATTACK_TEX,
	PLAYER_FLAME_LEFT_TEX,			//!< 炎オーラの主人公が左を向いたときの画像を割り当てる
	PLAYER_FLAME_LEFT_MOVE_TEX,		//!< 炎オーラの主人公が左を向きで移動したときの画像を割り当てる
	PLAYER_FLAME_LEFT_JUMP_TEX,
	PLAYER_FLAME_LEFT_FALL_TEX,
	PLAYER_FLAME_LEFT_ATTACK_TEX,

	PLAYER_ICE_RIGHT_TEX,					//!< 凝オーラの主人公の画像を割り当てる
	PLAYER_ICE_RIGHT_MOVE_TEX,			//!< 氷オーラの主人公が移動している画像を割り当てる
	PLAYER_ICE_RIGHT_JUMP_TEX,
	PLAYER_ICE_RIGHT_FALL_TEX,
	PLAYER_ICE_LEFT_TEX,			//!< 氷オーラの主人公が左を向いたときの画像を割り当てる
	PLAYER_ICE_LEFT_MOVE_TEX,		//!< 氷オーラの主人公が左を向きで移動したときの画像を割り当てる
	PLAYER_ICE_LEFT_JUMP_TEX,
	PLAYER_ICE_LEFT_FALL_TEX,

	PLAYER_WIND_RIGHT_TEX,				//!< 風オーラの主人公の画像を割り当てる
	PLAYER_WIND_RIGHT_MOVE_TEX,			//!< 風オーラの主人公が移動している画像を割り当てる
	PLAYER_WIND_RIGHT_JUMP_TEX,
	PLAYER_WIND_RIGHT_FALL_TEX,
	PLAYER_WIND_LEFT_TEX,			//!< 風オーラの主人公が左を向いたときの画像を割り当てる
	PLAYER_WIND_LEFT_MOVE_TEX,		//!< 風オーラの主人公が左を向きで移動したときの画像を割り当てる
	PLAYER_WIND_LEFT_JUMP_TEX,
	PLAYER_WIND_LEFT_FALL_TEX,

	KODORA_FLAME_RIGHT_STATE_TEX,	//!< 焔コドラの右に待機モーションしている画像を割り当てている
	KODORA_FLAME_RIGHT_MOVE_TEX,	//!< 焔コドラの右に移動している画像を割り当てている
	KODORA_FLAME_LEFT_STATE_TEX,	//!< 焔コドラの待機モーションしている画像を割り当てている
	KODORA_FLAME_LEFT_MOVE_TEX,		//!< 焔コドラの移動している画像を割り当てている

	KODORA_ICE_RIGHT_STATE_TEX,		//!< 氷コドラの右に待機モーションしている画像を割り当てている
	KODORA_ICE_RIGHT_MOVE_TEX,		//!< 氷コドラの右に移動している画像を割り当てている
	KODORA_ICE_LEFT_STATE_TEX,		//!< 氷コドラの待機モーションしている画像を割り当てている
	KODORA_ICE_LEFT_MOVE_TEX,		//!< 氷コドラの移動している画像を割り当てている

	KODORA_WIND_RIGHT_STATE_TEX,	//!< 風コドラの右に待機モーションしている画像を割り当てている
	KODORA_WIND_RIGHT_MOVE_TEX,		//!< 風コドラの右に移動している画像を割り当てている
	KODORA_WIND_LEFT_STATE_TEX,		//!< 風コドラの待機モーションしている画像を割り当てている
	KODORA_WIND_LEFT_MOVE_TEX,		//!< 風コドラの移動している画像を割り当てている

	SLIME_FLAME_RIGHT_STATE_TEX,	//!< 焔スライムの右に待機モーションしている画像を割り当てている
	SLIME_FLAME_RIGHT_MOVE_TEX,		//!< 焔スライムの右に移動している画像を割り当てている
	SLIME_FLAME_LEFT_STATE_TEX,		//!< 焔スライムの待機モーションしている画像を割り当てている
	SLIME_FLAME_LEFT_MOVE_TEX,		//!< 焔スライムの移動している画像を割り当てている

	SLIME_ICE_RIGHT_STATE_TEX,		//!< 氷スライムの右に待機モーションしている画像を割り当てている
	SLIME_ICE_RIGHT_MOVE_TEX,		//!< 氷スライムの右に移動している画像を割り当てている
	SLIME_ICE_LEFT_STATE_TEX,		//!< 氷スライムの待機モーションしている画像を割り当てている
	SLIME_ICE_LEFT_MOVE_TEX,		//!< 氷スライムの移動している画像を割り当てている

	SLIME_WIND_RIGHT_STATE_TEX,		//!< 風スライムの右に待機モーションしている画像を割り当てている
	SLIME_WIND_RIGHT_MOVE_TEX,		//!< 風スライムの右に移動している画像を割り当てている
	SLIME_WIND_LEFT_STATE_TEX,		//!< 風スライムの待機モーションしている画像を割り当てている
	SLIME_WIND_LEFT_MOVE_TEX,		//!< 風スライムの移動している画像を割り当てている


	PLAYER_FLAME_RIGHT_BULLET_TEX,
	PLAYER_FLAME_LEFT_BULLET_TEX,
	PLAYER_ICE_RIGHT_BULLET_TEX,
	PLAYER_ICE_LEFT_BULLET_TEX,
	PLAYER_WIND_RIGHT_BULLET_TEX,
	PLAYER_WIND_LEFT_BULLET_TEX,

	FLAMEGIMMICK_TEX,
	WINDGIMMICK_TEX,				//!< 風のギミックの画像を割り当てる

	GOAL,

	TEX_MAX,						//!< 画像枚数の最大値
};		

enum AURA
{
	NORMAL,
	FLAME,
	ICE,
	WIND,
};

//キャラの向いてる方向
enum Direction
{
	Right,		//!< 右
	Left,		//!< 左
	Up,
	Down,
};

enum STATE
{
	Wait,		//!< 敵の待機状態
	Move,		//!< 敵の動き
};

////////////////////////////////////////////////
// 使用する関数のプロトタイプ宣言
////////////////////////////////////////////////

/// 60fpsでループさせる描画関数
/**
 * @return なし
 */
void Render();

/// csvで読み込んだマップの描画関数
/**
 * @return なし
 */
void Draw_Map();

/// csvファイルの読み込み関数
/**
 * @param [out] _mapdate 読み込むcsvファイルの名前
 * @return なし
 */
void Load_Map(const char* _mapdata);

/// 描画関数
/**
 * @param [in] 描画したい画像をどこに割り当てるかを書く
 * @param [in] どのCUSTOMVERTEXの情報を描画したいかを書く
 * @return なし
 */
void Draw_Obj(LPDIRECT3DTEXTURE9   _pTexture, CUSTOMVERTEX _setdraw[]);

void Goal_Draw();

/// テクスチャの解放関数
/**
 * @return なし
 */
void Tex_Free();

////////////////////////////////////////////////
// extern
////////////////////////////////////////////////

extern float g_ScreenOriginX;					//!< 画面の左上のｘ座標
extern float g_ScreenOriginY;					//!< 画面の左上のｙ座標
extern int map[MAP_HEIGHT][MAP_WIDTH];			//!< csvで読み込んだマップの2次元配列
extern LPDIRECT3DTEXTURE9 g_pTexture[TEX_MAX];	//!< DirectXテクスチャ・オブジェクトへのポインタ
extern CUSTOMVERTEX g_Maptip[4];

#endif