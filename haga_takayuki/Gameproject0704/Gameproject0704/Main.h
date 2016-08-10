/**
*@file Main.h
*@brief �Q�[���̃G���g���[�|�C���g��cpp�̃w�b�_�[�t�@�C��.
*/
#ifndef MAIN_H
#define MAIN_H

#include <windows.h>
#include <d3d9.h>
#include <dinput.h>
#include"draw_config.h"

/**�E�B���h�E��<br>*/
#define WINDOW_W 480
/**�E�B���h�E����<br>*/
#define WINDOW_H 640
/**�E�B���h�E��<br>*/
#define WINDOW_TITLE TEXT("�[�s�E�X")	

/**�v���C���[�e�̐�<br>*/
#define BULLETMAX 11

/**�G�̐�<br>*/
#define ENEMYMAX 4
/**�G�̒e�̐�<br>*/
#define ENEMYBULLETMAX 4

/**�Q�[���̃n�C�X�R�A�̋L�^�ł���ő吔<br>*/
#define RANKING_SCORE_MAX 5

/*�v���C���[�̍\����<br>*/
typedef struct
{
	int	LIFE;				/**<�c�@��*/
	int	SCORE;				/**<�X�R�A*/
	float posX, posY;		/**<���W*/
	bool hitFlag;			/**<�����������̃t���O*/
	bool drawFlag;			/**<�`��̃t���O*/
	bool animeExplosion;	/**<�A�j���[�V�����t���O(����)*/

}PLAYERSTATE;


/**�G�̍\����<br>*/
typedef struct
{
	CUSTOMVERTEX enemy[4];		/**<�o�[�e�b�N�X���*/
	int	SCORE;					/**<�|�����Ƃ��̃X�R�A*/
	float posX, posY;			/**<���W*/
	bool drawFlag;				/**<�`��̃t���O*/
	bool animeExplosion;		/**<�A�j���[�V�����t���O(����)*/
	bool moveRight;				/**<�G�̍��E�̓����t���O*/
	bool moveDown;				/***<�G�̉��̓���*/

}ENEMYSTATE;

/**�e�̍\����<br>*/
typedef struct
{
	CUSTOMVERTEX bullet[4];		/**<�o�[�e�b�N�X���*/
	float posX, posY;			/**<���W*/
	bool initFlag;				/**<�e�̏����ʒu�t���O*/
	bool drawFlag;				/**<�`��̃t���O*/

}BULLETSTATE;

/**�w�i�̍\����<br>*/
typedef struct
{
	float posX, posY;		/**<���W*/

}BACKGROUNDSTATE;

/**�e�L�X�g�̍\����<br>*/
typedef struct
{
	float posX, posY;		/**<���W*/

}TEXTSTATE;


/**�t���O�̍\����<br>*/
typedef struct
{
	bool titleScene;	 /**<�^�C�g���t���O*/							
	bool gameEnd;		 /**<�Q�[���I�[�o�[�t���O*/						
	bool loadScore;		 /**<�f�[�^���[�h�t���O*/
	bool saveScore;		 /**<�f�[�^�Z�[�u�t���O*/						
	bool gameComplete;	 /**<�Q�[���N���A�t���O*/	

}FLAGSTATE;

/**�X�R�A�����L���O�̍\����<br>*/
typedef struct
{
	char name[256];		/**<���O(���񖢎���)*/
	int score;			/**<���_*/

}SCORESTATE;


/**�e�N�X�`���[�Ǘ��p�񋓌^<br>*/
enum GAME_TEXTURE
{
	BACKGROUND_TEX,		/**<�w�i�̃e�N�X�`���[*/
	BULLET_TEX,			/**<�e�̃e�N�X�`���[*/
	PLAYER_TEX,			/**<�v���C���[�̃e�N�X�`���[*/
	ENEMY_TEX,			/**<�G�̃e�N�X�`���[*/
	EXPLOSION_TEX,		/**<�����̃e�N�X�`���[*/
	TITLE_TEX,			/**<�^�C�g���̃e�N�X�`���[*/
	TEXT01_TEX,			/**<����(�����E�Q�[���I�[�o�[)�̃e�N�X�`���[*/
	BULLET_ENEMY_TEX,	/**<�G�̒e�̃e�N�X�`���[*/
	SCORE_TEX,			/**<�X�R�A�̃e�N�X�`���[*/
	TEXT02_TEX,			/**<����(�Q�[���N���A�E�x��)�̃e�N�X�`���[*/
	GAME_TEX_MAX		/**<���̃Q�[���Ŏg�p����e�N�X�`���[�̍ő吔*/
};

/**�w�i�Ǘ��p�񋓌^*/
enum BACK_GROUND
{
	BG_ONE,				/**<�w�i��1����*/
	BG_TWO,				/**<�w�i��2����*/
	BG_MAX
};

/**DirectX�I�u�W�F�N�g�̃|�C���^*/
extern LPDIRECT3D9			g_pDirect3D;
/**DirectX�f�o�C�X�̃|�C���^*/
extern LPDIRECT3DDEVICE9	g_pDirect3DDevice;
/**�摜�������ꂨ�����߂̔z��*/
extern LPDIRECT3DTEXTURE9	g_pGameTexture[GAME_TEX_MAX];	
/**DirectInput8 �C���^�[�t�F�C�X*/
extern LPDIRECTINPUT8		g_pDInput;
/**�L�[�{�[�h�f�o�C�X*/
extern LPDIRECTINPUTDEVICE8 g_pkeyDevice;				


#endif