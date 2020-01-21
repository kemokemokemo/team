//=============================================================================
//
// プレイヤー処理 [player.cpp]
// Author : KOUTA KIMURA
//
//=============================================================================

//=============================================================================
// インクルードファイル
//=============================================================================
#include "player_ken.h"
#include "camera.h"
#include "manager.h"
#include "renderer.h"
#include "keybord.h"
#include "pad.h"
#include "gauge.h"
#include "Scene2D.h"
#include "model.h"

//=============================================================================
// マクロ定義
//===========================================================================
#define KPLAYER_SPEED	(2.0f)					//プレイヤーの速さ
#define KPLAYER_AIRSPEED	(1.8f)					//空中でのプレイヤーの速さ
#define KPLAYER_AIRATKSPEED	(0.8f)					//空中でのプレイヤーの速さ
#define KPLAYER_JUMP (100.0f)					//ジャンプの高さ
#define KPLAYER_AIRJUMP (80.0f)					//空中ジャンプの高さ
#define KLIGHT_ATK (9)					//弱攻撃に派生できるフレーム

//=============================================================================
// メンバ変数初期化
//=============================================================================

//=============================================================================
// コンストラクタ
//=============================================================================
CPlayer_KEN::CPlayer_KEN(OBJTYPE type) : CPlayerBase(type)
{

}

//=============================================================================
// デストラクタ
//=============================================================================
CPlayer_KEN::~CPlayer_KEN()
{

}

//=============================================================================
// モデルの生成
//=============================================================================
CPlayer_KEN * CPlayer_KEN::Create(D3DXVECTOR3 pos, D3DXVECTOR3 rot, CMaker::MAKERTYPE MokerType)
{
	CPlayer_KEN *pPlayer;
	pPlayer = new CPlayer_KEN(OBJTYPE_PLAYER);

	pPlayer->Init(pos, rot, MokerType);
	return pPlayer;
}

//=============================================================================
// 初期化処理
//=============================================================================
HRESULT CPlayer_KEN::Init(D3DXVECTOR3 pos, D3DXVECTOR3 rot, CMaker::MAKERTYPE MokerType)
{
	m_nLife = 100;

	m_TypeChara = CPlayer_KEN::PLAYERTYPE_KEN;
	CPlayerBase::Init(pos, rot, m_nLife, MokerType);


	m_fDiffrot.y = D3DX_PI*-0.5f;
	m_fRadius = 15.0f;
	m_fAttack = 30.0f;

	m_fSpeed = KPLAYER_SPEED;
	m_fAirSpeed = KPLAYER_AIRSPEED;
	m_fAirAtkSpeed = KPLAYER_AIRATKSPEED;
	m_fJump = KPLAYER_JUMP;
	m_fAirJump = KPLAYER_AIRJUMP;
	m_fLightAtk = KLIGHT_ATK;



	return S_OK;
}
//=============================================================================
// 終了処理
//=============================================================================
void CPlayer_KEN::Uninit(void)
{
	CPlayerBase::Uninit();
}

//=============================================================================
// 更新処理
//=============================================================================
void CPlayer_KEN::Update(void)
{
	CKeybord *pKeyboard = CManager::GetKeybord();

	CPad *pGamePad = CManager::GetPad();


	//switch (m_MotionType)
	//{
	//case MOTIONTYPE_LIGHT0:
	//	nCountATK++;
	//	if (nCountATK >= 0 && nCountATK <= 5)
	//	{
	//		if (m_fDiffrot.y == D3DX_PI*0.5f)
	//		{
	//			m_move.x -= 1.5f;
	//		}
	//		else
	//		{
	//			m_move.x += 1.5f;
	//		}
	//	}
	//	if (nCountATK >= KLIGHT_ATK)
	//	{
	//		if (pKeyboard->GetKeyboardTrigger(DIK_SPACE))
	//		{
	//			nCountATK = 0;
	//			MotionChangePlayer(MOTIONTYPE_LIGHT1);
	//		}
	//	}
	//	break;
	//case MOTIONTYPE_LIGHT1:
	//	nCountATK++;
	//	if (nCountATK >= 0 && nCountATK <= 5)
	//	{
	//		if (m_fDiffrot.y == D3DX_PI*0.5f)
	//		{
	//			m_move.x -= 1.0f;
	//		}
	//		else
	//		{
	//			m_move.x += 1.0f;
	//		}
	//	}
	//	if (nCountATK >= KLIGHT_ATK)
	//	{
	//		if (pKeyboard->GetKeyboardTrigger(DIK_SPACE))
	//		{
	//			nCountATK = 0;
	//			MotionChangePlayer(MOTIONTYPE_LIGHT2);
	//		}
	//	}
	//	break;
	//case MOTIONTYPE_LIGHT2:
	//	nCountATK++;
	//	if (nCountATK >= 0 && nCountATK <= 5)
	//	{
	//		if (m_fDiffrot.y == D3DX_PI*0.5f)
	//		{
	//			m_move.x -= 1.5f;
	//		}
	//		else
	//		{
	//			m_move.x += 1.5f;
	//		}
	//	}

	//	break;
	//case MOTIONTYPE_DASHATK:
	//	nCountATK++;
	//	if (nCountATK >= 1 && nCountATK <= 34)
	//	{
	//		if (m_fDiffrot.y == D3DX_PI*0.5f)
	//		{
	//			m_move.x -= 1.5f;
	//		}
	//		else
	//		{
	//			m_move.x += 1.5f;
	//		}
	//	}
	//	break;
	//case MOTIONTYPE_SP_UP:
	//	if (m_fDiffrot.y == D3DX_PI*0.5f)
	//	{
	//		m_move.x -= 1.3f;
	//	}
	//	else
	//	{
	//		m_move.x += 1.3f;
	//	}
	//	break;
	//case MOTIONTYPE_SP_DOWN:
	//	nCountATK++;
	//	if (nCountATK >= 45 && nCountATK <= 55)
	//	{
	//		if (m_fDiffrot.y == D3DX_PI*0.5f)
	//		{
	//			m_move.x -= 2.5f;
	//		}
	//		else
	//		{
	//			m_move.x += 2.5f;
	//		}
	//	}
	//	break;
	//case MOTIONTYPE_AIR_N:
	//case MOTIONTYPE_AIR_F:
	//case MOTIONTYPE_AIR_B:
	//case MOTIONTYPE_AIR_U:
	//case MOTIONTYPE_AIR_D:
	//	if (pKeyboard->GetKeyboardPress(DIK_D))
	//	{
	//		m_move.x += D3DX_PI*0.5f* KPLAYER_AIRATKSPEED;
	//	}
	//	else if (pKeyboard->GetKeyboardPress(DIK_A))
	//	{
	//		m_move.x += D3DX_PI*-0.5f* KPLAYER_AIRATKSPEED;
	//	}
	//	if (pKeyboard->GetKeyboardPress(DIK_S))
	//	{
	//		m_move.y -= 1.2f;
	//	}
	//	break;
	//case MOTIONTYPE_GAUDE:
	//	if (pKeyboard->GetKeyboardPress(DIK_G))
	//	{
	//		m_PlayerState = PLAYERSTATE_GAUDE;
	//	}
	//	else
	//	{
	//		MotionChangePlayer(MOTIONTYPE_WAIT);
	//	}
	//}


	CPlayerBase::Update();
}

//=============================================================================
// 描画処理
//=============================================================================
void CPlayer_KEN::Draw(void)
{
	CPlayerBase::Draw();
}