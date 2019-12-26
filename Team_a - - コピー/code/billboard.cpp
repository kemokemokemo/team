//====================================================================================================
//
// ビルボード処理 (BillBoard.cpp)
// Author KOUTA KIMURA
//
//====================================================================================================
#include "billboard.h"
#include "renderer.h"
#include "manager.h"
#include "Game.h"

//====================================================================================================
// プロトタイプ宣言
//====================================================================================================
#define POLTGON0_TEX "DATA/TEX/sougen.jpg"				//読み込むテクスチャファイル名

//====================================================================================================
// メンバ変数初期化
//====================================================================================================

//====================================================================================================
// コンストラクタ
//====================================================================================================
CBillboard::CBillboard(OBJTYPE nPriority) : CScene3D(nPriority)
{

}

//=============================================================================
// 初期化処理
//=============================================================================
HRESULT CBillboard::Init(void)
{
	CRenderer *pRenderer = CManager::GetRenderer();
	LPDIRECT3DDEVICE9 pDevice = pRenderer->GetDevice();

	VERTEX_3D *pVtx;

	// オブジェクトの頂点バッファを生成
	pDevice->CreateVertexBuffer(sizeof(VERTEX_3D) * 4,
		D3DUSAGE_WRITEONLY,
		FVF_VERTEX_3D,
		D3DPOOL_MANAGED,
		&m_pVtxBuffBillBoard,
		NULL);
	
	int m_nCounterAnim = 0;
	int m_nPatternAnim = 0;


	// 頂点データの範囲をロックし、頂点バッファへのポインタを取得
	m_pVtxBuffBillBoard->Lock(0, 0, (void**)&pVtx, 0);

	pVtx[0].pos = m_pos + D3DXVECTOR3(-800.0f, 800.0f, 150.0f);
	pVtx[1].pos = m_pos + D3DXVECTOR3(800.0f, 800.0f, 150.0f);
	pVtx[2].pos = m_pos + D3DXVECTOR3(-800.0f, -800.0f, 150.0f);
	pVtx[3].pos = m_pos + D3DXVECTOR3(800.0f, -800.0f, 150.0f);

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
	m_pVtxBuffBillBoard->Unlock();

	return S_OK;
}

//==================================================================================================
// 終了処理
//===================================================================================================
void CBillboard::Uninit(void)
{
	CScene3D::Uninit();
}

//====================================================================================================
//更新処理
//=====================================================================================================
void CBillboard::Update(void)
{
	VERTEX_3D *pVtx;

	// 頂点データの範囲をロックし、頂点バッファへのポインタを取得
	m_pVtxBuffBillBoard->Lock(0, 0, (void**)&pVtx, 0);

	pVtx[0].pos = D3DXVECTOR3(-m_size_x, m_size_y, m_size_z);
	pVtx[1].pos = D3DXVECTOR3(m_size_x, m_size_y, m_size_z);
	pVtx[2].pos = D3DXVECTOR3(-m_size_x, -m_size_y, m_size_z);
	pVtx[3].pos = D3DXVECTOR3(m_size_x, -m_size_y, m_size_z);

	pVtx[0].col = m_Color;
	pVtx[1].col = m_Color;
	pVtx[2].col = m_Color;
	pVtx[3].col = m_Color;

	// 頂点データをアンロックする
	m_pVtxBuffBillBoard->Unlock();

	CScene3D::Update();
}

