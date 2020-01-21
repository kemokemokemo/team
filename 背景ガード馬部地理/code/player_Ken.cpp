//=============================================================================
//
// �v���C���[���� [player.cpp]
// Author : KOUTA KIMURA
//
//=============================================================================

//=============================================================================
// �C���N���[�h�t�@�C��
//=============================================================================
#include "player_ken.h"
#include "camera.h"
#include "manager.h"
#include "renderer.h"
#include "keybord.h"
#include "pad.h"
#include "gauge.h"
#include "Scene2D.h"
#include "model.h"

//=============================================================================
// �}�N����`
//===========================================================================
#define KPLAYER_SPEED	(2.0f)					//�v���C���[�̑���
#define KPLAYER_AIRSPEED	(1.8f)					//�󒆂ł̃v���C���[�̑���
#define KPLAYER_AIRATKSPEED	(0.8f)					//�󒆂ł̃v���C���[�̑���
#define KPLAYER_JUMP (100.0f)					//�W�����v�̍���
#define KPLAYER_AIRJUMP (80.0f)					//�󒆃W�����v�̍���
#define KLIGHT_ATK (9)					//��U���ɔh���ł���t���[��

//=============================================================================
// �����o�ϐ�������
//=============================================================================

//=============================================================================
// �R���X�g���N�^
//=============================================================================
CPlayer_KEN::CPlayer_KEN(OBJTYPE type) : CPlayerBase(type)
{

}

//=============================================================================
// �f�X�g���N�^
//=============================================================================
CPlayer_KEN::~CPlayer_KEN()
{

}

//=============================================================================
// ���f���̐���
//=============================================================================
CPlayer_KEN * CPlayer_KEN::Create(D3DXVECTOR3 pos, D3DXVECTOR3 rot, CMaker::MAKERTYPE MokerType)
{
	CPlayer_KEN *pPlayer;
	pPlayer = new CPlayer_KEN(OBJTYPE_PLAYER);

	pPlayer->Init(pos, rot, MokerType);
	return pPlayer;
}

//=============================================================================
// ����������
//=============================================================================
HRESULT CPlayer_KEN::Init(D3DXVECTOR3 pos, D3DXVECTOR3 rot, CMaker::MAKERTYPE MokerType)
{
	m_nLife = 100;

	m_TypeChara = CPlayer_KEN::PLAYERTYPE_KEN;
	CPlayerBase::Init(pos, rot, m_nLife, MokerType);


	m_fDiffrot.y = D3DX_PI*-0.5f;
	m_fRadius = 15.0f;
	m_fAttack = 30.0f;

	m_fSpeed = KPLAYER_SPEED;
	m_fAirSpeed = KPLAYER_AIRSPEED;
	m_fAirAtkSpeed = KPLAYER_AIRATKSPEED;
	m_fJump = KPLAYER_JUMP;
	m_fAirJump = KPLAYER_AIRJUMP;
	m_fLightAtk = KLIGHT_ATK;



	return S_OK;
}
//=============================================================================
// �I������
//=============================================================================
void CPlayer_KEN::Uninit(void)
{
	CPlayerBase::Uninit();
}

//=============================================================================
// �X�V����
//=============================================================================
void CPlayer_KEN::Update(void)
{
	CPlayerBase::Update();
}

//=============================================================================
// �`�揈��
//=============================================================================
void CPlayer_KEN::Draw(void)
{
	CPlayerBase::Draw();
}