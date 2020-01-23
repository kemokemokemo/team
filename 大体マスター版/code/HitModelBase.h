//=============================================================================
//
// 当たり判定用モデル処理 [hitmodel.h]
// Author : KOUTA KIMURA
//
//=============================================================================
#ifndef _HITMODELBASE_H_
#define _HITMODELBASE_H_

#define _CRT_SECURE_NO_WARNINGS

//=============================================================================
// インクルードファイル
//=============================================================================
#include "main.h"
#include "Scene3D.h"

//=============================================================================
// 構造体定義
//=============================================================================

//=============================================================================
// マクロ定義
//=============================================================================
#define MAX_TEXTURE		(21)									// テクスチャ数
#define MAX_SET_TEXTURE	(20)									// 設置テクスチャ数

//================================================================
// レンダリングクラス
//================================================================
class CHitModelBase : public CScene
{
public:
	enum UNITTYPE
	{
		UNITTYPE_FLOOR,
		UNITTYPE_MAX
	};

	//=============================================================================
	// プロトタイプ宣言
	//=============================================================================
	CHitModelBase(OBJTYPE type);
	~CHitModelBase();


	HRESULT Init();
	void Uninit(void);
	void Update(void);
	void Draw(void);

	D3DXVECTOR3 GetPos();
	D3DXVECTOR3 GetSize();
	void SetPos(D3DXVECTOR3 pos);
	void Setsize(D3DXVECTOR3 scale);

	void BindHitModel(DWORD NumMat, LPD3DXMESH Mesh, LPD3DXBUFFER BuffMat);

private:

	LPDIRECT3DVERTEXBUFFER9 m_pVtxBuffScene;		// 頂点バッファへのポインタ
	LPDIRECT3DTEXTURE9 m_pTextureModel;
	D3DXVECTOR3 m_pos;
	D3DXVECTOR3 m_rot;						// ポリゴンの向き
	D3DXVECTOR3	m_scale;						
	D3DXMATRIX  m_mtxWorld;					// ワールドマトリックス
	D3DXVECTOR3		m_vtxMin;				//最小値
	D3DXVECTOR3		m_vtxMax;				//最大値 

	DWORD		nNumMat;				// マテリアル情報の数
	LPD3DXMESH	pMesh;					// メッシュ情報へのポインタ
	LPD3DXBUFFER	pBuffMat;				// マテリアル情報へのポインタ

};
#endif
