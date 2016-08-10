#include <d3d9.h>
#include <d3dx9.h>
#include "GameScene.h"
#include <stdio.h>


//	�Q�[���V�[���̉摜�������Ă����z��
LPDIRECT3DTEXTURE9			g_pGameTexture[GAMESCENE_MAX];	
KEYSTATE Key[KEYMAX];

int PreKey[KEYMAX] = { 0 };

int KeyState[4] = { 0 };

PLAYERSTATE g_playerState = { 1, 520.f, 480.f, false, false, false };
CUSTOMVERTEX g_mapTip1[] =
{
	{ 0.0f, 0.0f, 0.5f, 1.0f, 0xFFFFFFFF, 0.0f, 0.0f },
	{ 64.0f, 0.0f, 0.5f, 1.0f, 0xFFFFFFFF, 0.5f, 0.0f },
	{ 64.0f, 64.0f, 0.5f, 1.0f, 0xFFFFFFFF, 0.5f, 1.0f },
	{ 0.0f, 64.0f, 0.5f, 1.0f, 0xFFFFFFFF, 0.0f, 1.0f },
};
CUSTOMVERTEX g_mapTip2[] =
{
	{ 0.0f, 0.0f, 0.5f, 1.0f, 0xFFFFFFFF, 0.5f, 0.0f },
	{ 64.0f, 0.0f, 0.5f, 1.0f, 0xFFFFFFFF, 1.0f, 0.0f },
	{ 64.0f, 64.0f, 0.5f, 1.0f, 0xFFFFFFFF, 1.0f, 1.0f },
	{ 0.0f, 64.0f, 0.5f, 1.0f, 0xFFFFFFFF, 0.5f, 1.0f },
};

CUSTOMVERTEX g_player[] =
{
	{ -32.0f, -32.0f, 0.5f, 1.0f, 0xFFFFFFFF, 0.0f, 0.0f },
	{ 32.0f, -32.0f, 0.5f, 1.0f, 0xFFFFFFFF, 0.25f, 0.0f },
	{ 32.0f, 32.0f, 0.5f, 1.0f, 0xFFFFFFFF, 0.25f, 1.0f },
	{ -32.0f, 32.0f, 0.5f, 1.0f, 0xFFFFFFFF, 0.0f, 1.0f },
};

int map[MAP_HEIGHT][MAP_WIDTH];
// �Q�[���V�[���̐���֐�
void GameSceneControl()
{
	KeyCheck(VK_LEFT, LEFT);
	KeyCheck(VK_RIGHT, RIGHT);
	KeyCheck(VK_UP, UP);
	KeyCheck(VK_DOWN, DOWN);
	KeyCheck('Z', FIRE);

	if (Key[LEFT] == ON)
	{
		g_playerState.isLeft = true;
		if (g_playerState.posX > 400.f)
		{
			g_playerState.posX -= 3.f;
		}
		else
		{
			for (int i = 0; i < 4; i++)
			{
				g_mapTip1[i].x += 3.f;
				g_mapTip2[i].x += 3.f;
			}
		}
	}
	if (Key[RIGHT] == ON)
	{
		g_playerState.isLeft = false;
		if (g_playerState.posX < 820.f)
		{
			g_playerState.posX += 3.f;
		}
		else
		{
			for (int i = 0; i < 4; i++)
			{
				g_mapTip1[i].x -= 3.f;
				g_mapTip2[i].x -= 3.f;
			}
		}
	}
}

// �Q�[���V�[���̕`��֐�
void GameSceneDraw()
{
	// �o�b�N�O���E���h�̒��_�����쐬����
	CUSTOMVERTEX backGround[4]
	{
		{ 0.f,   0.f,   1.f, 1.f, 0xFFFFFFFF, 0.f, 0.f },
		{ 1280.f, 0.f,   1.f, 1.f, 0xFFFFFFFF, 1.f, 0.f },
		{ 1280.f, 720.f, 1.f, 1.f, 0xFFFFFFFF, 1.f, 1.f },
		{ 0.f,   720.f, 1.f, 1.f, 0xFFFFFFFF, 0.f, 1.f }
	};


	// ���_���̎w��
	g_pDirect3DDevice->SetFVF(D3DFVF_CUSTOMVERTEX);

	// ��ʂ̏���
	g_pDirect3DDevice->Clear(0, NULL,D3DCLEAR_TARGET,D3DCOLOR_XRGB(0x00, 0x00, 0x00),1.0, 0);
	// �`����J�n
	g_pDirect3DDevice->BeginScene();



	// �e�N�X�`�����X�e�[�W�Ɋ��蓖�Ă�
	g_pDirect3DDevice->SetTexture(0, g_pGameTexture[BACKGROUND_TEX]);
	// �`��
	g_pDirect3DDevice->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, backGround, sizeof(CUSTOMVERTEX));

	MapDraw();

	PlayerDraw();

	// �`����I��
	g_pDirect3DDevice->EndScene();
	// ��ʂɕ\��
	g_pDirect3DDevice->Present(NULL, NULL, NULL, NULL);
}

