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
#define POLTGON0_TEX "DATA/TEX/IMm_2227.JPG"				//読み込むテクスチャファイル名


//====================================================================================================
// メンバ変数初期化
//====================================================================================================

//====================================================================================================
// コンストラクタ
//====================================================================================================
CScene3D::CScene3D(OBJTYPE nPriority) : CScene(nPriority)
{
	 m_PosPolygon = D3DXVECTOR3(0.0f, 0.0f, 0.0f);					//ポリゴンの位置
	 m_rotPolygon = D3DXVECTOR3(0.0f, 0.0f, 0.0f);					//ポリゴンの向き
}

//=============================================================================
// 初期化処理
//=============================================================================
HRESULT CScene3D::Init(void)
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

	pVtx[0].pos = m_pos + D3DXVECTOR3(-10.0f, 0.0f, 10.0f);
	pVtx[1].pos = m_pos + D3DXVECTOR3(10.0f, 0.0f, 10.0f);
	pVtx[2].pos = m_pos + D3DXVECTOR3(-10.0f, 0.0f, -10.0f);
	pVtx[3].pos = m_pos + D3DXVECTOR3(10.0f, 0.0f, -10.0f);

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

	//モデルの初期化
	ModelInit();

	return S_OK;
}

//==================================================================================================
// 終了処理
//===================================================================================================
void CScene3D::Uninit(void)
{
	// 頂点バッファの開放
	if (m_pVtxBuffScene != NULL)
	{
		m_pVtxBuffScene->Release();
		m_pVtxBuffScene = NULL;
	}
}

//====================================================================================================
//更新処理
//=====================================================================================================
void CScene3D::Update(void)
{
	VERTEX_3D *pVtx;

	// 頂点データの範囲をロックし、頂点バッファへのポインタを取得
	m_pVtxBuffScene->Lock(0, 0, (void**)&pVtx, 0);

	for (int nCntModel = 0; nCntModel < MAX_MODEL; nCntModel++)
	{
		pVtx[0].pos = m_pos + D3DXVECTOR3(-10.0f, 0.0f, 10.0f);
		pVtx[1].pos = m_pos + D3DXVECTOR3(10.0f, 0.0f, 10.0f);
		pVtx[2].pos = m_pos + D3DXVECTOR3(-10.0f, 0.0f, -10.0f);
		pVtx[3].pos = m_pos + D3DXVECTOR3(10.0f, 0.0f, -10.0f);
	}

	// 頂点データをアンロックする
	m_pVtxBuffScene->Unlock();
}

//========================================================================================================
// 描画処理
//========================================================================================================
void CScene3D::Draw(void)
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

////========================================================================================================
//// 描画処理
////========================================================================================================
//void CScene3D::DrawModel(void)
//{
//	CRenderer *pRenderer = CManager::GetRenderer();
//	LPDIRECT3DDEVICE9 pDevice = pRenderer->GetDevice();
//
//	D3DXMATRIX mtxRot, mtxTrans;				// 計算用マトリックス
//	D3DXMATERIAL *pMat;							// 現在のマテリアル保存用
//	D3DMATERIAL9 matDef;						// マテリアルデータへのポインタ
//	D3DXMATRIX	mtxParent;						// 親のマトリックス
//
//												// ワールドマトリックスの初期化
//	D3DXMatrixIdentity(&m_mtxWorld);
//
//	// 回転を反映
//	D3DXMatrixRotationYawPitchRoll(&mtxRot, m_rot.y, m_rot.x, m_rot.z);
//	D3DXMatrixMultiply(&m_mtxWorld, &m_mtxWorld, &mtxRot);
//
//	// 位置を反映
//	D3DXMatrixTranslation(&mtxTrans, m_pos.x, m_pos.y, m_pos.z);
//	D3DXMatrixMultiply(&m_mtxWorld, &m_mtxWorld, &mtxTrans);
//
//	// ワールドマトリックスの設定
//	pDevice->SetTransform(D3DTS_WORLD, &m_mtxWorld);
//
//
//	for (int nCntModel = 0; nCntModel < MAX_MODEL; nCntModel++)
//	{
//
//		if (m_Parent[nCntModel].nIdxModelParent == -1)
//		{
//			mtxParent = m_mtxWorld;
//		}
//		else
//		{
//			mtxParent = m_Parent[m_Parent[nCntModel].nIdxModelParent].mtxWorld;
//		}
//		// ワールドマトリックスの初期化
//		D3DXMatrixIdentity(&m_mtxWorld);
//
//		// 回転を反映
//		D3DXMatrixRotationYawPitchRoll(&mtxRot, m_Parent[nCntModel].rot.y, m_Parent[nCntModel].rot.x, m_Parent[nCntModel].rot.z);
//		D3DXMatrixMultiply(&m_mtxWorld, &m_mtxWorld, &mtxRot);
//
//		// 位置を反映
//		D3DXMatrixTranslation(&mtxTrans, m_Parent[nCntModel].pos.x, m_Parent[nCntModel].pos.y, m_Parent[nCntModel].pos.z);
//		D3DXMatrixMultiply(&m_mtxWorld, &m_mtxWorld, &mtxTrans);
//
//		// 親モデルのマトリックスをかけ合わせる
//		D3DXMatrixMultiply(&m_Parent[nCntModel].mtxWorld,
//			&m_Parent[nCntModel].mtxWorld, &mtxParent);
//
//		// ワールドマトリックスの設定
//		pDevice->SetTransform(D3DTS_WORLD, &m_Parent[nCntModel].mtxWorld);
//
//		// 現在のマテリアルを取得
//		pDevice->GetMaterial(&matDef);
//
//		// マテリアル情報に対するポインタを取得
//		pMat = (D3DXMATERIAL*)pBuffMat->GetBufferPointer();
//
//		for (int nCntMat = 0; nCntMat < (int)nNumMat; nCntMat++)
//		{
//			// マテリアルの設定
//			pDevice->SetMaterial(&pMat[nCntMat].MatD3D);
//
//			// 描画
//			pMesh->DrawSubset(nCntMat);
//		}
//
//		// マテリアルをデフォルトに戻す
//		pDevice->SetMaterial(&matDef);
//	}
//}

