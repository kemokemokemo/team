//=============================================================================
//
// �v���C���[���� [player.cpp]
// Author : KOUTA KIMURA
//
//=============================================================================

//=============================================================================
// �C���N���[�h�t�@�C��
//=============================================================================
#include "player_kangaroo.h"
#include "camera.h"
#include "manager.h"
#include "renderer.h"
#include "keybord.h"
#include "pad.h"
#include "gauge.h"
#include "Scene2D.h"

//=============================================================================
// �}�N����`
//=============================================================================
#define PLAYER_SPEED	(1.5f)					//�v���C���[�̑���
#define PLAYER_AIRSPEED	(1.5f)					//�󒆂ł̃v���C���[�̑���
#define PLAYER_AIRATKSPEED	(0.5f)					//�󒆂ł̃v���C���[�̑���
#define PLAYER_JUMP (120.0f)					//�W�����v�̍���
#define PLAYER_AIRJUMP (90.0f)					//�󒆃W�����v�̍���
#define LIGHT_ATK (9)					//��U���ɔh���ł���t���[��

//=============================================================================
// �����o�ϐ�������
//=============================================================================

//=============================================================================
// �R���X�g���N�^
//=============================================================================
CPlayer_Kangaroo::CPlayer_Kangaroo(OBJTYPE type) : CPlayerBase(type)
{

}

//=============================================================================
// �f�X�g���N�^
//=============================================================================
CPlayer_Kangaroo::~CPlayer_Kangaroo()
{

}

//=============================================================================
// ���f���̐���
//=============================================================================
CPlayer_Kangaroo * CPlayer_Kangaroo::Create(D3DXVECTOR3 pos, D3DXVECTOR3 rot, CMaker::MAKERTYPE MokerType)
{
	CPlayer_Kangaroo *pPlayer;
	pPlayer = new CPlayer_Kangaroo(OBJTYPE_PLAYER);

	pPlayer->Init(pos, rot, MokerType);
	return pPlayer;
}

//=============================================================================
// ����������
//=============================================================================
HRESULT CPlayer_Kangaroo::Init(D3DXVECTOR3 pos, D3DXVECTOR3 rot, CMaker::MAKERTYPE MokerType)
{
	m_TypeChara = CPlayer_Kangaroo::PLAYERTYPE_KANGAROO;
	CPlayerBase::Init(pos, rot, MokerType);

	m_nLife = 5;

	m_fRadius = 100.0f;
	m_fAttack = 50.0f;

	return S_OK;
}
//=============================================================================
// �I������
//=============================================================================
void CPlayer_Kangaroo::Uninit(void)
{
	CPlayerBase::Uninit();
}

