//=============================================================================
//
// エフェクトの処理 [effect.cpp]
// Author : KIMURA KOUTA
//
//=============================================================================
#include "effect.h"
#include "manager.h"
#include "renderer.h"

//=============================================================================
// グローバル変数
//=============================================================================
LPDIRECT3DTEXTURE9 CEffect::m_pTextureEffect[MAX_EFFECTTEX] = {};

//=============================================================================
// マクロ定義
//=============================================================================
#define	EFFECT_01			"DATA/TEX/HitEffect.png"		// 読み込むテクスチャファイル名
#define	EFFECT_02			"DATA/TEX/Explosion.png"		// 読み込むテクスチャファイル名
#define EFFECT_SIZE (50)

//=============================================================================
// コンストラクタ
//=============================================================================
CEffect::CEffect(OBJTYPE type) : CBillboard(type)
{

}

//=============================================================================
// 初期化処理
//=============================================================================
HRESULT CEffect::Init(D3DXVECTOR3 pos, D3DXVECTOR3 move, int nLife, EFFECTTYPE effectType)
{
	m_move = D3DXVECTOR3(0.0f,0.0f,0.0f);

	CBillboard::SetPos(pos);

	m_move = move;
	m_nLife = nLife;
	EffectType = effectType;

	CBillboard::SetColor(D3DXCOLOR(1.0f, 1.0f, 1.0f, 0.5f));
	CBillboard::Init();
	return S_OK;
}

//=============================================================================
// 終了処理
//=============================================================================
void CEffect::Uninit(void)
{
	if (m_pVtxBuffEffect != NULL)
	{// 頂点バッファの開放
		m_pVtxBuffEffect->Release();
		m_pVtxBuffEffect = NULL;
	}

	CBillboard::Uninit();
}

//=============================================================================
// 更新処理
//=============================================================================
void CEffect::Update(void)
{
	D3DXVECTOR3 pos = CBillboard::GetPos();

	switch (EffectType)
	{
	case EFFECTTYPE_DAMAGE:
		CBillboard::SetSize(40.0f, 40.0f, 0.0f);

		break;

	case EFFECTTYPE_EXPLOSION:
		CBillboard::SetSize(400.0f, 400.0f, 0.0f);

		CBillboard::SetAnim(4, 1, 3);

		break;
	}


	pos += m_move;
	CBillboard::SetPos(pos);

	m_nLife--;

	CBillboard::Update();

	if (m_nLife <= 0)
	{
		this->Release();
	}
}

//=============================================================================
// 描画処理
//=============================================================================
void CEffect::Draw(void)
{
	CRenderer *pRenderer = CManager::GetRenderer();
	LPDIRECT3DDEVICE9 pDevice = pRenderer->GetDevice();

	// レンダーステート(加算合成処理)
	pDevice->SetRenderState(D3DRS_BLENDOP, D3DBLENDOP_ADD);
	pDevice->SetRenderState(D3DRS_SRCBLEND, D3DBLEND_SRCALPHA);
	pDevice->SetRenderState(D3DRS_DESTBLEND, D3DBLEND_ONE);

	CBillboard::Draw();

	// レンダーステート(通常ブレンド処理)
	pDevice->SetRenderState(D3DRS_BLENDOP, D3DBLENDOP_ADD);
	pDevice->SetRenderState(D3DRS_SRCBLEND, D3DBLEND_SRCALPHA);
	pDevice->SetRenderState(D3DRS_DESTBLEND, D3DBLEND_INVSRCALPHA);
}

//=============================================================================
// エフェクトの作成
//=============================================================================
CEffect * CEffect::Create(D3DXVECTOR3 pos, D3DXVECTOR3 move, int nLife,EFFECTTYPE effectType)
{
	CEffect *pEffect = new CEffect(OBJTYPE_EFFECT);
	pEffect->BindTexture(m_pTextureEffect[effectType]);
	pEffect->Init(pos, move, nLife, effectType);
	return pEffect;
}

//=============================================================================
// テクスチャの読み込み
//=============================================================================
HRESULT CEffect::Load(void)
{
	CRenderer *pRenderer = CManager::GetRenderer();
	LPDIRECT3DDEVICE9 pDevice = pRenderer->GetDevice();

	// テクスチャの読み込み
	D3DXCreateTextureFromFile(pDevice,				// デバイスへのポインタ
		EFFECT_01,		// ファイルの名前
		&m_pTextureEffect[EFFECTTYPE_DAMAGE]);	// 読み込むメモリー
												// テクスチャの読み込み
	D3DXCreateTextureFromFile(pDevice,				// デバイスへのポインタ
		EFFECT_02,		// ファイルの名前
		&m_pTextureEffect[EFFECTTYPE_EXPLOSION]);	// 読み込むメモリー

	return S_OK;
}

//=============================================================================
// テクスチャの破棄
//=============================================================================
void CEffect::Unload(void)
{
	// テクスチャの開放
	for (int nCntEffect = 0; nCntEffect < MAX_EFFECTTEX; nCntEffect++)
	{
		if (m_pTextureEffect[nCntEffect] != NULL)
		{
			m_pTextureEffect[nCntEffect]->Release();
			m_pTextureEffect[nCntEffect] = NULL;
		}
	}
}

//=============================================================================
// パーテクル
//=============================================================================
void CEffect::SetParticle(D3DXVECTOR3 pos, D3DXVECTOR3 move, int nLife, EFFECTTYPE effectType)
{

	CEffect::Create(D3DXVECTOR3(pos.x , pos.y, pos.z ), move, nLife, effectType);
	
}

//=============================================================================
// デストラクタ
//=============================================================================
CEffect::~CEffect()
{

}
