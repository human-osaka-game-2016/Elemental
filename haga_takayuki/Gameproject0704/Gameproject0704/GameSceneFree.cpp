/**
*@file GameSceneFree.h
*@brief �������J���֐���cpp.
*/
#include <d3d9.h>
#include <dinput.h>
#include"config.h"
#include"Main.h"

//�������J���֐�
void Free()
{
	//�J��
	// �e�N�X�`�������
	for (int i = 0; i < GAME_TEX_MAX; i++)
	{
		SAFE_RELEASE(g_pGameTexture[i]);
	}

	SAFE_RELEASE(g_pkeyDevice);
	SAFE_RELEASE(g_pDInput);
	SAFE_RELEASE(g_pDirect3DDevice);
	SAFE_RELEASE(g_pDirect3D);
	
	
}