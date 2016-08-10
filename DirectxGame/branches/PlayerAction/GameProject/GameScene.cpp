#include <d3d9.h>
#include <d3dx9.h>
#include "GameScene.h"
#include <stdio.h>

#define MOVESPEED 5.f
#define JUMP_POWER -20.f
#define GRAVITY 0.6f
#define BULLETMAX 5

// ゲームシーンの画像情報を入れておく配列
LPDIRECT3DTEXTURE9			g_pGameTexture[GAMESCENE_MAX];	

// キー情報を格納する変数
KEYSTATE Key[KEYMAX];

int PreKey[KEYMAX] = { 0 };

int KeyState[4] = { 0 };

PLAYERSTATE g_playerState;
BULLETSTATE g_bulletState[BULLETMAX];

// 氷のチップの頂点情報
CUSTOMVERTEX g_mapTip1[] =
{
	{ 0.0f   , 0.0f   , 0.5f, 1.0f, 0xFFFFFFFF, 0.0f, 0.0f },
	{ TIPSIZE, 0.0f   , 0.5f, 1.0f, 0xFFFFFFFF, 0.5f, 0.0f },
	{ TIPSIZE, TIPSIZE, 0.5f, 1.0f, 0xFFFFFFFF, 0.5f, 1.0f },
	{ 0.0f   , TIPSIZE, 0.5f, 1.0f, 0xFFFFFFFF, 0.0f, 1.0f },
};

// 土のチップの頂点情報
CUSTOMVERTEX g_mapTip2[] =
{
	{ 0.0f   , 0.0f   , 0.5f, 1.0f, 0xFFFFFFFF, 0.5f, 0.0f },
	{ TIPSIZE, 0.0f   , 0.5f, 1.0f, 0xFFFFFFFF, 1.0f, 0.0f },
	{ TIPSIZE, TIPSIZE, 0.5f, 1.0f, 0xFFFFFFFF, 1.0f, 1.0f },
	{ 0.0f   , TIPSIZE, 0.5f, 1.0f, 0xFFFFFFFF, 0.5f, 1.0f },
};

// プレイヤーキャラの頂点情報
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

// マップチップのデータを格納してる二次元配列
int map[MAP_HEIGHT][MAP_WIDTH];


// ゲームシーンの制御関数
void GameSceneControl()
{
	// キーのチェック関数群
	KeyCheck(VK_LEFT, LEFT);
	KeyCheck(VK_RIGHT, RIGHT);
	KeyCheck(VK_UP, UP);
	KeyCheck(VK_DOWN, DOWN);
	KeyCheck(VK_SPACE, SPACE);
	KeyCheck('Z', FIRE);

	// プレイヤーのコントロール関数
	PlayerControl();
	BulletControl();
}

// ゲームシーンの描画関数
void GameSceneDraw()
{
	// バックグラウンドの頂点情報を作成する
	CUSTOMVERTEX backGround[4]
	{
		{ 0.f, 0.f, 1.f, 1.f, 0xFFFFFFFF, 0.f, 0.f },
		{ 1280.f, 0.f, 1.f, 1.f, 0xFFFFFFFF, 1.f, 0.f },
		{ 1280.f, 720.f, 1.f, 1.f, 0xFFFFFFFF, 1.f, 1.f },
		{ 0.f, 720.f, 1.f, 1.f, 0xFFFFFFFF, 0.f, 1.f }
	};



	// 頂点情報の指定
	g_pDirect3DDevice->SetFVF(D3DFVF_CUSTOMVERTEX);

	// 画面の消去
	g_pDirect3DDevice->Clear(0, NULL, D3DCLEAR_TARGET, D3DCOLOR_XRGB(0x00, 0x00, 0x00), 1.0, 0);
	// 描画を開始
	g_pDirect3DDevice->BeginScene();



	// テクスチャをステージに割り当てる
	g_pDirect3DDevice->SetTexture(0, g_pGameTexture[BACKGROUND_TEX]);
	// 描画
	g_pDirect3DDevice->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, backGround, sizeof(CUSTOMVERTEX));

	MapDraw();
	BulletDraw();
	PlayerDraw();

	// 描画を終了
	g_pDirect3DDevice->EndScene();
	// 画面に表示
	g_pDirect3DDevice->Present(NULL, NULL, NULL, NULL);
}


