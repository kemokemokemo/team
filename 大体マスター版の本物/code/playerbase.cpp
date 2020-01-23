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
#include "model.h"
#include "effect.h"
#include "HitModel.h"
#include "sound.h"
#include"Game.h"
#include "Result.h"
#include "guard.h"
#include "bullet.h"
//=============================================================================
// �}�N����`
//=============================================================================
#define PLAYER_SPEED		(1.0f)						//�v���C���[�̑���
#define PLAYER__BLOWAWAY	(2.0f)					//�v���C���[�̐������
#define MODELFILE1		"DATA/motion_ken.txt"		// �ǂݍ��ރ��f��
#define MODELFILE2		"DATA/motion_Kangaroo.txt"	// �ǂݍ��ރ��f��
#define MODELFILE3		"DATA/motion_sword.txt"	// �ǂݍ��ރ��f��

//=============================================================================
// �����o�ϐ�������
//=============================================================================
CScene3D::MODELNUM CPlayerBase::m_PlayerType[PLAYERTYPE_MAX] = {};
CPlayerBase::MOTION_INFO CPlayerBase::aMotionInfo[PLAYERTYPE_MAX][CPlayerBase::MOTIONTYPE_MAX] = {};
char *CPlayerBase::TextLoad[PLAYERTYPE_MAX];

