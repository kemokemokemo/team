//=============================================================================
//
// プレイヤー処理 [player.cpp]
// Author : KOUTA KIMURA
//
//=============================================================================

//=============================================================================
// インクルードファイル
//=============================================================================
#include "player_kangaroo.h"
#include "camera.h"
#include "manager.h"
#include "renderer.h"
#include "keybord.h"
#include "pad.h"
#include "gauge.h"
#include "Scene2D.h"

//=============================================================================
// マクロ定義
//=============================================================================
#define ROOPLAYER_SPEED	(1.5f)					//プレイヤーの速さ
#define ROOPLAYER_AIRSPEED	(1.5f)					//空中でのプレイヤーの速さ
#define ROOPLAYER_AIRATKSPEED	(0.5f)					//空中でのプレイヤーの速さ
#define ROOPLAYER_JUMP (120.0f)					//ジャンプの高さ
#define ROOPLAYER_AIRJUMP (90.0f)					//空中ジャンプの高さ
#define ROOLIGHT_ATK (9)					//弱攻撃に派生できるフレーム

//=============================================================================
// メンバ変数初期化
//=============================================================================

//=============================================================================
// コンストラクタ
//=============================================================================
CPlayer_Kangaroo::CPlayer_Kangaroo(OBJTYPE type) : CPlayerBase(type)
{

}

//=============================================================================
// デストラクタ
//=============================================================================
CPlayer_Kangaroo::~CPlayer_Kangaroo()
{

}

//=============================================================================
// モデルの生成
//=============================================================================
CPlayer_Kangaroo * CPlayer_Kangaroo::Create(D3DXVECTOR3 pos, D3DXVECTOR3 rot, CMaker::MAKERTYPE MokerType)
{
	CPlayer_Kangaroo *pPlayer;
	pPlayer = new CPlayer_Kangaroo(OBJTYPE_PLAYER);

	pPlayer->Init(pos, rot, MokerType);
	return pPlayer;
}

//=============================================================================
// 初期化処理
//=============================================================================
HRESULT CPlayer_Kangaroo::Init(D3DXVECTOR3 pos, D3DXVECTOR3 rot, CMaker::MAKERTYPE MokerType)
{
	m_nLife = 100;

	m_TypeChara = CPlayer_Kangaroo::PLAYERTYPE_KANGAROO;
	CPlayerBase::Init(pos, rot, m_nLife, MokerType);

	m_fRadius = 60.0f;
	m_fAttack = 60.0f;

	m_fSpeed = ROOPLAYER_SPEED;
	m_fAirSpeed = ROOPLAYER_AIRSPEED;
	m_fAirAtkSpeed = ROOPLAYER_AIRATKSPEED;
	m_fJump = ROOPLAYER_JUMP;
	m_fAirJump = ROOPLAYER_AIRJUMP;
	m_fLightAtk = ROOLIGHT_ATK;

	return S_OK;
}
//=============================================================================
// 終了処理
//=============================================================================
void CPlayer_Kangaroo::Uninit(void)
{
	CPlayerBase::Uninit();
}

//=============================================================================
// 更新処理
//=============================================================================
void CPlayer_Kangaroo::Update(void)
{
	CPlayerBase::Update();
}

//=============================================================================
// 描画処理
//=============================================================================
void CPlayer_Kangaroo::Draw(void)
{
	CPlayerBase::Draw();
}