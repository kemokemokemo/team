//====================================================================================================
//
// レンダリング処理 (renderer.h)
// Author (Kimura kouta)
//
//====================================================================================================
#ifndef _RENDERER_H_
#define _RENDERER_H_

//====================================================================================================
//インクリードファイル
//====================================================================================================
#include"main.h"
#include"manager.h"
#include"fade.h"
//====================================================================================================
//構造体定義
//=====================================================================================================
class CCamera;

//================================================================
// レンダリングクラス
//================================================================
class CRenderer
{
public:

	// プロトタイプ宣言
	CRenderer();
	~CRenderer();

	HRESULT Init(HWND hWnd, BOOL bWindow);
	void Uninit(void);
	void Update(void);
	void Draw(void);
	LPDIRECT3DDEVICE9 GetDevice(void);

#ifdef _DEBUG

	void DrawFPS(void);
#endif

private:

	LPDIRECT3D9 m_pD3D;
	LPDIRECT3DDEVICE9 m_pD3DDevice;
	DWORD dwCurrentTime;

	DWORD dwExeclastTime;

	DWORD dwFrameCount;

	DWORD dwFPSLastTime;

	CManager::MODE m_aManager;

	CFade *m_pFade;
	static CCamera*m_pCamera;
#ifdef _DEBUG
	LPD3DXFONT			m_pFont = NULL;			// フォントへのポインタ
	int					m_nCountFPS = 0;		// FPSカウンタ
	int					m_FPS = 0;		// FPSカウンタ
#endif
};


//====================================================================================================
// マクロ定義
//==================================================================================================== 
#endif