//========================================================================================================
// 描画処理
//========================================================================================================
void CScene3D::DrawModel(void)
{
	CRenderer *pRenderer = CManager::GetRenderer();
	LPDIRECT3DDEVICE9 pDevice = pRenderer->GetDevice();

	D3DXMATRIX mtxRot, mtxTrans;				// 計算用マトリックス
	D3DXMATERIAL *pMat;							// 現在のマテリアル保存用
	D3DMATERIAL9 matDef;						// マテリアルデータへのポインタ

	for (int nCntModel = 0; nCntModel < MAX_MODEL; nCntModel++)
	{
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
}

//====================================================================================================
// モデルの初期化
//====================================================================================================
void CScene3D::ModelInit(void)
{
	CRenderer *pRenderer = CManager::GetRenderer();
	LPDIRECT3DDEVICE9 pDevice = pRenderer->GetDevice();

	// 初期設定
	for (int nCntModel = 0; nCntModel < MAX_MODEL; nCntModel++)
	{
		m_pos = D3DXVECTOR3(0.0f,0.0f,0.0f);
		m_rot = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	}

	// モデルの頂点数の最大値・最小値の設定
	int		nNumVertices;							// 頂点数
	DWORD	sizeFVF;								// 頂点フォーマットのサイズ
	BYTE	*pVertexBuffer;

	for (int nCntModel = 0; nCntModel < MODELTYPE_MAX; nCntModel++)
	{
		m_vtxMax = D3DXVECTOR3(-1000.0f, -1000.0f, -1000.0f);
		m_vtxMin = D3DXVECTOR3(1000.0f, 1000.0f, 1000.0f);

		// 頂点数を取得
		nNumVertices = pMesh->GetNumVertices();

		// 頂点フォーマットのサイズを取得
		sizeFVF = D3DXGetFVFVertexSize(pMesh->GetFVF());

		// 頂点バッファをロック
		pMesh->LockVertexBuffer(D3DLOCK_READONLY, (void**)&pVertexBuffer);

		for (int nCntVtx = 0; nCntVtx < nNumVertices; nCntVtx++)
		{
			D3DXVECTOR3 vtx = *(D3DXVECTOR3*)pVertexBuffer;

			// 全ての頂点情報を比較して最大値・最小値を抜き出す
			D3DXVec3Minimize(&m_vtxMin, &vtx, &m_vtxMin);

			D3DXVec3Maximize(&m_vtxMax, &vtx, &m_vtxMax);

			pVertexBuffer += sizeFVF;//	サイズ分ポインタを進める
		}
		// アンロック
		pMesh->UnlockVertexBuffer();
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


//====================================================================================================
// モデルの取得
//====================================================================================================
void CScene3D::BindModel(DWORD NumMat, LPD3DXMESH Mesh, LPD3DXBUFFER BuffMat)
{
	nNumMat = NumMat;
	pMesh = Mesh;
	pBuffMat = BuffMat;
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
// 種類のセット
//====================================================================================================
void CScene3D::SetType(MODELTYPE Type)
{
	m_type = Type;
}

//====================================================================================================
// デストラクタ
//====================================================================================================
CScene3D::~CScene3D()
{

}