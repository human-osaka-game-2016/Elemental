/**
*@file transform_poly.h
*@brief 拡大・縮小・回転に関する関数をまとめているcppのヘッダーファイルです.
*基本的には行列を用いた関数を使用する.
*@author 芳我貴之
*@data 2016/06/29
*/
#ifndef TRANSFORM_POLY_H
#define TRANSFORM_POLY_H
#include  <d3dx9math.h>
#include"draw_config.h"

/**
*円周率<br>
*ラジアンを求めるのに必要とする為<br>
*@sa	Rotation(CUSTOMVERTEX* texture, int deg)
*@sa	RotationMatrix(CUSTOMVERTEX* texture, int deg, int axis)	
*/
#define PI  3.141592f

/**
*回転において中心にする軸を3つ列挙<br>
*参照関数の引数にて使用<br>
*@sa RotationMatrix(CUSTOMVERTEX* texture, int deg, int axis)
*/
enum AXIS
{
	X_AXIS,		/**<x軸*/
	Y_AXIS,		/**<y軸*/
	Z_AXIS		/**<z軸*/
};


/**
*ポリゴンの拡大と縮小を行う関数<br>
*拡大、及び縮小をしたい倍率を指定して行う<br>
*例:2倍拡大したいなら2、2分の1に縮小したいなら0.5をわたす.<br>
*@param[out] vertex		･処理を行いたいカスタムバーテックス型の構造体
*@param[in] multiple	･倍率
*/
void Zoom(CUSTOMVERTEX* vertex, float multiple);

/**
*ポリゴンの回転を行う関数<br>
*回転したい角度を指定する<br>
*角度が+値だと左回転、-値だと右回転を行う.<br>
*@param[out] vertex		･処理を行いたいカスタムバーテックス型の構造体
*@param[in] deg		･回転したい角度
*/
void Rotation(CUSTOMVERTEX* vertex, int deg);

/**
*ポリゴンを行列で移動させる関数<br>
*行列を使用してポリゴンを任意の位置へ移動させる.<br>
*@param[out] vertex		･処理を行いたいカスタムバーテックス型の構造体
*@param[in] cx		･この関数の引数であるカスタムバーテックス型の構造体の中心のx座標
*@param[in]	cy		･この関数の引数であるカスタムバーテックス型の構造体の中心のy座標
*@param[in]	cz		･この関数の引数であるカスタムバーテックス型の構造体の中心のz座標
*/
void MoveMatrix(CUSTOMVERTEX* vertex, float cx, float cy, float cz);

/**
*行列を使用して拡大・縮小を行う関数<br>
*x,y,zそれぞれ拡大、及び縮小をしたい倍率を指定して行う.<br>
*@note 二次元で処理を行う場合は基本zの倍率は1
*@param[out] vertex		･処理を行いたいカスタムバーテックス型の構造体
*@param[in] multipleX	･x座標に処理する倍率
*@param[in] multipleY	･y座標に処理する倍率
*@param[in] multipleZ	･z座標に処理する倍率
*/
void ZoomMatrix(CUSTOMVERTEX* vertex, float multipleX, float multipleY, float multipleZ);

/**
*行列を使用して回転を行う関数<br>
*回転したい軸と角度を指定する<br>
*角度が+値だと右回転、-値だと左回転を行う.<br>
*@attention 下記の回転関数とは+,-での回転が逆なので注意
*@sa Rotation(CUSTOMVERTEX* vertex, int deg)
*@param[out] vertex		･処理を行いたいカスタムバーテックス型の構造体
*@param[in]	deg		･回転したい角度
*@param[in]	axis	･回転の中心にしたい軸
*/
void RotationMatrix(CUSTOMVERTEX* vertex, int deg, int axis);

#endif