/**
*@file GamePlayerDraw.h
*@brief ゲームにおけるプレイヤー、プレイヤーの弾、及びプレイヤーの爆発アニメーションの描画関数をまとめたヘッダーファイルです.
*/

#ifndef GAME_PLAYER_DRAW_H
#define GAME_PLAYER_DRAW_H

/**プレイヤー描画関数<br>*/
void PlayDraw(CUSTOMVERTEX* player, PLAYERSTATE* playerState);

/**プレイヤー弾の描画関数<br>*/
void PlayerBulletDraw(CUSTOMVERTEX* player, BULLETSTATE* playerBulletState, PLAYERSTATE* playerState);

/**爆発アニメーション(プレイヤー)描画関数<br>*/
void ExplosionAnimePlayer(CUSTOMVERTEX* player, PLAYERSTATE* playerState);

#endif