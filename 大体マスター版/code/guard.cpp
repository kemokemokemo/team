//====================================================================================================
//
// �K�[�h���� (guard.cpp)
// Author (Kimura kouta)
//
//====================================================================================================
#include "maker.h"
#include "renderer.h"
#include "manager.h"
#include "Game.h"
#include "playerbase.h"
#include "player_Ken.h"
#include "guard.h"

//====================================================================================================
// �}�N����`
//====================================================================================================
#define BULLET_SIZE (40)
#define MAX_LIFE (40)
#define TEX_01 "DATA/TEX/gaude.png"					//�ǂݍ��ރe�N�X�`���t�@�C����

//====================================================================================================
// �v���g�^�C�v�錾
//====================================================================================================

//====================================================================================================
// �O���[�o���ϐ�
//====================================================================================================
LPDIRECT3DTEXTURE9 CGuard::m_pTextureGuard[1] = {};

//====================================================================================================
// �R���X�g���N�^
//====================================================================================================
CGuard::CGuard(OBJTYPE type) : CBillboard(type)
{
}
//=============================================================================
// ����������
//=============================================================================
HRESULT CGuard::Init(D3DXVECTOR3 pos, int Life, CMaker::MAKERTYPE makertype)
{
	CBillboard::Init();

	SetPos(pos);
	Size = 100.0f;
	CBillboard::SetSize(Size, Size, 0.0f);

	if (makertype == CMaker::MAKERTYPE_1P)
	{
		CBillboard::SetColor(D3DXCOLOR(1.0f, 0.0f, 0.0f, 0.5f));
	}

	if (makertype == CMaker::MAKERTYPE_2P)
	{
		CBillboard::SetColor(D3DXCOLOR(0.0f, 0.0f, 1.0f, 0.5f));
	}

	m_nLife = Life;
	Makertype = makertype;

	return S_OK;
}


//==================================================================================================
//�I������
//===================================================================================================
void CGuard::Uninit(void)
{
	CBillboard::Uninit();
}

//====================================================================================================
//�X�V����
//=====================================================================================================
void CGuard::Update(void)
{
	CBillboard::Update();

	for (int nCntModel = 0; nCntModel < MAX_POLYGON; nCntModel++)
	{
		CScene *pScene;

		pScene = CScene::GetScene(OBJTYPE_PLAYER, nCntModel);

		if (!pScene)
			continue;

		CPlayerBase *pPlayer = (CPlayerBase*)pScene;

		if (pPlayer->GetMaker() == Makertype)
		{
			D3DXVECTOR3 pos = CBillboard::GetPos();

			D3DXVECTOR3 posm = pPlayer->GetPos();

			pos = posm;
			CBillboard::SetPos(D3DXVECTOR3(pos.x, pos.y + 80.0f, pos.z));
		}
	}

	if (m_nLife <= 0)
	{
		m_nLife = 0;
	}


	if (m_nLife != m_nLifeOld)
	{
		Size -= 10;
		m_nLifeOld = m_nLife;
	}
	CBillboard::SetSize(Size, Size, 0.0f);

}
//========================================================================================================
// �`�揈��
//========================================================================================================
CGuard *CGuard::Create(D3DXVECTOR3 pos, int Life, CMaker::MAKERTYPE makertype)
{
	CGuard *pGuard;

	pGuard = new CGuard(OBJTYPE_ANIMATION);

	pGuard->BindTexture(m_pTextureGuard[0]);

	pGuard->Init(pos, Life, makertype);

	return pGuard;
}

//========================================================================================================
// �e�N�X�`���̓ǂݍ���
//========================================================================================================
HRESULT CGuard::Load(void)
{
	CRenderer *pRenderer = CManager::GetRenderer();
	LPDIRECT3DDEVICE9 pDevice = pRenderer->GetDevice();

	//�e�N�X�`���̓ǂݍ���
	D3DXCreateTextureFromFile(
		pDevice,
		TEX_01,
		&m_pTextureGuard[0]);


	return S_OK;
}
//=======================================================================================================
// �e�N�X�`���̔j��
//========================================================================================================
void CGuard::Unload(void)
{
	// ���_�o�b�t�@�̊J��
	if (m_pTextureGuard[0] != NULL)
	{
		m_pTextureGuard[0]->Release();
		m_pTextureGuard[0] = NULL;
	}
}

//========================================================================================================
// �`�揈��
//========================================================================================================
void CGuard::GuardLife(int nDamage)
{
	m_nLifeOld = m_nLife;

	m_nLife -= nDamage;
}

int CGuard::GetGuardLife()
{
	return m_nLife;
}

//========================================================================================================
// �`�揈��
//========================================================================================================
void CGuard::Draw(void)
{
	CBillboard::Draw();
}

//====================================================================================================
// �f�X�g���N�^
//=====================================================================================================
CGuard::~CGuard()
{

}