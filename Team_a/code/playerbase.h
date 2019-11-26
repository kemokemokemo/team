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
	typedef enum
	{
		MOTIONSTATE_WAIT = 0,	// ニュートラル
		MOTIONSTATE_RUN,		// ランニング
		MOTIONSTATE_LIGHT0,		// 弱攻撃1段目
		MOTIONSTATE_LIGHT1,		// 2段目
		MOTIONSTATE_LIGHT2,		// 3段目
		MOTIONSTATE_DASHATK,	// ダッシュ攻撃
		MOTIONSTATE_UPATK,		// サマソ
		MOTIONSTATE_CROUCHATK,
		MOTIONSTATE_CROUCHWAIT,
		MOTIONSTATE_DAMAGE,	// 吹き飛ぶ
		MOTIONSTATE_JUMP,		// ジャンプ
		MOTIONSTATE_MAX			// モーションの最大数
	} MOTIONSTATE;

	//=============================================================================
	// プレイヤー人数
	//=============================================================================
	typedef enum
	{
		PLAYER_01= 0,
		PLAYER_02,
		PLAYER_03,
		PLAYER_04,			// 人の最大数
	} PLAYERNUM;

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

	HRESULT Init(D3DXVECTOR3 pos, D3DXVECTOR3 rot, PLAYERNUM PlayerNum);

	void Uninit();
	void Update();
	void Draw();
	void PlayerMove();
	void PlayerDamage(CPlayerBase *pPlayer);
	void Damage(CPlayerBase *pPlayer, int nDamage);
	void MoveLimit(void);
	void MotionPlayer(int nCnt);
	void MotionChangePlayer(MOTIONTYPE motionType, int nCnt);
	D3DXVECTOR3 GetPlayerPos(void);

	int GetLife(void);

	static HRESULT Load(void);
	static HRESULT MotionLoad(std::ifstream *file, int nCnt);
	static void Unload(void);

	//bool CollisionModel(D3DXVECTOR3 *pPos, D3DXVECTOR3 *pPosOld, D3DXVECTOR3 size);

protected:
	void PlayerCollision();

	float m_fRadius;
	float m_fAttack;

	int m_nLife;

	PLAYERTYPE m_TypeChara;
	D3DXVECTOR3	m_move;							// 移動量
	PLAYERSTATE m_PlayerState;					//プレイヤーの状態
	MOTIONSTATE m_MotionState;

private:
	static MODELNUM m_PlayerType[PLAYERTYPE_MAX];


	PLAYERNUM	m_PlayerNum;					// プレイヤーの人数

	int m_PlayerStateCount;

	static char *TextLoad[PLAYERTYPE_MAX];

	CGauge *pLifeGauge;
	D3DXVECTOR3 m_pos;


	MODELNUM m_TypeSelect;
	D3DXVECTOR3 m_fDistance;
	D3DXVECTOR3 m_fDiffrot;
};
#endif
