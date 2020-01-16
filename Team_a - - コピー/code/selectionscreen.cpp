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

	CSelectIcon::Load();
	float pos = 0;

	for (int nCnt = 0; nCnt < 4; nCnt++)
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

	// �A�C�R���̓���
	float fH, fV;
	for (int nCnt = 0; nCnt < 2; nCnt++)
	{
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
		}
		if (pPad->GetJoypadTrigger(nCnt, CPad::JOYPADKEY_A))
		{
			D3DXVECTOR3 pos = m_pPlayerIcon[nCnt]->GetPos();

			// �����ŉ��̃v���C���[��������
			m_pPlayerIcon[nCnt]->SetType(CPlayerBase::PLAYERTYPE_KANGAROO);
		}
		if (pPad->GetJoypadTrigger(nCnt, CPad::JOYPADKEY_Y))
		{
			D3DXVECTOR3 pos = m_pPlayerIcon[nCnt]->GetPos();

			// �����ŉ��̃v���C���[��������
			m_pPlayerIcon[nCnt]->SetType(CPlayerBase::PLAYERTYPE_SWORD);
		}
	}

	if (pPad->GetJoypadTrigger(0, CPad::JOYPADKEY_START))
	{
		if (CFade::GetFade() == CFade::FADE_NONE)
		{
			CGame::SetPlayerType(m_pPlayerIcon[0]);

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