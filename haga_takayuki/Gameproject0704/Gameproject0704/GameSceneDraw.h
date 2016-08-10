/**
*@file GameSceneDraw.h
*@brief ゲームの描画関連をまとめているcppのヘッダーファイル.
*/
#ifndef GAME_SCENE_DRAW_H
#define GAME_SCENE_DRAW_H

/**背景幅<br>*/
#define BACKGROUND_W 224.f
/**背景高さ<br>*/
#define BACKGROUND_H 640.f

/**テキストサイズ*/
#define TEXT_SIZE 224.f
/**テキストのx軸初期位置*/
#define TEXT_X_POS 128.f
/**テキストのy軸初期位置*/
#define TEXT_Y_POS 150.f

/**テクスチャースケールの基本値<br>*/
#define TEXSIZE 32.f
/**爆発エフェクトの基本スケール*/
#define EFECTTEXSIZE 32.f

/**爆発アニメーションtu値変化量<br>*/
#define ANIMETION_TU 0.25.f
/**爆発アニメーション時間間隔量<br>*/
#define ANIMETION_TIME 5

/**テキスト表示時間間隔量<br>*/
#define TEXT_TIME 60
/**テキストのtv値の変化量<br>*/
#define TEXT_TV 0.5f

/**敵の配置の間隔<br>*/
#define ENEMY_POS_Y 32.f


/**ゲームの描画関数<br>*/
void GameDraw(PLAYERSTATE* playerState, BULLETSTATE* playerBulletState, ENEMYSTATE* enemyState, BULLETSTATE* enemyBulletState, BACKGROUNDSTATE*	backgroundState, SCORESTATE* hiscore, FLAGSTATE* flags);

/**背景描画関数<br>*/
void BgDraw(BACKGROUNDSTATE* backgroundState);

/**タイトル描画関数<br>*/
void TitleDraw(FLAGSTATE* flags);

/**
*テキスト描画関数.<br>
*テキスト文字はテキスト「Zボタンを押してね」・「GAME OVER」<br>
*/
void Text01Draw(TEXTSTATE* textState, FLAGSTATE* flags);

/**
*テキスト描画関数.<br>
*テキスト文字はテキスト「Complete」・「WARNING」<br>
*/
void Text02Draw(TEXTSTATE* textState, FLAGSTATE* flags);

#endif
