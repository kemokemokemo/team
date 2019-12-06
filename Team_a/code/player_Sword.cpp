//=============================================================================
//
// �v���C���[���� [player.cpp]
// Author : KOUTA KIMURA
//
//=============================================================================

//=============================================================================
// �C���N���[�h�t�@�C��
//=============================================================================
#include "player_Sword.h"
#include "camera.h"
#include "manager.h"
#include "renderer.h"
#include "keybord.h"
#include "pad.h"
#include "gauge.h"
#include "Scene2D.h"
#include "Scene3D.h"
#include "model.h"

//=============================================================================
// �}�N����`
//=============================================================================
#define PLAYER_SPEED	(1.8f)						//�v���C���[�̑���
#define PLAYER_AIRSPEED	(1.5f)						//�󒆂ł̃v���C���[�̑���
#define PLAYER_JUMP (60.0f)						//�W�����v�̍���
#define PLAYER_AIRJUMP (50.0f)					//�󒆃W�����v�̍���

//=============================================================================
// �����o�ϐ�������
//=============================================================================

//=============================================================================
// �R���X�g���N�^
//=============================================================================
CPlayer_SWORD::CPlayer_SWORD(OBJTYPE type) : CPlayerBase(type)
{

}

//=============================================================================
// �f�X�g���N�^
//=============================================================================
CPlayer_SWORD::~CPlayer_SWORD()
{

}

//=============================================================================
// ���f���̐���
//=============================================================================
CPlayer_SWORD * CPlayer_SWORD::Create(D3DXVECTOR3 pos, D3DXVECTOR3 rot)
{
	CPlayer_SWORD *pPlayer;
	pPlayer = new CPlayer_SWORD(OBJTYPE_PLAYER);

	pPlayer->Init(pos, rot);
	return pPlayer;
}

//=============================================================================
// ����������
//=============================================================================
HRESULT CPlayer_SWORD::Init(D3DXVECTOR3 pos, D3DXVECTOR3 rot)
{
	m_TypeChara = CPlayer_SWORD::PLAYERTYPE_SWORD;
	CPlayerBase::Init(pos, rot);

	m_nLife = 12;
	m_fRadius = 50.0f;
	m_fAttack = 30.0f;

	return S_OK;
}
//=============================================================================
// �I������
//=============================================================================
void CPlayer_SWORD::Uninit(void)
{
	CPlayerBase::Uninit();
}

