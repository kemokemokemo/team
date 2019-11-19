//====================================================================================================
//
// ゲーム処理 (Game.h)
// Author  Kimura Kouta
//
//====================================================================================================
#ifndef _GAME_H_
#define _GAME_H_

#define DIRECTINPUT_VERSION	(0x0800)
//====================================================================================================
//インクリードファイル
//====================================================================================================
#include"main.h"

class CManager;
class CRenderer;
class CCamera;
class CLight;
class CPlayer;

//================================================================
// レンダリングクラス
//================================================================
class CGame
{
public:

	// プロトタイプ宣言
	CGame();
	~CGame();

	HRESULT Init(void);
	void Uninit(void);
	void Update(void);
	void Draw(void);


	static CGame * Create();

private:

	static CManager*m_pManager;
	static CCamera*m_pCamera;
	static CLight*m_pLight;

};
#endif