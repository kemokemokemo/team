//====================================================================================================
//
// �e�N�X�`���\������ (Texture.cpp)
// Author (Kimura kouta)
//
//====================================================================================================
#include "Texture.h"
#include "renderer.h"
#include "manager.h"
#include "Game.h"
#include "player_Ken.h"
#include "keybord.h"

//====================================================================================================
// �}�N����`
//====================================================================================================
#define TEXTURE_SIZE (40)
#define MAX_LIFE (40)
#define TEX_01 "DATA/TEX/selected_1p.png"					//�ǂݍ��ރe�N�X�`���t�@�C����
#define TEX_02 "DATA/TEX/life_gauge_1p.png"					//�ǂݍ��ރe�N�X�`���t�@�C����
#define TEX_03 "DATA/TEX/arrow_3p.png"					//�ǂݍ��ރe�N�X�`���t�@�C����
#define TEX_04 "DATA/TEX/arrow_4p.png"					//�ǂݍ��ރe�N�X�`���t�@�C����

#define TEX_05 "DATA/TEX/ken_icon.png"					//�ǂݍ��ރe�N�X�`���t�@�C����
#define TEX_06 "DATA/TEX/kangaroo_icon.png"					//�ǂݍ��ރe�N�X�`���t�@�C����
#define TEX_07 "DATA/TEX/sword_icon.png"					//�ǂݍ��ރe�N�X�`���t�@�C����

#define TEX_08 "DATA/TEX/chara_ken.png"					//�ǂݍ��ރe�N�X�`���t�@�C����
#define TEX_09 "DATA/TEX/chara_kangaroo.png"					//�ǂݍ��ރe�N�X�`���t�@�C����
#define TEX_010 "DATA/TEX/chara_sword.png"					//�ǂݍ��ރe�N�X�`���t�@�C����

#define TEX_011 "DATA/TEX/TitleBG.jpg"					//�ǂݍ��ރe�N�X�`���t�@�C����
#define TEX_012 "DATA/TEX/TitleLogo.png"					//�ǂݍ��ރe�N�X�`���t�@�C����

//====================================================================================================
// �v���g�^�C�v�錾
//====================================================================================================

//====================================================================================================
// �O���[�o���ϐ�
//====================================================================================================
LPDIRECT3DTEXTURE9 CTexture::m_pTextureIcon[TYPE_MAX] = {};



//====================================================================================================
// �R���X�g���N�^
//====================================================================================================
CTexture::CTexture(OBJTYPE type) : CScene2D(type)
{
}
//=============================================================================
// ����������
//=============================================================================
HRESULT CTexture::Init(TEXTURE_TYPE type)
{
	CScene2D::Init();

	TexType = type;
	return S_OK;
}

//==================================================================================================
//�I������
//===================================================================================================
void CTexture::Uninit(void)
{
	CScene2D::Uninit();
}

//====================================================================================================
//�X�V����
//=====================================================================================================
void CTexture::Update(void)
{
	if (TexType == TYPE_TITLEBG)
	{
		SetAnim(0.1f, 0.0f, 0.5f, 10);
	}
}
//========================================================================================================
// �`�揈��
//========================================================================================================
CTexture *CTexture::Create(D3DXVECTOR3 pos, D3DXVECTOR3 move, D3DXCOLOR col, float Weight, float Height,TEXTURE_TYPE type)
{
	CTexture *pTex;

	pTex = new CTexture(OBJTYPE_LIFE);

	pTex->SetPos(pos);
	pTex->SetColor(col);
	pTex->SetSize(Weight,Height);
	pTex->BindTexture(m_pTextureIcon[type]);
	pTex->Init(type);

	return pTex;
}

