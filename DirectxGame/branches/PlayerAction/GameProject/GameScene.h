#define D3DFVF_CUSTOMVERTEX (D3DFVF_XYZRHW | D3DFVF_DIFFUSE | D3DFVF_TEX1)
#define MAP_HEIGHT 23
#define MAP_WIDTH 60
#define TIPSIZE 64.f

enum ANIM_STATE
{
	WAIT,
	DASH,
	ATTACK
};

struct CUSTOMVERTEX
{
	FLOAT	x, y, z, rhw;
	DWORD	color;
	FLOAT	tu, tv;
};

struct PLAYERSTATE
{
	int  HP;
	float posX, posY;
	float dispPosX, dispPosY;
	//初速度
	float a;
	bool animReverse;
	bool jumpFlag;
	bool skyFlag;
	bool isLeft;
};

struct BULLETSTATE
{
	CUSTOMVERTEX bullet[4];
	float posX, posY;
	bool initFlag;
	bool drawFlag;
	bool isLeft;
};

enum GAME_TEXTURE
{
	BACKGROUND_TEX,
	MAP_GROUND_TEX,
	BULLET_TEX,
	PLAYER_RIGHT_TEX,
	PLAYER_LEFT_TEX,
	GAMESCENE_MAX
};

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
	SPACE,
	FIRE,
	QUIT,
	KEYMAX
};

extern LPDIRECT3D9			g_pDirect3D;		// DirectXオブジェクトのポインタ
extern LPDIRECT3DDEVICE9	g_pDirect3DDevice;	// DirectXデバイスのポインタ

// ゲームシーンの制御関数
void GameSceneControl();

// ゲームシーンの描画関数
void GameSceneDraw();

// ゲームシーンの初期化関数
void GameSceneInit();

// ゲームシーンの解放関数
void GameSceneFree();

void BulletControl();
void BulletDraw();

void MapLoad(const char* mapdata);

void MapDraw();

//プレイヤーの操作
void PlayerControl();
void PlayerDraw();

void KeyCheck(int VK, KEYKIND st);