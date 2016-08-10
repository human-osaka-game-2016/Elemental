/**
*@file GameEnemyDraw.cpp
*@brief ゲームにおける敵、敵の弾、及び敵の爆発アニメーションの描画関数をまとめたファイルです.
*/

#include <d3dx9.h>
#include <d3dx9tex.h>
#include"draw_config.h"
#include"Main.h"
#include"GameSceneInit.h"
#include"GameSceneDraw.h"
#include"GameSceneControl.h"

// 敵描画
void EnemyDraw(CUSTOMVERTEX* enemy, ENEMYSTATE* enemyState)
{
	g_pDirect3DDevice->SetTexture(0, g_pGameTexture[ENEMY_TEX]);

	for (int j = 0; j < ENEMYMAX; j++)
	{
		for (int i = 0; i < 4; i++)
		{
			enemyState[j].enemy[i] = enemy[i];
			enemyState[j].enemy[i].x += enemyState[j].posX;
			enemyState[j].enemy[i].y += enemyState[j].posY;

		}

		if (enemyState[j].drawFlag)
		{
			g_pDirect3DDevice->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, enemyState[j].enemy, sizeof(CUSTOMVERTEX));	
		}
	}

}


// 敵の弾の描画
void EnemyBulletDraw(CUSTOMVERTEX* bullet, CUSTOMVERTEX* enemy, ENEMYSTATE* enemyState, BULLETSTATE* enemyBulletState)
{

	//弾の数だけ敵は打つ
	for (int i = 0; i < ENEMYBULLETMAX; i++)
	{
		if (enemyBulletState[i].initFlag == true)
		{
			//現在の弾の位置を代入
			for (int k = 0; k < 4; k++)
			{
				enemyBulletState[i].bullet[k] = bullet[k];
				enemyBulletState[i].bullet[k].x += enemyState[i].posX;
				enemyBulletState[i].bullet[k].y += enemyState[i].posY;
			}

		}

		//描画
		if (enemyBulletState[i].drawFlag == true)
		{
			g_pDirect3DDevice->SetTexture(0, g_pGameTexture[BULLET_ENEMY_TEX]);
			g_pDirect3DDevice->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, enemyBulletState[i].bullet, sizeof(CUSTOMVERTEX));
		}
	}


}


//爆発アニメーション(敵)
void  ExplosionAnimeEnemy(CUSTOMVERTEX* enemy, ENEMYSTATE* enemyState)
{

	//爆発エフェクトの頂点情報
	CUSTOMVERTEX explosion02[] =
	{
		{ -EFECTTEXSIZE, -EFECTTEXSIZE, 0.5f, 1.0f, 0xFFFFFFFF,  0.0f, 0.25f },
		{  EFECTTEXSIZE, -EFECTTEXSIZE, 0.5f, 1.0f, 0xFFFFFFFF, 0.25f, 0.25f },
		{  EFECTTEXSIZE,  EFECTTEXSIZE, 0.5f, 1.0f, 0xFFFFFFFF, 0.25f,  0.5f },
		{ -EFECTTEXSIZE,  EFECTTEXSIZE, 0.5f, 1.0f, 0xFFFFFFFF,  0.0f,  0.5f },
	};


	g_pDirect3DDevice->SetTexture(0, g_pGameTexture[EXPLOSION_TEX]);


	for (int j = 0; j < ENEMYMAX; j++)
	{
		//元のデータを保持するための器
		static CUSTOMVERTEX explo02_defu[ENEMYMAX][4];

		if (enemyState[j].animeExplosion)
		{
			//アニメーション(敵の爆発)を動かすための時間をカウント
			static int gameTimeAnimeE = 0;
			gameTimeAnimeE++;

			if ((gameTimeAnimeE % ANIMETION_TIME) == 0)
			{
				for (int i = 0; i < 4; i++)
				{
					explo02_defu[j][i].tu += 0.25f;
				}

			}
			/*爆発する位置を求める(敵の位置)*/
			CUSTOMVERTEX drawEnemyVertex[4];
			for (int i = 0; i < 4; i++)
			{
				drawEnemyVertex[i] = enemy[i];
				drawEnemyVertex[i].x += enemyState[j].posX;
				drawEnemyVertex[i].y += enemyState[j].posY;
			}

			//爆発画像を描画する位置を空の変数にいれる
			CUSTOMVERTEX drawExplosiinVertex[4];
			for (int i = 0; i < 4; i++)
			{
				drawExplosiinVertex[i] = explo02_defu[j][i];
				drawExplosiinVertex[i].x += drawEnemyVertex[i].x;
				drawExplosiinVertex[i].y += drawEnemyVertex[i].y;
			}

			g_pDirect3DDevice->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, drawExplosiinVertex, sizeof(CUSTOMVERTEX));

			if (explo02_defu[j][2].tu >= 1.0f)
			{
				enemyState[j].animeExplosion = false;
				enemyState[j].posX = ENEMY_X_DEFU + (ENEMY_POS_X * j);
				enemyState[j].posY = 0 - (ENEMY_POS_Y * j);
				enemyState[j].moveDown = true;
				//enemyState[j].drawFlag = true;
			}
		}
		else
		{
			for (int i = 0; i < 4; i++)
			{
				explo02_defu[j][i] = explosion02[i];
			}
		}
	}
}
