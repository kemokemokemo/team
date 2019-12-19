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
	CRenderer *pRenderer = CManager::GetRenderer();
	LPDIRECT3DDEVICE9 pDevice = pRenderer->GetDevice();

	VERTEX_3D *pVtx;

	// オブジェクトの頂点バッファを生成
	pDevice->CreateVertexBuffer(sizeof(VERTEX_3D) * 4,
		D3DUSAGE_WRITEONLY,
		FVF_VERTEX_3D,
		D3DPOOL_MANAGED,
		&m_pVtxBuffScene,
		NULL);

	// 頂点データの範囲をロックし、頂点バッファへのポインタを取得
	m_pVtxBuffScene->Lock(0, 0, (void**)&pVtx, 0);

	pVtx[0].pos = m_pos + D3DXVECTOR3(-m_scale.x, m_scale.y, m_scale.z);
	pVtx[1].pos = m_pos + D3DXVECTOR3(m_scale.x, m_scale.y, m_scale.z);
	pVtx[2].pos = m_pos + D3DXVECTOR3(-m_scale.x, m_scale.y, -m_scale.z);
	pVtx[3].pos = m_pos + D3DXVECTOR3(m_scale.x, m_scale.y, -m_scale.z);

	pVtx[0].nor = D3DXVECTOR3(0.0f, 1.0f, 0.0f);
	pVtx[1].nor = D3DXVECTOR3(0.0f, 1.0f, 0.0f);
	pVtx[2].nor = D3DXVECTOR3(0.0f, 1.0f, 0.0f);
	pVtx[3].nor = D3DXVECTOR3(0.0f, 1.0f, 0.0f);

	pVtx[0].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
	pVtx[1].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
	pVtx[2].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
	pVtx[3].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);

	pVtx[0].tex = D3DXVECTOR2(0.0f, 0.0f);
	pVtx[1].tex = D3DXVECTOR2(1.0f, 0.0f);
	pVtx[2].tex = D3DXVECTOR2(0.0f, 1.0f);
	pVtx[3].tex = D3DXVECTOR2(1.0f, 1.0f);

	// 頂点データをアンロックする
	m_pVtxBuffScene->Unlock();

	return S_OK;

}

//=============================================================================
// 終了処理
//=============================================================================
void CHitModelBase::Uninit(void)
{

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

		// テクスチャの反映
		pDevice->SetTexture(0, 0);

		// 描画
		pMesh->DrawSubset(nCntMat);
	}
	// マテリアルをデフォルトに戻す
	pDevice->SetMaterial(&matDef);
}

//====================================================================================================
// モデルの初期化
//====================================================================================================
void CHitModelBase::ModelInit(void)
{
	CRenderer *pRenderer = CManager::GetRenderer();
	LPDIRECT3DDEVICE9 pDevice = pRenderer->GetDevice();
}

D3DXVECTOR3 CHitModelBase::GetPos()
{
	return m_pos;
}

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
