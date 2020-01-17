//=============================================================================
//
// カメラ処理 [camera.cpp]
// Author : 木村洸太
//
//=============================================================================
#include "camera.h"
#include "manager.h"
#include "renderer.h"
#include "input.h"
#include "keybord.h"

//=============================================================================
// マクロ定義
//=============================================================================
#define CSPEED		(1.0f)

//=============================================================================
// 前方宣言の初期化
//=============================================================================
CCamera::CAMERA CCamera::m_Camera = {};

//=============================================================================
// コンストラクタ
//=============================================================================
CCamera::CCamera()
{
}


//=============================================================================
// デストラクタ
//=============================================================================
CCamera::~CCamera()
{
}

//=============================================================================
// カメラの生成
//=============================================================================
CCamera * CCamera::Create()
{
	CCamera *pCamera;

	pCamera = new CCamera();

	pCamera->Init();

	//pCamera->SetCamera();

	return pCamera;
}

//=============================================================================
// カメラの初期化処理
//=============================================================================
void CCamera::Init(void)
{

	m_Camera.posV = D3DXVECTOR3(0.0f, 50.0f, -650.0f);
	m_Camera.posVDest = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	m_Camera.posR = D3DXVECTOR3(0.0f, 100.0f, 0.0f);
	m_Camera.posRDest = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	m_Camera.rot  = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	m_Camera.vecU = D3DXVECTOR3(0.0f, 1.0f, 0.0f);
	m_Camera.rotDest = D3DXVECTOR3(0.0f, 0.0f, 0.0f);

	// 差分
	D3DXVECTOR3 fDiffpos = m_Camera.posV - m_Camera.posR;

	// 距離
	m_fDistance = sqrtf(fDiffpos.y * fDiffpos.y + fDiffpos.z* fDiffpos.z);
}
//=============================================================================
// カメラの終了処理
//=============================================================================
void CCamera::Uninit(void)
{

}

