/**
 * @file PlayerCntrol.h
 * @breif 主人公の操作ファイル

 * 主人公の操作に必要な定義・プロトタイプ宣言を書いている

 */

#ifndef PLAYERCONTROL
#define PLAYERCONTROL

////////////////////////////////////////////////
// 定義
////////////////////////////////////////////////

#define WALK_SPEED		4		//!< キャラクターの動くスピード
#define RUN_SPEED		6		//!< キャラクターの走るスピード
#define JUMP_POWER		-16.f	//!< ここまで飛べる値
#define GRAVITY			0.4f	//!< この値ずつ上がったり下がったりする
#define BULLET_SPEED	8		//!< 主人公から出される弾の速度

////////////////////////////////////////////////
//使用する関数のプロトタイプ宣言
////////////////////////////////////////////////

/// 主人公の操作関数
/**
 * @return なし
 */
void Player_Control();
void Player_Flame_Control();
void Player_Ice_Control();
void Player_Wind_Control();
//void Player_aura_Control(KEYKIND _st, bool _auraflag);
void Player_Bullet_Control();

#endif