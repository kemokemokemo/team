//=============================================================================
//
// スコア処理 [time.h]
// Author :KIMURA KOUTA
//
//=============================================================================
#ifndef _TIME_H_
#define _TIME_H_

//=============================================================================
// インクルードファイル
//=============================================================================
#include "main.h"
#include "Scene.h"
#include "Number.h"

#define MAX_TIME   (3)


class CNumber;

//================================================================
// レンダリングクラス
//================================================================
class CTime : public CScene
{
public:

	//================================================================
	// プロトタイプ宣言
	//================================================================
	CTime(OBJTYPE nPriority);
	~CTime();

	HRESULT Init(void);
	void Uninit(void);
	void Update(void);
	void Draw(void);

	static CTime *Create(int nScore);
	int GetTime();
	void AddTime(int nNumber);
	void SetTime(int nScore);

private:

	CNumber *m_apTime[MAX_TIME];
	int m_nTime;
	int m_TimerState;
	int m_nCntTime;
};

//====================================================================================================
// マクロ定義
//==================================================================================================== 

#endif
