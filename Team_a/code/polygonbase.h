//====================================================================================================
//
// ポリゴン処理 (Polygonbase.h)
// Author KOUTA KIMURA
//
//====================================================================================================
#ifndef _POLYGONBASE_H_
#define _POLYGONBASE_H_

//====================================================================================================
//インクリードファイル
//====================================================================================================
#include"main.h"
#include"Scene.h"

//====================================================================================================
// マクロ定義
//==================================================================================================== 

//================================================================
// レンダリングクラス
//================================================================
class CPolygonBase : public CScene
{
public:
	//=============================================================================
	// モーションの種類
	//=============================================================================
	typedef enum
	{
		MOTIONTYPE_WAIT = 0,	// ニュートラル
		MOTIONTYPE_RUN,			// ランニング
		MOTIONTYPE_LIGHT0,		// 弱攻撃1段目
		MOTIONTYPE_LIGHT1,		// 2段目
		MOTIONTYPE_LIGHT2,		// 3段目
		MOTIONTYPE_DASHATK,		// ダッシュ攻撃
		MOTIONTYPE_UPATK,		// 上攻撃
		MOTIONTYPE_CROUCHATK,	// しゃがみ攻撃
		MOTIONTYPE_CROUCHWAIT,	// しゃがみ中
		MOTIONTYPE_DAMAGE,		// ダメージ
		MOTIONTYPE_JUMP,		// 空中
		MOTIONTYPE_DOUBLEJUMP,	// 二段ジャンプ
		MOTIONTYPE_RAND,		// 着地
		MOTIONTYPE_AIR_N,		// 空中ニュートラル
		MOTIONTYPE_AIR_F,		// 空中前
		MOTIONTYPE_AIR_B,		// 空中後ろ
		MOTIONTYPE_AIR_U,		// 空中上
		MOTIONTYPE_AIR_D,		// 空中下
		MOTIONTYPE_SP_N,		// 特殊ニュートラル
		MOTIONTYPE_SP_UP,		// 特殊上
		MOTIONTYPE_SP_DOWN,		// 特殊下
		MOTIONTYPE_GAUDE,		// ガード
		MOTIONTYPE_MAX			// モーションの最大数
	} MOTIONTYPE;

	//================================================================
	// プロトタイプ宣言
	//================================================================
	CPolygonBase(OBJTYPE nPriority);
	~CPolygonBase();

	HRESULT Init(void);
	void Uninit(void);
	void Update(void);
	void Draw(void);

private:
	LPDIRECT3DTEXTURE9 m_pTexturePolygon;
	LPDIRECT3DVERTEXBUFFER9 m_pVtxBuffScene;
	D3DXMATRIX m_mtxWorldPolygon;
	D3DXVECTOR3 m_rotPolygon;
	D3DXVECTOR3 m_PosPolygon;
	D3DXVECTOR3 m_pos;
};

//====================================================================================================
// マクロ定義
//==================================================================================================== 
#endif