/**
*@file GamePlayerDraw.cpp
*@brief �Q�[���ɂ�����v���C���[�A�v���C���[�̒e�A�y�уv���C���[�̔����A�j���[�V�����̕`��֐����܂Ƃ߂��t�@�C���ł�.
*/
#include <d3dx9.h>
#include <d3dx9tex.h>
#include"draw_config.h"
#include"Main.h"
#include"GameSceneInit.h"
#include"GameSceneDraw.h"

// �v���C���[�`��
void PlayDraw(CUSTOMVERTEX* player, PLAYERSTATE* playerState)
{

	if (playerState->drawFlag)
	{
		CUSTOMVERTEX drawPlayerVertex[4];
		for (int i = 0; i < 4; i++)
		{
			drawPlayerVertex[i] = player[i];
			drawPlayerVertex[i].x += playerState->posX;
			drawPlayerVertex[i].y += playerState->posY;
		}
		g_pDirect3DDevice->SetTexture(0, g_pGameTexture[PLAYER_TEX]);
		g_pDirect3DDevice->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, drawPlayerVertex, sizeof(CUSTOMVERTEX));
	}

}

// �v���C���[�̒e�̕`��
void PlayerBulletDraw(CUSTOMVERTEX* player, BULLETSTATE* playerBulletState, PLAYERSTATE* playerState)
{
	//�v���C���[�̒e�̒��_���
	CUSTOMVERTEX player_bullet[] =
	{
		{ -TEXSIZE / 4.0f, -TEXSIZE / 2.0f, 0.5f, 1.0f, 0xFFFFFFFF, 0.0f, 0.0f },
		{  TEXSIZE / 4.0f, -TEXSIZE / 2.0f, 0.5f, 1.0f, 0xFFFFFFFF, 1.0f, 0.0f },
		{  TEXSIZE / 4.0f,  TEXSIZE / 2.0f, 0.5f, 1.0f, 0xFFFFFFFF, 1.0f, 1.0f },
		{ -TEXSIZE / 4.0f,  TEXSIZE / 2.0f, 0.5f, 1.0f, 0xFFFFFFFF, 0.0f, 1.0f },
	};

	for (int i = 0; i < BULLETMAX; i++)
	{

		if (playerBulletState[i].initFlag == true)
		{
			//���݂̒e�̈ʒu����
			for (int j = 0; j < 4; j++)
			{
				playerBulletState[i].bullet[j] = player_bullet[j];
				playerBulletState[i].bullet[j].x += playerState->posX;
				playerBulletState[i].bullet[j].y += playerState->posY;
			}

		}

		//�`��
		if (playerBulletState[i].drawFlag == true)
		{
			g_pDirect3DDevice->SetTexture(0, g_pGameTexture[BULLET_TEX]);
			g_pDirect3DDevice->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, playerBulletState[i].bullet, sizeof(CUSTOMVERTEX));

		}
	}
}

//�����A�j���[�V����(�v���C���[)
void ExplosionAnimePlayer(CUSTOMVERTEX* player, PLAYERSTATE* playerState)
{
	//�v���C���[�̔����G�t�F�N�g�̒��_���
	CUSTOMVERTEX explosion01[] =
	{
		{ -EFECTTEXSIZE, -EFECTTEXSIZE, 0.5f, 1.0f, 0xFFFFFFFF, 0.0f, 0.0f },
		{  EFECTTEXSIZE, -EFECTTEXSIZE, 0.5f, 1.0f, 0xFFFFFFFF, 0.25f, 0.0f },
		{  EFECTTEXSIZE,  EFECTTEXSIZE, 0.5f, 1.0f, 0xFFFFFFFF, 0.25f, 0.25f },
		{ -EFECTTEXSIZE,  EFECTTEXSIZE, 0.5f, 1.0f, 0xFFFFFFFF, 0.0f, 0.25f },
	};

	//���̃f�[�^��ێ����邽�߂̊�
	static CUSTOMVERTEX explo01_defu[4];

	if (playerState->animeExplosion)
	{
		//�A�j���[�V����(�v���C���[�̔���)�𓮂������߂̎��Ԃ��J�E���g
		static int gameTimeAnimeP = 0;
		gameTimeAnimeP++;

		if ((gameTimeAnimeP % ANIMETION_TIME) == 0)
		{
			for (int i = 0; i < 4; i++)
			{
				explo01_defu[i].tu += 0.25f;
			}

		}

		/*��������ʒu�����߂�(�v���C���[�̈ʒu)*/
		CUSTOMVERTEX drawPlayerVertex[4];
		for (int i = 0; i < 4; i++)
		{
			drawPlayerVertex[i] = player[i];
			drawPlayerVertex[i].x += playerState->posX;
			drawPlayerVertex[i].y += playerState->posY;
		}

		//�����摜��`�悷��ʒu����̕ϐ��ɂ����
		CUSTOMVERTEX drawExplosiinVertex[4];
		for (int i = 0; i < 4; i++)
		{
			drawExplosiinVertex[i] = explo01_defu[i];
			drawExplosiinVertex[i].x += drawPlayerVertex[i].x;
			drawExplosiinVertex[i].y += drawPlayerVertex[i].y;
		}

		g_pDirect3DDevice->SetTexture(0, g_pGameTexture[EXPLOSION_TEX]);
		g_pDirect3DDevice->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, drawExplosiinVertex, sizeof(CUSTOMVERTEX));

		if (explo01_defu[2].tu >= 1.0f && playerState->LIFE >= 0)
		{
			playerState->animeExplosion = false;
			playerState->drawFlag = true;
			playerState->posX = PLAYER_X_DEFU;
			playerState->posY = PLAYER_Y_DEFU;
		}
		else if (explo01_defu[2].tu >= 1.0f && playerState->LIFE < 0)
		{
			playerState->animeExplosion = false;
		}
	}
	else
	{
		for (int i = 0; i < 4; i++)
		{
			explo01_defu[i] = explosion01[i];
		}
	}
}