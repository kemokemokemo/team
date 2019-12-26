//====================================================================================================
//
// �}�[�J�[���� (maker.cpp)
// Author (Kimura kouta)
//
//====================================================================================================
#include "SelectIcon.h"
#include "renderer.h"
#include "manager.h"
#include "Game.h"
#include "player_Ken.h"
#include "keybord.h"

//====================================================================================================
// �}�N����`
//====================================================================================================
#define BULLET_SIZE (40)
#define MAX_LIFE (40)
#define MAKERTEX_01 "DATA/TEX/arrow_1p.png"					//�ǂݍ��ރe�N�X�`���t�@�C����
#define MAKERTEX_02 "DATA/TEX/arrow_2p.png"					//�ǂݍ��ރe�N�X�`���t�@�C����
#define MAKERTEX_03 "DATA/TEX/arrow_3p.png"					//�ǂݍ��ރe�N�X�`���t�@�C����
#define MAKERTEX_04 "DATA/TEX/arrow_4p.png"					//�ǂݍ��ރe�N�X�`���t�@�C����

//====================================================================================================
// �v���g�^�C�v�錾
//====================================================================================================

//====================================================================================================
// �O���[�o���ϐ�
//====================================================================================================
LPDIRECT3DTEXTURE9 CSelectIcon::m_pTextureIcon[ICON_MAX] = {};



//====================================================================================================
// �R���X�g���N�^
//====================================================================================================
CSelectIcon::CSelectIcon(OBJTYPE type) : CBillboard(type)
{
}
//=============================================================================
// ����������
//=============================================================================
HRESULT CSelectIcon::Init(D3DXVECTOR3 pos, ICON Icon)
{

	SetPos(pos);
	SetSize(100.0f, 100.0f, 0.0f);
	SetColor(D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f));

	m_move = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	m_Icon[Icon] = Icon;

	CBillboard::Init();

	return S_OK;
}

//==================================================================================================
//�I������
//===================================================================================================
void CSelectIcon::Uninit(void)
{
	CBillboard::Uninit();
}

//====================================================================================================
//�X�V����
//=====================================================================================================
void CSelectIcon::Update(void)
{
	CKeybord *pKeyboard = CManager::GetKeybord();

	D3DXVECTOR3 pos = CBillboard::GetPos();

	if (m_Icon[1])
	{
		if (pKeyboard->GetKeyboardPress(DIK_W))
		{// W �L�[����
			m_move.y += 10.0f;
		}
		else if (pKeyboard->GetKeyboardPress(DIK_S))
		{// W �L�[����
			m_move.y -= 10.0f;
		}
		else if (pKeyboard->GetKeyboardPress(DIK_A))
		{// W �L�[����
			m_move.x -= 10.0f;
		}
		else if (pKeyboard->GetKeyboardPress(DIK_D))
		{// W �L�[����
			m_move.x += 10.0f;
		}
	}
	if (m_Icon[2])
	{
		if (pKeyboard->GetKeyboardPress(DIK_T))
		{// W �L�[����
			m_move.y += 10.0f;
		}
		else if (pKeyboard->GetKeyboardPress(DIK_G))
		{// W �L�[����
			m_move.y -= 10.0f;
		}
		else if (pKeyboard->GetKeyboardPress(DIK_F))
		{// W �L�[����
			m_move.x -= 10.0f;
		}
		else if (pKeyboard->GetKeyboardPress(DIK_H))
		{// W �L�[����
			m_move.x += 10.0f;
		}
	}
	if (m_Icon[3])
	{
		if (pKeyboard->GetKeyboardPress(DIK_I))
		{// W �L�[����
			m_move.y += 10.0f;
		}
		else if (pKeyboard->GetKeyboardPress(DIK_K))
		{// W �L�[����
			m_move.y -= 10.0f;
		}
		else if (pKeyboard->GetKeyboardPress(DIK_J))
		{// W �L�[����
			m_move.x -= 10.0f;
		}
		else if (pKeyboard->GetKeyboardPress(DIK_L))
		{// W �L�[����
			m_move.x += 10.0f;
		}
	}


	pos += m_move;

	//��������
	m_move.x += (0 - m_move.x) * 1 / 4;
	m_move.y += (0 - m_move.y) * 1 / 4;

	CBillboard::SetPos(pos);

	CBillboard::Update();
}
//========================================================================================================
// �`�揈��
//========================================================================================================
CSelectIcon *CSelectIcon::Create(D3DXVECTOR3 pos, ICON Icon)
{
	CSelectIcon *pMaker;

	pMaker = new CSelectIcon(OBJTYPE_ANIMATION);

	pMaker->BindTexture(m_pTextureIcon[Icon]);

	pMaker->Init(pos, Icon);

	return pMaker;
}

//========================================================================================================
// �e�N�X�`���̓ǂݍ���
//========================================================================================================
HRESULT CSelectIcon::Load(void)
{
	CRenderer *pRenderer = CManager::GetRenderer();
	LPDIRECT3DDEVICE9 pDevice = pRenderer->GetDevice();

	//�e�N�X�`���̓ǂݍ���
	D3DXCreateTextureFromFile(
		pDevice,
		MAKERTEX_01,
		&m_pTextureIcon[ICON_1P]);

	//�e�N�X�`���̓ǂݍ���
	D3DXCreateTextureFromFile(
		pDevice,
		MAKERTEX_02,
		&m_pTextureIcon[ICON_2P]);

	//�e�N�X�`���̓ǂݍ���
	D3DXCreateTextureFromFile(
		pDevice,
		MAKERTEX_03,
		&m_pTextureIcon[ICON_3P]);

	//�e�N�X�`���̓ǂݍ���
	D3DXCreateTextureFromFile(
		pDevice,
		MAKERTEX_04,
		&m_pTextureIcon[ICON_4P]);

	return S_OK;
}
//=======================================================================================================
// �e�N�X�`���̔j��
//========================================================================================================
void CSelectIcon::Unload(void)
{
	for (int nCnt =0; nCnt < ICON_MAX; nCnt++)
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
void CSelectIcon::Draw(void)
{
	CBillboard::Draw();
}

//====================================================================================================
// �f�X�g���N�^
//=====================================================================================================
CSelectIcon::~CSelectIcon()
{

}