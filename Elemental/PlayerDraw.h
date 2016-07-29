typedef struct
{
	float posX, posY;
	bool jumpFlag;
	bool skyFlag;
}PLAYER_STATE;

void Draw_Player();

extern PLAYER_STATE g_player;