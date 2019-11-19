//====================================================================================================
//
// リザルト処理 (Result.cpp)
// Author  Kimura Kouta
//
//====================================================================================================
#include"tutorial.h"//インクルードファイル
#include"manager.h"
#include"renderer.h"
#include"input.h"
#include"keybord.h"

//====================================================================================================
// マクロ定義
//==================================================================================================== 

//=====================================================================================================
// 前方宣言初期化
//=====================================================================================================
CManager *CTutorial::m_pManager = NULL;

//================================================================================================
// コンストラクタ
//=================================================================================================
CTutorial::CTutorial()
{

}

//================================================================================================
// デストラクタ
//=================================================================================================
CTutorial::~CTutorial()
{

}

//================================================================================================
// 背景の初期化
//=================================================================================================
HRESULT CTutorial::Init(void)
{



	return S_OK;
}

//================================================================================================
// 背景の開放処理
//=================================================================================================
void CTutorial::Uninit(void)
{

}

//================================================================================================
// 背景の更新処理
//=================================================================================================
void CTutorial::Update(void)
{
	CKeybord *pKetybord = CManager::GetKeybord();

	if (CFade::GetFade() == CFade::FADE_NONE)
	{
		if (pKetybord->GetKeyboardTrigger(DIK_RETURN))
		{
			CFade::SetFade(m_pManager->MODE_GAME);
		}
	}
}

//================================================================================================
// 背景の描画処理
//=================================================================================================
void CTutorial::Draw(void)
{

}

//================================================================================================
// タイトル処理
//================================================================================================
CTutorial * CTutorial::Create(void)
{
	CTutorial *pTutorial;

	pTutorial = new CTutorial();

	pTutorial->Init();

	return pTutorial;
}