//=============================================================================
//
// プレイヤー処理 [player.h]
// Author : KOUTA KIMURA
//
//=============================================================================
#ifndef _PLAYER_H_
#define _PLAYER_H_

#define _CRT_SECURE_NO_WARNINGS

//=============================================================================
// インクルードファイル
//=============================================================================
#include "main.h"
#include "Scene3D.h"

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
class CPlayer : public CScene3D
{
public:

	//=============================================================================
	// プロトタイプ宣言
	//=============================================================================
	CPlayer(OBJTYPE type);
	~CPlayer();

	static CPlayer *Create(D3DXVECTOR3 pos, D3DXVECTOR3 rot, MODELTYPE type);

	HRESULT Init(D3DXVECTOR3 pos, D3DXVECTOR3 rot, MODELTYPE type);
	void Uninit(void);
	void Update(void);
	void Draw(void);
	void PlayerMove(void);

	//bool CollisionModel(D3DXVECTOR3 *pPos, D3DXVECTOR3 *pPosOld, D3DXVECTOR3 size);

private:

	D3DXVECTOR3	m_move;						// 移動量
	MODELTYPE	m_type;						// 種類
};
#endif