// �Q�[���V�[���̏������֐�
void GameSceneInit()
{
	// �`��̐ݒ�
	g_pDirect3DDevice->SetRenderState(D3DRS_ALPHABLENDENABLE, true);
	g_pDirect3DDevice->SetRenderState(D3DRS_SRCBLEND, D3DBLEND_SRCALPHA);  //SRC�̐ݒ�
	g_pDirect3DDevice->SetRenderState(D3DRS_DESTBLEND, D3DBLEND_INVSRCALPHA);
	g_pDirect3DDevice->SetRenderState(D3DRS_DIFFUSEMATERIALSOURCE, D3DMCS_COLOR1);

	g_pDirect3DDevice->SetTextureStageState(0, D3DTSS_COLORARG1, D3DTA_TEXTURE);
	g_pDirect3DDevice->SetTextureStageState(0, D3DTSS_COLORARG2, D3DTA_DIFFUSE);

	g_pDirect3DDevice->SetTextureStageState(0, D3DTSS_COLOROP, D3DTOP_MODULATE);

	g_pDirect3DDevice->SetTextureStageState(0, D3DTSS_ALPHAARG1, D3DTA_TEXTURE);
	g_pDirect3DDevice->SetTextureStageState(0, D3DTSS_ALPHAARG2, D3DTA_DIFFUSE);

	g_pDirect3DDevice->SetTextureStageState(0, D3DTSS_ALPHAOP, D3DTOP_MODULATE);


	// �e�N�X�`����Ǎ�
	D3DXCreateTextureFromFile(
		g_pDirect3DDevice,
		"RabbitHouse.png",
		&g_pGameTexture[BACKGROUND_TEX]);

	D3DXCreateTextureFromFile(
		g_pDirect3DDevice,
		"mapGround.jpg",
		&g_pGameTexture[MAP_GROUND_TEX]);

	D3DXCreateTextureFromFile(
		g_pDirect3DDevice,
		"chara.png",
		&g_pGameTexture[PLAYER_RIGHT_TEX]);

	D3DXCreateTextureFromFile(
		g_pDirect3DDevice,
		"chara_reverse.png",
		&g_pGameTexture[PLAYER_LEFT_TEX]);

	MapLoad("map.csv");
}

// �Q�[���V�[���̉���֐�
void GameSceneFree()
{
	// �e�N�X�`�������
	for (int i = 0; i < GAMESCENE_MAX; i++)
	{
		g_pGameTexture[i]->Release();
	}
}

void MapLoad(const char* mapdata)
{
	FILE*  fp;
	fopen_s(&fp, mapdata, "r");

	for (int i = 0; i < MAP_HEIGHT; i++)
	{
		for (int j = 0; j < MAP_WIDTH; j++)
		{
			fscanf_s(fp, "%d,", &map[i][j], _countof(map));
		}
	}
}

void PlayerDraw()
{
	static int gameTime = 0;
	gameTime++;
	if ((gameTime % 10) == 0)
	{
		if (g_playerState.animReverse)
		{
			for (int i = 0; i < 4; i++)
			{
				g_player[i].tu -= 0.25f;
			}
		}
		else
		{
			for (int i = 0; i < 4; i++)
			{
				g_player[i].tu += 0.25f;
			}
		}

		if (g_player[2].tu == 1.f && !g_playerState.animReverse)
		{
			g_playerState.animReverse = true;
		}
		else if (g_player[0].tu == 0.f && g_playerState.animReverse)
		{
			g_playerState.animReverse = false;
		}
	}
	CUSTOMVERTEX drawPlayerVertex[4];
	for (int i = 0; i < 4; i++)
	{
		drawPlayerVertex[i] = g_player[i];
		drawPlayerVertex[i].x += g_playerState.posX;
		drawPlayerVertex[i].y += g_playerState.posY;
	}

	if (g_playerState.isLeft)
	{
		g_pDirect3DDevice->SetTexture(0, g_pGameTexture[PLAYER_LEFT_TEX]);
	}
	else
	{
		g_pDirect3DDevice->SetTexture(0, g_pGameTexture[PLAYER_RIGHT_TEX]);
	}
	// �`��
	g_pDirect3DDevice->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, drawPlayerVertex, sizeof(CUSTOMVERTEX));
}

void MapDraw()
{
	for (int y = 0; y < MAP_HEIGHT; y++)
	{
		for (int x = 0; x < MAP_WIDTH; x++)
		{

			if (map[y][x] == 1)
			{
				CUSTOMVERTEX drawMapVertex[4];
				for (int i = 0; i < 4; i++)
				{
					drawMapVertex[i] = g_mapTip1[i];
				}

				for (int i = 0; i < 4; i++)
				{
					drawMapVertex[i].x += (x * TIPSIZE);
					drawMapVertex[i].y += (y * TIPSIZE);
				}
				// �e�N�X�`�����X�e�[�W�Ɋ��蓖�Ă�
				g_pDirect3DDevice->SetTexture(0, g_pGameTexture[MAP_GROUND_TEX]);
				// �`��
				g_pDirect3DDevice->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, drawMapVertex, sizeof(CUSTOMVERTEX));
			}
			else if (map[y][x] == 2)
			{
				CUSTOMVERTEX drawMapVertex[4];
				for (int i = 0; i < 4; i++)
				{
					drawMapVertex[i] = g_mapTip2[i];
				}

				for (int i = 0; i < 4; i++)
				{
					drawMapVertex[i].x += (x * TIPSIZE);
					drawMapVertex[i].y += (y * TIPSIZE);
				}

				// �e�N�X�`�����X�e�[�W�Ɋ��蓖�Ă�
				g_pDirect3DDevice->SetTexture(0, g_pGameTexture[MAP_GROUND_TEX]);
				// �`��
				g_pDirect3DDevice->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, drawMapVertex, sizeof(CUSTOMVERTEX));
			}
		}
	}
}

void KeyCheck(int VK, KEYKIND st) {
	if ((GetKeyState(VK) & 0x8000) != 0) {
		if (PreKey[st] == 0) {
			Key[st] = PUSH;
		}
		else {
			Key[st] = ON;
		}
		PreKey[st] = 1;
	}
	else {
		if (PreKey[st] == 0) {
			Key[st] = OFF;
		}
		else {
			Key[st] = RELEASE;
		}
		PreKey[st] = 0;
	}
}