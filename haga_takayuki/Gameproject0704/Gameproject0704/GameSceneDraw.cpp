/**
*@file GameSceneDraw.cpp
*@brief ゲームの描画関連をまとめているcpp.
*/
#include <d3dx9.h>
#include <d3dx9tex.h>
#include"draw_config.h"
#include"Main.h"
#include"GameSceneInit.h"
#include"GameSceneDraw.h"
#include"GameSceneControl.h"
#include"GameScore.h"
#include"GameScoreDraw.h"
#include"GamePlayerDraw.h"
#include"GameEnemyDraw.h"


//ゲームの描画関数をまとめた関数
void GameDraw(PLAYERSTATE* playerState, BULLETSTATE* playerBulletState, ENEMYSTATE* enemyState, BULLETSTATE* enemyBulletState, BACKGROUNDSTATE* backgroundState, SCORESTATE* hiscore, FLAGSTATE* flags)
{

	//テキストの位置
	TEXTSTATE textState = { TEXT_X_POS, TEXT_Y_POS };

	//プレイヤーの頂点情報
	CUSTOMVERTEX player[] =
	{
		{ -TEXSIZE / 2.0f, -TEXSIZE / 2.0f, 0.5f, 1.0f, 0xFFFFFFFF, 0.0f, 0.0f },
		{  TEXSIZE / 2.0f, -TEXSIZE / 2.0f, 0.5f, 1.0f, 0xFFFFFFFF, 1.0f, 0.0f },
		{  TEXSIZE / 2.0f,  TEXSIZE / 2.0f, 0.5f, 1.0f, 0xFFFFFFFF, 1.0f, 1.0f },
		{ -TEXSIZE / 2.0f,  TEXSIZE / 2.0f, 0.5f, 1.0f, 0xFFFFFFFF, 0.0f, 1.0f },
	};

	//敵の頂点情報
	CUSTOMVERTEX enemy[] =
	{
		{ -TEXSIZE / 2.0f, -TEXSIZE / 2.0f, 0.5f, 1.0f, 0xFFFFFFFF, 0.0f, 0.0f },
		{  TEXSIZE / 2.0f, -TEXSIZE / 2.0f, 0.5f, 1.0f, 0xFFFFFFFF, 1.0f, 0.0f },
		{  TEXSIZE / 2.0f,  TEXSIZE / 2.0f, 0.5f, 1.0f, 0xFFFFFFFF, 1.0f, 1.0f },
		{ -TEXSIZE / 2.0f,  TEXSIZE / 2.0f, 0.5f, 1.0f, 0xFFFFFFFF, 0.0f, 1.0f },
	};


	//弾の頂点情報
	CUSTOMVERTEX bullet[] =
	{
		{ -TEXSIZE / 4.0f, -TEXSIZE / 4.0f, 0.5f, 1.0f, 0xFFFFFFFF, 0.0f, 0.0f },
		{  TEXSIZE / 4.0f, -TEXSIZE / 4.0f, 0.5f, 1.0f, 0xFFFFFFFF, 1.0f, 0.0f },
		{  TEXSIZE / 4.0f,  TEXSIZE / 4.0f, 0.5f, 1.0f, 0xFFFFFFFF, 1.0f, 1.0f },
		{ -TEXSIZE / 4.0f,  TEXSIZE / 4.0f, 0.5f, 1.0f, 0xFFFFFFFF, 0.0f, 1.0f },
	};

	//スコアの数字の頂点情報
	CUSTOMVERTEX scorenumber[] =
	{
		{ -SCORETEXSIZE, -SCORETEXSIZE, 0.5f, 1.0f, 0xFFFFFFFF,   0.0f,   0.0f },
		{  SCORETEXSIZE, -SCORETEXSIZE, 0.5f, 1.0f, 0xFFFFFFFF, 0.125f,   0.0f },
		{  SCORETEXSIZE,  SCORETEXSIZE, 0.5f, 1.0f, 0xFFFFFFFF, 0.125f, 0.125f },
		{ -SCORETEXSIZE,  SCORETEXSIZE, 0.5f, 1.0f, 0xFFFFFFFF,   0.0f, 0.125f },
	};

	//描画開始
	DrawStart(g_pDirect3DDevice, D3DFVF_CUSTOMVERTEX);

	//背景描画
	BgDraw( backgroundState);
	//プレイヤーの弾描画
	PlayerBulletDraw(player, playerBulletState, playerState);
	//プレイヤー描画
	PlayDraw(player, playerState);
	//敵の弾描画
	EnemyBulletDraw(bullet, enemy, enemyState, enemyBulletState);
	//敵の描画
	EnemyDraw(enemy, enemyState);
	//敵の爆発描画
	ExplosionAnimeEnemy(enemy, enemyState);
	//プレイヤー爆発描画
	ExplosionAnimePlayer(player, playerState);
	//ライフ描画
	LifeDraw(scorenumber, playerState);
	//ゲーム中のスコア描画
	GameSceneScoreDraw(scorenumber, playerState);
	
	if (flags->titleScene)
	{
		//タイトル描画
		TitleDraw(flags);
		//ハイスコア描画
		GameSceneHiScoreDraw(scorenumber, hiscore);
	}

	//「Zボタンを押してください」と「GAME OVER」描画
	Text01Draw(&textState,flags);
	//「Complete」「Warning」を描画
	Text02Draw(&textState, flags);
	
	//描画終了&表示
	DrawEnd(g_pDirect3DDevice);
}

