//=============================================================================
//
// モデル処理 [model.h]
// Author : KOUTA KIMURA
//
//=============================================================================
#ifndef _MODEL_H_
#define _MODEL_H_

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
#define MODELFILE0		"DATA/MODEL/icefence.x"					// 読み込むモデル
#define MODELFILE1		"DATA/MODEL/car_000.x"					// 読み込むモデル

#define MAX_TEXTURE		(21)									// テクスチャ数
#define MAX_SET_TEXTURE	(20)									// 設置テクスチャ数

//================================================================
// レンダリングクラス
//================================================================
class CModel : public CScene3D
{
public:

	//=============================================================================
	// プロトタイプ宣言
	//=============================================================================
	CModel(OBJTYPE type);
	~CModel();

	static CModel *Create(D3DXVECTOR3 pos, D3DXVECTOR3 rot, MODELTYPE type);

	HRESULT Init(D3DXVECTOR3 pos, D3DXVECTOR3 rot, MODELTYPE type);
	void Uninit(void);
	void Update(void);
	void Draw(void);

	//void SetModel(D3DXVECTOR3 pos, D3DXVECTOR3 rot, MODELTYPE type);
	//bool CollisionModel(D3DXVECTOR3 *pPos, D3DXVECTOR3 *pPosOld, D3DXVECTOR3 size);

private:

	LPDIRECT3DTEXTURE9	m_pTextureModel[MAX_TEXTURE] = {};			// テクスチャへのポインタ
	D3DXVECTOR3 m_pos;
};
#endif
