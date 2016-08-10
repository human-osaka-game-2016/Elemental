/**
*@file GameSceneControl.h
*@brief ゲームの操作や動きに関する関数をまとめているcppのヘッダーファイル.
*/
#ifndef GAME_SCENE_CONTROL_H
#define	GAME_SCENE_CONTROL_H

/**背景の動く速度<br>*/
#define BG_MOVESPEED 1.f

/**敵の基本スピード<br>*/
#define ENEMY_MOVESPEED 1.f
/**敵が画面外から現れる時のスピード<br>*/
#define ENEMY_DOWN_MOVESPEED 2.f

/**敵の弾のスピード<br>*/
#define ENEMY_BULLET_MOVESPEED 3.f
/**敵同士の間隔(x座標)<br>*/
#define ENEMY_POS_X 40.f
/**敵同士の間隔(y座標)<br>*/
#define ENEMY_POS_Y 32.f


/**ダメージ数*/
#define LIFE_DAMEGE 1

/**背景で動けるxの限界(左)<br>*/
#define BG_X_LEFT_LIMIT 130.f
/**背景で動けるxの限界(右)<br>*/
#define BG_X_RIGHT_LIMIT 350.f

/**背景で動けるyの限界(上)<br>*/
#define BG_Y_UP_LIMIT 0.0f
/**背景で動けるyの限界(下)<br>*/
#define BG_Y_DOWN_LIMIT 629.f

/**
*ゲームシーンのコントロールをまとめている関数<br>
*/
void GameControl(PLAYERSTATE* playerState, BULLETSTATE* playerBulletState, ENEMYSTATE* enemyState, BULLETSTATE* enemyBulletState, SCORESTATE* hiscore
	, BACKGROUNDSTATE*	backgroundState, FLAGSTATE* flags);

/**
*背景コントロール関数<br>
*/
void BgControl(BACKGROUNDSTATE*	backgroundState);

/**
*タイトルコントロール関数<br>
*/
void TitleSceneControl(FLAGSTATE* flags, PLAYERSTATE* playerState, ENEMYSTATE* enemyState, BULLETSTATE* playerBulletState, BULLETSTATE* enemyBulletState);

/**
デバック関数<br>
*/
void GameDbug(PLAYERSTATE* playerState, SCORESTATE* hiscore, bool* gameEnd);
#endif