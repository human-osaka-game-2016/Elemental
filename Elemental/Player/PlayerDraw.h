/**
 * @file PlayerDraw.h
 * @breif 主人公の描画ファイル
 
 * 主人公の描画に必要なプロトタイプ宣言を書いている

 */

#ifndef PLAYERDRAW
#define PLAYERDRAW

#include "../GameScene/GameSceneDraw.h"

////////////////////////////////////////////////
// 定義
////////////////////////////////////////////////

#define BULLET_MAX 3	//!< 攻撃できる最大値

////////////////////////////////////////////////
// 使用する関数のプロトタイプ宣言
////////////////////////////////////////////////

/// 主人公の描画関数
/**
 * @return なし
 */
void Player_Draw();

/// 主人公がオーラをまとっている状態の描画関数
/**
 * @param [in] _auraFlag	どのオーラを描画するか
 * @param [in] _texsize		描画する画像のtu値を決める
 * @param [in] _auratex　	どのオーラに画像を割り当てるか
 * @return なし
 */
void Player_Aura_Draw(bool _auraFlag, float _texsize, GAMETEX _auratex);

/// 主人公の出す弾の描画関数
/**
* @return なし
*/
void Player_Bullet_Draw();

#endif