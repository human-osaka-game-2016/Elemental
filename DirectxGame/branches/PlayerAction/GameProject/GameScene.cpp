#include <d3d9.h>
#include <d3dx9.h>
#include "GameScene.h"
#include <stdio.h>

#define MOVESPEED 5.f
#define JUMP_POWER -20.f
#define GRAVITY 0.6f
#define BULLETMAX 5

// �Q�[���V�[���̉摜�������Ă����z��
LPDIRECT3DTEXTURE9			g_pGameTexture[GAMESCENE_MAX];	

// �L�[�����i�[����ϐ�
KEYSTATE Key[KEYMAX];

int PreKey[KEYMAX] = { 0 };

int KeyState[4] = { 0 };

PLAYERSTATE g_playerState;
BULLETSTATE g_bulletState[BULLETMAX];

// �X�̃`�b�v�̒��_���
CUSTOMVERTEX g_mapTip1[] =
{
	{ 0.0f   , 0.0f   , 0.5f, 1.0f, 0xFFFFFFFF, 0.0f, 0.0f },
	{ TIPSIZE, 0.0f   , 0.5f, 1.0f, 0xFFFFFFFF, 0.5f, 0.0f },
	{ TIPSIZE, TIPSIZE, 0.5f, 1.0f, 0xFFFFFFFF, 0.5f, 1.0f },
	{ 0.0f   , TIPSIZE, 0.5f, 1.0f, 0xFFFFFFFF, 0.0f, 1.0f },
};

// �y�̃`�b�v�̒��_���
CUSTOMVERTEX g_mapTip2[] =
{
	{ 0.0f   , 0.0f   , 0.5f, 1.0f, 0xFFFFFFFF, 0.5f, 0.0f },
	{ TIPSIZE, 0.0f   , 0.5f, 1.0f, 0xFFFFFFFF, 1.0f, 0.0f },
	{ TIPSIZE, TIPSIZE, 0.5f, 1.0f, 0xFFFFFFFF, 1.0f, 1.0f },
	{ 0.0f   , TIPSIZE, 0.5f, 1.0f, 0xFFFFFFFF, 0.5f, 1.0f },
};

// �v���C���[�L�����̒��_���
CUSTOMVERTEX g_player[] =
{
	{ -TIPSIZE / 2.0f, -TIPSIZE / 2.0f, 0.5f, 1.0f, 0xFFFFFFFF, 0.0f , 0.0f },
	{  TIPSIZE / 2.0f, -TIPSIZE / 2.0f, 0.5f, 1.0f, 0xFFFFFFFF, 0.25f, 0.0f },
	{  TIPSIZE / 2.0f,  TIPSIZE / 2.0f, 0.5f, 1.0f, 0xFFFFFFFF, 0.25f, 1.0f },
	{ -TIPSIZE / 2.0f,  TIPSIZE / 2.0f, 0.5f, 1.0f, 0xFFFFFFFF, 0.0f , 1.0f },
};

CUSTOMVERTEX g_initBullet[] =
{
	{ -TIPSIZE / 2.0f, -TIPSIZE / 2.0f, 0.5f, 1.0f, 0xAAFFFFFF, 0.0f, 0.0f },
	{ TIPSIZE / 2.0f, -TIPSIZE / 2.0f, 0.5f, 1.0f, 0xAAFFFFFF, 1.0f, 0.0f },
	{ TIPSIZE / 2.0f, TIPSIZE / 2.0f, 0.5f, 1.0f, 0xAAFFFFFF, 1.0f, 1.0f },
	{ -TIPSIZE / 2.0f, TIPSIZE / 2.0f, 0.5f, 1.0f, 0xAAFFFFFF, 0.0f, 1.0f },
};

// �}�b�v�`�b�v�̃f�[�^���i�[���Ă�񎟌��z��
int map[MAP_HEIGHT][MAP_WIDTH];


// �Q�[���V�[���̐���֐�
void GameSceneControl()
{
	// �L�[�̃`�F�b�N�֐��Q
	KeyCheck(VK_LEFT, LEFT);
	KeyCheck(VK_RIGHT, RIGHT);
	KeyCheck(VK_UP, UP);
	KeyCheck(VK_DOWN, DOWN);
	KeyCheck(VK_SPACE, SPACE);
	KeyCheck('Z', FIRE);

	// �v���C���[�̃R���g���[���֐�
	PlayerControl();
	BulletControl();
}

