/**
*@file GameEnemyDraw.h
*@brief �Q�[���ɂ�����G�A�G�̒e�A�y�ѓG�̔����A�j���[�V�����̕`��֐����܂Ƃ߂��t�@�C���ł�.
*/

#ifndef GAME_ENEMY_DRAW_H
#define GAME_ENEMY_DRAW_H

/**�G�̕`��֐�<br>*/
void EnemyDraw(CUSTOMVERTEX* enemy, ENEMYSTATE* enemyState);

/**�G�̒e�̕`��֐�<br>*/
void EnemyBulletDraw(CUSTOMVERTEX* bullet, CUSTOMVERTEX* enemy, ENEMYSTATE* enemyState, BULLETSTATE* enemyBulletState);

/**�����A�j���[�V����(�G)�`��֐�<br>*/
void  ExplosionAnimeEnemy(CUSTOMVERTEX* enemy, ENEMYSTATE* enemyState);

#endif