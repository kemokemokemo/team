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
	m_nLife = 100;
	m_TypeChara = CPlayer_SWORD::PLAYERTYPE_SWORD;
	CPlayerBase::Init(pos, rot, m_nLife, MokerType);
	m_fDiffrot.y = D3DX_PI*0.5f;

	m_fRadius = 25.0f;
	m_fAttack = 50.0f;

	m_fSpeed = PLAYER_SPEED;
	m_fAirSpeed = PLAYER_AIRSPEED;
	m_fAirAtkSpeed = PLAYER_AIRATKSPEED;
	m_fJump = PLAYER_JUMP;
	m_fAirJump = PLAYER_AIRJUMP;
	m_fLightAtk = LIGHT_ATK;


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
	CPlayerBase::Update();
}

//=============================================================================
// �`�揈��
//=============================================================================
void CPlayer_SWORD::Draw(void)
{
	CPlayerBase::Draw();
}