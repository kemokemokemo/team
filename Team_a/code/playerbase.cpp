//=============================================================================
//
// �v���C���[���� [player.cpp]
// Author : KOUTA KIMURA
//
//=============================================================================

//=============================================================================
// �C���N���[�h�t�@�C��
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
// �}�N����`
//=============================================================================
#define PLAYER_SPEED	(1.0f)						//�v���C���[�̑���
#define MODELFILE1		"DATA/motion_ken.txt"		// �ǂݍ��ރ��f��
#define MODELFILE2		"DATA/motion_Kangaroo.txt"	// �ǂݍ��ރ��f��
#define MODELFILE3		"DATA/motion_sword.txt"	// �ǂݍ��ރ��f��

//=============================================================================
// �����o�ϐ�������
//=============================================================================
CScene3D::MODELNUM CPlayerBase::m_PlayerType[PLAYERTYPE_MAX] = {};
char *CPlayerBase::TextLoad[PLAYERTYPE_MAX];

//=============================================================================
// �R���X�g���N�^
//=============================================================================
CPlayerBase::CPlayerBase(OBJTYPE type) : CScene3D(type)
{
	m_move = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	m_PlayerStateCount = 0;
}

//=============================================================================
// �f�X�g���N�^
//=============================================================================
CPlayerBase::~CPlayerBase()
{

}

//=============================================================================
// ����������
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
// �I������
//=============================================================================
void CPlayerBase::Uninit(void)
{
	CScene3D::Uninit();
}

