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
#include "model.h"
#include "effect.h"
#include "HitModel.h"

//=============================================================================
// マクロ定義
//=============================================================================
#define PLAYER_SPEED		(1.0f)						//プレイヤーの速さ
#define PLAYER__BLOWAWAY	(2.0f)					//プレイヤーの吹っ飛び
#define MODELFILE1		"DATA/motion_ken.txt"		// 読み込むモデル
#define MODELFILE2		"DATA/motion_Kangaroo.txt"	// 読み込むモデル
#define MODELFILE3		"DATA/motion_sword.txt"	// 読み込むモデル

//=============================================================================
// メンバ変数初期化
//=============================================================================
CScene3D::MODELNUM CPlayerBase::m_PlayerType[PLAYERTYPE_MAX] = {};
CPlayerBase::MOTION_INFO CPlayerBase::aMotionInfo[PLAYERTYPE_MAX][CPlayerBase::MOTIONTYPE_MAX] = {};
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
HRESULT CPlayerBase::Init(D3DXVECTOR3 pos, D3DXVECTOR3 rot, CMaker::MAKERTYPE MokerType)
{
	BindModel(&m_PlayerType[m_TypeChara]);
	//BindMotion(m_PlayerType[m_TypeChara].aMotionInfo);

	CScene3D::Init();

	m_posOld = pos;

	m_pos = pos;

	m_MokerType = MokerType;

	CScene3D::SetPos(pos);

	m_PlayerStateCount = 0;

	nCountATK = 0;

	m_MotionType = MOTIONTYPE_WAIT;					// 現在のモーション

	bJump = true;

	bWJump = true;

	m_PlayerState = PLAYERSTATE_NORMAL;

	for (int nCnt = 0; nCnt < MOTIONTYPE_MAX; nCnt++)
	{
		MotionInfo[nCnt] = aMotionInfo[m_TypeChara][nCnt];
	}

	if (m_MokerType == CMaker::MAKERTYPE_1P)
	{
		pMaker = CMaker::Create(pos, CMaker::MAKERTYPE_1P, 12);
	}
	if (m_MokerType == CMaker::MAKERTYPE_2P)
	{
		pMaker = CMaker::Create(pos, CMaker::MAKERTYPE_2P, 12);

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
	//モーションの再生
	MotionPlayer();

	PlayerMove();


	MODELNUM model = GetModel();
	switch (m_PlayerState)
	{
	case PLAYERSTATE_NORMAL:
		nCountATK = 0;

		break;

	case PLAYERSTATE_DAMAGE:
		MotionChangePlayer(MOTIONTYPE_DAMAGE);
		m_PlayerState = PLAYERSTATE_UNDYING;

		break;
	case PLAYERSTATE_UNDYING:
		m_PlayerStateCount--;
		if (m_PlayerStateCount <= 0)
		{
			m_PlayerState = PLAYERSTATE_NORMAL;
		}
		break;
	case PLAYERSTATE_GAUDE:
		break;
	}

	switch (m_MotionType)
	{
	case MOTIONTYPE_WAIT:
		m_PlayerState = PLAYERSTATE_NORMAL;
		MotionChangePlayer(MOTIONTYPE_WAIT);
		break;
	case MOTIONTYPE_RUN:
		MotionChangePlayer(MOTIONTYPE_RUN);
		break;
	case MOTIONTYPE_LIGHT0:
		MotionChangePlayer(MOTIONTYPE_LIGHT0);
		break;
	case MOTIONTYPE_LIGHT1:
		MotionChangePlayer(MOTIONTYPE_LIGHT1);
		break;
	case MOTIONTYPE_LIGHT2:
		m_PlayerState = PLAYERSTATE_ATK;
		MotionChangePlayer(MOTIONTYPE_LIGHT2);
		break;
	case MOTIONTYPE_DASHATK:
		m_PlayerState = PLAYERSTATE_ATK;
		MotionChangePlayer(MOTIONTYPE_DASHATK);
		break;
	case MOTIONTYPE_UPATK:
		m_PlayerState = PLAYERSTATE_ATK;
		MotionChangePlayer(MOTIONTYPE_UPATK);
		break;
	case MOTIONTYPE_CROUCHATK:
		m_PlayerState = PLAYERSTATE_ATK;
		MotionChangePlayer(MOTIONTYPE_CROUCHATK);
		break;
	case MOTIONTYPE_CROUCHWAIT:
		MotionChangePlayer(MOTIONTYPE_CROUCHWAIT);
		break;
	case MOTIONTYPE_DAMAGE:
		MotionChangePlayer(MOTIONTYPE_DAMAGE);
		break;
	case MOTIONTYPE_JUMP:
		m_PlayerState = PLAYERSTATE_NORMAL;
		MotionChangePlayer(MOTIONTYPE_JUMP);
		break;
	case MOTIONTYPE_DOUBLEJUMP:
		MotionChangePlayer(MOTIONTYPE_DOUBLEJUMP);
		break;
	case MOTIONTYPE_RAND:
		m_PlayerState = PLAYERSTATE_ATK;
		MotionChangePlayer(MOTIONTYPE_RAND);
		break;
	case MOTIONTYPE_AIR_N:
		m_PlayerState = PLAYERSTATE_AIRATK;
		MotionChangePlayer(MOTIONTYPE_AIR_N);
		break;
	case MOTIONTYPE_AIR_F:
		m_PlayerState = PLAYERSTATE_AIRATK;
		MotionChangePlayer(MOTIONTYPE_AIR_F);
		break;
	case MOTIONTYPE_AIR_B:
		m_PlayerState = PLAYERSTATE_AIRATK;
		MotionChangePlayer(MOTIONTYPE_AIR_B);
		break;
	case MOTIONTYPE_AIR_U:
		m_PlayerState = PLAYERSTATE_AIRATK;
		MotionChangePlayer(MOTIONTYPE_AIR_U);
		break;
	case MOTIONTYPE_AIR_D:
		m_PlayerState = PLAYERSTATE_AIRATK;
		MotionChangePlayer(MOTIONTYPE_AIR_D);
		break;
	case MOTIONTYPE_SP_N:
		m_PlayerState = PLAYERSTATE_ATK;
		MotionChangePlayer(MOTIONTYPE_SP_N);
		break;
	case MOTIONTYPE_SP_UP:
		m_PlayerState = PLAYERSTATE_ATK;
		MotionChangePlayer(MOTIONTYPE_SP_UP);
		break;
	case MOTIONTYPE_SP_DOWN:
		m_PlayerState = PLAYERSTATE_ATK;
		MotionChangePlayer(MOTIONTYPE_SP_DOWN);
		break;
	case MOTIONTYPE_GAUDE:
		MotionChangePlayer(MOTIONTYPE_GAUDE);
		break;
	}

	if (MotionInfo[m_MotionType].nHitIdx != -1 &&
		MotionInfo[m_MotionType].nAtkStar <= MotionInfo[m_MotionType].nNumKey && MotionInfo[m_MotionType].nAtkEnd >= MotionInfo[m_MotionType].nNumKey)
	{
		this->PlayerCollision();
	}

	this->PlayerCollisionShape();

	MoveLimit();

	SetModel(model);

	CScene3D::Update();
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

	m_move.y -= 1.6f;


	CScene3D::SetPos(pos);
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
	m_move.x += (0 - m_move.x) * 1 / 4;
	m_move.y += (0 - m_move.y) * 1 / 4;

	pos += m_move;

	CScene3D::SetPos(pos);
	CScene3D::SetRot(rot);
}

//====================================================================================================
// プレイヤーのダメージ処理
//=====================================================================================================
void CPlayerBase::PlayerDamage(CPlayerBase *pPlayer)
{
 	Damage(pPlayer, 1);

}

//====================================================================================================
// プレイヤーのダメージ処理
//=====================================================================================================
void CPlayerBase::Damage(CPlayerBase *pPlayer, int nDamage)
{

	if (pPlayer->m_PlayerState == PLAYERSTATE_NORMAL)
	{
		pPlayer->m_nLife -= nDamage;
		CEffect::SetParticle(pPlayer->GetPos(), D3DXVECTOR3(0.0f, 0.0f, 0.0f), 20,CEffect::EFFECTTYPE_EXPLOSION);
		pPlayer->m_PlayerState = PLAYERSTATE_DAMAGE;
		pPlayer->m_PlayerStateCount = 60;

		pPlayer->pMaker->MakerLife(nDamage);

	}
	
	if (pPlayer->m_PlayerState == PLAYERSTATE_GAUDE)
	{
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
	float fMinLength = 10000.0f;
	CPlayerBase *pPlayer[2] = {};

	D3DXVECTOR3 pos = GetPos();
	int nCnt = MotionInfo[m_MotionType].nHitIdx;

	while (nCnt != -1)
	{
		D3DXVec3Add(&pos, &pos, &MotionInfo[m_MotionType].aKeyInfo[MotionInfo[m_MotionType].nNumKey].aKey[nCnt].pos);
		D3DXVec3Add(&pos, &pos, &GetModel().NumModel[nCnt].pos);

		nCnt = GetModel().NumModel[nCnt].nIdxModel;
	}


	for (int nCntScene = 0; nCntScene < MAX_POLYGON; nCntScene++)
	{
		CScene *pScene;

		pScene = CScene::GetScene(OBJTYPE_PLAYER, nCntScene);

		if (!pScene || nCntScene == GetID())
			continue;

		pPlayer[0] = (CPlayerBase*)pScene;

		float fLength = D3DXVec3LengthSq(&(pPlayer[0]->GetPos() - pos));

		if (fMinLength > fLength)
		{
			fMinLength = fLength;
			pPlayer[1] = pPlayer[0];
		}
		SetParts(pos);
	}

	if (pPlayer[1] && pPlayer[1]->m_PlayerState != PLAYERSTATE_DAMAGE)
	{
		float fRadius = m_fRadius + pPlayer[1]->m_fAttack;

		//円の当たり判定
		if (fMinLength <= fRadius * fRadius)
		{
			PlayerDamage(pPlayer[1]);

			CHitModel::Create(pos, D3DXVECTOR3(pPlayer[1]->m_fAttack, pPlayer[1]->m_fAttack, pPlayer[1]->m_fAttack));
		}
	}

}

//========================================================================================================
// プレイヤーの衝突判定
//========================================================================================================
void CPlayerBase::PlayerCollisionShape()
{
	for (int nCntModel = 0; nCntModel < MAX_POLYGON; nCntModel++)
	{
		CScene *pScene;

		pScene = CScene::GetScene(OBJTYPE_PLAYER, nCntModel);

		if (!pScene || nCntModel == GetID())
			continue;

		CPlayerBase *pPlayer = (CPlayerBase*)pScene;

		// 頭 足元
		D3DXVECTOR3 pos[2] = { m_pos, m_pos };


		D3DXVECTOR3 opponent[2] = { pPlayer->m_pos, pPlayer->m_pos};

		int nIdx[2] = { GetModel().NumModel[1].nIdxModel,pPlayer->GetModel().NumModel[1].nIdxModel };
		D3DXVECTOR3 *poshead[2] = { &pos[0],&opponent[0] };

		for (int nCount = 0; nCount < 2; nCount++)
		{
			while (nIdx[nCount] != -1)
			{
				D3DXVec3Add(poshead[nCount], poshead[nCount], &MotionInfo[m_MotionType].aKeyInfo[MotionInfo[m_MotionType].nNumKey].aKey[nIdx[nCount]].pos);
				D3DXVec3Add(poshead[nCount], poshead[nCount], &GetModel().NumModel[nIdx[nCount]].pos);

				if (nCount == 0)
				{
					nIdx[0] = GetModel().NumModel[nIdx[0]].nIdxModel;
				}
				else
				{
					nIdx[1] = pPlayer->GetModel().NumModel[nIdx[1]].nIdxModel;
				}
			}
		}

		pos[0] -= (pos[0] - pos[1]) / 4.0f;
		pos[1] += (pos[0] - pos[1]) / 4.0f;

		opponent[0] -= (opponent[0] - opponent[1]) / 4.0f;
		opponent[1] += (opponent[0] - opponent[1]) / 4.0f;


		// モデルと物体の距離
		float fRadius = 10000.0f;
		D3DXVECTOR3 Vec = {};

		for (int nCnt = 0; nCnt < 2; nCnt++)
		{
			for (int nCount = nCnt; nCount < 2; nCount++)
			{
				float fDis = D3DXVec3Length(&(pos[nCnt] - opponent[nCount]));

				if (fRadius > fDis)
				{
					Vec = pos[nCnt] - opponent[nCount];
					fRadius = fDis;
				}
			}
		}

		// 半径
		float fRadiusA = m_fRadius;
		float fRadiusB = pPlayer->m_fRadius;

		if (fRadius <= (fRadiusA + fRadiusB))
		{// 半径+半径より近いか

			D3DXVECTOR3 vec;
			D3DXVec3Normalize(&vec, &Vec);			//正規化する

			// どれだけめり込んだか
			fRadius = (fRadiusB + fRadiusA) - fRadius;

			SetPos(GetPos() + vec * fRadius);

			D3DXVECTOR3 temp = D3DXVECTOR3(0.0f, 1.0f, 0.0f);

			float cosA = D3DXVec3Dot(&Vec, &temp) / D3DXVec3Length(&(Vec * -1.0f));

			m_move.y -= m_move.y * cosA * cosA * (fRadius / fRadiusA);
		}
	}
}

//=============================================================================
// モーションの再生
//=============================================================================
void CPlayerBase::MotionPlayer()
{
	D3DXVECTOR3 Distance;
	MODELNUM model = GetModel();

	MOTION_INFO* pInfo = &MotionInfo[m_MotionType];

	// モーション
	for (int nCntModel = 0; nCntModel < model.nMaxModel; nCntModel++)
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
		model.NumModel[nCntModel].pos = model.NumModel[nCntModel].startpos + pKeyInfo->pos + (pNextKey->pos - pKeyInfo->pos)*
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
		model.NumModel[nCntModel].rot = pKeyInfo->rot + Distance*
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
			pInfo->nNumKey = 0;
			pInfo->nCntFrame = 0;
			m_MotionType = MOTIONTYPE_WAIT;
	}
	else if (pInfo->nNumKey == pInfo->nMaxKey)
	{// モーションが終了した場合
		pInfo->nNumKey = 0;
	}

	SetModel(model);
}

//=============================================================================
// モーションの切り替え
//=============================================================================
void CPlayerBase::MotionChangePlayer(MOTIONTYPE motionType)
{
	if (m_MotionType != motionType)
	{
		MotionInfo[m_MotionType].nNumKey = 0;
		MotionInfo[m_MotionType].nCntFrame = 0;
		m_MotionType = motionType;
	}
}

//========================================================================================================
// モデルの読み込み処理
//========================================================================================================
int CPlayerBase::GetLife(void)
{
	return m_nLife;
}

CMaker::MAKERTYPE CPlayerBase::GetMaker()
{
	return m_MokerType;
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
				m_PlayerType[nCnt].NumModel[nCount].nIdxModel = std::stoi(CScene3D::WordLoad(&File, sWord));

				sWord = { "POS" };
				sLine = CScene3D::WordLoad(&File, sWord);
				Vector3Load(sLine, &m_PlayerType[nCnt].NumModel[nCount].pos);

				m_PlayerType[nCnt].NumModel[nCount].startpos = m_PlayerType[nCnt].NumModel[nCount].pos;

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

	MOTION_INFO *pMotion = &aMotionInfo[nCnt][0];

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
			pMotion->bLoop = (nLoop == 1) ? true : false;

			//キーの最大数
			sWord = { "NUM_KEY" };
			pMotion->nMaxKey = std::stoi(CScene3D::WordLoad(file, sWord));

			sWord = { "ATKSET" };
			if (CScene3D::WordLoad(file, sWord, 1) == sWord)
			{
				// 攻撃するときの部位
				sWord = { "ATK_IDX" };
				pMotion->nHitIdx = std::stoi(CScene3D::WordLoad(file, sWord));

				// 攻撃するときのキー(最初)
				sWord = { "ATK_START" };
				pMotion->nAtkStar = std::stoi(CScene3D::WordLoad(file, sWord));

				// 攻撃するときのキー(最後)
				sWord = { "ATK_END" };
				pMotion->nAtkEnd = std::stoi(CScene3D::WordLoad(file, sWord));
			}
			else
			{
				pMotion->nHitIdx = -1;
				pMotion->nAtkStar = 0;
				pMotion->nAtkEnd = 0;
			}

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
//=============================================================================
// 床の当たり判定
//=============================================================================
void CPlayerBase::PlayerCollisionFloor(void)
{
	m_posOld = m_pos;

	m_pos = CScene3D::GetPos();

	D3DXVECTOR3 size = CScene3D::GetScale();

	if ((CModel::CollisionModel(&m_pos, &m_posOld, size)) == true)
	{
		if (bJump == true)//ジャンプ可能な時
		{
			bJump = false;
			bWJump = false;
		}
		else
		{//着地
			if (m_MotionType == MOTIONTYPE_JUMP || m_PlayerState == PLAYERSTATE_AIRATK)
			{
				MotionChangePlayer(MOTIONTYPE_RAND);
			}
			CScene3D::SetHight(m_pos.y);
		}
	}

}

//=============================================================================
// ジャンプできるかできないか
//=============================================================================
void CPlayerBase::SetJump(bool bJumpman)
{
	bJump = bJumpman;
}
//=============================================================================
// ジャンプできるかできないか
//=============================================================================
bool CPlayerBase::GetJump()
{
	return bJump;
}
