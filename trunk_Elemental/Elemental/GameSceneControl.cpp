/**
 * @file GameSceneCntrol.cpp
 * @breif ゲーム全体の操作に関係する処理の内容を書いている
 * @author 柴田哲良、山本倫太郎、岸本大河、水瀧秀明、田中貴大、竹村翔平、飯田純矢
 * @date 2016年X月Y日
 */

#define DIRECTINPUT_VERSION 0x0800

#include <dinput.h>
#include <Direct_Draw.h>
#include <Direct_Key_Input.h>
#include "GameSceneDraw.h"
#include "GameSceneControl.h"
#include "PlayerControl.h"
#include "EnemyControl.h"

void Control()
{
	Get_Key_State();

	Check_Key(DIK_LEFT, LEFT);
	Check_Key(DIK_RIGHT, RIGHT);
	Check_Key(DIK_UP, UP);
	Check_Key(DIK_DOWN, DOWN);
	Check_Key(DIK_Z, Z);

	Player_Control();
	Kodora_Control();


}

bool Map_Collision_Check(float _x, float _y, int _sx, int _sy)
{
	bool ret = false;		//　マップチップにあたっていなかったらfalse
	int ix, iy;			

	if ((int)_x % TIPSIZE != 0)
	{
		_sx++;
	}

	if ((int)_y % TIPSIZE != 0)
	{
		_sy++;
	}

	ix = (int)_x / TIPSIZE;			//　現在のX軸の場所
	iy = (int)_y / TIPSIZE;			//　現在のY軸の場所

	for (int i = 0; i < _sx; i++)
	{
		for (int j = 0; j < _sy; j++)
		{
			if (map[iy + j][ix + i] == 1)
			{
				ret = true;		//　マップチップにあたっていたらtrue
				break;			//　当たっているとわかったからこれ以上の処理をする必要はない
			}
		}
	}

	return ret;		//　真(当たってる)か偽(当たってない)の値を返している
}

