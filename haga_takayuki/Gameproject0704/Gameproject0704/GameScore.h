/**
*@file GameScore.h
*@brief �Q�[���̃X�R�A�ւ���֐����܂Ƃ߂Ă���cpp�̃w�b�_�[�t�@�C��.
*/


#ifndef GAME_SCORE_H
#define	GAME_SCORE_H

/**�Q�[���̃X�R�A�̋L�^�ł���ő�̌���<br>*/
#define SCOREMAX 5

/**�Q�[���X�R�A�̏��*/
#define HI_SCORE_MAX 99999


/**
*�����L���O�`�F�b�N&�\�[�g�֐�<br>
*/
void ScoreRankingCheck(SCORESTATE* hiscore, PLAYERSTATE* playerState);

/**
*�o�C�i���t�@�C���ɃX�R�A���L�^����֐�<br>
*/
void SaveScore(SCORESTATE* hiscore);

/**
*�o�C�i���t�@�C������X�R�A��ǂݍ��ފ֐�<br>
*/
void LoadScore(SCORESTATE* hiscore, FLAGSTATE* flags);

#endif