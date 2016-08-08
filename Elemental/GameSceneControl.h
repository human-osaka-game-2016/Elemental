/**
 * @file GameSceneCntrol.h
 * @breif ����̊�ՂɂȂ�t�@�C��

 * �Q�[���S�̂̑���ɕK�v�Ȓ�`�E�v���g�^�C�v�錾�������Ă���

 */

#ifndef GAMESCENE_CONTROL
#define GAMESCENE_CONTROL

////////////////////////////////////////////////
// ��`
////////////////////////////////////////////////

#define MOVE_SPEED 4	//!< �L�����N�^�[�̓����X�s�[�h

////////////////////////////////////////////////
// �g�p����֐��̃v���g�^�C�v�錾
////////////////////////////////////////////////

/// 60fps�Ń��[�v�����鑀��֐�
/**
 * @return �Ȃ�
 */
void Control();

/// �ڂ̃V�X�e���̊֐�
/**
 * @return �Ȃ�
 */
void Map_Control();

/// �}�b�v�̓����蔻��̊֐�
/**
 * @param [in] _x	x���W
 * @param [in] _y	y���W
 * @param [in] _sx	�`�悷��L������X���̃`�b�v�̐�
 * @param [in] _sy	�`�悷��L������Y���̃`�b�v�̐�
 * @retval true		����Ƀ`�b�v�����݂��Ă���
 * @retval false	����Ƀ`�b�v�����݂��Ă��Ȃ�
 */
bool Map_Collision_Check(float _x, float _y, int _sx, int _sy);

///�@��`�̂����蔻��̊֐�
/**
 * abs�͐�Βl��Ԃ��֐��ł���
 * @param [in] _rectAX	1�ڂ̃I�u�W�F�N�g��X���W
 * @param [in] _rectBX	2�ڂ̃I�u�W�F�N�g��X���W
 * @param [in] _rectAY	1�ڂ̃I�u�W�F�N�g��Y���W
 * @param [in] _rectBY	2�ڂ̃I�u�W�F�N�g��Y���W
 * @param [in] _size	��`�̒��S�_���� ��/�Q �� ����/�Q ���������̃T�C�Y
 * @retval true			��ׂ��I�u�W�F�N�g�Ɠ������Ă���
 * @retval false		��ׂ��I�u�W�F�N�g�Ɠ������Ă��Ȃ�
 */
bool Collision_Check(float _rectAX, float _rectBX, float _rectAY, float _rectBY, int _size);

#endif