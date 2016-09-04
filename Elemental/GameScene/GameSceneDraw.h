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

#define NORMAL_BLOCK 1
#define FLAME_BLOCK 2
#define WIND_BLOCK 3
#define WIND_POS_BLOCK 4
#define TREASURE_BOX 6
#define ICESIZE 128		//! �X�̃T�C�Y
#define ICESIZE2 192
#define ICESIZE3 256
#define TIPSIZE 64		//! �}�b�v�`�b�v�̃T�C�Y
#define MAP_HEIGHT 22	//! �`�悷��}�b�v�̏c�̍ő�l
#define MAP_WIDTH 100	//! �`�悷��}�b�v�̉��̍ő�l

#include <Direct_Draw.h>

////////////////////////////////////////////////
// �^
////////////////////////////////////////////////

/// �摜����
enum GAMETEX
{
	BACKGROUND_TEX,					//!< �w�i�摜�����蓖�Ă�

	MAP_BLOCK_TEX,					//!< �}�b�v�`�b�v�����蓖�Ă�
	FLAME_BLOCK_TEX,
	WIND_BLOCK_TEX,
	WIND_POS_BLOCK_TEX,

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
	PLAYER_FLAME_RIGHT_FALL_TEX,
	PLAYER_FLAME_RIGHT_ATTACK_TEX,
	PLAYER_FLAME_LEFT_TEX,			//!< ���I�[���̎�l���������������Ƃ��̉摜�����蓖�Ă�
	PLAYER_FLAME_LEFT_MOVE_TEX,		//!< ���I�[���̎�l�������������ňړ������Ƃ��̉摜�����蓖�Ă�
	PLAYER_FLAME_LEFT_JUMP_TEX,
	PLAYER_FLAME_LEFT_FALL_TEX,
	PLAYER_FLAME_LEFT_ATTACK_TEX,

	PLAYER_ICE_RIGHT_TEX,					//!< �ÃI�[���̎�l���̉摜�����蓖�Ă�
	PLAYER_ICE_RIGHT_MOVE_TEX,			//!< �X�I�[���̎�l�����ړ����Ă���摜�����蓖�Ă�
	PLAYER_ICE_RIGHT_JUMP_TEX,
	PLAYER_ICE_RIGHT_FALL_TEX,
	PLAYER_ICE_LEFT_TEX,			//!< �X�I�[���̎�l���������������Ƃ��̉摜�����蓖�Ă�
	PLAYER_ICE_LEFT_MOVE_TEX,		//!< �X�I�[���̎�l�������������ňړ������Ƃ��̉摜�����蓖�Ă�
	PLAYER_ICE_LEFT_JUMP_TEX,
	PLAYER_ICE_LEFT_FALL_TEX,

	PLAYER_WIND_RIGHT_TEX,				//!< ���I�[���̎�l���̉摜�����蓖�Ă�
	PLAYER_WIND_RIGHT_MOVE_TEX,			//!< ���I�[���̎�l�����ړ����Ă���摜�����蓖�Ă�
	PLAYER_WIND_RIGHT_JUMP_TEX,
	PLAYER_WIND_RIGHT_FALL_TEX,
	PLAYER_WIND_LEFT_TEX,			//!< ���I�[���̎�l���������������Ƃ��̉摜�����蓖�Ă�
	PLAYER_WIND_LEFT_MOVE_TEX,		//!< ���I�[���̎�l�������������ňړ������Ƃ��̉摜�����蓖�Ă�
	PLAYER_WIND_LEFT_JUMP_TEX,
	PLAYER_WIND_LEFT_FALL_TEX,

	KODORA_FLAME_RIGHT_STATE_TEX,	//!< ���R�h���̉E�ɑҋ@���[�V�������Ă���摜�����蓖�ĂĂ���
	KODORA_FLAME_RIGHT_MOVE_TEX,	//!< ���R�h���̉E�Ɉړ����Ă���摜�����蓖�ĂĂ���
	KODORA_FLAME_LEFT_STATE_TEX,	//!< ���R�h���̑ҋ@���[�V�������Ă���摜�����蓖�ĂĂ���
	KODORA_FLAME_LEFT_MOVE_TEX,		//!< ���R�h���̈ړ����Ă���摜�����蓖�ĂĂ���

