/**
 * @file GameSceneInit.h
 * @breif �������t�@�C��

 * �������ɕK�v�Ȍ^�E�v���g�^�C�v�錾�Eextern�Ȃǂ������Ă���

 */

#include <Direct_Draw.h>
#include "../Player/PlayerDraw.h"

////////////////////////////////////////////////
// �^
////////////////////////////////////////////////

/// ��l���̗l�X�ȏ������\����
typedef struct
{
	float posX;				//!< ��l����X���W
	float posY;				//!< ��l����Y���W
	float acceleration;		//!< �W�����v����Ƃ��̉����x
	bool drawFlag;			//!< ��l�����`�悳��邩�ǂ����̃t���O
	bool moveFlag;
	bool leftFlag;
	bool skyFlag;			//!< �󒆂ɂ��邩�ǂ����̃t���O
	bool jumpFlag;			//!< �W�����v���邩�ǂ����̃t���O
	bool rightdashFlag;		//!< ��l�����E�Ƀ_�b�V�����邩�ǂ����̃t���O
	bool leftdashFlag;		//!< ��l�������Ƀ_�b�V�����邩�ǂ����̃t���O
	bool hitFlag;			//!< ��l���������ɓ��Ă����́A�����ɓ��������ǂ����̃t���O
	bool flamedrawFlag;		//!< ���̃I�[���̎�l����`�悷�邩�ǂ����̃t���O
	bool icedrawFlag;		//!< ���̃I�[���̎�l����`�悷�邩�ǂ����̃t���O
	bool winddrawFlag;		//!< ����(��)�̃I�[���̎�l����`�悷�邩�ǂ����̃t���O
	bool animationFlag;

}PLAYER_STATE;

/// �G�̗l�X�ȏ������\����
typedef struct
{
	float posX;		//!< �G��X���W
	float posY;		//!< �G��Y���W
	bool drawFlag;
	bool hitFlag;	//!< �����������������ǂ����̃t���O

}ENEMY_STATE;

typedef struct
{
	CUSTOMVERTEX bullet[4];		//!< ���ꂽ�ق����������y�ɂȂ邽��
	float posX;					//!< �e��X���W
	float posY;					//!< �e��Y���W
	bool initFlag;				//!< �e�̏������̃t���O
	bool drawFlag;				//!< �e�̕`��̃t���O

}BULLET_STATE;

/// �������̊֐�
/**
 * @return �Ȃ�
 */
void Init();

////////////////////////////////////////////////
// extern
////////////////////////////////////////////////

extern ENEMY_STATE g_kodora[KODORA_MAX];	//!< �G�̗l�X�ȏ������\����
extern PLAYER_STATE g_player;				//!< ��l���̗l�X�ȏ������\����
extern BULLET_STATE g_bullet[BULLET_MAX];	//!< �e�̗l�X�ȏ������\���̂̔z��