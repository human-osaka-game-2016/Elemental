/**
*@file GameSceneInit.h
*@brief ゲームシーンにおける初期化関数をまとめたcppのヘッダーファイルです.
*背景や敵やプレイヤーの初期座標もここで#defineしている<br>
*/
#ifndef GAME_SCENE_INIT_H
#define GAME_SCENE_INIT_H

/**背景のx座標における初期位置<br>*/
#define BACKGROUND_X_DEFU 128.f
/**背景のy座標における初期位置<br>*/
#define BACKGROUND_Y_DEFU 640.f

/**プレイヤーの残機初期値<br>*/
#define PLAYER_LIFE_DEFU 3
/**プレイヤーのスコア初期値<br>*/
#define PLAYER_SCORE_DEFU 0
/**プレイヤーのx座標の初期値<br>*/
#define PLAYER_X_DEFU 240.f
/**プレイヤーのy座標の初期値<br>*/
#define PLAYER_Y_DEFU 608.f

/**敵の撃退時に入るスコア<br>*/
#define ENEMY_SCORE_DEFU 100
/**敵のx座標の初期値(1体目)<br>*/
#define ENEMY_X_DEFU 198.f
/**敵のy座標の初期値(1体目)<br>*/
#define ENEMY_Y_DEFU 70.f

/**
*描画設定･座標初期化・画像読み込み関数<br>
*描画設定と変数の初期化、及び画像の読み込みといったゲームの初期化関連を行う関数<br>
*@param[out] playerState		プレイヤーの情報
*@param[out] playerBulletState	プレイヤーの弾情報
*@param[out] enemyState			敵の情報
*@param[out] enemyBulletState	敵の弾情報
*@param[out] backgroundState01	背景1枚目の座標情報
*@param[out] backgroundState02	背景2枚目の座標情報
*@param[out] hiscore			ハイスコアを格納する配列
*@param[out] flags				フラグ構造体
*/
void InitGameScene(PLAYERSTATE* playerState, BULLETSTATE* playerBulletState, ENEMYSTATE* enemyState, BULLETSTATE* enemyBulletState, BACKGROUNDSTATE* backgroundState, SCORESTATE* hiscore, FLAGSTATE* flags);


#endif