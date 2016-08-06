/**
 * @file Direct_Key_Input.h
 * @brief DirectXのキーに関係する型・プロトタイプ宣言を書いている
 * @author 柴田哲良
 * @date 2016年7月1日
 */

#ifndef DIRECT_KEY_INPUT
#define DIRECT_KEY_INPUT


////////////////////////////////////////////
// 型
////////////////////////////////////////////

/// キーの種類
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
	SHIFT,
	SPACE,
	KEYMAX		///<格納してるキーの最大値
};

/// キーの状態
enum KEYSTATE
{
	PUSH,		///<キーを押した瞬間
	RELEASE,	///<キーを離した瞬間
	ON,			///<押し続けているとき
	OFF			///<離し続けているとき
};

////////////////////////////////////////////
// 宣言
////////////////////////////////////////////

extern KEYSTATE			  g_Key[KEYMAX];						///<KEYSTATEにKEYKINDの全てを配列として格納している


////////////////////////////////////////////
// 使用する関数のプロトタイプ宣言
////////////////////////////////////////////

/// ダイレクトインプットの初期化関数
/**
 * @attention この関数はWinMainに書く
 * @param [in] hWnd ウィンドウ・ハンドル
 * @retval  S_OK	読み込み成功
 * @retval  E_FAIL	読み込み失敗
 */
HRESULT Init_Direct_Input(HWND _hWnd);	

/// キーボードの状態を取得しているかの確認の関数
/** 
 * @attention ここが成功していなければキーは一切動かない
 * @return なし
 */
void Get_Key_State();

/// 押されているキーを確認する関数
/** 
 * @param [in] DIK キーボードで何を入力したか
 * @param [in] st KEYKINDに格納されてるキーの種類の確認
 * @return なし
 */
void Check_Key(int _dik, KEYKIND _st);

/// キー操作の解放関数
/**
 * キー操作で使ってるオブジェクトを解放している
 * @return	なし
 */
void Key_Free();

#endif