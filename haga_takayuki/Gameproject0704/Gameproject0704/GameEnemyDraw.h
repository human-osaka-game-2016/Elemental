/**
*@file GameEnemyDraw.h
*@brief ゲームにおける敵、敵の弾、及び敵の爆発アニメーションの描画関数をまとめたファイルです.
*/

#ifndef GAME_ENEMY_DRAW_H
#define GAME_ENEMY_DRAW_H

/**敵の描画関数<br>*/
void EnemyDraw(CUSTOMVERTEX* enemy, ENEMYSTATE* enemyState);

/**敵の弾の描画関数<br>*/
void EnemyBulletDraw(CUSTOMVERTEX* bullet, CUSTOMVERTEX* enemy, ENEMYSTATE* enemyState, BULLETSTATE* enemyBulletState);

/**爆発アニメーション(敵)描画関数<br>*/
void  ExplosionAnimeEnemy(CUSTOMVERTEX* enemy, ENEMYSTATE* enemyState);

#endif