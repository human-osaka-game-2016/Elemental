/**
 * @file PlayerDraw.h
 * @breif ��l���̕`��t�@�C��
 
 * ��l���̕`��ɕK�v�ȃv���g�^�C�v�錾�������Ă���

 */

#ifndef PLAYERDRAW
#define PLAYERDRAW

////////////////////////////////////////////////
// ��`
////////////////////////////////////////////////

#define BULLET_MAX 3	//!< �U���ł���ő�l

////////////////////////////////////////////////
// �g�p����֐��̃v���g�^�C�v�錾
////////////////////////////////////////////////

/// ��l���̕`��֐�
/**
 * @return �Ȃ�
 */
void Player_Draw();
void Player_Aura_Draw(bool _auraFlag, float _texsize, GAMETEX _auratex);
void Player_Bullet_Draw();

#endif