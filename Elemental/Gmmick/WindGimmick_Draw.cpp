/**
 * @file WindGmmick.cpp
 * @breif ���M�~�b�N�̃t�@�C��

 * ���M�~�b�N�̕K�v�ȏ����������Ă���

 */

#include <Direct_Draw.h>
#include "../GameScene/GameSceneInit.h"
#include "WindGimmick_Draw.h"
#include "WindGimmick_Control.h"

void WindGimmick_Draw()
{
	CUSTOMVERTEX windgimmick[4] =
	{
		{ 0.0f, 0.0f, 0.5f, 1.0f, 0xFFFFFFFF, 0.0f, 0.0f },
		{ 512.f, 0.0f, 0.5f, 1.0f, 0xFFFFFFFF, 0.25f, 0.0f },
		{ 512.f, 512.f, 0.5f, 1.0f, 0xFFFFFFFF, 0.25f, 0.25f },
		{ 0.0f, 512.f, 0.5f, 1.0f, 0xFFFFFFFF, 0.0f, 0.25f },
	};

	if (g_enemy.hitFlag == true)
	{

	}
}