	KODORA_ICE_RIGHT_STATE_TEX,		//!< �X�R�h���̉E�ɑҋ@���[�V�������Ă���摜�����蓖�ĂĂ���
	KODORA_ICE_RIGHT_MOVE_TEX,		//!< �X�R�h���̉E�Ɉړ����Ă���摜�����蓖�ĂĂ���
	KODORA_ICE_LEFT_STATE_TEX,		//!< �X�R�h���̑ҋ@���[�V�������Ă���摜�����蓖�ĂĂ���
	KODORA_ICE_LEFT_MOVE_TEX,		//!< �X�R�h���̈ړ����Ă���摜�����蓖�ĂĂ���

	KODORA_WIND_RIGHT_STATE_TEX,	//!< ���R�h���̉E�ɑҋ@���[�V�������Ă���摜�����蓖�ĂĂ���
	KODORA_WIND_RIGHT_MOVE_TEX,		//!< ���R�h���̉E�Ɉړ����Ă���摜�����蓖�ĂĂ���
	KODORA_WIND_LEFT_STATE_TEX,		//!< ���R�h���̑ҋ@���[�V�������Ă���摜�����蓖�ĂĂ���
	KODORA_WIND_LEFT_MOVE_TEX,		//!< ���R�h���̈ړ����Ă���摜�����蓖�ĂĂ���

	SLIME_FLAME_RIGHT_STATE_TEX,	//!< ���X���C���̉E�ɑҋ@���[�V�������Ă���摜�����蓖�ĂĂ���
	SLIME_FLAME_RIGHT_MOVE_TEX,		//!< ���X���C���̉E�Ɉړ����Ă���摜�����蓖�ĂĂ���
	SLIME_FLAME_LEFT_STATE_TEX,		//!< ���X���C���̑ҋ@���[�V�������Ă���摜�����蓖�ĂĂ���
	SLIME_FLAME_LEFT_MOVE_TEX,		//!< ���X���C���̈ړ����Ă���摜�����蓖�ĂĂ���

	SLIME_ICE_RIGHT_STATE_TEX,		//!< �X�X���C���̉E�ɑҋ@���[�V�������Ă���摜�����蓖�ĂĂ���
	SLIME_ICE_RIGHT_MOVE_TEX,		//!< �X�X���C���̉E�Ɉړ����Ă���摜�����蓖�ĂĂ���
	SLIME_ICE_LEFT_STATE_TEX,		//!< �X�X���C���̑ҋ@���[�V�������Ă���摜�����蓖�ĂĂ���
	SLIME_ICE_LEFT_MOVE_TEX,		//!< �X�X���C���̈ړ����Ă���摜�����蓖�ĂĂ���

	SLIME_WIND_RIGHT_STATE_TEX,		//!< ���X���C���̉E�ɑҋ@���[�V�������Ă���摜�����蓖�ĂĂ���
	SLIME_WIND_RIGHT_MOVE_TEX,		//!< ���X���C���̉E�Ɉړ����Ă���摜�����蓖�ĂĂ���
	SLIME_WIND_LEFT_STATE_TEX,		//!< ���X���C���̑ҋ@���[�V�������Ă���摜�����蓖�ĂĂ���
	SLIME_WIND_LEFT_MOVE_TEX,		//!< ���X���C���̈ړ����Ă���摜�����蓖�ĂĂ���


	PLAYER_FLAME_RIGHT_BULLET_TEX,
	PLAYER_FLAME_LEFT_BULLET_TEX,
	PLAYER_ICE_RIGHT_BULLET_TEX,
	PLAYER_ICE_LEFT_BULLET_TEX,
	PLAYER_WIND_RIGHT_BULLET_TEX,
	PLAYER_WIND_LEFT_BULLET_TEX,

	FLAMEGIMMICK_TEX,
	WINDGIMMICK_TEX,				//!< ���̃M�~�b�N�̉摜�����蓖�Ă�

	GOAL,

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
	Up,
	Down,
};

enum STATE
{
	Wait,		//!< �G�̑ҋ@���
	Move,		//!< �G�̓���
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

void Goal_Draw();

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
extern CUSTOMVERTEX g_Maptip[4];

#endif