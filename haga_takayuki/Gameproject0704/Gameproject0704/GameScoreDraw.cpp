/**
*@file GameScoreDraw.cpp
*@brief 数字(スコアやライフ)の描画に関する関数をまとめているcpp.
*/
#include <d3dx9.h>
#include <d3dx9tex.h>
#include"draw_config.h"
#include"Main.h"
#include"GameSceneInit.h"
#include"GameSceneDraw.h"
#include"GameScore.h"
#include"GameScoreDraw.h"

//ゲーム中にスコアを上に描画
void GameSceneScoreDraw(CUSTOMVERTEX* scorenumber, PLAYERSTATE* playerState)
{
	g_pDirect3DDevice->SetTexture(0,g_pGameTexture[SCORE_TEX]);

	//画面上に表示するためにゲーム中のスコアを格納する変数
	int gameScoreCurrent[SCOREMAX];
	//元のデータを保持するための器
	int tempScore = playerState->SCORE;

	//1桁ずついれる為10で割っていく
	for (int i = 0; i < SCOREMAX; i++)
	{
		gameScoreCurrent[i] = tempScore % 10;
		tempScore /= 10;

	}
	//描画用の空の変数
	CUSTOMVERTEX drawScoreVertex[SCOREMAX][4];
	for (int i = 0; i < SCOREMAX; i++)
	{
		//スコアの一桁目を格納
		int scoreDigit = gameScoreCurrent[i];

		for (int j = 0; j < 4; j++)
		{
			drawScoreVertex[i][j] = scorenumber[j];
			drawScoreVertex[i][j].x += (GAMESCENESCORE_X - ((SCORETEXSIZE * 2) * i));
			drawScoreVertex[i][j].y += GAMESCENESCORE_Y;
		}
		
		//数字にあわせて描画
		DrawScoreNunber(scoreDigit, drawScoreVertex[i]);
	}
}


//タイトル中にスコアランキングを描画
void GameSceneHiScoreDraw(CUSTOMVERTEX* scorenumber, SCORESTATE* hiscore)
{

	g_pDirect3DDevice->SetTexture(0, g_pGameTexture[SCORE_TEX]);

	for (int k = 0; k < RANKING_SCORE_MAX; k++)
	{

		int gameScoreStore[RANKING_SCORE_MAX][SCOREMAX];

		//元のデータを保持するための器
		int tempScore = hiscore[k].score;

	   //1桁ずついれる為10で割っていく
		for (int i = 0; i < SCOREMAX; i++)
		{
	
			gameScoreStore[k][i] = tempScore % 10 ;
			tempScore /= 10;
		
		}

		//描画用の空の変数
		CUSTOMVERTEX drawScoreVertex[RANKING_SCORE_MAX][SCOREMAX][4];
		for (int i = 0; i < SCOREMAX; i++)
		{
			//スコアの一桁目を格納
			int scoreDigit = gameScoreStore[k][i];

			for (int j = 0; j < 4; j++)
			{
				drawScoreVertex[k][i][j] = scorenumber[j];
				drawScoreVertex[k][i][j].x += (HISCORE_X - ((SCORETEXSIZE * GAMESCORE_INTERVAL_X) * i));
				drawScoreVertex[k][i][j].y += (HISCORE_Y + ((SCORETEXSIZE * GAMESCORE_INTERVAL_Y) * k));
			}

			//数字にあわせて描画
			DrawScoreNunber(scoreDigit, drawScoreVertex[k][i]);
			
		}
	}
}

//ライフゲージ描画
void LifeDraw(CUSTOMVERTEX* scorenumber, PLAYERSTATE* playerState)
{
	g_pDirect3DDevice->SetTexture(0, g_pGameTexture[SCORE_TEX]);
	//ライフのLを表示
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


	//×の表示
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

	//ライフ量の表示
	//描画用の空の変数
	CUSTOMVERTEX drawScoreVertex[4];
	

		for (int j = 0; j < 4; j++)
		{
			drawScoreVertex[j] = scorenumber[j];
			drawScoreVertex[j].x += LIFE_X + ((SCORETEXSIZE * 2) * 3);
			drawScoreVertex[j].y += LIFE_Y;
		}

		DrawScoreNunber(playerState->LIFE, drawScoreVertex);
		
}


//数字を描画する関数
void DrawScoreNunber(int num, CUSTOMVERTEX* drawScoreVertex)
{
	//数字にあわせて描画
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