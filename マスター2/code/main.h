//====================================================================================================
//
// メイン (main.h)
// Author (Kimura kouta)
//
//====================================================================================================
#ifndef _MAIN_H_
#define _MAIN_H_

#define _CRT_SECURE_NO_WARNINGS

//====================================================================================================
//インクリードファイル
//====================================================================================================
#include<windows.h>
#include <stdio.h>
#include"d3dx9.h"		//描画処理に必要
#define DIRECTINPUT_VERSION	(0x0800)
#include"dinput.h"		//入力処理に必要
#include "xaudio2.h"

//====================================================================================================
//ライブラのリンク
//====================================================================================================
#pragma comment(lib,"d3d9.lib")		//描画処理に必要
#pragma comment(lib,"d3dx9.lib")	//[d3d9,lib]の拡張
#pragma comment(lib,"dxguid.lib")	//DirectXコンポーネント
#pragma comment(lib,"winmm.lib")	//システム時間に必要
#pragma comment(lib,"dinput8.lib")	//入力処理に必要

//====================================================================================================
// マクロ定義
//==================================================================================================== 
#define SCREEN_WIDTH	(1280)		//ウィンドウの幅
#define SCREEN_HEIGHT	(720)		//ウィンドウの高さ

// ２Ｄポリゴン頂点フォーマット( 頂点座標[2D] / 頂点カラー / テクスチャ座標 )
#define FVF_VERTEX_2D	(D3DFVF_XYZRHW|D3DFVF_DIFFUSE|D3DFVF_TEX1)

// 3Ｄポリゴン頂点フォーマット( 頂点座標[2D] / 頂点カラー / テクスチャ座標 )
#define	FVF_VERTEX_3D (D3DFVF_XYZ | D3DFVF_NORMAL | D3DFVF_DIFFUSE| D3DFVF_TEX1)

//====================================================================================================
// 構造体定義
//=====================================================================================================

// ２Ｄポリゴン頂点フォーマットに合わせた構造体を定義
typedef struct
{
	D3DXVECTOR3 pos;	//ポジション
	float       rhw;	//1で固定する
	D3DCOLOR    col;	//色
	D3DXVECTOR2 tex;	//テクスチャ情報
}VERTEX_2D;


// 3Ｄポリゴン頂点フォーマットに合わせた構造体を定義
typedef struct
{
	D3DXVECTOR3 pos;	// 頂点座標
	D3DXVECTOR3 nor;	// 頂点座標
	D3DCOLOR col;		// 頂点カラー
	D3DXVECTOR2 tex;	// テクスチャ座標
} VERTEX_3D;

int GetFPS();

#endif