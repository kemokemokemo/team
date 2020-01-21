//=============================================================================
//
// プレイヤー処理 [player.cpp]
// Author : KOUTA KIMURA
//
//=============================================================================

//=============================================================================
// インクルードファイル
//=============================================================================
#include "player_Sword.h"
#include "camera.h"
#include "manager.h"
#include "renderer.h"
#include "keybord.h"
#include "pad.h"
#include "gauge.h"
#include "Scene2D.h"
#include "Scene3D.h"
#include "model.h"

//=============================================================================
// マクロ定義
//=============================================================================
#define PLAYER_SPEED	(1.8f)						//プレイヤーの速さ
#define PLAYER_AIRSPEED	(1.5f)						//空中でのプレイヤーの速さ
#define PLAYER_AIRATKSPEED	(0.7f)						//空中でのプレイヤーの速さ
#define PLAYER_JUMP (90.0f)						//ジャンプの高さ
#define PLAYER_AIRJUMP (60.0f)					//空中ジャンプの高さ
#define LIGHT_ATK (9)					//弱攻撃に派生できるフレーム

//=============================================================================
// メンバ変数初期化
//=============================================================================

//=============================================================================
// コンストラクタ
//=============================================================================
CPlayer_SWORD::CPlayer_SWORD(OBJTYPE type) : CPlayerBase(type)
{
}

//=============================================================================
// デストラクタ
//=============================================================================
CPlayer_SWORD::~CPlayer_SWORD()
{

}

//=============================================================================
// モデルの生成
//=============================================================================
CPlayer_SWORD * CPlayer_SWORD::Create(D3DXVECTOR3 pos, D3DXVECTOR3 rot, CMaker::MAKERTYPE MokerType)
{
	CPlayer_SWORD *pPlayer;
	pPlayer = new CPlayer_SWORD(OBJTYPE_PLAYER);

	pPlayer->Init(pos, rot, MokerType);
	return pPlayer;
}

//=============================================================================
// 初期化処理
//=============================================================================
HRESULT CPlayer_SWORD::Init(D3DXVECTOR3 pos, D3DXVECTOR3 rot, CMaker::MAKERTYPE MokerType)
{
	m_nLife = 100;
	m_TypeChara = CPlayer_SWORD::PLAYERTYPE_SWORD;
	CPlayerBase::Init(pos, rot, m_nLife, MokerType);
	m_fDiffrot.y = D3DX_PI*0.5f;

	m_fRadius = 25.0f;
	m_fAttack = 50.0f;

	m_fSpeed = PLAYER_SPEED;
	m_fAirSpeed = PLAYER_AIRSPEED;
	m_fAirAtkSpeed = PLAYER_AIRATKSPEED;
	m_fJump = PLAYER_JUMP;
	m_fAirJump = PLAYER_AIRJUMP;
	m_fLightAtk = LIGHT_ATK;


	return S_OK;
}
//=============================================================================
// 終了処理
//=============================================================================
void CPlayer_SWORD::Uninit(void)
{
	CPlayerBase::Uninit();
}

//=============================================================================
// 更新処理
//=============================================================================
void CPlayer_SWORD::Update(void)
{
	CPlayerBase::Update();
}

//=============================================================================
// 描画処理
//=============================================================================
void CPlayer_SWORD::Draw(void)
{
	CPlayerBase::Draw();
}