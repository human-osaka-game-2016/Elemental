/**
 * @file EnemyControl.h
 * @breif �G�̑���t�@�C��

 * �S�Ă̓G�̑���ɕK�v�ȃv���g�^�C�v�錾�������Ă���

 */

#ifndef ENEMYCONTROL
#define ENEMYCONTROL

#define ENEMY_WALK 2	//!< �G�̕����X�s�[�h

////////////////////////////////////////////////
//�g�p����֐��̃v���g�^�C�v�錾
////////////////////////////////////////////////

/// �R�h���̑���֐�
/**
 * @return �Ȃ�
 */
void Kodora_Control();

/// �X�P���g���̑���֐�
/**
 * @return �Ȃ�
 */
void skeleton_Control();

/// �X���C���̑���֐�
/**
 * @return �Ȃ�
 */
void Slime_Control();

#endif