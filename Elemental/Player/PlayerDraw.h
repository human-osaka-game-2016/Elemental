/**
 * @file PlayerDraw.h
 * @breif 主人公の描画ファイル
 
 * 主人公の描画に必要なプロトタイプ宣言を書いている

 */

#ifndef PLAYERDRAW
#define PLAYERDRAW

#include <Direct_Draw.h>

////////////////////////////////////////////////
// 定義
////////////////////////////////////////////////

#define BULLET_MAX 3	//!< 攻撃できる最大値
#define BULLET_DISTAMCE 256//!< 弾の距離の上限

////////////////////////////////////////////////
// 使用する関数のプロトタイプ宣言
////////////////////////////////////////////////

/// 主人公がオーラをまとっている状態の描画関数
/**
 * @return なし
 */
void Player_Draw();

/// 主人公の出す弾の描画関数
/**
* @return なし
*/
void Player_Bullet_Draw();

/// 空中にいるときの主人公を描画する
/**
 * @return なし
 */
void Player_Sky_Draw();

/// 主人公の状態に合わせて描画する関数
/**
 * @return なし
 */
void Player_Case_Draw(CUSTOMVERTEX playerdraw[]);

/// 空中にいるときの状態に合わせて描画する関数
/*
 
 */
void Player_Sky_Case_Draw(CUSTOMVERTEX playerskydraw[]);

void Player_Init();

#endif