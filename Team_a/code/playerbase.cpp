//=============================================================================
//
// プレイヤー処理 [player.cpp]
// Author : KOUTA KIMURA
//
//=============================================================================

//=============================================================================
// インクルードファイル
//=============================================================================
#include "playerbase.h"
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
#define PLAYER_SPEED	(1.0f)						//プレイヤーの速さ
#define MODELFILE1		"DATA/motion_ken.txt"		// 読み込むモデル
#define MODELFILE2		"DATA/motion_Kangaroo.txt"	// 読み込むモデル
#define MODELFILE3		"DATA/motion_sword.txt"	// 読み込むモデル

//=============================================================================
// メンバ変数初期化
//=============================================================================
CScene3D::MODELNUM CPlayerBase::m_PlayerType[PLAYERTYPE_MAX] = {};
char *CPlayerBase::TextLoad[PLAYERTYPE_MAX];

//=============================================================================
// コンストラクタ
//=============================================================================
CPlayerBase::CPlayerBase(OBJTYPE type) : CScene3D(type)
{
	m_move = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	m_PlayerStateCount = 0;
}

//=============================================================================
// デストラクタ
//=============================================================================
CPlayerBase::~CPlayerBase()
{

}

//=============================================================================
// 初期化処理
//=============================================================================
HRESULT CPlayerBase::Init(D3DXVECTOR3 pos, D3DXVECTOR3 rot, PLAYERNUM PlayerNum)
{
	BindModel(&m_PlayerType[m_TypeChara]);

	CScene3D::Init();

	CScene3D::SetPos(pos);

	m_PlayerNum = PlayerNum;

	m_PlayerStateCount = 0;

	m_TypeSelect = m_PlayerType[m_TypeChara];

	m_PlayerState = PLAYERSTATE_NORMAL;

	m_TypeSelect.motionType = MOTIONTYPE_WAIT;

	for (int nCntModel = 0; nCntModel < MAX_MODEL; nCntModel++)
	{
		m_TypeSelect.NumModel[nCntModel].startpos = m_TypeSelect.NumModel[nCntModel].pos;
	}

	return S_OK;
}

//=============================================================================
// 終了処理
//=============================================================================
void CPlayerBase::Uninit(void)
{
	CScene3D::Uninit();
}

//=============================================================================
// 更新処理
//=============================================================================
void CPlayerBase::Update(void)
{
	CScene3D::Update();

	switch (m_PlayerNum)
	{
	case PLAYER_01:
		PlayerMove();
		// モーションの再生
		MotionPlayer(0);

		break;

	case PLAYER_02:
		PlayerMove();
		// モーションの再生
		MotionPlayer(0);

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
		//MotionChangePlayer(MOTIONTYPE_NEUTRAL, 0);
		break;

	case PLAYERSTATE_DAMAGE:
			m_MotionState = MOTIONSTATE_DAMAGE;
			m_PlayerState = PLAYERSTATE_UNDYING;

		break;
	case PLAYERSTATE_UNDYING:
		m_PlayerStateCount--;
		if (m_PlayerStateCount <= 0)
		{
			m_PlayerState = PLAYERSTATE_NORMAL;
		}
		break;
	case PLAYERSTATE_RANNING:
		//MotionChangePlayer(MOTIONTYPE_RUNNING, 0);
		break;
	}

	switch (m_MotionState)
	{
	case MOTIONSTATE_WAIT:
		m_PlayerState = PLAYERSTATE_NORMAL;
		MotionChangePlayer(MOTIONTYPE_WAIT, 0);
		break;
	case MOTIONSTATE_RUN:
		MotionChangePlayer(MOTIONTYPE_RUN, 0);
		break;
	case MOTIONSTATE_LIGHT0:
		MotionChangePlayer(MOTIONTYPE_LIGHT0, 0);
		break;
	case MOTIONSTATE_LIGHT1:
		MotionChangePlayer(MOTIONTYPE_LIGHT1, 0);
		break;
	case MOTIONSTATE_LIGHT2:
		MotionChangePlayer(MOTIONTYPE_LIGHT2, 0);
		break;
	case MOTIONSTATE_DASHATK:
		if (m_fDiffrot.y == D3DX_PI*0.5f)
		{
			m_move.x -= 0.5f;
		}
		else
		{
			m_move.x += 0.5f;
		}
		m_PlayerState = PLAYERSTATE_ATK;
		MotionChangePlayer(MOTIONTYPE_DASHATK, 0);
		break;
	case MOTIONSTATE_UPATK:
		m_PlayerState = PLAYERSTATE_ATK;
		MotionChangePlayer(MOTIONTYPE_UPATK, 0);
		break;
	case MOTIONSTATE_CROUCHATK:
		m_PlayerState = PLAYERSTATE_ATK;
		MotionChangePlayer(MOTIONTYPE_CROUCHATK, 0);
		break;
	case MOTIONSTATE_CROUCHWAIT:
		MotionChangePlayer(MOTIONTYPE_CROUCHWAIT, 0);
		break;
	case MOTIONSTATE_DAMAGE:
		MotionChangePlayer(MOTIONTYPE_DAMAGE, 0);
		break;
	case MOTIONSTATE_JUMP:
		MotionChangePlayer(MOTIONTYPE_JUMP, 0);
		break;
	}
	GetPlayerPos();

	MoveLimit();	
}

