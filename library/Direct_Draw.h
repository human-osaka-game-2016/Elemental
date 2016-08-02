/**
 * @file Direct_Draw.h
 * @brief DirectXの描画に関係する定義・型・プロトタイプ宣言を書いている
 * @author 柴田哲良
 * @date 2016年7月1日
 */

#ifndef DIRECT_DRAW
#define DIRECT_DRAW

#include <d3dx9.h>

////////////////////////////////////////////
// 型
////////////////////////////////////////////

/// 座標・色成分
struct CUSTOMVERTEX
{
	FLOAT	x;		///< 画面に表示するテクスチャのx座標
	FLOAT	y;		///< 画面に表示するテクスチャのy座標
	FLOAT	z;		///< 画面に表示するテクスチャのz座標
	FLOAT	rhw;		///< 同次座標
	DWORD	color;	///< 色成分
	FLOAT	tu;		///< テクスチャ自体のx座標
	FLOAT	tv;		///< テクスチャ自体のy座標
}; 

////////////////////////////////////////////
// 使用する関数のプロトタイプ宣言
////////////////////////////////////////////

/// 描画の初期化関数
/**
 * @attention この関数はWinMainに書く
 * @return なし
*/
void Init_Draw();

/// 描画始めの関数
/**
 * @return なし
 */
void Draw_Start();

/// 描画関数
/**
 * 画面に描画するための準備
 * @param [in] _pTexture  設定するテクスチャをここに書く
 * @param [in] _setdraw[] どこにテクスチャを設定するかを指定する
 * @return なし
 */
void Draw_Display(LPDIRECT3DTEXTURE9   _pTexture, CUSTOMVERTEX _setdraw[]);

/// 画像ファイルのロード
/**
 * @attention この関数はWinMainに書く
 * @param[in]	_filePath	読み込む画像ファイル名
 * @param[out]	_ppTexture	読み込んだ画像をどこに描画するかを指定する
 * @retval S_OK		読み込み成功
 * @retval E_FAIL	読み込み失敗
*/
HRESULT Load_Texture(TCHAR _filePath[256], LPDIRECT3DTEXTURE9* _ppTexture);

/// 画像ファイルのロード(詳細版)
/**
 * 画像ロード時にLoad_Texture()よりも詳細な設定をしたいときに使う
 * @attention この関数はWinMainに書く
 * @param[in]  _filepath		読み込む画像ファイル名
 * @param[out] _ppTexture		読み込んだ画像をどこに描画するかを指定する
 * @retval S_OK		読み込み成功
 * @retval E_FAIL	読み込み失敗
 */
HRESULT Load_Texture_EX(TCHAR _filePath[256], LPDIRECT3DTEXTURE9* _ppTexture);

/// 描画終わりの関数
/**
 * @return なし
 */
void Draw_End();

/// DirectXのデバイス生成の関数
/**
 *  この関数はMain.hで呼び出してる
 * @param [in] _pDirect3D		DirectXオブジェクトのポインタ
 * @param [in] _hWnd			ウィンドウ・ハンドル
 * @retval S_OK		読み込み成功
 * @retval E_FAIL	読み込み失敗
 */
HRESULT Create_Direct_Device(IDirect3D9* _pDirect3D, HWND _hWnd);

/// 描画の解放関数
/**
* 描画で使ってるオブジェクトを解放している
* @return なし
*/
void Draw_Free();

#endif