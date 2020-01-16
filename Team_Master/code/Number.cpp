//=============================================================================
//
// �������� [number.cpp]
// Author : KIMURA KOUTA
//
//=============================================================================
#include "Number.h"
#include "renderer.h"
#include "manager.h"

//=============================================================================
// �}�N����`
//=============================================================================
#define	TEXTURE_SCORE		"DATA/TEX/number000.png"	// �ǂݍ��ރe�N�X�`���t�@�C����
#define MAX_SCORE   (8)
#define SCORE_POS_X	(0)			    //�|���S���̕\���ʒu(����X)
#define SCORE_POS_Y	(0)			    //�|���S���̕\���ʒu(����Y)
#define SCORE_SIZE_X	(30)			//�|���S���̃T�C�Y(����)
#define SCORE_SIZE_Y	(40)			//�|���S���̃T�C�Y(����)
#define SCORECOLOR_TEX   (255)

//=============================================================================
// �v���g�^�C�v�錾
//=============================================================================

//=============================================================================
// �O���錾�̏�����
//=============================================================================
LPDIRECT3DTEXTURE9 CNumber::m_pTextureNumber = NULL;

//=============================================================================
// �R���X�g���N�^
//=============================================================================
CNumber::CNumber()
{
	m_pos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	m_Size_X = 0;
	m_Size_Y = 0;
	m_nNumber = 0;
}

//=============================================================================
// ����������
//=============================================================================
HRESULT CNumber::Init()
{
	CRenderer *pRenderer = CManager::GetRenderer();
	LPDIRECT3DDEVICE9 pDevice = pRenderer->GetDevice();

	VERTEX_2D *pVtx;

	// �I�u�W�F�N�g�̒��_�o�b�t�@�𐶐�
	pDevice->CreateVertexBuffer(sizeof(VERTEX_2D) * 4 * MAX_SCORE,
		D3DUSAGE_WRITEONLY,
		FVF_VERTEX_2D,
		D3DPOOL_MANAGED,
		&m_pVtxBuffNumber,
		NULL);

	// ���_���̐ݒ�
	m_pVtxBuffNumber->Lock(0, 0, (void**)&pVtx, 0);

	//���_���W�̐ݒ�(�E���Őݒ肷��j
	pVtx[0].pos = m_pos + D3DXVECTOR3(-m_Size_X, -m_Size_Y, 0.0f);
	pVtx[1].pos = m_pos + D3DXVECTOR3(m_Size_X, -m_Size_Y, 0.0f);
	pVtx[2].pos = m_pos + D3DXVECTOR3(-m_Size_X, m_Size_Y, 0.0f);
	pVtx[3].pos = m_pos + D3DXVECTOR3(m_Size_X, m_Size_Y, 0.0f);

	//rhw�̐ݒ�i�l��1.0�ŌŒ�j�F2D�Ƃ��ē������̂ɕK�v�Ȃ���
	pVtx[0].rhw = 1.0f;
	pVtx[1].rhw = 1.0f;
	pVtx[2].rhw = 1.0f;
	pVtx[3].rhw = 1.0f;

	//���_�J���[�̐ݒ�(0�`255�̒l�Őݒ�j
	pVtx[0].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
	pVtx[1].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
	pVtx[2].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
	pVtx[3].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);

	pVtx[0].tex = D3DXVECTOR2(0.1f * m_nNumber, 0.0f);
	pVtx[1].tex = D3DXVECTOR2(0.1f * m_nNumber + 0.1f, 0.0f);
	pVtx[2].tex = D3DXVECTOR2(0.1f * m_nNumber, 1.0f);
	pVtx[3].tex = D3DXVECTOR2(0.1f * m_nNumber + 0.1f, 1.0f);

	// ���_�f�[�^���A�����b�N����
	m_pVtxBuffNumber->Unlock();

	return S_OK;
}

