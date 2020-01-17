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
#define PLAYER_AIRATKSPEED	(0.7f)						//�󒆂ł̃v���C���[�̑���
#define PLAYER_JUMP (90.0f)						//�W�����v�̍���
#define PLAYER_AIRJUMP (60.0f)					//�󒆃W�����v�̍���
#define LIGHT_ATK (9)					//��U���ɔh���ł���t���[��

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
CPlayer_SWORD * CPlayer_SWORD::Create(D3DXVECTOR3 pos, D3DXVECTOR3 rot, CMaker::MAKERTYPE MokerType)
{
	CPlayer_SWORD *pPlayer;
	pPlayer = new CPlayer_SWORD(OBJTYPE_PLAYER);

	pPlayer->Init(pos, rot, MokerType);
	return pPlayer;
}

//=============================================================================
// ����������
//=============================================================================
HRESULT CPlayer_SWORD::Init(D3DXVECTOR3 pos, D3DXVECTOR3 rot, CMaker::MAKERTYPE MokerType)
{
	m_TypeChara = CPlayer_SWORD::PLAYERTYPE_SWORD;
	CPlayerBase::Init(pos, rot, MokerType);
	m_fDiffrot.y = D3DX_PI*0.5f;
	m_nLife = 12;
	m_fRadius = 25.0f;
	m_fAttack = 50.0f;


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
	CPad *pGamePad = CManager::GetPad();
	MODELNUM model = GetModel();

	PlayerCollisionFloor();

	if (m_PlayerState != PLAYERSTATE_ATK)
	{
		//��
		if (GetJump() == false)
		{
			if (pKeyboard->GetKeyboardTrigger(DIK_I) || pGamePad->GetJoypadTrigger(0, CPad::JOYPADKEY_Y))
			{//�W�����v
				if (bWJump == false)
				{
					SetJump(true);
					bWJump = true;
					m_move.y += PLAYER_JUMP;
				}
			}
			else if (pKeyboard->GetKeyboardPress(DIK_LEFTARROW) || pGamePad->GetJoypadPress(0, CPad::JOYPADKEY_LEFT))
			{//  A �L�[����
				m_move.x += D3DX_PI*-0.5f* PLAYER_SPEED;
				m_fDiffrot.y = D3DX_PI*0.5f;
				MotionChangePlayer(MOTIONTYPE_RUN);

				if (pKeyboard->GetKeyboardTrigger(DIK_L) || pGamePad->GetJoypadPress(0, CPad::JOYPADKEY_B))
				{
					MotionChangePlayer(MOTIONTYPE_DASHATK);
				}
				else if (pKeyboard->GetKeyboardTrigger(DIK_K) || pGamePad->GetJoypadTrigger(0, CPad::JOYPADKEY_A))
				{//����U���j���[�g����
					MotionChangePlayer(MOTIONTYPE_SP_N);
				}
			}
			else if (pKeyboard->GetKeyboardPress(DIK_RIGHTARROW) || pGamePad->GetJoypadPress(0, CPad::JOYPADKEY_RIGHT))
			{//  D �L�[����
				m_move.x += D3DX_PI*0.5f * PLAYER_SPEED;
				m_fDiffrot.y = D3DX_PI*-0.5f;
				MotionChangePlayer(MOTIONTYPE_RUN);
				if (pKeyboard->GetKeyboardTrigger(DIK_L) || pGamePad->GetJoypadTrigger(0, CPad::JOYPADKEY_B))
				{
					MotionChangePlayer(MOTIONTYPE_DASHATK);
				}
				else if (pKeyboard->GetKeyboardTrigger(DIK_K) || pGamePad->GetJoypadTrigger(0, CPad::JOYPADKEY_A))
				{//����U���j���[�g����
					MotionChangePlayer(MOTIONTYPE_SP_N);
				}
			}
			else if (m_MotionType == MOTIONTYPE_RUN)
			{// �ړ�����߂��ꍇ
			 // ���[�V�����̐؂�ւ�
				MotionChangePlayer(MOTIONTYPE_WAIT);
			}

			else if (pKeyboard->GetKeyboardPress(DIK_UPARROW) || pGamePad->GetJoypadPress(0, CPad::JOYPADKEY_UP))
			{// W �L�[����
				if (pKeyboard->GetKeyboardTrigger(DIK_L) || pGamePad->GetJoypadTrigger(0, CPad::JOYPADKEY_B))
				{
					MotionChangePlayer(MOTIONTYPE_UPATK);
				}
				else if (pKeyboard->GetKeyboardTrigger(DIK_K) || pGamePad->GetJoypadTrigger(0, CPad::JOYPADKEY_A))
				{//����U����
					MotionChangePlayer(MOTIONTYPE_SP_UP);
				}
			}

			else if (pKeyboard->GetKeyboardPress(DIK_DOWNARROW) || pGamePad->GetJoypadPress(0, CPad::JOYPADKEY_DOWN))
			{
				MotionChangePlayer(MOTIONTYPE_CROUCHWAIT);
				if (pKeyboard->GetKeyboardTrigger(DIK_L) || pGamePad->GetJoypadTrigger(0, CPad::JOYPADKEY_B))
				{
					MotionChangePlayer(MOTIONTYPE_CROUCHATK);
				}
				else if (pKeyboard->GetKeyboardTrigger(DIK_K) || pGamePad->GetJoypadTrigger(0, CPad::JOYPADKEY_A))
				{//����U����
					MotionChangePlayer(MOTIONTYPE_SP_DOWN);
				}
			}

			else if (m_MotionType == MOTIONTYPE_CROUCHWAIT)
			{// �ړ�����߂��ꍇ
			 // ���[�V�����̐؂�ւ�
				MotionChangePlayer(MOTIONTYPE_WAIT);
			}
			else if (pKeyboard->GetKeyboardTrigger(DIK_K) || pGamePad->GetJoypadTrigger(0, CPad::JOYPADKEY_A))
			{//����U���j���[�g����
				MotionChangePlayer(MOTIONTYPE_SP_N);
			}
			else if (pKeyboard->GetKeyboardTrigger(DIK_L) || pGamePad->GetJoypadTrigger(0, CPad::JOYPADKEY_B))
			{
				MotionChangePlayer(MOTIONTYPE_LIGHT0);
			}
			else if (pGamePad->GetJoypadPress(0, CPad::JOYPADKEY_X))
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
					if (pKeyboard->GetKeyboardTrigger(DIK_I) || pGamePad->GetJoypadTrigger(0, CPad::JOYPADKEY_Y))
					{//��i�W�����v
						MotionChangePlayer(MOTIONTYPE_DOUBLEJUMP);
						bWJump = false;
						m_move.y = 0.0f;
						m_move.y += PLAYER_AIRJUMP;
					}
				}
				if (pKeyboard->GetKeyboardPress(DIK_LEFTARROW) || pGamePad->GetJoypadPress(0, CPad::JOYPADKEY_LEFT))
				{//  A �L�[����
					m_move.x += D3DX_PI*-0.5f* PLAYER_AIRSPEED;

					if (pKeyboard->GetKeyboardTrigger(DIK_L) || pGamePad->GetJoypadTrigger(0, CPad::JOYPADKEY_B))
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
				else if (pKeyboard->GetKeyboardPress(DIK_RIGHTARROW) || pGamePad->GetJoypadPress(0, CPad::JOYPADKEY_RIGHT))
				{//  D �L�[����
					m_move.x += D3DX_PI*0.5f * PLAYER_AIRSPEED;
					if (pKeyboard->GetKeyboardTrigger(DIK_L) || pGamePad->GetJoypadTrigger(0, CPad::JOYPADKEY_B))
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
				else if (pKeyboard->GetKeyboardPress(DIK_UPARROW) || pGamePad->GetJoypadPress(0, CPad::JOYPADKEY_UP))
				{
					if (pKeyboard->GetKeyboardTrigger(DIK_L) || pGamePad->GetJoypadTrigger(0, CPad::JOYPADKEY_B))
					{
						MotionChangePlayer(MOTIONTYPE_AIR_U);
					}
				}
				else if (pKeyboard->GetKeyboardPress(DIK_DOWNARROW) || pGamePad->GetJoypadPress(0, CPad::JOYPADKEY_DOWN))
				{
					m_move.y -= 1.2f;
					if (pKeyboard->GetKeyboardTrigger(DIK_L) || pGamePad->GetJoypadTrigger(0, CPad::JOYPADKEY_B))
					{
						MotionChangePlayer(MOTIONTYPE_AIR_D);
					}
				}
				else if (pKeyboard->GetKeyboardTrigger(DIK_L) || pGamePad->GetJoypadTrigger(0, CPad::JOYPADKEY_B))
				{
					MotionChangePlayer(MOTIONTYPE_AIR_N);
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
			if (pKeyboard->GetKeyboardTrigger(DIK_L) || pGamePad->GetJoypadTrigger(0, CPad::JOYPADKEY_B))
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
		if (nCountATK >= LIGHT_ATK)
		{
			if (pKeyboard->GetKeyboardTrigger(DIK_L) || pGamePad->GetJoypadTrigger(0, CPad::JOYPADKEY_B))
			{
				nCountATK = 0;
				MotionChangePlayer(MOTIONTYPE_LIGHT2);
			}
		}
		break;
	case MOTIONTYPE_LIGHT2:
		nCountATK++;
		if (nCountATK >= 0 && nCountATK <= 5)
		{
			if (m_fDiffrot.y == D3DX_PI*0.5f)
			{
				m_move.x -= 2.5f;
			}
			else
			{
				m_move.x += 2.5f;
			}
		}

		break;
	case MOTIONTYPE_DASHATK:
		nCountATK++;
		if (nCountATK >= 1 && nCountATK <= 40)
		{
			if (m_fDiffrot.y == D3DX_PI*0.5f)
			{
				m_move.x -= 0.9f;
			}
			else
			{
				m_move.x += 0.9f;
			}
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
	case MOTIONTYPE_AIR_N:
	case MOTIONTYPE_AIR_F:
	case MOTIONTYPE_AIR_B:
	case MOTIONTYPE_AIR_U:
	case MOTIONTYPE_AIR_D:
		if (pGamePad->GetJoypadPress(0, CPad::JOYPADKEY_RIGHT))
		{
			m_move.x += D3DX_PI*0.5f* PLAYER_AIRATKSPEED;
		}
		else if (pGamePad->GetJoypadPress(0, CPad::JOYPADKEY_LEFT))
		{
			m_move.x += D3DX_PI*-0.5f* PLAYER_AIRATKSPEED;
		}
		if (pKeyboard->GetKeyboardPress(DIK_S) || pGamePad->GetJoypadPress(0, CPad::JOYPADKEY_DOWN))
		{
			m_move.y -= 1.2f;
		}
		break;
	case MOTIONTYPE_GAUDE:
		if (pGamePad->GetJoypadPress(0, CPad::JOYPADKEY_X))
		{
			m_PlayerState = PLAYERSTATE_GAUDE;
		}
		else
		{
			MotionChangePlayer(MOTIONTYPE_WAIT);
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