//=============================================================================
// �X�V����
//=============================================================================
void CPlayer_Kangaroo::Update(void)
{
	CKeybord *pKeyboard = CManager::GetKeybord();
	MODELNUM model = GetModel();

	PlayerCollisionFloor();

	if (m_PlayerState != PLAYERSTATE_ATK)
	{
		if (GetJump() == false)
		{
			if (pKeyboard->GetKeyboardTrigger(DIK_J))
			{//�W�����v
				if (bWJump == false)
				{
					SetJump(true);
					bWJump = true;
					m_move.y += PLAYER_JUMP;
				}
			}
			else if (pKeyboard->GetKeyboardPress(DIK_A))
			{//  A �L�[����
				m_move.x += D3DX_PI*-0.5f* PLAYER_SPEED;
				m_fDiffrot.y = D3DX_PI*0.5f;
				MotionChangePlayer(MOTIONTYPE_RUN);
				if (pKeyboard->GetKeyboardTrigger(DIK_SPACE))
				{
					MotionChangePlayer(MOTIONTYPE_DASHATK);
				}
				else if (pKeyboard->GetKeyboardTrigger(DIK_B))
				{//����U���j���[�g����
					MotionChangePlayer(MOTIONTYPE_SP_N);
				}
			}
			else if (pKeyboard->GetKeyboardPress(DIK_D))
			{//  D �L�[����
				m_move.x += D3DX_PI*0.5f * PLAYER_SPEED;
				m_fDiffrot.y = D3DX_PI*-0.5f;
				MotionChangePlayer(MOTIONTYPE_RUN);
				if (pKeyboard->GetKeyboardTrigger(DIK_SPACE))
				{
					MotionChangePlayer(MOTIONTYPE_DASHATK);
				}
				else if (pKeyboard->GetKeyboardTrigger(DIK_B))
				{//����U���j���[�g����
					MotionChangePlayer(MOTIONTYPE_SP_N);
				}
			}
			else if (m_MotionType == MOTIONTYPE_RUN)
			{// �ړ�����߂��ꍇ
			 // ���[�V�����̐؂�ւ�
				MotionChangePlayer(MOTIONTYPE_WAIT);
			}

			else if (pKeyboard->GetKeyboardPress(DIK_W))
			{// W �L�[����
				if (pKeyboard->GetKeyboardTrigger(DIK_SPACE))
				{
					MotionChangePlayer(MOTIONTYPE_UPATK);
				}
				else if (pKeyboard->GetKeyboardTrigger(DIK_B))
				{//����U����
					MotionChangePlayer(MOTIONTYPE_SP_UP);
				}
			}

			else if (pKeyboard->GetKeyboardPress(DIK_S))
			{
				MotionChangePlayer(MOTIONTYPE_CROUCHWAIT);
				if (pKeyboard->GetKeyboardTrigger(DIK_SPACE))
				{
					MotionChangePlayer(MOTIONTYPE_CROUCHATK);
				}
				else if (pKeyboard->GetKeyboardTrigger(DIK_B))
				{//����U����
					MotionChangePlayer(MOTIONTYPE_SP_DOWN);
				}
			}

			else if (m_MotionType == MOTIONTYPE_CROUCHWAIT)
			{// �ړ�����߂��ꍇ
			 // ���[�V�����̐؂�ւ�
				m_MotionType = MOTIONTYPE_WAIT;
			}
			else if (pKeyboard->GetKeyboardTrigger(DIK_B))
			{//����U���j���[�g����
				MotionChangePlayer(MOTIONTYPE_SP_N);
			}
			else if (pKeyboard->GetKeyboardTrigger(DIK_SPACE))
			{
				//2�i�U��
				if (m_MotionType == MOTIONTYPE_LIGHT0)
				{
					MotionChangePlayer(MOTIONTYPE_LIGHT1);
				}
				else
				{
					MotionChangePlayer(MOTIONTYPE_LIGHT0);
				}
			}
			else if (pKeyboard->GetKeyboardPress(DIK_G))
			{
				MotionChangePlayer(MOTIONTYPE_GAUDE);
			}
		}

		//��
		else
		{
			if (m_PlayerState != PLAYERSTATE_AIRATK)
			{
				if (m_MotionType != MOTIONTYPE_DOUBLEJUMP)
				{
					MotionChangePlayer(MOTIONTYPE_JUMP);
				}
				if (bWJump == true)
				{
					if (pKeyboard->GetKeyboardTrigger(DIK_J))
					{//��i�W�����v
						MotionChangePlayer(MOTIONTYPE_DOUBLEJUMP);
						bWJump = false;
						m_move.y = 0.0f;
						m_move.y += PLAYER_AIRJUMP;
					}
				}
				if (pKeyboard->GetKeyboardPress(DIK_A))
				{//  A �L�[����
					m_move.x += D3DX_PI*-0.5f* PLAYER_AIRSPEED;

					if (pKeyboard->GetKeyboardTrigger(DIK_SPACE))
					{
						if (m_fDiffrot.y == D3DX_PI*0.5f)
						{
							m_MotionType = MOTIONTYPE_AIR_F;
						}
						else
						{
							m_MotionType = MOTIONTYPE_AIR_B;
						}
					}
				}
				else if (pKeyboard->GetKeyboardPress(DIK_D))
				{//  D �L�[����
					m_move.x += D3DX_PI*0.5f * PLAYER_AIRSPEED;
					if (pKeyboard->GetKeyboardTrigger(DIK_SPACE))
					{
						if (m_fDiffrot.y == D3DX_PI*-0.5f)
						{
							m_MotionType = MOTIONTYPE_AIR_F;
						}
						else
						{
							m_MotionType = MOTIONTYPE_AIR_B;
						}
					}
				}
				else if (pKeyboard->GetKeyboardPress(DIK_W))
				{
					if (pKeyboard->GetKeyboardTrigger(DIK_SPACE))
					{
						m_MotionType = MOTIONTYPE_AIR_U;
					}
				}
				else if (pKeyboard->GetKeyboardPress(DIK_S))
				{
					m_move.y -= 1.2f;
					if (pKeyboard->GetKeyboardTrigger(DIK_SPACE))
					{
						m_MotionType = MOTIONTYPE_AIR_D;
					}
				}
				else if (pKeyboard->GetKeyboardTrigger(DIK_SPACE))
				{
					m_MotionType = MOTIONTYPE_AIR_N;
				}
			}
		}
	}

	switch (m_MotionType)
	{
	case MOTIONTYPE_LIGHT0:
		nCountATK++;
		if (nCountATK >= LIGHT_ATK)
		{
			if (pKeyboard->GetKeyboardTrigger(DIK_SPACE))
			{
				nCountATK = 0;
				MotionChangePlayer(MOTIONTYPE_LIGHT1);
			}
		}
		break;
	case MOTIONTYPE_LIGHT1:
		nCountATK++;
		if (nCountATK >= 0 && nCountATK <= 5)
		{
			if (m_fDiffrot.y == D3DX_PI*0.5f)
			{
				m_move.x -= 1.5f;
			}
			else
			{
				m_move.x += 1.5f;
			}
		}
		break;
	case MOTIONTYPE_DASHATK:
		nCountATK++;
		if (nCountATK >= 1 && nCountATK <= 24)
		{
			if (m_fDiffrot.y == D3DX_PI*0.5f)
			{
				m_move.x -= 1.5f;
			}
			else
			{
				m_move.x += 1.5f;
			}
		}
		break;
	case MOTIONTYPE_CROUCHATK:
		nCountATK++;
		if (nCountATK >= 4 && nCountATK <= 8)
		{
			if (m_fDiffrot.y == D3DX_PI*0.5f)
			{
				m_move.x -= 3.5f;
			}
			else
			{
				m_move.x += 3.5f;
			}
		}
		break;
	case MOTIONTYPE_SP_N:
		nCountATK++;
		if (nCountATK >= 15 && nCountATK <= 38)
		{
			if (m_fDiffrot.y == D3DX_PI*0.5f)
			{
				m_move.x -= 3.5f;
			}
			else
			{
				m_move.x += 3.5f;
			}
		}
		break;
	case MOTIONTYPE_SP_UP:
		nCountATK++;
		if (nCountATK >= 4 && nCountATK <= 23)
		{
			if (m_fDiffrot.y == D3DX_PI*0.5f)
			{
				m_move.x -= 3.5f;
			}
			else
			{
				m_move.x += 3.5f;
			}
		}
		break;
	case MOTIONTYPE_AIR_N:
	case MOTIONTYPE_AIR_F:
	case MOTIONTYPE_AIR_B:
	case MOTIONTYPE_AIR_U:
	case MOTIONTYPE_AIR_D:
		if (pKeyboard->GetKeyboardPress(DIK_D))
		{
			m_move.x += D3DX_PI*0.5f* PLAYER_AIRATKSPEED;
		}
		else if (pKeyboard->GetKeyboardPress(DIK_A))
		{
			m_move.x += D3DX_PI*-0.5f* PLAYER_AIRATKSPEED;
		}
		if (pKeyboard->GetKeyboardPress(DIK_S))
		{
			m_move.y -= 1.2f;
		}
		break;
	case MOTIONTYPE_GAUDE:
		if (pKeyboard->GetKeyboardPress(DIK_G))
		{
			m_PlayerState = PLAYERSTATE_GAUDE;
		}
		else
		{
			MotionChangePlayer(MOTIONTYPE_WAIT);
		}
	}
	SetModel(model);
	CPlayerBase::Update();
}

//=============================================================================
// �`�揈��
//=============================================================================
void CPlayer_Kangaroo::Draw(void)
{
	CPlayerBase::Draw();
}