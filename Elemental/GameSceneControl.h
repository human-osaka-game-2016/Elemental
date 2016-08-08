/**
 * @file GameSceneCntrol.h
 * @breif 操作の基盤になるファイル

 * ゲーム全体の操作に必要な定義・プロトタイプ宣言を書いている

 */

#ifndef GAMESCENE_CONTROL
#define GAMESCENE_CONTROL

////////////////////////////////////////////////
// 定義
////////////////////////////////////////////////

#define MOVE_SPEED 4	//!< キャラクターの動くスピード

////////////////////////////////////////////////
// 使用する関数のプロトタイプ宣言
////////////////////////////////////////////////

/// 60fpsでループさせる操作関数
/**
 * @return なし
 */
void Control();

/// 目のシステムの関数
/**
 * @return なし
 */
void Map_Control();

/// マップの当たり判定の関数
/**
 * @param [in] _x	x座標
 * @param [in] _y	y座標
 * @param [in] _sx	描画するキャラのX軸のチップの数
 * @param [in] _sy	描画するキャラのY軸のチップの数
 * @retval true		周りにチップが存在している
 * @retval false	周りにチップが存在していない
 */
bool Map_Collision_Check(float _x, float _y, int _sx, int _sy);

///　矩形のあたり判定の関数
/**
 * absは絶対値を返す関数である
 * @param [in] _rectAX	1つ目のオブジェクトのX座標
 * @param [in] _rectBX	2つ目のオブジェクトのX座標
 * @param [in] _rectAY	1つ目のオブジェクトのY座標
 * @param [in] _rectBY	2つ目のオブジェクトのY座標
 * @param [in] _size	矩形の中心点から 幅/２ と 高さ/２ をした分のサイズ
 * @retval true			比べたオブジェクトと当たっている
 * @retval false		比べたオブジェクトと当たっていない
 */
bool Collision_Check(float _rectAX, float _rectBX, float _rectAY, float _rectBY, int _size);

#endif