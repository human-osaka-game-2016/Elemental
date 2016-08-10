/**
*@file transform_poly.cpp
*@brief 拡大・縮小・回転に関する関数をまとめているcppファイルです.
*基本的には行列を用いた関数を使用する.
*@author 芳我貴之
*@data 2016/06/29
*/
#include <d3dx9math.h>
#include"draw_config.h"
#include"transform_poly.h"



/*
ライブラリ
#pragma comment ( lib, "d3dx9.lib" )
*/


//拡大・縮小関数
void Zoom(CUSTOMVERTEX* vertex, float multiple)
{
	float cx;		//中心座標のx座標を格納する変数
	float cy;		//中心座標のy座標を格納する変数


	//中心座標を求める
	cx = (vertex[2].x - vertex[0].x) / 2.0f + vertex[0].x;
	cy = (vertex[2].y - vertex[0].y) / 2.0f + vertex[0].y;

	//拡大、もしくは縮小をする
	for (int i = 0; i < 4; i++)
	{
		float fx = 0.0f;
		float fy = 0.0f;

		fx = vertex[i].x * multiple + cx;
		fy = vertex[i].y * multiple + cy;

		vertex[i].x = fx;
		vertex[i].y = fy;

	}
}


//回転関数
void Rotation(CUSTOMVERTEX* vertex, int deg)
{
	float cx;		//中心座標のx座標を格納する変数
	float cy;		//中心座標のy座標を格納する変数

	//ラジアンを求める
	float rd = (float)-deg * PI / 180.0f;

	//中心座標を求める
	cx = (vertex[2].x - vertex[0].x) / 2.0f + vertex[0].x;
	cy = (vertex[2].y - vertex[0].y) / 2.0f + vertex[0].y;

	//回転させる
	for (int i = 0; i < 4; i++)
	{
		float fx = 0.0f;		//変形したx座標を一時的に保持するための変数
		float fy = 0.0f;		//変形したy座標を一時的に保持するための変数

		fx = (vertex[i].x - cx) * cos(rd) - (vertex[i].y - cy) * sin(rd) + cx;
		fy = (vertex[i].x - cx) * sin(rd) + (vertex[i].y - cy) * cos(rd) + cy;

		vertex[i].x = fx;
		vertex[i].y = fy;

	}

}


//行列で移動させる関数
void MoveMatrix(CUSTOMVERTEX* vertex, float cx, float cy, float cz)
{
	D3DXMATRIX PosMatrix;
	D3DXMATRIX MoveMatrix;

	//行列の初期化
	D3DXMatrixIdentity(&PosMatrix);
	D3DXMatrixIdentity(&MoveMatrix);

	//移動量設定
	D3DXMatrixTranslation(&MoveMatrix, cx, cy, cz);

	//移動処理
	for (int i = 0; i < 4; i++)
	{
		//現在の頂点座標を格納
		D3DXMatrixTranslation(&PosMatrix, vertex[i].x, vertex[i].y, vertex[i].z);
		//移動
		PosMatrix *= MoveMatrix;
		//結果を返す
		vertex[i].x = PosMatrix._41;
		vertex[i].y = PosMatrix._42;
		vertex[i].z = PosMatrix._43;
	}

}


//行列を使用した拡大・縮小関数
void ZoomMatrix(CUSTOMVERTEX* vertex, float multipleX, float multipleY, float multipleZ)
{
	D3DXMATRIX PosMatrix;		// 頂点行列
	D3DXMATRIX MultipleMatrix;	// 拡大・縮小行列

	float cx = 0;		//中心座標のx座標を格納する変数
	float cy = 0;		//変形したy座標を一時的に保持するための変数

	//画像の中心座標を求める
	cx = (vertex[2].x - vertex[0].x) / 2.0f + vertex[0].x;
	cy = (vertex[2].y - vertex[0].y) / 2.0f + vertex[0].y;

	//原点へ移動させる
	MoveMatrix(vertex, -cx, -cy, 0.0f);

	// 行列の初期化（単位行列生成）
	D3DXMatrixIdentity(&PosMatrix);
	D3DXMatrixIdentity(&MultipleMatrix);



	//x 軸、y 軸、z 軸に沿ってスケーリングする行列を作成する。(拡大・縮小の場合はmultipleZは1)
	D3DXMatrixScaling(&MultipleMatrix, multipleX, multipleY, multipleZ);

	// 拡大・縮小処理
	for (int i = 0; i<4; i++)
	{
		// 現在の頂点座標を格納
		D3DXMatrixTranslation(&PosMatrix, vertex[i].x, vertex[i].y, vertex[i].z);
		// 拡大、または縮小
		PosMatrix *= MultipleMatrix;
		// 結果を戻す
		vertex[i].x = PosMatrix._41;
		vertex[i].y = PosMatrix._42;
		vertex[i].z = PosMatrix._43;
	}

	//元の位置に移動させる
	MoveMatrix(vertex, cx, cy, 0.0f);
}


//行列を使用した回転関数（+だと右回転、-だと左回転)
void RotationMatrix(CUSTOMVERTEX* vertex, int deg, int axis)
{
	float PAD = 3.141592f / 180.0f; // ラジアンの初期化
	D3DXMATRIX PosMatrix;		// 頂点行列
	D3DXMATRIX RotateMatrix;	// 回転行列

	float cx = 0;		//中心座標のx座標を格納する変数
	float cy = 0;		//変形したy座標を一時的に保持するための変数

	//画像の中心座標を求める
	cx = (vertex[2].x - vertex[0].x) / 2.0f + vertex[0].x;
	cy = (vertex[2].y - vertex[0].y) / 2.0f + vertex[0].y;

	//原点へ移動させる
	MoveMatrix(vertex, -cx, -cy, 0.0f);



	// 行列の初期化（単位行列生成）
	D3DXMatrixIdentity(&PosMatrix);
	D3DXMatrixIdentity(&RotateMatrix);

	// 回転行列にまわす軸と角度を設定
	switch (axis)
	{
	case X_AXIS:
		D3DXMatrixRotationX(&RotateMatrix, (float)deg * PAD);
		break;

	case Y_AXIS:
		D3DXMatrixRotationY(&RotateMatrix, (float)deg * PAD);
		break;

	case Z_AXIS:
		D3DXMatrixRotationZ(&RotateMatrix, (float)deg * PAD);
		break;
	}
	

	// 回転処理
	for (int i = 0; i<4; i++)
	{
		// 現在の頂点座標を格納
		D3DXMatrixTranslation(&PosMatrix, vertex[i].x, vertex[i].y, vertex[i].z);
		// 回転
		PosMatrix *= RotateMatrix;
		// 結果を戻す
		vertex[i].x = PosMatrix._41;
		vertex[i].y = PosMatrix._42;
		vertex[i].z = PosMatrix._43;
	}

	//元の位置に移動させる
	MoveMatrix(vertex, cx, cy, 0.0f);

}

