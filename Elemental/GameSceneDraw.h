/**
 * @file GameSceneDraw.h
 * @breif �Q�[���S�̂ɕK�v�ȕ`��Ɋ֌W�����`�E�^�E�v���g�^�C�v�錾�Eextern�������Ă���
 * @author �ēc�N�ǁA�R�{�ϑ��Y�A�ݖ{��́A����G���A�c���M��A�|���ĕ��A�ѓc����
 * @date 2016�NX��Y��
 */

////////////////////////////////////////////////
// ��`
////////////////////////////////////////////////

#define TIPSIZE 64		///< �}�b�v�`�b�v�̃T�C�Y
#define MAP_HEIGHT 11	///< �`�悷��}�b�v�̏c�̍ő�l
#define MAP_WIDTH 34	///< �`�悷��}�b�v�̉��̍ő�l

#include <Direct_Draw.h>

////////////////////////////////////////////////
// �^
////////////////////////////////////////////////

/// �摜����
enum 
{
	BACKGROUND_TEX,
	MAP_GROUND_TEX,
	PLAYER_TEX,
	TEX_MAX,
};

////////////////////////////////////////////////
// �g�p����֐��̃v���g�^�C�v�錾
////////////////////////////////////////////////

/// 60fps�Ń��[�v������`��֐�
/**
 * @return �Ȃ�
 */
void Render();

/// csv�œǂݍ��񂾃}�b�v�̕`��
/**
 * @return �Ȃ�
 */
void Draw_Map();

/// csv�t�@�C���̓ǂݍ���
/**
 * @param [out] _mapdate �ǂݍ���csv�t�@�C���̖��O
 * @return �Ȃ�
 */
void Load_Map(const char* _mapdata);

/// 
void Draw_Obj(LPDIRECT3DTEXTURE9   _pTexture, CUSTOMVERTEX _setdraw[]);

/// �e�N�X�`���̉���֐�
/**
 * @return �Ȃ�
 */
void Tex_Free();

////////////////////////////////////////////////
// extern
////////////////////////////////////////////////
extern float g_ScreenOriginX;					///< ��ʂ̍���̂����W
extern float g_ScreenOriginY;					///< ��ʂ̍���̂����W
extern int map[MAP_HEIGHT][MAP_WIDTH];			///< csv�œǂݍ��񂾃}�b�v��2�����z��
extern LPDIRECT3DTEXTURE9 g_pTexture[TEX_MAX];
