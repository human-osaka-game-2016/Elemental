/**
*@file GameEnemyDraw.cpp
*@brief �Q�[���ɂ�����G�A�G�̒e�A�y�ѓG�̔����A�j���[�V�����̕`��֐����܂Ƃ߂��t�@�C���ł�.
*/

#include <d3dx9.h>
#include <d3dx9tex.h>
#include"draw_config.h"
#include"Main.h"
#include"GameSceneInit.h"
#include"GameSceneDraw.h"
#include"GameSceneControl.h"

// �G�`��
void EnemyDraw(CUSTOMVERTEX* enemy, ENEMYSTATE* enemyState)
{
	g_pDirect3DDevice->SetTexture(0, g_pGameTexture[ENEMY_TEX]);

	for (int j = 0; j < ENEMYMAX; j++)
	{
		for (int i = 0; i < 4; i++)
		{
			enemyState[j].enemy[i] = enemy[i];
			enemyState[j].enemy[i].x += enemyState[j].posX;
			enemyState[j].enemy[i].y += enemyState[j].posY;

		}

		if (enemyState[j].drawFlag)
		{
			g_pDirect3DDevice->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, enemyState[j].enemy, sizeof(CUSTOMVERTEX));	
		}
	}

}


// �G�̒e�̕`��
void EnemyBulletDraw(CUSTOMVERTEX* bullet, CUSTOMVERTEX* enemy, ENEMYSTATE* enemyState, BULLETSTATE* enemyBulletState)
{

	//�e�̐������G�͑ł�
	for (int i = 0; i < ENEMYBULLETMAX; i++)
	{
		if (enemyBulletState[i].initFlag == true)
		{
			//���݂̒e�̈ʒu����
			for (int k = 0; k < 4; k++)
			{
				enemyBulletState[i].bullet[k] = bullet[k];
				enemyBulletState[i].bullet[k].x += enemyState[i].posX;
				enemyBulletState[i].bullet[k].y += enemyState[i].posY;
			}

		}

		//�`��
		if (enemyBulletState[i].drawFlag == true)
		{
			g_pDirect3DDevice->SetTexture(0, g_pGameTexture[BULLET_ENEMY_TEX]);
			g_pDirect3DDevice->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, enemyBulletState[i].bullet, sizeof(CUSTOMVERTEX));
		}
	}


}


//�����A�j���[�V����(�G)
void  ExplosionAnimeEnemy(CUSTOMVERTEX* enemy, ENEMYSTATE* enemyState)
{

	//�����G�t�F�N�g�̒��_���
	CUSTOMVERTEX explosion02[] =
	{
		{ -EFECTTEXSIZE, -EFECTTEXSIZE, 0.5f, 1.0f, 0xFFFFFFFF,  0.0f, 0.25f },
		{  EFECTTEXSIZE, -EFECTTEXSIZE, 0.5f, 1.0f, 0xFFFFFFFF, 0.25f, 0.25f },
		{  EFECTTEXSIZE,  EFECTTEXSIZE, 0.5f, 1.0f, 0xFFFFFFFF, 0.25f,  0.5f },
		{ -EFECTTEXSIZE,  EFECTTEXSIZE, 0.5f, 1.0f, 0xFFFFFFFF,  0.0f,  0.5f },
	};


	g_pDirect3DDevice->SetTexture(0, g_pGameTexture[EXPLOSION_TEX]);


	for (int j = 0; j < ENEMYMAX; j++)
	{
		//���̃f�[�^��ێ����邽�߂̊�
		static CUSTOMVERTEX explo02_defu[ENEMYMAX][4];

		if (enemyState[j].animeExplosion)
		{
			//�A�j���[�V����(�G�̔���)�𓮂������߂̎��Ԃ��J�E���g
			static int gameTimeAnimeE = 0;
			gameTimeAnimeE++;

			if ((gameTimeAnimeE % ANIMETION_TIME) == 0)
			{
				for (int i = 0; i < 4; i++)
				{
					explo02_defu[j][i].tu += 0.25f;
				}

			}
			/*��������ʒu�����߂�(�G�̈ʒu)*/
			CUSTOMVERTEX drawEnemyVertex[4];
			for (int i = 0; i < 4; i++)
			{
				drawEnemyVertex[i] = enemy[i];
				drawEnemyVertex[i].x += enemyState[j].posX;
				drawEnemyVertex[i].y += enemyState[j].posY;
			}

			//�����摜��`�悷��ʒu����̕ϐ��ɂ����
			CUSTOMVERTEX drawExplosiinVertex[4];
			for (int i = 0; i < 4; i++)
			{
				drawExplosiinVertex[i] = explo02_defu[j][i];
				drawExplosiinVertex[i].x += drawEnemyVertex[i].x;
				drawExplosiinVertex[i].y += drawEnemyVertex[i].y;
			}

			g_pDirect3DDevice->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, drawExplosiinVertex, sizeof(CUSTOMVERTEX));

			if (explo02_defu[j][2].tu >= 1.0f)
			{
				enemyState[j].animeExplosion = false;
				enemyState[j].posX = ENEMY_X_DEFU + (ENEMY_POS_X * j);
				enemyState[j].posY = 0 - (ENEMY_POS_Y * j);
				enemyState[j].moveDown = true;
				//enemyState[j].drawFlag = true;
			}
		}
		else
		{
			for (int i = 0; i < 4; i++)
			{
				explo02_defu[j][i] = explosion02[i];
			}
		}
	}
}
