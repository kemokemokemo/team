//====================================================================================================
//
// 背景処理 (Result.cpp)
// Author  Kimura Kouta
//
//====================================================================================================
#ifndef _RESULT_H_
#define _RESULT_H_

//====================================================================================================
//インクリードファイル
//====================================================================================================
#include"main.h"
#include"manager.h"
#include "maker.h"
#include "playerbase.h"

//====================================================================================================
// プロトタイプ宣言
//=====================================================================================================

//================================================================
// レンダリングクラス
//================================================================
class CResult
{
public:

	// プロトタイプ宣言
	CResult();
	~CResult();

	HRESULT Init(void);
	void Uninit(void);
	void Update(void);
	void Draw(void);

	static CResult * Create();
	static void SetWinPlayer(CPlayerBase::PLAYERTYPE type, CMaker::MAKERTYPE p);

private:
	static CManager*m_pManager;

	static CMaker::MAKERTYPE m_nRank;
	static CPlayerBase::PLAYERTYPE m_WinType;
};
#endif