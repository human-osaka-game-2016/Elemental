/**
*@file GameScoreDraw.cpp
*@brief ����(�X�R�A�⃉�C�t)�̕`��Ɋւ���֐����܂Ƃ߂Ă���cpp.
*/
#include <d3dx9.h>
#include <d3dx9tex.h>
#include"draw_config.h"
#include"Main.h"
#include"GameSceneInit.h"
#include"GameSceneDraw.h"
#include"GameScore.h"
#include"GameScoreDraw.h"

//�Q�[�����ɃX�R�A����ɕ`��
void GameSceneScoreDraw(CUSTOMVERTEX* scorenumber, PLAYERSTATE* playerState)
{
	g_pDirect3DDevice->SetTexture(0,g_pGameTexture[SCORE_TEX]);

	//��ʏ�ɕ\�����邽�߂ɃQ�[�����̃X�R�A���i�[����ϐ�
	int gameScoreCurrent[SCOREMAX];
	//���̃f�[�^��ێ����邽�߂̊�
	int tempScore = playerState->SCORE;

	//1����������10�Ŋ����Ă���
	for (int i = 0; i < SCOREMAX; i++)
	{
		gameScoreCurrent[i] = tempScore % 10;
		tempScore /= 10;

	}
	//�`��p�̋�̕ϐ�
	CUSTOMVERTEX drawScoreVertex[SCOREMAX][4];
	for (int i = 0; i < SCOREMAX; i++)
	{
		//�X�R�A�̈ꌅ�ڂ��i�[
		int scoreDigit = gameScoreCurrent[i];

		for (int j = 0; j < 4; j++)
		{
			drawScoreVertex[i][j] = scorenumber[j];
			drawScoreVertex[i][j].x += (GAMESCENESCORE_X - ((SCORETEXSIZE * 2) * i));
			drawScoreVertex[i][j].y += GAMESCENESCORE_Y;
		}
		
		//�����ɂ��킹�ĕ`��
		DrawScoreNunber(scoreDigit, drawScoreVertex[i]);
	}
}


//�^�C�g�����ɃX�R�A�����L���O��`��
void GameSceneHiScoreDraw(CUSTOMVERTEX* scorenumber, SCORESTATE* hiscore)
{

	g_pDirect3DDevice->SetTexture(0, g_pGameTexture[SCORE_TEX]);

	for (int k = 0; k < RANKING_SCORE_MAX; k++)
	{

		int gameScoreStore[RANKING_SCORE_MAX][SCOREMAX];

		//���̃f�[�^��ێ����邽�߂̊�
		int tempScore = hiscore[k].score;

	   //1����������10�Ŋ����Ă���
		for (int i = 0; i < SCOREMAX; i++)
		{
	
			gameScoreStore[k][i] = tempScore % 10 ;
			tempScore /= 10;
		
		}

		//�`��p�̋�̕ϐ�
		CUSTOMVERTEX drawScoreVertex[RANKING_SCORE_MAX][SCOREMAX][4];
		for (int i = 0; i < SCOREMAX; i++)
		{
			//�X�R�A�̈ꌅ�ڂ��i�[
			int scoreDigit = gameScoreStore[k][i];

			for (int j = 0; j < 4; j++)
			{
				drawScoreVertex[k][i][j] = scorenumber[j];
				drawScoreVertex[k][i][j].x += (HISCORE_X - ((SCORETEXSIZE * GAMESCORE_INTERVAL_X) * i));
				drawScoreVertex[k][i][j].y += (HISCORE_Y + ((SCORETEXSIZE * GAMESCORE_INTERVAL_Y) * k));
			}

			//�����ɂ��킹�ĕ`��
			DrawScoreNunber(scoreDigit, drawScoreVertex[k][i]);
			
		}
	}
}

//���C�t�Q�[�W�`��
void LifeDraw(CUSTOMVERTEX* scorenumber, PLAYERSTATE* playerState)
{
	g_pDirect3DDevice->SetTexture(0, g_pGameTexture[SCORE_TEX]);
	//���C�t��L��\��
	CUSTOMVERTEX drawLifeVertex[4];
	for (int j = 0; j < 4; j++)
	{
		drawLifeVertex[j] = scorenumber[j];
		drawLifeVertex[j].x += LIFE_X + (SCORETEXSIZE * 2);
		drawLifeVertex[j].y += LIFE_Y;
		drawLifeVertex[j].tv += GAMESCENESCORE_TV * 2;
		drawLifeVertex[j].tu += GAMESCENESCORE_TU * 5;
	}
	g_pDirect3DDevice->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, drawLifeVertex, sizeof(CUSTOMVERTEX));


	//�~�̕\��
	CUSTOMVERTEX drawPekeVertex[4];
	for (int j = 0; j < 4; j++)
	{
		drawPekeVertex[j] = scorenumber[j];
		drawPekeVertex[j].x += LIFE_X + ((SCORETEXSIZE * 2) * 2);
		drawPekeVertex[j].y += LIFE_Y;
		drawPekeVertex[j].tv += GAMESCENESCORE_TV * 5;
		drawPekeVertex[j].tu += GAMESCENESCORE_TU * 5;
	}
	g_pDirect3DDevice->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, drawPekeVertex, sizeof(CUSTOMVERTEX));

	//���C�t�ʂ̕\��
	//�`��p�̋�̕ϐ�
	CUSTOMVERTEX drawScoreVertex[4];
	

		for (int j = 0; j < 4; j++)
		{
			drawScoreVertex[j] = scorenumber[j];
			drawScoreVertex[j].x += LIFE_X + ((SCORETEXSIZE * 2) * 3);
			drawScoreVertex[j].y += LIFE_Y;
		}

		DrawScoreNunber(playerState->LIFE, drawScoreVertex);
		
}


//������`�悷��֐�
void DrawScoreNunber(int num, CUSTOMVERTEX* drawScoreVertex)
{
	//�����ɂ��킹�ĕ`��
	switch (num)
	{
	case 0:
		break;

	case 1:
		for (int j = 0; j < 4; j++)
		{
			drawScoreVertex[j].tu += GAMESCENESCORE_TU;
		}
		break;

	case 2:
		for (int j = 0; j < 4; j++)
		{
			drawScoreVertex[j].tu += (GAMESCENESCORE_TU * 2);
		}
		break;

	case 3:
		for (int j = 0; j < 4; j++)
		{
			drawScoreVertex[j].tu += (GAMESCENESCORE_TU * 3);
		}
		break;

	case 4:
		for (int j = 0; j < 4; j++)
		{
			drawScoreVertex[j].tu += (GAMESCENESCORE_TU * 4);
		}
		break;

	case 5:
		for (int j = 0; j < 4; j++)
		{
			drawScoreVertex[j].tu += (GAMESCENESCORE_TU * 5);
		}
		break;

	case 6:
		for (int j = 0; j < 4; j++)
		{
			drawScoreVertex[j].tu += (GAMESCENESCORE_TU * 6);
		}
		break;

	case 7:
		for (int j = 0; j < 4; j++)
		{
			drawScoreVertex[j].tu += (GAMESCENESCORE_TU * 7);
		}
		break;

	case 8:
		for (int j = 0; j < 4; j++)
		{
			drawScoreVertex[j].tv += GAMESCENESCORE_TV;
		}
		break;

	case 9:
		for (int j = 0; j < 4; j++)
		{
			drawScoreVertex[j].tv += GAMESCENESCORE_TV;
			drawScoreVertex[j].tu += GAMESCENESCORE_TU;

		}
		break;

	}

	g_pDirect3DDevice->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, drawScoreVertex, sizeof(CUSTOMVERTEX));
}