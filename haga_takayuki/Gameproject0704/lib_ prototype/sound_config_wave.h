/**
*@file sound_config_wave.h
*@brief Wave形式のサウンドを使用する為の関数をまとめているcppのヘッダーファイルです.
*@attention waveファイルのみ対応
*@author 芳我貴之
*@date 2016/06/25
*/
#ifndef SOUND_CONFIG_WAVE_H
#define SOUND_CONFIG_WAVE_H
#include <dSound.h>
#include <dshow.h>
#include"config.h"

/**
waveファイルに関連する関数.<br>
*・waveファイルオープン<br>
*・RIFFチャンク,フォーマットチャンク,データチャンク検索.<br>
*この関数は下記の参照している関数とセットで運用する.
*@sa SoundWave(HWND hWnd, char** pwaveData, DWORD* dataSize, WAVEFORMATEX* waveFormatEx, int playback_method)
*@param[in]	filepath	･wave形式の音のファイル名
*@param[in]	waveFormatEx	･WAVEFORMATEX構造体
*@param[out] pwaveData		･波形データ
*@param[out] dataSize	･セカンダリバッファで確保するサイズ
*@retval SUCCESS_VALUE  成功
*@retval ERROR_VALUE	失敗
*/
int OpenWave(TCHAR* filepath, WAVEFORMATEX* waveFormatEx, char** pwaveData, DWORD* dataSize);

/**
*サウンドデバイスに関連する関数.<br>
*・サウンドデバイス作成,協調レベル設定<br>
*・セカンダリバッファ作成<br>
*・セカンダリバッファにWaveデータ書き込み<br>
*・音の再生.<br>
*@attention この関数を使用するにはは下記の参照関数でwaveファイルを開くことが必須.
*@sa OpenWave(TCHAR* filepath, WAVEFORMATEX* waveFormatEx, char** pwaveData, DWORD* dataSize)
*@param[in] hWnd		･ウィンドウハンドル
*@param[in]	pwaveData	･波形データ
*@param[in]	dataSize	･セカンダリバッファで確保するサイズ
*@param[in]	waveFormatEx	･WAVEFORMATEX構造体
*@param[in] playback_method		･再生方法	
*/
void SoundWave(HWND hWnd, char** pwaveData, DWORD* dataSize, WAVEFORMATEX* waveFormatEx, int playback_method);


#endif