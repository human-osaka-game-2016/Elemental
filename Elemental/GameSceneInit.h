////////////////////////////////////////////////
// 型
////////////////////////////////////////////////

/// 主人公の様々な情報を持つ構造体
typedef struct
{
	float posX, posY;
	float speed;
	bool skyFlag;
	bool jumpFlag;
	bool hitFlag;
	bool dashFlag;
	
}PLAYER_STATE;

/// 敵の構造体
typedef struct
{
	float posX, posY;
}ENEMY_STATE;

void Init();

////////////////////////////////////////////////
// extern
////////////////////////////////////////////////

extern ENEMY_STATE g_enemy; ///< 主人公の様々な情報を持つ構造体の変数
extern PLAYER_STATE g_player; ///< 主人公の様々な情報を持つ構造体の変数