/**
*@file sound_config_multi.h
*@brief DirectShowを使用してサウンドを再生する関数をまとめているcppのヘッダーファイルです.<br>
*こちらはMP3とWAVEファイルどちらも再生可能です.<br>
*@author 芳我貴之
*@date 2016/06/25
*/
#ifndef SOUND_CONFIG_MULTI_H
#define SOUND_CONFIG_MULTI_H
#include <dSound.h>
#include <dshow.h>
#include"config.h"

/**
*音を再生しているかのフラグ<br>
*/
extern bool isPlay;

/**
*音をループするかのフラグ<br>
*/
extern bool isRoopMode;

/**
*サウンドファイル読み込みするための関数.
*･COM初期化、及びオブジェクト作成
*･サウンドファイル読み込み.
*@attention 必ずこのファイルを使って音を読み込む
*@param[in]	**pGraphBuilder		･フィルタの追加や削除、自動生成するインターフェイスのポインタ
*@param[in]	**pMediaControl		･キャプチャの実行制御のインターフェイスのポインタ
*@param[in]	**pMediaPosition	･ストリーム内の位置をシークするメソッドを持つインターフェイスのポインタ
*@param[in]	file	･サウンドファイル
*/
void LoadSoundFile(IGraphBuilder	**pGraphBuilder, IMediaControl	**pMediaControl, IMediaPosition	**pMediaPosition, BSTR file);

/**
*通常再生関数(１回だけ再生).
*@param[in]	**pMediaControl		･キャプチャの実行制御のインターフェイスのポインタのポインタ
*/
void PlayNormalSound(IMediaControl	**pMediaControl);

/**
*ループ再生関数(ループのフラグを立てる).
*@param[in]	**pMediaControl		･キャプチャの実行制御のインターフェイスのポインタのポインタ
*/
void PlayRoopSound(IMediaControl	**pMediaControl);

/**
*フラグをチェックして、ループ再生する関数.
*@param[in]	**pMediaControl		･キャプチャの実行制御のインターフェイスのポインタ
*@param[in]	**pMediaPosition	･ストリーム内の位置をシークするメソッドを持つインターフェイスのポインタ
*/
void CheckRoopSound(IMediaControl	**pMediaControl, IMediaPosition **pMediaPosition);

/**
*再生中の場合でも先頭に戻して再生し直す関数.
*@param[in]	**pMediaControl		･キャプチャの実行制御のインターフェイスのポインタ
*@param[in]	**pMediaPosition	･ストリーム内の位置をシークするメソッドを持つインターフェイスのポインタ
*@note	効果音などに使用しやすい
*/
void PlayFormStartSound(IMediaControl	**pMediaControl, IMediaPosition **pMediaPosition);

/**
*サウンドを一時停止する関数(途中から再生する状態にする).
*@param[in]	**pMediaControl		･キャプチャの実行制御のインターフェイスのポインタ
*/
void PauseSound(IMediaControl **pMediaControl);

/**
*サウンドを停止する関数(最初から再生する状態にする).<br>
*@param[in]	**pMediaControl		･キャプチャの実行制御のインターフェイスのポインタ
*@param[in]	**pMediaPosition	･ストリーム内の位置をシークするメソッドを持つインターフェイスのポインタ
*/
void StopSound(IMediaControl	**pMediaControl, IMediaPosition **pMediaPosition);

/**
*サウンドのボリュームを上げる関数.<br>
*@param[in]	**pGraphBuilder		･フィルタの追加や削除、自動生成するインターフェイスのポインタ
*/
void VolUpSound(IGraphBuilder	**pGraphBuilder);

/**
*サウンドのボリュームを下げる関数.<br>
*@param[in]	**pGraphBuilder		･フィルタの追加や削除、自動生成するインターフェイスのポインタ
*/
void VolDownSound(IGraphBuilder	**pGraphBuilder);


#endif