//========================================================================================================
// �e�N�X�`���̓ǂݍ���
//========================================================================================================
HRESULT CTexture::Load(void)
{
	CRenderer *pRenderer = CManager::GetRenderer();
	LPDIRECT3DDEVICE9 pDevice = pRenderer->GetDevice();

	//�e�N�X�`���̓ǂݍ���
	D3DXCreateTextureFromFile(
		pDevice,
		TEX_01,
		&m_pTextureIcon[TYPE_BG]);

	//�e�N�X�`���̓ǂݍ���
	D3DXCreateTextureFromFile(
		pDevice,
		TEX_02,
		&m_pTextureIcon[TYPE_LOGO]);

	//�e�N�X�`���̓ǂݍ���
	D3DXCreateTextureFromFile(
		pDevice,
		TEX_03,
		&m_pTextureIcon[TYPE_ENTER]);

	//�e�N�X�`���̓ǂݍ���
	D3DXCreateTextureFromFile(
		pDevice,
		"DATA/TEX/select_BG.jpg",
		&m_pTextureIcon[TYPE_SELECT_BG]);

	//�e�N�X�`���̓ǂݍ���
	D3DXCreateTextureFromFile(
		pDevice,
		"DATA/TEX/selected_1p.png",
		&m_pTextureIcon[TYPE_SELECT1]);

	//�e�N�X�`���̓ǂݍ���
	D3DXCreateTextureFromFile(
		pDevice,
		"DATA/TEX/selected_2p.png",
		&m_pTextureIcon[TYPE_SELECT2]);

	//�e�N�X�`���̓ǂݍ���
	D3DXCreateTextureFromFile(
		pDevice,
		"DATA/TEX/life_gauge_1p.png",
		&m_pTextureIcon[TYPE_LIFE1]);

	//�e�N�X�`���̓ǂݍ���
	D3DXCreateTextureFromFile(
		pDevice,
		"DATA/TEX/life_gauge_2p.png",
		&m_pTextureIcon[TYPE_LIFE2]);

	//�e�N�X�`���̓ǂݍ���
	D3DXCreateTextureFromFile(
		pDevice,
		TEX_05,
		&m_pTextureIcon[TYPE_KENICON]);

	//�e�N�X�`���̓ǂݍ���
	D3DXCreateTextureFromFile(
		pDevice,
		TEX_06,
		&m_pTextureIcon[TYPE_KANGAROOICON]);

	//�e�N�X�`���̓ǂݍ���
	D3DXCreateTextureFromFile(
		pDevice,
		TEX_07,
		&m_pTextureIcon[TYPE_SWORDICON]);

	//�e�N�X�`���̓ǂݍ���
	D3DXCreateTextureFromFile(
		pDevice,
		TEX_08,
		&m_pTextureIcon[TYPE_SELECTKENICON]);

	//�e�N�X�`���̓ǂݍ���
	D3DXCreateTextureFromFile(
		pDevice,
		TEX_09,
		&m_pTextureIcon[TYPE_SELECTKANGAROOICON]);

	//�e�N�X�`���̓ǂݍ���
	D3DXCreateTextureFromFile(
		pDevice,
		TEX_010,
		&m_pTextureIcon[TYPE_SELECTSWORDICON]);

	//�e�N�X�`���̓ǂݍ���
	D3DXCreateTextureFromFile(
		pDevice,
		TEX_011,
		&m_pTextureIcon[TYPE_TITLEBG]);

	//�e�N�X�`���̓ǂݍ���
	D3DXCreateTextureFromFile(
		pDevice,
		TEX_012,
		&m_pTextureIcon[TYPE_TITLELOG]);

	return S_OK;
}
//=======================================================================================================
// �e�N�X�`���̔j��
//========================================================================================================
void CTexture::Unload(void)
{
	for (int nCnt =0; nCnt < TYPE_MAX; nCnt++)
	{
		// ���_�o�b�t�@�̊J��
		if (m_pTextureIcon[nCnt] != NULL)
		{
			m_pTextureIcon[nCnt]->Release();
			m_pTextureIcon[nCnt] = NULL;
		}
	}
}

//========================================================================================================
// �`�揈��
//========================================================================================================
void CTexture::Draw(void)
{
	CScene2D::Draw();
}

//====================================================================================================
// �f�X�g���N�^
//=====================================================================================================
CTexture::~CTexture()
{

}