void PlayerControl()
{
	//プレイヤーの左下のマップのx位置
	int playerLeftDownArrayX = int((g_playerState.posX - 25) / TIPSIZE);
	//プレイヤーの右下のマップのx位置
	int playerRightDownArrayX = int((g_playerState.posX + 25) / TIPSIZE);


	// 左矢印キーが押されてる場合
	if (Key[LEFT] == ON)
	{
		// 左向いてるかのフラグを立てる
		g_playerState.isLeft = true;

		//プレイヤーの左のマップのx位置
		int playerArrayX = int((g_playerState.posX - TIPSIZE / 2) / TIPSIZE);
		//プレイヤーのマップのy位置
		int playerArrayY = int(g_playerState.posY / TIPSIZE);

		//左が何もなかったら
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
		//プレイヤーの右のマップのx位置
		int playerArrayX = int((g_playerState.posX + TIPSIZE / 2) / TIPSIZE);
		//プレイヤーのマップのy位置
		int playerArrayY = int(g_playerState.posY / TIPSIZE);
		//右が何もなかったら
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

	//ジャンプ処理中にこの処理に入る
	if (g_playerState.jumpFlag)
	{
		//プレイヤーの下のマップチップを見る
		int playerUpArrayY = int((g_playerState.posY - TIPSIZE / 2) / TIPSIZE);
		if (map[playerUpArrayY ][playerLeftDownArrayX] != 0 || map[playerUpArrayY][playerRightDownArrayX] != 0)
		{
			//上昇中でないと上判定を行わない
			if (g_playerState.a < 0)
			{
   				g_playerState.a = 0.8f;
			}
		}
		//初速度から重力を引く
		g_playerState.a += GRAVITY;
		//速度をプレイヤーの座標に入れる
		g_playerState.posY += g_playerState.a;


		int playerDownArrayY = int((g_playerState.posY + TIPSIZE / 2) / TIPSIZE);

		if (map[playerDownArrayY][playerLeftDownArrayX] == 1 || map[playerDownArrayY][playerRightDownArrayX] == 1)
		{
			//落下中でないと着地判定を行わない
			if (g_playerState.a > 0)
			{
				g_playerState.jumpFlag = false;
				g_playerState.skyFlag = false;
			}
		}
	}

	int playerDownArrayY = int((g_playerState.posY + TIPSIZE / 2) / TIPSIZE);
	//ジャンプ処理中以外の落下処理
	if (map[playerDownArrayY][playerLeftDownArrayX] == 0 || map[playerDownArrayY][playerRightDownArrayX] == 0)
	{
		if (g_playerState.jumpFlag == false)
		{
			g_playerState.a += GRAVITY;
			g_playerState.posY += g_playerState.a;
 			g_playerState.skyFlag = true;
		}
	}

	//ジャンプ処理中以外の着地処理
	if (map[playerDownArrayY][playerLeftDownArrayX] == 1 || map[playerDownArrayY][playerRightDownArrayX] == 1)
	{
		if (g_playerState.jumpFlag == false)
		{
			//下が地面ならキャラクターをその地面の上に座標を移動する。
			g_playerState.posY = TIPSIZE * playerDownArrayY - TIPSIZE / 2;
			g_playerState.a = 0.f;
			g_playerState.skyFlag = false;
		}
	}
}


// ゲームシーンの初期化関数
void GameSceneInit()
{
	// 描画の設定
	g_pDirect3DDevice->SetRenderState(D3DRS_ALPHABLENDENABLE, true);
	g_pDirect3DDevice->SetRenderState(D3DRS_SRCBLEND, D3DBLEND_SRCALPHA);  //SRCの設定
	g_pDirect3DDevice->SetRenderState(D3DRS_DESTBLEND, D3DBLEND_INVSRCALPHA);
	g_pDirect3DDevice->SetRenderState(D3DRS_DIFFUSEMATERIALSOURCE, D3DMCS_COLOR1);

	g_pDirect3DDevice->SetTextureStageState(0, D3DTSS_COLORARG1, D3DTA_TEXTURE);
	g_pDirect3DDevice->SetTextureStageState(0, D3DTSS_COLORARG2, D3DTA_DIFFUSE);

	g_pDirect3DDevice->SetTextureStageState(0, D3DTSS_COLOROP, D3DTOP_MODULATE);

	g_pDirect3DDevice->SetTextureStageState(0, D3DTSS_ALPHAARG1, D3DTA_TEXTURE);
	g_pDirect3DDevice->SetTextureStageState(0, D3DTSS_ALPHAARG2, D3DTA_DIFFUSE);

	g_pDirect3DDevice->SetTextureStageState(0, D3DTSS_ALPHAOP, D3DTOP_MODULATE);

	g_playerState = { 1, 520.f, 380.f, 520.f, 380.f, 0, false, false, false ,false};

	//弾のフラグの初期化
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


	// テクスチャを読込

	// ゲームシーンの背景の読み込み
	D3DXCreateTextureFromFile(
		g_pDirect3DDevice,
		"BackGround.png",
		&g_pGameTexture[BACKGROUND_TEX]);

	// マップチップの読み込み
	D3DXCreateTextureFromFile(
		g_pDirect3DDevice,
		"mapGround.jpg",
		&g_pGameTexture[MAP_GROUND_TEX]);

	// 右向きのプレイヤーキャラの読み込み
	D3DXCreateTextureFromFile(
		g_pDirect3DDevice,
		"chara.png",
		&g_pGameTexture[PLAYER_RIGHT_TEX]);

	// 左向きのプレイヤーキャラの読み込み
	D3DXCreateTextureFromFile(
		g_pDirect3DDevice,
		"chara_reverse.png",
		&g_pGameTexture[PLAYER_LEFT_TEX]);

	D3DXCreateTextureFromFile(
		g_pDirect3DDevice,
		"Bubble.png",
		&g_pGameTexture[BULLET_TEX]);

	// csvファイルの読み込み
	MapLoad("map.csv");
}

// ゲームシーンの解放関数
void GameSceneFree()
{
	// テクスチャを解放
	for (int i = 0; i < GAMESCENE_MAX; i++)
	{
		g_pGameTexture[i]->Release();
	}
}

// Csvの読み込み関数
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
//　UVアニメーション

void PlayerDraw()
{
	static int gameTime = 0;				//初期化
	gameTime++;					

	if ((gameTime % 10) == 0)				//余りが0になる度に以下の処理を行う
	{
		if (g_playerState.animReverse)		//リバースは省く
		{
			for (int i = 0; i < 4; i++)		//4は4つの頂点を指している
			{
				g_player[i].tu -= 0.25f;	// tu値の求め方はピクチャの横幅に全体のx座標を割っている
			}
		}
		//ここらかはリバース　今の所使わない
		else
		{
			for (int i = 0; i < 4; i++)		
			{
				g_player[i].tu += 0.25f;
			}
		}
		//↓はリバース 1,2,3,4の順番を逆の4,3,2,1にしている。その方が見え方が自然になる
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
	// 描画
	g_pDirect3DDevice->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, drawPlayerVertex, sizeof(CUSTOMVERTEX));
}
//　↑ここまで
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
				// テクスチャをステージに割り当てる
				g_pDirect3DDevice->SetTexture(0, g_pGameTexture[MAP_GROUND_TEX]);
				// 描画
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

				// テクスチャをステージに割り当てる
				g_pDirect3DDevice->SetTexture(0, g_pGameTexture[MAP_GROUND_TEX]);
				// 描画
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

	/*当たり判定*/
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

	/*ミサイル発射の処理　描画も中で行っている*/
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
			// テクスチャをステージに割り当てる
			g_pDirect3DDevice->SetTexture(0, g_pGameTexture[BULLET_TEX]);
			// 描画
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
