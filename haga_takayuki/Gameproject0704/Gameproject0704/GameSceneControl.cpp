/**
*@file GameSceneControl.cpp
*@brief �Q�[���̑���⓮���Ɋւ���֐����܂Ƃ߂Ă���cpp.
*/
#include <d3dx9.h>
#include <d3dx9tex.h>
#include <dinput.h>
#include"config.h"
#include"key_operation.h"
#include"Main.h"
#include"GameSceneInit.h"
#include"GameSceneDraw.h"
#include"GameSceneControl.h"
#include"GameScore.h"
#include"GamePlayerControl.h"
#include"GameEnemyControl.h"


//�f�o�b�N�@�\
//#define USE_DEBUG


void GameControl(PLAYERSTATE* playerState, BULLETSTATE* playerBulletState, ENEMYSTATE* enemyState, BULLETSTATE* enemyBulletState, SCORESTATE* hiscore
	, BACKGROUNDSTATE*	backgroundState, FLAGSTATE* flags)
{
	g_pkeyDevice->GetDeviceState(sizeof(diks), &diks);
	//�L�[����`�F�b�N
	KeyCheck(diks[DIK_LEFT], LEFT);
	KeyCheck(diks[DIK_RIGHT], RIGHT);
	KeyCheck(diks[DIK_UP], UP);
	KeyCheck(diks[DIK_DOWN], DOWN);
	KeyCheck(diks[DIK_Z], Z);

#ifdef USE_DEBUG
#define USE_DEBUG
	//�f�o�b�N�p����
	GameDbug(playerState,hiscore,gameEnd);
#endif
	if (flags->titleScene)
	{
		if (flags->loadScore)
		{
			//�t�@�C����ǂݍ���
			LoadScore(hiscore,flags);
		}
		//�^�C�g��
		TitleSceneControl(flags, playerState, enemyState, playerBulletState, enemyBulletState);
	}
	else
	{
		//�G�̓���
		EnemyControl(enemyState, playerBulletState,playerState,flags);
		//�G�̒e�̓���
		EnemyBulletControl(enemyBulletState,enemyState);
		
		//�v���C���[�̓���
		PlayerControl(playerState, enemyState, enemyBulletState, flags);
		//�v���C���[�e�̓���
		PlayerBulletControl(playerBulletState, playerState);
		
		//�w�i�̓���
		BgControl(backgroundState);
	
		if (playerState->SCORE >= HI_SCORE_MAX)
		{
			//�X�R�A�̏��������
			playerState->SCORE = HI_SCORE_MAX;
			flags->gameComplete = true;
		}
	}
	if (flags->saveScore)
	{
		//�����L���O�`�F�b�N
		ScoreRankingCheck(hiscore,playerState);
		//�X�R�A���L�^����
		SaveScore(hiscore);
		flags->gameEnd = false;
		flags->titleScene = true;
		flags->saveScore = false;
		flags->gameComplete = false;
	}

	
}


//�w�i�̓���
void BgControl(BACKGROUNDSTATE*	backgroundState)
{
	//�w�i�̓������x
	backgroundState[BG_ONE].posY += BG_MOVESPEED;
	backgroundState[BG_TWO].posY += BG_MOVESPEED;

	//��ʂ̉��܂ł��������փV�t�g����
	if (backgroundState[BG_ONE].posY >= 640.f)
	{
		backgroundState[BG_ONE].posY = -640.f;
	}

	if (backgroundState[BG_TWO].posY >= 640.f)
	{
		backgroundState[BG_TWO].posY = -640.f;
	}
}

//�^�C�g���R���g���[��
void TitleSceneControl(FLAGSTATE* flags, PLAYERSTATE* playerState, ENEMYSTATE* enemyState, BULLETSTATE* playerBulletState, BULLETSTATE* enemyBulletState)
{
	
	//�w�i�E�v���C���[�E�G�E�e�̈ʒu��t���O�Ȃǂ�������
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


	//�^�C�g������Q�[���ֈڍs
	if (Key[Z] == PUSH || Key[Z] == ON)
	{
		flags->titleScene = false;
	}
}


//�Q�[���f�o�b�N�p�֐��@
void GameDbug(PLAYERSTATE* playerState, SCORESTATE* hiscore,bool* gameEnd)
{

	//�v���C���[�c�@��
	KeyCheck(diks[DIK_Q], Q);
	if (Key[Q] == PUSH)
	{
		playerState->LIFE = PLAYER_LIFE_DEFU;
	}

	//�����L���O�X�R�A������
	KeyCheck(diks[DIK_D], D);
	if (Key[D] == PUSH)
	{
		
		for (int i = 0; i < RANKING_SCORE_MAX; i++)
		{
			hiscore[i].score = 0;
		}
	}

	//�X�R�A���Z
	KeyCheck(diks[DIK_P], P);
	if (Key[P] == PUSH)
	{
		playerState->SCORE = HI_SCORE_MAX;
	}

	//�v���C���[�X�R�A������
	KeyCheck(diks[DIK_U], U);
	if (Key[U] == PUSH)
	{
		playerState->SCORE = 0;
	}


	//�����I���{�^��
	KeyCheck(diks[DIK_E], E);
	if (Key[E] == PUSH)
	{
		*gameEnd = true;
	}
}