//=============================================================================
// �R���X�g���N�^
//=============================================================================
CPlayerBase::CPlayerBase(OBJTYPE type) : CScene3D(type)
{
	m_move = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	//m_PlayerStateCount = 0;
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
HRESULT CPlayerBase::Init(D3DXVECTOR3 pos, D3DXVECTOR3 rot, int nlife,CMaker::MAKERTYPE MokerType)
{
	BindModel(&m_PlayerType[m_TypeChara]);
	//BindMotion(m_PlayerType[m_TypeChara].aMotionInfo);

	CScene3D::Init();

	m_posOld = pos;
	m_rot = rot;
	m_pos = pos;
	m_nLife = nlife;
	m_MokerType = MokerType;

	CScene3D::SetPos(pos);
	SetRot(m_rot);

	m_PlayerStateCount = 2;

	nCountATK = 0;

	nCountWin = 0;

	m_PlayerDownCnt = 60;

	m_Guardold = MOTIONTYPE_WAIT;

	m_MotionType = MOTIONTYPE_WAIT;					// ���݂̃��[�V����

	bJump = true;

	bWJump = true;

	pMaker = NULL;
	m_Hitmodel = NULL;

	m_PlayerState = PLAYERSTATE_NORMAL;

	for (int nCnt = 0; nCnt < MOTIONTYPE_MAX; nCnt++)
	{
		MotionInfo[nCnt] = aMotionInfo[m_TypeChara][nCnt];
	}

	if (CManager::GetMode() == CManager::MODE_GAME)
	{
		if (m_MokerType == CMaker::MAKERTYPE_1P)
		{
			pMaker = CMaker::Create(pos, CMaker::MAKERTYPE_1P, m_nLife);
			pGauge = CGauge::Create(D3DXVECTOR3(170.0f, 650.0f, 0.0f), m_nLife, CMaker::MAKERTYPE_1P);
			m_fDiffrot.y = -D3DX_PI*0.5f;
		}
		if (m_MokerType == CMaker::MAKERTYPE_2P)
		{
			pMaker = CMaker::Create(pos, CMaker::MAKERTYPE_2P, m_nLife);
			pGauge = CGauge::Create(D3DXVECTOR3(770.0f, 650.0f, 0.0f), m_nLife, CMaker::MAKERTYPE_2P);
			m_fDiffrot.y = D3DX_PI*0.5f;
		}
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
	//���[�V�����̍Đ�
	MotionPlayer();

	if (m_MokerType == CMaker::MAKERTYPE_1P)
	{
		if (m_Guardold == MOTIONTYPE_WAIT)
		{
			if (m_MotionType == MOTIONTYPE_GAUDE)
			{
				pGuard = CGuard::Create(GetPos(), 10, CMaker::MAKERTYPE_1P);
				m_Guardold = MOTIONTYPE_GAUDE;
			}
		}

		if (m_Guardold == MOTIONTYPE_GAUDE)
		{
			if (m_MotionType != MOTIONTYPE_GAUDE)
			{
				pGuard->Release();
				m_Guardold = MOTIONTYPE_WAIT;
			}
		}
	}

	if (m_MokerType == CMaker::MAKERTYPE_2P)
	{
		if (m_Guardold == MOTIONTYPE_WAIT)
		{
			if (m_MotionType == MOTIONTYPE_GAUDE)
			{
				pGuard = CGuard::Create(GetPos(), 10, CMaker::MAKERTYPE_2P);
				m_Guardold = MOTIONTYPE_GAUDE;
			}
		}

		if (m_Guardold == MOTIONTYPE_GAUDE)
		{
			if (m_MotionType != MOTIONTYPE_GAUDE)
			{
				pGuard->Release();
				m_Guardold = MOTIONTYPE_WAIT;
			}
		}

	}
	if (m_MotionType ==  MOTIONTYPE_DOWN)
	{
		m_PlayerDownCnt++;
		if (m_PlayerDownCnt >= 120)
		{
			m_MotionType = MOTIONTYPE_STANDUP;
			m_PlayerDownCnt = 0;
		}
	}
	else if (CManager::GetMode() == CManager::MODE_RESULT)
	{
		nCountWin++;
		if (nCountWin >= 60)
		{
			if (m_MotionType == MOTIONTYPE_WAIT)
			{
				MotionChangePlayer(MOTIONTYPE_WIN);
			}
		}
		else
		{
			MotionChangePlayer(MOTIONTYPE_WAIT);
		}
	}

	switch (m_PlayerState)
	{
	case PLAYERSTATE_NORMAL:
		nCountATK = 0;

		break;

	case PLAYERSTATE_DAMAGE:
		MotionChangePlayer(MOTIONTYPE_DAMAGE);
		m_PlayerState = PLAYERSTATE_NORMAL;
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
		m_PlayerState = PLAYERSTATE_ATK;
		MotionChangePlayer(MOTIONTYPE_LIGHT0);
		break;
	case MOTIONTYPE_LIGHT1:
		m_PlayerState = PLAYERSTATE_ATK;
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
	case MOTIONTYPE_DOWN:
		MotionChangePlayer(MOTIONTYPE_DOWN);
		break;
	case MOTIONTYPE_STANDUP:
		MotionChangePlayer(MOTIONTYPE_STANDUP);
		break;
	case MOTIONTYPE_WIN:
		m_PlayerState = PLAYERSTATE_ATK;
		MotionChangePlayer(MOTIONTYPE_WIN);
		break;
	case MOTIONTYPE_WINWAIT:
		m_PlayerState = PLAYERSTATE_NORMAL;
		MotionChangePlayer(MOTIONTYPE_WINWAIT);
		break;
	}

	if (MotionInfo[m_MotionType].nHitIdx != -1 &&
		MotionInfo[m_MotionType].nAtkStar <= MotionInfo[m_MotionType].nNumKey && MotionInfo[m_MotionType].nAtkEnd >= MotionInfo[m_MotionType].nNumKey)
	{
		this->PlayerCollision();
	}
	else if (m_Hitmodel)
	{// �����Ȃ�
		m_Hitmodel->Uninit();
		m_Hitmodel = NULL;
	}
	this->PlayerMove();

	this->PlayerCollisionShape();

	MoveLimit();

	this->PlayerCollisionFloor();

	D3DXVECTOR3 pos = GetPos();
	if (pos.x <= -500.0f)
	{
		pos.x = -499.0f;
		m_move.x = 0.0f;
	}
	else if (pos.x >= 500.0f)
	{
		pos.x = 499.0f;
		m_move.x = 0.0f;

	}
	SetPos(pos);


	CScene3D::Update();
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

	m_move.y -= 1.6f;


	CScene3D::SetPos(pos);
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
	m_move.x += (0 - m_move.x) * 1 / 4;
	m_move.y += (0 - m_move.y) * 1 / 4;

	pos += m_move;

	CScene3D::SetPos(pos);
	CScene3D::SetRot(rot);
}

//====================================================================================================
// �v���C���[�̃_���[�W����
//=====================================================================================================
void CPlayerBase::PlayerDamage(CPlayerBase *pPlayer)
{
	switch (m_TypeChara)
	{
	case PLAYERTYPE_KEN:
		KenDamage(pPlayer);
		break;

	case PLAYERTYPE_KANGAROO:
		KangarooDamage(pPlayer);
		break;

	case PLAYERTYPE_SWORD:
		SwordDamage(pPlayer);
		break;
	}
}

//====================================================================================================
// �v���C���[�̃_���[�W����
//=====================================================================================================
void CPlayerBase::Damage(CPlayerBase *pPlayer, int nDamage)
{
	//�T�E���h�̎擾
	CSound *pSound = CManager::GetSound();

	if (pPlayer->m_PlayerState == PLAYERSTATE_NORMAL || pPlayer->m_PlayerState == PLAYERSTATE_ATK || pPlayer->m_PlayerState == PLAYERSTATE_AIRATK)
	{
		pSound->PlaySound(CSound::SOUND_LABEL_SE_ATK);

		pPlayer->m_nLife -= nDamage;
		CEffect::SetParticle(pPlayer->GetPos(), D3DXVECTOR3(0.0f, 0.0f, 0.0f), 10, CEffect::EFFECTTYPE_EXPLOSION);
		float fAngle = 0.0f;
		float fSpeed = 0.0f;

		for (int nCnt = 0; nCnt < 50; nCnt++)
		{
			// �o������
			fAngle = float(rand() % 314) / 20.0f - float(rand() % 314) / 20.0f;	// �S�����o��
			D3DXVECTOR3 move0 = D3DXVECTOR3(sinf(fAngle)*(fSpeed + rand() % 12 + 5.0f), cosf(fAngle)*(fSpeed + rand() % 12 + 5.0f), 0.0f);
			D3DXVECTOR3 move1 = D3DXVECTOR3(sinf(fAngle)*fSpeed, 0.0f, cosf(fAngle)*fSpeed);
			D3DXVECTOR3 move2 = D3DXVECTOR3(0.0f, sinf(fAngle)*fSpeed, cosf(fAngle)*fSpeed);
			CEffect::SetParticle(pPlayer->GetPos(), move0, 10, CEffect::EFFECTTYPE_DAMAGE);
		}

		pPlayer->m_PlayerState = PLAYERSTATE_DAMAGE;
		pPlayer->m_PlayerStateCount = 60;

		pPlayer->pMaker->MakerLife(nDamage);

		pPlayer->pGauge->GaugeLife(nDamage);
	}

	if (pPlayer->m_PlayerState == PLAYERSTATE_GAUDE)
	{
		pPlayer->pGuard->GuardLife(nDamage);

		int nLife = pPlayer->pGuard->GetGuardLife();

		if (nLife <= 0)
		{
			pPlayer->m_MotionType = MOTIONTYPE_DOWN;
		}

		pPlayer->m_PlayerState = PLAYERSTATE_NORMAL;
	}

	if (pPlayer->m_nLife <= 0)
	{
		pPlayer->m_nLife = 0;
	}
}
//========================================================================================================
// �v���C���[�̓����蔻��
//========================================================================================================
void CPlayerBase::PlayerCollision()
{
	float fMinLength = 10000.0f;
	CPlayerBase *pPlayer[2] = {};


	D3DXVECTOR3 pos = {};
	D3DXVECTOR3 NocVec;
	D3DXVECTOR3 Nocmove;

	// ���[�V�����ł̍��W
	D3DXMATRIX mtxWorld = GetModel().NumModel[MotionInfo[m_MotionType].nHitIdx].mtxWorld;

	pos.x = mtxWorld._41;
	pos.y = mtxWorld._42;
	pos.z = mtxWorld._43;

	if (MotionInfo[m_MotionType].nAtkStar == MotionInfo[m_MotionType].nNumKey && MotionInfo[m_MotionType].nCntFrame == 0)
	{// �����蔻��̉���

		if (m_Hitmodel)
		{
			m_Hitmodel->Uninit();
			m_Hitmodel = NULL;
		}
#ifdef _DEBUG
		m_Hitmodel = CHitModel::Create(pos, D3DXVECTOR3(m_fAttack, m_fAttack, m_fAttack));
#endif // DEBUG
	}
	else if (m_Hitmodel)
	{
		m_Hitmodel->SetPos(pos);
	}

	for (int nCntScene = 0; nCntScene < MAX_POLYGON; nCntScene++)
	{
		CScene *pScene;

		pScene = CScene::GetScene(OBJTYPE_PLAYER, nCntScene);

		if (!pScene || nCntScene == GetID())
			continue;

		pPlayer[0] = (CPlayerBase*)pScene;

		D3DXVECTOR3 headpos, legpos = {};

		headpos = pPlayer[0]->GetPos();

		int nCount = 1;
		while (nCount != -1)
		{
			D3DXVec3Add(&headpos, &headpos, &pPlayer[0]->GetModel().NumModel[nCount].pos);

			nCount = pPlayer[0]->GetModel().NumModel[nCount].nIdxModel;
		}

		legpos = pPlayer[0]->GetPos();

		D3DXVECTOR3 dis = headpos - legpos;

		headpos -= dis / 6;
		legpos += dis / 4;

		D3DXVECTOR3 aPos[2] = { headpos , legpos };

		float fLength = 0.0f;

		for (int nCnt = 0; nCnt < 2; nCnt++)
		{
			fLength = D3DXVec3LengthSq(&(aPos[nCnt] - pos));

			if (fMinLength > fLength)
			{
				fMinLength = fLength;
				pPlayer[1] = pPlayer[0];
			}
		}
		pos = GetPos();
		NocVec = pos - pPlayer[0]->GetPos();
		Nocmove = pPlayer[0]->GetMove();
	}

	if (pPlayer[1] && pPlayer[1]->m_PlayerState != PLAYERSTATE_DAMAGE && pPlayer[1]->m_MotionType != MOTIONTYPE_DOWN && pPlayer[1]->m_MotionType != MOTIONTYPE_STANDUP)
	{
		float fRadius = m_fAttack + pPlayer[1]->m_fRadius;

		//�~�̓����蔻��
		if (fMinLength <= fRadius * fRadius)
		{
			if (m_MotionOld != m_MotionType)
			{
				m_MotionOld = m_MotionType;
				PlayerDamage(pPlayer[1]);

				if (pPlayer[1]->GetLife() <= 0)
				{
					if (pPlayer[1]->GetID() < GetID())
					{
						CGame::DeletePlayer(0);
					}
					else
					{
						CGame::DeletePlayer(1);
					}
					CResult::SetWinPlayer(GetTypeChara(), GetMaker());

					pPlayer[1]->Uninit();

					CFade::SetFade(CManager::MODE_RESULT);
				}
			}
			if (pPlayer[1]->m_MotionType != MOTIONTYPE_GAUDE)
			{
				if (m_MotionType == MOTIONTYPE_LIGHT2 || m_MotionType == MOTIONTYPE_DASHATK || m_MotionType == MOTIONTYPE_AIR_N || m_MotionType == MOTIONTYPE_AIR_F
					|| m_MotionType == MOTIONTYPE_AIR_B || m_MotionType == MOTIONTYPE_AIR_U || m_MotionType == MOTIONTYPE_SP_N || m_MotionType == MOTIONTYPE_SP_UP || m_MotionType == MOTIONTYPE_SP_DOWN)
				{
					pPlayer[1]->m_MotionType = MOTIONTYPE_DOWN;


					if (pos.x < pPlayer[1]->GetPos().x)
					{
						Nocmove.y = 0.0f;
						Nocmove.x += PLAYER__BLOWAWAY;
						pPlayer[1]->SetMove(Nocmove);
					}
					else
					{
						Nocmove.y = 0.0f;
						Nocmove.x -= PLAYER__BLOWAWAY;
						pPlayer[1]->SetMove(Nocmove);
					}
				}
			}
		}
	}
}

//========================================================================================================
// �v���C���[�̏Փ˔���
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

		if (pPlayer->m_MotionType == MOTIONTYPE_DOWN || pPlayer->m_MotionType == MOTIONTYPE_STANDUP ||
			m_MotionType == MOTIONTYPE_DOWN || m_MotionType == MOTIONTYPE_STANDUP)
			break;

		// �� ����
		D3DXVECTOR3 pos[2] = { m_pos, m_pos };
		D3DXVECTOR3 opponent[2] = { pPlayer->m_pos, pPlayer->m_pos };

		// ���[�V�����ł̍��W
		D3DXMATRIX mtxWorld = GetModel().NumModel[1].mtxWorld;
		pos[0] = D3DXVECTOR3(mtxWorld._41, mtxWorld._42, mtxWorld._43);

		mtxWorld = pPlayer->GetModel().NumModel[1].mtxWorld;
		opponent[0] = D3DXVECTOR3(mtxWorld._41, mtxWorld._42, mtxWorld._43);

		// ���̏Փˈʒu����
		pos[0] -= (pos[0] - pos[1]) / 4.0f;
		pos[1] += (pos[0] - pos[1]) / 4.0f;

		// ���̏Փˈʒu����
		opponent[0] -= (opponent[0] - opponent[1]) / 4.0f;
		opponent[1] += (opponent[0] - opponent[1]) / 4.0f;

		// ���f���ƕ��̂̋���
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

		// ���a
		float fRadiusA = m_fRadius;
		float fRadiusB = pPlayer->m_fRadius;

		if (fRadius <= (fRadiusA + fRadiusB))
		{// ���a+���a���߂���

			D3DXVECTOR3 vec;
			D3DXVec3Normalize(&vec, &Vec);			//���K������

													// �ǂꂾ���߂荞�񂾂�
			fRadius = (fRadiusB + fRadiusA) - fRadius;

			D3DXVECTOR3 pos = GetPos() + vec * fRadius;
			pos.z = 0.0f;

			SetPos(pos);

			D3DXVECTOR3 temp = D3DXVECTOR3(0.0f, 1.0f, 0.0f);

			float cosA = D3DXVec3Dot(&Vec, &temp) / D3DXVec3Length(&(Vec * -1.0f));

			m_move.y -= m_move.y * cosA * cosA * (fRadius / fRadiusA);
		}
	}
}

