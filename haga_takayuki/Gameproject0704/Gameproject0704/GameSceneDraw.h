/**
*@file GameSceneDraw.h
*@brief �Q�[���̕`��֘A���܂Ƃ߂Ă���cpp�̃w�b�_�[�t�@�C��.
*/
#ifndef GAME_SCENE_DRAW_H
#define GAME_SCENE_DRAW_H

/**�w�i��<br>*/
#define BACKGROUND_W 224.f
/**�w�i����<br>*/
#define BACKGROUND_H 640.f

/**�e�L�X�g�T�C�Y*/
#define TEXT_SIZE 224.f
/**�e�L�X�g��x�������ʒu*/
#define TEXT_X_POS 128.f
/**�e�L�X�g��y�������ʒu*/
#define TEXT_Y_POS 150.f

/**�e�N�X�`���[�X�P�[���̊�{�l<br>*/
#define TEXSIZE 32.f
/**�����G�t�F�N�g�̊�{�X�P�[��*/
#define EFECTTEXSIZE 32.f

/**�����A�j���[�V����tu�l�ω���<br>*/
#define ANIMETION_TU 0.25.f
/**�����A�j���[�V�������ԊԊu��<br>*/
#define ANIMETION_TIME 5

/**�e�L�X�g�\�����ԊԊu��<br>*/
#define TEXT_TIME 60
/**�e�L�X�g��tv�l�̕ω���<br>*/
#define TEXT_TV 0.5f

/**�G�̔z�u�̊Ԋu<br>*/
#define ENEMY_POS_Y 32.f


/**�Q�[���̕`��֐�<br>*/
void GameDraw(PLAYERSTATE* playerState, BULLETSTATE* playerBulletState, ENEMYSTATE* enemyState, BULLETSTATE* enemyBulletState, BACKGROUNDSTATE*	backgroundState, SCORESTATE* hiscore, FLAGSTATE* flags);

/**�w�i�`��֐�<br>*/
void BgDraw(BACKGROUNDSTATE* backgroundState);

/**�^�C�g���`��֐�<br>*/
void TitleDraw(FLAGSTATE* flags);

/**
*�e�L�X�g�`��֐�.<br>
*�e�L�X�g�����̓e�L�X�g�uZ�{�^���������Ăˁv�E�uGAME OVER�v<br>
*/
void Text01Draw(TEXTSTATE* textState, FLAGSTATE* flags);

/**
*�e�L�X�g�`��֐�.<br>
*�e�L�X�g�����̓e�L�X�g�uComplete�v�E�uWARNING�v<br>
*/
void Text02Draw(TEXTSTATE* textState, FLAGSTATE* flags);

#endif
