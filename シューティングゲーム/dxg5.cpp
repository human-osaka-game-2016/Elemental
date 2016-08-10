#include <windows.h>
#include <mmsystem.h>
#include <d3dx9.h>
#include <d3dx9tex.h>

#define TITLE 	TEXT("Basic of Game(main is Kojima)")

#pragma comment(lib, "winmm.lib")
#pragma comment(lib, "d3d9.lib")
#pragma comment(lib, "d3dx9.lib")

IDirect3D9*			pDirect3D;
IDirect3DDevice9*	pD3Device;
LPDIRECT3DTEXTURE9	pTexture[3];

D3DPRESENT_PARAMETERS d3dpp;

int TEST[2];
int Counter = 0;

enum KEYSTATE {
	PUSH,
	RELEASE,
	ON,
	OFF
};

enum KEYKIND {
	LEFT,
	RIGHT,
	UP,
	DOWN,
	FIRE,
	KEYMAX
};

KEYSTATE Key[KEYMAX];

int PreKey[KEYMAX] = {0};
int KeyState[4] = {0};

float speed;
float Px, Py;
float Pang;
float Pw, Ph;

float Espeed;
float Ex, Ey;
float Eang;
float Ew, Eh;

bool MissileFlag;

struct CUSTOMVERTEX
{
	FLOAT	x, y, z, rhw;
	DWORD	color;
	FLOAT	tu, tv;
};
#define D3DFVF_CUSTOMVERTEX (D3DFVF_XYZRHW | D3DFVF_DIFFUSE | D3DFVF_TEX1)

static CUSTOMVERTEX pt[] = {
	{    0.0f,   0.0f, 0.5f, 1.0f, 0xFFFF0000, 0.0f, 0.0f },
	{  800.0f,   0.0f, 0.5f, 1.0f, 0xFFFF0000, 1.0f, 0.0f },
	{  800.0f, 600.0f, 0.5f, 1.0f, 0xFFFF0000, 1.0f, 1.0f },
	{    0.0f, 600.0f, 0.5f, 1.0f, 0xFFFF0000, 0.0f, 1.0f },
};

static CUSTOMVERTEX player[] = {
	{  380.0f, 300.0f, 0.5f, 1.0f, 0xFFFFFFFF, 0.0f, 0.0f },
	{  460.0f, 300.0f, 0.5f, 1.0f, 0xFFFFFFFF, 1.0f, 0.0f },
	{  460.0f, 400.0f, 0.5f, 1.0f, 0xFFFFFFFF, 1.0f, 1.0f },
	{  380.0f, 400.0f, 0.5f, 1.0f, 0xFFFFFFFF, 0.0f, 1.0f },
};
static CUSTOMVERTEX enemy[] = {
	{  380.0f, 300.0f, 0.5f, 1.0f, 0xFFFF0000, 0.0f, 0.0f },
	{  460.0f, 300.0f, 0.5f, 1.0f, 0xFFFF0000, 1.0f, 0.0f },
	{  460.0f, 400.0f, 0.5f, 1.0f, 0xFFFF00FF, 1.0f, 1.0f },
	{  380.0f, 400.0f, 0.5f, 1.0f, 0xFF0000FF, 0.0f, 1.0f },
};

//-------------------------------------------------------------
//
//	初期化処理
//
//-------------------------------------------------------------
void Init(void)
{
	speed = 1.0f;
	Px = 400.0f;
	Py = 300.0f;
	Pang = 0;
	Pw = 40.0f;
	Ph = 50.0f;
Espeed = 1.0f;
	Ex = 400.0f;
	Ey = 300.0f;
	Eang = 0;
	Ew = 40.0f;
	Eh = 50.0f;
	}
//-------------------------------------------------------------
//
//	キー状態チェック
//
//-------------------------------------------------------------
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

