//====================================================================================================
//
// 弾処理 (bullet.cpp)
// Author (Kimura kouta)
//
//====================================================================================================
#include "bullet.h"
#include "renderer.h"
#include "manager.h"
#include "effect.h"
#include "Game.h"

//====================================================================================================
// マクロ定義
//====================================================================================================
#define BULLET_TEX "DATA/TEX/hadoken.png"
#define BULLET_TEX2 "DATA/TEX/gaude.png"				//読み込むテクスチャファイル名
#define BULLET_SIZE (1)
#define MAX_LIFE (40)

//====================================================================================================
// プロトタイプ宣言
//====================================================================================================

//====================================================================================================
// グローバル変数
//====================================================================================================
LPDIRECT3DTEXTURE9 CBullet::m_pTextureBullet[MAX_TEXBULLET] = {};

//====================================================================================================
// コンストラクタ
//====================================================================================================
CBullet::CBullet(OBJTYPE type) : CBillboard(type)
{
	m_move = D3DXVECTOR3(0.0f,0.0f,0.0f);
	m_pos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	m_nLife = 0;
}

//=============================================================================
// 初期化処理
//=============================================================================
HRESULT CBullet::Init(D3DXVECTOR3 pos, D3DXVECTOR3 move, BULLETTEX BulletTex, CMaker::MAKERTYPE makertype, int nLife)
{
	CBillboard::Init();

	SetPos(pos);
	SetMove(move);
	m_nLife = nLife;
	m_BulletTex = BulletTex;
	m_MakerType = makertype;


	switch (BulletTex)
	{
	case BULLETTEX_KEN:

		CBillboard::SetSize(70.0f, 70.0f, 0.0f);
		CBillboard::SetColor(D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f));
		break;

	case BULLETTEX_KANGAROO:

		CBillboard::SetSize(70.0f, 70.0f, 0.0f);
		CBillboard::SetColor(D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f));

		break;
	}

	return S_OK;
}

//==================================================================================================
//終了処理
//===================================================================================================
void CBullet::Uninit(void)
{
	CBillboard::Uninit();
}

//====================================================================================================
//更新処理
//=====================================================================================================
void CBullet::Update(void)
{
	CBillboard::Update();

	////ポジションの取得
	m_pos = CBillboard::GetPos();

	////移動処理
	m_pos += m_move;

	//ライフのカウント
	m_nLife--;

	if (m_nLife <= 0)
	{
		Release();
	}

	PlayerCollision();

	SetPos(m_pos);
}

//========================================================================================================
// 弾とプレイヤーの当たり判定
//========================================================================================================
void CBullet::PlayerCollision()
{
	//変数宣言
	D3DXVECTOR3 PosP;
	//半径
	float fRadiusE = 100 / 2;
	float fRadiusP = 20 / 2;

	for (int nCntScene = 0; nCntScene < 256; nCntScene++)
	{
		for (int nCntModel = 0; nCntModel < MAX_POLYGON; nCntModel++)
		{
			CScene *pScene;

			pScene = CScene::GetScene(OBJTYPE_PLAYER, nCntModel);

			if (!pScene)
				continue;

			CPlayerBase *pPlayer = (CPlayerBase*)pScene;

			D3DXVECTOR3 pos;

			PosP = ((CPlayerBase*)pScene)->GetPos();

			if (pPlayer->GetMaker() != m_MakerType)
			{
				//円の当たり判定
				if ((m_pos.x - PosP.x) * (m_pos.x - PosP.x) + (m_pos.y - PosP.y) * (m_pos.y - PosP.y) <= (fRadiusP + fRadiusE) * (fRadiusP + fRadiusE))
				{
					((CPlayerBase*)pScene)->Damage(pPlayer, 1);

					Release();
				}
			}
		}
	}
}

//========================================================================================================
// 移動処理
//========================================================================================================
void CBullet::SetMove(D3DXVECTOR3 move)
{
	m_move = move;
}

//========================================================================================================
// 体力の取得
//========================================================================================================
int CBullet::GetLife()
{
	return m_nLife;
}

//========================================================================================================
// 描画処理
//========================================================================================================
CBullet *CBullet::Create(D3DXVECTOR3 pos, D3DXVECTOR3 move, BULLETTEX BulletTex, CMaker::MAKERTYPE makertype,int nLife)
{
	CBullet *pBullet;

	pBullet = new CBullet(OBJTYPE_BULLET);

	pBullet->BindTexture(m_pTextureBullet[BulletTex]);

	pBullet->Init(pos,move, BulletTex, makertype,nLife);

	return pBullet;
}

//========================================================================================================
// テクスチャの読み込み
//========================================================================================================
HRESULT CBullet::Load(void)
{
	CRenderer *pRenderer = CManager::GetRenderer();
	LPDIRECT3DDEVICE9 pDevice = pRenderer->GetDevice();

	//テクスチャの読み込み
	D3DXCreateTextureFromFile(
		pDevice,
		BULLET_TEX,
		&m_pTextureBullet[BULLETTEX_KEN]);

	//テクスチャの読み込み
	D3DXCreateTextureFromFile(
		pDevice,
		BULLET_TEX2,
		&m_pTextureBullet[BULLETTEX_KANGAROO]);

	return S_OK;
}

//=======================================================================================================
// テクスチャの破棄
//========================================================================================================
void CBullet::Unload(void)
{
	for (int nCnt =0; nCnt < MAX_TEXBULLET; nCnt++)
	{
		// 頂点バッファの開放
		if (m_pTextureBullet[nCnt] != NULL)
		{
			m_pTextureBullet[nCnt]->Release();
			m_pTextureBullet[nCnt] = NULL;
		}
	}
}

//========================================================================================================
// 描画処理
//========================================================================================================
void CBullet::Draw(void)
{
	CBillboard::Draw();
}

//====================================================================================================
// デストラクタ
//=====================================================================================================
CBullet::~CBullet()
{

}