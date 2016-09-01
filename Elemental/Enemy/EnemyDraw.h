/**
 * @file EnemyDraw.h
 * @breif 敵の描画ファイル

 * 全ての敵の描画に必要なプロトタイプ宣言を書いている

 */

#ifndef ENEMYDRAW
#define ENEMYDRAW

#define KODORA_MAX 1
#define SKERETON_MAX 1
#define SLIME_MAX 1

////////////////////////////////////////////////
//使用する関数のプロトタイプ宣言
////////////////////////////////////////////////

/// コドラの描画関数
/**
* @return なし
*/
void Kodora_Draw();

void Skeleton_Draw();

void Slime_Draw();



#endif