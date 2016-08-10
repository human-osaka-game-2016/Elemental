/**
*@file draw_config.cpp
*@brief Directx�̕`��֘A�̊֐����܂Ƃ߂Ă���cpp�t�@�C���ł�.
*@author �F��M�V
*@date 2016/06/18
*/
#include <d3dx9.h>
#include <d3dx9tex.h>
#include"draw_config.h"
#include"config.h"



/*�ȉ��̃\�[�X�����C����
IDirect3D9*			pDirect3D;		//	Direct3D�̃C���^�[�t�F�C�X
IDirect3DDevice9*	pD3Device;		//	Direct3D�̃f�o�C�X
LPDIRECT3DTEXTURE9	pTexture[];	//	�摜�̏������Ă����ׂ̃|�C���^�z��
D3DDISPLAYMODE d3ddm;               //�f�B�X�v���C
D3DPRESENT_PARAMETERS d3dpp;		//	�p�����[�^�[
*/

//�`����@�̐ݒ�(���̊֐��̓f�o�C�X�쐬�֐��̉��ɏ���)
void RenderState(IDirect3DDevice9*	pD3Device)
{
	pD3Device->SetRenderState(D3DRS_ALPHABLENDENABLE, true);
	pD3Device->SetRenderState(D3DRS_SRCBLEND, D3DBLEND_SRCALPHA);  //SRC�̐ݒ�
	pD3Device->SetRenderState(D3DRS_DESTBLEND, D3DBLEND_INVSRCALPHA);
	pD3Device->SetRenderState(D3DRS_DIFFUSEMATERIALSOURCE, D3DMCS_COLOR1);

	pD3Device->SetTextureStageState(0, D3DTSS_COLORARG1, D3DTA_TEXTURE);
	pD3Device->SetTextureStageState(0, D3DTSS_COLORARG2, D3DTA_DIFFUSE);

	pD3Device->SetTextureStageState(0, D3DTSS_COLOROP, D3DTOP_MODULATE);

	pD3Device->SetTextureStageState(0, D3DTSS_ALPHAARG1, D3DTA_TEXTURE);
	pD3Device->SetTextureStageState(0, D3DTSS_ALPHAARG2, D3DTA_DIFFUSE);

	pD3Device->SetTextureStageState(0, D3DTSS_ALPHAOP, D3DTOP_MODULATE);

}


//�`��X�^�[�g�@FVF�͏_��Ȓ��_�t�H�[�}�b�g�̂���
void DrawStart(IDirect3DDevice9*	pD3Device, DWORD FVF)
{

	
	//��ʂ̏���
	pD3Device->Clear(0, NULL,
		D3DCLEAR_TARGET,
		D3DCOLOR_XRGB(0x00, 0x00, 0x00),
		1.0, 0);
	//�`��̊J�n
	pD3Device->BeginScene();

	//�`��̃t�H�[�}�b�g��ݒ�
	pD3Device->SetFVF(FVF);
}

//�`��
void DrawPicture(IDirect3DDevice9*	pD3Device, LPDIRECT3DTEXTURE9 pTexture, CUSTOMVERTEX setdraw[])
{

	pD3Device->SetTexture(0, pTexture);
	pD3Device->DrawPrimitiveUP(
		D3DPT_TRIANGLEFAN,
		2,
		setdraw,
		sizeof(CUSTOMVERTEX));
}

//�`��G���h
void DrawEnd(IDirect3DDevice9*	pD3Device)
{
	//�`��̏I�� 
	pD3Device->EndScene();

	//�\��
	pD3Device->Present(NULL, NULL, NULL, NULL);
}

//�摜�ǂݍ���
int LoadPicture(IDirect3DDevice9* pD3Device, char text[256], LPDIRECT3DTEXTURE9*	pTexture)
{
	if (FAILED(D3DXCreateTextureFromFile(pD3Device, text, pTexture)))
	{

		return ERROR_VALUE;
	}
	
	return SUCCESS_VALUE;
}

//�摜�ǂݍ���Ex
int LoadPicture_Ex(IDirect3DDevice9* pD3Device, char text[256], LPDIRECT3DTEXTURE9*	pTexture)
{
	if (FAILED(D3DXCreateTextureFromFileEx(
		pD3Device,
		text,
		D3DX_DEFAULT_NONPOW2,
		D3DX_DEFAULT_NONPOW2,
		D3DX_DEFAULT,
		0,
		D3DFMT_UNKNOWN,
		D3DPOOL_MANAGED,
		D3DX_FILTER_NONE,
		D3DX_FILTER_NONE,
		D3DCOLOR_ARGB(255, 0, 0, 0),
		NULL, NULL,
		pTexture)))
	{
		return ERROR_VALUE;
	}

	return SUCCESS_VALUE;
}