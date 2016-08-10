/**
*@file sound_config_multi.cpp
*@brief DirectShow���g�p���ăT�E���h���Đ�����֐����܂Ƃ߂Ă���cpp�t�@�C���ł�.<br>
*�������MP3��WAVE�t�@�C���ǂ�����Đ��\�ł�.<br>
*@author �F��M�V
*@date 2016/06/25
*/
#include <dsound.h>
#include <dshow.h>
#include"config.h"
#include"sound_config_multi.h"

/*
���C�u����
#pragma comment ( lib, "dxguid.lib" )
#pragma comment ( lib, "dsound.lib" )
#pragma comment	(lib,"strmiids.lib")
*/

//------------------------------------------------------------------------------
//
//DirectShow���g�p���ẴT�E���h�Đ�
//������̊֐��Q��MP3�ȂǕ��L���Đ��\
//�K���ŏ���LoadSoundFile���g�p���Ă��瑼�̊֐����g������
//
//
//------------------------------------------------------------------------------


/*�ȉ��R�����C���ɏ������Ō�͕K���J������
IGraphBuilder	*pGraphBuilder = NULL;		//�A�v���P�[�V��������t�B���^ �O���t���쐬���郁�\�b�h��񋟂���
IMediaControl	*pMediaControl = NULL;		//�t�@�C���̓ǂݍ��݁A�Đ���~�Ȃǂ��s���B
IMediaPosition	*pMediaPosition = NULL;		//�Đ��ʒu���w�肷��̂Ɏg���B
*/

//�T�E���h�Đ��m�F�t���O(�f�o�b�N�p)
bool isPlay = false;
//�T�E���h�Đ����[�v�t���O
bool isRoopMode = false;

//�T�E���h�t�@�C���ǂݍ��݊֐�
void LoadSoundFile(IGraphBuilder	**pGraphBuilder, IMediaControl	**pMediaControl, IMediaPosition	**pMediaPosition, BSTR file)
{
	//COM��������
	CoInitialize(NULL);
	//COM�I�u�W�F�N�g�쐬
	CoCreateInstance(CLSID_FilterGraph, NULL, CLSCTX_INPROC, IID_IGraphBuilder, (LPVOID *)&(*pGraphBuilder));

	(*pGraphBuilder)->QueryInterface(IID_IMediaControl, (LPVOID *)&(*pMediaControl));
	(*pGraphBuilder)->QueryInterface(IID_IMediaPosition, (LPVOID *)&(*pMediaPosition));

	(*pMediaControl)->RenderFile(file);
}

//�ʏ�Đ�(�P�񂾂��Đ�)
void PlayNormalSound(IMediaControl	**pMediaControl)
{
	(*pMediaControl)->Run();
	isPlay = true;
	isRoopMode = false;
}

//���[�v�Đ�
void PlayRoopSound(IMediaControl	**pMediaControl)
{
	(*pMediaControl)->Run();
	isPlay = true;
	isRoopMode = true;
}

//���[�v�Đ��`�F�b�N
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

			/*��̏����ŉ��Đ��Ɏ㊥�̊Ԃ��󂭏ꍇ�����̏����ɕς��Ă݂�
			*pMediaPosition->put_CurrentPosition(0);
			*pMediaControl->Run();
			*/
		}
	}

}

//�Đ����̏ꍇ�ł��擪�ɖ߂��čĐ�������(���ʉ�)
void PlayFormStartSound(IMediaControl	**pMediaControl, IMediaPosition **pMediaPosition)
{
	(*pMediaPosition)->put_CurrentPosition(0);
	(*pMediaControl)->Run();

	isPlay = true;
}

//�ꎞ��~
void PauseSound(IMediaControl **pMediaControl)
{
	(*pMediaControl)->Pause();

	isPlay = false;
}


//��~
void StopSound(IMediaControl	**pMediaControl, IMediaPosition **pMediaPosition)
{
	(*pMediaControl)->Stop();
	//�Đ��ʒu��擪�ɖ߂�
	(*pMediaPosition)->put_CurrentPosition(0);

	isPlay = false;
}

//�{�����[���A�b�v
void VolUpSound(IGraphBuilder	**pGraphBuilder)
{
	//�A�v���P�[�V�����ŃI�[�f�B�I �X�g���[���̃{�����[���ƃo�����X�𐧌䂷�邽�߂̃C���^�[�t�F�C�X
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

//�{�����[���_�E��
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


