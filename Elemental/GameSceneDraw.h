#define TIPSIZE 64
#define MAP_HEIGHT 11
#define MAP_WIDTH 34

#include <Direct_Draw.h>

enum 
{
	BACKGROUND_TEX,
	MAP_GROUND_TEX,
	PLAYER_TEX,
	TEX_MAX,
};

void Draw_Map();

void Render();

void Load_Map(const char* mapdata);

void Draw_Obj(LPDIRECT3DTEXTURE9   _pTexture, CUSTOMVERTEX _setdraw[]);

void Tex_Free();

extern float g_ScreenOriginX;
extern float g_ScreenOriginY;
extern int map[MAP_HEIGHT][MAP_WIDTH];
extern LPDIRECT3DTEXTURE9 g_pTexture[TEX_MAX];
extern CUSTOMVERTEX g_maptip[4];
