/**
 * @file Direct_Sound.h
 * @brief DirectX�̃T�E���h�Ɋ֌W����v���g�^�C�v�錾�������Ă���
 * @brief Wave�t�@�C�����Đ�����Ƃ������Ɏg����
 * @author �ēc�N��
 * @date 2016�N7��2��
 */

#ifndef DIRECT_SOUND
#define DIRECT_SOUND

#include <dsound.h>

////////////////////////////////////////////
// ���C���ɏ����K�v�̂���\�[�X
////////////////////////////////////////////

/*
�����WinMain�ɏ���
IDirectSoundBuffer8*�͍Đ����鉹�y�̐�����cpp�ɏ����Ă���
IDirectSoundBuffer8*�̉�����Y�ꂸ��
Play(0, �D�揇��, �Đ�������(���[�v��ԂȂ�))

*/

////////////////////////////////////////////
// �g�p����֐��̃v���g�^�C�v�錾
////////////////////////////////////////////

/// Wave�t�@�C���I�[�v���֐�
/**
 * @attention ���̊֐���WinMain�ɏ���
 * @param [out] _filepath	�����t�@�C���̖��O
 * @param [in]  _waveFormat	�o�b�t�@�[��Wave�t�H�[���t�H�[�}�b�g
 * @param [in]  _ppDate		pDate�̃A�h���X�ɉ��̃f�[�^���i�[����Ă���
 * @param [in]  _datesize	�V�����o�b�t�@�T�C�Y(�o�C�g�P��)
 * @retval true		�ǂݍ��ݐ���
 * @retval false	�ǂݍ��ݎ��s
 */
bool Open_Wave(TCHAR* _filename, WAVEFORMATEX* _waveformat, char** _ppData, DWORD* _dataSize);

/// �T�E���h�I�u�W�F�N�g�̐���
/**
 * @attention ���̊֐���WinMain�ɏ���
 * @param [in] _hWnd			�E�B���h�E�E�n���h��
 * @retval S_OK		�ǂݍ��ݐ���
 * @retval E_FAIL	�ǂݍ��ݎ��s
 */
HRESULT Init_Sound_Device(HWND _hWnd );

/// �T�E���h�o�b�t�@�[�̐���
/**
 * �Z�J���_���o�b�t�@��Wave�f�[�^��������
 * @attention ���̊֐���WinMain�ŏ���
 * @param [in] _filename		�����t�@�C���̖��O
 * @param [in] _ppDSBuffer		�T�E���h�o�b�t�@���Ǘ����邽�߂Ɏg��
 * @retval S_OK		�ǂݍ��ݐ���
 * @retval E_FAIL	�ǂݍ��ݎ��s
 */
HRESULT Create_Sound_Buffer(TCHAR* _filename, IDirectSoundBuffer8** _ppDSBuffer);

/// �T�E���h�̉���֐�
/**
 * �T�E���h�Ŏg���Ă�I�u�W�F�N�g��������Ă���
 * @return �Ȃ�
 */
void Sound_Free();

#endif