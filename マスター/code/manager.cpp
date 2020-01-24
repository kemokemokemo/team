//====================================================================================================
//
// �}�l�[�W���[ (manager.cpp)
// Author (Kimura kouta)
//
//====================================================================================================
#include "manager.h"
#include "Scene.h"
#include "renderer.h"
#include "keybord.h"
#include "Title.h"
#include "Game.h"
#include "Result.h"
#include "Gameover.h"
#include "tutorial.h"
#include "selectionscreen.h"
#include "pad.h"
#include "sound.h"
//====================================================================================================
// �}�N����`
//==================================================================================================== 
#define MAX_POLIGON	(2)

//====================================================================================================
// �v���g�^�C�v�錾
//====================================================================================================

//====================================================================================================
// �����o�ϐ�������
//====================================================================================================
CRenderer *CManager::m_pRenderer = NULL;
CKeybord *CManager::m_pKeybord = NULL;
CPad *CManager::m_pPad = NULL;
CTitle *CManager::pTitle = NULL;
CGame *CManager::pGame = NULL;
CResult *CManager::pResult = NULL;
CGameover *CManager::pGameover = NULL;
CTutorial *CManager::pTutorial = NULL;
CSelectionScreen *CManager::pSelectionScreen = NULL;
CSound *CManager::m_pSound = NULL;
CManager::MODE CManager::m_mode = CManager::MODE_TITLE;

//====================================================================================================
// �R���X�g���N�^
//====================================================================================================
CManager::CManager()
{

}

//=============================================================================
// ����������
//=============================================================================
HRESULT CManager::Init(HINSTANCE hInstance, HWND hWnd, BOOL bWindow)
{
	m_pRenderer = new CRenderer;
	m_pKeybord = new CKeybord;
	m_pPad = new CPad;

	m_pSound = new CSound;

	//����������
	if (FAILED(m_pRenderer->Init(hWnd, TRUE)))
	{
		m_pRenderer->Uninit();
		return-1;
	}

	if (FAILED(m_pKeybord->Init(hInstance, hWnd)))
	{
		m_pKeybord->Uninit();
		return-1;
	}
	if (FAILED(m_pPad->Init(hInstance, hWnd)))
	{
		m_pPad->Uninit();
		return-1;
	}
	if (FAILED(m_pSound->InitSound(hWnd)))
	{
		m_pSound->UninitSound();
		return-1;
	}

	switch (m_mode)
	{
	case MODE_TITLE:
		pTitle = CTitle::Create();
		break;

	case MODE_TUTRIAL:
		pTutorial = CTutorial::Create();
		break;

	case MODE_GAME:
		pGame = CGame::Create();
		break;

	case MODE_RESULT:
		pResult = CResult::Create();
		break;

	case MODE_GAMEOVER:
		pGameover = CGameover::Create();
		break;

	case MODE_SELECTSCREEN:
		pSelectionScreen = CSelectionScreen::Create();
		break;
	}

	return S_OK;
}

//==================================================================================================
//�I������
//===================================================================================================
void CManager::Uninit(void)
{
	CScene::ReleaseAll();

	//�I������
	if (m_pRenderer != NULL)
	{
		m_pRenderer->Uninit();
		delete m_pRenderer;
		m_pRenderer = NULL;
	}

	if (m_pKeybord != NULL)
	{
		m_pKeybord->Uninit();
		delete m_pKeybord;
		m_pKeybord = NULL;
	}

	if (m_pPad != NULL)
	{
		m_pPad->Uninit();
		delete m_pPad;
		m_pPad = NULL;
	}

	switch (m_mode)
	{
	case MODE_TITLE:
		pTitle->Uninit();
		break;

	case MODE_TUTRIAL:
		pTutorial->Uninit();
		break;

	case MODE_GAME:
		pGame->Uninit();
		break;

	case MODE_RESULT:
		pResult->Uninit();
		break;

	case MODE_GAMEOVER:
		pGameover->Uninit();
		break;

	case MODE_SELECTSCREEN:
		pSelectionScreen->Uninit();
		break;
	}

	if (m_pSound != NULL)
	{
		m_pSound->UninitSound();
		delete m_pPad;
		m_pSound = NULL;
	}
}

