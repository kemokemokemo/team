//====================================================================================================
//
// �}�[�J�[���� (maker.cpp)
// Author (Kimura kouta)
//
//====================================================================================================
#include "maker.h"
#include "renderer.h"
#include "manager.h"
#include "Game.h"
#include "playerbase.h"
#include "player_Ken.h"

//====================================================================================================
// �}�N����`
//====================================================================================================
#define BULLET_SIZE (40)
#define MAX_LIFE (40)
#define MAKERTEX_01 "DATA/TEX/1p.png"					//�ǂݍ��ރe�N�X�`���t�@�C����
#define MAKERTEX_02 "DATA/TEX/2p.png"					//�ǂݍ��ރe�N�X�`���t�@�C����

//====================================================================================================
// �v���g�^�C�v�錾
//====================================================================================================

//====================================================================================================
// �O���[�o���ϐ�
//====================================================================================================
LPDIRECT3DTEXTURE9 CMaker::m_pTextureMaker[MAX_TEXMAKER] = {};

//====================================================================================================
// �R���X�g���N�^
//====================================================================================================
CMaker::CMaker(OBJTYPE type) : CBillboard(type)
{
}
//=============================================================================
// ����������
//=============================================================================
HRESULT CMaker::Init(D3DXVECTOR3 pos, MAKERTYPE makertype,int life)
{
	CBillboard::Init();

	SetPos(pos);
	CBillboard::SetSize(100.0f, 70.0f, 0.0f);
	CBillboard::SetColor(D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f));
	m_nLife = life;
	MakerType = makertype;

	return S_OK;
}

//==================================================================================================
//�I������
//===================================================================================================
void CMaker::Uninit(void)
{
	CBillboard::Uninit();
}

//====================================================================================================
//�X�V����
//=====================================================================================================
void CMaker::Update(void)
{
	CBillboard::Update();

	for (int nCntModel = 0; nCntModel < MAX_POLYGON; nCntModel++)
	{
		CScene *pScene;

		pScene = CScene::GetScene(OBJTYPE_PLAYER, nCntModel);

		if (!pScene)
			continue;

		CPlayerBase *pPlayer = (CPlayerBase*)pScene;

		D3DXVECTOR3 pos;

		if (pPlayer->GetMaker() == MakerType)
		{

			D3DXVECTOR3 posp = pPlayer->GetPos();

			pos = posp;
			CBillboard::SetPos(D3DXVECTOR3(pos.x, pos.y + 200.0f, pos.z));

			break;
		}
	}
	if (m_nLife <= 0)
	{
		Release();
	}

}
//========================================================================================================
// �`�揈��
//========================================================================================================
CMaker *CMaker::Create(D3DXVECTOR3 pos, MAKERTYPE makertype, int life)
{
	CMaker *pMaker;

	pMaker = new CMaker(OBJTYPE_ANIMATION);

	pMaker->BindTexture(m_pTextureMaker[makertype]);

	pMaker->Init(pos, makertype, life);

	return pMaker;
}

//========================================================================================================
// �e�N�X�`���̓ǂݍ���
//========================================================================================================
HRESULT CMaker::Load(void)
{
	CRenderer *pRenderer = CManager::GetRenderer();
	LPDIRECT3DDEVICE9 pDevice = pRenderer->GetDevice();

	//�e�N�X�`���̓ǂݍ���
	D3DXCreateTextureFromFile(
		pDevice,
		MAKERTEX_01,
		&m_pTextureMaker[MAKERTYPE_1P]);

	//�e�N�X�`���̓ǂݍ���
	D3DXCreateTextureFromFile(
		pDevice,
		MAKERTEX_02,
		&m_pTextureMaker[MAKERTYPE_2P]);

	return S_OK;
}
//=======================================================================================================
// �e�N�X�`���̔j��
//========================================================================================================
void CMaker::Unload(void)
{
	for (int nCnt =0; nCnt < MAX_TEXMAKER; nCnt++)
	{
		// ���_�o�b�t�@�̊J��
		if (m_pTextureMaker[nCnt] != NULL)
		{
			m_pTextureMaker[nCnt]->Release();
			m_pTextureMaker[nCnt] = NULL;
		}
	}
}

void CMaker::MakerLife(int nDamage)
{
	m_nLife -= nDamage;
}

int CMaker::GetMakerLife()
{
	return m_nLife;
}

//========================================================================================================
// �`�揈��
//========================================================================================================
void CMaker::Draw(void)
{
	CBillboard::Draw();
}

//====================================================================================================
// �f�X�g���N�^
//=====================================================================================================
CMaker::~CMaker()
{

}