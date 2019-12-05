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
CPlayer_KEN * CPlayer_KEN::Create(D3DXVECTOR3 pos, D3DXVECTOR3 rot)
{
	CPlayer_KEN *pPlayer;
	pPlayer = new CPlayer_KEN(OBJTYPE_PLAYER);

	pPlayer->Init(pos, rot);
	return pPlayer;
}

//=============================================================================
// 初期化処理
//=============================================================================
HRESULT CPlayer_KEN::Init(D3DXVECTOR3 pos, D3DXVECTOR3 rot)
{
	m_TypeChara = CPlayer_KEN::PLAYERTYPE_KEN;
	CPlayerBase::Init(pos, rot);

	m_nLife = 3;

	m_fRadius = 50.0f;
	m_fAttack = 20.0f;

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

	if (m_PlayerState != PLAYERSTATE_ATK)
	{
		if (pKeyboard->GetKeyboardPress(DIK_A))
		{//  A キー操作
			m_move.x += D3DX_PI*-0.5f* PLAYER_SPEED;
			m_fDiffrot.y = D3DX_PI*0.5f;
			MotionChangePlayer(MOTIONTYPE_RUN);
			if (pKeyboard->GetKeyboardTrigger(DIK_SPACE))
			{
				MotionType = MOTIONTYPE_DASHATK;
			}
			else if (pKeyboard->GetKeyboardTrigger(DIK_B))
			{//特殊攻撃ニュートラル
				MotionType = MOTIONTYPE_SP_N;
			}
		}
		else if (pKeyboard->GetKeyboardPress(DIK_D))
		{//  D キー操作
			m_move.x += D3DX_PI*0.5f * PLAYER_SPEED;
			m_fDiffrot.y = D3DX_PI*-0.5f;
			MotionType = MOTIONTYPE_RUN;
			if (pKeyboard->GetKeyboardTrigger(DIK_SPACE))
			{
				MotionType = MOTIONTYPE_DASHATK;
			}
			else if (pKeyboard->GetKeyboardTrigger(DIK_B))
			{//特殊攻撃ニュートラル
				MotionType = MOTIONTYPE_SP_N;
			}
		}
		else if (MotionType == MOTIONTYPE_RUN)
		{// 移動をやめた場合
		 // モーションの切り替え
			MotionType = MOTIONTYPE_WAIT;
		}

		else if (pKeyboard->GetKeyboardPress(DIK_W))
		{// W キー操作
			if (pKeyboard->GetKeyboardTrigger(DIK_SPACE))
			{
				MotionType = MOTIONTYPE_UPATK;
			}
			else if (pKeyboard->GetKeyboardTrigger(DIK_B))
			{//特殊攻撃上
				MotionType = MOTIONTYPE_SP_UP;
			}
		}

		else if (pKeyboard->GetKeyboardPress(DIK_S))
		{
			MotionType = MOTIONTYPE_CROUCHWAIT;
			if (pKeyboard->GetKeyboardTrigger(DIK_SPACE))
			{
				MotionType = MOTIONTYPE_CROUCHATK;
			}
			else if (pKeyboard->GetKeyboardTrigger(DIK_B))
			{//特殊攻撃下
				MotionType = MOTIONTYPE_SP_DOWN;
			}
		}

		else if (MotionType == MOTIONTYPE_CROUCHWAIT)
		{// 移動をやめた場合vbn
		 // モーションの切り替え
			MotionType = MOTIONTYPE_WAIT;
		}
		else if (pKeyboard->GetKeyboardTrigger(DIK_B))
		{//特殊攻撃ニュートラル
			MotionType = MOTIONTYPE_SP_N;
		}
		else if (pKeyboard->GetKeyboardTrigger(DIK_SPACE))
		{
			//3段攻撃
			if (MotionType == MOTIONTYPE_LIGHT0)
			{
				MotionType = MOTIONTYPE_LIGHT1;
			}
			else if (MotionType == MOTIONTYPE_LIGHT1)
			{
				MotionType = MOTIONTYPE_LIGHT2;
			}
			else
			{
				MotionType = MOTIONTYPE_LIGHT0;
			}
		}
	}
	switch (MotionType)
	{
	case MOTIONTYPE_SP_UP:
		if (m_fDiffrot.y == D3DX_PI*0.5f)
		{
			m_move.x -= 1.5f;
		}
		else
		{
			m_move.x += 1.5f;
		}
		break;
	}

	CPlayerBase::Update();
}

//=============================================================================
// 描画処理
//=============================================================================
void CPlayer_KEN::Draw(void)
{
	CPlayerBase::Draw();
}