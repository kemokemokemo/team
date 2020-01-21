//=============================================================================
//
// モデル処理 [hitmodel.cpp]
// Author : KOUAT KIMURA
//
//=============================================================================

//=============================================================================
// インクルードファイル
//=============================================================================
#include "hitmodelBase.h"
#include "camera.h"
#include "manager.h"
#include "renderer.h"

//=============================================================================
// メンバ変数初期化
//=============================================================================
#define MAX_HITMODEL		(1)									// モデルの数
#define POLTGON0_TEX "DATA/TEX/sougen.jpg"				//読み込むテクスチャファイル名

//=============================================================================
// コンストラクタ
//=============================================================================
CHitModelBase::CHitModelBase(OBJTYPE type) : CScene(type)
{
}

//=============================================================================
// デストラクタ
//=============================================================================
CHitModelBase::~CHitModelBase()
{
}

//=============================================================================
// 初期化処理
//=============================================================================
HRESULT CHitModelBase::Init()
{
	//CRenderer *pRenderer = CManager::GetRenderer();
	//LPDIRECT3DDEVICE9 pDevice = pRenderer->GetDevice();

	//D3DXCreateTextureFromFile(
	//	pDevice,
	//	POLTGON0_TEX,
	//	&m_pTextureModel);

	return S_OK;
}

//=============================================================================
// 終了処理
//=============================================================================
void CHitModelBase::Uninit(void)
{
	Release();
}

//=============================================================================
// 更新処理
//=============================================================================
void CHitModelBase::Update(void)
{

}

//=============================================================================
// 描画処理
//=============================================================================
void CHitModelBase::Draw(void)
{
	CRenderer *pRenderer = CManager::GetRenderer();
	LPDIRECT3DDEVICE9 pDevice = pRenderer->GetDevice();

	D3DXMATRIX mtxScale,mtxRot,mtxTrans;			// 計算用マトリックス
	D3DXMATERIAL *pMat;								// 現在のマテリアル保存用
	D3DMATERIAL9 matDef;							// マテリアルデータへのポインタ

	// ワールドマトリックスの初期化
	D3DXMatrixIdentity(&m_mtxWorld);

	// 拡大率を反映
	D3DXMatrixScaling(&mtxScale, m_scale.x, m_scale.y, m_scale.z);
	D3DXMatrixMultiply(&m_mtxWorld, &m_mtxWorld, &mtxScale);

	// 回転を反映
	D3DXMatrixRotationYawPitchRoll(&mtxRot, m_rot.y, m_rot.x, m_rot.z);
	D3DXMatrixMultiply(&m_mtxWorld, &m_mtxWorld, &mtxRot);

	// 位置を反映
	D3DXMatrixTranslation(&mtxTrans, m_pos.x, m_pos.y, m_pos.z);
	D3DXMatrixMultiply(&m_mtxWorld, &m_mtxWorld, &mtxTrans);

	//m_mtxWorld = mtxTrans * mtxScale *mtxRot;

	// ワールドマトリックスの設定
	pDevice->SetTransform(D3DTS_WORLD, &m_mtxWorld);

	// 現在のマテリアルを取得
	pDevice->GetMaterial(&matDef);

	// マテリアル情報に対するポインタを取得
	pMat = (D3DXMATERIAL*)pBuffMat->GetBufferPointer();

	for (int nCntMat = 0; nCntMat < (int)nNumMat; nCntMat++)
	{
		// マテリアルの設定
		pDevice->SetMaterial(&pMat[nCntMat].MatD3D);

		// テクスチャの設定
		pDevice->SetTexture(0, m_pTextureModel);

		// 描画
		pMesh->DrawSubset(nCntMat);
	}
	// マテリアルをデフォルトに戻す
	pDevice->SetMaterial(&matDef);
}

//====================================================================================================
// ポジションの取得
//====================================================================================================
D3DXVECTOR3 CHitModelBase::GetPos()
{
	return m_pos;
}

//====================================================================================================
// サイズの取得
//====================================================================================================
D3DXVECTOR3 CHitModelBase::GetSize()
{
	return m_scale;
}

void CHitModelBase::SetPos(D3DXVECTOR3 pos)
{
	m_pos = pos;
}

void CHitModelBase::Setsize(D3DXVECTOR3 scale)
{
	m_scale = scale;
}

void CHitModelBase::BindHitModel(DWORD NumMat, LPD3DXMESH Mesh, LPD3DXBUFFER BuffMat)
{
	nNumMat = NumMat;
	pMesh = Mesh;
	pBuffMat = BuffMat;
}
