/**
*@file sound_config_wave.h
*@brief Wave�`���̃T�E���h���g�p����ׂ̊֐����܂Ƃ߂Ă���cpp�̃w�b�_�[�t�@�C���ł�.
*@attention wave�t�@�C���̂ݑΉ�
*@author �F��M�V
*@date 2016/06/25
*/
#ifndef SOUND_CONFIG_WAVE_H
#define SOUND_CONFIG_WAVE_H
#include <dSound.h>
#include <dshow.h>
#include"config.h"

/**
wave�t�@�C���Ɋ֘A����֐�.<br>
*�Ewave�t�@�C���I�[�v��<br>
*�ERIFF�`�����N,�t�H�[�}�b�g�`�����N,�f�[�^�`�����N����.<br>
*���̊֐��͉��L�̎Q�Ƃ��Ă���֐��ƃZ�b�g�ŉ^�p����.
*@sa SoundWave(HWND hWnd, char** pwaveData, DWORD* dataSize, WAVEFORMATEX* waveFormatEx, int playback_method)
*@param[in]	filepath	�wave�`���̉��̃t�@�C����
*@param[in]	waveFormatEx	�WAVEFORMATEX�\����
*@param[out] pwaveData		��g�`�f�[�^
*@param[out] dataSize	��Z�J���_���o�b�t�@�Ŋm�ۂ���T�C�Y
*@retval SUCCESS_VALUE  ����
*@retval ERROR_VALUE	���s
*/
int OpenWave(TCHAR* filepath, WAVEFORMATEX* waveFormatEx, char** pwaveData, DWORD* dataSize);

/**
*�T�E���h�f�o�C�X�Ɋ֘A����֐�.<br>
*�E�T�E���h�f�o�C�X�쐬,�������x���ݒ�<br>
*�E�Z�J���_���o�b�t�@�쐬<br>
*�E�Z�J���_���o�b�t�@��Wave�f�[�^��������<br>
*�E���̍Đ�.<br>
*@attention ���̊֐����g�p����ɂ͉͂��L�̎Q�Ɗ֐���wave�t�@�C�����J�����Ƃ��K�{.
*@sa OpenWave(TCHAR* filepath, WAVEFORMATEX* waveFormatEx, char** pwaveData, DWORD* dataSize)
*@param[in] hWnd		��E�B���h�E�n���h��
*@param[in]	pwaveData	��g�`�f�[�^
*@param[in]	dataSize	��Z�J���_���o�b�t�@�Ŋm�ۂ���T�C�Y
*@param[in]	waveFormatEx	�WAVEFORMATEX�\����
*@param[in] playback_method		��Đ����@	
*/
void SoundWave(HWND hWnd, char** pwaveData, DWORD* dataSize, WAVEFORMATEX* waveFormatEx, int playback_method);


#endif