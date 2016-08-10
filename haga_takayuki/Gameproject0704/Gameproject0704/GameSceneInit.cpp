/**
*@file GameSceneInit.cpp
*@brief �Q�[���V�[���ɂ����鏉�����֐����܂Ƃ߂��t�@�C���ł�.
*/
#include <d3dx9.h>
#include <d3dx9tex.h>
#include <dinput.h>
#include"config.h"
#include"key_operation.h"
#include"Main.h"
#include"GameSceneInit.h"
#include"GameSceneControl.h"

//-----------------------------------------------------------------------------------------------------------
//
//�`��ݒ�Ɖ摜�ǂݍ��݂Ə�����
//
//------------------------------------------------------------------------------------------------------------

void InitGameScene(PLAYERSTATE* playerState, BULLETSTATE* playerBulletState, ENEMYSTATE* enemyState, BULLETSTATE* enemyBulletState,  BACKGROUNDSTATE*  backgroundState, SCORESTATE* hiscore, FLAGSTATE* flags)
{
	//�`��ݒ�
	RenderState(g_pDirect3DDevice);

	//�摜�ǂݍ���
	LoadPicture(g_pDirect3DDevice, "background01.jpg", &g_pGameTexture[BACKGROUND_TEX]);		//�w�i�摜
	LoadPicture_Ex(g_pDirect3DDevice, "bullet32.png", &g_pGameTexture[BULLET_TEX]);				//�v���C���[�̒e�摜
	LoadPicture_Ex(g_pDirect3DDevice, "player32.png", &g_pGameTexture[PLAYER_TEX]);				//�v���C���[�摜
	LoadPicture_Ex(g_pDirect3DDevice, "enemy32.png", &g_pGameTexture[ENEMY_TEX]);				//�G�摜
	LoadPicture_Ex(g_pDirect3DDevice, "Effect.dds", &g_pGameTexture[EXPLOSION_TEX]);			//�����摜
	LoadPicture(g_pDirect3DDevice, "title.png", &g_pGameTexture[TITLE_TEX]);					//�^�C�g���摜
	LoadPicture_Ex(g_pDirect3DDevice, "text.png", &g_pGameTexture[TEXT01_TEX]);					//����(�����E�Q�[���I�[�o�[)
	LoadPicture_Ex(g_pDirect3DDevice, "enemybullet.png", &g_pGameTexture[BULLET_ENEMY_TEX]);	//�G�̒e�摜
	LoadPicture_Ex(g_pDirect3DDevice, "number.png", &g_pGameTexture[SCORE_TEX]);				//�X�R�A�\������
	LoadPicture_Ex(g_pDirect3DDevice, "text02.png", &g_pGameTexture[TEXT02_TEX]);				//����(�Q�[���N���A�E�x��)

	//������
	//�v���C���[�̏�����
	*playerState = { PLAYER_LIFE_DEFU, PLAYER_SCORE_DEFU, PLAYER_X_DEFU, PLAYER_Y_DEFU, false, true, false };

	//�G�̏�����
	for (int i = 0; i < ENEMYMAX; i++)
	{
		enemyState[i].SCORE = ENEMY_SCORE_DEFU;
		enemyState[i].posX = ENEMY_X_DEFU + (ENEMY_POS_X * i);
		enemyState[i].posY = 0 - (ENEMY_POS_Y * i);
		enemyState[i].drawFlag = true;
		enemyState[i].animeExplosion = false;
		enemyState[i].moveRight = false;
		enemyState[i].moveDown = true;
	}

	//�v���C���[�e�̏�����
	for (int i = 0; i < BULLETMAX; i++)
	{
		playerBulletState[i].posX = 0.0f;
		playerBulletState[i].posY = 0.0f;
		playerBulletState[i].initFlag = true;
		playerBulletState[i].drawFlag = false;
	}

	//�G�̒e�̏�����
	for (int i = 0; i < ENEMYBULLETMAX; i++)
	{
		enemyBulletState[i].posX = 0.0f;
		enemyBulletState[i].posY = 0.0f;
		enemyBulletState[i].initFlag = true;
		enemyBulletState[i].drawFlag = false;
	}
	

	//�w�i������
	backgroundState[BG_ONE] = { BACKGROUND_X_DEFU, 0.0f };	
	backgroundState[BG_TWO] = { BACKGROUND_X_DEFU, -BACKGROUND_Y_DEFU };

	//�����L���O�X�R�A������
	for (int i = 0; i < RANKING_SCORE_MAX; i++)
	{
		hiscore[i].score = 0;
	}
	
	//�t���O�\���̏�����
	*flags = { true, false, true, false, false };

}


