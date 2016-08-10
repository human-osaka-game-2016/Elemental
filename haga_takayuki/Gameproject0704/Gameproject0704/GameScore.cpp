/**
*@file GameScore.cpp
*@brief ゲームのスコアに関する関数をまとめているcpp.
*/
#include <d3dx9.h>
#include <d3dx9tex.h>
#include <dinput.h>
#include <stdio.h>
#include"config.h"
#include"Main.h"
#include"GameSceneInit.h"
#include"GameSceneDraw.h"
#include"GameSceneControl.h"
#include"GameScore.h"



//ランキングチェック関数
void ScoreRankingCheck(SCORESTATE* hiscore, PLAYERSTATE* playerState)
{
	//ソートする為の変数(+1は今回のゲームスコア分)
	int rankingScore[RANKING_SCORE_MAX + 1];

	//ハイスコアと今回のゲームスコアを格納する
	for (int i = 0; i < RANKING_SCORE_MAX ;i++)
	{
		rankingScore[i] = hiscore[i].score;
	

	}
	rankingScore[RANKING_SCORE_MAX] = playerState->SCORE;

	//ソート用フラグ
	bool sortFlag = false;

	//並べ替え(バブルソート)
	do
	{
		sortFlag = false;

		
		for (int i = 0; i < RANKING_SCORE_MAX; i++)
		{
			if (rankingScore[i] < rankingScore[i + 1])
			{
				//交換用の変数(tmp)
				int tmp = rankingScore[i];
				rankingScore[i] = rankingScore[i + 1];
				rankingScore[i + 1] = tmp;

				sortFlag = true;
			}

		}
	} while (sortFlag);

	//並べ変えたものをハイスコアの変数にもどす
	for (int i = 0; i < RANKING_SCORE_MAX; i++)
	{
		hiscore[i].score = rankingScore[i];
	}


}


//バイナリファイルにスコアを記録する
void SaveScore(SCORESTATE* hiscore)
{
	//スコアデータの器
	SCORESTATE hiscoreTmp[RANKING_SCORE_MAX];

	for (int i = 0; i < RANKING_SCORE_MAX; i++)
	{
		hiscoreTmp[i] = hiscore[i];
	}

	//ファイルポインタ
	FILE *file;

	fopen_s(&file,"score.dat", "wb");
	fwrite(hiscoreTmp, sizeof(hiscoreTmp), 1, file);
	fclose(file);
}


//バイナリファイルからスコアを読み込む
void LoadScore(SCORESTATE* hiscore, FLAGSTATE* flags)
{
	//スコアデータの器
	SCORESTATE hiscoreTmp[RANKING_SCORE_MAX];


	//ファイルポインタ
	FILE *file;

	fopen_s(&file, "score.dat", "rb");
	fread(hiscoreTmp, sizeof(hiscoreTmp), 1, file);

	fclose(file);


	for (int i = 0; i < RANKING_SCORE_MAX; i++)
	{
		hiscore[i] = hiscoreTmp[i];
	}

	flags->loadScore = false;
}