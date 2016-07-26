// �t�@�C����ǂݍ��ނ��߂ɂ̓C���N���[�h���Ȃ���΂Ȃ�Ȃ�
#include <stdio.h>
//�@�����̃w�b�_�[
#include "GameSceneDraw.h"

/* 
�e�N�X�`����\�邽�߂ɂ͂����錾���Ȃ���΂Ȃ�Ȃ�
�O���[�o���ɂ��Ă�̂�g_�����Ă���
*/

LPDIRECT3DTEXTURE9 g_pTexture[TEX_MAX];

/*
�}�b�v�`�b�v�̒��_�������Ă���
����cpp�Ŏg�����߃O���[�o���ɂ����Ă���
�O���[�o���ɂ��Ă���̂�g_�����Ă���
*/
CUSTOMVERTEX g_maptip[4] =
{
	{ 0.0f, 0.0f, 0.5f, 1.0f, 0xFFFFFFFF, 0.0f, 0.0f },
	{ TIPSIZE, 0.0f, 0.5f, 1.0f, 0xFFFFFFFF, 1.0f, 0.0f },
	{ TIPSIZE, TIPSIZE, 0.5f, 1.0f, 0xFFFFFFFF, 1.0f, 1.0f },
	{ 0.0f, TIPSIZE, 0.5f, 1.0f, 0xFFFFFFFF, 0.0f, 1.0f },

};

// csv�œǂݍ��ޔ͈�
int map[MAP_HEIGHT][MAP_WIDTH];

void Render()
{
	// �w�i�̒��_���
	CUSTOMVERTEX background[4] =
	{
		{ 0.0f, 0.0f, 0.5f, 1.0f, 0xFFFFFFFF, 0.0f, 0.0f },
		{ 1280.f, 0.0f, 0.5f, 1.0f, 0xFFFFFFFF, 1.0f, 0.0f },
		{ 1280.f, 720, 0.5f, 1.0f, 0xFFFFFFFF, 1.0f, 1.0f },
		{ 0.0f, 720, 0.5f, 1.0f, 0xFFFFFFFF, 0.0f, 1.0f },

	};
	// ���̊֐����ĂׂΕ`��̑O�̏���������(���C�u�����֐�)
	Draw_Start();
	// ���̊֐����ĂׂΕ`��ł���(���C�u�����֐�)
	Draw_Display(g_pTexture[BACKGROUND_TEX], background);
	Map_Draw();
	// �`����I��点��(���C�u�����֐�)
	Draw_End();
}


// �t�@�C����ǂݍ��ނ��߂̊֐�
void Map_Load(const char* mapdata)
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

// csv�ɏ������}�b�v���𔽉f�����Ă���
void Map_Draw()
{
	for (int y = 0; y < MAP_HEIGHT; y++)
	{
		for (int x = 0; x < MAP_WIDTH; x++)
		{
			if (map[y][x] == 1)
			{
				CUSTOMVERTEX drawmap[4];
				for (int i = 0; i < 4; i++)
				{
					drawmap[i] = g_maptip[i];
				}

				for (int i = 0; i < 4; i++)
				{
					drawmap[i].m_x += (x * TIPSIZE);
					drawmap[i].m_y += (y * TIPSIZE);
				}
				Draw_Display(g_pTexture[MAP_GROUND_TEX], drawmap);
			}
		}
	}
}