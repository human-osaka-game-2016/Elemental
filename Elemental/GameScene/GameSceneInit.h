/**
 * @file GameSceneInit.h
 * @breif �������t�@�C��

 * �������ɕK�v�Ȍ^�E�v���g�^�C�v�錾�Eextern�Ȃǂ������Ă���

 */

////////////////////////////////////////////////
// �^
////////////////////////////////////////////////

/// ��l���̗l�X�ȏ������\����
typedef struct
{
	float posX;			//!< ��l����X���W
	float posY;			//!< ��l����Y���W
	float acceleration;	//!< �W�����v����Ƃ��̉����x
	bool skyFlag;		//!< �󒆂ɂ��邩�ǂ����̃t���O
	bool jumpFlag;		//!< �W�����v���邩�ǂ����̃t���O
	bool drawFlag;		//!< ��l�����`�悳��邩�ǂ����̃t���O
	bool dashFlag;		//!< ��l�����_�b�V�����邩�ǂ����̃t���O
	bool hitFlag;		//!< ��l���������ɓ��Ă����́A�����ɓ��������ǂ����̃t���O
}PLAYER_STATE;

/// �G�̗l�X�ȏ������\����
typedef struct
{
	float posX;	//!< �G��X���W
	float posY; //!< �G��Y���W
}ENEMY_STATE;

/// �������̊֐�
/**
 * @return �Ȃ�
 */
void Init();

////////////////////////////////////////////////
// extern
////////////////////////////////////////////////

extern ENEMY_STATE g_enemy;		//!< �G�̗l�X�ȏ������\����
extern PLAYER_STATE g_player;   //!< ��l���̗l�X�ȏ������\����