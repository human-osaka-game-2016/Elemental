/**
*@file GameScore.h
*@brief ゲームのスコア関する関数をまとめているcppのヘッダーファイル.
*/


#ifndef GAME_SCORE_H
#define	GAME_SCORE_H

/**ゲームのスコアの記録できる最大の桁数<br>*/
#define SCOREMAX 5

/**ゲームスコアの上限*/
#define HI_SCORE_MAX 99999


/**
*ランキングチェック&ソート関数<br>
*/
void ScoreRankingCheck(SCORESTATE* hiscore, PLAYERSTATE* playerState);

/**
*バイナリファイルにスコアを記録する関数<br>
*/
void SaveScore(SCORESTATE* hiscore);

/**
*バイナリファイルからスコアを読み込む関数<br>
*/
void LoadScore(SCORESTATE* hiscore, FLAGSTATE* flags);

#endif