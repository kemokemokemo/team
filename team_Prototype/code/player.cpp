//=============================================================================
//
// �v���C���[���� [player.cpp]
// Author : KOUTA KIMURA
//
//=============================================================================

//=============================================================================
// �C���N���[�h�t�@�C��
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
// �}�N����`
//=============================================================================
#define PLAYER_SPEED	(2.0f)						//�v���C���[�̑���
#define MODELFILE1		"DATA/MODEL/car_000.x"		// �ǂݍ��ރ��f��
#define MODELFILE2		"DATA/MODEL/cat.x"			// �ǂݍ��ރ��f��

//=============================================================================
//  �����o�ϐ�������
//=============================================================================
CScene3D::MODELNUM CPlayer::m_PlayerType[PLAYERTYPE_MAX] = {};

//=============================================================================
// �R���X�g���N�^
//=============================================================================
CPlayer::CPlayer(OBJTYPE type) : CScene3D(type)
{
	m_move = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	m_PlayerStateCount = 0;
}

//=============================================================================
// �f�X�g���N�^
//=============================================================================
CPlayer::~CPlayer()
{

}

//=============================================================================
// ���f���̐���
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
// ����������
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
// �I������
//=============================================================================
void CPlayer::Uninit(void)
{
	CScene3D::Uninit();
}

//=============================================================================
// �X�V����
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
// �`�揈��
//=============================================================================
void CPlayer::Draw(void)
{
	CScene3D::Draw();
}

//=============================================================================
// �v���C���[�̈ړ������Əd��
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
// �v���C���[�̈ړ�����
//=============================================================================
D3DXVECTOR3 CPlayer::GetPlayerPos(void)
{
	D3DXVECTOR3 pos = CScene3D::GetPos();

	return pos;
}

//=============================================================================
// �v���C���[�̈ړ�����
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
		{//  A �L�[����
			m_move.x += D3DX_PI*-0.5f* PLAYER_SPEED;

			m_fDiffrot.y = D3DX_PI*0.5f;
		}

		else if (pKetybord->GetKeyboardPress(DIK_D))
		{//  D �L�[����
			m_move.x += D3DX_PI*0.5f * PLAYER_SPEED;
			m_fDiffrot.y = D3DX_PI*-0.5f;
		}

		else if (pKetybord->GetKeyboardTrigger(DIK_W))
		{// W �L�[����
			m_move.y += 50;
		}

		if (pKetybord->GetKeyboardTrigger(DIK_SPACE))
		{//  Z�L�[���� �U��
			PlayerCollision();
		}
	}

	if (m_PlayerNum == PLAYER_02)
	{
		if (pKetybord->GetKeyboardPress(DIK_LEFTARROW))
		{//  A �L�[����
			m_move.x += D3DX_PI*-0.5f* PLAYER_SPEED;
			m_fDiffrot.y = D3DX_PI*0.5f;
		}

		else if (pKetybord->GetKeyboardPress(DIK_RIGHTARROW))
		{//  D �L�[����
			m_move.x += D3DX_PI*0.5f * PLAYER_SPEED;
			m_fDiffrot.y = D3DX_PI*-0.5f;
		}

		else if (pKetybord->GetKeyboardTrigger(DIK_UPARROW))
		{//  S �L�[����
			m_move.y += 50;
		}

		if (pKetybord->GetKeyboardTrigger(DIK_RETURN))
		{//  X�L�[���� �U��
			PlayerCollision();
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
// �v���C���[�̃_���[�W����
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
// �v���C���[�̓����蔻��
//========================================================================================================
void CPlayer::PlayerCollision()
{
	//���a
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
				//�~�̓����蔻��
				if (D3DXVec3LengthSq(&(Pos01 - Pos02)) <= (fRadiusPL01 + fRadiusPL02) * (fRadiusPL01 + fRadiusPL02))
				{
 					PlayerDamage();
				}

			}
		}
	}
}

//========================================================================================================
// ���f���̓ǂݍ��ݏ���
//========================================================================================================
int CPlayer::GetLife(void)
{
	return m_nLife;
}

//========================================================================================================
// ���f���̓ǂݍ��ݏ���
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

		// ���f����
		std::string sWord = { "NUM_MODEL" };
		m_PlayerType[nCnt].nMaxModel = std::stoi(CScene3D::WordLoad(&File, sWord));

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
// ���f���̉������
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