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

	m_pos = pos;

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

	//// Xファイルの読み込み
	//D3DXLoadMeshFromX(MODELFILE0, D3DXMESH_SYSTEMMEM, pDevice, NULL,
	//	&pBuffMat, NULL,
	//	&nNumMat,
	//	&pMesh);

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
//bool CollisionModel(D3DXVECTOR3 *pPos, D3DXVECTOR3 *pPosOld, D3DXVECTOR3 size)
//{
//	bool bRand = false;// 着地判定
//
//	// 当たり判定
//	for (int nCountBlock = 0; nCountBlock < MAX_MODEL; nCountBlock++)
//	{
//		if (m_aModel[nCountBlock].bUse)// ブロックが使用されている場合
//		{
//			if (pPos->y <= m_aModel[nCountBlock].pos.y + m_aModelModel[m_aModel[nCountBlock].type].vtxMax.y&&
//				pPosOld->y >= m_aModel[nCountBlock].pos.y + m_aModelModel[m_aModel[nCountBlock].type].vtxMax.y)
//			{// 乗っているか
//				if (pPos->x + size.x > m_aModel[nCountBlock].pos.x + m_aModelModel[m_aModel[nCountBlock].type].vtxMin.x&&
//					pPos->x - size.x < m_aModel[nCountBlock].pos.x + m_aModelModel[m_aModel[nCountBlock].type].vtxMax.x&&
//					pPos->z + size.z > m_aModel[nCountBlock].pos.z + m_aModelModel[m_aModel[nCountBlock].type].vtxMin.z&&
//					pPos->z - size.z < m_aModel[nCountBlock].pos.z + m_aModelModel[m_aModel[nCountBlock].type].vtxMax.z)
//				{// X,Z座標が範囲内の場合
//					pPos->y = m_aModel[nCountBlock].pos.y + m_aModelModel[m_aModel[nCountBlock].type].vtxMax.y;
//					bRand = true;
//				}
//			}
//			else if (pPos->y + size.y > m_aModel[nCountBlock].pos.y + m_aModelModel[m_aModel[nCountBlock].type].vtxMin.y &&
//				pPos->y < m_aModel[nCountBlock].pos.y + m_aModelModel[m_aModel[nCountBlock].type].vtxMax.y)
//			{// Y座標が範囲内の場合
//				if (pPos->x + size.x > m_aModel[nCountBlock].pos.x + m_aModelModel[m_aModel[nCountBlock].type].vtxMin.x&&
//					pPos->x - size.x < m_aModel[nCountBlock].pos.x + m_aModelModel[m_aModel[nCountBlock].type].vtxMax.x)
//				{// 上下
//					if (pPos->z - size.z <= m_aModel[nCountBlock].pos.z + m_aModelModel[m_aModel[nCountBlock].type].vtxMax.z&&
//						pPosOld->z - size.z >= m_aModel[nCountBlock].pos.z + m_aModelModel[m_aModel[nCountBlock].type].vtxMax.z)
//					{// プレイヤーがブロックに上からぶつかって
//						pPos->z = size.z + m_aModel[nCountBlock].pos.z + m_aModelModel[m_aModel[nCountBlock].type].vtxMax.z;
//					}
//					else if (pPos->z + size.z >= m_aModel[nCountBlock].pos.z + m_aModelModel[m_aModel[nCountBlock].type].vtxMin.z&&
//						pPosOld->z + size.z <= m_aModel[nCountBlock].pos.z + m_aModelModel[m_aModel[nCountBlock].type].vtxMin.z)
//					{// プレイヤーがブロックに下からぶつかって
//						pPos->z = m_aModel[nCountBlock].pos.z + m_aModelModel[m_aModel[nCountBlock].type].vtxMin.z - size.z;
//					}
//				}
//
//				if (pPos->z + size.z > m_aModel[nCountBlock].pos.z + m_aModelModel[m_aModel[nCountBlock].type].vtxMin.z&&
//					pPos->z - size.z < m_aModel[nCountBlock].pos.z + m_aModelModel[m_aModel[nCountBlock].type].vtxMax.z)
//				{// 左右
//					if (pPos->x - size.x <= m_aModel[nCountBlock].pos.x + m_aModelModel[m_aModel[nCountBlock].type].vtxMax.x&&
//						pPosOld->x - size.x >= m_aModel[nCountBlock].pos.x + m_aModelModel[m_aModel[nCountBlock].type].vtxMax.x)
//					{// プレイヤーがブロックに右からぶつかって
//						pPos->x = size.x + m_aModel[nCountBlock].pos.x + m_aModelModel[m_aModel[nCountBlock].type].vtxMax.x;
//					}
//					else if (pPos->x + size.x >= m_aModel[nCountBlock].pos.x + m_aModelModel[m_aModel[nCountBlock].type].vtxMin.x&&
//						pPosOld->x + size.x <= m_aModel[nCountBlock].pos.x + m_aModelModel[m_aModel[nCountBlock].type].vtxMin.x)
//					{// プレイヤーがブロックに左からぶつかって
//						pPos->x = m_aModel[nCountBlock].pos.x + m_aModelModel[m_aModel[nCountBlock].type].vtxMin.x - size.x;
//					}
//				}
//			}
//		}
//	}
//
//	return bRand;
//}