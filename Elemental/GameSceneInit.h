////////////////////////////////////////////////
// �^
////////////////////////////////////////////////

/// ��l���̗l�X�ȏ������\����
typedef struct
{
	float posX, posY;
	float speed;
	bool skyFlag;
	bool jumpFlag;
	bool hitFlag;
	bool dashFlag;
	
}PLAYER_STATE;

/// �G�̍\����
typedef struct
{
	float posX, posY;
}ENEMY_STATE;

void Init();

////////////////////////////////////////////////
// extern
////////////////////////////////////////////////

extern ENEMY_STATE g_enemy; ///< ��l���̗l�X�ȏ������\���̂̕ϐ�
extern PLAYER_STATE g_player; ///< ��l���̗l�X�ȏ������\���̂̕ϐ