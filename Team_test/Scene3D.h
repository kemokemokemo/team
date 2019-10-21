//====================================================================================================
//
// レンダリング処理 (Scene.h)
// Author (Kimura kouta)
//
//====================================================================================================
#ifndef _SCENE3D_H_
#define _SCENE3D_H_

//====================================================================================================
//インクリードファイル
//====================================================================================================
#include"main.h"
#include"Scene.h"

//====================================================================================================
// マクロ定義
//==================================================================================================== 
#define MAX_MODEL		(128)									// モデルの数

//================================================================
// レンダリングクラス
//================================================================
class CScene3D : public CScene
{
public:

	//=============================================================================
	// モデルの種類
	//=============================================================================
	typedef enum
	{
		MODELTYPE_BILL0 = 0,		// ビル0			[0]
		MODELTYPE_CAR,
		MODELTYPE_MAX				// 種類の最大数
	} MODELTYPE;

	//================================================================
	// プロトタイプ宣言
	//================================================================
	CScene3D(OBJTYPE nPriority);
	~CScene3D();

	HRESULT Init(void);
	void Uninit(void);
	void Update(void);
	void Draw(void);
	void DrawModel(void);
	void ModelInit(void);

	D3DXVECTOR3 GetPos(void);
	void SetPos(D3DXVECTOR3 pos);
	void SetType(MODELTYPE Type);

private:

	VERTEX_3D m_Vertex[4];
	LPDIRECT3DTEXTURE9 m_pTexturePolygon;
	LPDIRECT3DVERTEXBUFFER9 m_pVtxBuffScene;		// 頂点バッファへのポインタ
	D3DXVECTOR3 m_rotPolygon;
	D3DXMATRIX m_mtxWorldPolygon;
	D3DXVECTOR3 m_PosPolygon;

	D3DXVECTOR3 m_pos;						// ポリゴンの位置
	D3DXVECTOR3 m_rot;						// ポリゴンの向き
	D3DXVECTOR3	m_move;						// 移動量
	D3DXMATRIX  m_mtxWorld;					// ワールドマトリックス
	bool		m_bUse;						// 使用しているか
	MODELTYPE	m_type;						// 種類

	static DWORD		nNumMat;						// マテリアル情報の数
	static LPD3DXMESH	pMesh;						// メッシュ情報へのポインタ
	static LPD3DXBUFFER	pBuffMat;					// マテリアル情報へのポインタ

	D3DXVECTOR3		vtxMin;						// 最大値
	D3DXVECTOR3		vtxMax;						// 最小値

};

//====================================================================================================
// マクロ定義
//==================================================================================================== 
#endif