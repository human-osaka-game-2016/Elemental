/**
 * @file PlayerDraw.h
 * @breif 主人公の描画ファイル
 
 * 主人公の描画に必要なプロトタイプ宣言を書いている

 */

#ifndef PLAYERDRAW
#define PLAYERDRAW

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
void Player_Aura_Draw(bool _auraFlag, float _texsize, GAMETEX _auratex);
void Player_Bullet_Draw();

#endif