// �Q�[���V�[���̕`��֐�
void GameSceneDraw()
{
	// �o�b�N�O���E���h�̒��_�����쐬����
	CUSTOMVERTEX backGround[4]
	{
		{ 0.f, 0.f, 1.f, 1.f, 0xFFFFFFFF, 0.f, 0.f },
		{ 1280.f, 0.f, 1.f, 1.f, 0xFFFFFFFF, 1.f, 0.f },
		{ 1280.f, 720.f, 1.f, 1.f, 0xFFFFFFFF, 1.f, 1.f },
		{ 0.f, 720.f, 1.f, 1.f, 0xFFFFFFFF, 0.f, 1.f }
	};



	// ���_���̎w��
	g_pDirect3DDevice->SetFVF(D3DFVF_CUSTOMVERTEX);

	// ��ʂ̏���
	g_pDirect3DDevice->Clear(0, NULL, D3DCLEAR_TARGET, D3DCOLOR_XRGB(0x00, 0x00, 0x00), 1.0, 0);
	// �`����J�n
	g_pDirect3DDevice->BeginScene();



	// �e�N�X�`�����X�e�[�W�Ɋ��蓖�Ă�
	g_pDirect3DDevice->SetTexture(0, g_pGameTexture[BACKGROUND_TEX]);
	// �`��
	g_pDirect3DDevice->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, backGround, sizeof(CUSTOMVERTEX));

	MapDraw();
	BulletDraw();
	PlayerDraw();

	// �`����I��
	g_pDirect3DDevice->EndScene();
	// ��ʂɕ\��
	g_pDirect3DDevice->Present(NULL, NULL, NULL, NULL);
}


