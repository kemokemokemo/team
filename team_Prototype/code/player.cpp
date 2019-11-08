//=============================================================================
//
// プレイヤー処理 [player.cpp]
// Author : KOUTA KIMURA
//
//=============================================================================

//=============================================================================
// インクルードファイル
//=============================================================================
#include "player.h"
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
//  メンバ変数初期化
//=============================================================================
DWORD			CPlayer::nNumMat[MODELTYPE_MAX] = {};
LPD3DXMESH		CPlayer::pMesh[MODELTYPE_MAX] = {};
LPD3DXBUFFER	CPlayer::pBuffMat[MODELTYPE_MAX] = {};

//=============================================================================
// コンストラクタ
//=============================================================================
CPlayer::CPlayer(OBJTYPE type) : CScene3D(type)
{
	m_move = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	m_PlayerStateCount = 0;
}

//=============================================================================
// デストラクタ
//=============================================================================
CPlayer::~CPlayer()
{

}

//=============================================================================
// モデルの生成
//=============================================================================
CPlayer * CPlayer::Create(D3DXVECTOR3 pos, D3DXVECTOR3 rot, MODELTYPE type, PLAYERNUM PlayerNum)
{
	CPlayer *pPlayer;
	pPlayer = new CPlayer(OBJTYPE_PLAYER);
	pPlayer->BindModel(nNumMat[type], pMesh[type], pBuffMat[type]);
	pPlayer->Init(pos, rot, type, PlayerNum);
	return pPlayer;
}

//=============================================================================
// 初期化処理
//=============================================================================
HRESULT CPlayer::Init(D3DXVECTOR3 pos, D3DXVECTOR3 rot, MODELTYPE type, PLAYERNUM PlayerNum)
{
	CScene3D::Init();

	CScene3D::SetPos(pos);

	CScene3D::SetType(type);

	m_PlayerNum = PlayerNum;

	m_PlayerStateCount = 0;

	m_PlayerState = PLAYERSTATE_NORMAL;

	switch (type)
	{
	case MODELTYPE_CAR:
		m_nLife = 3;
		//pLifeGauge = CGauge::Create(D3DXVECTOR3(200.0f, 600.0f, 0.0f));
		break;

	case MODELTYPE_CAT:
		m_nLife = 5;
		//pLifeGauge = CGauge::Create(D3DXVECTOR3(200.0f, 600.0f, 0.0f));
		break;
	}

	return S_OK;
}

//=============================================================================
// 終了処理
//=============================================================================
void CPlayer::Uninit(void)
{
	CScene3D::Uninit();
}

//=============================================================================
// 更新処理
//=============================================================================
void CPlayer::Update(void)
{
	CScene3D::Update();

	switch (m_PlayerNum)
	{
	case PLAYER_01:
		PlayerMove();
		break;

	case PLAYER_02:
		PlayerMove();
		break;

	case PLAYER_03:
		//PlayerMove();
		break;

	case PLAYER_04:
		//PlayerMove();
		break;
	}
	switch (m_PlayerState)
	{
	case PLAYERSTATE_NORMAL:

		break;
	case PLAYERSTATE_DAMAGE:
			m_PlayerStateCount--;
			if (m_PlayerStateCount <= 0)
			{
				m_PlayerState = PLAYERSTATE_NORMAL;
			}
		break;
	}

	SetLife(m_nLife);

	GetPlayerPos();

	MoveLimit();

}

//=============================================================================
// 描画処理
//=============================================================================
void CPlayer::Draw(void)
{
	CScene3D::DrawModel();
}

//=============================================================================
// プレイヤーの移動制限と重力
//=============================================================================
void CPlayer::MoveLimit(void)
{
	D3DXVECTOR3 pos = CScene3D::GetPos();

	m_move.y--;

	if (pos.y <= 0)
	{
		pos.y = 0;
	}
	CScene3D::SetPos(pos);
}

//=============================================================================
// プレイヤーの移動処理
//=============================================================================
D3DXVECTOR3 CPlayer::GetPlayerPos(void)
{
	D3DXVECTOR3 pos = CScene3D::GetPos();

	return pos;
}

