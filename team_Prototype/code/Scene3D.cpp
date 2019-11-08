//====================================================================================================
//
// 3Dポリゴン処理 (Scene3D.cpp)
// Author (Kimura kouta)
//
//====================================================================================================
#include "Scene3D.h"
#include "renderer.h"
#include "manager.h"
#include "keybord.h"
#include "Game.h"
#include "model.h"

//====================================================================================================
// プロトタイプ宣言
//====================================================================================================
#define Bm_POS_X	(0)			    //ポリゴンの表示位置(左上X)
#define Bm_POS_Y	(0)			    //ポリゴンの表示位置(左上Y)
#define Bm_SIZE_X	(1280)			//ポリゴンのサイズ(横幅)
#define Bm_SIZE_Y	(720)			//ポリゴンのサイズ(立幅)
#define POLTGON0_TEX "DATA/TEX/IMG_2227.JPG"				//読み込むテクスチャファイル名


//====================================================================================================
// メンバ変数初期化
//====================================================================================================

//====================================================================================================
// コンストラクタ
//====================================================================================================
CScene3D::CScene3D(OBJTYPE nPriority) : CScene(nPriority)
{

}

//=============================================================================
// 初期化処理
//=============================================================================
HRESULT CScene3D::Init(void)
{
	CRenderer *pRenderer = CManager::GetRenderer();
	LPDIRECT3DDEVICE9 pDevice = pRenderer->GetDevice();

	// 初期設定
	for (int nCntModel = 0; nCntModel < MAX_MODEL; nCntModel++)
	{
		m_pos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
		m_rot = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	}

	// モデルの頂点数の最大値・最小値の設定
	int		nNumVertices;							// 頂点数
	DWORD	sizeFVF;								// 頂点フォーマットのサイズ
	BYTE	*pVertexBuffer;

	for (int nCntModel = 0; nCntModel < MAX_MODEL; nCntModel++)
	{
		m_vtxMax = D3DXVECTOR3(-1000.0f, -1000.0f, -1000.0f);
		m_vtxMin = D3DXVECTOR3(1000.0f, 1000.0f, 1000.0f);

		// 頂点数を取得
		nNumVertices = m_Model[nCntModel].pMesh->GetNumVertices();

		// 頂点フォーマットのサイズを取得
		sizeFVF = D3DXGetFVFVertexSize(m_Model[nCntModel].pMesh->GetFVF());

		// 頂点バッファをロック
		m_Model[nCntModel].pMesh->LockVertexBuffer(D3DLOCK_READONLY, (void**)&pVertexBuffer);

		for (int nCntVtx = 0; nCntVtx < nNumVertices; nCntVtx++)
		{
			D3DXVECTOR3 vtx = *(D3DXVECTOR3*)pVertexBuffer;

			// 全ての頂点情報を比較して最大値・最小値を抜き出す
			D3DXVec3Minimize(&m_vtxMin, &vtx, &m_vtxMin);
			D3DXVec3Maximize(&m_vtxMax, &vtx, &m_vtxMax);

			pVertexBuffer += sizeFVF;//	サイズ分ポインタを進める
		}
		// アンロック
		m_Model[nCntModel].pMesh->UnlockVertexBuffer();
	}

	return S_OK;
}

//==================================================================================================
// 終了処理
//===================================================================================================
void CScene3D::Uninit(void)
{

}

//====================================================================================================
//更新処理
//=====================================================================================================
void CScene3D::Update(void)
{

}

//========================================================================================================
// 描画処理
//========================================================================================================
void CScene3D::Draw(void)
{
	LPDIRECT3DDEVICE9 pDevice = CManager::GetRenderer()->GetDevice();

	D3DXMATRIX mtxRot, mtxTrans;				// 計算用マトリックス
	D3DXMATERIAL *pMat;							// 現在のマテリアル保存用
	D3DMATERIAL9 matDef;						// マテリアルデータへのポインタ
	D3DXMATRIX	mtxModel;						// 親のマトリックス

	// ワールドマトリックスの初期化
	D3DXMatrixIdentity(&m_mtxWorld);

	// 回転を反映
	D3DXMatrixRotationYawPitchRoll(&mtxRot, m_rot.y, m_rot.x, m_rot.z);
	D3DXMatrixMultiply(&m_mtxWorld, &m_mtxWorld, &mtxRot);

	// 位置を反映
	D3DXMatrixTranslation(&mtxTrans, m_pos.x, m_pos.y, m_pos.z);
	D3DXMatrixMultiply(&m_mtxWorld, &m_mtxWorld, &mtxTrans);

	// ワールドマトリックスの設定
	pDevice->SetTransform(D3DTS_WORLD, &m_mtxWorld);

	for (int nCntModel = 0; nCntModel < MAX_MODEL; nCntModel++)
	{
		if (m_Model[nCntModel].nIdxModelModel == -1)
		{
			mtxModel = m_mtxWorld;
		}
		else
		{
			mtxModel = m_Model[m_Model[nCntModel].nIdxModelModel].mtxWorld;
		}

		// ワールドマトリックスの初期化
		D3DXMatrixIdentity(&m_mtxWorld);

		// 回転を反映
		D3DXMatrixRotationYawPitchRoll(&mtxRot, m_Model[nCntModel].rot.y, m_Model[nCntModel].rot.x, m_Model[nCntModel].rot.z);
		D3DXMatrixMultiply(&m_mtxWorld, &m_mtxWorld, &mtxRot);

		// 位置を反映
		D3DXMatrixTranslation(&mtxTrans, m_Model[nCntModel].pos.x, m_Model[nCntModel].pos.y, m_Model[nCntModel].pos.z);
		D3DXMatrixMultiply(&m_mtxWorld, &m_mtxWorld, &mtxTrans);

		// 親モデルのマトリックスをかけ合わせる
		D3DXMatrixMultiply(&m_Model[nCntModel].mtxWorld, &m_Model[nCntModel].mtxWorld, &mtxModel);

		// ワールドマトリックスの設定
		pDevice->SetTransform(D3DTS_WORLD, &m_Model[nCntModel].mtxWorld);

		// 現在のマテリアルを取得
		pDevice->GetMaterial(&matDef);

		// マテリアル情報に対するポインタを取得
		pMat = (D3DXMATERIAL*)m_Model[nCntModel].pBuffMat->GetBufferPointer();

		for (int nCntMat = 0; nCntMat < (int)m_Model[nCntModel].nNumMat; nCntMat++)
		{
			// マテリアルの設定
			pDevice->SetMaterial(&pMat[nCntMat].MatD3D);

			// 描画
			m_Model[nCntModel].pMesh->DrawSubset(nCntMat);
		}

		// マテリアルをデフォルトに戻す
		pDevice->SetMaterial(&matDef);
	}
}

