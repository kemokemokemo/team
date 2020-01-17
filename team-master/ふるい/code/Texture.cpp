//====================================================================================================
//
// テクスチャ表示処理 (Texture.cpp)
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
// マクロ定義
//====================================================================================================
#define TEXTURE_SIZE (40)
#define MAX_LIFE (40)
#define TEX_01 "DATA/TEX/selected_1p.png"					//読み込むテクスチャファイル名
#define TEX_02 "DATA/TEX/life_gauge_1p.png"					//読み込むテクスチャファイル名
#define TEX_03 "DATA/TEX/arrow_3p.png"					//読み込むテクスチャファイル名
#define TEX_04 "DATA/TEX/arrow_4p.png"					//読み込むテクスチャファイル名

#define TEX_05 "DATA/TEX/ken_icon.png"					//読み込むテクスチャファイル名
#define TEX_06 "DATA/TEX/kangaroo_icon.png"					//読み込むテクスチャファイル名
#define TEX_07 "DATA/TEX/sword_icon.png"					//読み込むテクスチャファイル名

#define TEX_08 "DATA/TEX/chara_ken.png"					//読み込むテクスチャファイル名
#define TEX_09 "DATA/TEX/chara_kangaroo.png"					//読み込むテクスチャファイル名
#define TEX_010 "DATA/TEX/chara_sword.png"					//読み込むテクスチャファイル名

#define TEX_011 "DATA/TEX/TitleBG.jpg"					//読み込むテクスチャファイル名
#define TEX_012 "DATA/TEX/TitleLogo.png"					//読み込むテクスチャファイル名

//====================================================================================================
// プロトタイプ宣言
//====================================================================================================

//====================================================================================================
// グローバル変数
//====================================================================================================
LPDIRECT3DTEXTURE9 CTexture::m_pTextureIcon[TYPE_MAX] = {};



//====================================================================================================
// コンストラクタ
//====================================================================================================
CTexture::CTexture(OBJTYPE type) : CScene2D(type)
{
}
//=============================================================================
// 初期化処理
//=============================================================================
HRESULT CTexture::Init(TEXTURE_TYPE type)
{
	CScene2D::Init();

	TexType = type;
	return S_OK;
}

//==================================================================================================
//終了処理
//===================================================================================================
void CTexture::Uninit(void)
{
	CScene2D::Uninit();
}

//====================================================================================================
//更新処理
//=====================================================================================================
void CTexture::Update(void)
{
	if (TexType == TYPE_TITLEBG)
	{
		SetAnim(0.1f, 0.0f, 0.5f, 10);
	}
}
//========================================================================================================
// 描画処理
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
// テクスチャの読み込み
//========================================================================================================
HRESULT CTexture::Load(void)
{
	CRenderer *pRenderer = CManager::GetRenderer();
	LPDIRECT3DDEVICE9 pDevice = pRenderer->GetDevice();

	//テクスチャの読み込み
	D3DXCreateTextureFromFile(
		pDevice,
		TEX_01,
		&m_pTextureIcon[TYPE_BG]);

	//テクスチャの読み込み
	D3DXCreateTextureFromFile(
		pDevice,
		TEX_02,
		&m_pTextureIcon[TYPE_LOGO]);

	//テクスチャの読み込み
	D3DXCreateTextureFromFile(
		pDevice,
		TEX_03,
		&m_pTextureIcon[TYPE_ENTER]);

	//テクスチャの読み込み
	D3DXCreateTextureFromFile(
		pDevice,
		"DATA/TEX/select_BG.jpg",
		&m_pTextureIcon[TYPE_SELECT_BG]);

	//テクスチャの読み込み
	D3DXCreateTextureFromFile(
		pDevice,
		"DATA/TEX/selected_1p.png",
		&m_pTextureIcon[TYPE_SELECT1]);

	//テクスチャの読み込み
	D3DXCreateTextureFromFile(
		pDevice,
		"DATA/TEX/selected_2p.png",
		&m_pTextureIcon[TYPE_SELECT2]);

	//テクスチャの読み込み
	D3DXCreateTextureFromFile(
		pDevice,
		"DATA/TEX/life_gauge_1p.png",
		&m_pTextureIcon[TYPE_LIFE1]);

	//テクスチャの読み込み
	D3DXCreateTextureFromFile(
		pDevice,
		"DATA/TEX/life_gauge_2p.png",
		&m_pTextureIcon[TYPE_LIFE2]);

	//テクスチャの読み込み
	D3DXCreateTextureFromFile(
		pDevice,
		TEX_05,
		&m_pTextureIcon[TYPE_KENICON]);

	//テクスチャの読み込み
	D3DXCreateTextureFromFile(
		pDevice,
		TEX_06,
		&m_pTextureIcon[TYPE_KANGAROOICON]);

	//テクスチャの読み込み
	D3DXCreateTextureFromFile(
		pDevice,
		TEX_07,
		&m_pTextureIcon[TYPE_SWORDICON]);

	//テクスチャの読み込み
	D3DXCreateTextureFromFile(
		pDevice,
		TEX_08,
		&m_pTextureIcon[TYPE_SELECTKENICON]);

	//テクスチャの読み込み
	D3DXCreateTextureFromFile(
		pDevice,
		TEX_09,
		&m_pTextureIcon[TYPE_SELECTKANGAROOICON]);

	//テクスチャの読み込み
	D3DXCreateTextureFromFile(
		pDevice,
		TEX_010,
		&m_pTextureIcon[TYPE_SELECTSWORDICON]);

	//テクスチャの読み込み
	D3DXCreateTextureFromFile(
		pDevice,
		TEX_011,
		&m_pTextureIcon[TYPE_TITLEBG]);

	//テクスチャの読み込み
	D3DXCreateTextureFromFile(
		pDevice,
		TEX_012,
		&m_pTextureIcon[TYPE_TITLELOG]);

	return S_OK;
}
//=======================================================================================================
// テクスチャの破棄
//========================================================================================================
void CTexture::Unload(void)
{
	for (int nCnt =0; nCnt < TYPE_MAX; nCnt++)
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
void CTexture::Draw(void)
{
	CScene2D::Draw();
}

//====================================================================================================
// デストラクタ
//=====================================================================================================
CTexture::~CTexture()
{

}