/**
*@file GamePlayerControl.h
*@brief ゲームにおけるプレイヤーの操作、及びプレイヤーの弾の関数をまとめたヘッダーファイルです.
*/
#ifndef GAME_PLAYER_CONTROL_H
#define GAME_PLAYER_CONTROL_H

/**プレイヤーのスピード<br>*/
#define PLAYER_MOVESPEED 5.f
/**プレイヤー弾のスピード<br>*/
#define BULLET_MOVESPEED 8.f
/**プレイヤー弾の連射間隔<br>*/
#define BULLET_INTERVAL 10
/**プレイヤー無敵時間<br>*/
#define PLAYER_INVINCIBLE_TIME 60

/**
*プレイヤーコントロール関数<br>
*プレイヤーのキー操作、敵と敵の弾との当たり判定の処理を行っている<br>
*@param[out] playerState		プレイヤーの情報
*@param[in] enemyState			敵の情報
*@param[in]	enemyBulletState	敵の弾の情報
*@param[out]	gameEnd			ゲーム終了フラグ
*/
void PlayerControl(PLAYERSTATE* playerState, ENEMYSTATE* enemyState, BULLETSTATE* enemyBulletState, FLAGSTATE* flags);

/**
*プレイヤーの弾コントロール関数<br>
*プレイヤーの弾の発射と動作の処理<br>
*@param[out] playerBulletState		プレイヤーの弾の情報
*@param[in] playerState				プレイヤーの情報
*/
void PlayerBulletControl(BULLETSTATE* playerBulletState, PLAYERSTATE* playerState);

#endif