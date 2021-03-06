//====================================================================================================
//
// ガード処理 (guard.cpp)
// Author (Kimura kouta)
//
//====================================================================================================
#include "maker.h"
#include "renderer.h"
#include "manager.h"
#include "Game.h"
#include "playerbase.h"
#include "player_Ken.h"
#include "guard.h"

//====================================================================================================
// マクロ定義
//====================================================================================================
#define BULLET_SIZE (40)
#define MAX_LIFE (40)
#define TEX_01 "DATA/TEX/gaude.png"					//読み込むテクスチャファイル名

//====================================================================================================
// プロトタイプ宣言
//====================================================================================================

//====================================================================================================
// グローバル変数
//====================================================================================================
LPDIRECT3DTEXTURE9 CGuard::m_pTextureGuard[1] = {};

//====================================================================================================
// コンストラクタ
//====================================================================================================
CGuard::CGuard(OBJTYPE type) : CBillboard(type)
{
}
//=============================================================================
// 初期化処理
//=============================================================================
HRESULT CGuard::Init(D3DXVECTOR3 pos, int Life, CMaker::MAKERTYPE makertype)
{
	CBillboard::Init();

	SetPos(pos);
	Size = 100.0f;
	CBillboard::SetSize(Size, Size, 0.0f);
	if (makertype == CMaker::MAKERTYPE_1P)
	{
		CBillboard::SetColor(D3DXCOLOR(1.0f, 0.0f, 0.0f, 0.5f));
	}

	if (makertype == CMaker::MAKERTYPE_2P)
	{
		CBillboard::SetColor(D3DXCOLOR(1.0f, 0.0f, 0.0f, 0.5f));
	}
	m_nLife = Life;
	Makertype = makertype;
	m_nLifeOld = m_nLife;

	return S_OK;
}


//==================================================================================================
//終了処理
//===================================================================================================
void CGuard::Uninit(void)
{
	CBillboard::Uninit();
}

//====================================================================================================
//更新処理
//=====================================================================================================
void CGuard::Update(void)
{
	CBillboard::Update();

	for (int nCntModel = 0; nCntModel < MAX_POLYGON; nCntModel++)
	{
		CScene *pScene;

		pScene = CScene::GetScene(OBJTYPE_PLAYER, nCntModel);

		if (!pScene)
			continue;

		CPlayerBase *pPlayer = (CPlayerBase*)pScene;

		if (pPlayer->GetMaker() == Makertype)
		{
			D3DXVECTOR3 pos = CBillboard::GetPos();

			D3DXVECTOR3 posm = pPlayer->GetPos();

			pos = posm;
			CBillboard::SetPos(D3DXVECTOR3(pos.x, pos.y + 80.0f, pos.z));
		}
	}

	if (m_nLife <= 0)
	{
		m_nLife = 0;
	}



	if (m_nLife != m_nLifeOld)
	{
		int Calculation = m_nLifeOld;

		Calculation -= m_nLife;

		Size -= Calculation * 5;
		m_nLifeOld = m_nLife;

		CBillboard::SetSize(Size, Size, 0.0f);
	}

}
//========================================================================================================
// 描画処理
//========================================================================================================
CGuard *CGuard::Create(D3DXVECTOR3 pos, int Life, CMaker::MAKERTYPE makertype)
{
	CGuard *pGuard;

	pGuard = new CGuard(OBJTYPE_ANIMATION);

	pGuard->BindTexture(m_pTextureGuard[0]);

	pGuard->Init(pos, Life, makertype);

	return pGuard;
}

//========================================================================================================
// テクスチャの読み込み
//========================================================================================================
HRESULT CGuard::Load(void)
{
	CRenderer *pRenderer = CManager::GetRenderer();
	LPDIRECT3DDEVICE9 pDevice = pRenderer->GetDevice();

	//テクスチャの読み込み
	D3DXCreateTextureFromFile(
		pDevice,
		TEX_01,
		&m_pTextureGuard[0]);


	return S_OK;
}
//=======================================================================================================
// テクスチャの破棄
//========================================================================================================
void CGuard::Unload(void)
{
	// 頂点バッファの開放
	if (m_pTextureGuard[0] != NULL)
	{
		m_pTextureGuard[0]->Release();
		m_pTextureGuard[0] = NULL;
	}
}

//========================================================================================================
// 描画処理
//========================================================================================================
void CGuard::GuardLife(int nDamage)
{
	m_nLifeOld = m_nLife;

	m_nLife -= nDamage;
}

int CGuard::GetGuardLife()
{
	return m_nLife;
}

//========================================================================================================
// 描画処理
//========================================================================================================
void CGuard::Draw(void)
{
	CBillboard::Draw();
}

//====================================================================================================
// デストラクタ
//=====================================================================================================
CGuard::~CGuard()
{

}