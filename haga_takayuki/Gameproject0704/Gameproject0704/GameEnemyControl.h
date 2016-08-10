/**
*@file GameEnemyControl.h
*@brief �Q�[���ɂ�����G�̑���A�y�ѓG�̒e�̊֐����܂Ƃ߂��w�b�_�[�t�@�C���ł�.
*/
#ifndef GAME_ENEMY_CONTROL_H
#define GAME_ENEMY_CONTROL_H

/**
*�G�R���g���[���֐�<br>
*�G�̓���A�y�уv���C���[�̒e�Ƃ̓����蔻��̏���<br>
*@param[out] enemyState				�G�̏��
*@param[in] playerBulletState		�v���C���[�̒e�̏��
*@param[in] playerState				�v���C���[�̏��			
*@param[out] gameComplete			�Q�[���N���A�t���O
*/
void EnemyControl(ENEMYSTATE* enemyState, BULLETSTATE* playerBulletState, PLAYERSTATE* playerState, FLAGSTATE* flags);

/**
*�G�̒e�̃R���g���[���֐�<br>
*�G�̒e�̔��ˁA�G�̒e�̓���̏���<br>
*@param[out] enemyBulletState		�G�̒e�̏��
*@param[in] enemyState				�G�̏��
*/
void EnemyBulletControl(BULLETSTATE* enemyBulletState, ENEMYSTATE* enemyState);

#endif