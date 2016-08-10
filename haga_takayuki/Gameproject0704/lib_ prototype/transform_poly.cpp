/**
*@file transform_poly.cpp
*@brief �g��E�k���E��]�Ɋւ���֐����܂Ƃ߂Ă���cpp�t�@�C���ł�.
*��{�I�ɂ͍s���p�����֐����g�p����.
*@author �F��M�V
*@data 2016/06/29
*/
#include <d3dx9math.h>
#include"draw_config.h"
#include"transform_poly.h"



/*
���C�u����
#pragma comment ( lib, "d3dx9.lib" )
*/


//�g��E�k���֐�
void Zoom(CUSTOMVERTEX* vertex, float multiple)
{
	float cx;		//���S���W��x���W���i�[����ϐ�
	float cy;		//���S���W��y���W���i�[����ϐ�


	//���S���W�����߂�
	cx = (vertex[2].x - vertex[0].x) / 2.0f + vertex[0].x;
	cy = (vertex[2].y - vertex[0].y) / 2.0f + vertex[0].y;

	//�g��A�������͏k��������
	for (int i = 0; i < 4; i++)
	{
		float fx = 0.0f;
		float fy = 0.0f;

		fx = vertex[i].x * multiple + cx;
		fy = vertex[i].y * multiple + cy;

		vertex[i].x = fx;
		vertex[i].y = fy;

	}
}


//��]�֐�
void Rotation(CUSTOMVERTEX* vertex, int deg)
{
	float cx;		//���S���W��x���W���i�[����ϐ�
	float cy;		//���S���W��y���W���i�[����ϐ�

	//���W�A�������߂�
	float rd = (float)-deg * PI / 180.0f;

	//���S���W�����߂�
	cx = (vertex[2].x - vertex[0].x) / 2.0f + vertex[0].x;
	cy = (vertex[2].y - vertex[0].y) / 2.0f + vertex[0].y;

	//��]������
	for (int i = 0; i < 4; i++)
	{
		float fx = 0.0f;		//�ό`����x���W���ꎞ�I�ɕێ����邽�߂̕ϐ�
		float fy = 0.0f;		//�ό`����y���W���ꎞ�I�ɕێ����邽�߂̕ϐ�

		fx = (vertex[i].x - cx) * cos(rd) - (vertex[i].y - cy) * sin(rd) + cx;
		fy = (vertex[i].x - cx) * sin(rd) + (vertex[i].y - cy) * cos(rd) + cy;

		vertex[i].x = fx;
		vertex[i].y = fy;

	}

}


//�s��ňړ�������֐�
void MoveMatrix(CUSTOMVERTEX* vertex, float cx, float cy, float cz)
{
	D3DXMATRIX PosMatrix;
	D3DXMATRIX MoveMatrix;

	//�s��̏�����
	D3DXMatrixIdentity(&PosMatrix);
	D3DXMatrixIdentity(&MoveMatrix);

	//�ړ��ʐݒ�
	D3DXMatrixTranslation(&MoveMatrix, cx, cy, cz);

	//�ړ�����
	for (int i = 0; i < 4; i++)
	{
		//���݂̒��_���W���i�[
		D3DXMatrixTranslation(&PosMatrix, vertex[i].x, vertex[i].y, vertex[i].z);
		//�ړ�
		PosMatrix *= MoveMatrix;
		//���ʂ�Ԃ�
		vertex[i].x = PosMatrix._41;
		vertex[i].y = PosMatrix._42;
		vertex[i].z = PosMatrix._43;
	}

}


//�s����g�p�����g��E�k���֐�
void ZoomMatrix(CUSTOMVERTEX* vertex, float multipleX, float multipleY, float multipleZ)
{
	D3DXMATRIX PosMatrix;		// ���_�s��
	D3DXMATRIX MultipleMatrix;	// �g��E�k���s��

	float cx = 0;		//���S���W��x���W���i�[����ϐ�
	float cy = 0;		//�ό`����y���W���ꎞ�I�ɕێ����邽�߂̕ϐ�

	//�摜�̒��S���W�����߂�
	cx = (vertex[2].x - vertex[0].x) / 2.0f + vertex[0].x;
	cy = (vertex[2].y - vertex[0].y) / 2.0f + vertex[0].y;

	//���_�ֈړ�������
	MoveMatrix(vertex, -cx, -cy, 0.0f);

	// �s��̏������i�P�ʍs�񐶐��j
	D3DXMatrixIdentity(&PosMatrix);
	D3DXMatrixIdentity(&MultipleMatrix);



	//x ���Ay ���Az ���ɉ����ăX�P�[�����O����s����쐬����B(�g��E�k���̏ꍇ��multipleZ��1)
	D3DXMatrixScaling(&MultipleMatrix, multipleX, multipleY, multipleZ);

	// �g��E�k������
	for (int i = 0; i<4; i++)
	{
		// ���݂̒��_���W���i�[
		D3DXMatrixTranslation(&PosMatrix, vertex[i].x, vertex[i].y, vertex[i].z);
		// �g��A�܂��͏k��
		PosMatrix *= MultipleMatrix;
		// ���ʂ�߂�
		vertex[i].x = PosMatrix._41;
		vertex[i].y = PosMatrix._42;
		vertex[i].z = PosMatrix._43;
	}

	//���̈ʒu�Ɉړ�������
	MoveMatrix(vertex, cx, cy, 0.0f);
}


//�s����g�p������]�֐��i+���ƉE��]�A-���ƍ���])
void RotationMatrix(CUSTOMVERTEX* vertex, int deg, int axis)
{
	float PAD = 3.141592f / 180.0f; // ���W�A���̏�����
	D3DXMATRIX PosMatrix;		// ���_�s��
	D3DXMATRIX RotateMatrix;	// ��]�s��

	float cx = 0;		//���S���W��x���W���i�[����ϐ�
	float cy = 0;		//�ό`����y���W���ꎞ�I�ɕێ����邽�߂̕ϐ�

	//�摜�̒��S���W�����߂�
	cx = (vertex[2].x - vertex[0].x) / 2.0f + vertex[0].x;
	cy = (vertex[2].y - vertex[0].y) / 2.0f + vertex[0].y;

	//���_�ֈړ�������
	MoveMatrix(vertex, -cx, -cy, 0.0f);



	// �s��̏������i�P�ʍs�񐶐��j
	D3DXMatrixIdentity(&PosMatrix);
	D3DXMatrixIdentity(&RotateMatrix);

	// ��]�s��ɂ܂킷���Ɗp�x��ݒ�
	switch (axis)
	{
	case X_AXIS:
		D3DXMatrixRotationX(&RotateMatrix, (float)deg * PAD);
		break;

	case Y_AXIS:
		D3DXMatrixRotationY(&RotateMatrix, (float)deg * PAD);
		break;

	case Z_AXIS:
		D3DXMatrixRotationZ(&RotateMatrix, (float)deg * PAD);
		break;
	}
	

	// ��]����
	for (int i = 0; i<4; i++)
	{
		// ���݂̒��_���W���i�[
		D3DXMatrixTranslation(&PosMatrix, vertex[i].x, vertex[i].y, vertex[i].z);
		// ��]
		PosMatrix *= RotateMatrix;
		// ���ʂ�߂�
		vertex[i].x = PosMatrix._41;
		vertex[i].y = PosMatrix._42;
		vertex[i].z = PosMatrix._43;
	}

	//���̈ʒu�Ɉړ�������
	MoveMatrix(vertex, cx, cy, 0.0f);

}

