/**
@file config.h
@brief Windows�֘A�A�y��Directx�������֐��Ȃǂ��܂Ƃ߂Ă���cpp�̃w�b�_�[�t�@�C���ł�.
@author �F��M�V
@data 2016/06/18
*/
#ifndef CONFIG_H
#define CONFIG_H
#include <d3dx9.h>


/**
*�������J���Ɏg�p.
*@note ������g�p�����Ƀ��C���\�[�X�Ń������J���֐��������Ă������ł�
*/
#define SAFE_RELEASE(p) {if(p){(p)->Release(); (p)=NULL;}}

/**
*�T�N�Z�X(����)�̏ꍇ�̖߂�l<br>
*�����ł���߂�l��0���킩��₷�����邽�߂�SUCCESS_VALUE�Ƃ��Ă���܂�.
*/
#define SUCCESS_VALUE 0

/**
*�G���[�̏ꍇ�̖߂�l<br>
*���s�ł���߂�l��-1���킩��₷�����邽�߂�ERROR_VALUE�Ƃ��Ă���܂�.
*/
#define ERROR_VALUE -1


/**
*Windows�Ɋւ���֐�.<br>
*�E�E�B���h�E���̐ݒ襓o�^<br>
*�E�E�B���h�E�쐬<br>
*@param[in] hInstance	��A�v���P�[�V�����ւ̃|�C���^
*@param[out] winc		��E�B���h�E�N���X�̍\����
*@param[out] hWnd		��E�B���h�E�n���h��
*@param[in]	text[256]	��E�B���h�E�^�C�g��
*@param[in]	Window_Widgh�@	��E�B���h�E�̕�
*@param[in]	Window_Height�@	��E�B���h�E�̍���
*@param[in]	WndProc			��E�B���h�E�v���V�[�W���֐��@
*@retval SUCCESS_VALUE  ����
*@retval ERROR_VALUE	���s
*/
int MakeWindows(HINSTANCE hInstance, WNDCLASS* winc, HWND* hWnd, char text[256], int Window_Widgh, int Window_Height, LRESULT CALLBACK WndProc(HWND hWnd, UINT msg, WPARAM wp, LPARAM lp));

/**
*DirectX �I�u�W�F�N�g�𐶐�����֐�.
*@param[in]	pDirect3D		�Direct3D�̃f�o�C�X	
*@param[in]	version			��o�[�W�������
*/
void InitGameObject(IDirect3D9** pDirect3D, int version);

/**
*DirectX�f�o�C�X���쐬����֐�.
*@param[in] pDirect3D	�Direct3D�̃C���^�[�t�F�C�X
*@param[in]	pD3Device	�Direct3D�̃f�o�C�X
*@param[in]	d3dpp		��f�B�X�v���C
*@param[in]	d3ddm		��p�����[�^�[
*/
void InitGameDevice(IDirect3D9*	pDirect3D, IDirect3DDevice9** pD3Device, D3DPRESENT_PARAMETERS* d3dpp, D3DDISPLAYMODE* d3ddm, HWND hWnd);


#endif