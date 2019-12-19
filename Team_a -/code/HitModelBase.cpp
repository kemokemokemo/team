//=============================================================================
//
// ���f������ [hitmodel.cpp]
// Author : KOUAT KIMURA
//
//=============================================================================

//=============================================================================
// �C���N���[�h�t�@�C��
//=============================================================================
#include "hitmodelBase.h"
#include "camera.h"
#include "manager.h"
#include "renderer.h"

//=============================================================================
// �����o�ϐ�������
//=============================================================================
#define MAX_HITMODEL		(1)									// ���f���̐�


//=============================================================================
// �R���X�g���N�^
//=============================================================================
CHitModelBase::CHitModelBase(OBJTYPE type) : CScene(type)
{
}

//=============================================================================
// �f�X�g���N�^
//=============================================================================
CHitModelBase::~CHitModelBase()
{
}

//=============================================================================
// ����������
//=============================================================================
HRESULT CHitModelBase::Init()
{
	CRenderer *pRenderer = CManager::GetRenderer();
	LPDIRECT3DDEVICE9 pDevice = pRenderer->GetDevice();

	VERTEX_3D *pVtx;

	// �I�u�W�F�N�g�̒��_�o�b�t�@�𐶐�
	pDevice->CreateVertexBuffer(sizeof(VERTEX_3D) * 4,
		D3DUSAGE_WRITEONLY,
		FVF_VERTEX_3D,
		D3DPOOL_MANAGED,
		&m_pVtxBuffScene,
		NULL);

	// ���_�f�[�^�͈̔͂����b�N���A���_�o�b�t�@�ւ̃|�C���^���擾
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

	// ���_�f�[�^���A�����b�N����
	m_pVtxBuffScene->Unlock();

	return S_OK;

}

//=============================================================================
// �I������
//=============================================================================
void CHitModelBase::Uninit(void)
{

}

//=============================================================================
// �X�V����
//=============================================================================
void CHitModelBase::Update(void)
{

}

//=============================================================================
// �`�揈��
//=============================================================================
void CHitModelBase::Draw(void)
{
	CRenderer *pRenderer = CManager::GetRenderer();
	LPDIRECT3DDEVICE9 pDevice = pRenderer->GetDevice();

	D3DXMATRIX mtxScale,mtxRot,mtxTrans;			// �v�Z�p�}�g���b�N�X
	D3DXMATERIAL *pMat;								// ���݂̃}�e���A���ۑ��p
	D3DMATERIAL9 matDef;							// �}�e���A���f�[�^�ւ̃|�C���^

	// ���[���h�}�g���b�N�X�̏�����
	D3DXMatrixIdentity(&m_mtxWorld);

	// �g�嗦�𔽉f
	D3DXMatrixScaling(&mtxScale, m_scale.x, m_scale.y, m_scale.z);
	D3DXMatrixMultiply(&m_mtxWorld, &m_mtxWorld, &mtxScale);

	// ��]�𔽉f
	D3DXMatrixRotationYawPitchRoll(&mtxRot, m_rot.y, m_rot.x, m_rot.z);
	D3DXMatrixMultiply(&m_mtxWorld, &m_mtxWorld, &mtxRot);

	// �ʒu�𔽉f
	D3DXMatrixTranslation(&mtxTrans, m_pos.x, m_pos.y, m_pos.z);
	D3DXMatrixMultiply(&m_mtxWorld, &m_mtxWorld, &mtxTrans);

	// ���[���h�}�g���b�N�X�̐ݒ�
	pDevice->SetTransform(D3DTS_WORLD, &m_mtxWorld);

	// ���݂̃}�e���A�����擾
	pDevice->GetMaterial(&matDef);

	// �}�e���A�����ɑ΂���|�C���^���擾
	pMat = (D3DXMATERIAL*)pBuffMat->GetBufferPointer();

	for (int nCntMat = 0; nCntMat < (int)nNumMat; nCntMat++)
	{
		// �}�e���A���̐ݒ�
		pDevice->SetMaterial(&pMat[nCntMat].MatD3D);

		// �e�N�X�`���̔��f
		pDevice->SetTexture(0, 0);

		// �`��
		pMesh->DrawSubset(nCntMat);
	}
	// �}�e���A�����f�t�H���g�ɖ߂�
	pDevice->SetMaterial(&matDef);
}

//====================================================================================================
// ���f���̏�����
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
