/**
 * @file GameSceneInit.h
 * @breif 初期化ファイル

 * 初期化に必要な型・プロトタイプ宣言・externなどを書いている

 */

#include <Direct_Draw.h>
#include "../Player/PlayerDraw.h"

////////////////////////////////////////////////
// 型
////////////////////////////////////////////////

/// 主人公の様々な情報を持つ構造体
typedef struct
{
	float posX;				//!< 主人公のX座標
	float posY;				//!< 主人公のY座標
	float acceleration;		//!< ジャンプするときの加速度
	bool drawFlag;			//!< 描画されるかどうかのフラグ
	bool moveFlag;			//!< 動いたかどうかのフラグ
	bool leftFlag;			//!< 左を向いたかどうかのフラグ
	bool skyFlag;			//!< 空中にいるかどうかのフラグ
	bool jumpFlag;			//!< ジャンプするかどうかのフラグ
	bool rightdashFlag;		//!< 右にダッシュするかどうかのフラグ
	bool leftdashFlag;		//!< 左にダッシュするかどうかのフラグ
	bool hitFlag;			//!< 何かに当てた又は、何かに当たったどうかのフラグ
	bool flamedrawFlag;		//!< 焔のオーラの主人公を描画するかどうかのフラグ
	bool icedrawFlag;		//!< 凍のオーラの主人公を描画するかどうかのフラグ
	bool winddrawFlag;		//!< 疾風(風)のオーラの主人公を描画するかどうかのフラグ

}PLAYER_STATE;

/// 敵の様々な情報を持つ構造体
typedef struct
{
	float posX;		//!< 敵のX座標
	float posY;		//!< 敵のY座標
	bool drawFlag;	//!< 描画されたかどうかのフラグ
	bool hitFlag;	//!< 何かが当たったかどうかのフラグ

}ENEMY_STATE;

typedef struct
{
	CUSTOMVERTEX bullet[4];		//!< 入れたほうが処理が楽になるため
	float posX;					//!< 弾のX座標
	float posY;					//!< 弾のY座標
	bool initFlag;				//!< 弾の初期化のフラグ
	bool drawFlag;				//!< 弾の描画のフラグ

}BULLET_STATE;

/// 初期化の関数
/**
 * @return なし
 */
void Init();

////////////////////////////////////////////////
// extern
////////////////////////////////////////////////

extern ENEMY_STATE g_kodora[KODORA_MAX];	//!< 敵の様々な情報を持つ構造体
extern PLAYER_STATE g_player;				//!< 主人公の様々な情報を持つ構造体
extern BULLET_STATE g_bullet[BULLET_MAX];	//!< 弾の様々な情報を持つ構造体の配列