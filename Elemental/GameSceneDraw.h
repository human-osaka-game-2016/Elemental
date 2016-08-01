/**
 * @file GameSceneDraw.h
 * @breif ゲーム全体に必要な描画に関係する定義・型・プロトタイプ宣言・externを書いている
 * @author 柴田哲良、山本倫太郎、岸本大河、水瀧秀明、田中貴大、竹村翔平、飯田純矢
 * @date 2016年X月Y日
 */

////////////////////////////////////////////////
// 定義
////////////////////////////////////////////////

#define TIPSIZE 64		///< マップチップのサイズ
#define MAP_HEIGHT 11	///< 描画するマップの縦の最大値
#define MAP_WIDTH 34	///< 描画するマップの横の最大値

#include <Direct_Draw.h>

////////////////////////////////////////////////
// 型
////////////////////////////////////////////////

/// 画像枚数
enum 
{
	BACKGROUND_TEX,
	MAP_GROUND_TEX,
	PLAYER_TEX,
	TEX_MAX,
};

////////////////////////////////////////////////
// 使用する関数のプロトタイプ宣言
////////////////////////////////////////////////

/// 60fpsでループさせる描画関数
/**
 * @return なし
 */
void Render();

/// csvで読み込んだマップの描画
/**
 * @return なし
 */
void Draw_Map();

/// csvファイルの読み込み
/**
 * @param [out] _mapdate 読み込むcsvファイルの名前
 * @return なし
 */
void Load_Map(const char* _mapdata);

/// 
void Draw_Obj(LPDIRECT3DTEXTURE9   _pTexture, CUSTOMVERTEX _setdraw[]);

/// テクスチャの解放関数
/**
 * @return なし
 */
void Tex_Free();

////////////////////////////////////////////////
// extern
////////////////////////////////////////////////
extern float g_ScreenOriginX;					///< 画面の左上のｘ座標
extern float g_ScreenOriginY;					///< 画面の左上のｙ座標
extern int map[MAP_HEIGHT][MAP_WIDTH];			///< csvで読み込んだマップの2次元配列
extern LPDIRECT3DTEXTURE9 g_pTexture[TEX_MAX];
