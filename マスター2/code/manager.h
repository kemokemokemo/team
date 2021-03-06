//====================================================================================================
//
// マネージャー処理 (manager.h)
// Author (Kimura kouta)
//
//====================================================================================================
#ifndef _MANAGER_H_
#define _MANAGER_H_

//====================================================================================================
//インクリードファイル
//====================================================================================================
#include"main.h"

class CRenderer;
class CKeybord;
class CPad;
class CTitle;
class CGame;
class CResult;
class CGameover;
class CTutorial;
class CSelectionScreen;
class CSound;
//====================================================================================================
//構造体定義
//=====================================================================================================

//================================================================
// レンダリングクラス
//================================================================
class CManager
{
public:

	//=============================================================================
	// 構造体定義
	//=============================================================================
	typedef enum
	{
		MODE_NONE = 0,
		MODE_TITLE,
		MODE_TUTRIAL,
		MODE_GAME,
		MODE_RESULT,
		MODE_RANKING,
		MODE_GAMEOVER,
		MODE_SELECTSCREEN,
		MODE_MAX,
	} MODE;

	// プロトタイプ宣言
	CManager();
	~CManager();

	HRESULT Init(HINSTANCE hInstance,HWND hWnd, BOOL bWindow);
	void Uninit(void);
	void Update(void);
	void Draw(void);

	static CRenderer *GetRenderer(void);
	static CKeybord *GetKeybord(void);
	static CPad *GetPad(void);
	static CSound *GetSound(void);
	static MODE GetMode(void);

	static void SetMode(MODE mode);

private:

	 static CRenderer *m_pRenderer;
	 static CKeybord *m_pKeybord;
	 static CPad *m_pPad;
	 static CTitle *pTitle;
	 static CGame *pGame;
	 static CResult *pResult;
	 static CGameover *pGameover;
	 static CTutorial *pTutorial;
	 static CSelectionScreen *pSelectionScreen;
	 static MODE m_mode;
	 static CSound *m_pSound;

};

#endif
