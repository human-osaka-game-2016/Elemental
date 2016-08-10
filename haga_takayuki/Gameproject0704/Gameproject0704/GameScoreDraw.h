/**
*@file GameScoreDraw.h
*@brief 数字(スコアやライフ)の描画に関する関数をまとめているcppのヘッダーファイル.
*/
#ifndef GAME_SCORE_DRAW_H
#define GAME_SCORE_DRAW_H


/**スコアのテクスチャーサイズ<br>*/
#define SCORETEXSIZE 8.f

/**ゲーム中に表示するスコアの1桁目のx座標<br>*/
#define GAMESCENESCORE_X 342.f
/**ゲーム中に表示するスコアの1桁目のy座標<br>*/
#define GAMESCENESCORE_Y 13.f
/**ゲーム中に表示するスコアの1桁のtu値の変動量<br>*/
#define GAMESCENESCORE_TU 0.125f
/**ゲーム中に表示するスコアの1桁のtv値の変動量<br>*/
#define GAMESCENESCORE_TV 0.125f

/**ゲームスコアの１桁の間隔x座標<br>*/
#define GAMESCORE_INTERVAL_X 2
/**ゲームスコアの１桁の間隔y座標<br>*/
#define GAMESCORE_INTERVAL_Y 4

/**ハイスコア表示x座標*/
#define HISCORE_X 270.f
/**ハイスコア表示座標*/
#define HISCORE_Y 350.f


/**ライフの表示x座標*/
#define LIFE_X 128.f
/**ライフの表示y座標*/
#define LIFE_Y 16.f

/**ゲーム終了からタイトル移行への待機時間<br>*/
#define END_WAIT_TIME 350


/**ゲーム中にスコアを上に描画する関数<br>*/
void GameSceneScoreDraw(CUSTOMVERTEX* scorenumber, PLAYERSTATE* playerState);

/**タイトルにスコアランキングを描画する関数<br>*/
void GameSceneHiScoreDraw(CUSTOMVERTEX* scorenumber, SCORESTATE* hiscore);

/**ライフゲージ描画*/
void LifeDraw(CUSTOMVERTEX* scorenumber, PLAYERSTATE* playerState);

//数字を描画する関数
void DrawScoreNunber(int num, CUSTOMVERTEX* drawScoreVertex);

#endif