//=============================================================================
// �I������
//=============================================================================
void CNumber::Uninit(void)
{
	// �e�N�X�`���̊J��
	if (m_pVtxBuffNumber != NULL)
	{
		m_pVtxBuffNumber->Release();
		m_pVtxBuffNumber = NULL;
	}
}

//=============================================================================
// �X�V����
//=============================================================================
void CNumber::Update(void)
{
}

//=============================================================================
// �`�揈��
//=============================================================================
void CNumber::Draw(void)
{
	CRenderer *pRenderer = CManager::GetRenderer();
	LPDIRECT3DDEVICE9 pDevice = pRenderer->GetDevice();

	// ���_�o�b�t�@���f�o�C�X�̃f�[�^�X�g���[���Ƀo�C���h
	pDevice->SetStreamSource(0, m_pVtxBuffNumber, 0, sizeof(VERTEX_2D));

	// ���_�t�H�[�}�b�g�̐ݒ�
	pDevice->SetFVF(FVF_VERTEX_2D);

	// �e�N�X�`���̐ݒ�
	pDevice->SetTexture(0, m_pTextureNumber);

	pDevice->DrawPrimitive(D3DPT_TRIANGLESTRIP, 0, 2);
}

//=============================================================================
// �X�R�A�̕ύX
//=============================================================================
CNumber * CNumber::Create(D3DXVECTOR3 pos, float size_x, float size_y, int nNumber)
{
	CNumber *pNumber;

	pNumber = new CNumber();

	pNumber->SetNumber(nNumber);

	pNumber->SetPosition(pos);

	pNumber->SetSize(size_x, size_y);

	pNumber->Init();

	return pNumber;
}

//=============================================================================
// �X�R�A�̕ύX
//=============================================================================
HRESULT CNumber::Load(void)
{
	CRenderer *pRenderer = CManager::GetRenderer();
	LPDIRECT3DDEVICE9 pDevice = pRenderer->GetDevice();

	// �e�N�X�`���̓ǂݍ���
	D3DXCreateTextureFromFile(pDevice,				// �f�o�C�X�ւ̃|�C���^
		TEXTURE_SCORE,		// �t�@�C���̖��O
		&m_pTextureNumber);	// �ǂݍ��ރ������[

	return S_OK;
}

//=============================================================================
// �X�R�A�̕ύX
//=============================================================================
void CNumber::Unload(void)
{
	// ���_�o�b�t�@�̊J��
	if (m_pTextureNumber != NULL)
	{
		m_pTextureNumber->Release();
		m_pTextureNumber = NULL;
	}
}

//=============================================================================
// �����̃Z�b�g
//=============================================================================
void CNumber::SetNumber(int nNumber)
{
	m_nNumber = nNumber;
}

//=============================================================================
// �|�W�V�����̃Z�b�g
//=============================================================================
void CNumber::SetPosition(D3DXVECTOR3 pos)
{
	m_pos = pos;
}

//=============================================================================
// �T�C�Y�̃Z�b�g
//=============================================================================
void CNumber::SetSize(float size_x, float size_y)
{
	m_Size_X = size_x;
	m_Size_Y = size_y;
}

//=============================================================================
// �e�N�X�`���̃Z�b�g
//=============================================================================
void CNumber::SetTex(int nDigits)
{
	VERTEX_2D *pVtx;

	// ���_���̐ݒ�
	m_pVtxBuffNumber->Lock(0, 0, (void**)&pVtx, 0);

	pVtx[0].tex = D3DXVECTOR2(0.1f * nDigits, 0.0f);
	pVtx[1].tex = D3DXVECTOR2(0.1f * nDigits + 0.1f, 0.0f);
	pVtx[2].tex = D3DXVECTOR2(0.1f * nDigits, 1.0f);
	pVtx[3].tex = D3DXVECTOR2(0.1f * nDigits + 0.1f, 1.0f);

	// ���_�f�[�^���A�����b�N����
	m_pVtxBuffNumber->Unlock();
}

//=============================================================================
// �f�X�g���N�^
//=============================================================================
CNumber::~CNumber()
{
}