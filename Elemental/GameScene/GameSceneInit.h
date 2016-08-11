/**
 * @file GameSceneInit.h
 * @breif 初期化ファイル

 * 初期化に必要な型・プロトタイプ宣言・externなどを書いている

 */

////////////////////////////////////////////////
// 型
////////////////////////////////////////////////

/// 主人公の様々な情報を持つ構造体
typedef struct
{
	float posX;				//!< 主人公のX座標
	float posY;				//!< 主人公のY座標
	float acceleration;		//!< ジャンプするときの加速度
	bool stayFlag;			//!< 主人公が待機している状態
	bool skyFlag;			//!< 空中にいるかどうかのフラグ
	bool jumpFlag;			//!< ジャンプするかどうかのフラグ
	bool drawFlag;			//!< 主人公が描画されるかどうかのフラグ
	bool rightdashflag;		//!< 主人公が右にダッシュするかどうかのフラグ
	bool leftdashFlag;		//!< 主人公が左にダッシュするかどうかのフラグ
	bool hitFlag;			//!< 主人公が何かに当てた又は、何かに当たったどうかのフラグ
}PLAYER_STATE;

/// 敵の様々な情報を持つ構造体
typedef struct
{
	float posX;	//!< 敵のX座標
	float posY; //!< 敵のY座標
}ENEMY_STATE;

/// 初期化の関数
/**
 * @return なし
 */
void Init();

////////////////////////////////////////////////
// extern
////////////////////////////////////////////////

extern ENEMY_STATE g_enemy;		//!< 敵の様々な情報を持つ構造体
extern PLAYER_STATE g_player;   //!< 主人公の様々な情報を持つ構造体