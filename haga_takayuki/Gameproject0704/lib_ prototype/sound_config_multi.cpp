/**
*@file sound_config_multi.cpp
*@brief DirectShowを使用してサウンドを再生する関数をまとめているcppファイルです.<br>
*こちらはMP3とWAVEファイルどちらも再生可能です.<br>
*@author 芳我貴之
*@date 2016/06/25
*/
#include <dsound.h>
#include <dshow.h>
#include"config.h"
#include"sound_config_multi.h"

/*
ライブラリ
#pragma comment ( lib, "dxguid.lib" )
#pragma comment ( lib, "dsound.lib" )
#pragma comment	(lib,"strmiids.lib")
*/

//------------------------------------------------------------------------------
//
//DirectShowを使用してのサウンド再生
//こちらの関数群はMP3など幅広く再生可能
//必ず最初にLoadSoundFileを使用してから他の関数を使うこと
//
//
//------------------------------------------------------------------------------


/*以下３つをメインに書く→最後は必ず開放する
IGraphBuilder	*pGraphBuilder = NULL;		//アプリケーションからフィルタ グラフを作成するメソッドを提供する
IMediaControl	*pMediaControl = NULL;		//ファイルの読み込み、再生停止などを行う。
IMediaPosition	*pMediaPosition = NULL;		//再生位置を指定するのに使う。
*/

//サウンド再生確認フラグ(デバック用)
bool isPlay = false;
//サウンド再生ループフラグ
bool isRoopMode = false;

//サウンドファイル読み込み関数
void LoadSoundFile(IGraphBuilder	**pGraphBuilder, IMediaControl	**pMediaControl, IMediaPosition	**pMediaPosition, BSTR file)
{
	//COMを初期化
	CoInitialize(NULL);
	//COMオブジェクト作成
	CoCreateInstance(CLSID_FilterGraph, NULL, CLSCTX_INPROC, IID_IGraphBuilder, (LPVOID *)&(*pGraphBuilder));

	(*pGraphBuilder)->QueryInterface(IID_IMediaControl, (LPVOID *)&(*pMediaControl));
	(*pGraphBuilder)->QueryInterface(IID_IMediaPosition, (LPVOID *)&(*pMediaPosition));

	(*pMediaControl)->RenderFile(file);
}

//通常再生(１回だけ再生)
void PlayNormalSound(IMediaControl	**pMediaControl)
{
	(*pMediaControl)->Run();
	isPlay = true;
	isRoopMode = false;
}

//ループ再生
void PlayRoopSound(IMediaControl	**pMediaControl)
{
	(*pMediaControl)->Run();
	isPlay = true;
	isRoopMode = true;
}

//ループ再生チェック
void CheckRoopSound(IMediaControl	**pMediaControl, IMediaPosition **pMediaPosition)
{
	if (!isPlay || !isRoopMode)
	{
		return;
	}

	if (isRoopMode)
	{
		REFTIME pos, end;
		(*pMediaPosition)->get_CurrentPosition(&pos);
		(*pMediaPosition)->get_StopTime(&end);


		if (pos >= end)
		{
			StopSound(&(*pMediaControl), &(*pMediaPosition));
			PlayRoopSound(&(*pMediaControl));

			/*上の処理で音再生に弱冠の間が空く場合したの処理に変えてみる
			*pMediaPosition->put_CurrentPosition(0);
			*pMediaControl->Run();
			*/
		}
	}

}

//再生中の場合でも先頭に戻して再生し直す(効果音)
void PlayFormStartSound(IMediaControl	**pMediaControl, IMediaPosition **pMediaPosition)
{
	(*pMediaPosition)->put_CurrentPosition(0);
	(*pMediaControl)->Run();

	isPlay = true;
}

//一時停止
void PauseSound(IMediaControl **pMediaControl)
{
	(*pMediaControl)->Pause();

	isPlay = false;
}


//停止
void StopSound(IMediaControl	**pMediaControl, IMediaPosition **pMediaPosition)
{
	(*pMediaControl)->Stop();
	//再生位置を先頭に戻す
	(*pMediaPosition)->put_CurrentPosition(0);

	isPlay = false;
}

//ボリュームアップ
void VolUpSound(IGraphBuilder	**pGraphBuilder)
{
	//アプリケーションでオーディオ ストリームのボリュームとバランスを制御するためのインターフェイス
	IBasicAudio *pBasicAudio;
	(*pGraphBuilder)->QueryInterface(IID_IBasicAudio, (LPVOID *)&pBasicAudio);

	long vol = 0;
	pBasicAudio->get_Volume(&vol);
	vol += 100;
	if (vol > 0) {
		vol = 0;
	}
	pBasicAudio->put_Volume(vol);

	pBasicAudio->Release();
}

//ボリュームダウン
void VolDownSound(IGraphBuilder	**pGraphBuilder)
{
	IBasicAudio *pBasicAudio;
	(*pGraphBuilder)->QueryInterface(IID_IBasicAudio, (LPVOID *)&pBasicAudio);

	long vol = 0;
	pBasicAudio->get_Volume(&vol);
	vol -= 100;
	if (vol < -10000) {
		vol = -10000;
	}
	pBasicAudio->put_Volume(vol);

	pBasicAudio->Release();
}


