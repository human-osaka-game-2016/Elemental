/**
*@file GamePlayerControl.cpp
*@brief �Q�[���ɂ�����v���C���[�̑���A�y�уv���C���[�̒e�̊֐����܂Ƃ߂��t�@�C���ł�.
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

//�v���C���[�֐�
void PlayerControl(PLAYERSTATE* playerState, ENEMYSTATE* enemyState, BULLETSTATE* enemyBulletState, FLAGSTATE* flags)
{

	//�v���C���[�̕`�悳�ꂽ���玞�Ԃ��J�E���g(���G���Ԃ̈�)
	static int gamePlayeTime = 0;

	//�N���A���Ă���΃v���C���[�̖��G���Ԃ͌p��(�f�o�b�N���̃Q�[���I�[�o�[�����G�d�l)
	if (flags->gameComplete || flags->gameEnd)
	{
		gamePlayeTime = 0;
	}

	if (playerState->drawFlag)
	{
		gamePlayeTime++;
		//�L�[����Ɠ�����͈͎w�菈��
		if (Key[LEFT] == ON)
		{
			if (playerState->posX < (BG_X_LEFT_LIMIT + TEXSIZE / 2.0f))
			{
				playerState->posX += 0;
			}
			else
			{
				playerState->posX -= PLAYER_MOVESPEED;
			}

		}
		if (Key[RIGHT] == ON)
		{
			if (playerState->posX > (BG_X_RIGHT_LIMIT - TEXSIZE / 2.0f))
			{
				playerState->posX += 0;
			}
			else
			{
				playerState->posX += PLAYER_MOVESPEED;
			}
		}
		if (Key[UP] == ON)
		{
			if (playerState->posY < (BG_Y_UP_LIMIT + TEXSIZE / 2.0f))
			{
				playerState->posY += 0;
			}
			else
			{
				playerState->posY -= PLAYER_MOVESPEED;
			}
		}
		if (Key[DOWN] == ON)
		{
			if (playerState->posY > (BG_Y_DOWN_LIMIT - TEXSIZE / 2))
			{
				playerState->posY += 0;
			}
			else
			{
				playerState->posY += PLAYER_MOVESPEED;
			}
		}
	}
	//���G���Ԃ��߂����瓖���蔻�������
	if (gamePlayeTime >= PLAYER_INVINCIBLE_TIME)
	{
		//�G�̓����蔻��	
		for (int i = 0; i < ENEMYMAX; i++)
		{

			if (((abs(enemyState[i].posY - playerState->posY))) < TEXSIZE && ((abs(enemyState[i].posX - playerState->posX))) < TEXSIZE
				&& playerState->drawFlag == true && enemyState[i].drawFlag == true)
			{
				playerState->LIFE -= LIFE_DAMEGE;

				if (playerState->LIFE < 0)
				{
					//�v���C���[�`�悪�����Ĕ����A�j���[�V�����֐ؑ�
					playerState->drawFlag = false;
					playerState->animeExplosion = true;
					gamePlayeTime = 0;
					//�Q�[���I���t���O
					flags->gameEnd = true;
				}
				else
				{
					//�v���C���[�`�悪�����Ĕ����A�j���[�V�����֐ؑ�
					playerState->drawFlag = false;
					playerState->animeExplosion = true;
					gamePlayeTime = 0;
					break;

				}
			}

			//�G�̒e�Ƃ̓����蔻��
			for (int j = 0; j < ENEMYBULLETMAX; j++)
			{
				if (((abs(enemyBulletState[j].posY - playerState->posY))) < (TEXSIZE / 2) && ((abs(enemyBulletState[j].posX - playerState->posX))) < (TEXSIZE / 2)
					&& playerState->drawFlag == true && enemyBulletState[j].drawFlag == true)
				{
					playerState->LIFE -= LIFE_DAMEGE;

					if (playerState->LIFE < 0)
					{
						//�v���C���[�`�悪�����Ĕ����A�j���[�V�����ֈڍs
						playerState->drawFlag = false;
						playerState->animeExplosion = true;
						gamePlayeTime = 0;

						//�G�̒e�������Č��̈ʒu�ɖ߂�
						enemyBulletState[j].initFlag = true;
						enemyBulletState[j].drawFlag = false;


						//�Q�[���I���t���O
						flags->gameEnd = true;
					}
					else
					{
						//�v���C���[�`�悪�����Ĕ����A�j���[�V�����ֈڍs
						playerState->drawFlag = false;
						playerState->animeExplosion = true;
						gamePlayeTime = 0;

						//�G�̒e�������Č��̈ʒu�ɖ߂�
						enemyBulletState[j].initFlag = true;
						enemyBulletState[j].drawFlag = false;




					}
				}
			}

		}
	}

}

//�v���C���[�e�̊֐�
void PlayerBulletControl(BULLETSTATE* playerBulletState,PLAYERSTATE* playerState)
{

	//�v���C���[�e�̎��Ԃ��J�E���g
	static int gameTimeBulletP = 0;
	//�e�̔���
	for (int i = 0; i < BULLETMAX; i++)
	{


		if (Key[Z] == PUSH && playerBulletState[i].drawFlag == false && playerState->drawFlag == true)
		{
			playerBulletState[i].posX = playerState->posX;
			playerBulletState[i].posY = playerState->posY;
			playerBulletState[i].drawFlag = true;
			playerBulletState[i].initFlag = false;
			gameTimeBulletP = 0;
			break;
		}


		if ((gameTimeBulletP % BULLET_INTERVAL) == 0 && Key[Z] == ON && playerBulletState[i].drawFlag == false && playerState->drawFlag == true)
		{
			playerBulletState[i].posX = playerState->posX;
			playerBulletState[i].posY = playerState->posY;
			playerBulletState[i].drawFlag = true;
			playerBulletState[i].initFlag = false;
			break;
		}
	}

	gameTimeBulletP++;

	//�e�����ł�������
	for (int i = 0; i < BULLETMAX; i++)
	{
		if (playerBulletState[i].drawFlag == true)
		{

			playerBulletState[i].posY -= BULLET_MOVESPEED;

			for (int j = 0; j < 4; j++)
			{
				playerBulletState[i].bullet[j].y -= BULLET_MOVESPEED;
			}
		}
	}

	//��ʂ̒[�܂Ō������������
	for (int i = 0; i < BULLETMAX; i++)
	{
		if (playerBulletState[i].posY <= BG_Y_UP_LIMIT)
		{
			playerBulletState[i].initFlag = true;
			playerBulletState[i].drawFlag = false;

		}
	}


}
