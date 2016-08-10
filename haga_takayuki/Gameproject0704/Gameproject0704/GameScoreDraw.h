/**
*@file GameScoreDraw.h
*@brief ����(�X�R�A�⃉�C�t)�̕`��Ɋւ���֐����܂Ƃ߂Ă���cpp�̃w�b�_�[�t�@�C��.
*/
#ifndef GAME_SCORE_DRAW_H
#define GAME_SCORE_DRAW_H


/**�X�R�A�̃e�N�X�`���[�T�C�Y<br>*/
#define SCORETEXSIZE 8.f

/**�Q�[�����ɕ\������X�R�A��1���ڂ�x���W<br>*/
#define GAMESCENESCORE_X 342.f
/**�Q�[�����ɕ\������X�R�A��1���ڂ�y���W<br>*/
#define GAMESCENESCORE_Y 13.f
/**�Q�[�����ɕ\������X�R�A��1����tu�l�̕ϓ���<br>*/
#define GAMESCENESCORE_TU 0.125f
/**�Q�[�����ɕ\������X�R�A��1����tv�l�̕ϓ���<br>*/
#define GAMESCENESCORE_TV 0.125f

/**�Q�[���X�R�A�̂P���̊Ԋux���W<br>*/
#define GAMESCORE_INTERVAL_X 2
/**�Q�[���X�R�A�̂P���̊Ԋuy���W<br>*/
#define GAMESCORE_INTERVAL_Y 4

/**�n�C�X�R�A�\��x���W*/
#define HISCORE_X 270.f
/**�n�C�X�R�A�\�����W*/
#define HISCORE_Y 350.f


/**���C�t�̕\��x���W*/
#define LIFE_X 128.f
/**���C�t�̕\��y���W*/
#define LIFE_Y 16.f

/**�Q�[���I������^�C�g���ڍs�ւ̑ҋ@����<br>*/
#define END_WAIT_TIME 350


/**�Q�[�����ɃX�R�A����ɕ`�悷��֐�<br>*/
void GameSceneScoreDraw(CUSTOMVERTEX* scorenumber, PLAYERSTATE* playerState);

/**�^�C�g���ɃX�R�A�����L���O��`�悷��֐�<br>*/
void GameSceneHiScoreDraw(CUSTOMVERTEX* scorenumber, SCORESTATE* hiscore);

/**���C�t�Q�[�W�`��*/
void LifeDraw(CUSTOMVERTEX* scorenumber, PLAYERSTATE* playerState);

//������`�悷��֐�
void DrawScoreNunber(int num, CUSTOMVERTEX* drawScoreVertex);

#endif