//=============================================================================
// ���[�V�����̍Đ�
//=============================================================================
void CPlayerBase::MotionPlayer()
{
	D3DXVECTOR3 Distance;
	MODELNUM model = GetModel();

	MOTION_INFO* pInfo = &MotionInfo[m_MotionType];

	// ���[�V����
	for (int nCntModel = 0; nCntModel < model.nMaxModel; nCntModel++)
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
		// �p�[�c�̌����ݒ�
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
	{// ���[�V���������[�v���Ȃ��ꍇ
		pInfo->nNumKey = 0;
		pInfo->nCntFrame = 0;
		if (m_MotionType == MOTIONTYPE_WIN)
		{
			m_MotionType = MOTIONTYPE_WINWAIT;
		}
		else
		{
			m_MotionType = MOTIONTYPE_WAIT;
		}
	}
	else if (pInfo->nNumKey == pInfo->nMaxKey)
	{// ���[�V�������I�������ꍇ
		pInfo->nNumKey = 0;
	}

	SetModel(model);
}

//=============================================================================
// ���[�V�����̐؂�ւ�
//=============================================================================
void CPlayerBase::MotionChangePlayer(MOTIONTYPE motionType)
{
	if (m_MotionType != motionType)
	{
		MotionInfo[m_MotionType].nNumKey = 0;
		MotionInfo[m_MotionType].nCntFrame = 0;
		m_MotionOld = m_MotionType;
		m_MotionType = motionType;
	}
}
//========================================================================================================
// �P���̃_���[�W����
//========================================================================================================
void CPlayerBase::KenDamage(CPlayerBase *pPlayer)
{
	switch (m_MotionType)
	{
	case MOTIONTYPE_LIGHT0:
		// ��U��1�i��
		Damage(pPlayer, 2);
		break;

	case MOTIONTYPE_LIGHT1:
		// 2�i��
		Damage(pPlayer, 2);
		break;

	case MOTIONTYPE_LIGHT2:
		// 3�i��
		Damage(pPlayer, 3);
		break;

	case MOTIONTYPE_DASHATK:
		// �_�b�V���U��
		Damage(pPlayer, 8);
		break;

	case MOTIONTYPE_UPATK:
		// ��U��
		Damage(pPlayer, 14);
		break;

	case MOTIONTYPE_CROUCHATK:
		// ���Ⴊ�ݍU��
		Damage(pPlayer, 5);
		break;

	case MOTIONTYPE_AIR_N:
		// �󒆃j���[�g����
		Damage(pPlayer, 6);
		break;

	case MOTIONTYPE_AIR_F:
		// �󒆑O
		Damage(pPlayer, 11);
		break;

	case MOTIONTYPE_AIR_B:
		// �󒆌��
		Damage(pPlayer, 13);
		break;

	case MOTIONTYPE_AIR_U:
		// �󒆏�
		Damage(pPlayer, 7);
		break;

	case MOTIONTYPE_AIR_D:
		// �󒆉�
		Damage(pPlayer, 17);
		break;

	case MOTIONTYPE_SP_N:
		//����
		Damage(pPlayer, 20);
		break;

	case MOTIONTYPE_SP_UP:
		//�����
		Damage(pPlayer, 17);
		break;

	case MOTIONTYPE_SP_DOWN:
		//������
		Damage(pPlayer, 30);
		break;
	}
}

