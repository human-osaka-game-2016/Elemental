/**
 * @file EnemyControl.h
 * @breif 敵の操作ファイル

 * 全ての敵の操作に必要なプロトタイプ宣言を書いている

 */

#ifndef ENEMYCONTROL
#define ENEMYCONTROL

#define ENEMY_WALK 2	//!< 敵の歩くスピード

////////////////////////////////////////////////
//使用する関数のプロトタイプ宣言
////////////////////////////////////////////////

/// コドラの操作関数
/**
 * @return なし
 */
void Kodora_Control();

/// スケルトンの操作関数
/**
 * @return なし
 */
void skeleton_Control();

/// スライムの操作関数
/**
 * @return なし
 */
void Slime_Control();

#endif