//=============================================================================
//
// プレイヤー処理 [playerbase.h]
// Author : KOTA KIMURA
//
//=============================================================================
#ifndef _PLAYERBASE_H_
#define _PLAYERBASE_H_

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
class CPlayerBase : public CScene3D
{
public:

	//=============================================================================
	// プレイヤー状態
	//=============================================================================
	typedef enum
	{
		PLAYERSTATE_NORMAL = 0,
		PLAYERSTATE_DAMAGE,
		PLAYERSTATE_UNDYING,
		PLAYERSTATE_ATK,
		PLAYERSTATE_RANNING,
		PLAYERSTATE_MAX,
	} PLAYERSTATE;

	//=============================================================================
	// モーションの種類
	//=============================================================================

	////=============================================================================
	//// プレイヤー人数
	////=============================================================================
	//typedef enum
	//{
	//	PLAYER_01= 0,
	//	PLAYER_02,
	//	PLAYER_03,
	//	PLAYER_04,			// 人の最大数
	//} PLAYERNUM;

	//=============================================================================
	// プレイヤー種類
	//=============================================================================
	typedef enum
	{
		PLAYERTYPE_KEN = 0,
		PLAYERTYPE_KANGAROO,
		PLAYERTYPE_SWORD,
		PLAYERTYPE_MAX
	} PLAYERTYPE;

	//=============================================================================
	// プロトタイプ宣言
	//=============================================================================
	CPlayerBase(OBJTYPE type);
	~CPlayerBase();

	HRESULT Init(D3DXVECTOR3 pos, D3DXVECTOR3 rot);

	void Uninit();
	void Update();
	void Draw();
	void PlayerMove();
	void PlayerDamage(CPlayerBase *pPlayer);
	void Damage(CPlayerBase *pPlayer, int nDamage);
	void MoveLimit(void);
	void MotionPlayer();
	void MotionChangePlayer(MOTIONTYPE motionType);

	void SetMove(D3DXVECTOR3 move) { m_move += move; }

	int GetLife();
	D3DXVECTOR3 GetMove() { return m_move; }

	static HRESULT Load();
	static HRESULT MotionLoad(std::ifstream *file, int nCnt);
	static void Unload();

	//bool CollisionModel(D3DXVECTOR3 *pPos, D3DXVECTOR3 *pPosOld, D3DXVECTOR3 size);

protected:
	void PlayerCollisionShape();

	float m_fRadius;
	float m_fAttack;

	int m_nLife;

	PLAYERTYPE m_TypeChara;
	PLAYERSTATE m_PlayerState;					//プレイヤーの状態

	D3DXVECTOR3	m_move;							// 移動量
	D3DXVECTOR3 m_fDistance;
	D3DXVECTOR3 m_fDiffrot;
private:
	void PlayerCollision();

	static MODELNUM m_PlayerType[PLAYERTYPE_MAX];
	static char *TextLoad[PLAYERTYPE_MAX];

	int m_PlayerStateCount;


};
#endif
