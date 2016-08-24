/**
 * @file GameSceneInit.cpp
 * @breif �������t�@�C��
 
 * �������ɕK�v�ȏ����������Ă���

 */

#include <Direct_Draw.h>
#include "GameSceneDraw.h"
#include "GameSceneInit.h"
#include "../Player/PlayerDraw.h"


PLAYER_STATE g_player = { 150.f, 350.f, 0.f, true, false, false, false, false, false, false, false, false, false };

ENEMY_STATE g_kodora[KODORA_MAX];

BULLET_STATE g_bullet[BULLET_MAX];

void Init()
{
	// �`��̏�����
	Init_Draw();

	//�����t�@�C���̉摜��ǂݍ��ނƂ�Resource/Texture/

	// �摜��ǂݍ��݂ǂ����Ɋ��蓖�ĂĂ���
	Load_Texture("���[���h�`�b�v.png", &g_pTexture[MAP_GROUND_TEX]);
	Load_Texture("Resource/Texture/Background/inside.png", &g_pTexture[BACKGROUND_TEX]);
	Load_Texture("Resource/Texture/Player/normal_player/player_state.png", &g_pTexture[PLAYER_TEX]);
	Load_Texture("Resource/Texture/Player/fire_player/f_player_state.png", &g_pTexture[PLAYER_FLAME_TEX]);
	Load_Texture("Resource/Texture/Player/ice_player/i_player_state.png", &g_pTexture[PLAYER_ICE_TEX]);
	Load_Texture("Resource/Texture/Player/wind_player/w_player_state.png", &g_pTexture[PLAYER_WIND_TEX]);
	Load_Texture("�S�W��.png", &g_pTexture[KODORA_TEX]);
	Load_Texture("Bubble.png", &g_pTexture[BULLET_TEX]);
	Load_Texture("Resource/Texture/Gimmick/tornado.png", &g_pTexture[WINDGIMMICK_TEX]);
	Load_Map("Resource/file/ElementalWorld.csv");

	for (int i = 0; i < KODORA_MAX; i++)
	{
		g_kodora[i].drawFlag = true;
		g_kodora[i].hitFlag = false;
		g_kodora[i].posX = 730.f;
		g_kodora[i].posY = 350.f;
	}

	for (int i = 0; i < BULLET_MAX; i++)
	{
		g_bullet[i].drawFlag = false;
		g_bullet[i].initFlag = true;
		g_bullet[i].posX = 0.0f;
		g_bullet[i].posY = 0.0f;
	}

}