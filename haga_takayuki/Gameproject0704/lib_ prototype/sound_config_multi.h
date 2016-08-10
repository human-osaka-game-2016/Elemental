/**
*@file sound_config_multi.h
*@brief DirectShow���g�p���ăT�E���h���Đ�����֐����܂Ƃ߂Ă���cpp�̃w�b�_�[�t�@�C���ł�.<br>
*�������MP3��WAVE�t�@�C���ǂ�����Đ��\�ł�.<br>
*@author �F��M�V
*@date 2016/06/25
*/
#ifndef SOUND_CONFIG_MULTI_H
#define SOUND_CONFIG_MULTI_H
#include <dSound.h>
#include <dshow.h>
#include"config.h"

/**
*�����Đ����Ă��邩�̃t���O<br>
*/
extern bool isPlay;

/**
*�������[�v���邩�̃t���O<br>
*/
extern bool isRoopMode;

/**
*�T�E���h�t�@�C���ǂݍ��݂��邽�߂̊֐�.
*�COM�������A�y�уI�u�W�F�N�g�쐬
*��T�E���h�t�@�C���ǂݍ���.
*@attention �K�����̃t�@�C�����g���ĉ���ǂݍ���
*@param[in]	**pGraphBuilder		��t�B���^�̒ǉ���폜�A������������C���^�[�t�F�C�X�̃|�C���^
*@param[in]	**pMediaControl		��L���v�`���̎��s����̃C���^�[�t�F�C�X�̃|�C���^
*@param[in]	**pMediaPosition	��X�g���[�����̈ʒu���V�[�N���郁�\�b�h�����C���^�[�t�F�C�X�̃|�C���^
*@param[in]	file	��T�E���h�t�@�C��
*/
void LoadSoundFile(IGraphBuilder	**pGraphBuilder, IMediaControl	**pMediaControl, IMediaPosition	**pMediaPosition, BSTR file);

/**
*�ʏ�Đ��֐�(�P�񂾂��Đ�).
*@param[in]	**pMediaControl		��L���v�`���̎��s����̃C���^�[�t�F�C�X�̃|�C���^�̃|�C���^
*/
void PlayNormalSound(IMediaControl	**pMediaControl);

/**
*���[�v�Đ��֐�(���[�v�̃t���O�𗧂Ă�).
*@param[in]	**pMediaControl		��L���v�`���̎��s����̃C���^�[�t�F�C�X�̃|�C���^�̃|�C���^
*/
void PlayRoopSound(IMediaControl	**pMediaControl);

/**
*�t���O���`�F�b�N���āA���[�v�Đ�����֐�.
*@param[in]	**pMediaControl		��L���v�`���̎��s����̃C���^�[�t�F�C�X�̃|�C���^
*@param[in]	**pMediaPosition	��X�g���[�����̈ʒu���V�[�N���郁�\�b�h�����C���^�[�t�F�C�X�̃|�C���^
*/
void CheckRoopSound(IMediaControl	**pMediaControl, IMediaPosition **pMediaPosition);

/**
*�Đ����̏ꍇ�ł��擪�ɖ߂��čĐ��������֐�.
*@param[in]	**pMediaControl		��L���v�`���̎��s����̃C���^�[�t�F�C�X�̃|�C���^
*@param[in]	**pMediaPosition	��X�g���[�����̈ʒu���V�[�N���郁�\�b�h�����C���^�[�t�F�C�X�̃|�C���^
*@note	���ʉ��ȂǂɎg�p���₷��
*/
void PlayFormStartSound(IMediaControl	**pMediaControl, IMediaPosition **pMediaPosition);

/**
*�T�E���h���ꎞ��~����֐�(�r������Đ������Ԃɂ���).
*@param[in]	**pMediaControl		��L���v�`���̎��s����̃C���^�[�t�F�C�X�̃|�C���^
*/
void PauseSound(IMediaControl **pMediaControl);

/**
*�T�E���h���~����֐�(�ŏ�����Đ������Ԃɂ���).<br>
*@param[in]	**pMediaControl		��L���v�`���̎��s����̃C���^�[�t�F�C�X�̃|�C���^
*@param[in]	**pMediaPosition	��X�g���[�����̈ʒu���V�[�N���郁�\�b�h�����C���^�[�t�F�C�X�̃|�C���^
*/
void StopSound(IMediaControl	**pMediaControl, IMediaPosition **pMediaPosition);

/**
*�T�E���h�̃{�����[�����グ��֐�.<br>
*@param[in]	**pGraphBuilder		��t�B���^�̒ǉ���폜�A������������C���^�[�t�F�C�X�̃|�C���^
*/
void VolUpSound(IGraphBuilder	**pGraphBuilder);

/**
*�T�E���h�̃{�����[����������֐�.<br>
*@param[in]	**pGraphBuilder		��t�B���^�̒ǉ���폜�A������������C���^�[�t�F�C�X�̃|�C���^
*/
void VolDownSound(IGraphBuilder	**pGraphBuilder);


#endif