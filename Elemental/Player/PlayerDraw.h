/**
 * @file PlayerDraw.h
 * @breif ��l���̕`��t�@�C��
 
 * ��l���̕`��ɕK�v�ȃv���g�^�C�v�錾�������Ă���

 */

#ifndef PLAYERDRAW
#define PLAYERDRAW

#include "../GameScene/GameSceneDraw.h"

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

/// ��l�����I�[�����܂Ƃ��Ă����Ԃ̕`��֐�
/**
 * @param [in] _auraFlag	�ǂ̃I�[����`�悷�邩
 * @param [in] _auratex�@	�ǂ̃I�[���ɉ摜�����蓖�Ă邩
 * @return �Ȃ�
 */
void Player_Aura_Draw(bool _auraFlag, bool _moveflag, bool _leftflag, GAMETEX _auratex);

/// ��l���̏o���e�̕`��֐�
/**
* @return �Ȃ�
*/
void Player_Bullet_Draw();

#endif