//-------------------------------------------------------------
//
//	制御処理
//
//-------------------------------------------------------------
void Control(void)
{
	float Prad;
	float dx = 0.0f;
	float dy = 0.0f;

		//キー状態の管理
	KeyCheck(VK_LEFT, LEFT);
	KeyCheck(VK_RIGHT, RIGHT);
	KeyCheck(VK_UP, UP);
	KeyCheck(VK_DOWN, DOWN);
	KeyCheck('Z', FIRE);

	if (Key[UP] == PUSH || Key[UP] == ON) {
		speed-= -0.20f;
    if (speed >10.0f) {
	speed = 10.0f;
}
	}

	if (Key[DOWN] == PUSH || Key[DOWN] == ON) {
		speed+=-0.20f;
	}

	if (Key[LEFT] == PUSH || Key[LEFT] == ON) {
		Pang +=40.00f;
	}

	if (Key[RIGHT] == PUSH || Key[RIGHT] == ON) {
        Pang +=-40.00f;
	}


	////もし上下までいったら逆に行く
	//if (player[0].y <= 0.0f || player[2].y >= 600.0f) {
	//	dy *= -1.0f;
	//}
	////もし左右までいったら逆に行く
	//if (player[1].x >= 800.0f || player[0].x <= 0.0f) {
	//	dx *= -1.0f;
	//}

	for (int i = 0 ; i < 4 ; i++) {
		player[i].x += dx;
		player[i].y += dy;
	}

	Prad = D3DXToRadian(Pang+90.0f);
	Px += speed * cos(Prad);
	Py -= speed * sin(Prad);

	if (Py - Ph / 2 > 600.0f){
        Py = -Ph / 2;
	}
	if (Py + Ph / 2 < 0.0f){
        Py = 600.0f + Ph / 2;
	}
	if (Px - Pw / 2 > 800.0f){
        Px = -Pw / 2;
	}
	if (Px + Pw / 2 < 0.0f){
        Px = 800.0f + Pw / 2;
	}
}
//-------------------------------------------------------------
//
//	描画処理
//
//-------------------------------------------------------------
void Render(void)
{
	int Number;
	float Prad;
	float Erad;

	if (!pD3Device) return;

	//描画方法の設定
	pD3Device->SetRenderState(D3DRS_ALPHABLENDENABLE, true);
	pD3Device->SetRenderState(D3DRS_SRCBLEND, D3DBLEND_SRCALPHA);  //SRCの設定
	pD3Device->SetRenderState(D3DRS_DESTBLEND, D3DBLEND_INVSRCALPHA);
	pD3Device->SetRenderState(D3DRS_DIFFUSEMATERIALSOURCE,D3DMCS_COLOR1 );

	pD3Device->SetTextureStageState(0, D3DTSS_COLORARG1, D3DTA_TEXTURE);
	pD3Device->SetTextureStageState(0, D3DTSS_COLORARG2, D3DTA_DIFFUSE);  

	pD3Device->SetTextureStageState(0, D3DTSS_COLOROP, D3DTOP_MODULATE);

	pD3Device->SetTextureStageState(0, D3DTSS_ALPHAARG1, D3DTA_TEXTURE);
	pD3Device->SetTextureStageState(0, D3DTSS_ALPHAARG2, D3DTA_DIFFUSE);

	pD3Device->SetTextureStageState(0, D3DTSS_ALPHAOP, D3DTOP_MODULATE);

	//画面の消去
	pD3Device->Clear(0, NULL, 
						D3DCLEAR_TARGET,
						D3DCOLOR_XRGB(0x00, 0x00, 0x00),
						1.0, 0);
	//描画の開始
	pD3Device->BeginScene();

	//画像の描画
	pD3Device->SetFVF(D3DFVF_CUSTOMVERTEX);
	//背景
	pD3Device->SetTexture(0, pTexture[0]);
	pD3Device->DrawPrimitiveUP(
				D3DPT_TRIANGLEFAN,
				2,
				pt,
				sizeof(CUSTOMVERTEX));
	//プレイヤー
	pD3Device->SetTexture(0, pTexture[1]);

	Prad = D3DXToRadian(Pang);
	player[0].x = Px + ( (-Pw / 2) * cos(Prad) + (-Ph / 2) * sin(Prad));
	player[0].y = Py + (-(-Pw / 2) * sin(Prad) + (-Ph / 2) * cos(Prad));
	player[1].x = Px + ( ( Pw / 2) * cos(Prad) + (-Ph / 2) * sin(Prad));
	player[1].y = Py + (-( Pw / 2) * sin(Prad) + (-Ph / 2) * cos(Prad));
	player[2].x = Px + ( ( Pw / 2) * cos(Prad) + ( Ph / 2) * sin(Prad));
	player[2].y = Py + (-( Pw / 2) * sin(Prad) + ( Ph / 2) * cos(Prad));
	player[3].x = Px + ( (-Pw / 2) * cos(Prad) + ( Ph / 2) * sin(Prad));
	player[3].y = Py + (-(-Pw / 2) * sin(Prad) + ( Ph / 2) * cos(Prad));
	pD3Device->DrawPrimitiveUP(
				D3DPT_TRIANGLEFAN,
				2,
				player,
				sizeof(CUSTOMVERTEX));
	//敵
	pD3Device->SetTexture(0, pTexture[2]);

	Erad = D3DXToRadian(Eang);
	enemy[0].x = Ex + ( (-Ew / 2) * cos(Erad) + (-Eh / 2) * sin(Erad));
	enemy[0].y = Ey + (-(-Ew / 2) * sin(Erad) + (-Eh / 2) * cos(Erad));
	enemy[1].x = Ex + ( ( Ew / 2) * cos(Erad) + (-Eh / 2) * sin(Erad));
	enemy[1].y = Ey + (-( Ew / 2) * sin(Erad) + (-Eh / 2) * cos(Erad));
	enemy[2].x = Ex + ( ( Ew / 2) * cos(Erad) + ( Eh / 2) * sin(Erad));
	enemy[2].y = Ey + (-( Ew / 2) * sin(Erad) + ( Eh / 2) * cos(Erad));
	enemy[3].x = Ex + ( (-Ew / 2) * cos(Erad) + ( Eh / 2) * sin(Erad));
	enemy[3].y = Ey + (-(-Ew / 2) * sin(Erad) + ( Eh / 2) * cos(Erad));
	pD3Device->DrawPrimitiveUP(
				D3DPT_TRIANGLEFAN,
				2,
				enemy,
				sizeof(CUSTOMVERTEX));

	//ミサイル
	if(MissileFlag == true ) {
		pD3Device->SetTexture(0, pTexture[3]);
		pD3Device->DrawPrimitiveUP(
					D3DPT_TRIANGLEFAN,
					2,
					missile,
					sizeof(CUSTOMVERTEX));
	}
	//描画の終了
	pD3Device->EndScene();

	//表示
	pD3Device->Present(NULL, NULL, NULL, NULL);
}

