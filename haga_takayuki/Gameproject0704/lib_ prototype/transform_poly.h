/**
*@file transform_poly.h
*@brief �g��E�k���E��]�Ɋւ���֐����܂Ƃ߂Ă���cpp�̃w�b�_�[�t�@�C���ł�.
*��{�I�ɂ͍s���p�����֐����g�p����.
*@author �F��M�V
*@data 2016/06/29
*/
#ifndef TRANSFORM_POLY_H
#define TRANSFORM_POLY_H
#include  <d3dx9math.h>
#include"draw_config.h"

/**
*�~����<br>
*���W�A�������߂�̂ɕK�v�Ƃ����<br>
*@sa	Rotation(CUSTOMVERTEX* texture, int deg)
*@sa	RotationMatrix(CUSTOMVERTEX* texture, int deg, int axis)	
*/
#define PI  3.141592f

/**
*��]�ɂ����Ē��S�ɂ��鎲��3��<br>
*�Q�Ɗ֐��̈����ɂĎg�p<br>
*@sa RotationMatrix(CUSTOMVERTEX* texture, int deg, int axis)
*/
enum AXIS
{
	X_AXIS,		/**<x��*/
	Y_AXIS,		/**<y��*/
	Z_AXIS		/**<z��*/
};


/**
*�|���S���̊g��Ək�����s���֐�<br>
*�g��A�y�яk�����������{�����w�肵�čs��<br>
*��:2�{�g�債�����Ȃ�2�A2����1�ɏk���������Ȃ�0.5���킽��.<br>
*@param[out] vertex		��������s�������J�X�^���o�[�e�b�N�X�^�̍\����
*@param[in] multiple	��{��
*/
void Zoom(CUSTOMVERTEX* vertex, float multiple);

/**
*�|���S���̉�]���s���֐�<br>
*��]�������p�x���w�肷��<br>
*�p�x��+�l���ƍ���]�A-�l���ƉE��]���s��.<br>
*@param[out] vertex		��������s�������J�X�^���o�[�e�b�N�X�^�̍\����
*@param[in] deg		���]�������p�x
*/
void Rotation(CUSTOMVERTEX* vertex, int deg);

/**
*�|���S�����s��ňړ�������֐�<br>
*�s����g�p���ă|���S����C�ӂ̈ʒu�ֈړ�������.<br>
*@param[out] vertex		��������s�������J�X�^���o�[�e�b�N�X�^�̍\����
*@param[in] cx		����̊֐��̈����ł���J�X�^���o�[�e�b�N�X�^�̍\���̂̒��S��x���W
*@param[in]	cy		����̊֐��̈����ł���J�X�^���o�[�e�b�N�X�^�̍\���̂̒��S��y���W
*@param[in]	cz		����̊֐��̈����ł���J�X�^���o�[�e�b�N�X�^�̍\���̂̒��S��z���W
*/
void MoveMatrix(CUSTOMVERTEX* vertex, float cx, float cy, float cz);

/**
*�s����g�p���Ċg��E�k�����s���֐�<br>
*x,y,z���ꂼ��g��A�y�яk�����������{�����w�肵�čs��.<br>
*@note �񎟌��ŏ������s���ꍇ�͊�{z�̔{����1
*@param[out] vertex		��������s�������J�X�^���o�[�e�b�N�X�^�̍\����
*@param[in] multipleX	�x���W�ɏ�������{��
*@param[in] multipleY	�y���W�ɏ�������{��
*@param[in] multipleZ	�z���W�ɏ�������{��
*/
void ZoomMatrix(CUSTOMVERTEX* vertex, float multipleX, float multipleY, float multipleZ);

/**
*�s����g�p���ĉ�]���s���֐�<br>
*��]���������Ɗp�x���w�肷��<br>
*�p�x��+�l���ƉE��]�A-�l���ƍ���]���s��.<br>
*@attention ���L�̉�]�֐��Ƃ�+,-�ł̉�]���t�Ȃ̂Œ���
*@sa Rotation(CUSTOMVERTEX* vertex, int deg)
*@param[out] vertex		��������s�������J�X�^���o�[�e�b�N�X�^�̍\����
*@param[in]	deg		���]�������p�x
*@param[in]	axis	���]�̒��S�ɂ�������
*/
void RotationMatrix(CUSTOMVERTEX* vertex, int deg, int axis);

#endif