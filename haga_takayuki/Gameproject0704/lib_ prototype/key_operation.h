/**
@file key_operation.h
@brief DirectInput�������֐��ȁA�y�ё���֘A�֐����܂Ƃ߂Ă���cpp�̃w�b�_�[�t�@�C���ł�.
@author �F��M�V
@data 2016/06/18
*/

#ifndef KEY_OPERATION_H
#define KEY_OPERATION_H

#include <dinput.h>


/**
*�L�[�̎�ނ�񋓁B<br>
*KeyCheck�֐��Ŏg�p.
*@sa KeyCheck(BYTE DIK, KEYKIND st)
*/
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
	ESCAPE,
	SHIFT,
	SPACE,
	KEYMAX
};



/**
*�L�[�̏�ԂS��ނ��<br>
*KeyCheck�֐��Ŏg�p.
*@sa KeyCheck(BYTE DIK, KEYKIND st)
*/
enum KEYSTATE
{
	PUSH,/**<�L�[������*/
	RELEASE,/**<�L�[�𗣂�*/
	ON,/**<�L�[����������Ԃ������Ă���*/
	OFF/**<�L�[�𗣂�����Ԃ������Ă���*/
};

/**
*DirectInput�̏������֐�(�Ή��f�o�C�X�̓L�[�{�[�h�̂�).<br>
*��I�u�W�F�N�g�쐬,�f�o�C�X�쐬<br>
*��f�o�C�X���L�[�{�[�h�ɐݒ�<br>
*��������x���ݒ�.<br>
*@param[in]	hWnd		��E�B���h�E�n���h��
*@param[in]	g_pDInput	�DirectInput�I�u�W�F�N�g�|�C���^
*@param[in]	g_pkeyDevice	�DirectInput�f�o�C�X��I�u�W�F�N�g�|�C���^
*@retval S_OK	���� 
*@retval FALSE	���s 
*@note�}�E�X��W���C�X�e�B�b�N�̎�����������
*/
HRESULT InitDinput(HWND hWnd, LPDIRECTINPUT8* g_pDInput, LPDIRECTINPUTDEVICE8* g_pkeyDevice);

/**
*DIK���i�[����ϐ�.
*/
extern BYTE diks[256];

/**
*�L�[�̎�ނ��i�[����ϐ�.
*/
extern KEYSTATE Key[KEYMAX];

/**
*�����O�̏�Ԃ��i�[����ϐ�.
*0��������Ă��Ȃ�,1��������Ă����Ԃ�\���Ă���.
*/
extern int PreKey[KEYMAX];

/**
*�L�[�̏�Ԃ��m�F����֐�.<br>
*��L�[��������Ă��邩�`�F�b�N<br>
*��L�[�̏��(KEYSTATE�ŗ񋓂��Ă���)�̊m�F<br>
*@param[in]	DIK		�DIK���i�[
*@param[in] st		��L�[�̎�ނ��i�[
*@attention	�֐����g���O�Ƀ��C���Ńf�o�C�X�ւ̃A�N�Z�X�����l������Ă��邩�ēx�m�F���邱��.
*/
void KeyCheck(BYTE DIK, KEYKIND st);



#endif

