/**
 * @file Direct_Draw.cpp
 * @brief DirectX�̕`��Ɋ֌W����֐��̒��g
 * @author �ēc�N��
 * @date 2016�N7��1��
 */

#include <d3dx9.h>
#include "Direct_Draw.h"

/**
* �_��Ȓ��_�t�H�[�}�b�g�Ƃ��Ē�`���Ă���<br>
* D3DFVF_XYZRHW�͍��W<br>
* D3DFVF_DIFFUSE�͐F����<br>
* D3DFVF_TEX1�͍��W�Z�b�g�̃e�N�X�`���ԍ�
*/
#define D3DFVF_CUSTOMVERTEX (D3DFVF_XYZRHW | D3DFVF_DIFFUSE | D3DFVF_TEX1)

static IDirect3DDevice9*		g_pD3Device = NULL;			///<DirectX�f�o�C�X�̃|�C���^

// �`�揉�����֐�
void Init_Draw()
{
	// �`��̐ݒ�
	g_pD3Device->SetRenderState(D3DRS_ALPHABLENDENABLE, true);

	g_pD3Device->SetRenderState(D3DRS_DESTBLEND, D3DBLEND_INVSRCALPHA);
	g_pD3Device->SetRenderState(D3DRS_SRCBLEND, D3DBLEND_SRCALPHA);
	//	g_pD3Device->SetRenderState(D3DRS_DIFFUSEMATERIALSOURCE, D3DMCS_COLOR1);

	g_pD3Device->SetTextureStageState(0, D3DTSS_COLORARG1, D3DTA_TEXTURE);
	g_pD3Device->SetTextureStageState(0, D3DTSS_COLORARG2, D3DTA_DIFFUSE);

	g_pD3Device->SetTextureStageState(0, D3DTSS_COLOROP, D3DTOP_MODULATE);

	g_pD3Device->SetTextureStageState(0, D3DTSS_ALPHAARG1, D3DTA_TEXTURE);
	g_pD3Device->SetTextureStageState(0, D3DTSS_ALPHAARG2, D3DTA_DIFFUSE);

	g_pD3Device->SetTextureStageState(0, D3DTSS_ALPHAOP, D3DTOP_MODULATE);
}

// �`��n��
void Draw_Start()
{
	// ���_���̎w��
	g_pD3Device->SetFVF(D3DFVF_CUSTOMVERTEX);

	// ��ʂ̏���
	g_pD3Device->Clear(0, NULL,				
		D3DCLEAR_TARGET,					
		D3DCOLOR_XRGB(0x00, 0x00, 0x00)		// RGB�F��������
		, 1.0, 0);

	// �`����J�n
	g_pD3Device->BeginScene();
}


// �`��֐�		  // DirectX�e�N�X�`���E�I�u�W�F�N�g�ւ̃|�C���^
void Draw_Display(LPDIRECT3DTEXTURE9   _pTexture, CUSTOMVERTEX _setdraw[])
{
	g_pD3Device->SetTexture(0, _pTexture);		// SetTexture:�e�N�X�`�����f�o�C�X�̃X�e�[�W�Ɋ��蓖�Ă�
	g_pD3Device->DrawPrimitiveUP				// ()�̒��̎w�肵���摜�̕\��
		(D3DPT_TRIANGLEFAN, 2,				// �O�p�`�̃e�N�X�`�����Q���p�ӂ��Ă���
		_setdraw, sizeof(CUSTOMVERTEX));
}

// �摜�̓ǂݍ���			//�摜
HRESULT Load_Texture(TCHAR _filePath[256], LPDIRECT3DTEXTURE9*   _ppTexture)
{

	if (FAILED(D3DXCreateTextureFromFile(g_pD3Device, _filePath, _ppTexture)))
	{
		MessageBox(NULL, "�摜���ǂݍ��߂܂���ł����B", NULL, MB_OK);
		return E_FAIL;
	}

	return S_OK;
}

