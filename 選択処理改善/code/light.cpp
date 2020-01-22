//=============================================================================
//
// ライト処理 [light.cpp]
// Author : 
//
//=============================================================================
#include "light.h"
#include "manager.h"
#include "renderer.h"

//=============================================================================
// メンバ変数初期化
//=============================================================================

//=============================================================================
// コンストラクタ
//=============================================================================
CLight::CLight()
{
}

//=============================================================================
// デストラクタ
//=============================================================================
CLight::~CLight()
{
}

//=============================================================================
// ライトの生成
//=============================================================================
CLight * CLight::Create()
{
	CLight *pLight;

	pLight = new CLight();

	pLight->Init();

	return pLight;
}

//=============================================================================
// ライトの初期化処理
//=============================================================================
void CLight::Init(void)
{
	CRenderer *pRenderer = CManager::GetRenderer();
	LPDIRECT3DDEVICE9 pDevice = pRenderer->GetDevice();

	D3DXVECTOR3 vecDir;

	for (int nCntLight = 0; nCntLight < MAX_LIGHT; nCntLight++)
	{
		// ライトをクリアする
		ZeroMemory(&m_Light[nCntLight], sizeof(D3DLIGHT9));

		// ライトの種類を設定
		m_Light[nCntLight].Type = D3DLIGHT_DIRECTIONAL;
		
		// ライトの拡散光を設定
		m_Light[nCntLight].Diffuse = D3DXCOLOR(1.0f - nCntLight * 0.3f, 1.0f - nCntLight * 0.3f, 1.0f - nCntLight * 0.3f, 1.0f);

	}

		// ライトの方向の設定
		vecDir = D3DXVECTOR3(0.20f, -0.80f, 0.40f);
		D3DXVec3Normalize(&vecDir, &vecDir);
		m_Light[0].Direction = vecDir;

		vecDir = D3DXVECTOR3(-0.20f, 0.80f, -0.40f);
		D3DXVec3Normalize(&vecDir, &vecDir);
		m_Light[1].Direction = vecDir;

		vecDir = D3DXVECTOR3(0.90f, -0.10f, 0.40f);
		D3DXVec3Normalize(&vecDir, &vecDir);
		m_Light[2].Direction = vecDir;

		for (int nCntLight = 0; nCntLight < MAX_LIGHT; nCntLight++)
		{
			// ライトを設定する
			pDevice->SetLight(nCntLight, &m_Light[nCntLight]);

			// ライトを有効にする
			pDevice->LightEnable(nCntLight, TRUE);
		}
}

//=============================================================================
// ライトの終了処理
//=============================================================================
void  CLight::Uninit(void)
{
}

//=============================================================================
// ライトの更新処理
//=============================================================================
void  CLight::Update(void)
{
}

