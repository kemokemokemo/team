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
CPlayer_SWORD * CPlayer_SWORD::Create(D3DXVECTOR3 pos, D3DXVECTOR3 rot)
{
	CPlayer_SWORD *pPlayer;
	pPlayer = new CPlayer_SWORD(OBJTYPE_PLAYER);

	pPlayer->Init(pos, rot);
	return pPlayer;
}

//=============================================================================
// 初期化処理
//=============================================================================
HRESULT CPlayer_SWORD::Init(D3DXVECTOR3 pos, D3DXVECTOR3 rot)
{
	m_TypeChara = CPlayer_SWORD::PLAYERTYPE_SWORD;
	CPlayerBase::Init(pos, rot);

	m_nLife = 3;

	m_fRadius = 50.0f;
	m_fAttack = 20.0f;

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
	CKeybord *pKeyboard = CManager::GetKeybord();
	MODELNUM model = GetModel();

	if (m_PlayerState != PLAYERSTATE_ATK)
	{
		if (pKeyboard->GetKeyboardPress(DIK_LEFTARROW))
		{//  A キー操作
			m_move.x += D3DX_PI*-0.5f* PLAYER_SPEED;
			m_fDiffrot.y = D3DX_PI*0.5f;
			model.motionType = MOTIONTYPE_RUN;
			if (pKeyboard->GetKeyboardTrigger(DIK_L))
			{
				model.motionType = MOTIONTYPE_DASHATK;
			}
		}
		else if (pKeyboard->GetKeyboardPress(DIK_RIGHTARROW))
		{//  D キー操作
			m_move.x += D3DX_PI*0.5f * PLAYER_SPEED;
			m_fDiffrot.y = D3DX_PI*-0.5f;
			model.motionType = MOTIONTYPE_RUN;
			if (pKeyboard->GetKeyboardTrigger(DIK_L))
			{
				model.motionType = MOTIONTYPE_DASHATK;
			}
		}
		else if (model.motionType == MOTIONTYPE_RUN)
		{// 移動をやめた場合
		 // モーションの切り替え
			model.motionType = MOTIONTYPE_WAIT;
		}

		else if (pKeyboard->GetKeyboardPress(DIK_UPARROW))
		{// W キー操作
			if (pKeyboard->GetKeyboardTrigger(DIK_L))
			{
				model.motionType = MOTIONTYPE_UPATK;
			}
		}

		else if (pKeyboard->GetKeyboardPress(DIK_DOWNARROW))
		{
			model.motionType = MOTIONTYPE_CROUCHWAIT;
			if (pKeyboard->GetKeyboardTrigger(DIK_L))
			{
				model.motionType = MOTIONTYPE_CROUCHATK;
			}
		}
		else if (model.motionType == MOTIONTYPE_CROUCHWAIT)
		{// 移動をやめた場合vbn
		 // モーションの切り替え
			model.motionType = MOTIONTYPE_WAIT;
		}

		else if (pKeyboard->GetKeyboardTrigger(DIK_L))
		{
			//3段攻撃
			if (model.motionType == MOTIONTYPE_LIGHT0)
			{
				model.motionType = MOTIONTYPE_LIGHT1;
			}
			else if (model.motionType == MOTIONTYPE_LIGHT1)
			{
				model.motionType = MOTIONTYPE_LIGHT2;
			}
			else
			{
				model.motionType = MOTIONTYPE_LIGHT0;
			}
		}
	}	
	SetModel(model);

	CPlayerBase::Update();
}

//=============================================================================
// 描画処理
//=============================================================================
void CPlayer_SWORD::Draw(void)
{
	CPlayerBase::Draw();
}