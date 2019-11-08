//=============================================================================
//
// ���f������ [model.cpp]
// Author : KOUAT KIMURA
//
//=============================================================================

//=============================================================================
// �C���N���[�h�t�@�C��
//=============================================================================
#include "model.h"
#include "camera.h"
#include "manager.h"
#include "renderer.h"

//=============================================================================
// �����o�ϐ�������
//=============================================================================
DWORD			CModel::nNumMat = NULL;
LPD3DXMESH		CModel::pMesh = NULL;
LPD3DXBUFFER	CModel::pBuffMat = NULL;

//=============================================================================
// �R���X�g���N�^
//=============================================================================
CModel::CModel(OBJTYPE type) : CScene3D(type)
{
}

//=============================================================================
// �f�X�g���N�^
//=============================================================================
CModel::~CModel()
{
}

//=============================================================================
// ���f���̐���
//=============================================================================
CModel * CModel::Create(D3DXVECTOR3 pos, D3DXVECTOR3 rot, MODELTYPE type)
{
	CModel *pModel;
	pModel = new CModel(OBJTYPE_BG);
	pModel->BindModel(nNumMat, pMesh, pBuffMat);
	pModel->Init(pos, rot, type);

	return pModel;
}

//=============================================================================
// ����������
//=============================================================================
HRESULT CModel::Init(D3DXVECTOR3 pos, D3DXVECTOR3 rot, MODELTYPE type)
{
	CScene3D::Init();
	CScene3D::ModelInit();

	CScene3D::SetPos(pos);

	return S_OK;
}

//=============================================================================
// �I������
//=============================================================================
void CModel::Uninit(void)
{
	CScene3D::Uninit();
}

//=============================================================================
// �X�V����
//=============================================================================
void CModel::Update(void)
{
	CScene3D::Update();

	D3DXVECTOR3 pos = CScene3D::GetPos();


	D3DXVECTOR3 posOld;
	// �O��̈ʒu��ۑ�
	posOld = pos;

	if (CollisionModel(&pos, &posOld, D3DXVECTOR3(15.0f, 50.0f, 15.0f)) == true)// �t�B�[���h
	{

	}

	CScene3D::SetPos(pos);
}

//=============================================================================
// �`�揈��
//=============================================================================
void CModel::Draw(void)
{
	CScene3D::DrawModel();
}

//========================================================================================================
// ���f���̓ǂݍ��ݏ���
//========================================================================================================
HRESULT CModel::Load(void)
{
	CRenderer *pRenderer = CManager::GetRenderer();
	LPDIRECT3DDEVICE9 pDevice = pRenderer->GetDevice();

	// X�t�@�C���̓ǂݍ���
	D3DXLoadMeshFromX(MODELFILE0, D3DXMESH_SYSTEMMEM, pDevice, NULL,
		&pBuffMat, NULL,
		&nNumMat,
		&pMesh);

	return S_OK;
}

//========================================================================================================
// ���f���̉������
//========================================================================================================
void CModel::Unload(void)
{

}

//=============================================================================
// ���f���Ƃ̓����蔻��
//=============================================================================
bool CModel::CollisionModel(D3DXVECTOR3 *pPos, D3DXVECTOR3 *pPosOld, D3DXVECTOR3 size)
{

	bool bRand = false;// ���n����

	D3DXVECTOR3 pos = D3DXVECTOR3(0.0f,0.0f,0.0f);
	D3DXVECTOR3 vtxMin = D3DXVECTOR3(0.0f,0.0f,0.0f);				//�ŏ��l
	D3DXVECTOR3 vtxMax = D3DXVECTOR3(0.0f,0.0f,0.0f);				//�ő�l 


	pos = GetPos();
	vtxMin = GetvtxMin();				//�ŏ��l
	vtxMax = GetvtxMax();				//�ő�l 

			if (pPos->y <= pos.y + vtxMax.y&&
				pPosOld->y >= pos.y + vtxMax.y)
			{// ����Ă��邩
				if (pPos->x + size.x > pos.x + vtxMin.x&&
					pPos->x - size.x < pos.x + vtxMax.x)
				{// X,Z���W���͈͓��̏ꍇ
					pPos->y = pos.y + vtxMax.y;
					bRand = true;
				}
			}

	return bRand;
}