//========================================================================================================
// �J���K���[�̃_���[�W����
//========================================================================================================
void CPlayerBase::KangarooDamage(CPlayerBase *pPlayer)
{
	switch (m_MotionType)
	{
	case MOTIONTYPE_LIGHT0:
		// ��U��1�i��
		Damage(pPlayer, 4);
		break;

	case MOTIONTYPE_LIGHT1:
		// 2�i��
		Damage(pPlayer, 4);
		break;

	case MOTIONTYPE_LIGHT2:
		// 3�i��
		Damage(pPlayer, 1);
		break;

	case MOTIONTYPE_DASHATK:
		// �_�b�V���U��
		Damage(pPlayer, 9);
		break;

	case MOTIONTYPE_UPATK:
		// ��U��
		Damage(pPlayer, 7);
		break;

	case MOTIONTYPE_CROUCHATK:
		// ���Ⴊ�ݍU��
		Damage(pPlayer, 10);
		break;

	case MOTIONTYPE_AIR_N:
		// �󒆃j���[�g����
		Damage(pPlayer, 6);
		break;

	case MOTIONTYPE_AIR_F:
		// �󒆑O
		Damage(pPlayer, 11);
		break;

	case MOTIONTYPE_AIR_B:
		// �󒆌��
		Damage(pPlayer, 10);
		break;

	case MOTIONTYPE_AIR_U:
		// �󒆏�
		Damage(pPlayer, 8);
		break;

	case MOTIONTYPE_AIR_D:
		// �󒆉�
		Damage(pPlayer, 13);
		break;

	case MOTIONTYPE_SP_N:
		//����
		Damage(pPlayer, 15);
		break;

	case MOTIONTYPE_SP_UP:
		//�����
		Damage(pPlayer, 16);
		break;

	case MOTIONTYPE_SP_DOWN:
		//������
		Damage(pPlayer, 20);
		break;
	}

}

