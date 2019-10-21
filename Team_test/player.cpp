//=============================================================================
//
// �v���C���[���� [player.cpp]
// Author : KOUTA KIMURA
//
//=============================================================================

//=============================================================================
// �C���N���[�h�t�@�C��
//=============================================================================
#include "player.h"
#include "camera.h"
#include "manager.h"
#include "renderer.h"
#include "keybord.h"

//====================================================================================================
// �}�N����`
//==================================================================================================== 
#define PLAYER_SPEED			(10.0f)	//�v���C���[�̑���

//=============================================================================
// �R���X�g���N�^
//=============================================================================
CPlayer::CPlayer(OBJTYPE type) : CScene3D(type)
{

	m_move = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	
}

//=============================================================================
// �f�X�g���N�^
//=============================================================================
CPlayer::~CPlayer()
{

}

//=============================================================================
// ���f���̐���
//=============================================================================
CPlayer * CPlayer::Create(D3DXVECTOR3 pos, D3DXVECTOR3 rot, MODELTYPE type)
{
	CPlayer *pPlayer;
	pPlayer = new CPlayer(OBJTYPE_PLAYER);
	pPlayer->Init(pos, rot, type);

	return pPlayer;
}

//=============================================================================
// ����������
//=============================================================================
HRESULT CPlayer::Init(D3DXVECTOR3 pos, D3DXVECTOR3 rot, MODELTYPE type)
{
	CScene3D::Init();

	CScene3D::SetPos(pos);

	CScene3D::SetType(type);

	return S_OK;
}

//=============================================================================
// �I������
//=============================================================================
void CPlayer::Uninit(void)
{
	CScene3D::Uninit();
}

//=============================================================================
// �X�V����
//=============================================================================
void CPlayer::Update(void)
{

	CScene3D::Update();
	
	PlayerMove();
}

//=============================================================================
// �`�揈��
//=============================================================================
void CPlayer::Draw(void)
{
	CScene3D::DrawModel();
}

//========================================================================================================
// �v���C���[�̈ړ�����
//========================================================================================================
void CPlayer::PlayerMove(void)
{
	CKeybord *pKetybord = CManager::GetKeybord();

	//�J�����̎擾
	CCamera::CAMERA *pCamera;
	pCamera = CCamera::GetCamera();

	D3DXVECTOR3 pos;

	pos = CScene3D::GetPos();

	pos += m_move;

		if (pKetybord->GetKeyboardPress(DIK_A))
		{//  A �L�[����
			if (pKetybord->GetKeyboardPress(DIK_S))
			{// ����
			m_move.x += sinf(pCamera->rot.y - D3DX_PI*0.75f) * PLAYER_SPEED;
			m_move.z += cosf(pCamera->rot.y - D3DX_PI*0.75f) * PLAYER_SPEED;
			}
			else if (pKetybord->GetKeyboardPress(DIK_W))
			{// �E��
				m_move.x += sinf(pCamera->rot.y - D3DX_PI*0.25f) * PLAYER_SPEED;
				m_move.z += cosf(pCamera->rot.y - D3DX_PI*0.25f) * PLAYER_SPEED;
			}
			else
			{// ��
				m_move.x += cosf(pCamera->rot.y + D3DX_PI*1.0f) * PLAYER_SPEED;
			}
		}

		else if (pKetybord->GetKeyboardPress(DIK_D))
		{//  D �L�[����

			if (pKetybord->GetKeyboardPress(DIK_S))
			{// �E��
				m_move.x += sinf(pCamera->rot.y + D3DX_PI*0.75f) * PLAYER_SPEED;
				m_move.z += cosf(pCamera->rot.y + D3DX_PI*0.75f) * PLAYER_SPEED;
			}
			else if (pKetybord->GetKeyboardPress(DIK_W))
			{// �E�� 
				m_move.x += sinf(pCamera->rot.y + D3DX_PI*0.25f) * PLAYER_SPEED;
				m_move.z += cosf(pCamera->rot.y + D3DX_PI*0.25f) * PLAYER_SPEED;
			}
			else
			{// �E
				m_move.x += sinf(pCamera->rot.y + D3DX_PI*0.5f) * PLAYER_SPEED;
			}
		}

		else if (pKetybord->GetKeyboardPress(DIK_W))
		{//  S �L�[����
			m_move.z += cosf(pCamera->rot.y + D3DX_PI*0.0f) * PLAYER_SPEED;
		}

		else if (pKetybord->GetKeyboardPress(DIK_S))
		{//  W �L�[����
			m_move.z += cosf(pCamera->rot.y + D3DX_PI*1.0f) * PLAYER_SPEED;
		}

		if (pKetybord->GetKeyboardPress(DIK_O))
		{// ����
			m_move.y += cosf(pCamera->rot.y + D3DX_PI*0.0f) * PLAYER_SPEED;
		}

		if (pKetybord->GetKeyboardPress(DIK_P))
		{// ����
			m_move.y += cosf(pCamera->rot.y + D3DX_PI*1.0f) * PLAYER_SPEED;
		}

		CScene3D::SetPos(pos);
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