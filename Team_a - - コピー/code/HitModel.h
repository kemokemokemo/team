//=============================================================================
//
// 当たり判定用モデル処理 [hitmodel.h]
// Author : KOUTA KIMURA
//
//=============================================================================
#ifndef _HITMODEL_H_
#define _HITMODEL_H_

#define _CRT_SECURE_NO_WARNINGS

//=============================================================================
// インクルードファイル
//=============================================================================
#include "main.h"
#include "HitModelBase.h"

class CPlayerBase;

//=============================================================================
// マクロ定義
//=============================================================================
#define MAX_TEXTURE		(21)									// テクスチャ数
#define MAX_SET_TEXTURE	(20)									// 設置テクスチャ数

//================================================================
// レンダリングクラス
//================================================================
class CHitModel : public CHitModelBase
{
public:
	enum UNITTYPE
	{
		UNITTYPE_FLOOR,
		UNITTYPE_MAX
	};

	struct shape
	{
		DWORD		nNumMat;				// マテリアル情報の数
		LPD3DXMESH	pMesh;					// メッシュ情報へのポインタ
		LPD3DXBUFFER	pBuffMat;			// マテリアル情報へのポインタ
	};

	//=============================================================================
	// プロトタイプ宣言
	//=============================================================================
	CHitModel(OBJTYPE type);
	~CHitModel();

	static CHitModel *Create(CPlayerBase *pplayer, D3DXVECTOR3 pos, D3DXVECTOR3 scale);

	HRESULT Init(D3DXVECTOR3 pos, D3DXVECTOR3 scale);
	void Uninit(void);
	void Update(void);
	void Draw(void);

	static HRESULT Load(void);
	static void Unload(void);

private:

	static shape ShapeBase;
	
	CPlayerBase *m_pPlayer;
};
#endif
