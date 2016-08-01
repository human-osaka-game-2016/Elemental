/**
 * @file Main.cpp
 * @breif �Q�[���̃G���g���[�|�C���g
 * @author �ēc�N�ǁA�R�{�ϑ��Y�A�ݖ{��́A����G���A�c���M��A�|���ĕ��A�ѓc����
 * @date 2016�NX��Y��
 */


#include <windows.h>
#include <d3dx9tex.h>
#include "GameSceneDraw.h"
#include "GameSceneCntrol.h"


#include <Direct_Draw.h>
#include <Direct_Key_Input.h>
#include <Direct_Main.h>

#define WINDOW_W 1280					// �E�B���h�E��
#define WINDOW_H 736					// �E�B���h�E����
#define WINDOW_TITLE TEXT("Elemental")	// �E�B���h�E��

LRESULT CALLBACK WndProc(HWND hWnd, UINT mes, WPARAM wParam, LPARAM lParam)
{
	if (mes == WM_DESTROY)
	{
		PostQuitMessage(0);
		return 0;
	}

	return DefWindowProc(hWnd, mes, wParam, lParam);
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int nCmdShow)
{
	//---------------------------------------------------------------------
	//							�E�B���h�E��������
	//---------------------------------------------------------------------

	MSG msg;			// ���b�Z�[�W���i�[����\����
	HWND hWnd;			// �E�B���h�E�n���h��
	WNDCLASS winc;

	//Windows���̐ݒ�
	winc.style = CS_HREDRAW | CS_VREDRAW;
	winc.lpfnWndProc = WndProc;
	winc.cbClsExtra = winc.cbWndExtra = 0;
	winc.hInstance = hInstance;
	winc.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	winc.hCursor = LoadCursor(NULL, IDC_ARROW);
	winc.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	winc.lpszMenuName = NULL;
	winc.lpszClassName = WINDOW_TITLE;	//�N���X��

	//Window�̓o�^
	if (!RegisterClass(&winc)) return 0;
	//Window�̐���
	hWnd = CreateWindow(
		WINDOW_TITLE,						//�E�B���h�E�̃N���X��
		WINDOW_TITLE, 						//�E�B���h�E�̃^�C�g��
		WS_OVERLAPPEDWINDOW | WS_VISIBLE,	//�E�B���h�E�X�^�C��
		CW_USEDEFAULT,						// �E�B���h�E�̉������̈ʒux
		CW_USEDEFAULT,						// �E�B���h�E�̏c�����̈ʒuy
		WINDOW_W,							// Width�i���j
		WINDOW_H,							// Height�i�����j
		NULL,
		NULL,
		hInstance,							// �A�v���P�[�V�����C���X�^���X�̃n���h��
		NULL
		);
	if (!hWnd) return 0;

	ShowWindow(hWnd, SW_SHOW);

	Init_Direct(hWnd);

	Init_Direct_Input(hWnd);

	Init_Draw();

	Load_Texture("normal_1.png", &g_pTexture[MAP_GROUND_TEX]);
	Load_Texture("RabbitHouse.png", &g_pTexture[BACKGROUND_TEX]);
	Load_Texture("�L�����N�^�[_��.png", &g_pTexture[PLAYER_TEX]);

	Load_Map("ElementalWorld.csv");

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
				Render();
				Control();
				SyncOld = SyncNow;
			}
		}
	}
	timeEndPeriod(1);

	for (int i = 0; i < TEX_MAX; i++)
	{
		g_pTexture[i]->Release();
	}

	Draw_Free();
	Key_Free();
	Free();

	return 0;
}