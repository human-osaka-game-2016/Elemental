#include <dinput.h>
#include <Direct_Draw.h>
#include <Direct_Key_Input.h>
#include "GameSceneCntrol.h"
#include "PlayerControl.h"


void Control()
{
	Get_Key_State();

	Check_Key(DIK_LEFT, LEFT);
	Check_Key(DIK_RIGHT, RIGHT);
	Check_Key(DIK_UP, UP);
	Check_Key(DIK_DOWN, DOWN);
	Check_Key(DIK_Z, Z);

	Player_Control();

}

