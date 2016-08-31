/**
* @file WindGmmick_Cntrol.cpp
* @breif 風ギミックのファイル

* 風ギミックの操作に必要な処理を書いている

*/

#include "../GameScene/GameSceneControl.h"
#include "../GameScene/GameSceneInit.h"
#include "../Player/PlayerControl.h"
#include "WindGimmick_Draw.h"
#include "WindGimmick_Control.h"


void WindGimmick_Control()
{
	if (g_gimmick.hitFlag == true)
	{
		for (int i = 0; i < SLIME_MAX; i++)
		{
			if (g_slime[i].directionID == Left)
			{
				
			}
		}
	}
}