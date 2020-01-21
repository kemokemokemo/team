//=============================================================================
//
// ���C�g���� [light.cpp]
// Author : 
//
//=============================================================================
#include "light.h"
#include "manager.h"
#include "renderer.h"

//=============================================================================
// �����o�ϐ�������
//=============================================================================

//=============================================================================
// �R���X�g���N�^
//=============================================================================
CLight::CLight()
{
}

//=============================================================================
// �f�X�g���N�^
//=============================================================================
CLight::~CLight()
{
}

//=============================================================================
// ���C�g�̐���
//=============================================================================
CLight * CLight::Create()
{
	CLight *pLight;

	pLight = new CLight();

	pLight->Init();

	return pLight;
}

//=============================================================================
// ���C�g�̏���������
//=============================================================================
void CLight::Init(void)
{
	CRenderer *pRenderer = CManager::GetRenderer();
	LPDIRECT3DDEVICE9 pDevice = pRenderer->GetDevice();

	D3DXVECTOR3 vecDir;

	for (int nCntLight = 0; nCntLight < MAX_LIGHT; nCntLight++)
	{
		// ���C�g���N���A����
		ZeroMemory(&m_Light[nCntLight], sizeof(D3DLIGHT9));

		// ���C�g�̎�ނ�ݒ�
		m_Light[nCntLight].Type = D3DLIGHT_DIRECTIONAL;
		
		// ���C�g�̊g�U����ݒ�
		m_Light[nCntLight].Diffuse = D3DXCOLOR(1.0f - nCntLight * 0.3f, 1.0f - nCntLight * 0.3f, 1.0f - nCntLight * 0.3f, 1.0f);

	}

		// ���C�g�̕����̐ݒ�
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
			// ���C�g��ݒ肷��
			pDevice->SetLight(nCntLight, &m_Light[nCntLight]);

			// ���C�g��L���ɂ���
			pDevice->LightEnable(nCntLight, TRUE);
		}
}

//=============================================================================
// ���C�g�̏I������
//=============================================================================
void  CLight::Uninit(void)
{
}

//=============================================================================
// ���C�g�̍X�V����
//=============================================================================
void  CLight::Update(void)
{
}

