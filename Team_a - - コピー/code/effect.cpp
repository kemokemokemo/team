//=============================================================================
//
// �G�t�F�N�g�̏��� [effect.cpp]
// Author : KIMURA KOUTA
//
//=============================================================================
#include "effect.h"
#include "manager.h"
#include "renderer.h"

//=============================================================================
// �O���[�o���ϐ�
//=============================================================================
LPDIRECT3DTEXTURE9 CEffect::m_pTextureEffect[MAX_EFFECTTEX] = {};

//=============================================================================
// �}�N����`
//=============================================================================
#define	EFFECT_01			"DATA/TEX/HitEffect.png"		// �ǂݍ��ރe�N�X�`���t�@�C����
#define	EFFECT_02			"DATA/TEX/Explosion.png"		// �ǂݍ��ރe�N�X�`���t�@�C����
#define EFFECT_SIZE (50)

//=============================================================================
// �R���X�g���N�^
//=============================================================================
CEffect::CEffect(OBJTYPE type) : CBillboard(type)
{

}

//=============================================================================
// ����������
//=============================================================================
HRESULT CEffect::Init(D3DXVECTOR3 pos, D3DXVECTOR3 move, int nLife, EFFECTTYPE effectType)
{
	m_move = D3DXVECTOR3(0.0f,0.0f,0.0f);

	CBillboard::SetPos(pos);

	m_move = move;
	m_nLife = nLife;
	EffectType = effectType;

	CBillboard::SetColor(D3DXCOLOR(1.0f, 1.0f, 1.0f, 0.5f));
	CBillboard::Init();
	return S_OK;
}

//=============================================================================
// �I������
//=============================================================================
void CEffect::Uninit(void)
{
	if (m_pVtxBuffEffect != NULL)
	{// ���_�o�b�t�@�̊J��
		m_pVtxBuffEffect->Release();
		m_pVtxBuffEffect = NULL;
	}

	CBillboard::Uninit();
}

//=============================================================================
// �X�V����
//=============================================================================
void CEffect::Update(void)
{
	D3DXVECTOR3 pos = CBillboard::GetPos();

	switch (EffectType)
	{
	case EFFECTTYPE_DAMAGE:
		CBillboard::SetSize(40.0f, 40.0f, 0.0f);

		break;

	case EFFECTTYPE_EXPLOSION:
		CBillboard::SetSize(400.0f, 400.0f, 0.0f);

		CBillboard::SetAnim(4, 1, 3);

		break;
	}


	pos += m_move;
	CBillboard::SetPos(pos);

	m_nLife--;

	CBillboard::Update();

	if (m_nLife <= 0)
	{
		this->Release();
	}
}

//=============================================================================
// �`�揈��
//=============================================================================
void CEffect::Draw(void)
{
	CRenderer *pRenderer = CManager::GetRenderer();
	LPDIRECT3DDEVICE9 pDevice = pRenderer->GetDevice();

	// �����_�[�X�e�[�g(���Z��������)
	pDevice->SetRenderState(D3DRS_BLENDOP, D3DBLENDOP_ADD);
	pDevice->SetRenderState(D3DRS_SRCBLEND, D3DBLEND_SRCALPHA);
	pDevice->SetRenderState(D3DRS_DESTBLEND, D3DBLEND_ONE);

	CBillboard::Draw();

	// �����_�[�X�e�[�g(�ʏ�u�����h����)
	pDevice->SetRenderState(D3DRS_BLENDOP, D3DBLENDOP_ADD);
	pDevice->SetRenderState(D3DRS_SRCBLEND, D3DBLEND_SRCALPHA);
	pDevice->SetRenderState(D3DRS_DESTBLEND, D3DBLEND_INVSRCALPHA);
}

//=============================================================================
// �G�t�F�N�g�̍쐬
//=============================================================================
CEffect * CEffect::Create(D3DXVECTOR3 pos, D3DXVECTOR3 move, int nLife,EFFECTTYPE effectType)
{
	CEffect *pEffect = new CEffect(OBJTYPE_EFFECT);
	pEffect->BindTexture(m_pTextureEffect[effectType]);
	pEffect->Init(pos, move, nLife, effectType);
	return pEffect;
}

//=============================================================================
// �e�N�X�`���̓ǂݍ���
//=============================================================================
HRESULT CEffect::Load(void)
{
	CRenderer *pRenderer = CManager::GetRenderer();
	LPDIRECT3DDEVICE9 pDevice = pRenderer->GetDevice();

	// �e�N�X�`���̓ǂݍ���
	D3DXCreateTextureFromFile(pDevice,				// �f�o�C�X�ւ̃|�C���^
		EFFECT_01,		// �t�@�C���̖��O
		&m_pTextureEffect[EFFECTTYPE_DAMAGE]);	// �ǂݍ��ރ������[
												// �e�N�X�`���̓ǂݍ���
	D3DXCreateTextureFromFile(pDevice,				// �f�o�C�X�ւ̃|�C���^
		EFFECT_02,		// �t�@�C���̖��O
		&m_pTextureEffect[EFFECTTYPE_EXPLOSION]);	// �ǂݍ��ރ������[

	return S_OK;
}

//=============================================================================
// �e�N�X�`���̔j��
//=============================================================================
void CEffect::Unload(void)
{
	// �e�N�X�`���̊J��
	for (int nCntEffect = 0; nCntEffect < MAX_EFFECTTEX; nCntEffect++)
	{
		if (m_pTextureEffect[nCntEffect] != NULL)
		{
			m_pTextureEffect[nCntEffect]->Release();
			m_pTextureEffect[nCntEffect] = NULL;
		}
	}
}

//=============================================================================
// �p�[�e�N��
//=============================================================================
void CEffect::SetParticle(D3DXVECTOR3 pos, D3DXVECTOR3 move, int nLife, EFFECTTYPE effectType)
{

	CEffect::Create(D3DXVECTOR3(pos.x , pos.y, pos.z ), move, nLife, effectType);
	
}

//=============================================================================
// �f�X�g���N�^
//=============================================================================
CEffect::~CEffect()
{

}
