/**
 * @file GameSceneCntrol.h
 * @breif ゲーム全体の操作に関係する定義・プロトタイプ宣言を書いている
 * @author 柴田哲良、山本倫太郎、岸本大河、水瀧秀明、田中貴大、竹村翔平、飯田純矢
 * @date 2016年X月Y日
 */

////////////////////////////////////////////////
// 定義
////////////////////////////////////////////////

/// キャラクター移動速度
#define MOVE_SPEED 4

////////////////////////////////////////////////
// 使用する関数のプロトタイプ宣言
////////////////////////////////////////////////

/// 60fpsでループさせる操作関数
/**
 * @return なし
 */
void Control();

/// マップの当たり判定の関数
/**
 * @param [in] _x x座標
 * @param [in] _y y座標
 * @param [in] _sx 描画するキャラのX軸のチップの数
 * @param [in] _sy 描画するキャラのY軸のチップの数
 * @retval true 
 * @retval false 
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
 * @retval true
 * @retval false
 */
bool Collision_Check(float _rectAX, float _rectBX, float _rectAY, float _rectBY, int _size);

