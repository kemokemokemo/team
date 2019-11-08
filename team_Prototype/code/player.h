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

class CGauge;
//================================================================
// レンダリングクラス
//================================================================
class CPlayer : public CScene3D
{
public:

	//=============================================================================
	// プレイヤー状態
	//=============================================================================
	typedef enum
	{
		PLAYERSTATE_NORMAL = 0,
		PLAYERSTATE_DAMAGE,
		PLAYERSTATE_DEATH,
		PLAYERSTATE_MAX,
	} PLAYERSTATE;

	//=============================================================================
	// プレイヤー人数
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
	void PlayerDamage(void);
	void Damage(int nDamage);
	void MoveLimit(void);
	D3DXVECTOR3 GetPlayerPos(void);

	int GetLife(void);

	static HRESULT Load(void);
	static void Unload(void);
	void PlayerCollision();

	//bool CollisionModel(D3DXVECTOR3 *pPos, D3DXVECTOR3 *pPosOld, D3DXVECTOR3 size);

private:

	D3DXVECTOR3	m_move;							// 移動量
	PLAYERNUM	m_PlayerNum;					// プレイヤーの人数
	PLAYERSTATE m_PlayerState;					//プレイヤーの状態

	int m_nLife;
	int m_PlayerStateCount;
	CGauge *pLifeGauge;
	D3DXVECTOR3 Pos01;
	D3DXVECTOR3 Pos02;

	D3DXVECTOR3 m_fDistance;
	D3DXVECTOR3 m_fDiffrot;

	static DWORD		nNumMat[MODELTYPE_MAX];						// マテリアル情報の数
	static LPD3DXMESH	pMesh[MODELTYPE_MAX];						// メッシュ情報へのポインタ
	static LPD3DXBUFFER	pBuffMat[MODELTYPE_MAX];					// マテリアル情報へのポインタ
};
#endif
