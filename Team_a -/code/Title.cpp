//====================================================================================================
//
// 背景処理 (Title.cpp)
// Author  Kimura Kouta
//
//====================================================================================================
#include"Title.h"//インクルードファイル
#include"manager.h"
#include"renderer.h"
#include"input.h"
#include"keybord.h"

//================================================================================================
// マクロ定義
//================================================================================================

//================================================================================================
// 前方宣言初期化
//================================================================================================
CManager *CTitle::m_pManager = NULL;

//================================================================================================
// コンストラクタ
//================================================================================================
CTitle::CTitle()
{

}

//================================================================================================
// デストラクタ
//================================================================================================
CTitle::~CTitle()
{

}

//================================================================================================
// 背景の初期化
//================================================================================================
HRESULT CTitle::Init(void)
{


	return S_OK;
}

//================================================================================================
// 背景の開放処理
//================================================================================================
void CTitle::Uninit(void)
{

}

//================================================================================================
// 背景の更新処理
//================================================================================================
void CTitle::Update(void)
{
	CKeybord *pKetybord = CManager::GetKeybord();

	if (CFade::GetFade() == CFade::FADE_NONE)
	{
		if (pKetybord->GetKeyboardTrigger(DIK_RETURN))
		{
			CFade::SetFade(m_pManager->MODE_TUTRIAL);
		}
	}
}

//================================================================================================
// 背景の描画処理
//================================================================================================
void CTitle::Draw(void)
{

}

//================================================================================================
// タイトル処理
//================================================================================================
CTitle * CTitle::Create(void)
{
	CTitle *pTitle;

	pTitle = new CTitle();

	pTitle->Init();

	return pTitle;
}

//================================================================================================
// 読み込み処理
//================================================================================================
HRESULT CTitle::Load(void)
{
	//CRenderer *pRenderer = CManager::GetRenderer();
	//LPDIRECT3DDEVICE9 pDevice = pRenderer->GetDevice();

	////テクスチャの読み込み
	//D3DXCreateTextureFromFile(
	//	pDevice,
	//	TEXTUER_008,
	//	&m_pTextureNeutral[0]);

	return S_OK;
}

//================================================================================================
// 破棄の処理
//================================================================================================
void CTitle::Unload(void)
{
	//for (int nCnt = 0; nCnt < MAX_TEXENEMY; nCnt++)
	//{
	//	// 頂点バッファの開放
	//	if (m_pTextureNeutral[nCnt] != NULL)
	//	{
	//		m_pTextureNeutral[nCnt]->Release();
	//		m_pTextureNeutral[nCnt] = NULL;
	//	}
	//}
}
