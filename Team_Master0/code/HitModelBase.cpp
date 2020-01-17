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
#define POLTGON0_TEX "DATA/TEX/sougen.jpg"				//�ǂݍ��ރe�N�X�`���t�@�C����

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
	//CRenderer *pRenderer = CManager::GetRenderer();
	//LPDIRECT3DDEVICE9 pDevice = pRenderer->GetDevice();

	//D3DXCreateTextureFromFile(
	//	pDevice,
	//	POLTGON0_TEX,
	//	&m_pTextureModel);

	return S_OK;
}

//=============================================================================
// �I������
//=============================================================================
void CHitModelBase::Uninit(void)
{
	Release();
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

	//m_mtxWorld = mtxTrans * mtxScale *mtxRot;

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

		// �e�N�X�`���̐ݒ�
		pDevice->SetTexture(0, m_pTextureModel);

		// �`��
		pMesh->DrawSubset(nCntMat);
	}
	// �}�e���A�����f�t�H���g�ɖ߂�
	pDevice->SetMaterial(&matDef);
}

//====================================================================================================
// �|�W�V�����̎擾
//====================================================================================================
D3DXVECTOR3 CHitModelBase::GetPos()
{
	return m_pos;
}

//====================================================================================================
// �T�C�Y�̎擾
//====================================================================================================
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
