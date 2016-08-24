/**
 * @file EnemyDraw.cpp
 * @breif �S�Ă̓G�̕`��t�@�C��

 * �S�Ă̓G�̕`��ɕK�v�ȏ����������Ă���

 */

#include "../GameScene/GameSceneDraw.h"
#include "../GameScene/GameSceneInit.h"

// �R�h���̕`��֐�
void Draw_Kodora()
{
	// �R�h���̒��_���
	CUSTOMVERTEX Kodora[4] =
	{
		{ 0.0f, 0.0f, 0.5f, 1.0f, 0xFFFFFFFF, 0.0f, 0.0f },
		{ 128.0f, 0.0f, 0.5f, 1.0f, 0xFFFFFFFF, -1.0f, 0.0f },
		{ 128.0f, 128.0f, 0.5f, 1.0f, 0xFFFFFFFF, -1.0f, 1.0f },
		{ 0.0f, 128.0f, 0.5f, 1.0f, 0xFFFFFFFF, 0.0f, 1.0f },

	};
	
		CUSTOMVERTEX drawkodora[4];

		for (int j = 0; j < KODORA_MAX; j++)
		{
			for (int i = 0; i < 4; i++)
			{
				drawkodora[i] = Kodora[i];
				drawkodora[i].x += g_kodora[j].posX;
				drawkodora[i].y += g_kodora[j].posY;
			}

			if (g_kodora[j].drawFlag == true)
			{
				Draw_Obj(g_pTexture[KODORA_TEX], drawkodora);
			}
		}
}

// �X�P���g���̕`��֐�

//void Draw_Skeleton()
//{
//	// �X�P���g���̒��_���
//	CUSTOMVERTEX Skeleton[4] =
//	{
//		{ 0.0f, 0.0f, 0.5f, 1.0f, 0xFFFFFFFF, 0.0f, 0.0f },
//		{ 128.0f, 0.0f, 0.5f, 1.0f, 0xFFFFFFFF, 0.25f, 0.0f },
//		{ 128.0f, 128.0f, 0.5f, 1.0f, 0xFFFFFFFF, 0.25f, 1.0f },
//		{ 0.0f, 128.f, 0.5f, 1.0f, 0xFFFFFFFF, 0.0f, 1.0f },
//	};
//
//	CUSTOMVERTEX drawskeleton[4];
//	for (int i = 0; i < 4; i++)
//	{
//		drawskeleton[i] = Skeleton[i];
//		drawskeleton[i].x += g_enemy2.posX;
//		drawskeleton[i].y += g_enemy2.posY;
//	}
//	Draw_Obj(g_pTexture[SKERETON_TEX], drawskeleton);
//}