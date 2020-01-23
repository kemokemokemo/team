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
	CTexture::Load();
	CSelectIcon::Load();

	float fPos = 0.0f;
	CTexture::Create(D3DXVECTOR3(0.0f, 0.0f, 0.0f), D3DXVECTOR3(0.0f, 0.0f, 0.0f), D3DXCOLOR(0.9f, 0.9f, 0.9f, 1.0f), 1280.0f, 720.0f, CTexture::TYPE_SELECT_BG);

	CTexture::Create(D3DXVECTOR3(100.0f, 350.0f, 0.0f), D3DXVECTOR3(0.0f, 0.0f, 0.0f), D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f), 370.0f, 350.0f, CTexture::TYPE_SELECT1);
	CTexture::Create(D3DXVECTOR3(800.0f, 350.0f, 0.0f), D3DXVECTOR3(0.0f, 0.0f, 0.0f), D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f), 370.0f, 350.0f, CTexture::TYPE_SELECT2);

	m_pTextureIcon[0] = CTexture::Create(D3DXVECTOR3(100.0f, 100.0f, 0.0f), D3DXVECTOR3(0.0f, 0.0f, 0.0f), D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f), 230.0f, 230.0f, CTexture::TYPE_KENICON);
	m_pTextureIcon[1] = CTexture::Create(D3DXVECTOR3(500.0f, 100.0f, 0.0f), D3DXVECTOR3(0.0f, 0.0f, 0.0f), D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f), 230.0f, 230.0f, CTexture::TYPE_KANGAROOICON);
	m_pTextureIcon[2] = CTexture::Create(D3DXVECTOR3(900.0f, 100.0f, 0.0f), D3DXVECTOR3(0.0f, 0.0f, 0.0f), D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f), 230.0f, 230.0f, CTexture::TYPE_SWORDICON);

	m_pTextureIcon[0]->SetType(CPlayerBase::PLAYERTYPE_KEN);
	m_pTextureIcon[1]->SetType(CPlayerBase::PLAYERTYPE_KANGAROO);
	m_pTextureIcon[2]->SetType(CPlayerBase::PLAYERTYPE_SWORD);

	for (int nCnt = 0; nCnt < 2; nCnt++)
	{
		m_pPlayerIcon[nCnt] = CSelectIcon::Create(D3DXVECTOR3(fPos, 0.0f, 0.0f), (CSelectIcon::ICON)nCnt);
		fPos += 100.0f;
	}
	return S_OK;
}

//=================================================================================================
// 背景の開放処理
//=================================================================================================
void CSelectionScreen::Uninit(void)
{
	CSelectIcon::Unload();
	CTexture::Unload();
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
			Selectpos = D3DXVECTOR3(180.0f, 470.0f, 0.0f);
		}
		if (nCnt == 1)
		{
			Selectpos = D3DXVECTOR3(880.0f, 470.0f, 0.0f);
		}

		// スティック取得
		pPad->GetJoypadStickLeft(nCnt, &fH, &fV);

		if (m_pPlayerIcon[nCnt])
		{
			if (fH != 0 || fV != 0)
			{// スティック移動
				m_pPlayerIcon[nCnt]->SetMove(D3DXVECTOR3(sinf(atan2f(fH, fV)), -cosf(atan2f(fH, fV)), 0.0f) * 3.0f);
			}

			if (pKeyboard->GetKeyboardPress(DIK_D))
			{// スティック移動
				m_pPlayerIcon[1]->SetMove(D3DXVECTOR3(1.0f, 0.0f, 0.0f));
			}

			D3DXVECTOR3 pos = {};

			for (int nCount = 0; nCount < 3; nCount++)
			{
				pos = m_pPlayerIcon[nCnt]->GetPos() - m_pTextureIcon[nCount]->GetPos();

				// 表示されてるキャラを消す
				if (m_pTexture[nCnt])
				{
					m_pTexture[nCnt]->Uninit();
					m_pTexture[nCnt] = NULL;
				}

				// 範囲内なら
				if (fabsf(pos.x) <= 230.0f / 2.0f && fabsf(pos.y) <= 230.0f / 2.0f)
				{
					if (!m_pTexture[nCnt])
					{
						// 選択キャラ表示
						m_pTexture[nCnt] = CTexture::Create(Selectpos, D3DXVECTOR3(0.0f, 0.0f, 0.0f), D3DXCOLOR(1.0f, 1.0f, 1.0f, 0.5f), 200.0f, 200.0f, CTexture::TEXTURE_TYPE((int)CTexture::TYPE_SELECTKENICON + nCount));
						m_pTexture[nCnt]->SetType(CPlayerBase::PLAYERTYPE(nCount));
						break;
					}
				}
			}
			if (pPad->GetJoypadTrigger(nCnt, CPad::JOYPADKEY_B) || pKeyboard->GetKeyboardTrigger(DIK_SPACE))
			{
				if (m_pTexture[nCnt])
				{
					// 指消す
					m_pPlayerIcon[nCnt]->Uninit();
					m_pPlayerIcon[nCnt] = NULL;
					m_pTexture[nCnt]->SetColor(D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f));
				}
			}
		}
		else
		{
			if (pPad->GetJoypadTrigger(nCnt, CPad::JOYPADKEY_A))
			{
				// 指生成
				m_pPlayerIcon[nCnt] = CSelectIcon::Create(m_pTextureIcon[(int)m_pTexture[nCnt]->GetType()]->GetPos(), (CSelectIcon::ICON)nCnt);
			}
		}
	}


	if (!m_pPlayerIcon[0] && !m_pPlayerIcon[1])
	{
		if (!m_Ready)
		{
			m_Ready = CTexture::Create(D3DXVECTOR3(-100.0f, 305.0f, 0.0f), D3DXVECTOR3(0.0f, 0.0f, 0.0f), D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f), 1500.0f, 130.0f, CTexture::TYPE_READY);
		}

		for (int nCnt = 0; nCnt < 2; nCnt++)
		{
			if (pPad->GetJoypadTrigger(nCnt, CPad::JOYPADKEY_START) || pKeyboard->GetKeyboardTrigger(DIK_RETURN))
			{
				CGame::SetPlayerType(m_pTexture);

				if (CFade::GetFade() == CFade::FADE_NONE)
				{
					CFade::SetFade(CManager::MODE_GAME);
				}
			}
		}
	}
	else
	{
		if (m_Ready)
		{
			// 画像消す
			m_Ready->Uninit();
			m_Ready = NULL;
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