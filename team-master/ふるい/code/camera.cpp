//=============================================================================
//
// �J�������� [camera.cpp]
// Author : �ؑ�����
//
//=============================================================================
#include "camera.h"
#include "manager.h"
#include "renderer.h"
#include "input.h"
#include "keybord.h"

//=============================================================================
// �}�N����`
//=============================================================================
#define CSPEED		(1.0f)

//=============================================================================
// �O���錾�̏�����
//=============================================================================
CCamera::CAMERA CCamera::m_Camera = {};

//=============================================================================
// �R���X�g���N�^
//=============================================================================
CCamera::CCamera()
{
}


//=============================================================================
// �f�X�g���N�^
//=============================================================================
CCamera::~CCamera()
{
}

//=============================================================================
// �J�����̐���
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
// �J�����̏���������
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

	// ����
	D3DXVECTOR3 fDiffpos = m_Camera.posV - m_Camera.posR;

	// ����
	m_fDistance = sqrtf(fDiffpos.y * fDiffpos.y + fDiffpos.z* fDiffpos.z);
}
//=============================================================================
// �J�����̏I������
//=============================================================================
void CCamera::Uninit(void)
{

}

//=============================================================================
// �J�����̍X�V����
//=============================================================================
void CCamera::Update(void)
{

	CKeybord *pKetybord = CManager::GetKeybord();

	//// ��]
	//if (pKetybord->GetKeyboardPress(DIK_LEFTARROW))
	//{
	//	m_Camera.rot.y -= 0.05f;
	//}
	//if (pKetybord->GetKeyboardPress(DIK_RIGHTARROW))
	//{
	//	m_Camera.rot.y += 0.05f;
	//}

	// ���]
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

	////�ړ�
	//if (pKetybord->GetKeyboardPress(DIK_LEFTARROW))
	//{//  F �L�[����
	//	if (pKetybord->GetKeyboardPress(DIK_DOWNARROW))
	//	{// ����
	//		m_Camera.posV.x += sinf(-D3DX_PI*0.75f+m_Camera.rot.y)*1.0f;
	//		m_Camera.posV.z += cosf(-D3DX_PI*0.75f+m_Camera.rot.y)*1.0f;

	//	}
	//	else if (pKetybord->GetKeyboardPress(DIK_UPARROW))
	//	{// �E��
	//		m_Camera.posV.x += sinf(-D3DX_PI*0.25f+m_Camera.rot.y)*1.0f;
	//		m_Camera.posV.z += cosf(-D3DX_PI*0.25f+m_Camera.rot.y)*1.0f;
	//	}
	//	else
	//	{// ��
	//		m_Camera.posV.x += sinf(-D3DX_PI*0.5f+m_Camera.rot.y)*1.0f;
	//		m_Camera.posV.z += cosf(-D3DX_PI*0.5f+m_Camera.rot.y)*1.0f;
	//	}

	//}
	//else if (pKetybord->GetKeyboardPress(DIK_RIGHTARROW))
	//{//  H �L�[����
	//	if (pKetybord->GetKeyboardPress(DIK_DOWNARROW))
	//	{// �E��
	//		m_Camera.posV.x += sinf(D3DX_PI*0.75f+m_Camera.rot.y)*1.0f;
	//		m_Camera.posV.z += cosf(D3DX_PI*0.75f+m_Camera.rot.y)*1.0f;
	//	}
	//	else if (pKetybord->GetKeyboardPress(DIK_UPARROW))
	//	{// �E�� 
	//		m_Camera.posV.x += sinf(D3DX_PI*0.25f+m_Camera.rot.y)*1.0f;
	//		m_Camera.posV.z += cosf(D3DX_PI*0.25f+m_Camera.rot.y)*1.0f;
	//	}
	//	else
	//	{// �E
	//		m_Camera.posV.x += sinf(D3DX_PI*0.5f+m_Camera.rot.y)*1.0f;
	//		m_Camera.posV.z += cosf(D3DX_PI*0.5f+m_Camera.rot.y)*1.0f;
	//	}

	//}
	//else if (pKetybord->GetKeyboardPress(DIK_DOWNARROW))
	//{//  G �L�[����
	//	m_Camera.posV.x += sinf(D3DX_PI+m_Camera.rot.y)*1.0f;
	//	m_Camera.posV.z += cosf(D3DX_PI+m_Camera.rot.y)*1.0f;

	//}
	//else if (pKetybord->GetKeyboardPress(DIK_UPARROW))
	//{//  T �L�[����

	//	m_Camera.posV.x += sinf(0.0f+m_Camera.rot.y)*1.0f;
	//	m_Camera.posV.z += cosf(0.0f+m_Camera.rot.y)*1.0f;
	//}

	m_Camera.posR.x = m_Camera.posV.x + sinf(m_Camera.rot.y) * m_fDistance;
	m_Camera.posR.z = m_Camera.posV.z + cosf(m_Camera.rot.y) * m_fDistance;

}

//=============================================================================
// �J�����̐ݒ菈��
//=============================================================================
void CCamera::SetCamera(void)
{
	CRenderer *pRenderer = CManager::GetRenderer();
	LPDIRECT3DDEVICE9 pDevice = pRenderer->GetDevice();

	// �v���W�F�N�V�����}�g���b�N�X�̏�����
	D3DXMatrixIdentity(&m_Camera.mtxProjection);

	// �v���W�F�N�V�����}�g���b�N�X���쐬
	D3DXMatrixPerspectiveFovLH(&m_Camera.mtxProjection,
		D3DXToRadian(45.0f),(float)SCREEN_WIDTH / (float)SCREEN_HEIGHT,
		10.0f,
		5000.0f);

	// �v���W�F�N�V�����}�g���b�N�X�̐ݒ�
	pDevice->SetTransform(D3DTS_PROJECTION, &m_Camera.mtxProjection);

	// �r���[�}�g���b�N�X�̏�����
	D3DXMatrixIdentity(&m_Camera.mtxView);

	// �r���[�}�g���b�N�X���쐬
	D3DXMatrixLookAtLH(
		&m_Camera.mtxView,
		&m_Camera.posV,
		&m_Camera.posR,
		&m_Camera.vecU);

	// �r���[�}�g���b�N�X�̐ݒ�
	pDevice->SetTransform(D3DTS_VIEW, &m_Camera.mtxView);
}
//=========================================================================
// �J�����̎擾
//=========================================================================
CCamera::CAMERA *  CCamera::GetCamera(void)
{
	return &m_Camera;
}