void PlayerControl()
{
	//�v���C���[�̍����̃}�b�v��x�ʒu
	int playerLeftDownArrayX = int((g_playerState.posX - 25) / TIPSIZE);
	//�v���C���[�̉E���̃}�b�v��x�ʒu
	int playerRightDownArrayX = int((g_playerState.posX + 25) / TIPSIZE);


	// �����L�[��������Ă�ꍇ
	if (Key[LEFT] == ON)
	{
		// �������Ă邩�̃t���O�𗧂Ă�
		g_playerState.isLeft = true;

		//�v���C���[�̍��̃}�b�v��x�ʒu
		int playerArrayX = int((g_playerState.posX - TIPSIZE / 2) / TIPSIZE);
		//�v���C���[�̃}�b�v��y�ʒu
		int playerArrayY = int(g_playerState.posY / TIPSIZE);

		//���������Ȃ�������
		if (map[playerArrayY][playerArrayX] == 0)
		{
			g_playerState.posX -= MOVESPEED;
			if (g_playerState.dispPosX > 400.f || g_mapTip1[0].x >= 0)
			{
				g_playerState.dispPosX -= MOVESPEED;
			}
			else
			{
				for (int i = 0; i < 4; i++)
				{
					g_mapTip1[i].x += MOVESPEED;
					g_mapTip2[i].x += MOVESPEED;
				}
			}
		}
	}
	if (Key[RIGHT] == ON)
	{
		g_playerState.isLeft = false;
		//�v���C���[�̉E�̃}�b�v��x�ʒu
		int playerArrayX = int((g_playerState.posX + TIPSIZE / 2) / TIPSIZE);
		//�v���C���[�̃}�b�v��y�ʒu
		int playerArrayY = int(g_playerState.posY / TIPSIZE);
		//�E�������Ȃ�������
		if (map[playerArrayY][playerArrayX] == 0)
		{
			g_playerState.posX += MOVESPEED;
			if (g_playerState.dispPosX < 820.f)
			{
				g_playerState.dispPosX += MOVESPEED;
			}
			else
			{
				for (int i = 0; i < 4; i++)
				{
					g_mapTip1[i].x -= MOVESPEED;
					g_mapTip2[i].x -= MOVESPEED;
				}
			}
		}
	}

	if (Key[SPACE] == PUSH && !g_playerState.skyFlag)
	{
		g_playerState.jumpFlag = true;
		g_playerState.skyFlag = true;
		g_playerState.a = JUMP_POWER;
	}

	if (Key[SPACE] == ON && g_playerState.a > 0.f)
	{
		g_playerState.a = 0.f;
	}

	//�W�����v�������ɂ��̏����ɓ���
	if (g_playerState.jumpFlag)
	{
		//�v���C���[�̉��̃}�b�v�`�b�v������
		int playerUpArrayY = int((g_playerState.posY - TIPSIZE / 2) / TIPSIZE);
		if (map[playerUpArrayY ][playerLeftDownArrayX] != 0 || map[playerUpArrayY][playerRightDownArrayX] != 0)
		{
			//�㏸���łȂ��Ə㔻����s��Ȃ�
			if (g_playerState.a < 0)
			{
   				g_playerState.a = 0.8f;
			}
		}
		//�����x����d�͂�����
		g_playerState.a += GRAVITY;
		//���x���v���C���[�̍��W�ɓ����
		g_playerState.posY += g_playerState.a;


		int playerDownArrayY = int((g_playerState.posY + TIPSIZE / 2) / TIPSIZE);

		if (map[playerDownArrayY][playerLeftDownArrayX] == 1 || map[playerDownArrayY][playerRightDownArrayX] == 1)
		{
			//�������łȂ��ƒ��n������s��Ȃ�
			if (g_playerState.a > 0)
			{
				g_playerState.jumpFlag = false;
				g_playerState.skyFlag = false;
			}
		}
	}

	int playerDownArrayY = int((g_playerState.posY + TIPSIZE / 2) / TIPSIZE);
	//�W�����v�������ȊO�̗�������
	if (map[playerDownArrayY][playerLeftDownArrayX] == 0 || map[playerDownArrayY][playerRightDownArrayX] == 0)
	{
		if (g_playerState.jumpFlag == false)
		{
			g_playerState.a += GRAVITY;
			g_playerState.posY += g_playerState.a;
 			g_playerState.skyFlag = true;
		}
	}

	//�W�����v�������ȊO�̒��n����
	if (map[playerDownArrayY][playerLeftDownArrayX] == 1 || map[playerDownArrayY][playerRightDownArrayX] == 1)
	{
		if (g_playerState.jumpFlag == false)
		{
			//�����n�ʂȂ�L�����N�^�[�����̒n�ʂ̏�ɍ��W���ړ�����B
			g_playerState.posY = TIPSIZE * playerDownArrayY - TIPSIZE / 2;
			g_playerState.a = 0.f;
			g_playerState.skyFlag = false;
		}
	}
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

	g_playerState = { 1, 520.f, 380.f, 520.f, 380.f, 0, false, false, false ,false};

	//�e�̃t���O�̏�����
	for (int i = 0; i < BULLETMAX; i++)
	{
		g_bulletState[i].drawFlag = false;
		g_bulletState[i].initFlag = true;
		g_bulletState[i].posX = 0.f;
		g_bulletState[i].posY = 0.f;

		for (int n = 0; n < 4; n++)
		{
			g_bulletState[i].bullet[n] = g_initBullet[n];
		}
	}


	// �e�N�X�`����Ǎ�

	// �Q�[���V�[���̔w�i�̓ǂݍ���
	D3DXCreateTextureFromFile(
		g_pDirect3DDevice,
		"BackGround.png",
		&g_pGameTexture[BACKGROUND_TEX]);

	// �}�b�v�`�b�v�̓ǂݍ���
	D3DXCreateTextureFromFile(
		g_pDirect3DDevice,
		"mapGround.jpg",
		&g_pGameTexture[MAP_GROUND_TEX]);

	// �E�����̃v���C���[�L�����̓ǂݍ���
	D3DXCreateTextureFromFile(
		g_pDirect3DDevice,
		"chara.png",
		&g_pGameTexture[PLAYER_RIGHT_TEX]);

	// �������̃v���C���[�L�����̓ǂݍ���
	D3DXCreateTextureFromFile(
		g_pDirect3DDevice,
		"chara_reverse.png",
		&g_pGameTexture[PLAYER_LEFT_TEX]);

	D3DXCreateTextureFromFile(
		g_pDirect3DDevice,
		"Bubble.png",
		&g_pGameTexture[BULLET_TEX]);

	// csv�t�@�C���̓ǂݍ���
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

// Csv�̓ǂݍ��݊֐�
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
//�@UV�A�j���[�V����

void PlayerDraw()
{
	static int gameTime = 0;				//������
	gameTime++;					

	if ((gameTime % 10) == 0)				//�]�肪0�ɂȂ�x�Ɉȉ��̏������s��
	{
		if (g_playerState.animReverse)		//���o�[�X�͏Ȃ�
		{
			for (int i = 0; i < 4; i++)		//4��4�̒��_���w���Ă���
			{
				g_player[i].tu -= 0.25f;	// tu�l�̋��ߕ��̓s�N�`���̉����ɑS�̂�x���W�������Ă���
			}
		}
		//�����炩�̓��o�[�X�@���̏��g��Ȃ�
		else
		{
			for (int i = 0; i < 4; i++)		
			{
				g_player[i].tu += 0.25f;
			}
		}
		//���̓��o�[�X 1,2,3,4�̏��Ԃ��t��4,3,2,1�ɂ��Ă���B���̕��������������R�ɂȂ�
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
		drawPlayerVertex[i].x += g_playerState.dispPosX;
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
//�@�������܂�
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

void BulletDraw()
{
	CUSTOMVERTEX drawPlayerVertex[4];
	for (int i = 0; i < 4; i++)
	{
		drawPlayerVertex[i] = g_player[i];
		drawPlayerVertex[i].x += g_playerState.dispPosX;
		drawPlayerVertex[i].y += g_playerState.posY;
	}

	/*�����蔻��*/
	for (int i = 0; i < BULLETMAX; i++)
	{
		if (g_bulletState[i].bullet[2].x <= 0.0f)
		{
			g_bulletState[i].drawFlag = false;
			g_bulletState[i].initFlag = true;
		}

		if (g_bulletState[i].bullet[0].x >= 1280.0f)
		{
			g_bulletState[i].drawFlag = false;
			g_bulletState[i].initFlag = true;
		}

		int bulletArrayY = int(g_bulletState[i].posY / TIPSIZE);
		int bulletArrayX = int(g_bulletState[i].posX / TIPSIZE);

		if (map[bulletArrayY][bulletArrayX] == 1)
		{
			g_bulletState[i].drawFlag = false;
			g_bulletState[i].initFlag = true;
		}

	}

	/*�~�T�C�����˂̏����@�`������ōs���Ă���*/
	for (int i = 0; i < BULLETMAX; i++)
	{
		if (g_bulletState[i].initFlag == true)
		{
			g_bulletState[i].bullet[0].x = drawPlayerVertex[0].x;
			g_bulletState[i].bullet[0].y = drawPlayerVertex[0].y;

			g_bulletState[i].bullet[1].x = drawPlayerVertex[1].x;
			g_bulletState[i].bullet[1].y = drawPlayerVertex[1].y;

			g_bulletState[i].bullet[2].x = drawPlayerVertex[2].x;
			g_bulletState[i].bullet[2].y = drawPlayerVertex[2].y;

			g_bulletState[i].bullet[3].x = drawPlayerVertex[3].x;
			g_bulletState[i].bullet[3].y = drawPlayerVertex[3].y;
		}

		if (g_bulletState[i].drawFlag == true)
		{
			// �e�N�X�`�����X�e�[�W�Ɋ��蓖�Ă�
			g_pDirect3DDevice->SetTexture(0, g_pGameTexture[BULLET_TEX]);
			// �`��
			g_pDirect3DDevice->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, g_bulletState[i].bullet, sizeof(CUSTOMVERTEX));
		}
	}

}

void BulletControl()
{
	for (int i = 0; i < BULLETMAX; i++)
	{
		if (Key[FIRE] == PUSH && g_bulletState[i].drawFlag == false)
		{
			g_bulletState[i].drawFlag = true;
			g_bulletState[i].initFlag = false;
			g_bulletState[i].isLeft = g_playerState.isLeft;
			g_bulletState[i].posX = g_playerState.posX;
			g_bulletState[i].posY = g_playerState.posY;
			break;
		}
	}

	for (int i = 0; i < BULLETMAX; i++)
	{
		if (g_bulletState[i].drawFlag == true)
		{
			if (g_bulletState[i].isLeft)
			{
				g_bulletState[i].posX -= 10.f;
				for (int j = 0; j < 4; j++)
				{
					g_bulletState[i].bullet[j].x -= 10.f;
				}
			}
			else
			{
				g_bulletState[i].posX += 10.f;
				for (int j = 0; j < 4; j++)
				{
					g_bulletState[i].bullet[j].x += 10.f;
				}
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
