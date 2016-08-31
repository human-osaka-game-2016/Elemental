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
#define MAP_WIDTH 38	//! �`�悷��}�b�v�̉��̍ő�l

#include <Direct_Draw.h>

////////////////////////////////////////////////
// �^
////////////////////////////////////////////////

/// �摜����
enum GAMETEX
{
//	BACKGROUND_TEX,					//!< �w�i�摜�����蓖�Ă�

	MAP_BLOCK_TEX,					//!< �}�b�v�`�b�v�����蓖�Ă�
	FLAME_BLOCK_TEX,
	WIND_BLOCK_TEX,

	PLAYER_RIGHT_TEX,						//!< ��l���̉摜�����蓖�Ă�
	PLAYER_RIGHT_MOVE_TEX,				//!< ��l�����ړ������Ƃ��̉摜�����蓖�Ă�
	PLAYER_RIGHT_JUMP_TEX,
	PLAYER_RIGHT_FALL_TEX,
	PLAYER_LEFT_TEX,				//!< ��l���������������Ƃ��̉摜�����蓖�Ă�
	PLAYER_LEFT_MOVE_TEX,			//!< ��l�����������ňړ������Ƃ��̉摜�����蓖�Ă�
	PLAYER_LEFT_JUMP_TEX,
	PLAYER_LEFT_FALL_TEX,

	PLAYER_FLAME_RIGHT_TEX,				//!< ���I�[���̎�l���̉摜�����蓖�Ă�
	PLAYER_FLAME_RIGHT_MOVE_TEX,			//!< ���I�[���̎�l�����ړ����Ă���摜�����蓖�Ă�
	PLAYER_FLAME_RIGHT_JUMP_TEX,
	PLAYER_FLAME_LEFT_TEX,			//!< ���I�[���̎�l���������������Ƃ��̉摜�����蓖�Ă�
	PLAYER_FLAME_LEFT_MOVE_TEX,		//!< ���I�[���̎�l�������������ňړ������Ƃ��̉摜�����蓖�Ă�
	PLAYER_FLAME_LEFT_JUMP_TEX,

	PLAYER_ICE_RIGHT_TEX,					//!< �ÃI�[���̎�l���̉摜�����蓖�Ă�
	PLAYER_ICE_RIGHT_MOVE_TEX,			//!< �X�I�[���̎�l�����ړ����Ă���摜�����蓖�Ă�
	PLAYER_ICE_RIGHT_JUMP_TEX,
	PLAYER_ICE_LEFT_TEX,			//!< �X�I�[���̎�l���������������Ƃ��̉摜�����蓖�Ă�
	PLAYER_ICE_LEFT_MOVE_TEX,		//!< �X�I�[���̎�l�������������ňړ������Ƃ��̉摜�����蓖�Ă�
	PLAYER_ICE_LEFT_JUMP_TEX,

	PLAYER_WIND_RIGHT_TEX,				//!< ���I�[���̎�l���̉摜�����蓖�Ă�
	PLAYER_WIND_RIGHT_MOVE_TEX,			//!< ���I�[���̎�l�����ړ����Ă���摜�����蓖�Ă�
	PLAYER_WIND_RIGHT_JUMP_TEX,
	PLAYER_WIND_LEFT_TEX,			//!< ���I�[���̎�l���������������Ƃ��̉摜�����蓖�Ă�
	PLAYER_WIND_LEFT_MOVE_TEX,		//!< ���I�[���̎�l�������������ňړ������Ƃ��̉摜�����蓖�Ă�
	PLAYER_WIND_LEFT_JUMP_TEX,

	KODORA_FLAME_RIGHT_MOVE_TEX,	//!< ���R�h���̉E�Ɉړ����Ă���摜�����蓖�ĂĂ���
	KODORA_FLAME_LEFT_MOVE_TEX,			//!< ���R�h���̈ړ����Ă���摜�����蓖�ĂĂ���


	SLIME_FLAME_RIGHT_MOVE_TEX,		//!< ���X���C���̉E�Ɉړ����Ă���摜�����蓖�ĂĂ���
	SLIME_FLAME_LEFT_MOVE_TEX,			//!< ���X���C���̈ړ����Ă���摜�����蓖�ĂĂ���


	PLAYER_FLAME_ATTACK_TEX,
	PLAYER_ICE_ATTACK_TEX,
	PLAYER_WIND_ATTACK_TEX,


	WINDGIMMICK_TEX,				//!< ���̃M�~�b�N�̉摜�����蓖�Ă�

	TEX_MAX,						//!< �摜�����̍ő�l
};		

enum AURA
{
	NORMAL,
	FLAME,
	ICE,
	WIND,
};

//�L�����̌����Ă����
enum Direction
{
	Right,		//!< �E
	Left,		//!< ��
	Normal,		//!< �ʏ���
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

extern float g_ScreenOriginX;					//!< ��ʂ̍���̂����W
extern float g_ScreenOriginY;					//!< ��ʂ̍���̂����W
extern int map[MAP_HEIGHT][MAP_WIDTH];			//!< csv�œǂݍ��񂾃}�b�v��2�����z��
extern LPDIRECT3DTEXTURE9 g_pTexture[TEX_MAX];	//!< DirectX�e�N�X�`���E�I�u�W�F�N�g�ւ̃|�C���^

#endif