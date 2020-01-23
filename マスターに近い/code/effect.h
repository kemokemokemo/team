//=============================================================================
//
// エフェクトの処理 [effect.h]
// Author : KIMURA KOUTA
//
//=============================================================================
#ifndef _EFFECT_H_
#define _EFFECT_H_

#define _CRT_SECURE_NO_WARNINGS

//=============================================================================
// インクルードファイル
//=============================================================================
#include "main.h"
#include "billboard.h"

//=============================================================================
// マクロ定義
//=============================================================================
#define	MAX_EFFECT			(256)							// エフェクトの最大数
#define	MAX_EFFECTTEX		(1)							// エフェクトの最大数


//================================================================
// レンダリングクラス
//================================================================
class CEffect :public CBillboard
{
public:

	//=============================================================================
	// UIの種類
	//=============================================================================
	typedef enum
	{
		EFFECTTYPE_DAMAGE = 0,
		EFFECTTYPE_EXPLOSION,
		EFFECTTYPE_MAX
	} EFFECTTYPE;

	//=============================================================================
	// プロトタイプ宣言
	//=============================================================================
	CEffect(OBJTYPE type);
	~CEffect();

	HRESULT Init(D3DXVECTOR3 pos, D3DXVECTOR3 move, int nLife, EFFECTTYPE EffectType);
	void Uninit(void);
	void Update(void);
	void Draw(void);

	static CEffect *Create(D3DXVECTOR3 pos, D3DXVECTOR3 move, int nLife, EFFECTTYPE EffectType);
	static HRESULT Load(void);
	static void Unload(void);

	static void SetParticle(D3DXVECTOR3 pos, D3DXVECTOR3 move, int nLife, EFFECTTYPE EffectType);

private:

	static LPDIRECT3DTEXTURE9 m_pTextureEffect[MAX_EFFECTTEX];		// テクスチャへのポインタ
	LPDIRECT3DVERTEXBUFFER9 m_pVtxBuffEffect;				// 頂点バッファへのポインタ
	EFFECTTYPE EffectType;
	float size;
	D3DXVECTOR3 m_move;
	int m_nLife;
};

#endif