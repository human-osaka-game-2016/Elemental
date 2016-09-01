/**
 * @file GameSceneInit.cpp
 * @breif �������t�@�C��
 
 * �������ɕK�v�ȏ����������Ă���

 */

#include <Direct_Draw.h>
#include "GameSceneDraw.h"
#include "GameSceneInit.h"
#include "../Player/PlayerDraw.h"
#include "../Player/PlayerControl.h"
#include "../Enemy/EnemyControl.h"


PLAYER_STATE g_player = { 0.f, 0.f, 0.f, NORMAL , true, false, false, false, false, false, false, false, false };

ENEMY_STATE g_kodora[KODORA_MAX];

ENEMY_STATE g_skereton[SKERETON_MAX];

ENEMY_STATE g_slime[SLIME_MAX];

BULLET_STATE g_bullet[BULLET_MAX];

GIMMICK_STATE g_gimmick = { false, false };



void Init()
{
	// �`��̏�����
	Init_Draw();

	//�����t�@�C���̉摜��ǂݍ��ނƂ�Resource/Texture/�t�H���_��/�t�H���_��/�t�@�C�����Ə����Ή摜���ǂ݂��܂��悤�ɂȂ�

	// �摜��ǂݍ��݂ǂ����Ɋ��蓖�ĂĂ���

	Load_Texture("Resource/Texture/Background/Background.png", &g_pTexture[BACKGROUND_TEX]);

	Load_Texture("Resource/Texture/Maptip/maptip.png", &g_pTexture[MAP_BLOCK_TEX]);
	Load_Texture("Resource/Texture/Maptip/fire_block.png", &g_pTexture[FLAME_BLOCK_TEX]);
	Load_Texture("Resource/Texture/Maptip/wind_block.png", &g_pTexture[WIND_BLOCK_TEX]);
	Load_Texture("Resource/Texture/UI/wind_position.png", &g_pTexture[WIND_POS_BLOCK_TEX]);

	// �ʏ�̎�l���̉摜
	Load_Texture("Resource/Texture/Player/normal_player/player_state.png", &g_pTexture[PLAYER_RIGHT_TEX]);
	Load_Texture("Resource/Texture/Player/normal_player/player_move.png", &g_pTexture[PLAYER_RIGHT_MOVE_TEX]);
	Load_Texture("Resource/Texture/Player/normal_player/player_jump.png", &g_pTexture[PLAYER_RIGHT_JUMP_TEX]);
	Load_Texture("Resource/Texture/Player/normal_player/player_fall.png", &g_pTexture[PLAYER_RIGHT_FALL_TEX]);
	Load_Texture("Resource/Texture/Player/normal_player_reverse/r_player_state.png", &g_pTexture[PLAYER_LEFT_TEX]);
	Load_Texture("Resource/Texture/Player/normal_player_reverse/r_player_move.png", &g_pTexture[PLAYER_LEFT_MOVE_TEX]);
	Load_Texture("Resource/Texture/Player/normal_player_reverse/r_player_jump.png", &g_pTexture[PLAYER_LEFT_JUMP_TEX]);
	Load_Texture("Resource/Texture/Player/normal_player_reverse/r_player_fall.png", &g_pTexture[PLAYER_LEFT_FALL_TEX]);


	// ���̃I�[�����܂Ƃ�����l���̉摜
	Load_Texture("Resource/Texture/Player/fire_player/f_player_state.png", &g_pTexture[PLAYER_FLAME_RIGHT_TEX]);
	Load_Texture("Resource/Texture/Player/fire_player/f_player_move.png", &g_pTexture[PLAYER_FLAME_RIGHT_MOVE_TEX]);
	Load_Texture("Resource/Texture/Player/fire_player/f_player_jump.png", &g_pTexture[PLAYER_FLAME_RIGHT_JUMP_TEX]);
	Load_Texture("Resource/Texture/Player/fire_player/f_player_fall.png", &g_pTexture[PLAYER_FLAME_RIGHT_FALL_TEX]);
	Load_Texture("Resource/Texture/Player/fire_player/f_player_attack.png", &g_pTexture[PLAYER_FLAME_RIGHT_ATTACK_TEX]);
	Load_Texture("Resource/Texture/Player/fire_player_reverse/r_f_player_state.png", &g_pTexture[PLAYER_FLAME_LEFT_TEX]);
	Load_Texture("Resource/Texture/Player/fire_player_reverse/r_f_player_move.png", &g_pTexture[PLAYER_FLAME_LEFT_MOVE_TEX]);
	Load_Texture("Resource/Texture/Player/fire_player_reverse/r_f_player_jump.png", &g_pTexture[PLAYER_FLAME_LEFT_JUMP_TEX]);
	Load_Texture("Resource/Texture/Player/fire_player_reverse/r_f_player_fall.png", &g_pTexture[PLAYER_FLAME_LEFT_FALL_TEX]);
	Load_Texture("Resource/Texture/Player/fire_player_reverse/r_f_player_attack.png", &g_pTexture[PLAYER_FLAME_LEFT_ATTACK_TEX]);

	// �X�̃I�[�����܂Ƃ�����l���̉摜
	Load_Texture("Resource/Texture/Player/ice_player/i_player_state.png", &g_pTexture[PLAYER_ICE_RIGHT_TEX]);
	Load_Texture("Resource/Texture/Player/ice_player/i_player_move.png", &g_pTexture[PLAYER_ICE_RIGHT_MOVE_TEX]);
	Load_Texture("Resource/Texture/Player/ice_player/i_player_jump.png", &g_pTexture[PLAYER_ICE_RIGHT_JUMP_TEX]);
	Load_Texture("Resource/Texture/Player/ice_player/i_player_fall.png", &g_pTexture[PLAYER_ICE_RIGHT_FALL_TEX]);
	Load_Texture("Resource/Texture/Player/ice_player_reverse/r_i_player_state.png", &g_pTexture[PLAYER_ICE_LEFT_TEX]);
	Load_Texture("Resource/Texture/Player/ice_player_reverse/r_i_player_move.png", &g_pTexture[PLAYER_ICE_LEFT_MOVE_TEX]);
	Load_Texture("Resource/Texture/Player/ice_player_reverse/r_i_player_jump.png", &g_pTexture[PLAYER_ICE_LEFT_JUMP_TEX]);
	Load_Texture("Resource/Texture/Player/ice_player_reverse/r_i_player_fall.png", &g_pTexture[PLAYER_ICE_LEFT_FALL_TEX]);

	// ���̃I�[�����܂Ƃ�����l���̉摜
	Load_Texture("Resource/Texture/Player/wind_player/w_player_state.png", &g_pTexture[PLAYER_WIND_RIGHT_TEX]);
	Load_Texture("Resource/Texture/Player/wind_player/w_player_move.png", &g_pTexture[PLAYER_WIND_RIGHT_MOVE_TEX]);
	Load_Texture("Resource/Texture/Player/wind_player/w_player_jump.png", &g_pTexture[PLAYER_WIND_RIGHT_JUMP_TEX]);
	Load_Texture("Resource/Texture/Player/wind_player/w_player_fall.png", &g_pTexture[PLAYER_WIND_RIGHT_FALL_TEX]);
	Load_Texture("Resource/Texture/Player/wind_player_reverse/r_w_player_state.png", &g_pTexture[PLAYER_WIND_LEFT_TEX]);
	Load_Texture("Resource/Texture/Player/wind_player_reverse/r_w_player_move.png", &g_pTexture[PLAYER_WIND_LEFT_MOVE_TEX]);
	Load_Texture("Resource/Texture/Player/wind_player_reverse/r_w_player_jump.png", &g_pTexture[PLAYER_WIND_LEFT_JUMP_TEX]);
	Load_Texture("Resource/Texture/Player/wind_player_reverse/r_w_player_fall.png", &g_pTexture[PLAYER_WIND_LEFT_FALL_TEX]);

	// �R�h���̉摜
	Load_Texture("Resource/Texture/Enemy/Kodora/flame_kodora/f_kodora_move.png", &g_pTexture[KODORA_FLAME_LEFT_MOVE_TEX]);
	Load_Texture("Resource/Texture/Enemy/Kodora_reverse/flame_kodora/r_f_kodora_move.png", &g_pTexture[KODORA_FLAME_RIGHT_MOVE_TEX]);

	// �X�P���g���̉摜

	// �X���C���̉摜
	Load_Texture("Resource/Texture/Enemy/slime/flame_slime/f_slime_move .png", &g_pTexture[SLIME_FLAME_LEFT_MOVE_TEX]);
	Load_Texture("Resource/Texture/Enemy/slime_reverse/flame_slime_reverse/r_f_slime_move.png", &g_pTexture[SLIME_FLAME_RIGHT_MOVE_TEX]);

	// ���̒e�̉摜
	Load_Texture("Resource/Texture/Player/fire_player/f_player_magic.png", &g_pTexture[PLAYER_FLAME_RIGHT_BULLET_TEX]);
	Load_Texture("Resource/Texture/Player/fire_player_reverse/r_f_player_magic.png", &g_pTexture[PLAYER_FLAME_LEFT_BULLET_TEX]);

	// �X�̒e�̉摜
	Load_Texture("Resource/Texture/Player/ice_player/i_player_magic.png", &g_pTexture[PLAYER_ICE_RIGHT_BULLET_TEX]);
	Load_Texture("Resource/Texture/Player/ice_player_reverse/r_i_player_magic.png", &g_pTexture[PLAYER_ICE_LEFT_BULLET_TEX]);

	// ���̒e�̉摜
	Load_Texture("Resource/Texture/Player/wind_player/w_player_magic.png", &g_pTexture[PLAYER_WIND_RIGHT_BULLET_TEX]);
	Load_Texture("Resource/Texture/Player/wind_player_reverse/r_w_player_magic.png", &g_pTexture[PLAYER_WIND_LEFT_BULLET_TEX]);
	
	// ���̃M�~�b�N�̉摜

	// �X�̃M�~�b�N�̉摜

	// ���̃M�~�b�N�̉摜
	Load_Texture("Resource/Texture/Gimmick/tornado.png", &g_pTexture[WINDGIMMICK_TEX]);

	//�}�b�v�̓ǂݍ���
	Load_Map("Resource/file/ElementalWorld.csv");

	Player_Init();

	// �R�h���̏�����
	for (int i = 0; i < KODORA_MAX; i++)
	{
		g_kodora[i].drawFlag = true;
		g_kodora[i].hitFlag = false;
		g_kodora[i].directionID = Left;
		g_kodora[i].posX = 0.0f;
		g_kodora[i].posY = 0.0f;
	}

	Kodora_Init();

	// �X�P���g���̏�����
	for (int i = 0; i < SKERETON_MAX; i++)
	{
		g_skereton[i].drawFlag = true;
		g_skereton[i].hitFlag = false;
		g_skereton[i].directionID = Left;
		g_skereton[i].posX = 1000.f;
		g_skereton[i].posY = 350.f;
	}

	// �X���C���̏�����
	for (int i = 0; i < SLIME_MAX; i++)
	{
		g_slime[i].drawFlag = true;
		g_slime[i].hitFlag = false;
		g_slime[i].directionID = Left;
		g_slime[i].posX = 1000.0f;
		g_slime[i].posY = 500.0f;
	}

	Slime_Init();

	// �e�̏�����
	for (int i = 0; i < BULLET_MAX; i++)
	{
		g_bullet[i].drawFlag = false;
		g_bullet[i].initFlag = true;
		g_bullet[i].posX = 0.0f;
		g_bullet[i].posY = 0.0f;
	}

}