//=============================================================================
// 描画処理
//=============================================================================
void CPlayerBase::Draw(void)
{
	CScene3D::Draw();
}

//=============================================================================
// プレイヤーの移動制限と重力
//=============================================================================
void CPlayerBase::MoveLimit(void)
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
D3DXVECTOR3 CPlayerBase::GetPlayerPos(void)
{
	D3DXVECTOR3 pos = CScene3D::GetPos();


	return pos;
}

//=============================================================================
// プレイヤーの移動処理
//=============================================================================
void CPlayerBase::PlayerMove(void)
{
	CKeybord *pKeyboard = CManager::GetKeybord();

	D3DXVECTOR3 pos;
	D3DXVECTOR3 rot;

	pos = CScene3D::GetPos();

	rot = CScene3D::GetRot();

	pos += m_move;

	if (m_PlayerNum == PLAYER_01)
	{
		if (m_PlayerState != PLAYERSTATE_ATK)
		{
			if (pKeyboard->GetKeyboardPress(DIK_A))
			{//  A キー操作
				m_move.x += D3DX_PI*-0.5f* PLAYER_SPEED;
				m_fDiffrot.y = D3DX_PI*0.5f;
				m_MotionState = MOTIONSTATE_RUN;
				if (pKeyboard->GetKeyboardTrigger(DIK_SPACE))
				{
					m_MotionState = MOTIONSTATE_DASHATK;
				}
			}
			else if (pKeyboard->GetKeyboardPress(DIK_D))
			{//  D キー操作
				m_move.x += D3DX_PI*0.5f * PLAYER_SPEED;
				m_fDiffrot.y = D3DX_PI*-0.5f;
				m_MotionState = MOTIONSTATE_RUN;
				if (pKeyboard->GetKeyboardTrigger(DIK_SPACE))
				{
					m_MotionState = MOTIONSTATE_DASHATK;
				}
			}
			else if (m_MotionState == MOTIONSTATE_RUN)
			{// 移動をやめた場合
			 // モーションの切り替え
				m_MotionState = MOTIONSTATE_WAIT;
			}

			else if (pKeyboard->GetKeyboardPress(DIK_W))
			{// W キー操作
				if (pKeyboard->GetKeyboardTrigger(DIK_SPACE))
				{
					m_MotionState = MOTIONSTATE_UPATK;
				}
			}

			else if (pKeyboard->GetKeyboardPress(DIK_S))
			{
				m_MotionState = MOTIONSTATE_CROUCHWAIT;
				if (pKeyboard->GetKeyboardTrigger(DIK_SPACE))
				{
					m_MotionState = MOTIONSTATE_CROUCHATK;
				}
			}
			else if (m_MotionState == MOTIONSTATE_CROUCHWAIT)
			{// 移動をやめた場合vbn
			 // モーションの切り替え
				m_MotionState = MOTIONSTATE_WAIT;
			}

			else if (pKeyboard->GetKeyboardTrigger(DIK_SPACE))
			{
				PlayerCollision();
				//3段攻撃
				if (m_MotionState == MOTIONSTATE_LIGHT0)
				{
					m_MotionState = MOTIONSTATE_LIGHT1;
				}
				else if (m_MotionState == MOTIONSTATE_LIGHT1)
				{
					m_MotionState = MOTIONSTATE_LIGHT2;
				}
				else
				{
					m_MotionState = MOTIONSTATE_LIGHT0;
				}
			}
		}
	}


	if (m_PlayerNum == PLAYER_02)
	{
		if (m_PlayerState != PLAYERSTATE_ATK)
		{
			if (pKeyboard->GetKeyboardPress(DIK_LEFTARROW))
			{//  A キー操作
				m_move.x += D3DX_PI*-0.5f* PLAYER_SPEED;
				m_fDiffrot.y = D3DX_PI*0.5f;
				m_MotionState = MOTIONSTATE_RUN;
				if (pKeyboard->GetKeyboardTrigger(DIK_L))
				{
					m_MotionState = MOTIONSTATE_DASHATK;
				}
			}
			else if (pKeyboard->GetKeyboardPress(DIK_RIGHTARROW))
			{//  D キー操作
				m_move.x += D3DX_PI*0.5f * PLAYER_SPEED;
				m_fDiffrot.y = D3DX_PI*-0.5f;
				m_MotionState = MOTIONSTATE_RUN;
				if (pKeyboard->GetKeyboardTrigger(DIK_L))
				{
					m_MotionState = MOTIONSTATE_DASHATK;
				}
			}
			else if (m_MotionState == MOTIONSTATE_RUN)
			{// 移動をやめた場合
			 // モーションの切り替え
				m_MotionState = MOTIONSTATE_WAIT;
			}

			else if (pKeyboard->GetKeyboardPress(DIK_UPARROW))
			{// W キー操作
				if (pKeyboard->GetKeyboardTrigger(DIK_L))
				{
					m_MotionState = MOTIONSTATE_UPATK;
				}
			}

			else if (pKeyboard->GetKeyboardPress(DIK_DOWNARROW))
			{
				m_MotionState = MOTIONSTATE_CROUCHWAIT;
				if (pKeyboard->GetKeyboardTrigger(DIK_L))
				{
					m_MotionState = MOTIONSTATE_CROUCHATK;
				}
			}
			else if (m_MotionState == MOTIONSTATE_CROUCHWAIT)
			{// 移動をやめた場合vbn
			 // モーションの切り替え
				m_MotionState = MOTIONSTATE_WAIT;
			}

			else if (pKeyboard->GetKeyboardTrigger(DIK_L))
			{
				PlayerCollision();
				//3段攻撃
				if (m_MotionState == MOTIONSTATE_LIGHT0)
				{
					m_MotionState = MOTIONSTATE_LIGHT1;
				}
				else if (m_MotionState == MOTIONSTATE_LIGHT1)
				{
					m_MotionState = MOTIONSTATE_LIGHT2;
				}
				else
				{
					m_MotionState = MOTIONSTATE_LIGHT0;
				}
			}
		}
	}
	if (m_PlayerNum == PLAYER_03)
	{
		if (pKeyboard->GetKeyboardTrigger(DIK_RETURN))
		{
			m_MotionState = MOTIONSTATE_RUN;
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
void CPlayerBase::PlayerDamage(CPlayerBase *pPlayer)
{
	switch (m_PlayerNum)
	{
	case PLAYER_01:
		Damage(pPlayer, 1);
		break;

	case PLAYER_02:
		Damage(pPlayer, 1);
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
void CPlayerBase::Damage(CPlayerBase *pPlayer, int nDamage)
{
	if (pPlayer->m_PlayerState == PLAYERSTATE_NORMAL)
	{
		pPlayer->m_nLife -= nDamage;
		pPlayer->m_PlayerState = PLAYERSTATE_DAMAGE;
		pPlayer->m_PlayerStateCount = 60;
	}
	
	if (pPlayer->m_nLife <= 0)
	{
		pPlayer->Release();
	}
}
//========================================================================================================
// プレイヤーの当たり判定
//========================================================================================================
void CPlayerBase::PlayerCollision()
{
	for (int nCntScene = 0; nCntScene < MAX_POLYGON; nCntScene++)
	{
		CScene *pScene;

		pScene = CScene::GetScene(OBJTYPE_PLAYER, nCntScene);

		if (!pScene || nCntScene == GetID())
			continue;

		CPlayerBase *pPlayer = (CPlayerBase*)pScene;

		float fLength = D3DXVec3LengthSq(&(pPlayer->GetPos() - GetPos()));
		float fRadius = m_fRadius + pPlayer->m_fAttack;

		//円の当たり判定
		if (fLength <= fRadius * fRadius)
		{
			PlayerDamage(pPlayer);
		}
	}
}

//=============================================================================
// モーションの再生
//=============================================================================
void CPlayerBase::MotionPlayer(int nCnt)
{
	D3DXVECTOR3 Distance;

	MOTION_INFO* pInfo = &m_TypeSelect.aMotionInfo[m_TypeSelect.motionType];
	// モーション
	for (int nCntModel = 0; nCntModel < m_TypeSelect.nMaxModel; nCntModel++)
	{
		KEY *pKeyInfo, *pNextKey;

		// 現在のキー
		pKeyInfo = &pInfo->aKeyInfo[pInfo->nNumKey].aKey[nCntModel];

		// 次のキー
		if (pInfo->nNumKey + 1 == pInfo->nMaxKey)
		{
			pNextKey = &pInfo->aKeyInfo[0].aKey[nCntModel];
		}
		else
		{
			pNextKey = &pInfo->aKeyInfo[pInfo->nNumKey + 1].aKey[nCntModel];
		}

		// パーツの位置設定
		m_TypeSelect.NumModel[nCntModel].pos = m_TypeSelect.NumModel[nCntModel].startpos + pKeyInfo->pos + (pNextKey->pos - pKeyInfo->pos)*
			(float)pInfo->nCntFrame / (float)pInfo->aKeyInfo[pInfo->nNumKey].nNumKyeFrame;

		Distance = pNextKey->rot - pKeyInfo->rot;

		if (D3DX_PI < Distance.y)
		{
			Distance.y -= D3DX_PI * 2;
		}
		else if (-D3DX_PI > Distance.y)
		{
			Distance.y += D3DX_PI * 2;
		}
		if (D3DX_PI < Distance.x)
		{
			Distance.x -= D3DX_PI * 2;
		}
		else if (-D3DX_PI > Distance.x)
		{
			Distance.x += D3DX_PI * 2;
		}
		// パーツの向き設定
		m_TypeSelect.NumModel[nCntModel].rot = pKeyInfo->rot + Distance*
			(float)pInfo->nCntFrame / (float)pInfo->aKeyInfo[pInfo->nNumKey].nNumKyeFrame;


	}
	pInfo->nCntFrame++;

	if (pInfo->nCntFrame == pInfo->aKeyInfo[pInfo->nNumKey].nNumKyeFrame)
	{
		pInfo->nNumKey++;
		pInfo->nCntFrame = 0;
	}

	if (!pInfo->bLoop && pInfo->nNumKey + 1 == pInfo->nMaxKey)
	{// モーションがループしない場合
		if (m_PlayerType[nCnt].motionType != MOTIONTYPE_JUMP)
		{// ジャンプ以外
			pInfo->nNumKey = 0;
			pInfo->nCntFrame = 0;

			m_MotionState = MOTIONSTATE_WAIT;
			
		}
	}
	else if (pInfo->nNumKey == pInfo->nMaxKey && m_TypeSelect.motionType != MOTIONTYPE_JUMP)
	{// モーションが終了した場合
		pInfo->nNumKey = 0;
	}

	SetPosParts(&m_TypeSelect);
}

//=============================================================================
// モーションの切り替え
//=============================================================================
void CPlayerBase::MotionChangePlayer(MOTIONTYPE motionType, int nCnt)
{
	if (m_TypeSelect.motionType != motionType)
	{
		m_TypeSelect.aMotionInfo[m_TypeSelect.motionType].nNumKey = 0;
		m_TypeSelect.aMotionInfo[m_TypeSelect.motionType].nCntFrame = 0;
	}
	m_TypeSelect.motionType = motionType;
}

//========================================================================================================
// モデルの読み込み処理
//========================================================================================================
int CPlayerBase::GetLife(void)
{
	return m_nLife;
}

//========================================================================================================
// モデルの読み込み処理
//========================================================================================================
HRESULT CPlayerBase::Load(void)
{
	TextLoad[PLAYERTYPE_KEN] = (char*)MODELFILE1;
	TextLoad[PLAYERTYPE_KANGAROO] = (char*)MODELFILE2;
	TextLoad[PLAYERTYPE_SWORD] = (char*)MODELFILE3;

	for (int nCnt = 0; nCnt < PLAYERTYPE_MAX; nCnt++)
	{
		std::ifstream File(TextLoad[nCnt]);

		if (!File)
			return -1;

		std::string sLine;
		
		// モデル数
		std::string sWord = { "NUM_MODEL" };
		m_PlayerType[nCnt].nMaxModel = std::stoi(CScene3D::WordLoad(&File, sWord));

		// モーションの最大数
		sWord = { "NUM_MOTION" };
		m_PlayerType[nCnt].nMotionMax = std::stoi(CScene3D::WordLoad(&File, sWord));

		// モデルのファイル名
		sWord = { "MODEL_FILENAME" };
		for (int nCount = 0; nCount < m_PlayerType[nCnt].nMaxModel; nCount++)
		{
			std::string sFile = CScene3D::WordLoad(&File, sWord);
			// char型にコピー
			std::char_traits<char>::copy(m_PlayerType[nCnt].NumModel[nCount].cFileName, sFile.c_str(), sFile.size() + 1);
		}

		// モデルのファイル名
		sWord = { "CHARACTERSET" };
		sLine = CScene3D::WordLoad(&File, sWord);

		if (sWord == sLine)
		{
			for (int nCount = 0; nCount < m_PlayerType[nCnt].nMaxModel; nCount++)
			{
				sWord = { "PARTSSET" };
				sLine = CScene3D::WordLoad(&File, sWord);

				sWord = { "INDEX" };
				m_PlayerType[nCnt].NumModel[nCount].nType = std::stoi(CScene3D::WordLoad(&File, sWord));

				sWord = { "PARENT" };
				m_PlayerType[nCnt].NumModel[nCount].nIdxModelModel = std::stoi(CScene3D::WordLoad(&File, sWord));

				sWord = { "POS" };
				sLine = CScene3D::WordLoad(&File, sWord);
				Vector3Load(sLine, &m_PlayerType[nCnt].NumModel[nCount].pos);

				sWord = { "ROT" };
				sLine = CScene3D::WordLoad(&File, sWord);
				Vector3Load(sLine, &m_PlayerType[nCnt].NumModel[nCount].rot);
				
				sWord = { "END_PARTSSET" };
				sLine = CScene3D::WordLoad(&File, sWord);
			}
		}

		//モーションの読み込み
		MotionLoad(&File, nCnt);

		CRenderer *pRenderer = CManager::GetRenderer();
		LPDIRECT3DDEVICE9 pDevice = pRenderer->GetDevice();

		for (int nCntModel = 0; nCntModel < m_PlayerType[nCnt].nMaxModel; nCntModel++)
		{
			// Xファイルの読み込み
			D3DXLoadMeshFromX(m_PlayerType[nCnt].NumModel[nCntModel].cFileName, D3DXMESH_SYSTEMMEM, pDevice, NULL,
				&m_PlayerType[nCnt].NumModel[nCntModel].pBuffMat, NULL,
				&m_PlayerType[nCnt].NumModel[nCntModel].nNumMat,
				&m_PlayerType[nCnt].NumModel[nCntModel].pMesh);
		}
	}
	return S_OK;
}

//========================================================================================================
// モーションの読み込み
//========================================================================================================
HRESULT CPlayerBase::MotionLoad(std::ifstream *file, int nCnt)
{
	std::string sLine;
	int nLoop = 0;			// ループ格納用

	MOTION_INFO *pMotion = &m_PlayerType[nCnt].aMotionInfo[0];

	// モデルのファイル名
	std::string sWord = { "MOTIONSET" };
	sLine = CScene3D::WordLoad(file, sWord);

	for (int nCountKey = 0; nCountKey < m_PlayerType[nCnt].nMotionMax; nCountKey++)
	{
		KEY_INFO *pKeyInfo = &pMotion->aKeyInfo[0];

		if (sWord == sLine)
		{
			sWord = { "LOOP" };
			nLoop = std::stoi(CScene3D::WordLoad(file, sWord));
			// 1の場合ループする
			pMotion->bLoop = nLoop == 1 ? true : false;

			//キーの最大数
			sWord = { "NUM_KEY" };
			pMotion->nMaxKey = std::stoi(CScene3D::WordLoad(file, sWord));

			for (int nCount = 0; nCount < pMotion->nMaxKey; nCount++)
			{
				KEY *pKey = &pKeyInfo->aKey[0];

				sWord = { "KEYSET" };
				sLine = CScene3D::WordLoad(file, sWord);

				sWord = { "FRAME" };
				pKeyInfo->nNumKyeFrame = std::stoi(CScene3D::WordLoad(file, sWord));

				for (int nCntModel = 0; nCntModel < m_PlayerType[nCnt].nMaxModel; nCntModel++)
				{
					sWord = { "POS" };
					sLine = CScene3D::WordLoad(file, sWord);
					Vector3Load(sLine, &pKey->pos);

					sWord = { "ROT" };
					sLine = CScene3D::WordLoad(file, sWord);
					Vector3Load(sLine, &pKey->rot);
					pKey++;
				}
				sWord = { "END_KEYSET" };
				sLine = CScene3D::WordLoad(file, sWord);
				pKeyInfo++;
			}
			pMotion++;
		}
	}
	return S_OK;
}

//========================================================================================================
// モデルの解放処理
//========================================================================================================
void CPlayerBase::Unload(void)
{
	for (int nCntType = 0; nCntType < PLAYERTYPE_MAX; nCntType++)
	{
		for (int nCnt = 0; nCnt < MAX_MODEL; nCnt++)
		{
			m_PlayerType[nCntType].NumModel[nCnt].nNumMat = NULL;
			m_PlayerType[nCntType].NumModel[nCnt].pBuffMat = NULL;
			m_PlayerType[nCntType].NumModel[nCnt].pMesh = NULL;
		}
	}
}
