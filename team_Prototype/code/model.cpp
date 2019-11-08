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
CScene3D::MODELNUM CModel::m_Unit[UNITTYPE_MAX] = {};

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
CModel * CModel::Create(D3DXVECTOR3 pos, D3DXVECTOR3 rot, UNITTYPE type)
{
	CModel *pModel;
	pModel = new CModel(OBJTYPE_BG);
	pModel->BindModel(&m_Unit[type]);
	pModel->Init(pos, rot, type);

	return pModel;
}

//=============================================================================
// ����������
//=============================================================================
HRESULT CModel::Init(D3DXVECTOR3 pos, D3DXVECTOR3 rot, UNITTYPE type)
{
	CScene3D::Init();

	m_pos = pos;

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

	//m_pos = CScene3D::GetPos();

	CScene3D::SetPos(m_pos);
}

//=============================================================================
// �`�揈��
//=============================================================================
void CModel::Draw(void)
{
	CScene3D::Draw();
}

//========================================================================================================
// ���f���̓ǂݍ��ݏ���
//========================================================================================================
HRESULT CModel::Load(void)
{
	CRenderer *pRenderer = CManager::GetRenderer();
	LPDIRECT3DDEVICE9 pDevice = pRenderer->GetDevice();

	//// X�t�@�C���̓ǂݍ���
	//D3DXLoadMeshFromX(MODELFILE0, D3DXMESH_SYSTEMMEM, pDevice, NULL,
	//	&pBuffMat, NULL,
	//	&nNumMat,
	//	&pMesh);

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
//bool CollisionModel(D3DXVECTOR3 *pPos, D3DXVECTOR3 *pPosOld, D3DXVECTOR3 size)
//{
//	bool bRand = false;// ���n����
//
//	// �����蔻��
//	for (int nCountBlock = 0; nCountBlock < MAX_MODEL; nCountBlock++)
//	{
//		if (m_aModel[nCountBlock].bUse)// �u���b�N���g�p����Ă���ꍇ
//		{
//			if (pPos->y <= m_aModel[nCountBlock].pos.y + m_aModelModel[m_aModel[nCountBlock].type].vtxMax.y&&
//				pPosOld->y >= m_aModel[nCountBlock].pos.y + m_aModelModel[m_aModel[nCountBlock].type].vtxMax.y)
//			{// ����Ă��邩
//				if (pPos->x + size.x > m_aModel[nCountBlock].pos.x + m_aModelModel[m_aModel[nCountBlock].type].vtxMin.x&&
//					pPos->x - size.x < m_aModel[nCountBlock].pos.x + m_aModelModel[m_aModel[nCountBlock].type].vtxMax.x&&
//					pPos->z + size.z > m_aModel[nCountBlock].pos.z + m_aModelModel[m_aModel[nCountBlock].type].vtxMin.z&&
//					pPos->z - size.z < m_aModel[nCountBlock].pos.z + m_aModelModel[m_aModel[nCountBlock].type].vtxMax.z)
//				{// X,Z���W���͈͓��̏ꍇ
//					pPos->y = m_aModel[nCountBlock].pos.y + m_aModelModel[m_aModel[nCountBlock].type].vtxMax.y;
//					bRand = true;
//				}
//			}
//			else if (pPos->y + size.y > m_aModel[nCountBlock].pos.y + m_aModelModel[m_aModel[nCountBlock].type].vtxMin.y &&
//				pPos->y < m_aModel[nCountBlock].pos.y + m_aModelModel[m_aModel[nCountBlock].type].vtxMax.y)
//			{// Y���W���͈͓��̏ꍇ
//				if (pPos->x + size.x > m_aModel[nCountBlock].pos.x + m_aModelModel[m_aModel[nCountBlock].type].vtxMin.x&&
//					pPos->x - size.x < m_aModel[nCountBlock].pos.x + m_aModelModel[m_aModel[nCountBlock].type].vtxMax.x)
//				{// �㉺
//					if (pPos->z - size.z <= m_aModel[nCountBlock].pos.z + m_aModelModel[m_aModel[nCountBlock].type].vtxMax.z&&
//						pPosOld->z - size.z >= m_aModel[nCountBlock].pos.z + m_aModelModel[m_aModel[nCountBlock].type].vtxMax.z)
//					{// �v���C���[���u���b�N�ɏォ��Ԃ�����
//						pPos->z = size.z + m_aModel[nCountBlock].pos.z + m_aModelModel[m_aModel[nCountBlock].type].vtxMax.z;
//					}
//					else if (pPos->z + size.z >= m_aModel[nCountBlock].pos.z + m_aModelModel[m_aModel[nCountBlock].type].vtxMin.z&&
//						pPosOld->z + size.z <= m_aModel[nCountBlock].pos.z + m_aModelModel[m_aModel[nCountBlock].type].vtxMin.z)
//					{// �v���C���[���u���b�N�ɉ�����Ԃ�����
//						pPos->z = m_aModel[nCountBlock].pos.z + m_aModelModel[m_aModel[nCountBlock].type].vtxMin.z - size.z;
//					}
//				}
//
//				if (pPos->z + size.z > m_aModel[nCountBlock].pos.z + m_aModelModel[m_aModel[nCountBlock].type].vtxMin.z&&
//					pPos->z - size.z < m_aModel[nCountBlock].pos.z + m_aModelModel[m_aModel[nCountBlock].type].vtxMax.z)
//				{// ���E
//					if (pPos->x - size.x <= m_aModel[nCountBlock].pos.x + m_aModelModel[m_aModel[nCountBlock].type].vtxMax.x&&
//						pPosOld->x - size.x >= m_aModel[nCountBlock].pos.x + m_aModelModel[m_aModel[nCountBlock].type].vtxMax.x)
//					{// �v���C���[���u���b�N�ɉE����Ԃ�����
//						pPos->x = size.x + m_aModel[nCountBlock].pos.x + m_aModelModel[m_aModel[nCountBlock].type].vtxMax.x;
//					}
//					else if (pPos->x + size.x >= m_aModel[nCountBlock].pos.x + m_aModelModel[m_aModel[nCountBlock].type].vtxMin.x&&
//						pPosOld->x + size.x <= m_aModel[nCountBlock].pos.x + m_aModelModel[m_aModel[nCountBlock].type].vtxMin.x)
//					{// �v���C���[���u���b�N�ɍ�����Ԃ�����
//						pPos->x = m_aModel[nCountBlock].pos.x + m_aModelModel[m_aModel[nCountBlock].type].vtxMin.x - size.x;
//					}
//				}
//			}
//		}
//	}
//
//	return bRand;
//}