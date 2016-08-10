/**
*@file Main.cpp
*@brief �Q�[���̃G���g���[�|�C���g��cpp.
*/
#include <windows.h>
#include <d3d9.h>
#include <dinput.h>
#include"key_operation.h"
#include"config.h"
#include"Main.h"
#include"GameSceneInit.h"
#include"GameSceneDraw.h"
#include"GameSceneControl.h"
#include"GameSceneFree.h"

//-----------------------------------------------------------------------------
//							�O���[�o���ϐ��Q
//-----------------------------------------------------------------------------

LPDIRECT3D9				g_pDirect3D		= NULL;				// DirectX�I�u�W�F�N�g�̃|�C���^
LPDIRECT3DDEVICE9		g_pDirect3DDevice = NULL;			// DirectX�f�o�C�X�̃|�C���^
LPDIRECT3DTEXTURE9		g_pGameTexture[GAME_TEX_MAX];		//�摜�������ꂨ�����߂̔z��
LPDIRECTINPUT8			g_pDInput = NULL;					//DirectInput8 �C���^�[�t�F�C�X
LPDIRECTINPUTDEVICE8	g_pkeyDevice = NULL;				//�L�[�{�[�h�f�o�C�X

// �E�B���h�E�v���V�[�W��
LRESULT CALLBACK WndProc(HWND hWnd, UINT mes, WPARAM wParam, LPARAM lParam)
{
	if (mes == WM_DESTROY)
	{
		PostQuitMessage(0);
		return 0;
	}

	return DefWindowProc(hWnd, mes, wParam, lParam);
}


// �G���g���|�C���g
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int nCmdShow)
{
	//-----------------------------------------------------------------------------
	//								�ϐ��Q
	//-----------------------------------------------------------------------------

	/*-------------------------�E�B���h�E�֘A--------------------------------------*/
	MSG msg;											// ���b�Z�[�W���i�[����\����
	HWND hWnd;											// �E�B���h�E�n���h��
	WNDCLASS winc;										//�E�B���h�E�N���X
	/*------------------------DirectX�������֘A------------------------------------*/
					
	D3DDISPLAYMODE		D3DdisplayMode;					//�f�B�X�v���C���[�h
	D3DPRESENT_PARAMETERS d3dpp;						// DirectX�̃f�o�C�X�𐶐�����ۂɕK�v�ȃp�����[�^�[��p��

	/*---------------------�Q�[���Ŏg�p����ϐ�------------------------------------*/
	PLAYERSTATE playerState;							//�v���C���[���
	BULLETSTATE playerBulletState[BULLETMAX];			//�v���C���[�̒e���
	ENEMYSTATE enemyState[ENEMYMAX];					//�G�̒e���
	BULLETSTATE enemyBulletState[ENEMYBULLETMAX];		//�G�̒e�̏��
	BACKGROUNDSTATE backgroundState[BG_MAX];            //�w�i
	SCORESTATE hiscore[RANKING_SCORE_MAX];				//�n�C�X�R�A
	FLAGSTATE flags;									//�t���O���܂Ƃ߂�����
	//----------------------------------------------------------------------------
	//							�E�B���h�E��������
	//----------------------------------------------------------------------------

	if ((MakeWindows(hInstance, &winc, &hWnd, WINDOW_TITLE, WINDOW_W, WINDOW_H, WndProc)) == ERROR_VALUE)
	{
		return ERROR_VALUE;
	}

	ShowWindow(hWnd, SW_SHOW);

	//--------------------------------------------------------------------------
	//							DirectX����������
	//--------------------------------------------------------------------------

	// DirectX�I�u�W�F�N�g����
	InitGameObject(&g_pDirect3D, D3D_SDK_VERSION);
	// �I�u�W�F�N�g�̐����ɐ����������`�F�b�N
	if (g_pDirect3D == NULL)
	{
		// �����Ɏ��s������I������
		return ERROR_VALUE;
	}
	
	//�f�o�C�X����
	InitGameDevice(g_pDirect3D, &g_pDirect3DDevice, &d3dpp, &D3DdisplayMode, hWnd);

	if (g_pDirect3DDevice == NULL)
	{
		// �����Ɏ��s������DirectX�I�u�W�F�N�g��������ďI������
		SAFE_RELEASE(g_pDirect3D);
		return ERROR_VALUE;
	}
	//-----------------------------------------------------------------------
	//						DirectInput����������
	//-----------------------------------------------------------------------
	if (FAILED(InitDinput(hWnd, &g_pDInput, &g_pkeyDevice)))
	{
		// �����Ɏ��s������DirectX�I�u�W�F�N�g��������ďI������
		SAFE_RELEASE(g_pDirect3D);
		SAFE_RELEASE(g_pDirect3DDevice);
		return ERROR_VALUE;
	}
	//----------------------------------------------------------------------
	//							�Q�[�����[�v
	//----------------------------------------------------------------------

	//�Q�[���̏�����
	InitGameScene(&playerState, playerBulletState, enemyState, enemyBulletState, backgroundState, hiscore,&flags);

	DWORD SyncOld = timeGetTime();	//	�V�X�e�����Ԃ��擾
	DWORD SyncNow;

	timeBeginPeriod(1);
	ZeroMemory(&msg, sizeof(msg));
	while (msg.message != WM_QUIT)
	{
		Sleep(1);
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
		else
		{
			SyncNow = timeGetTime();
			if (SyncNow - SyncOld >= 1000 / 60) //	1�b�Ԃ�60�񂱂̒��ɓ���
			{
				//�Q�[��
				GameControl(&playerState, playerBulletState, enemyState, enemyBulletState, hiscore, backgroundState,&flags);

				GameDraw(&playerState, playerBulletState, enemyState, enemyBulletState, backgroundState, hiscore, &flags);

				SyncOld = SyncNow;
			}
		}
	}
	timeEndPeriod(1);

	//�������J��
	Free();
	return 0;
}