//====================================================================================================
//�X�V����
//=====================================================================================================
void CManager::Update(void)
{
	m_pRenderer->Update();

	m_pKeybord->Update();

	m_pPad->Update();

	switch (m_mode)
	{
	case MODE_TITLE:
		pTitle->Update();
		break;

	case MODE_TUTRIAL:
		pTutorial->Update();
		break;

	case MODE_GAME:
		pGame->Update();

		break;

	case MODE_RESULT:
		pResult->Update();
		break;

	case MODE_GAMEOVER:
		pGameover->Update();
		break;

	case MODE_SELECTSCREEN:
		pSelectionScreen->Update();
		break;
	}
}

//========================================================================================================
//�`�揈��
//========================================================================================================
void CManager::Draw(void)
{
	//�`�揈��
	m_pRenderer->Draw();

	switch (m_mode)
	{
	case MODE_TITLE:
		pTitle->Draw();
		break;

	case MODE_TUTRIAL:
		pTutorial->Draw();
		break;

	case MODE_GAME:
		pGame->Draw();
		break;

	case MODE_RESULT:
		pResult->Draw();
		break;

	case MODE_GAMEOVER:
		pGameover->Draw();
		break;

	case MODE_SELECTSCREEN:
		pSelectionScreen->Draw();
		break;

	}
}


//========================================================================================================
// �����_���[�̎擾
//========================================================================================================
CRenderer *CManager::GetRenderer(void)
{
	return m_pRenderer;
}

//========================================================================================================
// �L�[�{�[�h�̎擾
//========================================================================================================
CKeybord *CManager::GetKeybord(void)
{
	return m_pKeybord;
}

CPad * CManager::GetPad(void)
{
	return m_pPad;
}
//========================================================================================================
// �T�E���h�̎擾
//========================================================================================================
CSound * CManager::GetSound(void)
{
	return m_pSound;
}

//====================================================================================================
// ���[�h�̏��
//====================================================================================================
void CManager::SetMode(MODE mode)
{
	CScene::ReleaseAll();

	switch (m_mode)
	{
	case MODE_TITLE:
		m_pSound->StopSound();
		pTitle->Uninit();
		delete pTitle;
		pTitle = NULL;
		break;

	case MODE_TUTRIAL:
		m_pSound->StopSound();
		pTutorial->Uninit();
		delete pTutorial;
		pTutorial = NULL;
		break;

	case MODE_GAME:
		m_pSound->StopSound();
		pGame->Uninit();
		delete pGame;
		pGame = NULL;
		break;

	case MODE_RESULT:
		m_pSound->StopSound();
		pResult->Uninit();
		delete pResult;
		pResult = NULL;
		break;


	case MODE_GAMEOVER:
		m_pSound->StopSound();
		pGameover->Uninit();
		delete pGameover;
		pGameover = NULL;
		break;

	case MODE_SELECTSCREEN:
		m_pSound->StopSound();
		pSelectionScreen->Draw();
		delete pSelectionScreen;
		pSelectionScreen = NULL;
		break;
	}

	m_mode = mode;

	switch (mode)
	{
	case MODE_TITLE:
		pTitle = CTitle::Create();
		m_pSound->PlaySound(CSound::SOUND_LABEL_TITLE);

		break;

	case MODE_TUTRIAL:
		pTutorial = CTutorial::Create();
		//m_pSound->PlaySound(CSound::SOUND_LABEL_TITLE);

		break;

	case MODE_GAME:
		pGame = CGame::Create();
		m_pSound->PlaySound(CSound::SOUND_LABEL_BATTLE);
		break;

	case MODE_RESULT:
		pResult = CResult::Create();
		m_pSound->PlaySound(CSound::SOUND_LABEL_VICTORY);
		break;

	case MODE_GAMEOVER:
		pGameover = CGameover::Create();
		//m_pSound->PlaySound(CSound::SOUND_LABEL_TITLE);
		break;

	case MODE_SELECTSCREEN:
		pSelectionScreen = CSelectionScreen::Create();
		m_pSound->PlaySound(CSound::SOUND_LABEL_SELECT);
		break;
	}
}

//====================================================================================================
// ���[�h�̎擾
//====================================================================================================
CManager::MODE CManager::GetMode(void)
{
	return m_mode;
}

//====================================================================================================
// �f�X�g���N�^
//====================================================================================================
CManager::~CManager()
{

}