// �摜�̓ǂݍ���EX
HRESULT Load_Texture_EX(TCHAR _filePath[256], LPDIRECT3DTEXTURE9* _ppTexture)
{
	if (FAILED(D3DXCreateTextureFromFileEx(
		g_pD3Device,			
		_filePath,				// �摜�t�@�C���ւ̐�΃p�X�A���΃p�X��\��������@������摜�t�@�C���� bmp, dds, dib, jpg, png(��(�����x)��񂠂�), tga(��(�����x)��񂠂�)
		D3DX_DEFAULT,		// �摜�̕����擾
		D3DX_DEFAULT,		// �摜�̍������擾
		D3DX_DEFAULT,		// �~�b�v�}�b�v���x�����f�t�H���g�ɐݒ�@�~�j�}�b�v�ɂ��Ă̓������Q��
		0,					
		D3DFMT_UNKNOWN,
		D3DPOOL_DEFAULT,	
		D3DX_FILTER_NONE,	
		D3DX_DEFAULT,
		D3DCOLOR_ARGB(255, 0, 0, 0),
		NULL,
		NULL,
		_ppTexture
		)))
	{
		MessageBox(0, "�摜���ǂݍ��߂܂���ł����B", NULL, MB_OK);
		return E_FAIL;
	}
	return S_OK;
}

// �`��I���
void Draw_End()
{
	// �`����I��
	g_pD3Device->EndScene();

	// ��ʂɕ\��
	g_pD3Device->Present(NULL, NULL, NULL, NULL);		//���̃o�b�t�@�̃R���e���c��񎦂���
}

// DirectX�̃f�o�C�X�����̊֐�
HRESULT Create_Direct_Device(IDirect3D9* _pDirect3D, HWND _hWnd)
{
	// DirectX�̃f�o�C�X�𐶐�����ۂɕK�v�ȏ���p��
	D3DPRESENT_PARAMETERS	d3dpp;							// Direct3DPresentParameters
	ZeroMemory(&d3dpp, sizeof(D3DPRESENT_PARAMETERS));		// �w�肵�Ă���ꏊ�̃�����������������

	/*
	* ��ʕ\���͕��ʁu�t�����g�o�b�t�@�v�Ɓu�o�b�N�o�b�t�@�v��2������
	*/
	d3dpp.BackBufferFormat = D3DFMT_UNKNOWN;	// D3DFMT_UNKNOWN�Ō��݂̃f�B�X�v���C���[�h�t�H�[�}�b�g�������Őݒ肵�Ă����
	d3dpp.BackBufferCount = 1;					// �o�b�N�o�b�t�@�̐�
	d3dpp.SwapEffect = D3DSWAPEFFECT_DISCARD;	// �t�����g�ƃo�b�N�̐؂�ւ�
	d3dpp.Windowed = TRUE;						// TRUE�Ȃ�E�B���h�E�E���[�h�AFALSE�Ȃ�t���X�N���[���E���[�h(���������K�v����)

	// DirectX�̃f�o�C�X����
	_pDirect3D->CreateDevice(					// �f�B�X�v���C�A�_�v�^��\�����߂̃f�o�C�X���쐬����
		D3DADAPTER_DEFAULT,
		D3DDEVTYPE_HAL,							// �n�[�h�E�F�A�Ŏ��������Ă���(�\�t�g�E�F�A�ł������ł���)
		_hWnd,
		D3DCREATE_HARDWARE_VERTEXPROCESSING,	//High(����), Width(��),�̒��_����
		&d3dpp,
		&g_pD3Device);

	// DirectX�̃f�o�C�X�𐶐��ł������`�F�b�N
	if (g_pD3Device == NULL)
	{
		MessageBox(NULL, "�f�o�C�X�������ł��܂���ł����B", NULL, MB_OK);

		// �����Ɏ��s������DirectX�I�u�W�F�N�g��������ďI������
		_pDirect3D->Release();
		return E_FAIL;
	}
	return S_OK;
}


// ����֐�
void Draw_Free()
{
	g_pD3Device->Release();
}

