/**
 * @file GameSceneInit.h
 * @breif 初期化ファイル

 * 初期化に必要な型・プロトタイプ宣言・externなどを書いている

 */

#ifndef GAMESCENEINIT
#define GAMESCENEINIT

#include <Direct_Draw.h>
#include "../GameScene/GameSceneDraw.h"
#include "../Player/PlayerDraw.h"
#include "../Enemy/EnemyDraw.h"

////////////////////////////////////////////////
// 型
////////////////////////////////////////////////

/// 主人公の様々な情報を持つ構造体
typedef struct
{
	float posX;				//!< 主人公のX座標
	float posY;				//!< 主人公のY座標
	float acceleration;		//!< ジャンプするときの加速度
	AURA p_elerent;
	bool drawFlag;			//!< 描画されるかどうかのフラグ
	bool moveFlag;			//!< 動いたかどうかのフラグ
	bool leftFlag;			//!< 左を向いたかどうかのフラグ
	bool skyFlag;			//!< 空中にいるかどうかのフラグ
	bool jumpFlag;			//!< ジャンプするかどうかのフラグ
	bool rightdashFlag;		//!< 右にダッシュするかどうかのフラグ
	bool leftdashFlag;		//!< 左にダッシュするかどうかのフラグ
	bool hitFlag;			//!< 何かに当たったどうかのフラグ

}PLAYER_STATE;

/// 敵の様々な情報を持つ構造体
typedef struct
{
	float posX;		//!< 敵のX座標
	float posY;		//!< 敵のY座標
	bool drawFlag;	//!< 描画されたかどうかのフラグ
	bool hitFlag;	//!< 何かが当たったかどうかのフラグ
	bool deathFlag;
	AURA e_element;
	Direction directionID;	//!< 敵の向いてる方向
	STATE stateID;			//!< 敵の状態


}ENEMY_STATE;

typedef struct
{
	CUSTOMVERTEX bullet[4];		//!< 入れたほうが処理が楽になるため
	float posX;					//!< 弾のX座標
	float posY;					//!< 弾のY座標
	bool initFlag;				//!< 弾の初期化のフラグ
	bool drawFlag;				//!< 弾の描画のフラグ
	bool leftFlag;
	bool animationFlag;

}BULLET_STATE;

typedef struct
{
	bool hitFlag;
	bool drawFlag;
	bool outbreakFlag;	//!< ギミックの発生フラグ
	bool animaFlag;

}GIMMICK_STATE;

/// 初期化の関数
/**
 * @return なし
 */
void Init();

void Image_Display();

void Enemy_Init();

////////////////////////////////////////////////
// extern
////////////////////////////////////////////////

extern PLAYER_STATE g_player;					//!< 主人公の様々な情報を持つ構造体
extern ENEMY_STATE g_kodora[KODORA_MAX];		//!< 敵の様々な情報を持つ構造体
extern ENEMY_STATE g_skeleton[SKERETON_MAX];
extern BULLET_STATE g_bullet[BULLET_MAX];		//!< 弾の様々な情報を持つ構造体の配列
extern ENEMY_STATE g_slime[SLIME_MAX];
extern GIMMICK_STATE g_gimmick;

#endif