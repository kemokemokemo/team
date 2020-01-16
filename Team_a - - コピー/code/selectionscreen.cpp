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
	CPad *pPad = CManager::GetPad();

	// アイコンの動き
	float fH, fV;
	for (int nCnt = 0; nCnt < 2; nCnt++)
	{
		// スティック取得
		pPad->GetJoypadStickLeft(nCnt, &fH, &fV);

		if (fH != 0 || fV != 0)
		{// スティック移動
			m_pPlayerIcon[nCnt]->SetMove(D3DXVECTOR3(sinf(atan2f(fH, fV)), cosf(atan2f(fH, fV)), 0.0f) * 3.0f);
		}

		if (pPad->GetJoypadTrigger(nCnt, CPad::JOYPADKEY_B))
		{
			D3DXVECTOR3 pos = m_pPlayerIcon[nCnt]->GetPos();

			// ここで何のプレイヤーか分ける
			m_pPlayerIcon[nCnt]->SetType(CPlayerBase::PLAYERTYPE_KEN);
		}
		if (pPad->GetJoypadTrigger(nCnt, CPad::JOYPADKEY_A))
		{
			D3DXVECTOR3 pos = m_pPlayerIcon[nCnt]->GetPos();

			// ここで何のプレイヤーか分ける
			m_pPlayerIcon[nCnt]->SetType(CPlayerBase::PLAYERTYPE_KANGAROO);
		}
		if (pPad->GetJoypadTrigger(nCnt, CPad::JOYPADKEY_Y))
		{
			D3DXVECTOR3 pos = m_pPlayerIcon[nCnt]->GetPos();

			// ここで何のプレイヤーか分ける
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