//====================================================================================================
//
// マーカー処理 (maker.cpp)
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
// マクロ定義
//====================================================================================================
#define BULLET_SIZE (40)
#define MAX_LIFE (40)
#define MAKERTEX_01 "DATA/TEX/arrow_1p.png"					//読み込むテクスチャファイル名
#define MAKERTEX_02 "DATA/TEX/arrow_2p.png"					//読み込むテクスチャファイル名
#define MAKERTEX_03 "DATA/TEX/arrow_3p.png"					//読み込むテクスチャファイル名
#define MAKERTEX_04 "DATA/TEX/arrow_4p.png"					//読み込むテクスチャファイル名

//====================================================================================================
// プロトタイプ宣言
//====================================================================================================

//====================================================================================================
// グローバル変数
//====================================================================================================
LPDIRECT3DTEXTURE9 CSelectIcon::m_pTextureIcon[ICON_MAX] = {};



//====================================================================================================
// コンストラクタ
//====================================================================================================
CSelectIcon::CSelectIcon(OBJTYPE type) : CBillboard(type)
{
}
//=============================================================================
// 初期化処理
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
//終了処理
//===================================================================================================
void CSelectIcon::Uninit(void)
{
	CBillboard::Uninit();
}

//====================================================================================================
//更新処理
//=====================================================================================================
void CSelectIcon::Update(void)
{
	CKeybord *pKeyboard = CManager::GetKeybord();

	D3DXVECTOR3 pos = CBillboard::GetPos();

	if (m_Icon[1])
	{
		if (pKeyboard->GetKeyboardPress(DIK_W))
		{// W キー操作
			m_move.y += 10.0f;
		}
		else if (pKeyboard->GetKeyboardPress(DIK_S))
		{// W キー操作
			m_move.y -= 10.0f;
		}
		else if (pKeyboard->GetKeyboardPress(DIK_A))
		{// W キー操作
			m_move.x -= 10.0f;
		}
		else if (pKeyboard->GetKeyboardPress(DIK_D))
		{// W キー操作
			m_move.x += 10.0f;
		}
	}
	if (m_Icon[2])
	{
		if (pKeyboard->GetKeyboardPress(DIK_T))
		{// W キー操作
			m_move.y += 10.0f;
		}
		else if (pKeyboard->GetKeyboardPress(DIK_G))
		{// W キー操作
			m_move.y -= 10.0f;
		}
		else if (pKeyboard->GetKeyboardPress(DIK_F))
		{// W キー操作
			m_move.x -= 10.0f;
		}
		else if (pKeyboard->GetKeyboardPress(DIK_H))
		{// W キー操作
			m_move.x += 10.0f;
		}
	}
	if (m_Icon[3])
	{
		if (pKeyboard->GetKeyboardPress(DIK_I))
		{// W キー操作
			m_move.y += 10.0f;
		}
		else if (pKeyboard->GetKeyboardPress(DIK_K))
		{// W キー操作
			m_move.y -= 10.0f;
		}
		else if (pKeyboard->GetKeyboardPress(DIK_J))
		{// W キー操作
			m_move.x -= 10.0f;
		}
		else if (pKeyboard->GetKeyboardPress(DIK_L))
		{// W キー操作
			m_move.x += 10.0f;
		}
	}


	pos += m_move;

	//慣性処理
	m_move.x += (0 - m_move.x) * 1 / 4;
	m_move.y += (0 - m_move.y) * 1 / 4;

	CBillboard::SetPos(pos);

	CBillboard::Update();
}
//========================================================================================================
// 描画処理
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
// テクスチャの読み込み
//========================================================================================================
HRESULT CSelectIcon::Load(void)
{
	CRenderer *pRenderer = CManager::GetRenderer();
	LPDIRECT3DDEVICE9 pDevice = pRenderer->GetDevice();

	//テクスチャの読み込み
	D3DXCreateTextureFromFile(
		pDevice,
		MAKERTEX_01,
		&m_pTextureIcon[ICON_1P]);

	//テクスチャの読み込み
	D3DXCreateTextureFromFile(
		pDevice,
		MAKERTEX_02,
		&m_pTextureIcon[ICON_2P]);

	//テクスチャの読み込み
	D3DXCreateTextureFromFile(
		pDevice,
		MAKERTEX_03,
		&m_pTextureIcon[ICON_3P]);

	//テクスチャの読み込み
	D3DXCreateTextureFromFile(
		pDevice,
		MAKERTEX_04,
		&m_pTextureIcon[ICON_4P]);

	return S_OK;
}
//=======================================================================================================
// テクスチャの破棄
//========================================================================================================
void CSelectIcon::Unload(void)
{
	for (int nCnt =0; nCnt < ICON_MAX; nCnt++)
	{
		// 頂点バッファの開放
		if (m_pTextureIcon[nCnt] != NULL)
		{
			m_pTextureIcon[nCnt]->Release();
			m_pTextureIcon[nCnt] = NULL;
		}
	}
}

//========================================================================================================
// 描画処理
//========================================================================================================
void CSelectIcon::Draw(void)
{
	CBillboard::Draw();
}

//====================================================================================================
// デストラクタ
//=====================================================================================================
CSelectIcon::~CSelectIcon()
{

}