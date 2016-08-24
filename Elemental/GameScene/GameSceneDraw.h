/**
 * @file GameSceneDraw.h
 * @breif �`��̊�ՂɂȂ�t�@�C��

 * �Q�[���S�̂̕`��ɕK�v�Ȓ�`�E�^�E�v���g�^�C�v�錾�Eextern�������Ă��� 

 */

#ifndef GAMESCENEDRAW
#define GAMESCENEDRAW

////////////////////////////////////////////////
// ��`
////////////////////////////////////////////////

#define KODORA_MAX 1
#define SKERETON_MAX 1
#define SLIME_MAX 1
#define TIPSIZE 64		//! �}�b�v�`�b�v�̃T�C�Y
#define MAP_HEIGHT 12	//! �`�悷��}�b�v�̏c�̍ő�l
#define MAP_WIDTH 34	//! �`�悷��}�b�v�̉��̍ő�l

#include <Direct_Draw.h>

////////////////////////////////////////////////
// �^
////////////////////////////////////////////////

/// �摜����
enum GAMETEX
{
	BACKGROUND_TEX,		//!< �w�i�摜�����蓖�Ă�
	MAP_GROUND_TEX,		//!< �}�b�v�`�b�v�����蓖�Ă�
	PLAYER_TEX,			//!< ��l���̉摜�����蓖�Ă�
	PLAYER_MOVE_TEX,
	PLAYER_LEFT_TEX,
	PLAYER_LEFT_MOVE_TEX,
	PLAYER_FLAME_TEX,	//!< ���I�[���̎�l���̉摜�����蓖�Ă�
	PLAYER_ICE_TEX,		//!< �ÃI�[���̎�l���̉摜�����蓖�Ă�
	PLAYER_WIND_TEX,	//!< ���I�[���̎�l���̉摜�����蓖�Ă�
	KODORA_TEX,			//!< �R�h���̉摜�����蓖�Ă�
//	SKERETON_TEX,
	BULLET_TEX,			//!< �e�̉摜�����蓖�Ă�
	WINDGIMMICK_TEX,	//!< ���̃M�~�b�N�̉摜�����蓖�Ă�
	TEX_MAX,			//!< �摜�����̍ő�l
};

////////////////////////////////////////////////
// �g�p����֐��̃v���g�^�C�v�錾
////////////////////////////////////////////////

/// 60fps�Ń��[�v������`��֐�
/**
 * @return �Ȃ�
 */
void Render();

/// csv�œǂݍ��񂾃}�b�v�̕`��֐�
/**
 * @return �Ȃ�
 */
void Draw_Map();

/// csv�t�@�C���̓ǂݍ��݊֐�
/**
 * @param [out] _mapdate �ǂݍ���csv�t�@�C���̖��O
 * @return �Ȃ�
 */
void Load_Map(const char* _mapdata);

/// �`��֐�
/**
 * @param [in] �`�悵�����摜���ǂ��Ɋ��蓖�Ă邩������
 * @param [in] �ǂ�CUSTOMVERTEX�̏���`�悵������������
 * @return �Ȃ�
 */
void Draw_Obj(LPDIRECT3DTEXTURE9   _pTexture, CUSTOMVERTEX _setdraw[]);

/// �e�N�X�`���̉���֐�
/**
 * @return �Ȃ�
 */
void Tex_Free();

////////////////////////////////////////////////
// extern
////////////////////////////////////////////////

extern float g_ScreenOriginX;					//! ��ʂ̍���̂����W
extern float g_ScreenOriginY;					//! ��ʂ̍���̂����W
extern int map[MAP_HEIGHT][MAP_WIDTH];			//! csv�œǂݍ��񂾃}�b�v��2�����z��
extern LPDIRECT3DTEXTURE9 g_pTexture[TEX_MAX];	//! DirectX�e�N�X�`���E�I�u�W�F�N�g�ւ̃|�C���^

#endif