/**
*@file GamePlayerControl.h
*@brief �Q�[���ɂ�����v���C���[�̑���A�y�уv���C���[�̒e�̊֐����܂Ƃ߂��w�b�_�[�t�@�C���ł�.
*/
#ifndef GAME_PLAYER_CONTROL_H
#define GAME_PLAYER_CONTROL_H

/**�v���C���[�̃X�s�[�h<br>*/
#define PLAYER_MOVESPEED 5.f
/**�v���C���[�e�̃X�s�[�h<br>*/
#define BULLET_MOVESPEED 8.f
/**�v���C���[�e�̘A�ˊԊu<br>*/
#define BULLET_INTERVAL 10
/**�v���C���[���G����<br>*/
#define PLAYER_INVINCIBLE_TIME 60

/**
*�v���C���[�R���g���[���֐�<br>
*�v���C���[�̃L�[����A�G�ƓG�̒e�Ƃ̓����蔻��̏������s���Ă���<br>
*@param[out] playerState		�v���C���[�̏��
*@param[in] enemyState			�G�̏��
*@param[in]	enemyBulletState	�G�̒e�̏��
*@param[out]	gameEnd			�Q�[���I���t���O
*/
void PlayerControl(PLAYERSTATE* playerState, ENEMYSTATE* enemyState, BULLETSTATE* enemyBulletState, FLAGSTATE* flags);

/**
*�v���C���[�̒e�R���g���[���֐�<br>
*�v���C���[�̒e�̔��˂Ɠ���̏���<br>
*@param[out] playerBulletState		�v���C���[�̒e�̏��
*@param[in] playerState				�v���C���[�̏��
*/
void PlayerBulletControl(BULLETSTATE* playerBulletState, PLAYERSTATE* playerState);

#endif