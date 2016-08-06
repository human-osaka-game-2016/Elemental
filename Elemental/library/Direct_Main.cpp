/**
 * @file Direct_Main.cpp
 * @brief DirectX�I�u�W�F�N�g��f�o�C�X�Ɋ֌W����֐��̒��g
 * @author �ēc�N��
 * @date 2016�N7��1��
*/

#include <d3dx9.h>
#include "Direct_Main.h"
#include "Direct_Draw.h"


static IDirect3D9*				g_pDirect3D = NULL;			///< DirectX�I�u�W�F�N�g�̃|�C���^

// DirectX�̏������֐�
HRESULT Init_Direct(HWND _hWnd)
{
	// DirectX�I�u�W�F�N�g����
	g_pDirect3D = Direct3DCreate9(D3D_SDK_VERSION);		// D3D_SDK_VERSION�͕ς��Ă͂����Ȃ�

	// �I�u�W�F�N�g�̐����ɐ����������`�F�b�N
	if (g_pDirect3D == NULL)
	{
		MessageBox(NULL, "�I�u�W�F�N�g�������ł��܂���ł����B", NULL, MB_OK);
		// �����Ɏ��s������I������
		return E_FAIL;
	}

	// DisplayMode�̎擾
	D3DDISPLAYMODE			D3DdisplayMode;				// �f�B�X�v���C���[�h
	g_pDirect3D->GetAdapterDisplayMode(					// �A�_�v�^�̌��݂̃f�B�X�v���C ���[�h���擾����
		D3DADAPTER_DEFAULT,					
		 &D3DdisplayMode);
	
	if (FAILED(Create_Direct_Device(g_pDirect3D, _hWnd)))
	{
		MessageBox(NULL, "�I�u�W�F�N�g�������ł��܂���ł����B", NULL, MB_OK);
		return E_FAIL;
	}
	
	
	return S_OK;
}

// ����֐�
void Free()
{
	g_pDirect3D->Release();
}