/// 敵の構造体
typedef struct
{
	float posX, posY;
}ENEMY_STATE;

/// 主人公の描画
/**
* @return なし
*/
void Draw_Enemy();

////////////////////////////////////////////////
// extern
////////////////////////////////////////////////
extern ENEMY_STATE g_enemy; ///< 主人公の様々な情報を持つ構造体の変数