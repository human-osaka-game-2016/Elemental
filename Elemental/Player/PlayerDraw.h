/**
 * @file PlayerDraw.h
 * @breif ��l���̕`��t�@�C��
 
 * ��l���̕`��ɕK�v�ȃv���g�^�C�v�錾�������Ă���

 */

#ifndef PLAYERDRAW
#define PLAYERDRAW

#include <Direct_Draw.h>

////////////////////////////////////////////////
// ��`
////////////////////////////////////////////////

#define BULLET_MAX 3	//!< �U���ł���ő�l
#define BULLET_DISTAMCE 256//!< �e�̋����̏��

////////////////////////////////////////////////
// �g�p����֐��̃v���g�^�C�v�錾
////////////////////////////////////////////////

/// ��l�����I�[�����܂Ƃ��Ă����Ԃ̕`��֐�
/**
 * @return �Ȃ�
 */
void Player_Draw();

/// ��l���̏o���e�̕`��֐�
/**
* @return �Ȃ�
*/
void Player_Bullet_Draw();

/// �󒆂ɂ���Ƃ��̎�l����`�悷��
/**
 * @return �Ȃ�
 */
void Player_Sky_Draw();

/// ��l���̏�Ԃɍ��킹�ĕ`�悷��֐�
/**
 * @return �Ȃ�
 */
void Player_Case_Draw(CUSTOMVERTEX playerdraw[]);

/// �󒆂ɂ���Ƃ��̏�Ԃɍ��킹�ĕ`�悷��֐�
/*
 
 */
void Player_Sky_Case_Draw(CUSTOMVERTEX playerskydraw[]);

void Player_Init();

#endif