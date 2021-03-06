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
CScene3D::MODELNUM CModel::m_Unit[UNITTYPE_MAX] = {};
#define Distance	(5)					//プレイヤーの吹っ飛び

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
CModel * CModel::Create(D3DXVECTOR3 pos, D3DXVECTOR3 rot, UNITTYPE type)
{
	CModel *pModel;
	pModel = new CModel(OBJTYPE_BG);
	pModel->BindModel(&m_Unit[type]);
	pModel->Init(pos, rot, type);

	return pModel;
}

//=============================================================================
// 初期化処理
//=============================================================================
HRESULT CModel::Init(D3DXVECTOR3 pos, D3DXVECTOR3 rot, UNITTYPE type)
{
	CScene3D::Init();

	for (int nCountBlock = 0; nCountBlock < UNITTYPE_MAX; nCountBlock++)
	{
		m_Unit->NumModel[nCountBlock].pos = pos;
		m_Unit->NumModel[m_Unit->NumModel[nCountBlock].nType].vtxMin = CScene3D::GetvtxMin();
		m_Unit->NumModel[m_Unit->NumModel[nCountBlock].nType].vtxMax = CScene3D::GetvtxMax();
	}

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

	//m_pos = CScene3D::GetPos();

	CScene3D::SetPos(m_pos);
}

//=============================================================================
// 描画処理
//=============================================================================
void CModel::Draw(void)
{
	CScene3D::Draw();
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
		&m_Unit->NumModel->pBuffMat, NULL,
		&m_Unit->NumModel->nNumMat,
		&m_Unit->NumModel->pMesh);

	m_Unit->NumModel->nType = 0;
	m_Unit->NumModel->nIdxModel = -1;
	m_Unit->nMaxModel = 1;

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
bool CModel::CollisionModel(D3DXVECTOR3 * pPos, D3DXVECTOR3 * pPosOld, D3DXVECTOR3 size)
{

	bool bRand = false;// 着地判定

	// 当たり判定
	for (int nCountBlock = 0; nCountBlock < MAX_MODEL; nCountBlock++)
	{
		if (pPos->y <= m_Unit->NumModel[m_Unit->NumModel[nCountBlock].nType].pos.y + Distance + m_Unit->NumModel[m_Unit->NumModel[nCountBlock].nType].vtxMax.y&&
			pPosOld->y >= m_Unit->NumModel[m_Unit->NumModel[nCountBlock].nType].pos.y + Distance + m_Unit->NumModel[m_Unit->NumModel[nCountBlock].nType].vtxMax.y)
		{// 乗っているか
			if (pPos->x + size.x > m_Unit->NumModel[m_Unit->NumModel[nCountBlock].nType].pos.x + m_Unit->NumModel[m_Unit->NumModel[nCountBlock].nType].vtxMin.x&&
				pPos->x - size.x < m_Unit->NumModel[m_Unit->NumModel[nCountBlock].nType].pos.x + m_Unit->NumModel[m_Unit->NumModel[nCountBlock].nType].vtxMax.x&&
				pPos->z + size.z > m_Unit->NumModel[m_Unit->NumModel[nCountBlock].nType].pos.z + m_Unit->NumModel[m_Unit->NumModel[nCountBlock].nType].vtxMin.z&&
				pPos->z - size.z < m_Unit->NumModel[m_Unit->NumModel[nCountBlock].nType].pos.z + m_Unit->NumModel[m_Unit->NumModel[nCountBlock].nType].vtxMax.z)
			{// X,Z座標が範囲内の場合
				pPos->y = m_Unit->NumModel[m_Unit->NumModel[nCountBlock].nType].pos.y + Distance + m_Unit->NumModel[m_Unit->NumModel[nCountBlock].nType].vtxMax.y;
				bRand = true;
			}
		}
	}
		return bRand;
}
