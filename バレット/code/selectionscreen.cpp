//====================================================================================================
//
// キャラ選択画面処理 (SelectionScreen.cpp)
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
// マクロ定義
//==================================================================================================== 

//=====================================================================================================
// 前方宣言初期化
//=====================================================================================================
CManager *CSelectionScreen::m_pManager = NULL;
CLight*CSelectionScreen::m_pLight = NULL;

//================================================================================================
// コンストラクタ
//=================================================================================================
CSelectionScreen::CSelectionScreen()
{
	for (int nCnt = 0; nCnt < 2; nCnt++)
	{
		m_pPlayerIcon[nCnt] = NULL;
	}

}

//================================================================================================
// デストラクタ
//=================================================================================================
CSelectionScreen::~CSelectionScreen()
{

}

//================================================================================================
// 背景の初期化
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
// 背景の開放処理
//=================================================================================================
void CSelectionScreen::Uninit(void)
{
	CSelectIcon::Unload();
}

//================================================================================================
// 背景の更新処理
//=================================================================================================
void CSelectionScreen::Update(void)
{
	CKeybord *pKeyboard = CManager::GetKeybord();
	CPad *pPad = CManager::GetPad();
	D3DXVECTOR3 Selectpos;

	// アイコンの動き
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

		// スティック取得
		pPad->GetJoypadStickLeft(nCnt, &fH, &fV);

		if (fH != 0 || fV != 0)
		{// スティック移動
			m_pPlayerIcon[nCnt]->SetMove(D3DXVECTOR3(sinf(atan2f(fH, fV)), cosf(atan2f(fH, fV)), 0.0f) * 3.0f);
		}

		if (pPad->GetJoypadTrigger(nCnt, CPad::JOYPADKEY_B))
		{
			D3DXVECTOR3 pos = m_pPlayerIcon[nCnt]->GetPos();
			if (pTexture[nCnt] != NULL)
			{
				pTexture[nCnt]->Release();
			}
			// ここで何のプレイヤーか分ける
			m_pPlayerIcon[nCnt]->SetType(CPlayerBase::PLAYERTYPE_KEN);
			pTexture[nCnt] = CTexture::Create(Selectpos, D3DXVECTOR3(0.0f, 0.0f, 0.0f), D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f), 200.0f, 200.0f, CTexture::TYPE_SELECTKENICON);

		}
		if (pPad->GetJoypadTrigger(nCnt, CPad::JOYPADKEY_A))
		{
			D3DXVECTOR3 pos = m_pPlayerIcon[nCnt]->GetPos();
			if (pTexture[nCnt] != NULL)
			{
				pTexture[nCnt]->Release();
			}
			// ここで何のプレイヤーか分ける
			m_pPlayerIcon[nCnt]->SetType(CPlayerBase::PLAYERTYPE_KANGAROO);
			pTexture[nCnt] = CTexture::Create(Selectpos, D3DXVECTOR3(0.0f, 0.0f, 0.0f), D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f), 200.0f, 200.0f, CTexture::TYPE_SELECTKANGAROOICON);
		}
		if (pPad->GetJoypadTrigger(nCnt, CPad::JOYPADKEY_Y))
		{
			D3DXVECTOR3 pos = m_pPlayerIcon[nCnt]->GetPos();
			if (pTexture[nCnt] != NULL)
			{
				pTexture[nCnt]->Release();
			}
			// ここで何のプレイヤーか分ける
			m_pPlayerIcon[nCnt]->SetType(CPlayerBase::PLAYERTYPE_SWORD);
			pTexture[nCnt] = CTexture::Create(Selectpos, D3DXVECTOR3(0.0f, 0.0f, 0.0f), D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f), 200.0f, 200.0f, CTexture::TYPE_SELECTSWORDICON);

		}
	}
