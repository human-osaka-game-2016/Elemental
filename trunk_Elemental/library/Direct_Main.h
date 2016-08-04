/**
 * @file Direct_Main.h
 * @brief DirectXのオブジェクトやデバイスに関するプロトタイプ宣言を書いてる
 * @author 柴田哲良
 * @date 2016年7月1日
 */

#ifndef DIRECT_MAIN
#define DIRECT_MAIN

////////////////////////////////////////////
// 使用する関数のプロトタイプ宣言
////////////////////////////////////////////

/// DirectXの初期化関数
/**
 * @attention この関数はWinMainに書く
 * @param [in] _hWnd		ウィンドウ・ハンドル
 * @retval S_OK デバイスの生成に成功
 * @retval E_FAIL デバイスの生成に失敗
*/
HRESULT Init_Direct(HWND _hWnd);

/// オブジェクトの解放関数
/**
 * @attention この関数はWinMainに書く
 * @return なし
 */
void Free();


#endif