//========================================================================================================
// �\�[�h�̃_���[�W����
//========================================================================================================
void CPlayerBase::SwordDamage(CPlayerBase *pPlayer)
{
	switch (m_MotionType)
	{
	case MOTIONTYPE_LIGHT0:
		// ��U��1�i��
		Damage(pPlayer, 3);
		break;

	case MOTIONTYPE_LIGHT1:
		// 2�i��
		Damage(pPlayer, 3);
		break;

	case MOTIONTYPE_LIGHT2:
		// 3�i��
		Damage(pPlayer, 5);
		break;

	case MOTIONTYPE_DASHATK:
		// �_�b�V���U��
		Damage(pPlayer, 15);
		break;

	case MOTIONTYPE_UPATK:
		// ��U��
		Damage(pPlayer, 7);
		break;

	case MOTIONTYPE_CROUCHATK:
		// ���Ⴊ�ݍU��
		Damage(pPlayer, 9);
		break;

	case MOTIONTYPE_AIR_N:
		// �󒆃j���[�g����
		Damage(pPlayer, 8);
		break;

	case MOTIONTYPE_AIR_F:
		// �󒆑O
		Damage(pPlayer, 12);
		break;

	case MOTIONTYPE_AIR_B:
		// �󒆌��
		Damage(pPlayer, 16);
		break;

	case MOTIONTYPE_AIR_U:
		// �󒆏�
		Damage(pPlayer, 13);
		break;

	case MOTIONTYPE_AIR_D:
		// �󒆉�
		Damage(pPlayer, 13);
		break;

	case MOTIONTYPE_SP_N:
		//����
		Damage(pPlayer, 17);
		break;

	case MOTIONTYPE_SP_UP:
		//�����
		Damage(pPlayer, 16);
		break;

	case MOTIONTYPE_SP_DOWN:
		//������
		Damage(pPlayer, 16);
		break;
	}
}