//-------------------------------------------------------------
//
//	メッセージ処理
//
//-------------------------------------------------------------
LRESULT CALLBACK kojima(HWND hWnd , UINT msg , WPARAM wp , LPARAM lp) {

	switch (msg) {
	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	}
	return DefWindowProc(hWnd , msg , wp , lp);
}

//-------------------------------------------------------------
//
//	メインルーチン
//
//-------------------------------------------------------------
int WINAPI WinMain(HINSTANCE hInstance , HINSTANCE hPrevInstance ,
			PSTR lpCmdLine , int nCmdShow) {
	MSG msg;
	HWND hWnd;
	WNDCLASS winc;
	D3DDISPLAYMODE d3ddm;

	//DirectX オブジェクトの生成
	pDirect3D = Direct3DCreate9(
		        D3D_SDK_VERSION);
	//Display Mode の設定
	pDirect3D->GetAdapterDisplayMode(
				D3DADAPTER_DEFAULT,
				&d3ddm);
	ZeroMemory(&d3dpp, 
		sizeof(D3DPRESENT_PARAMETERS));
	d3dpp.BackBufferFormat = d3ddm.Format;
	d3dpp.BackBufferCount  = 1;
	d3dpp.SwapEffect	   = D3DSWAPEFFECT_DISCARD;
	d3dpp.Windowed		   = TRUE;

	//Windows情報の設定
	winc.style 			= CS_HREDRAW | CS_VREDRAW;
	winc.lpfnWndProc	= kojima;
	winc.cbClsExtra		= winc.cbWndExtra = 0;
	winc.hInstance		= hInstance;
	winc.hIcon			= LoadIcon(NULL , IDI_APPLICATION);
	winc.hCursor		= LoadCursor(NULL , IDC_ARROW);
	winc.hbrBackground	= (HBRUSH)GetStockObject(WHITE_BRUSH);
	winc.lpszMenuName	= NULL;
	winc.lpszClassName	= TEXT("Human Game College(main is Kojima)");
	//Windowsの登録
	if (!RegisterClass(&winc)) return 0;
	//Windowsの生成
	int dH = GetSystemMetrics(SM_CYCAPTION) + GetSystemMetrics(SM_CYFRAME) * 2;
	int dW = GetSystemMetrics(SM_CXFRAME) * 2;

	hWnd = CreateWindow(
		TEXT("Human Game College(main is Kojima)") , 
		TITLE , 
		WS_OVERLAPPEDWINDOW | WS_VISIBLE ,
		CW_USEDEFAULT ,		// x
		CW_USEDEFAULT ,		// y
		800 + dW,		// Width
		600 + dH,		// Height
		NULL , NULL , hInstance , NULL
	);
	if (!hWnd) return 0;

	pDirect3D->CreateDevice(
		D3DADAPTER_DEFAULT,
		D3DDEVTYPE_HAL,
		hWnd,
		D3DCREATE_SOFTWARE_VERTEXPROCESSING,
		&d3dpp, &pD3Device);

	if (FAILED(D3DXCreateTextureFromFile(
					pD3Device,
					TEXT("test.bmp"),
					&pTexture[0]))) {
						return 0;
	}

	if (FAILED(D3DXCreateTextureFromFileEx(
					pD3Device,
					TEXT("chara.bmp"),
					D3DX_DEFAULT_NONPOW2,
					D3DX_DEFAULT_NONPOW2,
					D3DX_DEFAULT,
					0,
					D3DFMT_UNKNOWN,
					D3DPOOL_MANAGED,
					D3DX_FILTER_NONE,
					D3DX_FILTER_NONE,
					D3DCOLOR_ARGB(255, 0, 0, 0),
					NULL, NULL,
					&pTexture[1]))) {
						return 0;
	}
	if (FAILED(D3DXCreateTextureFromFileEx(
					pD3Device,
					TEXT("enemy.bmp"),
					D3DX_DEFAULT_NONPOW2,
					D3DX_DEFAULT_NONPOW2,
					D3DX_DEFAULT,
					0,
					D3DFMT_UNKNOWN,
					D3DPOOL_MANAGED,
					D3DX_FILTER_NONE,
					D3DX_FILTER_NONE,
					D3DCOLOR_ARGB(255, 0, 0, 0),
					NULL, NULL,
					&pTexture[2]))) {
						return 0;
	}

	DWORD SyncOld = timeGetTime();
	DWORD SyncNow;

	timeBeginPeriod(1);
	 Init();
	ZeroMemory(&msg, sizeof(msg));
	while (msg.message != WM_QUIT) {
		Sleep(1);
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE)) {
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
		else {
			SyncNow = timeGetTime();
			if (SyncNow - SyncOld >= 1000 / 60) {
				Control();
				Render();
				SyncOld = SyncNow;
			}
		}
	}

	timeEndPeriod(1);

	return (int)msg.wParam;
}
