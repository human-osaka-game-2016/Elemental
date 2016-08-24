/**
 * @file GameSceneDraw.cpp
 * @breif �`��̊�ՂɂȂ�t�@�C��

 * �Q�[���S�̂̕`��ɕK�v�ȏ����������Ă���

 */

#include <stdio.h>
#include <stdlib.h>
#include "GameSceneDraw.h"
#include "../GameScene/GameSceneInit.h"
#include "../Player/PlayerDraw.h"
#include "../Enemy/EnemyDraw.h"
#include "../Gmmick/WindGimmick_Draw.h"

float g_ScreenOriginX = 0.0f;	// X���W�̉�ʒ[�����_�Ƃ��Ă���
float g_ScreenOriginY = 0.0f;	// Y���W�̉�ʒ[�����_�Ƃ��Ă���

LPDIRECT3DTEXTURE9 g_pTexture[TEX_MAX];	

// csv�œǂݍ��ޔ͈�
int map[MAP_HEIGHT][MAP_WIDTH];

// �`��֐�
void Render()
{
	
	CUSTOMVERTEX background[4] =
	{
		{ 0.0f, 0.0f, 0.5f, 1.0f, 0xFFFFFFFF, 0.0f, 0.0f },
		{ 1440.f, 0.0f, 0.5f, 1.0f, 0xFFFFFFFF, 1.0f, 0.0f },
		{ 1440.f, 810, 0.5f, 1.0f, 0xFFFFFFFF, 1.0f, 1.0f },
		{ 0.0f, 810, 0.5f, 1.0f, 0xFFFFFFFF, 0.0f, 1.0f },

	};
	
	Draw_Start();
	Draw_Obj(g_pTexture[BACKGROUND_TEX], background);
	Draw_Map();
	Draw_Kodora();
	Player_Draw();
	Player_Aura_Draw(g_player.flamedrawFlag, PLAYER_FLAME_TEX);
	Player_Aura_Draw(g_player.icedrawFlag, PLAYER_ICE_TEX);
	Player_Aura_Draw(g_player.winddrawFlag, PLAYER_WIND_TEX);
	Player_Bullet_Draw();
	WindGimmick_Draw();
	Draw_End();
}


// �t�@�C����ǂݍ��ނ��߂̊֐�
void Load_Map(const char* _mapdata)
{
	FILE*  fp;
	fopen_s(&fp, _mapdata, "r");	// _mapdate�ɏ����ꂽ�t�@�C����ǂݎ���Ă��邾��

	for (int i = 0; i < MAP_HEIGHT; i++)
	{
		for (int j = 0; j < MAP_WIDTH; j++)
		{
			fscanf_s(fp, "%d,", &map[i][j], _countof(map));		
		}
	}
}

// csv�ɏ������}�b�v���𔽉f�����Ă���
void Draw_Map()
{
	// �}�b�v�`�b�v�̒��_���
	CUSTOMVERTEX Maptip[4] =
	{
		{ 0.0f, 0.0f, 0.5f, 1.0f, 0xFFFFFFFF, 0.0f, 0.0f },
		{ TIPSIZE, 0.0f, 0.5f, 1.0f, 0xFFFFFFFF, 1.0f, 0.0f },
		{ TIPSIZE, TIPSIZE, 0.5f, 1.0f, 0xFFFFFFFF, 1.0f, 1.0f },
		{ 0.0f, TIPSIZE, 0.5f, 1.0f, 0xFFFFFFFF, 0.0f, 1.0f },

	};

	for (int y = 0; y < MAP_HEIGHT; y++)
	{
		for (int x = 0; x < MAP_WIDTH; x++)
		{
			if (map[y][x] == 1)						// �ǂ݂��񂾃t�@�C����1�Ə�����Ă��鏊�͎w�肵���摜��`�悷��悤�ɂ��Ă���
			{
				CUSTOMVERTEX drawmap[4];			// ���CUSTOMVERTEX�p��
				for (int i = 0; i < 4; i++)
				{
					drawmap[i] = Maptip[i];		// �}�b�v�`�b�v�̒��_�������CUSTOMVERTEX�ɑ�����Ă���
				}

				// ���̂܂܂���1�����`�悳��Ȃ��̂ŉ��̏����Ŏw�肵���͈͕����ׂĕ`�悷��悤�ɂ��Ă���
				for (int i = 0; i < 4; i++)
				{
					drawmap[i].x += (x * TIPSIZE);	// ���̃`�b�v��`�悷�邽�߂Ƀ`�b�v�̑傫�����������ĕ`�悵�Ă���
					drawmap[i].y += (y * TIPSIZE);	// ��ɓ���
				}
				Draw_Obj(g_pTexture[MAP_GROUND_TEX], drawmap);
			}
		}
	}
}

void Draw_Obj(LPDIRECT3DTEXTURE9   _pTexture, CUSTOMVERTEX _setdraw[]) 
{
	CUSTOMVERTEX drawobj[4];

	for (int i = 0; i < 4; i++) 
	{
		drawobj[i] = _setdraw[i];
		drawobj[i].x -= g_ScreenOriginX;
		drawobj[i].y -= g_ScreenOriginY;
	}

	Draw_Display(_pTexture, drawobj);
}
