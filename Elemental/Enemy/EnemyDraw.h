/**
 * @file EnemyDraw.h
 * @breif 敵の描画ファイル

 * 全ての敵の描画に必要なプロトタイプ宣言を書いている

 */

#ifndef ENEMYDRAW
#define ENEMYDRAW

#define KODORA_MAX 5
#define SKERETON_MAX 2
#define SLIME_MAX 2
#define FLAME_KODORA 10
#define ICE_KODORA 11
#define WIND_KODORA 12
#define FLAME_SKERETON 15
#define ICE_SKERETON 16
#define WIND_SKERETON 17
#define FLAME_SLIME 20
#define ICE_SLIME 21
#define WIND_SLIME 22

////////////////////////////////////////////////
//使用する関数のプロトタイプ宣言
////////////////////////////////////////////////

/// コドラの描画関数
/**
* @return なし
*/
void Kodora_Walk_Draw();

void Kodora_Stay_Draw();

void Skeleton_Draw();

void Slime_Draw();

void Kodora_Init();

void Slime_Init();

#endif