//=============================================================================
//
// プレイヤー処理 [player_ken.h]
// Author : KOTA KIMURA
//
//=============================================================================
#ifndef _PLAYER_KEN_H_
#define _PLAYER_KEN_H_

#define _CRT_SECURE_NO_WARNINGS

//=============================================================================
// インクルードファイル
//=============================================================================
#include "main.h"
#include "Scene3D.h"
#include "playerbase.h"

//=============================================================================
// 構造体定義
//=============================================================================

//=============================================================================
// マクロ定義
//=============================================================================
#define MAX_PLAYER	(2)


//================================================================
// レンダリングクラス
//================================================================
class CPlayer_KEN : public CPlayerBase
{
public:

	//=============================================================================
	// プロトタイプ宣言
	//=============================================================================
	CPlayer_KEN(OBJTYPE type);
	~CPlayer_KEN();

	static CPlayer_KEN *Create(D3DXVECTOR3 pos, D3DXVECTOR3 rot, CMaker::MAKERTYPE MokerType);

	HRESULT Init(D3DXVECTOR3 pos, D3DXVECTOR3 rot, CMaker::MAKERTYPE MokerType);

	void Uninit(void);
	void Update(void);
	void Draw(void);

private:
	bool bJunp;
};
#endif
