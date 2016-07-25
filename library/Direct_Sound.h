/**
 * @file Direct_Sound.h
 * @brief DirectXのサウンドに関係するプロトタイプ宣言を書いている
 * @brief Waveファイルを再生するときだけに使える
 * @author 柴田哲良
 * @date 2016年7月2日
 */

#ifndef DIRECT_SOUND
#define DIRECT_SOUND

#include <dsound.h>

////////////////////////////////////////////
// メインに書く必要のあるソース
////////////////////////////////////////////

/*
これはWinMainに書く
IDirectSoundBuffer8*は再生する音楽の数だけcppに書いていく
IDirectSoundBuffer8*の解放も忘れずに
Play(0, 優先順位, 再生する状態(ループ状態など))

*/

////////////////////////////////////////////
// 使用する関数のプロトタイプ宣言
////////////////////////////////////////////

/// Waveファイルオープン関数
/**
 * @attention この関数はWinMainに書く
 * @param [out] _filepath	音声ファイルの名前
 * @param [in]  _waveFormat	バッファーのWaveフォームフォーマット
 * @param [in]  _ppDate		pDateのアドレスに音のデータが格納されている
 * @param [in]  _datesize	新しいバッファサイズ(バイト単位)
 * @retval true		読み込み成功
 * @retval false	読み込み失敗
 */
bool Open_Wave(TCHAR* _filename, WAVEFORMATEX* _waveformat, char** _ppData, DWORD* _dataSize);

/// サウンドオブジェクトの生成
/**
 * @attention この関数はWinMainに書く
 * @param [in] _hWnd			ウィンドウ・ハンドル
 * @retval S_OK		読み込み成功
 * @retval E_FAIL	読み込み失敗
 */
HRESULT Init_Sound_Device(HWND _hWnd );

/// サウンドバッファーの生成
/**
 * セカンダリバッファにWaveデータ書き込み
 * @attention この関数はWinMainで書く
 * @param [in] _filename		音声ファイルの名前
 * @param [in] _ppDSBuffer		サウンドバッファを管理するために使う
 * @retval S_OK		読み込み成功
 * @retval E_FAIL	読み込み失敗
 */
HRESULT Create_Sound_Buffer(TCHAR* _filename, IDirectSoundBuffer8** _ppDSBuffer);

/// サウンドの解放関数
/**
 * サウンドで使ってるオブジェクトを解放している
 * @return なし
 */
void Sound_Free();

#endif