//====================================================================================================
//
// 3Dポリゴン処理 (Scene3D.cpp)
// Author KOUTA KIMURA
//
//====================================================================================================
#include "polygonbase.h"
#include "renderer.h"
#include "manager.h"
#include "Game.h"

//====================================================================================================
// プロトタイプ宣言
//====================================================================================================
#define POLTGON0_TEX "DATA/TEX/pipo-battlebg013.jpg"				//読み込むテクスチャファイル名

//====================================================================================================
// メンバ変数初期化
//====================================================================================================

//====================================================================================================
// コンストラクタ
//====================================================================================================
CPolygonBase::CPolygonBase(OBJTYPE nPriority) : CScene(nPriority)
{

}

//=============================================================================
// 初期化処理
//=============================================================================
HRESULT CPolygonBase::Init(void)
{
	CRenderer *pRenderer = CManager::GetRenderer();
	LPDIRECT3DDEVICE9 pDevice = pRenderer->GetDevice();

	VERTEX_3D *pVtx;

	D3DXCreateTextureFromFile(
		pDevice,
		POLTGON0_TEX,
		&m_pTexturePolygon);

	// オブジェクトの頂点バッファを生成
	pDevice->CreateVertexBuffer(sizeof(VERTEX_3D) * 4,
		D3DUSAGE_WRITEONLY,
		FVF_VERTEX_3D,
		D3DPOOL_MANAGED,
		&m_pVtxBuffScene,
		NULL);

	// 頂点データの範囲をロックし、頂点バッファへのポインタを取得
	m_pVtxBuffScene->Lock(0, 0, (void**)&pVtx, 0);

	pVtx[0].pos = m_pos + D3DXVECTOR3(-1000.0f, 800.0f, 680.0f);
	pVtx[1].pos = m_pos + D3DXVECTOR3(1000.0f, 800.0f, 680.0f);
	pVtx[2].pos = m_pos + D3DXVECTOR3(-1000.0f, -800.0f, 680.0f);
	pVtx[3].pos = m_pos + D3DXVECTOR3(1000.0f, -800.0f, 680.0f);

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

//==================================================================================================
// 終了処理
//===================================================================================================
void CPolygonBase::Uninit(void)
{

}

//====================================================================================================
//更新処理
//=====================================================================================================
void CPolygonBase::Update(void)
{

}

//========================================================================================================
// 描画処理
//========================================================================================================
void CPolygonBase::Draw(void)
{
	CRenderer *pRenderer = CManager::GetRenderer();
	LPDIRECT3DDEVICE9 pDevice = pRenderer->GetDevice();

	D3DXMATRIX mtxRot, mtxTrans;				//計算用マトリックス

	// ワールドマトリックスの初期化
	D3DXMatrixIdentity(&m_mtxWorldPolygon);

	// 回転を反映
	D3DXMatrixRotationYawPitchRoll(&mtxRot, m_rotPolygon.y, m_rotPolygon.x, m_rotPolygon.z);
	D3DXMatrixMultiply(&m_mtxWorldPolygon, &m_mtxWorldPolygon, &mtxRot);

	// 位置を反映
	D3DXMatrixTranslation(&mtxTrans, m_PosPolygon.x, m_PosPolygon.y, m_PosPolygon.z);
	D3DXMatrixMultiply(&m_mtxWorldPolygon, &m_mtxWorldPolygon, &mtxTrans);

	// ワールドマトリックスの設定
	pDevice->SetTransform(D3DTS_WORLD, &m_mtxWorldPolygon);

	// 頂点バッファをデータストリームに設定
	pDevice->SetStreamSource(0, m_pVtxBuffScene, 0, sizeof(VERTEX_3D));

	//頂点フォーマットの設定
	pDevice->SetFVF(FVF_VERTEX_3D);

	// テクスチャの設定
	pDevice->SetTexture(0, m_pTexturePolygon);

	// ポリゴンの描画
	pDevice->DrawPrimitive(D3DPT_TRIANGLESTRIP, 0, 4);//D3DPT_TRIANGLESTRIPは反時計回りにする
}

//====================================================================================================
// デストラクタ
//====================================================================================================
CPolygonBase::~CPolygonBase()
{

}
