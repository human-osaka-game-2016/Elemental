/**
*@file GamePlayerDraw.h
*@brief �Q�[���ɂ�����v���C���[�A�v���C���[�̒e�A�y�уv���C���[�̔����A�j���[�V�����̕`��֐����܂Ƃ߂��w�b�_�[�t�@�C���ł�.
*/

#ifndef GAME_PLAYER_DRAW_H
#define GAME_PLAYER_DRAW_H

/**�v���C���[�`��֐�<br>*/
void PlayDraw(CUSTOMVERTEX* player, PLAYERSTATE* playerState);

/**�v���C���[�e�̕`��֐�<br>*/
void PlayerBulletDraw(CUSTOMVERTEX* player, BULLETSTATE* playerBulletState, PLAYERSTATE* playerState);

/**�����A�j���[�V����(�v���C���[)�`��֐�<br>*/
void ExplosionAnimePlayer(CUSTOMVERTEX* player, PLAYERSTATE* playerState);

#endif