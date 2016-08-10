/**
*@file draw_config.h
*@brief Directx�̕`��֘A�̊֐����܂Ƃ߂Ă���cpp�̃w�b�_�[�t�@�C���ł�.
*@author �F��M�V
*@date 2016/06/18
*/


#ifndef CUTOMVERTEX_CONFIG_H
#define CUTOMVERTEX_CONFIG_H
#include <d3dx9.h>
#include <d3dx9tex.h>

/**
*���_�f�[�^(���)<br>
*�_��Ȓ��_�t�H�[�}�b�g�̒�Ԃ�define���Ă���܂�.
*@attention �����܂ł���͒�Ԃł��B������g�킸�ɒ��_�f�[�^��ݒ肵�Ă������ł�
*/
#define D3DFVF_CUSTOMVERTEX (D3DFVF_XYZRHW | D3DFVF_DIFFUSE | D3DFVF_TEX1)

/**
*@par �J�X�^���o�[�e�b�N�X
* �\���̂ŃJ�X�^���o�[�e�b�N�X�^���`���Ă��܂��B�����o�[�͈ȉ��̒ʂ�ł�.<br>
*x, y, z, rhw�F��ʏ�̍��W���<br>
*color�F�F���<br>
*tu, tv�F�e�N�X�`�����W.<br>
*/
struct CUSTOMVERTEX
{
	FLOAT	x, y, z, rhw;
	DWORD	color;
	FLOAT	tu, tv;
};

/**
*�`����@�̐ݒ�֐�.
*@attention���̊֐���Winmain�֐��ɏ����Ă�������
*@param[in] pD3Device	�Direct3D�̃f�o�C�X
*/
void RenderState(IDirect3DDevice9*	pD3Device);

/**
*�`����J�n����ׂ̊֐�.<br>
*�E��ʂ̏���<br>
*�E�`��̊J�n<br>
*�E�`��̃t�H�[�}�b�g��ݒ�<br>
*@param[in] pD3Device   �EDirect3D�̃f�o�C�X
*@param[in] FVF  �EFVF�萔
*/
void DrawStart(IDirect3DDevice9* pD3Device, DWORD FVF);

/**
*��ʂɉ摜��`�悷�鏈���������Ȃ��Ă���֐�.
*@param[in] pD3Device	�Direct3D�̃f�o�C�X
*@param[in] pTexture	��ǂݍ��񂾉摜���
*@param[in] setdraw		��o�[�e�b�N�X�i���W���Ȃǁj
*/
void DrawPicture(IDirect3DDevice9*	pD3Device, LPDIRECT3DTEXTURE9 pTexture, CUSTOMVERTEX setdraw[]);

/**
*�`����I���A�\������ׂ̊֐�.<br>
*�`��̏I��<br>
*�\��.<br>
*@param[in] pD3Device	�Direct3D�̃f�o�C�X
*/
void DrawEnd(IDirect3DDevice9*	pD3Device);

/**
*�摜��ǂݍ��ފ֐�.<br>
*D3DXCreateTextureFromFile���g�p.
*@param[in] pD3Device	�Direct3D�̃f�o�C�X
*@param[in] text[256]	��摜
*@param[out] pTexture	��ǂݍ��񂾉摜�����i�[����
*@retval SUCCESS_VALUE  �ǂݍ��ݐ���
*@retval ERROR_VALUE	�ǂݍ��ݎ��s
*/
int LoadPicture(IDirect3DDevice9* pD3Device, char text[256], LPDIRECT3DTEXTURE9* pTexture);

/**
*�摜��ǂݍ��ފ֐�.
*D3DXCreateTextureFromFileEx���g�p.
*@param[in] pD3Device	�Direct3D�̃f�o�C�X
*@param[in] text[256]	��摜
*@param[out] pTexture	��ǂݍ��񂾉摜�����i�[����
*@retval SUCCESS_VALUE  �ǂݍ��ݐ���
*@retval ERROR_VALUE	�ǂݍ��ݎ��s
*/
int LoadPicture_Ex(IDirect3DDevice9* pD3Device, char text[256], LPDIRECT3DTEXTURE9*	pTexture);



#endif


