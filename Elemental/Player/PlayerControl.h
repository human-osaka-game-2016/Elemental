/**
 * @file PlayerCntrol.h
 * @breif ��l���̑���t�@�C��

 * ��l���̑���ɕK�v�Ȓ�`�E�v���g�^�C�v�錾�������Ă���

 */

#ifndef PLAYERCONTROL
#define PLAYERCONTROL

////////////////////////////////////////////////
// ��`
////////////////////////////////////////////////

#define WALK_SPEED		4		//!< �L�����N�^�[�̓����X�s�[�h
#define RUN_SPEED		6		//!< �L�����N�^�[�̑���X�s�[�h
#define JUMP_POWER		-16.f	//!< �����܂Ŕ�ׂ�l
#define GRAVITY			0.4f	//!< ���̒l���オ�����艺�������肷��
#define BULLET_SPEED	8		//!< ��l������o�����e�̑��x

////////////////////////////////////////////////
//�g�p����֐��̃v���g�^�C�v�錾
////////////////////////////////////////////////

/// ��l���̑���֐�
/**
 * @return �Ȃ�
 */
void Player_Control();
void Player_Flame_Control();
void Player_Ice_Control();
void Player_Wind_Control();
//void Player_aura_Control(KEYKIND _st, bool _auraflag);
void Player_Bullet_Control();

#endif