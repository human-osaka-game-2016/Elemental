// �L�[���삷�邽�߂ɕK�v�ȃC���N���[�h
#include <dinput.h>
// ���색�C�u�����̃C���N���[�h
#include <Direct_Draw.h>
#include <Direct_Key_Input.h>
// �����̃w�b�_�[
#include "GameSceneDraw.h"
#include "GameSceneCntrol.h"


// 60�t���[���ŌĂ΂��L�[�̊֐�
void Control()
{
	// ��������邱�Ƃɂ���ăL�[�{�[�h���Q�[����t�ς���悤�ɂȂ�
	Get_Key_State();

	// �_�C���N�g�C���v�b�g�̉��z�̃L�[�ŉ���������Ă��邩�̊m�F�����Ă���
	Check_Key(DIK_LEFT, LEFT);
	Check_Key(DIK_RIGHT, RIGHT);

	Player_Control();
}

//�@����̓}�b�v�̑S�̂����邽�߂ɂ����g���Ă܂��񂪖��O�̂悤�ɂ����Ƀv���C���[����n�̏����������܂�
void Player_Control()
{
	if (g_Key[LEFT] == ON)
	{
		// ���������ꂽ��}�b�v�����ɓ���
		for (int i = 0; i < 4; i++)
		{
			g_maptip[i].m_x += MOVE_SPEED;
		}
	}

	if (g_Key[RIGHT] == ON)
	{
		// �E�������ꂽ��}�b�v���E�ɓ���
		for (int i = 0; i < 4; i++)
		{
			g_maptip[i].m_x -= MOVE_SPEED;
		}
	}
}
