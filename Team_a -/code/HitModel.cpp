//=============================================================================
//
// モデル処理 [hitmodel.cpp]
// Author : KOUAT KIMURA
//
//=============================================================================

//=============================================================================
// インクルードファイル
//=============================================================================
#include "hitmodel.h"
#include "camera.h"
#include "manager.h"
#include "renderer.h"
#include "playerbase.h"

//=============================================================================
// メンバ変数初期化
//=============================================================================
#define MODELFILE0		"DATA/MODEL/HitModel.x"					// 読み込むモデル
#define MAX_HITMODEL		(1)									// モデルの数

DWORD		CHitModel::nNumMat = {};				// マテリアル情報の数
LPD3DXMESH	CHitModel::pMesh = {};					// メッシュ情報へのポインタ
LPD3DXBUFFER	CHitModel::pBuffMat = {};				// マテリアル情報へのポインタ

//=============================================================================
// コンストラクタ
//=============================================================================
CHitModel::CHitModel(OBJTYPE type) : CHitModelBase(type)
{
}

//=============================================================================
// デストラクタ
//=============================================================================
CHitModel::~CHitModel()
{
}

//=============================================================================
// モデルの生成
//=============================================================================
CHitModel * CHitModel::Create(D3DXVECTOR3 pos, D3DXVECTOR3 scale)
{
	CHitModel *pHitModel;
	pHitModel = new CHitModel(OBJTYPE_BG);
	pHitModel->BindHitModel(nNumMat, pMesh, pBuffMat);
	pHitModel->Init(pos, scale);

	return pHitModel;
}

//=============================================================================
// 初期化処理
//=============================================================================
HRESULT CHitModel::Init(D3DXVECTOR3 pos, D3DXVECTOR3 scale)
{
	CHitModelBase::Init();

	CHitModelBase::SetPos(pos);
	CHitModelBase::Setsize(scale);

	return S_OK;
}

//=============================================================================
// 終了処理
//=============================================================================
void CHitModel::Uninit(void)
{
	CHitModelBase::Uninit();
}

//=============================================================================
// 更新処理
//=============================================================================
void CHitModel::Update(void)
{
	for (int nCntModel = 0; nCntModel < MAX_POLYGON; nCntModel++)
	{
		CScene *pScene;

		pScene = CScene::GetScene(OBJTYPE_PLAYER, nCntModel);

		if (!pScene)
			continue;

		CPlayerBase *pPlayer = (CPlayerBase*)pScene;

		D3DXVECTOR3 pos;

		D3DXVECTOR3 posp = pPlayer->GetPosParts();

		pos = posp;

		CHitModelBase::SetPos(pos);

		break;
	}
	CHitModelBase::Update();
}

//=============================================================================
// 描画処理
//=============================================================================
void CHitModel::Draw(void)
{
	CHitModelBase::Draw();
}

//========================================================================================================
// モデルの読み込み処理
//========================================================================================================
HRESULT CHitModel::Load(void)
{
	CRenderer *pRenderer = CManager::GetRenderer();
	LPDIRECT3DDEVICE9 pDevice = pRenderer->GetDevice();

	// Xファイルの読み込み
	D3DXLoadMeshFromX(MODELFILE0, D3DXMESH_SYSTEMMEM, pDevice, NULL,
		&pBuffMat, NULL,
		&nNumMat,
		&pMesh);

	return S_OK;
}

//========================================================================================================
// モデルの解放処理
//========================================================================================================
void CHitModel::Unload(void)
{

}