#ifdef _DEBUG
	if (pKeyboard->GetKeyboardPress(DIK_Z))
	{
		D3DXVECTOR3 pos = m_pPlayerIcon[0]->GetPos();
		if (pTexture[0] != NULL)
		{
			pTexture[0]->Release();
		}
		// ここで何のプレイヤーか分ける
		m_pPlayerIcon[0]->SetType(CPlayerBase::PLAYERTYPE_KEN);
		pTexture[0] = CTexture::Create(Selectpos, D3DXVECTOR3(0.0f, 0.0f, 0.0f), D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f), 200.0f, 200.0f, CTexture::TYPE_SELECTKENICON);
	}
	if (pKeyboard->GetKeyboardPress(DIK_X))
	{
		D3DXVECTOR3 pos = m_pPlayerIcon[0]->GetPos();
		if (pTexture[0] != NULL)
		{
			pTexture[0]->Release();
		}
		// ここで何のプレイヤーか分ける
		m_pPlayerIcon[0]->SetType(CPlayerBase::PLAYERTYPE_KANGAROO);
		pTexture[0] = CTexture::Create(Selectpos, D3DXVECTOR3(0.0f, 0.0f, 0.0f), D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f), 200.0f, 200.0f, CTexture::TYPE_SELECTKANGAROOICON);
	}
	if (pKeyboard->GetKeyboardPress(DIK_C))
	{
		D3DXVECTOR3 pos = m_pPlayerIcon[0]->GetPos();
		if (pTexture[0] != NULL)
		{
			pTexture[0]->Release();
		}
		// ここで何のプレイヤーか分ける
		m_pPlayerIcon[0]->SetType(CPlayerBase::PLAYERTYPE_SWORD);
		pTexture[0] = CTexture::Create(Selectpos, D3DXVECTOR3(0.0f, 0.0f, 0.0f), D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f), 200.0f, 200.0f, CTexture::TYPE_SELECTSWORDICON);
	}
	if (pKeyboard->GetKeyboardPress(DIK_A))
	{
		D3DXVECTOR3 pos = m_pPlayerIcon[1]->GetPos();
		if (pTexture[1] != NULL)
		{
			pTexture[1]->Release();
		}
		// ここで何のプレイヤーか分ける
		m_pPlayerIcon[1]->SetType(CPlayerBase::PLAYERTYPE_KEN);
		pTexture[1] = CTexture::Create(Selectpos, D3DXVECTOR3(0.0f, 0.0f, 0.0f), D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f), 200.0f, 200.0f, CTexture::TYPE_SELECTKENICON);
	}
	if (pKeyboard->GetKeyboardPress(DIK_S))
	{
		D3DXVECTOR3 pos = m_pPlayerIcon[1]->GetPos();
		if (pTexture[1] != NULL)
		{
			pTexture[1]->Release();
		}
		// ここで何のプレイヤーか分ける
		m_pPlayerIcon[1]->SetType(CPlayerBase::PLAYERTYPE_KANGAROO);
		pTexture[1] = CTexture::Create(Selectpos, D3DXVECTOR3(0.0f, 0.0f, 0.0f), D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f), 200.0f, 200.0f, CTexture::TYPE_SELECTKANGAROOICON);
	}
	if (pKeyboard->GetKeyboardPress(DIK_D))
	{
		D3DXVECTOR3 pos = m_pPlayerIcon[1]->GetPos();
		if (pTexture[1] != NULL)
		{
			pTexture[1]->Release();
		}
		// ここで何のプレイヤーか分ける
		m_pPlayerIcon[1]->SetType(CPlayerBase::PLAYERTYPE_SWORD);
		pTexture[1] = CTexture::Create(Selectpos, D3DXVECTOR3(0.0f, 0.0f, 0.0f), D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f), 200.0f, 200.0f, CTexture::TYPE_SELECTSWORDICON);
	}
#endif
	if (pPad->GetJoypadTrigger(0, CPad::JOYPADKEY_START) || pKeyboard->GetKeyboardTrigger(DIK_RETURN))
	{
		if (CFade::GetFade() == CFade::FADE_NONE)
		{
			CGame::SetPlayerType(m_pPlayerIcon);

			CFade::SetFade(m_pManager->MODE_GAME);
		}
	}
}

//================================================================================================
// 背景の描画処理
//=================================================================================================
void CSelectionScreen::Draw(void)
{

}

//================================================================================================
// タイトル処理
//================================================================================================
CSelectionScreen * CSelectionScreen::Create(void)
{
	CSelectionScreen *pSelectionScreen;

	pSelectionScreen = new CSelectionScreen();

	pSelectionScreen->Init();

	return pSelectionScreen;
}