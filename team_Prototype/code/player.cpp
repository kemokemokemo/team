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
CScene3D::MODELNUM CPlayer::m_PlayerType[PLAYERTYPE_MAX] = {};

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
CPlayer * CPlayer::Create(D3DXVECTOR3 pos, D3DXVECTOR3 rot, PLAYERTYPE type, PLAYERNUM PlayerNum)
{
	CPlayer *pPlayer;
	pPlayer = new CPlayer(OBJTYPE_PLAYER);

	pPlayer->BindModel(&m_PlayerType[type]);


	pPlayer->Init(pos, rot, type, PlayerNum);
	return pPlayer;
}

//=============================================================================
// 初期化処理
//=============================================================================
HRESULT CPlayer::Init(D3DXVECTOR3 pos, D3DXVECTOR3 rot, PLAYERTYPE type, PLAYERNUM PlayerNum)
{
	CScene3D::Init();

	CScene3D::SetPos(pos);

	m_PlayerNum = PlayerNum;

	m_PlayerStateCount = 0;

	m_PlayerState = PLAYERSTATE_NORMAL;

	//switch (type)
	//{
	//case MODELTYPE_CAR:
	//	m_nLife = 3;
	//	//pLifeGauge = CGauge::Create(D3DXVECTOR3(200.0f, 600.0f, 0.0f));
	//	break;

	//case MODELTYPE_CAT:
	//	m_nLife = 5;
	//	//pLifeGauge = CGauge::Create(D3DXVECTOR3(200.0f, 600.0f, 0.0f));
	//	break;
	//}

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


	GetPlayerPos();

	MoveLimit();

}

//=============================================================================
// 描画処理
//=============================================================================
void CPlayer::Draw(void)
{
	CScene3D::Draw();
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
	for (int nCnt = 0; nCnt < PLAYERTYPE_MAX; nCnt++)
	{
		std::ifstream File("DATA/motion_Kangaroo.txt");

		if (!File)
			return -1;

		std::string sLine;

		int nCount[2] = {};

		// モデル数
		std::string sWord = { "NUM_MODEL" };
		m_PlayerType[nCnt].nMaxModel = std::stoi(CScene3D::WordLoad(&File, sWord));

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

				for (int nCntModel = 0; nCntModel < 1; nCntModel++)
				{
					Vector3Load(sLine, &m_PlayerType[nCnt].NumModel[nCntModel].rot);
				}

				sWord = { "END_PARTSSET" };
				sLine = CScene3D::WordLoad(&File, sWord);

			}
		}

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
// モデルの解放処理
//========================================================================================================
void CPlayer::Unload(void)
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