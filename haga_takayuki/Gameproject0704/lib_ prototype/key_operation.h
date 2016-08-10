/**
@file key_operation.h
@brief DirectInput初期化関数な、及び操作関連関数をまとめているcppのヘッダーファイルです.
@author 芳我貴之
@data 2016/06/18
*/

#ifndef KEY_OPERATION_H
#define KEY_OPERATION_H

#include <dinput.h>


/**
*キーの種類を列挙。<br>
*KeyCheck関数で使用.
*@sa KeyCheck(BYTE DIK, KEYKIND st)
*/
enum  KEYKIND
{
	LEFT,
	RIGHT,
	UP,
	DOWN,
	A,
	B,
	C,
	D,
	E,
	F,
	G,
	H,
	I,
	J,
	K,
	L,
	M,
	N,
	O,
	P,
	Q,
	R,
	S,
	T,
	U,
	V,
	W,
	X,
	Y,
	Z,
	ESCAPE,
	SHIFT,
	SPACE,
	KEYMAX
};



/**
*キーの状態４種類を列挙<br>
*KeyCheck関数で使用.
*@sa KeyCheck(BYTE DIK, KEYKIND st)
*/
enum KEYSTATE
{
	PUSH,/**<キーを押す*/
	RELEASE,/**<キーを離す*/
	ON,/**<キーを押した状態が続いている*/
	OFF/**<キーを離した状態が続いている*/
};

/**
*DirectInputの初期化関数(対応デバイスはキーボードのみ).<br>
*･オブジェクト作成,デバイス作成<br>
*･デバイスをキーボードに設定<br>
*･協調レベル設定.<br>
*@param[in]	hWnd		･ウィンドウハンドル
*@param[in]	g_pDInput	･DirectInputオブジェクトポインタ
*@param[in]	g_pkeyDevice	･DirectInputデバイス･オブジェクトポインタ
*@retval S_OK	成功 
*@retval FALSE	失敗 
*@noteマウスやジョイスティックの実装も検討中
*/
HRESULT InitDinput(HWND hWnd, LPDIRECTINPUT8* g_pDInput, LPDIRECTINPUTDEVICE8* g_pkeyDevice);

/**
*DIKを格納する変数.
*/
extern BYTE diks[256];

/**
*キーの種類を格納する変数.
*/
extern KEYSTATE Key[KEYMAX];

/**
*押す前の状態を格納する変数.
*0が押されていない,1が押されている状態を表している.
*/
extern int PreKey[KEYMAX];

/**
*キーの状態を確認する関数.<br>
*･キーが押されているかチェック<br>
*･キーの状態(KEYSTATEで列挙している)の確認<br>
*@param[in]	DIK		･DIKを格納
*@param[in] st		･キーの種類を格納
*@attention	関数を使う前にメインでデバイスへのアクセス権が獲得されているか再度確認すること.
*/
void KeyCheck(BYTE DIK, KEYKIND st);



#endif

