/**
 * @file GameSceneInit.cpp
 * @breif �������t�@�C��
 
 * �������ɕK�v�ȏ����������Ă���

 */

#include <Direct_Draw.h>
#include "GameSceneDraw.h"
#include "GameSceneInit.h"



PLAYER_STATE g_player = { 300.f, 350.f, 0.f, false, false, true, false, false };	

ENEMY_STATE g_enemy = { 1200.f, 320.f };

void Init()
{
	// �`��̏�����
	Init_Draw();

	//�����t�@�C���̉摜��ǂݍ��ނƂ�Resource/Texture/

	// �摜��ǂݍ��݂ǂ����Ɋ��蓖�ĂĂ���
	Load_Texture("���[���h�`�b�v.png", &g_pTexture[MAP_GROUND_TEX]);
	//Load_Texture("", &g_pTexture[BACKGROUND_TEX]);
	Load_Texture("�X�g�����W�搶�ǂ��ƊG.png", &g_pTexture[PLAYER_TEX]);
	Load_Texture("�S�W��.png", &g_pTexture[ENEMY_TEX]);
	Load_Map("Resource/file/ElementalWorld.csv");

}