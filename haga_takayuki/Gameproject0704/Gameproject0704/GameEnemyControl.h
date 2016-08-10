/**
*@file GameEnemyControl.h
*@brief ゲームにおける敵の操作、及び敵の弾の関数をまとめたヘッダーファイルです.
*/
#ifndef GAME_ENEMY_CONTROL_H
#define GAME_ENEMY_CONTROL_H

/**
*敵コントロール関数<br>
*敵の動作、及びプレイヤーの弾との当たり判定の処理<br>
*@param[out] enemyState				敵の情報
*@param[in] playerBulletState		プレイヤーの弾の情報
*@param[in] playerState				プレイヤーの情報			
*@param[out] gameComplete			ゲームクリアフラグ
*/
void EnemyControl(ENEMYSTATE* enemyState, BULLETSTATE* playerBulletState, PLAYERSTATE* playerState, FLAGSTATE* flags);

/**
*敵の弾のコントロール関数<br>
*敵の弾の発射、敵の弾の動作の処理<br>
*@param[out] enemyBulletState		敵の弾の情報
*@param[in] enemyState				敵の情報
*/
void EnemyBulletControl(BULLETSTATE* enemyBulletState, ENEMYSTATE* enemyState);

#endif