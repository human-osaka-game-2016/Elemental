/**
*@file GameSceneInit.h
*@brief �Q�[���V�[���ɂ����鏉�����֐����܂Ƃ߂�cpp�̃w�b�_�[�t�@�C���ł�.
*�w�i��G��v���C���[�̏������W��������#define���Ă���<br>
*/
#ifndef GAME_SCENE_INIT_H
#define GAME_SCENE_INIT_H

/**�w�i��x���W�ɂ����鏉���ʒu<br>*/
#define BACKGROUND_X_DEFU 128.f
/**�w�i��y���W�ɂ����鏉���ʒu<br>*/
#define BACKGROUND_Y_DEFU 640.f

/**�v���C���[�̎c�@�����l<br>*/
#define PLAYER_LIFE_DEFU 3
/**�v���C���[�̃X�R�A�����l<br>*/
#define PLAYER_SCORE_DEFU 0
/**�v���C���[��x���W�̏����l<br>*/
#define PLAYER_X_DEFU 240.f
/**�v���C���[��y���W�̏����l<br>*/
#define PLAYER_Y_DEFU 608.f

/**�G�̌��ގ��ɓ���X�R�A<br>*/
#define ENEMY_SCORE_DEFU 100
/**�G��x���W�̏����l(1�̖�)<br>*/
#define ENEMY_X_DEFU 198.f
/**�G��y���W�̏����l(1�̖�)<br>*/
#define ENEMY_Y_DEFU 70.f

/**
*�`��ݒ襍��W�������E�摜�ǂݍ��݊֐�<br>
*�`��ݒ�ƕϐ��̏������A�y�щ摜�̓ǂݍ��݂Ƃ������Q�[���̏������֘A���s���֐�<br>
*@param[out] playerState		�v���C���[�̏��
*@param[out] playerBulletState	�v���C���[�̒e���
*@param[out] enemyState			�G�̏��
*@param[out] enemyBulletState	�G�̒e���
*@param[out] backgroundState01	�w�i1���ڂ̍��W���
*@param[out] backgroundState02	�w�i2���ڂ̍��W���
*@param[out] hiscore			�n�C�X�R�A���i�[����z��
*@param[out] flags				�t���O�\����
*/
void InitGameScene(PLAYERSTATE* playerState, BULLETSTATE* playerBulletState, ENEMYSTATE* enemyState, BULLETSTATE* enemyBulletState, BACKGROUNDSTATE* backgroundState, SCORESTATE* hiscore, FLAGSTATE* flags);


#endif