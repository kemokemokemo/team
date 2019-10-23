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
	// モデルの種類
	//=============================================================================
	typedef enum
	{
		PLAYER_01= 0,
		PLAYER_02,
		PLAYER_03,
		PLAYER_04,			// 種類の最大数
	} PLAYERNUM;

	//=============================================================================
	// プロトタイプ宣言
	//=============================================================================
	CPlayer(OBJTYPE type);
	~CPlayer();

	static CPlayer *Create(D3DXVECTOR3 pos, D3DXVECTOR3 rot, MODELTYPE type, PLAYERNUM PlayerNum);

	HRESULT Init(D3DXVECTOR3 pos, D3DXVECTOR3 rot, MODELTYPE type, PLAYERNUM PlayerNum);
	void Uninit(void);
	void Update(void);
	void Draw(void);
	void PlayerMove(void);

	static HRESULT Load(void);
	static void Unload(void);

	//bool CollisionModel(D3DXVECTOR3 *pPos, D3DXVECTOR3 *pPosOld, D3DXVECTOR3 size);

private:

	D3DXVECTOR3	m_move;						// 移動量
	MODELTYPE	m_type;						// 種類
	PLAYERNUM	m_PlayerNum;					// プレイヤーの人数

	static DWORD		nNumMat;						// マテリアル情報の数
	static LPD3DXMESH	pMesh;						// メッシュ情報へのポインタ
	static LPD3DXBUFFER	pBuffMat;					// マテリアル情報へのポインタ
};
#endif
