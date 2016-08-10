/**
*@file GameSceneDraw.cpp
*@brief �Q�[���̕`��֘A���܂Ƃ߂Ă���cpp.
*/
#include <d3dx9.h>
#include <d3dx9tex.h>
#include"draw_config.h"
#include"Main.h"
#include"GameSceneInit.h"
#include"GameSceneDraw.h"
#include"GameSceneControl.h"
#include"GameScore.h"
#include"GameScoreDraw.h"
#include"GamePlayerDraw.h"
#include"GameEnemyDraw.h"


//�Q�[���̕`��֐����܂Ƃ߂��֐�
void GameDraw(PLAYERSTATE* playerState, BULLETSTATE* playerBulletState, ENEMYSTATE* enemyState, BULLETSTATE* enemyBulletState, BACKGROUNDSTATE* backgroundState, SCORESTATE* hiscore, FLAGSTATE* flags)
{

	//�e�L�X�g�̈ʒu
	TEXTSTATE textState = { TEXT_X_POS, TEXT_Y_POS };

	//�v���C���[�̒��_���
	CUSTOMVERTEX player[] =
	{
		{ -TEXSIZE / 2.0f, -TEXSIZE / 2.0f, 0.5f, 1.0f, 0xFFFFFFFF, 0.0f, 0.0f },
		{  TEXSIZE / 2.0f, -TEXSIZE / 2.0f, 0.5f, 1.0f, 0xFFFFFFFF, 1.0f, 0.0f },
		{  TEXSIZE / 2.0f,  TEXSIZE / 2.0f, 0.5f, 1.0f, 0xFFFFFFFF, 1.0f, 1.0f },
		{ -TEXSIZE / 2.0f,  TEXSIZE / 2.0f, 0.5f, 1.0f, 0xFFFFFFFF, 0.0f, 1.0f },
	};

	//�G�̒��_���
	CUSTOMVERTEX enemy[] =
	{
		{ -TEXSIZE / 2.0f, -TEXSIZE / 2.0f, 0.5f, 1.0f, 0xFFFFFFFF, 0.0f, 0.0f },
		{  TEXSIZE / 2.0f, -TEXSIZE / 2.0f, 0.5f, 1.0f, 0xFFFFFFFF, 1.0f, 0.0f },
		{  TEXSIZE / 2.0f,  TEXSIZE / 2.0f, 0.5f, 1.0f, 0xFFFFFFFF, 1.0f, 1.0f },
		{ -TEXSIZE / 2.0f,  TEXSIZE / 2.0f, 0.5f, 1.0f, 0xFFFFFFFF, 0.0f, 1.0f },
	};


	//�e�̒��_���
	CUSTOMVERTEX bullet[] =
	{
		{ -TEXSIZE / 4.0f, -TEXSIZE / 4.0f, 0.5f, 1.0f, 0xFFFFFFFF, 0.0f, 0.0f },
		{  TEXSIZE / 4.0f, -TEXSIZE / 4.0f, 0.5f, 1.0f, 0xFFFFFFFF, 1.0f, 0.0f },
		{  TEXSIZE / 4.0f,  TEXSIZE / 4.0f, 0.5f, 1.0f, 0xFFFFFFFF, 1.0f, 1.0f },
		{ -TEXSIZE / 4.0f,  TEXSIZE / 4.0f, 0.5f, 1.0f, 0xFFFFFFFF, 0.0f, 1.0f },
	};

	//�X�R�A�̐����̒��_���
	CUSTOMVERTEX scorenumber[] =
	{
		{ -SCORETEXSIZE, -SCORETEXSIZE, 0.5f, 1.0f, 0xFFFFFFFF,   0.0f,   0.0f },
		{  SCORETEXSIZE, -SCORETEXSIZE, 0.5f, 1.0f, 0xFFFFFFFF, 0.125f,   0.0f },
		{  SCORETEXSIZE,  SCORETEXSIZE, 0.5f, 1.0f, 0xFFFFFFFF, 0.125f, 0.125f },
		{ -SCORETEXSIZE,  SCORETEXSIZE, 0.5f, 1.0f, 0xFFFFFFFF,   0.0f, 0.125f },
	};

	//�`��J�n
	DrawStart(g_pDirect3DDevice, D3DFVF_CUSTOMVERTEX);

	//�w�i�`��
	BgDraw( backgroundState);
	//�v���C���[�̒e�`��
	PlayerBulletDraw(player, playerBulletState, playerState);
	//�v���C���[�`��
	PlayDraw(player, playerState);
	//�G�̒e�`��
	EnemyBulletDraw(bullet, enemy, enemyState, enemyBulletState);
	//�G�̕`��
	EnemyDraw(enemy, enemyState);
	//�G�̔����`��
	ExplosionAnimeEnemy(enemy, enemyState);
	//�v���C���[�����`��
	ExplosionAnimePlayer(player, playerState);
	//���C�t�`��
	LifeDraw(scorenumber, playerState);
	//�Q�[�����̃X�R�A�`��
	GameSceneScoreDraw(scorenumber, playerState);
	
	if (flags->titleScene)
	{
		//�^�C�g���`��
		TitleDraw(flags);
		//�n�C�X�R�A�`��
		GameSceneHiScoreDraw(scorenumber, hiscore);
	}

	//�uZ�{�^���������Ă��������v�ƁuGAME OVER�v�`��
	Text01Draw(&textState,flags);
	//�uComplete�v�uWarning�v��`��
	Text02Draw(&textState, flags);
	
	//�`��I��&�\��
	DrawEnd(g_pDirect3DDevice);
}

