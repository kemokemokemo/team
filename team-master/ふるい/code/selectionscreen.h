//====================================================================================================
//
// 背景処理 (SelectionScreen.cpp)
// Author  Kimura Kouta
//
//====================================================================================================
#ifndef _SELECTIONSCREEN_H_
#define _SELECTIONSCREEN_H_

//====================================================================================================
//インクリードファイル
//====================================================================================================
#include"main.h"
#include"manager.h"
#include"SelectIcon.h"
#include "Texture.h"

class CLight;

//====================================================================================================
// プロトタイプ宣言
//=====================================================================================================

//================================================================
// レンダリングクラス
//================================================================
class CSelectionScreen
{
public:

	// プロトタイプ宣言
	CSelectionScreen();
	~CSelectionScreen();

	HRESULT Init(void);
	void Uninit(void);
	void Update(void);
	void Draw(void);

	static CSelectionScreen * Create();

private:

	static CManager*m_pManager;
	static CLight*m_pLight;

	CSelectIcon *m_pPlayerIcon[2];
	CTexture *pTexture[2] = {};
};
#endif