//背景描画
void BgDraw(BACKGROUNDSTATE*	backgroundState)
{
	//	背景1枚目の頂点情報
	CUSTOMVERTEX background01[] = {
		{				 backgroundState[BG_ONE].posX,				backgroundState[BG_ONE].posY, 1.0f, 1.0f, 0xFFFFFFFF, 0.0f, 0.0f },
		{ backgroundState[BG_ONE].posX + BACKGROUND_W,	backgroundState[BG_ONE].posY, 1.0f, 1.0f, 0xFFFFFFFF, 1.0f, 0.0f },
		{ backgroundState[BG_ONE].posX + BACKGROUND_W, backgroundState[BG_ONE].posY + BACKGROUND_H, 1.0f, 1.0f, 0xFFFFFFFF, 1.0f, 1.0f },
		{				 backgroundState[BG_ONE].posX, backgroundState[BG_ONE].posY + BACKGROUND_H, 1.0f, 1.0f, 0xFFFFFFFF, 0.0f, 1.0f },
	};

	//	背景2枚目の頂点情報
	CUSTOMVERTEX background02[] = {
		{				 backgroundState[BG_TWO].posX,				  backgroundState[BG_TWO].posY, 1.0f, 1.0f, 0xFFFFFFFF, 0.0f, 0.0f },
		{ backgroundState[BG_TWO].posX + BACKGROUND_W,				  backgroundState[BG_TWO].posY, 1.0f, 1.0f, 0xFFFFFFFF, 1.0f, 0.0f },
		{ backgroundState[BG_TWO].posX + BACKGROUND_W, backgroundState[BG_TWO].posY + BACKGROUND_H, 1.0f, 1.0f, 0xFFFFFFFF, 1.0f, 1.0f },
		{				 backgroundState[BG_TWO].posX, backgroundState[BG_TWO].posY + BACKGROUND_H, 1.0f, 1.0f, 0xFFFFFFFF, 0.0f, 1.0f },
	};

	// 背景描画
	g_pDirect3DDevice->SetTexture(0, g_pGameTexture[BACKGROUND_TEX]);
	g_pDirect3DDevice->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, background01, sizeof(CUSTOMVERTEX));
	g_pDirect3DDevice->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, background02, sizeof(CUSTOMVERTEX));

	
}

//タイトル描画
void TitleDraw(FLAGSTATE* flags)
{
	if (flags->titleScene)
	{
		//タイトルの頂点情報
		CUSTOMVERTEX title[] = {
			{				 BACKGROUND_X_DEFU,         0.0f, 1.0f, 1.0f, 0xFFFFFFFF, 0.0f, 0.0f },
			{ BACKGROUND_X_DEFU + BACKGROUND_W,         0.0f, 1.0f, 1.0f, 0xFFFFFFFF, 1.0f, 0.0f },
			{ BACKGROUND_X_DEFU + BACKGROUND_W, BACKGROUND_H, 1.0f, 1.0f, 0xFFFFFFFF, 1.0f, 1.0f },
			{				 BACKGROUND_X_DEFU, BACKGROUND_H, 1.0f, 1.0f, 0xFFFFFFFF, 0.0f, 1.0f },
		};

		g_pDirect3DDevice->SetTexture(0, g_pGameTexture[TITLE_TEX]);
		g_pDirect3DDevice->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2,title, sizeof(CUSTOMVERTEX));
	}
}