//========================================================================================================
// 描画処理
//========================================================================================================
void CBillboard::Draw(void)
{
	CRenderer *pRenderer = CManager::GetRenderer();
	LPDIRECT3DDEVICE9 pDevice = pRenderer->GetDevice();

	pDevice->SetRenderState(D3DRS_ZENABLE, D3DZB_FALSE);
	pDevice->SetRenderState(D3DRS_ZFUNC, D3DCMP_ALWAYS);

	D3DXMATRIX mtxrot, mtxTrans, mtxView;				//計算用マトリックス

	// ワールドマトリックスの初期化
	D3DXMatrixIdentity(&m_mtxWorldBillBoard);

	// ワールドマトリックスの初期化
	D3DXMatrixIdentity(&mtxView);

	pDevice->GetTransform(D3DTS_VIEW, &mtxView);

	m_mtxWorldBillBoard._11 = mtxView._11;//X軸
	m_mtxWorldBillBoard._12 = mtxView._21;//X軸
	m_mtxWorldBillBoard._13 = mtxView._31;//X軸

	m_mtxWorldBillBoard._21 = mtxView._12;//Y軸
	m_mtxWorldBillBoard._22 = mtxView._22;//Y軸
	m_mtxWorldBillBoard._23 = mtxView._32;//Y軸

	m_mtxWorldBillBoard._31 = mtxView._13;//Z軸
	m_mtxWorldBillBoard._32 = mtxView._23;//Z軸
	m_mtxWorldBillBoard._33 = mtxView._33;//Z軸

	// 回転を反映
	D3DXMatrixRotationYawPitchRoll(&mtxrot,
		m_rot.y,
		m_rot.x,
		m_rot.z);
	D3DXMatrixMultiply(&m_mtxWorldBillBoard,
		&m_mtxWorldBillBoard,
		&mtxrot);

	// 位置を反映
	D3DXMatrixTranslation(&mtxTrans,
		m_pos.x,
		m_pos.y,
		m_pos.z);
	D3DXMatrixMultiply(&m_mtxWorldBillBoard,
		&m_mtxWorldBillBoard,
		&mtxTrans);

	// ワールドマトリックスの設定
	pDevice->SetTransform(D3DTS_WORLD, &m_mtxWorldBillBoard);

	// 頂点バッファをデータストリームにバインド
	pDevice->SetStreamSource(0, m_pVtxBuffBillBoard, 0, sizeof(VERTEX_3D));

	// 頂点フォーマットの設定
	pDevice->SetFVF(FVF_VERTEX_3D);

	// テクスチャの設定
	pDevice->SetTexture(0, m_pTextureBillBoard);

	// ポリゴンの描画
	pDevice->DrawPrimitive(D3DPT_TRIANGLESTRIP, 0, 2);

	pDevice->SetRenderState(D3DRS_ZENABLE, D3DZB_TRUE);
	pDevice->SetRenderState(D3DRS_ZFUNC, D3DCMP_LESSEQUAL);
}

//========================================================================================================
// アニメーション
//========================================================================================================
void CBillboard::SetAnim(int fHeight, int fWidht, int fChange)
{
	VERTEX_3D *pVtx;

	float Hight = 1.0f / fHeight;
	float Wight = 1.0f / fWidht;

	m_nCounterAnim++;

	if (m_nCounterAnim % fChange == 0)
	{
		// パターンの初期化
		m_nPatternAnim = (m_nPatternAnim + 1) % 4;
	}

	// 頂点情報の設定
	m_pVtxBuffBillBoard->Lock(0, 0, (void**)&pVtx, 0);

	// 頂点の設定
	pVtx[0].tex = D3DXVECTOR2(0.0f + m_nPatternAnim * Hight, 0.0f);
	pVtx[1].tex = D3DXVECTOR2(Hight + m_nPatternAnim * Hight, 0.0f);
	pVtx[2].tex = D3DXVECTOR2(0.0f + m_nPatternAnim * Hight, Wight);
	pVtx[3].tex = D3DXVECTOR2(Hight + m_nPatternAnim * Hight, Wight);

	// 頂点データをアンロックする
	m_pVtxBuffBillBoard->Unlock();
}

//========================================================================================================
// テクスチャのセット
//========================================================================================================
void CBillboard::BindTexture(LPDIRECT3DTEXTURE9 cName)
{
	m_pTextureBillBoard = cName;
}

//========================================================================================================
// 位置の取得
//========================================================================================================
D3DXVECTOR3 CBillboard::GetPos(void)
{
	return m_pos;
}

//========================================================================================================
// 位置のセット
//========================================================================================================
void CBillboard::SetPos(D3DXVECTOR3 pos)
{
	m_pos = pos;
}

//========================================================================================================
// 色のセット
//========================================================================================================
void CBillboard::SetColor(D3DXCOLOR color)
{
	m_Color = color;
}

//========================================================================================================
// サイズのセット
//========================================================================================================
void CBillboard::SetSize(float Size_x, float Size_y, float Size_z)
{
	m_size_x = Size_x;
	m_size_y = Size_y;
	m_size_z = Size_z;
}

//====================================================================================================
// デストラクタ
//====================================================================================================
CBillboard::~CBillboard()
{

}