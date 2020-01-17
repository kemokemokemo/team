//====================================================================================================
//
// �Q�[������ (Game.cpp)
// Author  Kimura Kouta
//
//====================================================================================================
#include "Game.h"//�C���N���[�h�t�@�C��
#include "manager.h"
#include "Scene.h"
#include "Scene2D.h"
#include "renderer.h"
#include "keybord.h"
#include "Title.h"
#include "Result.h"
#include "fade.h"
#include "light.h"
#include "camera.h"
#include "polygon.h"
#include "model.h"
#include "player_ken.h"
#include "player_sword.h"
#include "player_Kangaroo.h"
#include "gauge.h"
#include "effect.h"
#include "HitModel.h"
#include "Number.h"
#include "time.h"
#include "Texture.h"
//====================================================================================================
// �}�N����`
//==================================================================================================== 

//=====================================================================================================
// �O���錾������
//=====================================================================================================
CManager *CGame::m_pManager = NULL;
CLight*CGame::m_pLight = NULL;
CTime *CGame::pTime = NULL;

CPlayerBase::PLAYERTYPE CGame::m_PlayerType[2] = {};

//================================================================================================
// �R���X�g���N�^
//=================================================================================================
CGame::CGame()
{

}

//================================================================================================
// �f�X�g���N�^
//=================================================================================================
CGame::~CGame()
{

}

//================================================================================================
// �w�i�̏�����
//=================================================================================================
HRESULT CGame::Init(void)
{
	m_pLight = CLight::Create();

	CPlayerBase::Load();

	CModel::Load();

	CGauge::Load();

	CMaker::Load();

	CEffect::Load();

	CTexture::Load();

	CHitModel::Load();

	CNumber::Load();

	CModel::Create(D3DXVECTOR3(0.0f, 0.0f, 0.0f), D3DXVECTOR3(0.0f, 0.0f, 0.0f), CModel::UNITTYPE_FLOOR);

	//CModel::Create(D3DXVECTOR3(640.0f, 0.0f, 0.0f), D3DXVECTOR3(0.0f, 0.0f, 0.0f), CModel::MODELTYPE_BILL0);


	for (int nCnt = 0; nCnt < 2; nCnt++)
	{	

		switch (m_PlayerType[nCnt])
		{
		case CPlayerBase::PLAYERTYPE_KEN:

			m_Player[nCnt] = CPlayer_KEN::Create(D3DXVECTOR3(-200.0f, 500.0f, 0.0f), D3DXVECTOR3(0.0f, 0.0f, 0.0f), (CMaker::MAKERTYPE)nCnt);

			break;

		case CPlayerBase::PLAYERTYPE_KANGAROO:

			m_Player[nCnt] = CPlayer_Kangaroo::Create(D3DXVECTOR3(0.0f, 500.0f, 0.0f), D3DXVECTOR3(0.0f, 0.0f, 0.0f), (CMaker::MAKERTYPE)nCnt);
			break;

		case CPlayerBase::PLAYERTYPE_SWORD:

			m_Player[nCnt] = CPlayer_SWORD::Create(D3DXVECTOR3(200.0f, 500.0f, 0.0f), D3DXVECTOR3(0.0f, 0.0f, 0.0f), (CMaker::MAKERTYPE)nCnt);

			break;

		}
	}

	//CPlayer_KEN::Create(D3DXVECTOR3(-200.0f, 500.0f, 0.0f), D3DXVECTOR3(0.0f, 0.0f, 0.0f), CMaker::MAKERTYPE_1P);


	//CPlayer_SWORD::Create(D3DXVECTOR3(200.0f,500.0f, 0.0f), D3DXVECTOR3(0.0f, 0.0f, 0.0f), CMaker::MAKERTYPE_2P);
	CTexture::Create(D3DXVECTOR3(80.0f, 550.0f, 0.0f), D3DXVECTOR3(0.0f, 0.0f, 0.0f), D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f), 510.0f, 200.0f, CTexture::TYPE_LIFE1);
	CTexture::Create(D3DXVECTOR3(600.0f, 550.0f, 0.0f), D3DXVECTOR3(0.0f, 0.0f, 0.0f), D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f), 510.0f, 200.0f, CTexture::TYPE_LIFE2);



	//CPlayer_Kangaroo::Create(D3DXVECTOR3(0.0f, 500.0f, 0.0f), D3DXVECTOR3(0.0f, 0.0f, 0.0f), CMaker::MAKERTYPE_2P);

	//CGauge::Create(D3DXVECTOR3(200.0f, 600.0f, 0.0f));

	CPolygon::Create();


	{//�������Ԃ̐���
		pTime = CTime::Create(100);
	}

	return S_OK;
}

//================================================================================================
// �w�i�̊J������
//=================================================================================================
void CGame::Uninit(void)
{
	m_pLight->Uninit();
	CPlayerBase::Unload();
	CModel::Unload();
	CGauge::Unload();
	CMaker::Unload();
	CTexture::Unload();
	CEffect::Unload();
	CHitModel::Unload();
}

//================================================================================================
// �w�i�̍X�V����
//=================================================================================================
void CGame::Update(void)
{
	m_pLight->Update();

	CKeybord *pKetybord = CManager::GetKeybord();

	// (pKetybord->GetKeyboardTrigger(DIK_RETURN))
	{
		//CFade::SetFade(m_pManager->MODE_RESULT);
	}
}

//================================================================================================
// �w�i�̕`�揈��
//=================================================================================================
void CGame::Draw(void)
{

}

void CGame::SetPlayerType(CSelectIcon * type[])
{
	for (int nCnt = 0; nCnt < 2; nCnt++)
	{
		m_PlayerType[nCnt] = type[nCnt]->GetType();
	}
}

//================================================================================================
// �^�C�g������
//================================================================================================
CGame * CGame::Create(void)
{
	CGame *pGame;

	pGame = new CGame();

	pGame->Init();

	return pGame;
}