//====================================================================================================
//
// リザルト処理 (Result.cpp)
// Author  Kimura Kouta
//
//====================================================================================================
#include"Result.h"//インクルードファイル
#include"manager.h"
#include"renderer.h"
#include"input.h"
#include"keybord.h"
#include "pad.h"
#include "player_Ken.h"
#include "player_Sword.h"
#include "player_Kangaroo.h"
#include "model.h"
#include "camera.h"

//====================================================================================================
// マクロ定義
//==================================================================================================== 

//=====================================================================================================
// 前方宣言初期化
//=====================================================================================================
CMaker::MAKERTYPE CResult::m_nRank = {};
CPlayerBase::PLAYERTYPE CResult::m_WinType = {};

//================================================================================================
// コンストラクタ
//=================================================================================================
CResult::CResult()
{

}

//================================================================================================
// デストラクタ
//=================================================================================================
CResult::~CResult()
{

}

//================================================================================================
// 背景の初期化
//=================================================================================================
HRESULT CResult::Init(void)
{
	CPlayerBase::Load();
	CModel::Load();

	CModel::Create(D3DXVECTOR3(0.0f, 0.0f, 0.0f), D3DXVECTOR3(0.0f, 0.0f, 0.0f), CModel::UNITTYPE_FLOOR);

	switch (m_WinType)
	{
	case CPlayerBase::PLAYERTYPE_KEN:
		m_Player = CPlayer_KEN::Create(D3DXVECTOR3(0, 500.0f, 0.0f), D3DXVECTOR3(0.0f, 0.0f, 0.0f), (CMaker::MAKERTYPE)m_nRank);
		break;

	case CPlayerBase::PLAYERTYPE_KANGAROO:
		m_Player = CPlayer_Kangaroo::Create(D3DXVECTOR3(0, 500.0f, 0.0f), D3DXVECTOR3(0.0f, 0.0f, 0.0f), (CMaker::MAKERTYPE)m_nRank);
		break;

	case CPlayerBase::PLAYERTYPE_SWORD:
		m_Player = CPlayer_SWORD::Create(D3DXVECTOR3(0, 500.0f, 0.0f), D3DXVECTOR3(0.0f, 0.0f, 0.0f), (CMaker::MAKERTYPE)m_nRank);
		break;
	}

	return S_OK;
}

//================================================================================================
// 背景の開放処理
//=================================================================================================
void CResult::Uninit(void)
{
	CPlayerBase::Unload();
	CModel::Unload();

}

//================================================================================================
// 背景の更新処理
//=================================================================================================
void CResult::Update(void)
{
	CKeybord *pKetybord = CManager::GetKeybord();
	CPad *pGamePad = CManager::GetPad();

	if (CFade::GetFade() == CFade::FADE_NONE)
	{
		if (pKetybord->GetKeyboardTrigger(DIK_RETURN) || pGamePad->GetJoypadTrigger(0, CPad::JOYPADKEY_START))
		{
			CFade::SetFade(CManager::MODE_RANKING);
		}
	}

	CCamera::SetCameraPos(D3DXVECTOR3(0.0f, 0.0f, 0.0f), &D3DXVECTOR3(0.0f, 0.0f, 0.0f));
}

//================================================================================================
// 背景の描画処理
//=================================================================================================
void CResult::Draw(void)
{

}

//================================================================================================
// タイトル処理
//================================================================================================
CResult * CResult::Create(void)
{
	CResult *pResult;

	pResult = new CResult();

	pResult->Init();

	return pResult;
}

void CResult::SetWinPlayer(CPlayerBase::PLAYERTYPE type, CMaker::MAKERTYPE p)
{
	m_nRank = p;
	m_WinType = type;
}