//========================================================================================================
// ���f���̓ǂݍ��ݏ���
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

	MOTION_INFO *pMotion = &aMotionInfo[nCnt][0];

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
			pMotion->bLoop = (nLoop == 1) ? true : false;

			//�L�[�̍ő吔
			sWord = { "NUM_KEY" };
			pMotion->nMaxKey = std::stoi(CScene3D::WordLoad(file, sWord));

			sWord = { "ATKSET" };
			if (CScene3D::WordLoad(file, sWord, 1) == sWord)
			{
				// �U������Ƃ��̕���
				sWord = { "ATK_IDX" };
				pMotion->nHitIdx = std::stoi(CScene3D::WordLoad(file, sWord));

				// �U������Ƃ��̃L�[(�ŏ�)
				sWord = { "ATK_START" };
				pMotion->nAtkStar = std::stoi(CScene3D::WordLoad(file, sWord));

				// �U������Ƃ��̃L�[(�Ō�)
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
//========================================================================================================
// ���̓����蔻��
//========================================================================================================
void CPlayerBase::PlayerCollisionFloor(void)
{
	m_posOld = m_pos;

	m_pos = CScene3D::GetPos();

	D3DXVECTOR3 size = CScene3D::GetScale();

	if ((CModel::CollisionModel(&m_pos, &m_posOld, size)) == true)
	{
		if (bJump == true)
		{
			bJump = false;
			bWJump = false;
		}
		else
		{//���n
			if (m_MotionType == MOTIONTYPE_JUMP || m_PlayerState == PLAYERSTATE_AIRATK)
			{
				MotionChangePlayer(MOTIONTYPE_RAND);
			}
			CScene3D::SetHight(m_pos.y);
		}
	}
}

void CPlayerBase::PlayerPad(int cnt)
{
	CPad *pGamePad = CManager::GetPad();
	CKeybord *pKeyboard = CManager::GetKeybord();

	if (m_PlayerState != PLAYERSTATE_ATK && m_MotionType != MOTIONTYPE_DAMAGE && m_MotionType != MOTIONTYPE_STANDUP)
	{
		//��
		if (bJump == false && m_MotionType != MOTIONTYPE_RAND)
		{
			if (CManager::GetMode() == CManager::MODE_GAME)
			{
				if (m_MotionType == MOTIONTYPE_DOWN)
				{
					if (pKeyboard->GetKeyboardPress(DIK_B) || pGamePad->GetJoypadTrigger(cnt, CPad::JOYPADKEY_A) || pGamePad->GetJoypadPress(cnt, CPad::JOYPADKEY_B) || pGamePad->GetJoypadPress(cnt, CPad::JOYPADKEY_X))
					{
						m_MotionType = MOTIONTYPE_STANDUP;
					}
				}
				else if (pKeyboard->GetKeyboardTrigger(DIK_J) || pGamePad->GetJoypadTrigger(cnt, CPad::JOYPADKEY_Y))
				{//�W�����v
					bJump = true;
					bWJump = true;
					m_move.y += m_fJump;
				}
				else if (pKeyboard->GetKeyboardPress(DIK_A) || pGamePad->GetJoypadPress(cnt, CPad::JOYPADKEY_LEFT))
				{//  A �L�[����
					m_move.x += D3DX_PI*-0.5f* m_fSpeed;
					m_fDiffrot.y = D3DX_PI*0.5f;
					MotionChangePlayer(MOTIONTYPE_RUN);

					if (pKeyboard->GetKeyboardPress(DIK_SPACE) || pGamePad->GetJoypadPress(cnt, CPad::JOYPADKEY_B))
					{
						MotionChangePlayer(MOTIONTYPE_DASHATK);
					}
					else if (pKeyboard->GetKeyboardPress(DIK_B) || pGamePad->GetJoypadTrigger(cnt, CPad::JOYPADKEY_A))
					{//����U���j���[�g����
						MotionChangePlayer(MOTIONTYPE_SP_N);
					}
				}
				else if (pKeyboard->GetKeyboardPress(DIK_D) || pGamePad->GetJoypadPress(cnt, CPad::JOYPADKEY_RIGHT))
				{//  D �L�[����
					m_move.x += D3DX_PI*0.5f * m_fSpeed;
					m_fDiffrot.y = D3DX_PI*-0.5f;
					MotionChangePlayer(MOTIONTYPE_RUN);

					if (pKeyboard->GetKeyboardPress(DIK_SPACE) || pGamePad->GetJoypadTrigger(cnt, CPad::JOYPADKEY_B))
					{
						MotionChangePlayer(MOTIONTYPE_DASHATK);
					}
					else if (pKeyboard->GetKeyboardPress(DIK_B) || pGamePad->GetJoypadTrigger(cnt, CPad::JOYPADKEY_A))
					{//����U���j���[�g����
						MotionChangePlayer(MOTIONTYPE_SP_N);
					}
				}
				else if (m_MotionType == MOTIONTYPE_RUN)
				{// �ړ�����߂��ꍇ
				 // ���[�V�����̐؂�ւ�
					MotionChangePlayer(MOTIONTYPE_WAIT);
				}

				else if (pKeyboard->GetKeyboardPress(DIK_W) || pGamePad->GetJoypadPress(cnt, CPad::JOYPADKEY_UP))
				{// W �L�[����
					if (pKeyboard->GetKeyboardPress(DIK_SPACE) || pGamePad->GetJoypadTrigger(cnt, CPad::JOYPADKEY_B))
					{
						MotionChangePlayer(MOTIONTYPE_UPATK);
					}
					else if (pKeyboard->GetKeyboardPress(DIK_B) || pGamePad->GetJoypadTrigger(cnt, CPad::JOYPADKEY_A))
					{//����U����
						MotionChangePlayer(MOTIONTYPE_SP_UP);
					}
				}

				else if (pKeyboard->GetKeyboardPress(DIK_S) || pGamePad->GetJoypadPress(cnt, CPad::JOYPADKEY_DOWN))
				{
					MotionChangePlayer(MOTIONTYPE_CROUCHWAIT);
					if (pKeyboard->GetKeyboardPress(DIK_SPACE) || pGamePad->GetJoypadTrigger(cnt, CPad::JOYPADKEY_B))
					{
						MotionChangePlayer(MOTIONTYPE_CROUCHATK);
					}
					else if (pKeyboard->GetKeyboardPress(DIK_B) || pGamePad->GetJoypadTrigger(cnt, CPad::JOYPADKEY_A))
					{//����U����
						MotionChangePlayer(MOTIONTYPE_SP_DOWN);
					}
				}

				else if (m_MotionType == MOTIONTYPE_CROUCHWAIT)
				{// �ړ�����߂��ꍇ
				 // ���[�V�����̐؂�ւ�
					MotionChangePlayer(MOTIONTYPE_WAIT);
				}
				else if (pKeyboard->GetKeyboardPress(DIK_B) || pGamePad->GetJoypadTrigger(cnt, CPad::JOYPADKEY_A))
				{//����U���j���[�g����
					MotionChangePlayer(MOTIONTYPE_SP_N);
				}
				else if (pKeyboard->GetKeyboardTrigger(DIK_SPACE) || pGamePad->GetJoypadTrigger(cnt, CPad::JOYPADKEY_B))
				{
					MotionChangePlayer(MOTIONTYPE_LIGHT0);
				}
				else if (pKeyboard->GetKeyboardPress(DIK_G) || pGamePad->GetJoypadPress(cnt, CPad::JOYPADKEY_X))
				{
					MotionChangePlayer(MOTIONTYPE_GAUDE);
				}
			}
		}

		//��
		else
		{
			if (m_PlayerState != PLAYERSTATE_AIRATK && m_MotionType != MOTIONTYPE_DAMAGE)
			{
				if (m_MotionType != MOTIONTYPE_DOUBLEJUMP && m_MotionType != MOTIONTYPE_RAND)
				{
					MotionChangePlayer(MOTIONTYPE_JUMP);
				}
				if (bWJump == true)
				{
					if (pKeyboard->GetKeyboardPress(DIK_J) || pGamePad->GetJoypadTrigger(cnt, CPad::JOYPADKEY_Y))
					{//��i�W�����v
						MotionChangePlayer(MOTIONTYPE_DOUBLEJUMP);
						bWJump = false;
						m_move.y = 0.0f;
						m_move.y += m_fAirJump;
					}
				}
				if (pKeyboard->GetKeyboardPress(DIK_A) || pGamePad->GetJoypadPress(cnt, CPad::JOYPADKEY_LEFT))
				{//  A �L�[����
					m_move.x += D3DX_PI*-0.5f* m_fAirSpeed;

					if (pKeyboard->GetKeyboardPress(DIK_SPACE) || pGamePad->GetJoypadTrigger(cnt, CPad::JOYPADKEY_B))
					{
						if (m_fDiffrot.y == D3DX_PI*0.5f)
						{
							MotionChangePlayer(MOTIONTYPE_AIR_F);
						}
						else
						{
							MotionChangePlayer(MOTIONTYPE_AIR_B);
						}
					}
				}
				else if (pKeyboard->GetKeyboardPress(DIK_D) || pGamePad->GetJoypadPress(cnt, CPad::JOYPADKEY_RIGHT))
				{//  D �L�[����
					m_move.x += D3DX_PI*0.5f * m_fAirSpeed;
					if (pKeyboard->GetKeyboardPress(DIK_SPACE) || pGamePad->GetJoypadTrigger(cnt, CPad::JOYPADKEY_B))
					{
						if (m_fDiffrot.y == D3DX_PI*-0.5f)
						{
							MotionChangePlayer(MOTIONTYPE_AIR_F);
						}
						else
						{
							MotionChangePlayer(MOTIONTYPE_AIR_B);
						}
					}
				}
				else if (pKeyboard->GetKeyboardPress(DIK_W) || pGamePad->GetJoypadPress(cnt, CPad::JOYPADKEY_UP))
				{
					if (pKeyboard->GetKeyboardPress(DIK_SPACE) || pGamePad->GetJoypadTrigger(cnt, CPad::JOYPADKEY_B))
					{
						MotionChangePlayer(MOTIONTYPE_AIR_U);
					}
				}
				else if (pKeyboard->GetKeyboardPress(DIK_S) || pGamePad->GetJoypadPress(cnt, CPad::JOYPADKEY_DOWN))
				{
					m_move.y -= 1.2f;
					if (pKeyboard->GetKeyboardPress(DIK_SPACE) || pGamePad->GetJoypadTrigger(cnt, CPad::JOYPADKEY_B))
					{
						MotionChangePlayer(MOTIONTYPE_AIR_D);
					}
				}
				else if (pKeyboard->GetKeyboardPress(DIK_SPACE) || pGamePad->GetJoypadTrigger(cnt, CPad::JOYPADKEY_B))
				{
					MotionChangePlayer(MOTIONTYPE_AIR_N);
				}
			}
		}
	}

	switch (m_TypeChara)
	{
	case PLAYERTYPE::PLAYERTYPE_KEN:
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
			if (nCountATK >= m_fLightAtk)
			{
				if (pKeyboard->GetKeyboardTrigger(DIK_SPACE) || pGamePad->GetJoypadTrigger(cnt, CPad::JOYPADKEY_B))
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
			if (nCountATK >= m_fLightAtk)
			{
				if (pKeyboard->GetKeyboardTrigger(DIK_SPACE) || pGamePad->GetJoypadTrigger(cnt, CPad::JOYPADKEY_B))
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
		case MOTIONTYPE_SP_N:
			nCountATK++;
			if (nCountATK == 20)
			{
				if (m_fDiffrot.y == D3DX_PI*0.5f)
				{
					if (cnt == 0)
					{
						CBullet::Create(GetPos(), D3DXVECTOR3(-10, 0.0f, 0.0f), CBullet::BULLETTEX_KEN, CMaker::MAKERTYPE_1P, 50);
					}
					if (cnt == 1)
					{
						CBullet::Create(GetPos(), D3DXVECTOR3(-10, 0.0f, 0.0f), CBullet::BULLETTEX_KEN, CMaker::MAKERTYPE_2P, 50);
					}
				}
				else
				{
					if (cnt == 0)
					{
						CBullet::Create(GetPos(), D3DXVECTOR3(10, 0.0f, 0.0f), CBullet::BULLETTEX_KEN, CMaker::MAKERTYPE_1P, 50);
					}
					if (cnt == 1)
					{
						CBullet::Create(GetPos(), D3DXVECTOR3(10, 0.0f, 0.0f), CBullet::BULLETTEX_KEN, CMaker::MAKERTYPE_2P, 50);
					}
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
			if (pKeyboard->GetKeyboardPress(DIK_D) || pGamePad->GetJoypadPress(cnt, CPad::JOYPADKEY_RIGHT))
			{
				m_move.x += D3DX_PI*0.5f* m_fAirAtkSpeed;
			}
			else if (pKeyboard->GetKeyboardPress(DIK_A) || pGamePad->GetJoypadPress(cnt, CPad::JOYPADKEY_LEFT))
			{
				m_move.x += D3DX_PI*-0.5f* m_fAirAtkSpeed;
			}
			if (pKeyboard->GetKeyboardPress(DIK_S) || pGamePad->GetJoypadPress(cnt, CPad::JOYPADKEY_DOWN))
			{
				m_move.y -= 1.2f;
			}
			break;
		case MOTIONTYPE_GAUDE:
			if (pKeyboard->GetKeyboardPress(DIK_G) || pGamePad->GetJoypadPress(cnt, CPad::JOYPADKEY_X))
			{
				m_PlayerState = PLAYERSTATE_GAUDE;
			}
			else
			{
				MotionChangePlayer(MOTIONTYPE_WAIT);
			}
		}


		break;

	case PLAYERTYPE::PLAYERTYPE_SWORD:

		switch (m_MotionType)
		{
		case MOTIONTYPE_LIGHT0:
			nCountATK++;
			if (nCountATK >= m_fLightAtk)
			{
				if (pKeyboard->GetKeyboardTrigger(DIK_L) || pGamePad->GetJoypadTrigger(cnt, CPad::JOYPADKEY_B))
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
					m_move.x -= 1.5f;
				}
				else
				{
					m_move.x += 1.5f;
				}
			}
			if (nCountATK >= m_fLightAtk)
			{
				if (pKeyboard->GetKeyboardTrigger(DIK_L) || pGamePad->GetJoypadTrigger(cnt, CPad::JOYPADKEY_B))
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
					m_move.x -= 2.5f;
				}
				else
				{
					m_move.x += 2.5f;
				}
			}

			break;
		case MOTIONTYPE_DASHATK:
			nCountATK++;
			if (nCountATK >= 1 && nCountATK <= 40)
			{
				if (m_fDiffrot.y == D3DX_PI*0.5f)
				{
					m_move.x -= 0.9f;
				}
				else
				{
					m_move.x += 0.9f;
				}
			}
			break;

		case MOTIONTYPE_SP_N:
			nCountATK++;
			if (nCountATK >= 4 && nCountATK <= 23)
			{
				if (m_fDiffrot.y == D3DX_PI*0.5f)
				{
					m_move.x -= 3.5f;
				}
				else
				{
					m_move.x += 3.5f;
				}
			}
			break;
		case MOTIONTYPE_AIR_N:
		case MOTIONTYPE_AIR_F:
		case MOTIONTYPE_AIR_B:
		case MOTIONTYPE_AIR_U:
		case MOTIONTYPE_AIR_D:
			if (pGamePad->GetJoypadPress(cnt, CPad::JOYPADKEY_RIGHT))
			{
				m_move.x += D3DX_PI*0.5f* m_fAirAtkSpeed;
			}
			else if (pGamePad->GetJoypadPress(cnt, CPad::JOYPADKEY_LEFT))
			{
				m_move.x += D3DX_PI*-0.5f* m_fAirAtkSpeed;
			}
			if (pGamePad->GetJoypadPress(cnt, CPad::JOYPADKEY_DOWN))
			{
				m_move.y -= 1.2f;
			}
			break;
		case MOTIONTYPE_GAUDE:
			if (pGamePad->GetJoypadPress(cnt, CPad::JOYPADKEY_X))
			{
				m_PlayerState = PLAYERSTATE_GAUDE;
			}
			else
			{
				MotionChangePlayer(MOTIONTYPE_WAIT);
			}
			break;
		}

		break;

	case PLAYERTYPE::PLAYERTYPE_KANGAROO:
		switch (m_MotionType)
		{
		case MOTIONTYPE_LIGHT0:
			nCountATK++;
			if (nCountATK >= m_fLightAtk)
			{
				if (pKeyboard->GetKeyboardTrigger(DIK_SPACE) || pGamePad->GetJoypadTrigger(cnt, CPad::JOYPADKEY_B))
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
			if (nCountATK >= 1 && nCountATK <= 24)
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
		case MOTIONTYPE_CROUCHATK:
			nCountATK++;
			if (nCountATK >= 4 && nCountATK <= 8)
			{
				if (m_fDiffrot.y == D3DX_PI*0.5f)
				{
					m_move.x -= 3.5f;
				}
				else
				{
					m_move.x += 3.5f;
				}
			}
			break;
		case MOTIONTYPE_SP_N:
			nCountATK++;
			if (nCountATK >= 15 && nCountATK <= 38)
			{
				if (m_fDiffrot.y == D3DX_PI*0.5f)
				{
					m_move.x -= 3.5f;
				}
				else
				{
					m_move.x += 3.5f;
				}
			}
			break;
		case MOTIONTYPE_SP_UP:
			nCountATK++;
			if (nCountATK >= 4 && nCountATK <= 23)
			{
				if (m_fDiffrot.y == D3DX_PI*0.5f)
				{
					m_move.x -= 3.5f;
				}
				else
				{
					m_move.x += 3.5f;
				}
			}
			break;
		case MOTIONTYPE_SP_DOWN:
			nCountATK++;
			if (nCountATK == 20)
			{
					if (cnt == 0)
					{
						CBullet::Create(GetPos(), D3DXVECTOR3(-10, 0.0f, 0.0f), CBullet::BULLETTEX_KEN, CMaker::MAKERTYPE_1P, 10);
						CBullet::Create(GetPos(), D3DXVECTOR3(10, 0.0f, 0.0f), CBullet::BULLETTEX_KEN, CMaker::MAKERTYPE_1P, 10);
					}
					if (cnt == 1)
					{
						CBullet::Create(GetPos(), D3DXVECTOR3(-10, 0.0f, 0.0f), CBullet::BULLETTEX_KEN, CMaker::MAKERTYPE_2P, 10);
						CBullet::Create(GetPos(), D3DXVECTOR3(10, 0.0f, 0.0f), CBullet::BULLETTEX_KEN, CMaker::MAKERTYPE_2P, 10);

					}

			}

		case MOTIONTYPE_AIR_N:
		case MOTIONTYPE_AIR_F:
		case MOTIONTYPE_AIR_B:
		case MOTIONTYPE_AIR_U:
		case MOTIONTYPE_AIR_D:
			if (pGamePad->GetJoypadPress(cnt, CPad::JOYPADKEY_RIGHT))
			{
				m_move.x += D3DX_PI*0.5f* m_fAirAtkSpeed;
			}
			else if (pGamePad->GetJoypadPress(cnt, CPad::JOYPADKEY_LEFT))
			{
				m_move.x += D3DX_PI*-0.5f* m_fAirAtkSpeed;
			}
			if (pGamePad->GetJoypadPress(cnt, CPad::JOYPADKEY_DOWN))
			{
				m_move.y -= 1.2f;
			}
			break;
		case MOTIONTYPE_GAUDE:
			if (pGamePad->GetJoypadPress(cnt, CPad::JOYPADKEY_X))
			{
				m_PlayerState = PLAYERSTATE_GAUDE;
			}
			else
			{
				MotionChangePlayer(MOTIONTYPE_WAIT);
			}
		}

		break;
	}
}

