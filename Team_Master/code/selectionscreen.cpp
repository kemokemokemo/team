//====================================================================================================
//
// �L�����I����ʏ��� (SelectionScreen.cpp)
// Author  Kimura Kouta
//
//====================================================================================================
#include"selectionscreen.h"
#include"manager.h"
#include"renderer.h"
#include"input.h"
#include"keybord.h"
#include "pad.h"
#include "light.h"
#include "playerbase.h"
#include "Game.h"
#include "Texture.h"
//====================================================================================================
// �}�N����`
//==================================================================================================== 

//=====================================================================================================
// �O���錾������
//=====================================================================================================
CManager *CSelectionScreen::m_pManager = NULL;
CLight*CSelectionScreen::m_pLight = NULL;

//================================================================================================
// �R���X�g���N�^
//=================================================================================================
CSelectionScreen::CSelectionScreen()
{
	for (int nCnt = 0; nCnt < 2; nCnt++)
	{
		m_pPlayerIcon[nCnt] = NULL;
	}

}

//================================================================================================
// �f�X�g���N�^
//=================================================================================================
CSelectionScreen::~CSelectionScreen()
{

}

//================================================================================================
// �w�i�̏�����
//=================================================================================================
HRESULT CSelectionScreen::Init(void)
{
	m_pLight = CLight::Create();
	CTexture::Load();

	CSelectIcon::Load();
	float pos = 0;
	CTexture::Create(D3DXVECTOR3(0.0f, 0.0f, 0.0f), D3DXVECTOR3(0.0f, 0.0f, 0.0f), D3DXCOLOR(0.9f, 0.9f, 0.9f, 1.0f), 1280.0f, 720.0f, CTexture::TYPE_SELECT_BG);
	CTexture::Create(D3DXVECTOR3(100.0f, 350.0f, 0.0f), D3DXVECTOR3(0.0f, 0.0f, 0.0f), D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f), 370.0f, 350.0f, CTexture::TYPE_SELECT1);
	CTexture::Create(D3DXVECTOR3(800.0f, 350.0f, 0.0f), D3DXVECTOR3(0.0f, 0.0f, 0.0f), D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f), 370.0f, 350.0f, CTexture::TYPE_SELECT2);

	CTexture::Create(D3DXVECTOR3(100.0f, 100.0f, 0.0f), D3DXVECTOR3(0.0f, 0.0f, 0.0f), D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f), 230.0f, 230.0f, CTexture::TYPE_KENICON);
	CTexture::Create(D3DXVECTOR3(500.0f, 100.0f, 0.0f), D3DXVECTOR3(0.0f, 0.0f, 0.0f), D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f), 230.0f, 230.0f, CTexture::TYPE_KANGAROOICON);
	CTexture::Create(D3DXVECTOR3(900.0f, 100.0f, 0.0f), D3DXVECTOR3(0.0f, 0.0f, 0.0f), D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f), 230.0f, 230.0f, CTexture::TYPE_SWORDICON);



	for (int nCnt = 0; nCnt < 2; nCnt++)
	{
		m_pPlayerIcon[nCnt] = CSelectIcon::Create(D3DXVECTOR3(pos, 0.0f, 0.0f), (CSelectIcon::ICON)nCnt);
		pos += 100.0f;
	}
	return S_OK;
}

//=================================================================================================
// �w�i�̊J������
//=================================================================================================
void CSelectionScreen::Uninit(void)
{
	CSelectIcon::Unload();
}

//================================================================================================
// �w�i�̍X�V����
//=================================================================================================
void CSelectionScreen::Update(void)
{
	CPad *pPad = CManager::GetPad();
	D3DXVECTOR3 Selectpos;
	// �A�C�R���̓���
	float fH, fV;
	for (int nCnt = 0; nCnt < 2; nCnt++)
	{
		if (nCnt == 0)
		{
			Selectpos = D3DXVECTOR3(180.0f, 450.0f, 0.0f);
		}
		if (nCnt == 1)
		{
			Selectpos = D3DXVECTOR3(880.0f, 450.0f, 0.0f);
		}
		// �X�e�B�b�N�擾
		pPad->GetJoypadStickLeft(nCnt, &fH, &fV);

		if (fH != 0 || fV != 0)
		{// �X�e�B�b�N�ړ�
			m_pPlayerIcon[nCnt]->SetMove(D3DXVECTOR3(sinf(atan2f(fH, fV)), cosf(atan2f(fH, fV)), 0.0f) * 3.0f);
		}

		if (pPad->GetJoypadTrigger(nCnt, CPad::JOYPADKEY_B))
		{
			D3DXVECTOR3 pos = m_pPlayerIcon[nCnt]->GetPos();

			// �����ŉ��̃v���C���[��������
			m_pPlayerIcon[nCnt]->SetType(CPlayerBase::PLAYERTYPE_KEN);
			CTexture::Create(Selectpos, D3DXVECTOR3(0.0f, 0.0f, 0.0f), D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f), 200.0f, 200.0f, CTexture::TYPE_SELECTKENICON);

		}
		if (pPad->GetJoypadTrigger(nCnt, CPad::JOYPADKEY_A))
		{
			D3DXVECTOR3 pos = m_pPlayerIcon[nCnt]->GetPos();

			// �����ŉ��̃v���C���[��������
			m_pPlayerIcon[nCnt]->SetType(CPlayerBase::PLAYERTYPE_KANGAROO);
			CTexture::Create(Selectpos, D3DXVECTOR3(0.0f, 0.0f, 0.0f), D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f), 200.0f, 200.0f, CTexture::TYPE_SELECTKANGAROOICON);

		}
		if (pPad->GetJoypadTrigger(nCnt, CPad::JOYPADKEY_Y))
		{
			D3DXVECTOR3 pos = m_pPlayerIcon[nCnt]->GetPos();

			// �����ŉ��̃v���C���[��������
			m_pPlayerIcon[nCnt]->SetType(CPlayerBase::PLAYERTYPE_SWORD);
			CTexture::Create(Selectpos, D3DXVECTOR3(0.0f, 0.0f, 0.0f), D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f), 200.0f, 200.0f, CTexture::TYPE_SELECTSWORDICON);

		}
	}

	if (pPad->GetJoypadTrigger(0, CPad::JOYPADKEY_START))
	{
		if (CFade::GetFade() == CFade::FADE_NONE)
		{
			CGame::SetPlayerType(m_pPlayerIcon);

			CFade::SetFade(m_pManager->MODE_GAME);
		}
	}

	CKeybord *pKetybord = CManager::GetKeybord();

	if (CFade::GetFade() == CFade::FADE_NONE)
	{
		if (pKetybord->GetKeyboardTrigger(DIK_RETURN))
		{
			CFade::SetFade(m_pManager->MODE_GAME);
		}
	}
}

//================================================================================================
// �w�i�̕`�揈��
//=================================================================================================
void CSelectionScreen::Draw(void)
{

}

//================================================================================================
// �^�C�g������
//================================================================================================
CSelectionScreen * CSelectionScreen::Create(void)
{
	CSelectionScreen *pSelectionScreen;

	pSelectionScreen = new CSelectionScreen();

	pSelectionScreen->Init();

	return pSelectionScreen;
}