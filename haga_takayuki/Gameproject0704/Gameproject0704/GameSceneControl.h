/**
*@file GameSceneControl.h
*@brief �Q�[���̑���⓮���Ɋւ���֐����܂Ƃ߂Ă���cpp�̃w�b�_�[�t�@�C��.
*/
#ifndef GAME_SCENE_CONTROL_H
#define	GAME_SCENE_CONTROL_H

/**�w�i�̓������x<br>*/
#define BG_MOVESPEED 1.f

/**�G�̊�{�X�s�[�h<br>*/
#define ENEMY_MOVESPEED 1.f
/**�G����ʊO���猻��鎞�̃X�s�[�h<br>*/
#define ENEMY_DOWN_MOVESPEED 2.f

/**�G�̒e�̃X�s�[�h<br>*/
#define ENEMY_BULLET_MOVESPEED 3.f
/**�G���m�̊Ԋu(x���W)<br>*/
#define ENEMY_POS_X 40.f
/**�G���m�̊Ԋu(y���W)<br>*/
#define ENEMY_POS_Y 32.f


/**�_���[�W��*/
#define LIFE_DAMEGE 1

/**�w�i�œ�����x�̌��E(��)<br>*/
#define BG_X_LEFT_LIMIT 130.f
/**�w�i�œ�����x�̌��E(�E)<br>*/
#define BG_X_RIGHT_LIMIT 350.f

/**�w�i�œ�����y�̌��E(��)<br>*/
#define BG_Y_UP_LIMIT 0.0f
/**�w�i�œ�����y�̌��E(��)<br>*/
#define BG_Y_DOWN_LIMIT 629.f

/**
*�Q�[���V�[���̃R���g���[�����܂Ƃ߂Ă���֐�<br>
*/
void GameControl(PLAYERSTATE* playerState, BULLETSTATE* playerBulletState, ENEMYSTATE* enemyState, BULLETSTATE* enemyBulletState, SCORESTATE* hiscore
	, BACKGROUNDSTATE*	backgroundState, FLAGSTATE* flags);

/**
*�w�i�R���g���[���֐�<br>
*/
void BgControl(BACKGROUNDSTATE*	backgroundState);

/**
*�^�C�g���R���g���[���֐�<br>
*/
void TitleSceneControl(FLAGSTATE* flags, PLAYERSTATE* playerState, ENEMYSTATE* enemyState, BULLETSTATE* playerBulletState, BULLETSTATE* enemyBulletState);

/**
�f�o�b�N�֐�<br>
*/
void GameDbug(PLAYERSTATE* playerState, SCORESTATE* hiscore, bool* gameEnd);
#endif