//=============================================================================
// �X�V����
//=============================================================================
void CPlayerBase::Update(void)
{
	CScene3D::Update();

	switch (m_PlayerNum)
	{
	case PLAYER_01:
		PlayerMove();
		// ���[�V�����̍Đ�
		MotionPlayer(0);

		break;

	case PLAYER_02:
		PlayerMove();
		// ���[�V�����̍Đ�
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
// �`�揈��
//=============================================================================
void CPlayerBase::Draw(void)
{
	CScene3D::Draw();
}

//=============================================================================
// �v���C���[�̈ړ������Əd��
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
// �v���C���[�̈ړ�����
//=============================================================================
D3DXVECTOR3 CPlayerBase::GetPlayerPos(void)
{
	D3DXVECTOR3 pos = CScene3D::GetPos();


	return pos;
}

//=============================================================================
// �v���C���[�̈ړ�����
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
			{//  A �L�[����
				m_move.x += D3DX_PI*-0.5f* PLAYER_SPEED;
				m_fDiffrot.y = D3DX_PI*0.5f;
				m_MotionState = MOTIONSTATE_RUN;
				if (pKeyboard->GetKeyboardTrigger(DIK_SPACE))
				{
					m_MotionState = MOTIONSTATE_DASHATK;
				}
			}
			else if (pKeyboard->GetKeyboardPress(DIK_D))
			{//  D �L�[����
				m_move.x += D3DX_PI*0.5f * PLAYER_SPEED;
				m_fDiffrot.y = D3DX_PI*-0.5f;
				m_MotionState = MOTIONSTATE_RUN;
				if (pKeyboard->GetKeyboardTrigger(DIK_SPACE))
				{
					m_MotionState = MOTIONSTATE_DASHATK;
				}
			}
			else if (m_MotionState == MOTIONSTATE_RUN)
			{// �ړ�����߂��ꍇ
			 // ���[�V�����̐؂�ւ�
				m_MotionState = MOTIONSTATE_WAIT;
			}

			else if (pKeyboard->GetKeyboardPress(DIK_W))
			{// W �L�[����
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
			{// �ړ�����߂��ꍇvbn
			 // ���[�V�����̐؂�ւ�
				m_MotionState = MOTIONSTATE_WAIT;
			}

			else if (pKeyboard->GetKeyboardTrigger(DIK_SPACE))
			{
				PlayerCollision();
				//3�i�U��
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
			{//  A �L�[����
				m_move.x += D3DX_PI*-0.5f* PLAYER_SPEED;
				m_fDiffrot.y = D3DX_PI*0.5f;
				m_MotionState = MOTIONSTATE_RUN;
				if (pKeyboard->GetKeyboardTrigger(DIK_L))
				{
					m_MotionState = MOTIONSTATE_DASHATK;
				}
			}
			else if (pKeyboard->GetKeyboardPress(DIK_RIGHTARROW))
			{//  D �L�[����
				m_move.x += D3DX_PI*0.5f * PLAYER_SPEED;
				m_fDiffrot.y = D3DX_PI*-0.5f;
				m_MotionState = MOTIONSTATE_RUN;
				if (pKeyboard->GetKeyboardTrigger(DIK_L))
				{
					m_MotionState = MOTIONSTATE_DASHATK;
				}
			}
			else if (m_MotionState == MOTIONSTATE_RUN)
			{// �ړ�����߂��ꍇ
			 // ���[�V�����̐؂�ւ�
				m_MotionState = MOTIONSTATE_WAIT;
			}

			else if (pKeyboard->GetKeyboardPress(DIK_UPARROW))
			{// W �L�[����
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
			{// �ړ�����߂��ꍇvbn
			 // ���[�V�����̐؂�ւ�
				m_MotionState = MOTIONSTATE_WAIT;
			}

			else if (pKeyboard->GetKeyboardTrigger(DIK_L))
			{
				PlayerCollision();
				//3�i�U��
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
	// ����
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

	// ���͂��ꂽ X�AY
	float fH, fV;
	pPad->GetJoypadStickLeft(0, &fH, &fV);

	//�Q�[���p�b�h
	if (fH != 0 || fV != 0)
	{// �ړ�
		m_move.x += sinf(atan2f(fH, fV)) * PLAYER_SPEED;
		m_move.y += cosf(atan2f(fH, fV)) * PLAYER_SPEED;
	}

	//��������
	m_move.x += (0 - m_move.x) * 1 / 5;
	m_move.y += (0 - m_move.y) * 1 / 5;

	CScene3D::SetPos(pos);
	CScene3D::SetRot(rot);
}

//====================================================================================================
// �v���C���[�̃_���[�W����
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
// �v���C���[�̃_���[�W����
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
// �v���C���[�̓����蔻��
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

		//�~�̓����蔻��
		if (fLength <= fRadius * fRadius)
		{
			PlayerDamage(pPlayer);
		}
	}
}

//=============================================================================
// ���[�V�����̍Đ�
//=============================================================================
void CPlayerBase::MotionPlayer(int nCnt)
{
	D3DXVECTOR3 Distance;

	MOTION_INFO* pInfo = &m_TypeSelect.aMotionInfo[m_TypeSelect.motionType];
	// ���[�V����
	for (int nCntModel = 0; nCntModel < m_TypeSelect.nMaxModel; nCntModel++)
	{
		KEY *pKeyInfo, *pNextKey;

		// ���݂̃L�[
		pKeyInfo = &pInfo->aKeyInfo[pInfo->nNumKey].aKey[nCntModel];

		// ���̃L�[
		if (pInfo->nNumKey + 1 == pInfo->nMaxKey)
		{
			pNextKey = &pInfo->aKeyInfo[0].aKey[nCntModel];
		}
		else
		{
			pNextKey = &pInfo->aKeyInfo[pInfo->nNumKey + 1].aKey[nCntModel];
		}

		// �p�[�c�̈ʒu�ݒ�
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
		// �p�[�c�̌����ݒ�
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
	{// ���[�V���������[�v���Ȃ��ꍇ
		if (m_PlayerType[nCnt].motionType != MOTIONTYPE_JUMP)
		{// �W�����v�ȊO
			pInfo->nNumKey = 0;
			pInfo->nCntFrame = 0;

			m_MotionState = MOTIONSTATE_WAIT;
			
		}
	}
	else if (pInfo->nNumKey == pInfo->nMaxKey && m_TypeSelect.motionType != MOTIONTYPE_JUMP)
	{// ���[�V�������I�������ꍇ
		pInfo->nNumKey = 0;
	}

	SetPosParts(&m_TypeSelect);
}

//=============================================================================
// ���[�V�����̐؂�ւ�
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
// ���f���̓ǂݍ��ݏ���
//========================================================================================================
int CPlayerBase::GetLife(void)
{
	return m_nLife;
}

//========================================================================================================
// ���f���̓ǂݍ��ݏ���
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
		
		// ���f����
		std::string sWord = { "NUM_MODEL" };
		m_PlayerType[nCnt].nMaxModel = std::stoi(CScene3D::WordLoad(&File, sWord));

		// ���[�V�����̍ő吔
		sWord = { "NUM_MOTION" };
		m_PlayerType[nCnt].nMotionMax = std::stoi(CScene3D::WordLoad(&File, sWord));

		// ���f���̃t�@�C����
		sWord = { "MODEL_FILENAME" };
		for (int nCount = 0; nCount < m_PlayerType[nCnt].nMaxModel; nCount++)
		{
			std::string sFile = CScene3D::WordLoad(&File, sWord);
			// char�^�ɃR�s�[
			std::char_traits<char>::copy(m_PlayerType[nCnt].NumModel[nCount].cFileName, sFile.c_str(), sFile.size() + 1);
		}

		// ���f���̃t�@�C����
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

		//���[�V�����̓ǂݍ���
		MotionLoad(&File, nCnt);

		CRenderer *pRenderer = CManager::GetRenderer();
		LPDIRECT3DDEVICE9 pDevice = pRenderer->GetDevice();

		for (int nCntModel = 0; nCntModel < m_PlayerType[nCnt].nMaxModel; nCntModel++)
		{
			// X�t�@�C���̓ǂݍ���
			D3DXLoadMeshFromX(m_PlayerType[nCnt].NumModel[nCntModel].cFileName, D3DXMESH_SYSTEMMEM, pDevice, NULL,
				&m_PlayerType[nCnt].NumModel[nCntModel].pBuffMat, NULL,
				&m_PlayerType[nCnt].NumModel[nCntModel].nNumMat,
				&m_PlayerType[nCnt].NumModel[nCntModel].pMesh);
		}
	}
	return S_OK;
}

//========================================================================================================
// ���[�V�����̓ǂݍ���
//========================================================================================================
HRESULT CPlayerBase::MotionLoad(std::ifstream *file, int nCnt)
{
	std::string sLine;
	int nLoop = 0;			// ���[�v�i�[�p

	MOTION_INFO *pMotion = &m_PlayerType[nCnt].aMotionInfo[0];

	// ���f���̃t�@�C����
	std::string sWord = { "MOTIONSET" };
	sLine = CScene3D::WordLoad(file, sWord);

	for (int nCountKey = 0; nCountKey < m_PlayerType[nCnt].nMotionMax; nCountKey++)
	{
		KEY_INFO *pKeyInfo = &pMotion->aKeyInfo[0];

		if (sWord == sLine)
		{
			sWord = { "LOOP" };
			nLoop = std::stoi(CScene3D::WordLoad(file, sWord));
			// 1�̏ꍇ���[�v����
			pMotion->bLoop = nLoop == 1 ? true : false;

			//�L�[�̍ő吔
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
// ���f���̉������
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