//�w�i�`��
void BgDraw(BACKGROUNDSTATE*	backgroundState)
{
	//	�w�i1���ڂ̒��_���
	CUSTOMVERTEX background01[] = {
		{				 backgroundState[BG_ONE].posX,				backgroundState[BG_ONE].posY, 1.0f, 1.0f, 0xFFFFFFFF, 0.0f, 0.0f },
		{ backgroundState[BG_ONE].posX + BACKGROUND_W,	backgroundState[BG_ONE].posY, 1.0f, 1.0f, 0xFFFFFFFF, 1.0f, 0.0f },
		{ backgroundState[BG_ONE].posX + BACKGROUND_W, backgroundState[BG_ONE].posY + BACKGROUND_H, 1.0f, 1.0f, 0xFFFFFFFF, 1.0f, 1.0f },
		{				 backgroundState[BG_ONE].posX, backgroundState[BG_ONE].posY + BACKGROUND_H, 1.0f, 1.0f, 0xFFFFFFFF, 0.0f, 1.0f },
	};

	//	�w�i2���ڂ̒��_���
	CUSTOMVERTEX background02[] = {
		{				 backgroundState[BG_TWO].posX,				  backgroundState[BG_TWO].posY, 1.0f, 1.0f, 0xFFFFFFFF, 0.0f, 0.0f },
		{ backgroundState[BG_TWO].posX + BACKGROUND_W,				  backgroundState[BG_TWO].posY, 1.0f, 1.0f, 0xFFFFFFFF, 1.0f, 0.0f },
		{ backgroundState[BG_TWO].posX + BACKGROUND_W, backgroundState[BG_TWO].posY + BACKGROUND_H, 1.0f, 1.0f, 0xFFFFFFFF, 1.0f, 1.0f },
		{				 backgroundState[BG_TWO].posX, backgroundState[BG_TWO].posY + BACKGROUND_H, 1.0f, 1.0f, 0xFFFFFFFF, 0.0f, 1.0f },
	};

	// �w�i�`��
	g_pDirect3DDevice->SetTexture(0, g_pGameTexture[BACKGROUND_TEX]);
	g_pDirect3DDevice->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, background01, sizeof(CUSTOMVERTEX));
	g_pDirect3DDevice->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, background02, sizeof(CUSTOMVERTEX));

	
}

//�^�C�g���`��
void TitleDraw(FLAGSTATE* flags)
{
	if (flags->titleScene)
	{
		//�^�C�g���̒��_���
		CUSTOMVERTEX title[] = {
			{				 BACKGROUND_X_DEFU,         0.0f, 1.0f, 1.0f, 0xFFFFFFFF, 0.0f, 0.0f },
			{ BACKGROUND_X_DEFU + BACKGROUND_W,         0.0f, 1.0f, 1.0f, 0xFFFFFFFF, 1.0f, 0.0f },
			{ BACKGROUND_X_DEFU + BACKGROUND_W, BACKGROUND_H, 1.0f, 1.0f, 0xFFFFFFFF, 1.0f, 1.0f },
			{				 BACKGROUND_X_DEFU, BACKGROUND_H, 1.0f, 1.0f, 0xFFFFFFFF, 0.0f, 1.0f },
		};

		g_pDirect3DDevice->SetTexture(0, g_pGameTexture[TITLE_TEX]);
		g_pDirect3DDevice->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2,title, sizeof(CUSTOMVERTEX));
	}
}

