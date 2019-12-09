//====================================================================================================
//
// ゲーム処理 (Game.cpp)
// Author  Kimura Kouta
//
//====================================================================================================
#include "Game.h"//インクルードファイル
#include "manager.h"
#include "Scene.h"
#include "Scene2D.h"
#include "renderer.h"
#include "keybord.h"
#include "Title.h"
#include "Result.h"
#include "fade.h"
#include "light.h"
#include "camera.h"
#include "polygon.h"
#include "model.h"
#include "player_ken.h"
#include "player_sword.h"
#include "player_Kangaroo.h"
#include "gauge.h"

//====================================================================================================
// マクロ定義
//==================================================================================================== 

//=====================================================================================================
// 前方宣言初期化
//=====================================================================================================
CManager *CGame::m_pManager = NULL;
CLight*CGame::m_pLight = NULL;

//================================================================================================
// コンストラクタ
//=================================================================================================
CGame::CGame()
{

}

//================================================================================================
// デストラクタ
//=================================================================================================
CGame::~CGame()
{

}

//================================================================================================
// 背景の初期化
//=================================================================================================
HRESULT CGame::Init(void)
{
	m_pLight = CLight::Create();

	CPlayerBase::Load();

	CModel::Load();

	CGauge::Load();

	CModel::Create(D3DXVECTOR3(0.0f, 0.0f, 0.0f), D3DXVECTOR3(0.0f, 0.0f, 0.0f), CModel::UNITTYPE_FLOOR);

	//CModel::Create(D3DXVECTOR3(640.0f, 0.0f, 0.0f), D3DXVECTOR3(0.0f, 0.0f, 0.0f), CModel::MODELTYPE_BILL0);

	CPlayer_KEN::Create(D3DXVECTOR3(-200.0f, 500.0f, 0.0f), D3DXVECTOR3(0.0f, 0.0f, 0.0f));

	CPlayer_SWORD::Create(D3DXVECTOR3(200.0f,500.0f, 0.0f), D3DXVECTOR3(0.0f, 0.0f, 0.0f));

	CPlayer_Kangaroo::Create(D3DXVECTOR3(0.0f, 500.0f, 0.0f), D3DXVECTOR3(0.0f, 0.0f, 0.0f));

	CGauge::Create(D3DXVECTOR3(200.0f, 600.0f, 0.0f));

	CPolygon::Create();

	return S_OK;
}

//================================================================================================
// 背景の開放処理
//=================================================================================================
void CGame::Uninit(void)
{
	m_pLight->Uninit();
	CPlayerBase::Unload();
	CModel::Unload();
	CGauge::Unload();
}

//================================================================================================
// 背景の更新処理
//=================================================================================================
void CGame::Update(void)
{
	m_pLight->Update();

	CKeybord *pKetybord = CManager::GetKeybord();

	// (pKetybord->GetKeyboardTrigger(DIK_RETURN))
	{
		//CFade::SetFade(m_pManager->MODE_RESULT);
	}
}

//================================================================================================
// 背景の描画処理
//=================================================================================================
void CGame::Draw(void)
{

}

//================================================================================================
// タイトル処理
//================================================================================================
CGame * CGame::Create(void)
{
	CGame *pGame;

	pGame = new CGame();

	pGame->Init();

	return pGame;
}