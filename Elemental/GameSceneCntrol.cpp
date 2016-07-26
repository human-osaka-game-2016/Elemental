// キー操作するために必要なインクルード
#include <dinput.h>
// 自作ライブラリのインクルード
#include <Direct_Draw.h>
#include <Direct_Key_Input.h>
// ただのヘッダー
#include "GameSceneDraw.h"
#include "GameSceneCntrol.h"


// 60フレームで呼ばれるキーの関数
void Control()
{
	// これをすることによってキーボードがゲームでt変えるようになる
	Get_Key_State();

	// ダイレクトインプットの仮想のキーで何が押されているかの確認をしている
	Check_Key(DIK_LEFT, LEFT);
	Check_Key(DIK_RIGHT, RIGHT);

	Player_Control();
}

//　現状はマップの全体を見るためにしか使ってませんが名前のようにここにプレイヤー操作系の処理を書きます
void Player_Control()
{
	if (g_Key[LEFT] == ON)
	{
		// 左が押されたらマップが左に動く
		for (int i = 0; i < 4; i++)
		{
			g_maptip[i].m_x += MOVE_SPEED;
		}
	}

	if (g_Key[RIGHT] == ON)
	{
		// 右が押されたらマップが右に動く
		for (int i = 0; i < 4; i++)
		{
			g_maptip[i].m_x -= MOVE_SPEED;
		}
	}
}
