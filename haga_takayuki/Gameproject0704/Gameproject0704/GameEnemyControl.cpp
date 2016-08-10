/**
*@file GameEnemyControl.cpp
*@brief �Q�[���ɂ�����G�̑���A�y�ѓG�̒e�̊֐����܂Ƃ߂��t�@�C���ł�.
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


//�G�̃R���g���[���֐�
void EnemyControl(ENEMYSTATE* enemyState, BULLETSTATE* playerBulletState, PLAYERSTATE* playerState, FLAGSTATE* flags)
{
	//�G�̓����Ɠ�����͈͎w�菈��
	for (int i = 0; i < ENEMYMAX; i++)
	{
			if (enemyState[i].moveDown && enemyState[i].animeExplosion == false)
			{
				if ((enemyState[i].posY + (TEXSIZE / 2)) >= 0)
				{
					enemyState[i].drawFlag = true;
				}

				enemyState[i].posY += ENEMY_DOWN_MOVESPEED;

				if (enemyState[i].posY == ENEMY_Y_DEFU + (ENEMY_POS_Y * i))
				{
					enemyState[i].moveDown = false;
				}

			}
			else if (enemyState[i].drawFlag)
			{
				if (enemyState[i].moveRight)
				{
					enemyState[i].posX += ENEMY_MOVESPEED;
				}
				else
				{
					enemyState[i].posX -= ENEMY_MOVESPEED;
				}

				if (enemyState[i].posX < (BG_X_LEFT_LIMIT + TEXSIZE / 2.0))
				{
					enemyState[i].moveRight = true;
				}
				else if (enemyState[i].posX >(BG_X_RIGHT_LIMIT - TEXSIZE / 2.0f))
				{
					enemyState[i].moveRight = false;
				}
			}
	}

	for (int i = 0; i < ENEMYMAX; i++)
	{

		//�����蔻��	
		for (int j = 0; j < BULLETMAX; j++)
		{
			for (int k = 0; k < 4; k++)
			{
				/*��`�œ����蔻����Ƃ�
				if ((enemyState[i].posY - (TEXSIZE / 2)  ) <= ((playerBulletState[j].bullet[k].y - (TEXSIZE / 2)) + TEXSIZE)
				&& (playerBulletState[j].bullet[k].y - (TEXSIZE / 2)) <= ((enemyState[i].posY - (TEXSIZE / 2)) + TEXSIZE)
				&& (enemyState[i].posX - (TEXSIZE / 2)) <= ((playerBulletState[j].bullet[k].x - (TEXSIZE / 2) ) + TEXSIZE)
				&& (playerBulletState[j].bullet[k].x - (TEXSIZE  / 2)) <= ((enemyState[i].posX - (TEXSIZE / 2)) + TEXSIZE)
				&& playerBulletState[j].drawFlag == true && enemyState[i].drawFlag == true)*/
				if (((abs(enemyState[i].posY - playerBulletState[j].bullet[k].y)) < (TEXSIZE / 2))
					&& ((abs(enemyState[i].posX - playerBulletState[j].bullet[k].x)) < (TEXSIZE / 2))
					&& playerBulletState[j].drawFlag == true && enemyState[i].drawFlag == true)

				{
					//�Q�[�����N���A���Ă��Ȃ��Ȃ�X�R�A�����Z����
					if (!(flags->gameComplete))
					{
						//�v���C���[�ɓ��_���Z
						playerState->SCORE += enemyState[i].SCORE;
					}
					//�G�̕`�������s
					enemyState[i].drawFlag = false;
					enemyState[i].animeExplosion = true;

					//�v���C���[�̒e�̕`��������āA�ʒu�����ɖ߂�
					playerBulletState[j].drawFlag = false;
					playerBulletState[j].initFlag = true;
					break;
				}
			}
			//�G�������Ă����烋�[�v�𔲂���
			if (enemyState[i].drawFlag == false)
			{
				break;
			}
		}
	}

}

//�G�̒e�̃R���g���[���֐�
void EnemyBulletControl(BULLETSTATE* enemyBulletState, ENEMYSTATE* enemyState)
{

	//�e�̔���
	for (int j = 0; j < ENEMYBULLETMAX; j++)
	{

		if (enemyBulletState[j].drawFlag == false && enemyState[j].drawFlag == true && enemyState[j].moveDown == false)
		{
			enemyBulletState[j].posX = enemyState[j].posX;
			enemyBulletState[j].posY = enemyState[j].posY;
			enemyBulletState[j].drawFlag = true;
			enemyBulletState[j].initFlag = false;

			break;
		}

	}


	//�e�����ł�������
	for (int j = 0; j < ENEMYBULLETMAX; j++)
	{
		if (enemyBulletState[j].drawFlag == true)
		{

			enemyBulletState[j].posY += ENEMY_BULLET_MOVESPEED;

			for (int k = 0; k < 4; k++)
			{
				enemyBulletState[j].bullet[k].y += ENEMY_BULLET_MOVESPEED;
			}
		}
	}


	//��ʂ̒[�܂Ō������������
	for (int j = 0; j < ENEMYBULLETMAX; j++)
	{
		if (enemyBulletState[j].posY >= (BG_Y_DOWN_LIMIT + (TEXSIZE / 2)))
		{
			enemyBulletState[j].initFlag = true;
			enemyBulletState[j].drawFlag = false;

		}
	}



}


