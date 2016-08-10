/**
*@file GameScore.cpp
*@brief �Q�[���̃X�R�A�Ɋւ���֐����܂Ƃ߂Ă���cpp.
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



//�����L���O�`�F�b�N�֐�
void ScoreRankingCheck(SCORESTATE* hiscore, PLAYERSTATE* playerState)
{
	//�\�[�g����ׂ̕ϐ�(+1�͍���̃Q�[���X�R�A��)
	int rankingScore[RANKING_SCORE_MAX + 1];

	//�n�C�X�R�A�ƍ���̃Q�[���X�R�A���i�[����
	for (int i = 0; i < RANKING_SCORE_MAX ;i++)
	{
		rankingScore[i] = hiscore[i].score;
	

	}
	rankingScore[RANKING_SCORE_MAX] = playerState->SCORE;

	//�\�[�g�p�t���O
	bool sortFlag = false;

	//���בւ�(�o�u���\�[�g)
	do
	{
		sortFlag = false;

		
		for (int i = 0; i < RANKING_SCORE_MAX; i++)
		{
			if (rankingScore[i] < rankingScore[i + 1])
			{
				//�����p�̕ϐ�(tmp)
				int tmp = rankingScore[i];
				rankingScore[i] = rankingScore[i + 1];
				rankingScore[i + 1] = tmp;

				sortFlag = true;
			}

		}
	} while (sortFlag);

	//���וς������̂��n�C�X�R�A�̕ϐ��ɂ��ǂ�
	for (int i = 0; i < RANKING_SCORE_MAX; i++)
	{
		hiscore[i].score = rankingScore[i];
	}


}


//�o�C�i���t�@�C���ɃX�R�A���L�^����
void SaveScore(SCORESTATE* hiscore)
{
	//�X�R�A�f�[�^�̊�
	SCORESTATE hiscoreTmp[RANKING_SCORE_MAX];

	for (int i = 0; i < RANKING_SCORE_MAX; i++)
	{
		hiscoreTmp[i] = hiscore[i];
	}

	//�t�@�C���|�C���^
	FILE *file;

	fopen_s(&file,"score.dat", "wb");
	fwrite(hiscoreTmp, sizeof(hiscoreTmp), 1, file);
	fclose(file);
}


//�o�C�i���t�@�C������X�R�A��ǂݍ���
void LoadScore(SCORESTATE* hiscore, FLAGSTATE* flags)
{
	//�X�R�A�f�[�^�̊�
	SCORESTATE hiscoreTmp[RANKING_SCORE_MAX];


	//�t�@�C���|�C���^
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