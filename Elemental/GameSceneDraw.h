#define TIPSIZE 64.f
#define MAP_HEIGHT 11
#define MAP_WIDTH 34

#include <Direct_Draw.h>

enum 
{
	BACKGROUND_TEX,
	MAP_GROUND_TEX,
	TEX_MAX,
};

void Map_Draw();

void Render();

void Map_Load(const char* mapdata);

void Tex_Free();

extern LPDIRECT3DTEXTURE9 g_pTexture[TEX_MAX];
extern CUSTOMVERTEX g_maptip[4];