//�����`��(�e�L�X�g�uZ�{�^���������Ăˁv�E�uGAME OVER�v���ŃQ�[���I�[�o�[���������Ă���)
void Text01Draw(TEXTSTATE* textState, FLAGSTATE* flags)
{
	g_pDirect3DDevice->SetTexture(0, g_pGameTexture[TEXT01_TEX]);

	//�e�L�X�g�̒��_���
	CUSTOMVERTEX text[] = {
		{	   0.0f,      0.0f, 1.0f, 1.0f, 0xFFFFFFFF, 0.0f, 0.0f },
		{ TEXT_SIZE,      0.0f, 1.0f, 1.0f, 0xFFFFFFFF, 1.0f, 0.0f },
		{ TEXT_SIZE, TEXT_SIZE, 1.0f, 1.0f, 0xFFFFFFFF, 1.0f, 0.5f },
		{      0.0f, TEXT_SIZE, 1.0f, 1.0f, 0xFFFFFFFF, 0.0f, 0.5f },
	};

	//�`��p�ϐ�
	CUSTOMVERTEX drawTextVertex[4];
	if (flags->titleScene)							//�uZ�{�^���������Ăˁv�ƕ\��
	{
		for (int i = 0; i < 4;i++)
		{
			drawTextVertex[i] = text[i];
			drawTextVertex[i].x += textState->posX;
			drawTextVertex[i].y += textState->posY;
		}

		
			g_pDirect3DDevice->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, drawTextVertex, sizeof(CUSTOMVERTEX));
		
	}
	else if (flags->gameEnd)					//�Q�[���I�[�o�[�̕�����\��
	{
		
		//�Q�[���I�[�o�[���Ă���̎��Ԃ��J�E���g
		static int gameTimeEnd = 0;							
		gameTimeEnd++;

		for (int i = 0; i < 4; i++)
		{
			drawTextVertex[i] = text[i];
			drawTextVertex[i].tv += TEXT_TV;
			drawTextVertex[i].x += textState->posX;
			drawTextVertex[i].y += textState->posY;
		}

		g_pDirect3DDevice->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, drawTextVertex, sizeof(CUSTOMVERTEX));

		if (flags->gameEnd == true && (gameTimeEnd % END_WAIT_TIME) == 0)
		{
			gameTimeEnd = 0;
			flags->saveScore = true;
		
		}
	}
}

//�����`��(�e�L�X�g�uComplete�v�E�uWARNING�v���ŃQ�[���I�[�o�[���������Ă���)
void Text02Draw(TEXTSTATE* textState, FLAGSTATE* flags)
{
	g_pDirect3DDevice->SetTexture(0, g_pGameTexture[TEXT02_TEX]);

	//�e�L�X�g�̒��_���
	CUSTOMVERTEX text02[] = {
		{      0.0f,      0.0f, 1.0f, 1.0f, 0xFFFFFFFF, 0.0f,  0.0f },
		{ TEXT_SIZE,      0.0f, 1.0f, 1.0f, 0xFFFFFFFF, 1.0f,  0.0f },
		{ TEXT_SIZE, TEXT_SIZE, 1.0f, 1.0f, 0xFFFFFFFF, 1.0f, 0.25f },
		{      0.0f, TEXT_SIZE, 1.0f, 1.0f, 0xFFFFFFFF, 0.0f, 0.25f },
	};

	if (flags->gameComplete)//�uComplete�v�ƕ\��
	{
		//�N���A���Ă���̎��Ԃ��J�E���g
		static int gameTimeComplete = 0;
		gameTimeComplete++;
		//�`��p�ϐ�
		CUSTOMVERTEX drawTextVertex[4];
									
		
			for (int i = 0; i < 4; i++)
			{
				drawTextVertex[i] = text02[i];
				drawTextVertex[i].x += textState->posX;
				drawTextVertex[i].y += textState->posY;
			}

			g_pDirect3DDevice->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, drawTextVertex, sizeof(CUSTOMVERTEX));

			if (flags->gameComplete == true && (gameTimeComplete % END_WAIT_TIME) == 0)
			{
				gameTimeComplete = 0;
				flags->saveScore = true;
			}
	}
}



