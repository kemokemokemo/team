//=============================================================================
//
// モデル処理 [model.cpp]
// Author : KOUAT KIMURA
//
//=============================================================================

//=============================================================================
// インクルードファイル
//=============================================================================
#include "model.h"
#include "camera.h"
#include "manager.h"
#include "renderer.h"

//=============================================================================
// メンバ変数初期化
//=============================================================================
DWORD			CModel::nNumMat = NULL;
LPD3DXMESH		CModel::pMesh = NULL;
LPD3DXBUFFER	CModel::pBuffMat = NULL;

//=============================================================================
// コンストラクタ
//=============================================================================
CModel::CModel(OBJTYPE type) : CScene3D(type)
{
}

//=============================================================================
// デストラクタ
//=============================================================================
CModel::~CModel()
{
}

//=============================================================================
// モデルの生成
//=============================================================================
CModel * CModel::Create(D3DXVECTOR3 pos, D3DXVECTOR3 rot, MODELTYPE type)
{
	CModel *pModel;
	pModel = new CModel(OBJTYPE_BG);
	pModel->BindModel(nNumMat, pMesh, pBuffMat);
	pModel->Init(pos, rot, type);

	return pModel;
}

//=============================================================================
// 初期化処理
//=============================================================================
HRESULT CModel::Init(D3DXVECTOR3 pos, D3DXVECTOR3 rot, MODELTYPE type)
{
	CScene3D::Init();
	CScene3D::ModelInit();

	CScene3D::SetPos(pos);

	return S_OK;
}

//=============================================================================
// 終了処理
//=============================================================================
void CModel::Uninit(void)
{
	CScene3D::Uninit();
}

//=============================================================================
// 更新処理
//=============================================================================
void CModel::Update(void)
{
	CScene3D::Update();

	D3DXVECTOR3 pos = CScene3D::GetPos();


	D3DXVECTOR3 posOld;
	// 前回の位置を保存
	posOld = pos;

	if (CollisionModel(&pos, &posOld, D3DXVECTOR3(15.0f, 50.0f, 15.0f)) == true)// フィールド
	{

	}

	CScene3D::SetPos(pos);
}

//=============================================================================
// 描画処理
//=============================================================================
void CModel::Draw(void)
{
	CScene3D::DrawModel();
}

//========================================================================================================
// モデルの読み込み処理
//========================================================================================================
HRESULT CModel::Load(void)
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
void CModel::Unload(void)
{

}

//=============================================================================
// モデルとの当たり判定
//=============================================================================
bool CModel::CollisionModel(D3DXVECTOR3 *pPos, D3DXVECTOR3 *pPosOld, D3DXVECTOR3 size)
{

	bool bRand = false;// 着地判定

	D3DXVECTOR3 pos = D3DXVECTOR3(0.0f,0.0f,0.0f);
	D3DXVECTOR3 vtxMin = D3DXVECTOR3(0.0f,0.0f,0.0f);				//最小値
	D3DXVECTOR3 vtxMax = D3DXVECTOR3(0.0f,0.0f,0.0f);				//最大値 


	pos = GetPos();
	vtxMin = GetvtxMin();				//最小値
	vtxMax = GetvtxMax();				//最大値 

			if (pPos->y <= pos.y + vtxMax.y&&
				pPosOld->y >= pos.y + vtxMax.y)
			{// 乗っているか
				if (pPos->x + size.x > pos.x + vtxMin.x&&
					pPos->x - size.x < pos.x + vtxMax.x)
				{// X,Z座標が範囲内の場合
					pPos->y = pos.y + vtxMax.y;
					bRand = true;
				}
			}

	return bRand;
}