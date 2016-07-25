/**
 * @file Direct_Key_Input.h
 * @brief DirectX�̃L�[�Ɋ֌W����^�E�v���g�^�C�v�錾�������Ă���
 * @author �ēc�N��
 * @date 2016�N7��1��
 */

#ifndef DIRECT_KEY_INPUT
#define DIRECT_KEY_INPUT


////////////////////////////////////////////
// �^
////////////////////////////////////////////

/// �L�[�̎��
enum  KEYKIND
{
	LEFT,		
	RIGHT,
	UP,
	DOWN,
	A,
	B,
	C,
	D,
	E,
	F,
	G,
	H,
	I,
	J,
	K,
	L,
	M,
	N,
	O,
	P,
	Q,
	R,
	S,
	T,
	U,
	V,
	W,
	X,
	Y,
	Z,
	SHIFT,
	SPACE,
	KEYMAX		///<�i�[���Ă�L�[�̍ő�l
};

/// �L�[�̏��
enum KEYSTATE
{
	PUSH,		///<�L�[���������u��
	RELEASE,	///<�L�[�𗣂����u��
	ON,			///<���������Ă���Ƃ�
	OFF			///<���������Ă���Ƃ�
};

////////////////////////////////////////////
// �錾
////////////////////////////////////////////

extern KEYSTATE			  g_Key[KEYMAX];						///<KEYSTATE��KEYKIND�̑S�Ă�z��Ƃ��Ċi�[���Ă���


////////////////////////////////////////////
// �g�p����֐��̃v���g�^�C�v�錾
////////////////////////////////////////////

/// �_�C���N�g�C���v�b�g�̏������֐�
/**
 * @attention ���̊֐���WinMain�ɏ���
 * @param [in] hWnd �E�B���h�E�E�n���h��
 * @retval  S_OK	�ǂݍ��ݐ���
 * @retval  E_FAIL	�ǂݍ��ݎ��s
 */
HRESULT Init_Direct_Input(HWND _hWnd);	

/// �L�[�{�[�h�̏�Ԃ��擾���Ă��邩�̊m�F�̊֐�
/** 
 * @attention �������������Ă��Ȃ���΃L�[�͈�ؓ����Ȃ�
 * @return �Ȃ�
 */
void Get_Key_State();

/// ������Ă���L�[���m�F����֐�
/** 
 * @param [in] DIK �L�[�{�[�h�ŉ�����͂�����
 * @param [in] st KEYKIND�Ɋi�[����Ă�L�[�̎�ނ̊m�F
 * @return �Ȃ�
 */
void Check_Key(int _dik, KEYKIND _st);

/// �L�[����̉���֐�
/**
 * �L�[����Ŏg���Ă�I�u�W�F�N�g��������Ă���
 * @return	�Ȃ�
 */
void Key_Free();

#endif