//=============================================================================
// �X�V����
//=============================================================================
void CPlayer_SWORD::Update(void)
{
	CKeybord *pKeyboard = CManager::GetKeybord();
	MODELNUM model = GetModel();

	PlayerCollisionFloor();

	if (m_PlayerState != PLAYERSTATE_ATK)
	{
		//��
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
			else if (pKeyboard->GetKeyboardPress(DIK_LEFTARROW))
			{//  A �L�[����
				m_move.x += D3DX_PI*-0.5f* PLAYER_SPEED;
				m_fDiffrot.y = D3DX_PI*0.5f;
				MotionChangePlayer(MOTIONTYPE_RUN);

				if (pKeyboard->GetKeyboardTrigger(DIK_L))
				{
					MotionChangePlayer(MOTIONTYPE_DASHATK);
				}
				else if (pKeyboard->GetKeyboardTrigger(DIK_K))
				{//����U���j���[�g����
					MotionChangePlayer(MOTIONTYPE_SP_N);
				}
			}
			else if (pKeyboard->GetKeyboardPress(DIK_RIGHTARROW))
			{//  D �L�[����
				m_move.x += D3DX_PI*0.5f * PLAYER_SPEED;
				m_fDiffrot.y = D3DX_PI*-0.5f;
				MotionChangePlayer(MOTIONTYPE_RUN);
				if (pKeyboard->GetKeyboardTrigger(DIK_L))
				{
					MotionChangePlayer(MOTIONTYPE_DASHATK);
				}
				else if (pKeyboard->GetKeyboardTrigger(DIK_K))
				{//����U���j���[�g����
					MotionChangePlayer(MOTIONTYPE_SP_N);
				}
			}
			else if (MotionType == MOTIONTYPE_RUN)
			{// �ړ�����߂��ꍇ
			 // ���[�V�����̐؂�ւ�
				MotionChangePlayer(MOTIONTYPE_WAIT);
			}

			else if (pKeyboard->GetKeyboardPress(DIK_UPARROW))
			{// W �L�[����
				if (pKeyboard->GetKeyboardTrigger(DIK_L))
				{
					MotionChangePlayer(MOTIONTYPE_UPATK);
				}
				else if (pKeyboard->GetKeyboardTrigger(DIK_K))
				{//����U����
					MotionChangePlayer(MOTIONTYPE_SP_UP);
				}
			}

			else if (pKeyboard->GetKeyboardPress(DIK_DOWNARROW))
			{
				MotionChangePlayer(MOTIONTYPE_CROUCHWAIT);
				if (pKeyboard->GetKeyboardTrigger(DIK_L))
				{
					MotionChangePlayer(MOTIONTYPE_CROUCHATK);
				}
				else if (pKeyboard->GetKeyboardTrigger(DIK_K))
				{//����U����
					MotionChangePlayer(MOTIONTYPE_SP_DOWN);
				}
			}

			else if (MotionType == MOTIONTYPE_CROUCHWAIT)
			{// �ړ�����߂��ꍇ
			 // ���[�V�����̐؂�ւ�
				MotionChangePlayer(MOTIONTYPE_WAIT);
			}
			else if (pKeyboard->GetKeyboardTrigger(DIK_K))
			{//����U���j���[�g����
				MotionChangePlayer(MOTIONTYPE_SP_N);
			}
			else if (pKeyboard->GetKeyboardTrigger(DIK_L))
			{
				//3�i�U��
				if (MotionType == MOTIONTYPE_LIGHT0)
				{
					MotionChangePlayer(MOTIONTYPE_LIGHT1);
				}
				else if (MotionType == MOTIONTYPE_LIGHT1)
				{
					MotionChangePlayer(MOTIONTYPE_LIGHT2);
				}
				else
				{
					MotionChangePlayer(MOTIONTYPE_LIGHT0);
				}
			}
		}

		//��
		else
		{
			if (MotionType != MOTIONTYPE_DOUBLEJUMP)
			{
				MotionChangePlayer(MOTIONTYPE_JUMP);
			}
			if (bWJump == true)
			{
				if (pKeyboard->GetKeyboardTrigger(DIK_J))
				{//��i�W�����v
					MotionChangePlayer(MOTIONTYPE_DOUBLEJUMP);
					bWJump = false;
					m_move.y += PLAYER_AIRJUMP;
				}
			}
			if (pKeyboard->GetKeyboardPress(DIK_LEFTARROW))
			{//  A �L�[����
				m_move.x += D3DX_PI*-0.5f* PLAYER_AIRSPEED;

				if (pKeyboard->GetKeyboardTrigger(DIK_L))
				{
					if (m_fDiffrot.y == D3DX_PI*0.5f)
					{
						MotionChangePlayer(MOTIONTYPE_AIR_F);
					}
					else
					{
						MotionChangePlayer(MOTIONTYPE_AIR_B);
					}
				}
			}
			else if (pKeyboard->GetKeyboardPress(DIK_RIGHTARROW))
			{//  D �L�[����
				m_move.x += D3DX_PI*0.5f * PLAYER_AIRSPEED;
				if (pKeyboard->GetKeyboardTrigger(DIK_L))
				{
					if (m_fDiffrot.y == D3DX_PI*-0.5f)
					{
						MotionChangePlayer(MOTIONTYPE_AIR_F);
					}
					else
					{
						MotionChangePlayer(MOTIONTYPE_AIR_B);
					}
				}
			}
			else if (pKeyboard->GetKeyboardPress(DIK_UPARROW))
			{
				if (pKeyboard->GetKeyboardTrigger(DIK_L))
				{
					MotionChangePlayer(MOTIONTYPE_AIR_U);
				}
			}
			else if (pKeyboard->GetKeyboardPress(DIK_DOWNARROW))
			{
				if (pKeyboard->GetKeyboardTrigger(DIK_L))
				{
					MotionChangePlayer(MOTIONTYPE_AIR_D);
				}
			}
			else if (pKeyboard->GetKeyboardTrigger(DIK_L))
			{
				MotionChangePlayer(MOTIONTYPE_AIR_N);
			}
		}
	}

	switch (MotionType)
	{
		break;
	case MOTIONTYPE_DASHATK:
		if (m_fDiffrot.y == D3DX_PI*0.5f)
		{
			m_move.x -= 0.7f;
		}
		else
		{
			m_move.x += 0.7f;
		}
		break;

	case MOTIONTYPE_SP_N:
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
	}
	SetModel(model);

	CPlayerBase::Update();
}

//=============================================================================
// �`�揈��
//=============================================================================
void CPlayer_SWORD::Draw(void)
{
	CPlayerBase::Draw();
}