//文字描画(テキスト「Zボタンを押してね」・「GAME OVER」中でゲームオーバー処理もしている)
void Text01Draw(TEXTSTATE* textState, FLAGSTATE* flags)
{
	g_pDirect3DDevice->SetTexture(0, g_pGameTexture[TEXT01_TEX]);

	//テキストの頂点情報
	CUSTOMVERTEX text[] = {
		{	   0.0f,      0.0f, 1.0f, 1.0f, 0xFFFFFFFF, 0.0f, 0.0f },
		{ TEXT_SIZE,      0.0f, 1.0f, 1.0f, 0xFFFFFFFF, 1.0f, 0.0f },
		{ TEXT_SIZE, TEXT_SIZE, 1.0f, 1.0f, 0xFFFFFFFF, 1.0f, 0.5f },
		{      0.0f, TEXT_SIZE, 1.0f, 1.0f, 0xFFFFFFFF, 0.0f, 0.5f },
	};

	//描画用変数
	CUSTOMVERTEX drawTextVertex[4];
	if (flags->titleScene)							//「Zボタンを押してね」と表示
	{
		for (int i = 0; i < 4;i++)
		{
			drawTextVertex[i] = text[i];
			drawTextVertex[i].x += textState->posX;
			drawTextVertex[i].y += textState->posY;
		}

		
			g_pDirect3DDevice->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, drawTextVertex, sizeof(CUSTOMVERTEX));
		
	}
	else if (flags->gameEnd)					//ゲームオーバーの文字を表示
	{
		
		//ゲームオーバーしてからの時間をカウント
		static int gameTimeEnd = 0;							
		gameTimeEnd++;

		for (int i = 0; i < 4; i++)
		{
			drawTextVertex[i] = text[i];
			drawTextVertex[i].tv += TEXT_TV;
			drawTextVertex[i].x += textState->posX;
			drawTextVertex[i].y += textState->posY;
		}

		g_pDirect3DDevice->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, drawTextVertex, sizeof(CUSTOMVERTEX));

		if (flags->gameEnd == true && (gameTimeEnd % END_WAIT_TIME) == 0)
		{
			gameTimeEnd = 0;
			flags->saveScore = true;
		
		}
	}
}

//文字描画(テキスト「Complete」・「WARNING」中でゲームオーバー処理もしている)
void Text02Draw(TEXTSTATE* textState, FLAGSTATE* flags)
{
	g_pDirect3DDevice->SetTexture(0, g_pGameTexture[TEXT02_TEX]);

	//テキストの頂点情報
	CUSTOMVERTEX text02[] = {
		{      0.0f,      0.0f, 1.0f, 1.0f, 0xFFFFFFFF, 0.0f,  0.0f },
		{ TEXT_SIZE,      0.0f, 1.0f, 1.0f, 0xFFFFFFFF, 1.0f,  0.0f },
		{ TEXT_SIZE, TEXT_SIZE, 1.0f, 1.0f, 0xFFFFFFFF, 1.0f, 0.25f },
		{      0.0f, TEXT_SIZE, 1.0f, 1.0f, 0xFFFFFFFF, 0.0f, 0.25f },
	};

	if (flags->gameComplete)//「Complete」と表示
	{
		//クリアしてからの時間をカウント
		static int gameTimeComplete = 0;
		gameTimeComplete++;
		//描画用変数
		CUSTOMVERTEX drawTextVertex[4];
									
		
			for (int i = 0; i < 4; i++)
			{
				drawTextVertex[i] = text02[i];
				drawTextVertex[i].x += textState->posX;
				drawTextVertex[i].y += textState->posY;
			}

			g_pDirect3DDevice->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, drawTextVertex, sizeof(CUSTOMVERTEX));

			if (flags->gameComplete == true && (gameTimeComplete % END_WAIT_TIME) == 0)
			{
				gameTimeComplete = 0;
				flags->saveScore = true;
			}
	}
}



