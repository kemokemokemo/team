//=============================================================================
//
// �������ԏ��� [time.cpp]
// Author : KIMURA KOUTA
//
//=============================================================================
#include "time.h"
#include "renderer.h"
#include "manager.h"

//=============================================================================
// �}�N����`
//=============================================================================
#define	TEXTURE_SCORE		"DATA/TEX/number000.png"	// �ǂݍ��ރe�N�X�`���t�@�C����
#define SCORE_POS_X	(0)			    //�|���S���̕\���ʒu(����X)
#define SCORE_POS_Y	(0)			    //�|���S���̕\���ʒu(����Y)
#define SCORE_SIZE_X	(20)			//�|���S���̃T�C�Y(����)
#define SCORE_SIZE_Y	(30)			//�|���S���̃T�C�Y(����)
#define SCORECOLOR_TEX   (255)
#define MAX_TIMER   (300)

//=============================================================================
// �O���錾�̏�����
//=============================================================================

//=============================================================================
// �R���X�g���N�^
//=============================================================================
CTime::CTime(OBJTYPE nPriority) : CScene(nPriority)
{
	m_nTime = 0;
	m_nCntTime = 0;
	m_TimerState = 0;
}

//=============================================================================
// ����������
//=============================================================================
HRESULT CTime::Init(void)
{
	int nScore = CTime::GetTime();

	D3DXVECTOR3 pos;

	for (int nCntScore = 0; nCntScore < MAX_TIME; nCntScore++)
	{
		pos = D3DXVECTOR3(600.0f + (SCORE_SIZE_X +15.0f)*nCntScore, 10.0f + SCORE_SIZE_Y, 0.0f);

		int nDigits = nScore % (int)powf(10.0f,(float)MAX_TIME - nCntScore) / (int)powf(10.0f, (float)MAX_TIME - 1.0f - nCntScore);

		m_apTime[nCntScore] = CNumber::Create(pos, SCORE_SIZE_X, SCORE_SIZE_Y, nDigits);
	}

	return S_OK;
}

//=============================================================================
// �I������
//=============================================================================
void CTime::Uninit(void)
{
	for (int nCntScore = 0; nCntScore < MAX_TIME; nCntScore++)
	{
		m_apTime[nCntScore]->Uninit();
	}
}

//=============================================================================
// �X�V����
//=============================================================================
void CTime::Update(void)
{
	for (int nCntScore = 0; nCntScore < MAX_TIME; nCntScore++)
	{
		m_apTime[nCntScore]->Update();
	}

	if (m_TimerState < MAX_TIMER)
	{
		m_nCntTime++;
	}
	if (m_nCntTime >= 60)
	{
		AddTime(-1);
		m_nCntTime = 0;
		m_TimerState++;
	}
}

//=============================================================================
// �`�揈��
//=============================================================================
void CTime::Draw(void)
{
	for (int nCntScore = 0; nCntScore < MAX_TIME; nCntScore++)
	{
		m_apTime[nCntScore]->Draw();
	}
}

//=============================================================================
// �X�R�A�̕ύX
//=============================================================================
CTime * CTime::Create(int nScore)
{
	
	CTime *pNumber;

	pNumber = new CTime(OBJTYPE_SCORE);

	pNumber->SetTime(nScore);

	pNumber->Init();

	return pNumber;
}

//=============================================================================
// �X�R�A�̎擾
//=============================================================================
int CTime::GetTime()
{
	return m_nTime;
}

//=============================================================================
// �X�R�A�̉��Z
//=============================================================================
void CTime::AddTime(int nNumber)
{
	m_nTime += nNumber;

	if (m_nTime > 300)
	{
		m_nTime = 300;
	}
	if (m_nTime < 0)
	{
		m_nTime = 0;
	}

	for (int nCntTime = 0; nCntTime < MAX_TIME; nCntTime++)
	{
		int nTime = m_nTime / (int)powf(10.0f, MAX_TIME - nCntTime - 1.0f * 1.0f) % 10;

		m_apTime[nCntTime]->SetTex(nTime);
	}
}

//=============================================================================
// �X�R�A�̃Z�b�g
//=============================================================================
void CTime::SetTime(int nScore)
{
	m_nTime = nScore;
}

//=============================================================================
// �f�X�g���N�^
//=============================================================================
CTime::~CTime()
{

}