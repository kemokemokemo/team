//====================================================================================================
//
// �e���� (bullet.cpp)
// Author (Kimura kouta)
//
//====================================================================================================
#include "bullet.h"
#include "renderer.h"
#include "manager.h"
#include "effect.h"
#include "Game.h"

//====================================================================================================
// �}�N����`
//====================================================================================================
#define BULLET_TEX "DATA/TEX/hadoken.png"
#define BULLET_TEX2 "DATA/TEX/gaude.png"				//�ǂݍ��ރe�N�X�`���t�@�C����
#define BULLET_SIZE (1)
#define MAX_LIFE (40)

//====================================================================================================
// �v���g�^�C�v�錾
//====================================================================================================

//====================================================================================================
// �O���[�o���ϐ�
//====================================================================================================
LPDIRECT3DTEXTURE9 CBullet::m_pTextureBullet[MAX_TEXBULLET] = {};

//====================================================================================================
// �R���X�g���N�^
//====================================================================================================
CBullet::CBullet(OBJTYPE type) : CBillboard(type)
{
	m_move = D3DXVECTOR3(0.0f,0.0f,0.0f);
	m_pos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	m_nLife = 0;
}

//=============================================================================
// ����������
//=============================================================================
HRESULT CBullet::Init(D3DXVECTOR3 pos, D3DXVECTOR3 move, BULLETTEX BulletTex, CMaker::MAKERTYPE makertype, int nLife)
{
	CBillboard::Init();

	SetPos(pos);
	SetMove(move);
	m_nLife = nLife;
	m_BulletTex = BulletTex;
	m_MakerType = makertype;


	switch (BulletTex)
	{
	case BULLETTEX_KEN:

		CBillboard::SetSize(70.0f, 70.0f, 0.0f);
		CBillboard::SetColor(D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f));
		break;

	case BULLETTEX_KANGAROO:

		CBillboard::SetSize(70.0f, 70.0f, 0.0f);
		CBillboard::SetColor(D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f));

		break;
	}

	return S_OK;
}

//==================================================================================================
//�I������
//===================================================================================================
void CBullet::Uninit(void)
{
	CBillboard::Uninit();
}

//====================================================================================================
//�X�V����
//=====================================================================================================
void CBullet::Update(void)
{
	CBillboard::Update();

	////�|�W�V�����̎擾
	m_pos = CBillboard::GetPos();

	////�ړ�����
	m_pos += m_move;

	//���C�t�̃J�E���g
	m_nLife--;

	if (m_nLife <= 0)
	{
		Release();
	}

	PlayerCollision();

	SetPos(m_pos);
}

//========================================================================================================
// �e�ƃv���C���[�̓����蔻��
//========================================================================================================
void CBullet::PlayerCollision()
{
	//�ϐ��錾
	D3DXVECTOR3 PosP;
	//���a
	float fRadiusE = 100 / 2;
	float fRadiusP = 20 / 2;

	for (int nCntScene = 0; nCntScene < 256; nCntScene++)
	{
		for (int nCntModel = 0; nCntModel < MAX_POLYGON; nCntModel++)
		{
			CScene *pScene;

			pScene = CScene::GetScene(OBJTYPE_PLAYER, nCntModel);

			if (!pScene)
				continue;

			CPlayerBase *pPlayer = (CPlayerBase*)pScene;

			D3DXVECTOR3 pos;

			PosP = ((CPlayerBase*)pScene)->GetPos();

			if (pPlayer->GetMaker() != m_MakerType)
			{
				//�~�̓����蔻��
				if ((m_pos.x - PosP.x) * (m_pos.x - PosP.x) + (m_pos.y - PosP.y) * (m_pos.y - PosP.y) <= (fRadiusP + fRadiusE) * (fRadiusP + fRadiusE))
				{
					((CPlayerBase*)pScene)->Damage(pPlayer, 1);

					Release();
				}
			}
		}
	}
}

//========================================================================================================
// �ړ�����
//========================================================================================================
void CBullet::SetMove(D3DXVECTOR3 move)
{
	m_move = move;
}

//========================================================================================================
// �̗͂̎擾
//========================================================================================================
int CBullet::GetLife()
{
	return m_nLife;
}

//========================================================================================================
// �`�揈��
//========================================================================================================
CBullet *CBullet::Create(D3DXVECTOR3 pos, D3DXVECTOR3 move, BULLETTEX BulletTex, CMaker::MAKERTYPE makertype,int nLife)
{
	CBullet *pBullet;

	pBullet = new CBullet(OBJTYPE_BULLET);

	pBullet->BindTexture(m_pTextureBullet[BulletTex]);

	pBullet->Init(pos,move, BulletTex, makertype,nLife);

	return pBullet;
}

//========================================================================================================
// �e�N�X�`���̓ǂݍ���
//========================================================================================================
HRESULT CBullet::Load(void)
{
	CRenderer *pRenderer = CManager::GetRenderer();
	LPDIRECT3DDEVICE9 pDevice = pRenderer->GetDevice();

	//�e�N�X�`���̓ǂݍ���
	D3DXCreateTextureFromFile(
		pDevice,
		BULLET_TEX,
		&m_pTextureBullet[BULLETTEX_KEN]);

	//�e�N�X�`���̓ǂݍ���
	D3DXCreateTextureFromFile(
		pDevice,
		BULLET_TEX2,
		&m_pTextureBullet[BULLETTEX_KANGAROO]);

	return S_OK;
}

//=======================================================================================================
// �e�N�X�`���̔j��
//========================================================================================================
void CBullet::Unload(void)
{
	for (int nCnt =0; nCnt < MAX_TEXBULLET; nCnt++)
	{
		// ���_�o�b�t�@�̊J��
		if (m_pTextureBullet[nCnt] != NULL)
		{
			m_pTextureBullet[nCnt]->Release();
			m_pTextureBullet[nCnt] = NULL;
		}
	}
}

//========================================================================================================
// �`�揈��
//========================================================================================================
void CBullet::Draw(void)
{
	CBillboard::Draw();
}

//====================================================================================================
// �f�X�g���N�^
//=====================================================================================================
CBullet::~CBullet()
{

}