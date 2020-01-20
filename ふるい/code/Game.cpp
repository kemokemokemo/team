//====================================================================================================
//
// ゲーム処理 (Game.cpp)
// Author  Kimura Kouta
//
//====================================================================================================
#include "Game.h"//インクルードファイル
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
// マクロ定義
//==================================================================================================== 

//=====================================================================================================
// 前方宣言初期化
//=====================================================================================================
CManager *CGame::m_pManager = NULL;
CLight*CGame::m_pLight = NULL;
CTime *CGame::pTime = NULL;

CPlayerBase::PLAYERTYPE CGame::m_PlayerType[2] = {};
CPlayerBase *CGame::m_Player[2] = {};

//================================================================================================
// コンストラクタ
//=================================================================================================
CGame::CGame()
{

}

//================================================================================================
// デストラクタ
//=================================================================================================
CGame::~CGame()
{

}

//================================================================================================
// 背景の初期化
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

	for (int nCnt = 0; nCnt < 2; nCnt++)
	{
		float fX = 0.0f;
		if (nCnt == 0)
		{
			fX = -300.0f;
		}
		else
		{
			fX = 300.0f;
		}

		switch (m_PlayerType[nCnt])
		{
		case CPlayerBase::PLAYERTYPE_KEN:

			m_Player[nCnt] = CPlayer_KEN::Create(D3DXVECTOR3(fX, 500.0f, 0.0f), D3DXVECTOR3(0.0f, 0.0f, 0.0f), (CMaker::MAKERTYPE)nCnt);
			break;

		case CPlayerBase::PLAYERTYPE_KANGAROO:

			m_Player[nCnt] = CPlayer_Kangaroo::Create(D3DXVECTOR3(fX, 500.0f, 0.0f), D3DXVECTOR3(0.0f, 0.0f, 0.0f), (CMaker::MAKERTYPE)nCnt);
			break;

		case CPlayerBase::PLAYERTYPE_SWORD:

			m_Player[nCnt] = CPlayer_SWORD::Create(D3DXVECTOR3(fX, 500.0f, 0.0f), D3DXVECTOR3(0.0f, 0.0f, 0.0f), (CMaker::MAKERTYPE)nCnt);
			break;
		}
	}

	CPolygon::Create();

	{//制限時間の生成
		pTime = CTime::Create(100);
	}
	CTexture::Create(D3DXVECTOR3(80.0f, 550.0f, 0.0f), D3DXVECTOR3(0.0f, 0.0f, 0.0f), D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f), 510.0f, 200.0f, CTexture::TYPE_LIFE1);
	CTexture::Create(D3DXVECTOR3(680.0f, 550.0f, 0.0f), D3DXVECTOR3(0.0f, 0.0f, 0.0f), D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f), 510.0f, 200.0f, CTexture::TYPE_LIFE2);

	return S_OK;
}

//================================================================================================
// 背景の開放処理
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
// 背景の更新処理
//=================================================================================================
void CGame::Update(void)
{
	m_pLight->Update();

	CKeybord *pKetybord = CManager::GetKeybord();

	for (int nCnt = 0; nCnt < 2; nCnt++)
	{
		if (m_Player[nCnt])
		{
			m_Player[nCnt]->PlayerPad(nCnt);
		}
	}

	{// カメラ
		D3DXVECTOR3 pos[2] = {};

		for (int nCnt = 0; nCnt < 2; nCnt++)
		{
			if (m_Player[nCnt])
			{
				pos[nCnt] = m_Player[nCnt]->GetPos();
			}
		}

		D3DXVECTOR3 dis = pos[1] - pos[0];

		pos[0] += dis / 2.0f;

		CCamera::SetCameraPos(pos[0], dis);
	}

#ifdef _DEBUG
	if (pKetybord->GetKeyboardTrigger(DIK_RETURN))
	{
		CFade::SetFade(m_pManager->MODE_RESULT);
	}
#endif
}

//================================================================================================
// 背景の描画処理
//=================================================================================================
void CGame::Draw(void)
{

}

void CGame::SetPlayerType(CSelectIcon *type[])
{
	for (int nCnt = 0; nCnt < 2; nCnt++)
	{
		m_PlayerType[nCnt] = type[nCnt]->GetType();
	}
}

//================================================================================================
// タイトル処理
//================================================================================================
CGame * CGame::Create(void)
{
	CGame *pGame;

	pGame = new CGame();

	pGame->Init();

	return pGame;
}

void CGame::DeletePlayer(int cnt)
{
	if (m_Player[cnt])
	{
		m_Player[cnt] = NULL;
	}
}