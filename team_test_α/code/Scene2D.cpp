//====================================================================================================
//
// レンダリング (Scene2D.cpp)
// Author (Kimura kouta)
//
//====================================================================================================
#include "Scene2D.h"
#include "renderer.h"
#include "manager.h"
#include "keybord.h"
#include "Game.h"

//====================================================================================================
// プロトタイプ宣言
//====================================================================================================
#define Bm_POS_X	(0)			    //ポリゴンの表示位置(左上X)
#define Bm_POS_Y	(0)			    //ポリゴンの表示位置(左上Y)
#define Bm_SIZE_X	(1280)			//ポリゴンのサイズ(横幅)
#define Bm_SIZE_Y	(720)			//ポリゴンのサイズ(立幅)

//====================================================================================================
// グローバル変数
//====================================================================================================

//====================================================================================================
// コンストラクタ
//====================================================================================================
 CScene2D::CScene2D(OBJTYPE nPriority) : CScene(nPriority)
 {
}

 //====================================================================================================
 // コンストラクタ
 //====================================================================================================
 CScene2D::CScene2D()
 {
	 int m_nCounterAnim = 0;
	 int m_nPatternAnim = 0;
 }

//=============================================================================
// 初期化処理
//=============================================================================
HRESULT CScene2D::Init(void)
{
	CRenderer *pRenderer = CManager::GetRenderer();
	LPDIRECT3DDEVICE9 pDevice = pRenderer->GetDevice();

	//初期化
	D3DXVECTOR3 m_pos = D3DXVECTOR3(0.0f,0.0f,0.0f);		//ポジション
	D3DXCOLOR m_Col = D3DXCOLOR(1.0f,1.0f,1.0f,1.0f);		//色

	m_nCounterAnim = 0;
	m_nPatternAnim = 0;
	m_fHeight = 0.0f;
	m_fWidht = 0.0f;
	m_fWidht2 = 0.0f;

	 VERTEX_2D *pVtx;

	// オブジェクトの頂点バッファを生成
	pDevice->CreateVertexBuffer(sizeof(VERTEX_2D) * 4,
		D3DUSAGE_WRITEONLY,
		FVF_VERTEX_2D,
		D3DPOOL_MANAGED,
		&m_pVtxBuffScene,
		NULL);

	//初期化
	float Pos = 2.0f;

	// 頂点データの範囲をロックし、頂点バッファへのポインタを取得
	m_pVtxBuffScene->Lock(0, 0, (void**)&pVtx, 0);

	pVtx[0].pos = m_pos + D3DXVECTOR3(-Pos, -Pos, 0.0f);
	pVtx[1].pos = m_pos + D3DXVECTOR3(Pos, -Pos, 0.0f);
	pVtx[2].pos = m_pos + D3DXVECTOR3(-Pos, Pos, 0.0f);
	pVtx[3].pos = m_pos + D3DXVECTOR3(Pos, Pos, 0.0f);

	pVtx[0].rhw = 1.0f;
	pVtx[1].rhw = 1.0f;
	pVtx[2].rhw = 1.0f;
	pVtx[3].rhw = 1.0f;

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
void CScene2D::Uninit(void)
{
	// 頂点バッファの開放
	if (m_pVtxBuffScene != NULL)
	{
		m_pVtxBuffScene->Release();
		m_pVtxBuffScene = NULL;
	}
	// 頂点バッファの開放
	if (m_pTexturePolygon != NULL)
	{
		m_pTexturePolygon->Release();
		m_pTexturePolygon = NULL;
	}
}

//====================================================================================================
//更新処理
//=====================================================================================================
void CScene2D::Update(void)
{
	VERTEX_2D *pVtx;

	// 頂点データの範囲をロックし、頂点バッファへのポインタを取得
	m_pVtxBuffScene->Lock(0, 0, (void**)&pVtx, 0);

	pVtx[0].pos = m_pos + D3DXVECTOR3(-0.0f, -0.0f, 0.0f);
	pVtx[1].pos = m_pos + D3DXVECTOR3(m_PosSize_X, -0.0f, 0.0f);
	pVtx[2].pos = m_pos + D3DXVECTOR3(-0.0f, m_PosSize_Y, 0.0f);
	pVtx[3].pos = m_pos + D3DXVECTOR3(m_PosSize_X, m_PosSize_Y, 0.0f);

	pVtx[0].col = m_Col;
	pVtx[1].col = m_Col;
	pVtx[2].col = m_Col;
	pVtx[3].col = m_Col;

	// 頂点データをアンロックする
	m_pVtxBuffScene->Unlock();
}

//========================================================================================================
// 描画処理
//========================================================================================================
void CScene2D::Draw(void)
{
	CRenderer *pRenderer = CManager::GetRenderer();
	LPDIRECT3DDEVICE9 pDevice = pRenderer->GetDevice();

	// 頂点バッファをデバイスのデータストリームにバインド
	pDevice->SetStreamSource(0, m_pVtxBuffScene, 0, sizeof(VERTEX_2D));

	pDevice->SetTexture(0, m_pTexturePolygon);

	pDevice->SetFVF(FVF_VERTEX_2D);

	pDevice->DrawPrimitive(D3DPT_TRIANGLESTRIP,0,2);

}

//========================================================================================================
// アニメーション
//========================================================================================================
void CScene2D::SetAnim(float fHeight, float fWidht, float fWidht2, int fChange)
{
	VERTEX_2D *pVtx;

	m_fHeight = fHeight;
	m_fWidht = fWidht;
	m_fWidht2 = fWidht2;

	m_nCounterAnim++;
	
	if (m_nCounterAnim % fChange == 0)
	{
		// パターンの初期化
		m_nPatternAnim = (m_nPatternAnim + 1) % 8;
	}

	// 頂点情報の設定
	m_pVtxBuffScene->Lock(0, 0, (void**)&pVtx, 0);

	// 頂点の設定
	pVtx[0].tex = D3DXVECTOR2(0.0f + m_nPatternAnim * m_fHeight, m_fWidht);
	pVtx[1].tex = D3DXVECTOR2(m_fHeight + m_nPatternAnim * m_fHeight, m_fWidht);
	pVtx[2].tex = D3DXVECTOR2(0.0f + m_nPatternAnim * m_fHeight, m_fWidht2);
	pVtx[3].tex = D3DXVECTOR2(m_fHeight + m_nPatternAnim * m_fHeight, m_fWidht2);

	// 頂点データをアンロックする
	m_pVtxBuffScene->Unlock();
}

//========================================================================================================
// ポジションの取得
//========================================================================================================
D3DXVECTOR3 CScene2D::GetPos(void)
{
	return m_pos;
}

//========================================================================================================
// ポジションのセット
//========================================================================================================
void CScene2D::SetPos(D3DXVECTOR3 pos)
{
	m_pos = pos;
}

//========================================================================================================
// ポジションのセット
//========================================================================================================
void CScene2D::UIUpdate(int nLife, int size)
{
	VERTEX_2D *pVtx;

	// 頂点データの範囲をロックし、頂点バッファへのポインタを取得
	m_pVtxBuffScene->Lock(0, 0, (void**)&pVtx, 0);

		pVtx[0].pos = D3DXVECTOR3(m_pos.x, m_pos.y, 0.0f);
		pVtx[1].pos = D3DXVECTOR3(m_pos.x + (nLife * size), m_pos.y, 0.0f);
		pVtx[2].pos = D3DXVECTOR3(m_pos.x , m_pos.y + size, 0.0f);
		pVtx[3].pos = D3DXVECTOR3(m_pos.x + (nLife * size), m_pos.y + size, 0.0f);

		pVtx[0].col = m_Col;
		pVtx[1].col = m_Col;
		pVtx[2].col = m_Col;
		pVtx[3].col = m_Col;

	// 頂点データをアンロックする
	m_pVtxBuffScene->Unlock();
}

//========================================================================================================
// ポジションのセット
//========================================================================================================
void CScene2D::SetSize(float Size_x, float Size_y)
{
	m_PosSize_X = Size_x;
	m_PosSize_Y = Size_y;
}

//========================================================================================================
// カラーのセット
//========================================================================================================
void CScene2D::SetColor(D3DXCOLOR Color)
{
	m_Col = Color;
}


//========================================================================================================
// テクスチャのセット
//========================================================================================================
void CScene2D::BindTexture(LPDIRECT3DTEXTURE9 cName)
{
	m_pTexturePolygon = cName;
}

//====================================================================================================
// デストラクタ
//=====================================================================================================
CScene2D::~CScene2D()
{

}