//=============================================================================
// プレイヤーの移動処理
//=============================================================================
void CPlayer::PlayerMove(void)
{
	CKeybord *pKetybord = CManager::GetKeybord();


	D3DXVECTOR3 pos;
	D3DXVECTOR3 rot;

	pos = CScene3D::GetPos();

	rot = CScene3D::GetRot();

	pos += m_move;

	if (m_PlayerNum == PLAYER_01)
	{
		if (pKetybord->GetKeyboardPress(DIK_A))
		{//  A キー操作
			m_move.x += D3DX_PI*-0.5f* PLAYER_SPEED;

			m_fDiffrot.y = D3DX_PI*0.5f;
		}

		else if (pKetybord->GetKeyboardPress(DIK_D))
		{//  D キー操作
			m_move.x += D3DX_PI*0.5f * PLAYER_SPEED;
			m_fDiffrot.y = D3DX_PI*-0.5f;
		}

		else if (pKetybord->GetKeyboardTrigger(DIK_W))
		{// W キー操作
			m_move.y += 50;
		}

		if (pKetybord->GetKeyboardTrigger(DIK_SPACE))
		{//  Zキー操作 攻撃
			PlayerCollision();
		}
	}

	if (m_PlayerNum == PLAYER_02)
	{
		if (pKetybord->GetKeyboardPress(DIK_LEFTARROW))
		{//  A キー操作
			m_move.x += D3DX_PI*-0.5f* PLAYER_SPEED;
			m_fDiffrot.y = D3DX_PI*0.5f;
		}

		else if (pKetybord->GetKeyboardPress(DIK_RIGHTARROW))
		{//  D キー操作
			m_move.x += D3DX_PI*0.5f * PLAYER_SPEED;
			m_fDiffrot.y = D3DX_PI*-0.5f;
		}

		else if (pKetybord->GetKeyboardTrigger(DIK_UPARROW))
		{//  S キー操作
			m_move.y += 50;
		}

		if (pKetybord->GetKeyboardTrigger(DIK_RETURN))
		{//  Xキー操作 攻撃
			PlayerCollision();
		}
	}

	// 差分
	if (m_fDistance.y = m_fDiffrot.y - rot.y)
	{
		if (D3DX_PI < m_fDistance.y)
		{
			m_fDistance.y -= D3DX_PI * 2;
		}
		else if (-D3DX_PI > m_fDistance.y)
		{
			m_fDistance.y += D3DX_PI * 2;
		}
	}

	rot.y += m_fDistance.y * 0.2f;
	
	CPad *pPad = CManager::GetPad();

	// 入力された X、Y
	float fH, fV;
	pPad->GetJoypadStickLeft(0, &fH, &fV);

	//ゲームパッド
	if (fH != 0 || fV != 0)
	{// 移動
		m_move.x += sinf(atan2f(fH, fV)) * PLAYER_SPEED;
		m_move.y += cosf(atan2f(fH, fV)) * PLAYER_SPEED;
	}

		//慣性処理
		m_move.x += (0 - m_move.x) * 1 / 5;
		m_move.y += (0 - m_move.y) * 1 / 5;

		CScene3D::SetPos(pos);
		CScene3D::SetRot(rot);
}

//====================================================================================================
// プレイヤーのダメージ処理
//=====================================================================================================
void CPlayer::PlayerDamage(void)
{
	switch (m_PlayerNum)
	{
	case PLAYER_01:
		Damage(1);
			break;

	case PLAYER_02:
		Damage(1);
		break;

	case PLAYER_03:
		//PlayerMove();
		break;

	case PLAYER_04:
		//PlayerMove();
		break;
	}
}

//====================================================================================================
// プレイヤーのダメージ処理
//=====================================================================================================
void CPlayer::Damage(int nDamage)
{
	if (m_PlayerState == PLAYERSTATE_NORMAL)
	{
		
		m_nLife -= nDamage;
		m_PlayerState = PLAYERSTATE_DAMAGE;
		m_PlayerStateCount = 60;
	}
	else if (m_nLife <= 0)
	{
		Release();
	}
}
//========================================================================================================
// プレイヤーの当たり判定
//========================================================================================================
void CPlayer::PlayerCollision()
{
	//半径
	float fRadiusPL01 = 20;
	float fRadiusPL02 = 20;

	for (int nCntScene = 0; nCntScene < 256; nCntScene++)
	{
		CScene *pScene;

		pScene = CScene::GetScene(OBJTYPE_PLAYER, nCntScene);

		if (pScene != NULL)
		{
			CScene::OBJTYPE objtype;
			objtype = pScene->GetObjType();

			if (objtype == CScene::OBJTYPE_PLAYER)
			{
				if (m_PlayerNum == PLAYER_01)
				{
					Pos01 = ((CPlayer*)pScene)->GetPlayerPos();
				}

				if (m_PlayerNum == PLAYER_02)
				{
					Pos02 = ((CPlayer*)pScene)->GetPlayerPos();
				}
				//円の当たり判定
				if (D3DXVec3LengthSq(&(Pos01 - Pos02)) <= (fRadiusPL01 + fRadiusPL02) * (fRadiusPL01 + fRadiusPL02))
				{
 					PlayerDamage();
				}

			}
		}
	}
}

//========================================================================================================
// モデルの読み込み処理
//========================================================================================================
int CPlayer::GetLife(void)
{
	return m_nLife;
}
//========================================================================================================
// モデルの読み込み処理
//========================================================================================================
HRESULT CPlayer::Load(void)
{
	CRenderer *pRenderer = CManager::GetRenderer();
	LPDIRECT3DDEVICE9 pDevice = pRenderer->GetDevice();

	// Xファイルの読み込み
	D3DXLoadMeshFromX(MODELFILE1, D3DXMESH_SYSTEMMEM, pDevice, NULL,
		&pBuffMat[MODELTYPE_CAR], NULL,
		&nNumMat[MODELTYPE_CAR],
		&pMesh[MODELTYPE_CAR]);

	// Xファイルの読み込み
	D3DXLoadMeshFromX(MODELFILE2, D3DXMESH_SYSTEMMEM, pDevice, NULL,
		&pBuffMat[MODELTYPE_CAT], NULL,
		&nNumMat[MODELTYPE_CAT],
		&pMesh[MODELTYPE_CAT]);

	return S_OK;
}

//========================================================================================================
// モデルの解放処理
//========================================================================================================
void CPlayer::Unload(void)
{
	for (int nCnt = 0; nCnt < MODELTYPE_MAX; nCnt++)
	{
		if (pBuffMat[nCnt])
		{
			pBuffMat[nCnt]->Release();
			pBuffMat[nCnt] = NULL;
		}

		if (nNumMat[nCnt])
		{
			nNumMat[nCnt] = NULL;
		}

		if (pMesh[nCnt])
		{
			pMesh[nCnt]->Release();
			pMesh[nCnt] = NULL;
		}
	}
}