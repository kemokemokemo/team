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
#define PLAYER_SPEED	(2.0f)						//プレイヤーの速さ
#define MODELFILE1		"DATA/MODEL/car_000.x"		// 読み込むモデル
#define MODELFILE2		"DATA/MODEL/cat.x"			// 読み込むモデル

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
	m_TypeChara = CPlayer_Kangaroo::PLAYERTYPE_KANGAROO;
	CPlayerBase::Init(pos, rot, MokerType);

	m_nLife = 5;

	m_fRadius = 100.0f;
	m_fAttack = 50.0f;

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
	CKeybord *pKeyboard = CManager::GetKeybord();

	if (pKeyboard->GetKeyboardTrigger(DIK_RETURN))
	{
		m_MotionType = MOTIONTYPE_RUN;
	}

	CPlayerBase::Update();
}

//=============================================================================
// 描画処理
//=============================================================================
void CPlayer_Kangaroo::Draw(void)
{
	CPlayerBase::Draw();
}