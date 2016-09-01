/**
 * @file GameSceneCntrol.cpp
 * @breif 操作の基盤になるファイル

 * ゲーム全体の操作に必要な処理を書いている

 */

//! dinput.hを使うときはhより上にこれを入れなければならない
#define DIRECTINPUT_VERSION 0x0800	

#include <dinput.h>
#include <Direct_Key_Input.h>
#include "GameSceneDraw.h"
#include "GameSceneControl.h"
#include "GameSceneInit.h"
#include "../Player/PlayerDraw.h"
#include "../Player/PlayerControl.h"
#include "../Enemy/EnemyControl.h"
#include "../Gmmick/WindGimmick_Control.h"

// 操作関数
void Control()
{
	Get_Key_State();

	Check_Key(DIK_LEFT, LEFT);
	Check_Key(DIK_RIGHT, RIGHT);
	Check_Key(DIK_UP, UP);
	Check_Key(DIK_DOWN, DOWN);
	Check_Key(DIK_A, A);
	Check_Key(DIK_Z, Z);
	Check_Key(DIK_X, X);
	Check_Key(DIK_C, C);
	Check_Key(DIK_SPACE, SPACE);

	Player_Control();
	Player_Aura_Control();
	Player_Bullet_Control();

	Kodora_Control();
	skeleton_Control();
	Slime_Control();


	WindGimmick_Control();
	
}

bool Map_Collision_Check(float _x, float _y, int _sx, int _sy)
{
	bool ret = false;		// マップチップにあたっていなかったらfalse
	int ix, iy;			

	if ((int)_x % TIPSIZE != 0)
	{
		_sx++;
	}

	if ((int)_y % TIPSIZE != 0)
	{
		_sy++;
	}

	ix = (int)_x / TIPSIZE;			// 現在のX軸の場所
	iy = (int)_y / TIPSIZE;			// 現在のY軸の場所

	for (int i = 0; i < _sx; i++)
	{
		for (int j = 0; j < _sy; j++)
		{
			if (map[iy + j][ix + i] == 1)
			{
				ret = true;		// マップチップにあたっていたらtrue
				break;			// 当たっているとわかったからこれ以上の処理をする必要はない
			}
			else if (map[iy + j][ix + i] == 2)
			{
				ret = true;		
				break;
			}
			else if (map[iy + j][ix + i] == 3)
			{
				ret = true;
				break;
			}
		}
	}

	return ret;		//　真(当たってる)か偽(当たってない)の値を返している
}

// 矩形の当たり判定の関数
bool Collision_Check(float _rectAX, float _rectBX, float _rectAY, float _rectBY, int _size)
{
	bool hit = false;

	// absは()内の計算の絶対値を返してくれる
	if ((abs(_rectAX - _rectBX) < _size) && (abs(_rectAY - _rectBY) < _size))
	{
		hit = true;
	}

	return hit;
}

//ギミックのあたり判定
bool Gimmick_Collision_Check(float _playerX, float _playerY)
{
	for (int i = 0; i < 4; i++)
	{
		if (g_kodora[i].hitFlag == true)
		{
			if ((abs(_playerX - g_kodora[i].posX)) < ICESIZE && (abs(_playerY - g_kodora[i].posY)) < ICESIZE2)
			{
				return true;
			}
		}

	}
	return false;
}