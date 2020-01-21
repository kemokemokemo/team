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
#define ROOPLAYER_SPEED	(1.5f)					//�v���C���[�̑���
#define ROOPLAYER_AIRSPEED	(1.5f)					//�󒆂ł̃v���C���[�̑���
#define ROOPLAYER_AIRATKSPEED	(0.5f)					//�󒆂ł̃v���C���[�̑���
#define ROOPLAYER_JUMP (120.0f)					//�W�����v�̍���
#define ROOPLAYER_AIRJUMP (90.0f)					//�󒆃W�����v�̍���
#define ROOLIGHT_ATK (9)					//��U���ɔh���ł���t���[��

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
	m_nLife = 100;

	m_TypeChara = CPlayer_Kangaroo::PLAYERTYPE_KANGAROO;
	CPlayerBase::Init(pos, rot, m_nLife, MokerType);

	m_fRadius = 60.0f;
	m_fAttack = 60.0f;

	m_fSpeed = ROOPLAYER_SPEED;
	m_fAirSpeed = ROOPLAYER_AIRSPEED;
	m_fAirAtkSpeed = ROOPLAYER_AIRATKSPEED;
	m_fJump = ROOPLAYER_JUMP;
	m_fAirJump = ROOPLAYER_AIRJUMP;
	m_fLightAtk = ROOLIGHT_ATK;

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
	CPlayerBase::Update();
}

//=============================================================================
// �`�揈��
//=============================================================================
void CPlayer_Kangaroo::Draw(void)
{
	CPlayerBase::Draw();
}