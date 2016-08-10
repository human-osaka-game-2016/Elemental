/**
*@file Main.h
*@brief ゲームのエントリーポイントのcppのヘッダーファイル.
*/
#ifndef MAIN_H
#define MAIN_H

#include <windows.h>
#include <d3d9.h>
#include <dinput.h>
#include"draw_config.h"

/**ウィンドウ幅<br>*/
#define WINDOW_W 480
/**ウィンドウ高さ<br>*/
#define WINDOW_H 640
/**ウィンドウ名<br>*/
#define WINDOW_TITLE TEXT("ゼピウス")	

/**プレイヤー弾の数<br>*/
#define BULLETMAX 11

/**敵の数<br>*/
#define ENEMYMAX 4
/**敵の弾の数<br>*/
#define ENEMYBULLETMAX 4

/**ゲームのハイスコアの記録できる最大数<br>*/
#define RANKING_SCORE_MAX 5

/*プレイヤーの構造体<br>*/
typedef struct
{
	int	LIFE;				/**<残機数*/
	int	SCORE;				/**<スコア*/
	float posX, posY;		/**<座標*/
	bool hitFlag;			/**<当たったかのフラグ*/
	bool drawFlag;			/**<描画のフラグ*/
	bool animeExplosion;	/**<アニメーションフラグ(爆発)*/

}PLAYERSTATE;


/**敵の構造体<br>*/
typedef struct
{
	CUSTOMVERTEX enemy[4];		/**<バーテックス情報*/
	int	SCORE;					/**<倒したときのスコア*/
	float posX, posY;			/**<座標*/
	bool drawFlag;				/**<描画のフラグ*/
	bool animeExplosion;		/**<アニメーションフラグ(爆発)*/
	bool moveRight;				/**<敵の左右の動きフラグ*/
	bool moveDown;				/***<敵の下の動き*/

}ENEMYSTATE;

/**弾の構造体<br>*/
typedef struct
{
	CUSTOMVERTEX bullet[4];		/**<バーテックス情報*/
	float posX, posY;			/**<座標*/
	bool initFlag;				/**<弾の初期位置フラグ*/
	bool drawFlag;				/**<描画のフラグ*/

}BULLETSTATE;

/**背景の構造体<br>*/
typedef struct
{
	float posX, posY;		/**<座標*/

}BACKGROUNDSTATE;

/**テキストの構造体<br>*/
typedef struct
{
	float posX, posY;		/**<座標*/

}TEXTSTATE;


/**フラグの構造体<br>*/
typedef struct
{
	bool titleScene;	 /**<タイトルフラグ*/							
	bool gameEnd;		 /**<ゲームオーバーフラグ*/						
	bool loadScore;		 /**<データロードフラグ*/
	bool saveScore;		 /**<データセーブフラグ*/						
	bool gameComplete;	 /**<ゲームクリアフラグ*/	

}FLAGSTATE;

/**スコアランキングの構造体<br>*/
typedef struct
{
	char name[256];		/**<名前(今回未実装)*/
	int score;			/**<得点*/

}SCORESTATE;


/**テクスチャー管理用列挙型<br>*/
enum GAME_TEXTURE
{
	BACKGROUND_TEX,		/**<背景のテクスチャー*/
	BULLET_TEX,			/**<弾のテクスチャー*/
	PLAYER_TEX,			/**<プレイヤーのテクスチャー*/
	ENEMY_TEX,			/**<敵のテクスチャー*/
	EXPLOSION_TEX,		/**<爆発のテクスチャー*/
	TITLE_TEX,			/**<タイトルのテクスチャー*/
	TEXT01_TEX,			/**<文字(押す・ゲームオーバー)のテクスチャー*/
	BULLET_ENEMY_TEX,	/**<敵の弾のテクスチャー*/
	SCORE_TEX,			/**<スコアのテクスチャー*/
	TEXT02_TEX,			/**<文字(ゲームクリア・警告)のテクスチャー*/
	GAME_TEX_MAX		/**<このゲームで使用するテクスチャーの最大数*/
};

/**背景管理用列挙型*/
enum BACK_GROUND
{
	BG_ONE,				/**<背景の1枚目*/
	BG_TWO,				/**<背景の2枚目*/
	BG_MAX
};

/**DirectXオブジェクトのポインタ*/
extern LPDIRECT3D9			g_pDirect3D;
/**DirectXデバイスのポインタ*/
extern LPDIRECT3DDEVICE9	g_pDirect3DDevice;
/**画像情報をいれおくための配列*/
extern LPDIRECT3DTEXTURE9	g_pGameTexture[GAME_TEX_MAX];	
/**DirectInput8 インターフェイス*/
extern LPDIRECTINPUT8		g_pDInput;
/**キーボードデバイス*/
extern LPDIRECTINPUTDEVICE8 g_pkeyDevice;				


#endif