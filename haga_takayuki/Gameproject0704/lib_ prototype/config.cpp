/**
@file config.cpp
@brief Windows�֘A�A�y��Directx�������֐��Ȃǂ��܂Ƃ߂Ă���cpp�t�@�C���ł�.
@author �F��M�V
@data 2016/06/18
*/
#include <d3dx9.h>
#include <d3dx9tex.h>
#include"config.h"

/*
IDirect3D9*			pDirect3D;		//	Direct3D�̃C���^�[�t�F�C�X
IDirect3DDevice9*	pD3Device;		//	Direct3D�̃f�o�C�X
LPDIRECT3DTEXTURE9	pTexture[];		//	�摜�̏������Ă����ׂ̃|�C���^�z��
D3DDISPLAYMODE d3ddm;               // �f�B�X�v���C
D3DPRESENT_PARAMETERS d3dpp;		//	�p�����[�^�[
*/

/*�l�p�R�����g
�E�B���h�E�v���V�[�W���֐������C���ɏ������Ƃ�Y�ꂸ��
LRESULT CALLBACK WndProc(HWND hWnd, UINT msg, WPARAM wp, LPARAM lp)
{

	switch (msg)
	{
	case WM_DESTROY:	//	�E�C���h�E������ꂽ���Ƃ�
		PostQuitMessage(0);
		break;

	case WM_KEYDOWN:
		switch ((CHAR)wp)
		{
		case VK_ESCAPE:
			PostQuitMessage(0);
			break;
		}
		break;
	}
	return DefWindowProc(hWnd, msg, wp, lp);
}
*/

/*�ȉ��̃\�[�X�����C����
MSG msg;
HWND hWnd;
WNDCLASS winc;
*/

//Windows�֐�
int MakeWindows(HINSTANCE hInstance, WNDCLASS* winc, HWND* hWnd, char text[256], int Window_Widgh, int Window_Height, LRESULT CALLBACK WndProc(HWND hWnd, UINT msg, WPARAM wp, LPARAM lp))
{
	//Windows���̐ݒ�
	winc->style = CS_HREDRAW | CS_VREDRAW;
	winc->lpfnWndProc = WndProc;
	winc->cbClsExtra = winc->cbWndExtra = 0;
	winc->hInstance = hInstance;
	winc->hIcon = LoadIcon(NULL, IDI_APPLICATION);
	winc->hCursor = LoadCursor(NULL, IDC_ARROW);
	winc->hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);
	winc->lpszMenuName = NULL;
	winc->lpszClassName = text;	//�N���X��
	//Windows�̓o�^
	if (!RegisterClass(winc)) return ERROR_VALUE;
	//Windows�̐���
	//int dH = GetSystemMetrics(SM_CYCAPTION) + GetSystemMetrics(SM_CYFRAME) * 2;
	//int dW = GetSystemMetrics(SM_CXFRAME) * 2;
	//	�E�B���h�E�����				
	*hWnd = CreateWindow(
		text,								//�E�B���h�E�̃N���X��
		text, 							//�E�B���h�E�̃^�C�g��
		WS_OVERLAPPEDWINDOW | WS_VISIBLE,	//�E�B���h�E�X�^�C��
		CW_USEDEFAULT,						// �E�B���h�E�̉������̈ʒux
		CW_USEDEFAULT,						// �E�B���h�E�̏c�����̈ʒuy
		Window_Widgh ,							// Width�i���j�@
		Window_Height,							// Height�i����)
		NULL,
		NULL,
		hInstance,							// �A�v���P�[�V�����C���X�^���X�̃n���h��
		NULL
		);

	RECT client_rect;
	RECT widow_rect;
	GetWindowRect(*hWnd, &widow_rect);
	GetClientRect(*hWnd, &client_rect);


	//�������E�B���h�E�Ԋu�����߂�(��)
	widow_rect.right -= widow_rect.left;
	client_rect.right -= client_rect.left;

	//�������E�B���h�E�Ԋu�����߂�(����)
	widow_rect.bottom -= widow_rect.top;
	client_rect.bottom -= client_rect.top;

	SetWindowPos(*hWnd, HWND_TOP, 0,0, (Window_Widgh + (widow_rect.right - client_rect.right)), (Window_Height + (widow_rect.bottom - client_rect.bottom)), SWP_NOMOVE);

	//�ēx�m�F�p
	GetWindowRect(*hWnd, &widow_rect);
	GetClientRect(*hWnd, &client_rect);
	if (!hWnd) return ERROR_VALUE;

	return SUCCESS_VALUE;

}



//DirectX �I�u�W�F�N�g�̐���
void InitGameObject(IDirect3D9**	pDirect3D, int version)
{

	*pDirect3D = Direct3DCreate9(version);

}

//�f�o�C�X�쐬
void InitGameDevice(IDirect3D9*	pDirect3D, IDirect3DDevice9** pD3Device, D3DPRESENT_PARAMETERS* d3dpp, D3DDISPLAYMODE* d3ddm, HWND hWnd)
{
	pDirect3D->GetAdapterDisplayMode(
		D3DADAPTER_DEFAULT,
		d3ddm);
	ZeroMemory(d3dpp,
			   sizeof(D3DPRESENT_PARAMETERS));

	d3dpp->BackBufferFormat = d3ddm->Format;
	d3dpp->BackBufferCount = 1;
	d3dpp->SwapEffect = D3DSWAPEFFECT_DISCARD;
	d3dpp->Windowed = TRUE;

	//�f�o�C�X�����
	pDirect3D->CreateDevice(
		D3DADAPTER_DEFAULT,
		D3DDEVTYPE_HAL,
		hWnd,
		D3DCREATE_SOFTWARE_VERTEXPROCESSING,
		d3dpp, pD3Device);
}