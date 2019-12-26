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
#define PLAYER_SPEED	(2.0f)					//プレイヤーの速さ
#define PLAYER_AIRSPEED	(1.8f)					//空中でのプレイヤーの速さ
#define PLAYER_AIRATKSPEED	(0.8f)					//空中でのプレイヤーの速さ
#define PLAYER_JUMP (100.0f)					//ジャンプの高さ
#define PLAYER_AIRJUMP (80.0f)					//空中ジャンプの高さ
#define LIGHT_ATK (9)					//弱攻撃に派生できるフレーム

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
	m_TypeChara = CPlayer_KEN::PLAYERTYPE_KEN;
	CPlayerBase::Init(pos, rot, MokerType);

	m_nLife = 12;
	m_fDiffrot.y = D3DX_PI*-0.5f;
	m_fRadius = 20.0f;
	m_fAttack = 30.0f;

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

	PlayerCollisionFloor();

	if (m_PlayerState != PLAYERSTATE_ATK)
	{
		if (GetJump() == false)
		{
			if (pKeyboard->GetKeyboardTrigger(DIK_J))
			{//ジャンプ
				if (bWJump == false)
				{
					SetJump(true);
					bWJump = true;
					m_move.y += PLAYER_JUMP;
				}
			}
			else if (pKeyboard->GetKeyboardPress(DIK_A))
			{//  A キー操作
				m_move.x += D3DX_PI*-0.5f* PLAYER_SPEED;
				m_fDiffrot.y = D3DX_PI*0.5f;
				MotionChangePlayer(MOTIONTYPE_RUN);
				if (pKeyboard->GetKeyboardTrigger(DIK_SPACE))
				{
					MotionChangePlayer(MOTIONTYPE_DASHATK);
				}
				else if (pKeyboard->GetKeyboardTrigger(DIK_B))
				{//特殊攻撃ニュートラル
					MotionChangePlayer(MOTIONTYPE_SP_N);
				}
			}
			else if (pKeyboard->GetKeyboardPress(DIK_D))
			{//  D キー操作
				m_move.x += D3DX_PI*0.5f * PLAYER_SPEED;
				m_fDiffrot.y = D3DX_PI*-0.5f;
				MotionChangePlayer(MOTIONTYPE_RUN);
				if (pKeyboard->GetKeyboardTrigger(DIK_SPACE))
				{
					MotionChangePlayer(MOTIONTYPE_DASHATK);
				}
				else if (pKeyboard->GetKeyboardTrigger(DIK_B))
				{//特殊攻撃ニュートラル
					MotionChangePlayer(MOTIONTYPE_SP_N);
				}
			}
			else if (m_MotionType == MOTIONTYPE_RUN)
			{// 移動をやめた場合
			 // モーションの切り替え
				MotionChangePlayer(MOTIONTYPE_WAIT);
			}

			else if (pKeyboard->GetKeyboardPress(DIK_W))
			{// W キー操作
				if (pKeyboard->GetKeyboardTrigger(DIK_SPACE))
				{
					MotionChangePlayer(MOTIONTYPE_UPATK);
				}
				else if (pKeyboard->GetKeyboardTrigger(DIK_B))
				{//特殊攻撃上
					MotionChangePlayer(MOTIONTYPE_SP_UP);
				}
			}

			else if (pKeyboard->GetKeyboardPress(DIK_S))
			{
				MotionChangePlayer(MOTIONTYPE_CROUCHWAIT);
				if (pKeyboard->GetKeyboardTrigger(DIK_SPACE))
				{
					MotionChangePlayer(MOTIONTYPE_CROUCHATK);
				}
				else if (pKeyboard->GetKeyboardTrigger(DIK_B))
				{//特殊攻撃下
					MotionChangePlayer(MOTIONTYPE_SP_DOWN);
				}
			}

			else if (m_MotionType == MOTIONTYPE_CROUCHWAIT)
			{// 移動をやめた場合
			 // モーションの切り替え
				m_MotionType = MOTIONTYPE_WAIT;
			}
			else if (pKeyboard->GetKeyboardTrigger(DIK_B))
			{//特殊攻撃ニュートラル
				MotionChangePlayer(MOTIONTYPE_SP_N);
			}
			else if (pKeyboard->GetKeyboardTrigger(DIK_SPACE))
			{

				MotionChangePlayer(MOTIONTYPE_LIGHT0);
			}
			else if (pKeyboard->GetKeyboardPress(DIK_G))
			{
				MotionChangePlayer(MOTIONTYPE_GAUDE);
			}
		}

		//空中
		else
		{
			if (m_PlayerState != PLAYERSTATE_AIRATK)
			{
				if (m_MotionType != MOTIONTYPE_DOUBLEJUMP)
				{
					MotionChangePlayer(MOTIONTYPE_JUMP);
				}
				if (bWJump == true)
				{
					if (pKeyboard->GetKeyboardTrigger(DIK_J))
					{//二段ジャンプ
						MotionChangePlayer(MOTIONTYPE_DOUBLEJUMP);
						bWJump = false;
						m_move.y = 0.0f;
						m_move.y += PLAYER_AIRJUMP;
					}
				}
				if (pKeyboard->GetKeyboardPress(DIK_A))
				{//  A キー操作
					m_move.x += D3DX_PI*-0.5f* PLAYER_AIRSPEED;

					if (pKeyboard->GetKeyboardTrigger(DIK_SPACE))
					{
						if (m_fDiffrot.y == D3DX_PI*0.5f)
						{
							m_MotionType = MOTIONTYPE_AIR_F;
						}
						else
						{
							m_MotionType = MOTIONTYPE_AIR_B;
						}
					}
				}
				else if (pKeyboard->GetKeyboardPress(DIK_D))
				{//  D キー操作
					m_move.x += D3DX_PI*0.5f * PLAYER_AIRSPEED;
					if (pKeyboard->GetKeyboardTrigger(DIK_SPACE))
					{
						if (m_fDiffrot.y == D3DX_PI*-0.5f)
						{
							m_MotionType = MOTIONTYPE_AIR_F;
						}
						else
						{
							m_MotionType = MOTIONTYPE_AIR_B;
						}
					}
				}
				else if (pKeyboard->GetKeyboardPress(DIK_W))
				{
					if (pKeyboard->GetKeyboardTrigger(DIK_SPACE))
					{
						m_MotionType = MOTIONTYPE_AIR_U;
					}
				}
				else if (pKeyboard->GetKeyboardPress(DIK_S))
				{
					m_move.y -= 1.2f;
					if (pKeyboard->GetKeyboardTrigger(DIK_SPACE))
					{
						m_MotionType = MOTIONTYPE_AIR_D;
					}
				}
				else if (pKeyboard->GetKeyboardTrigger(DIK_SPACE))
				{
					m_MotionType = MOTIONTYPE_AIR_N;
				}
			}
		}
	}

	switch (m_MotionType)
	{
	case MOTIONTYPE_LIGHT0:
		nCountATK++;
		if (nCountATK >= 0 && nCountATK <= 5)
		{
			if (m_fDiffrot.y == D3DX_PI*0.5f)
			{
				m_move.x -= 1.5f;
			}
			else
			{
				m_move.x += 1.5f;
			}
		}
		if (nCountATK >= LIGHT_ATK)
		{
			if (pKeyboard->GetKeyboardTrigger(DIK_SPACE))
			{
				nCountATK = 0;
				MotionChangePlayer(MOTIONTYPE_LIGHT1);
			}
		}
		break;
	case MOTIONTYPE_LIGHT1:
		nCountATK++;
		if (nCountATK >= 0 && nCountATK <= 5)
		{
			if (m_fDiffrot.y == D3DX_PI*0.5f)
			{
				m_move.x -= 1.0f;
			}
			else
			{
				m_move.x += 1.0f;
			}
		}
		if (nCountATK >= LIGHT_ATK)
		{
			if (pKeyboard->GetKeyboardTrigger(DIK_SPACE))
			{
				nCountATK = 0;
				MotionChangePlayer(MOTIONTYPE_LIGHT2);
			}
		}
		break;
	case MOTIONTYPE_LIGHT2:
		nCountATK++;
		if (nCountATK >= 0 && nCountATK <= 5)
		{
			if (m_fDiffrot.y == D3DX_PI*0.5f)
			{
				m_move.x -= 1.5f;
			}
			else
			{
				m_move.x += 1.5f;
			}
		}

		break;
	case MOTIONTYPE_DASHATK:
		nCountATK++;
		if (nCountATK >= 1 && nCountATK <= 34)
		{
			if (m_fDiffrot.y == D3DX_PI*0.5f)
			{
				m_move.x -= 1.5f;
			}
			else
			{
				m_move.x += 1.5f;
			}
		}
		break;
	case MOTIONTYPE_SP_UP:
		if (m_fDiffrot.y == D3DX_PI*0.5f)
		{
			m_move.x -= 1.3f;
		}
		else
		{
			m_move.x += 1.3f;
		}
		break;
	case MOTIONTYPE_SP_DOWN:
		nCountATK++;
		if (nCountATK >= 45 && nCountATK <= 55)
		{
			if (m_fDiffrot.y == D3DX_PI*0.5f)
			{
				m_move.x -= 2.5f;
			}
			else
			{
				m_move.x += 2.5f;
			}
		}
		break;
	case MOTIONTYPE_AIR_N:
	case MOTIONTYPE_AIR_F:
	case MOTIONTYPE_AIR_B:
	case MOTIONTYPE_AIR_U:
	case MOTIONTYPE_AIR_D:
		if (pKeyboard->GetKeyboardPress(DIK_D))
		{
			m_move.x += D3DX_PI*0.5f* PLAYER_AIRATKSPEED;
		}
		else if (pKeyboard->GetKeyboardPress(DIK_A))
		{
			m_move.x += D3DX_PI*-0.5f* PLAYER_AIRATKSPEED;
		}
		if (pKeyboard->GetKeyboardPress(DIK_S))
		{
			m_move.y -= 1.2f;
		}
		break;
	case MOTIONTYPE_GAUDE:
		if (pKeyboard->GetKeyboardPress(DIK_G))
		{
			m_PlayerState = PLAYERSTATE_GAUDE;
		}
		else
		{
			MotionChangePlayer(MOTIONTYPE_WAIT);
		}
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