//=============================================================================
// カメラの更新処理
//=============================================================================
void CCamera::Update(void)
{

	CKeybord *pKetybord = CManager::GetKeybord();

	//// 回転
	//if (pKetybord->GetKeyboardPress(DIK_LEFTARROW))
	//{
	//	m_Camera.rot.y -= 0.05f;
	//}
	//if (pKetybord->GetKeyboardPress(DIK_RIGHTARROW))
	//{
	//	m_Camera.rot.y += 0.05f;
	//}

	// 公転
	if (pKetybord->GetKeyboardPress(DIK_Q))
	{
		m_Camera.rot.y += 0.05f;
		m_Camera.posV.x = m_Camera.posR.x + sinf(D3DX_PI + m_Camera.rot.y) * m_fDistance;
		m_Camera.posV.z = m_Camera.posR.z + cosf(D3DX_PI + m_Camera.rot.y) * m_fDistance;
	}
	if (pKetybord->GetKeyboardPress(DIK_E))
	{
		m_Camera.rot.y -= 0.05f;
		m_Camera.posV.x = m_Camera.posR.x + sinf(D3DX_PI+m_Camera.rot.y) * m_fDistance;
		m_Camera.posV.z = m_Camera.posR.z + cosf(D3DX_PI+m_Camera.rot.y) * m_fDistance;
	}

	////移動
	//if (pKetybord->GetKeyboardPress(DIK_LEFTARROW))
	//{//  F キー操作
	//	if (pKetybord->GetKeyboardPress(DIK_DOWNARROW))
	//	{// 左上
	//		m_Camera.posV.x += sinf(-D3DX_PI*0.75f+m_Camera.rot.y)*1.0f;
	//		m_Camera.posV.z += cosf(-D3DX_PI*0.75f+m_Camera.rot.y)*1.0f;

	//	}
	//	else if (pKetybord->GetKeyboardPress(DIK_UPARROW))
	//	{// 右下
	//		m_Camera.posV.x += sinf(-D3DX_PI*0.25f+m_Camera.rot.y)*1.0f;
	//		m_Camera.posV.z += cosf(-D3DX_PI*0.25f+m_Camera.rot.y)*1.0f;
	//	}
	//	else
	//	{// 左
	//		m_Camera.posV.x += sinf(-D3DX_PI*0.5f+m_Camera.rot.y)*1.0f;
	//		m_Camera.posV.z += cosf(-D3DX_PI*0.5f+m_Camera.rot.y)*1.0f;
	//	}

	//}
	//else if (pKetybord->GetKeyboardPress(DIK_RIGHTARROW))
	//{//  H キー操作
	//	if (pKetybord->GetKeyboardPress(DIK_DOWNARROW))
	//	{// 右上
	//		m_Camera.posV.x += sinf(D3DX_PI*0.75f+m_Camera.rot.y)*1.0f;
	//		m_Camera.posV.z += cosf(D3DX_PI*0.75f+m_Camera.rot.y)*1.0f;
	//	}
	//	else if (pKetybord->GetKeyboardPress(DIK_UPARROW))
	//	{// 右下 
	//		m_Camera.posV.x += sinf(D3DX_PI*0.25f+m_Camera.rot.y)*1.0f;
	//		m_Camera.posV.z += cosf(D3DX_PI*0.25f+m_Camera.rot.y)*1.0f;
	//	}
	//	else
	//	{// 右
	//		m_Camera.posV.x += sinf(D3DX_PI*0.5f+m_Camera.rot.y)*1.0f;
	//		m_Camera.posV.z += cosf(D3DX_PI*0.5f+m_Camera.rot.y)*1.0f;
	//	}

	//}
	//else if (pKetybord->GetKeyboardPress(DIK_DOWNARROW))
	//{//  G キー操作
	//	m_Camera.posV.x += sinf(D3DX_PI+m_Camera.rot.y)*1.0f;
	//	m_Camera.posV.z += cosf(D3DX_PI+m_Camera.rot.y)*1.0f;

	//}
	//else if (pKetybord->GetKeyboardPress(DIK_UPARROW))
	//{//  T キー操作

	//	m_Camera.posV.x += sinf(0.0f+m_Camera.rot.y)*1.0f;
	//	m_Camera.posV.z += cosf(0.0f+m_Camera.rot.y)*1.0f;
	//}

	m_Camera.posR.x = m_Camera.posV.x + sinf(m_Camera.rot.y) * m_fDistance;
	m_Camera.posR.z = m_Camera.posV.z + cosf(m_Camera.rot.y) * m_fDistance;

}

//=============================================================================
// カメラの設定処理
//=============================================================================
void CCamera::SetCamera(void)
{
	CRenderer *pRenderer = CManager::GetRenderer();
	LPDIRECT3DDEVICE9 pDevice = pRenderer->GetDevice();

	// プロジェクションマトリックスの初期化
	D3DXMatrixIdentity(&m_Camera.mtxProjection);

	// プロジェクションマトリックスを作成
	D3DXMatrixPerspectiveFovLH(&m_Camera.mtxProjection,
		D3DXToRadian(45.0f),(float)SCREEN_WIDTH / (float)SCREEN_HEIGHT,
		10.0f,
		5000.0f);

	// プロジェクションマトリックスの設定
	pDevice->SetTransform(D3DTS_PROJECTION, &m_Camera.mtxProjection);

	// ビューマトリックスの初期化
	D3DXMatrixIdentity(&m_Camera.mtxView);

	// ビューマトリックスを作成
	D3DXMatrixLookAtLH(
		&m_Camera.mtxView,
		&m_Camera.posV,
		&m_Camera.posR,
		&m_Camera.vecU);

	// ビューマトリックスの設定
	pDevice->SetTransform(D3DTS_VIEW, &m_Camera.mtxView);
}
//=========================================================================
// カメラの取得
//=========================================================================
CCamera::CAMERA *  CCamera::GetCamera(void)
{
	return &m_Camera;
}