//=============================================================================
// 当たり判定(球とカプセル)
//=============================================================================
bool CScene3D::ShapeCapsuleCollision(D3DXVECTOR3 *pPosStart, D3DXVECTOR3 *pPosEnd, float Radius, D3DXVECTOR3 *pPos)
{
	//カプセルのベクトル
	D3DXVECTOR3 CoreWire = *pPosEnd - *pPosStart;

	float fRadius = 5.0f * 0.5f + Radius;

	//距離のベクトル
	D3DXVECTOR3 Vec = *pPos - *pPosStart;

	if (D3DXVec3Dot(&CoreWire, &Vec) < 0)
	{
		if (D3DXVec3Dot(&Vec, &Vec) > fRadius * fRadius)
		{// startの方の半円
			return false;
		}
	}

	//距離のベクトル
	Vec = *pPosEnd - *pPos;

	if (D3DXVec3Dot(&CoreWire, &Vec) < 0)
	{
		if (D3DXVec3Dot(&Vec, &Vec) > fRadius * fRadius)
		{// endの方の半円
			return false;
		}
	}

	D3DXVec3Cross(&Vec, &CoreWire, &Vec);

	if (D3DXVec3Dot(&Vec, &Vec) / D3DXVec3Dot(&CoreWire, &CoreWire) > fRadius * fRadius)
	{// 真ん中の円柱
		return false;
	}
	return true;
}

//=======
/*
//=============================================================================
// 当たり判定(球とカプセル)
//=============================================================================
bool CollisionBullet(D3DXVECTOR3 *pPosStart, D3DXVECTOR3 *pPosEnd, float Radius, D3DXVECTOR3 *pBulletPos)
{
//カプセルのベクトル
D3DXVECTOR3 CoreWire = *pPosEnd - *pPosStart;

float fRadius = BULLET_SIZE * 0.5f + Radius;

//距離のベクトル
D3DXVECTOR3 Vec = *pBulletPos - *pPosStart;

if (D3DXVec3Dot(&CoreWire, &Vec) < 0)
{
if (D3DXVec3Dot(&Vec, &Vec) > fRadius * fRadius)
{// startの方の半円
return false;
}
}

//距離のベクトル
Vec = *pPosEnd - *pBulletPos;

if (D3DXVec3Dot(&CoreWire, &Vec) < 0)
{
if (D3DXVec3Dot(&Vec, &Vec) > fRadius * fRadius)
{// endの方の半円
return false;
}
}

D3DXVec3Cross(&Vec, &CoreWire, &Vec);

if (D3DXVec3Dot(&Vec, &Vec) / D3DXVec3Dot(&CoreWire, &CoreWire) > fRadius * fRadius)
{// 真ん中の円柱
return false;
}

return true;
}
*/
//>>>>>>> 9b731fce417e264f98bacdf04841822bd737d7b0:team/script/Scene3D.cpp

//====================================================================================================
// モデルの取得
//====================================================================================================
void CScene3D::BindModel(const MODELNUM *type)
{
	for (int nCnt = 0; nCnt < type->m_nMaxModel; nCnt++, type++)
	{
		m_Model[nCnt].nNumMat = type->NumModel->nNumMat;
		m_Model[nCnt].pMesh = type->NumModel->pMesh;
		m_Model[nCnt].pBuffMat = type->NumModel->pBuffMat;
	}
}

//====================================================================================================
// ポジションの取得
//====================================================================================================
D3DXVECTOR3 CScene3D::GetPos(void)
{
	return m_pos;
}

//====================================================================================================
// ポジションのセット
//====================================================================================================
void CScene3D::SetPos(D3DXVECTOR3 pos)
{
	m_pos = pos;
}

//====================================================================================================
// 回転量の取得
//====================================================================================================
D3DXVECTOR3 CScene3D::GetRot(void)
{
	return m_rot;
}

//====================================================================================================
// 回転量のセット
//====================================================================================================
void CScene3D::SetRot(D3DXVECTOR3 rot)
{
	m_rot = rot;
}

//====================================================================================================
// デストラクタ
//====================================================================================================
CScene3D::~CScene3D()
{

}
