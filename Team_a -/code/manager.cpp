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

CManager::MODE CManager::m_mode = CManager::MODE_SELECTSCREEN;

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

	switch (m_mode)
	{
	case MODE_TITLE:
		pTitle->Init();
		break;

	case MODE_TUTRIAL:
		pTutorial->Init();
		break;

	case MODE_GAME:
		pGame->Init();
		break;

	case MODE_RESULT:
		pResult->Init();
		break;

	case MODE_GAMEOVER:
		pGameover->Init();
		break;

	case MODE_SELECTSCREEN:
		pSelectionScreen->Init();
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

//====================================================================================================
// ���[�h�̏��
//====================================================================================================
void CManager::SetMode(MODE mode)
{
	CScene::ReleaseAll();

	switch (m_mode)
	{
	case MODE_TITLE:
		pTitle->Uninit();
		delete pTitle;
		pTitle = NULL;
		break;

	case MODE_TUTRIAL:
		pTutorial->Uninit();
		delete pTutorial;
		pTutorial = NULL;
		break;

	case MODE_GAME:
		pGame->Uninit();
		delete pGame;
		pGame = NULL;
		break;

	case MODE_RESULT:
		pResult->Uninit();
		delete pResult;
		pResult = NULL;
		break;


	case MODE_GAMEOVER:
		pGameover->Uninit();
		delete pGameover;
		pGameover = NULL;
		break;

	case MODE_SELECTSCREEN:
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
}

//====================================================================================================
// ���[�h�̎擾
//====================================================================================================
CManager::MODE CManager::GetMode(void)
{
	return MODE();
}

//====================================================================================================
// �f�X�g���N�^
//====================================================================================================
CManager::~CManager()
{

}

