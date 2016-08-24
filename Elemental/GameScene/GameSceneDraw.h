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

#define KODORA_MAX 1
#define SKERETON_MAX 1
#define SLIME_MAX 1
#define TIPSIZE 64		//! マップチップのサイズ
#define MAP_HEIGHT 12	//! 描画するマップの縦の最大値
#define MAP_WIDTH 34	//! 描画するマップの横の最大値

#include <Direct_Draw.h>

////////////////////////////////////////////////
// 型
////////////////////////////////////////////////

/// 画像枚数
enum GAMETEX
{
	BACKGROUND_TEX,		//!< 背景画像を割り当てる
	MAP_GROUND_TEX,		//!< マップチップを割り当てる
	PLAYER_TEX,			//!< 主人公の画像を割り当てる
	PLAYER_MOVE_TEX,
	PLAYER_LEFT_TEX,
	PLAYER_LEFT_MOVE_TEX,
	PLAYER_FLAME_TEX,	//!< 焔オーラの主人公の画像を割り当てる
	PLAYER_ICE_TEX,		//!< 凝オーラの主人公の画像を割り当てる
	PLAYER_WIND_TEX,	//!< 風オーラの主人公の画像を割り当てる
	KODORA_TEX,			//!< コドラの画像を割り当てる
//	SKERETON_TEX,
	BULLET_TEX,			//!< 弾の画像を割り当てる
	WINDGIMMICK_TEX,	//!< 風のギミックの画像を割り当てる
	TEX_MAX,			//!< 画像枚数の最大値
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

/// テクスチャの解放関数
/**
 * @return なし
 */
void Tex_Free();

////////////////////////////////////////////////
// extern
////////////////////////////////////////////////

extern float g_ScreenOriginX;					//! 画面の左上のｘ座標
extern float g_ScreenOriginY;					//! 画面の左上のｙ座標
extern int map[MAP_HEIGHT][MAP_WIDTH];			//! csvで読み込んだマップの2次元配列
extern LPDIRECT3DTEXTURE9 g_pTexture[TEX_MAX];	//! DirectXテクスチャ・オブジェクトへのポインタ

#endif