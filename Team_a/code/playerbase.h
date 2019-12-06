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
		PLAYERSTATE_ACT,
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
	// モーションの種類
	//=============================================================================
	typedef enum
	{
		MOTIONTYPE_WAIT = 0,	// ニュートラル
		MOTIONTYPE_RUN,			// ランニング
		MOTIONTYPE_LIGHT0,		// 弱攻撃1段目
		MOTIONTYPE_LIGHT1,		// 2段目
		MOTIONTYPE_LIGHT2,		// 3段目
		MOTIONTYPE_DASHATK,		// ダッシュ攻撃
		MOTIONTYPE_UPATK,		// 上攻撃
		MOTIONTYPE_CROUCHATK,	// しゃがみ攻撃
		MOTIONTYPE_CROUCHWAIT,	// しゃがみ中
		MOTIONTYPE_DAMAGE,		// ダメージ
		MOTIONTYPE_JUMP,		// 空中
		MOTIONTYPE_DOUBLEJUMP,	// 二段ジャンプ
		MOTIONTYPE_RAND,		// 着地
		MOTIONTYPE_AIR_N,		// 空中ニュートラル
		MOTIONTYPE_AIR_F,		// 空中前
		MOTIONTYPE_AIR_B,		// 空中後ろ
		MOTIONTYPE_AIR_U,		// 空中上
		MOTIONTYPE_AIR_D,		// 空中下
		MOTIONTYPE_SP_N,		// 特殊ニュートラル
		MOTIONTYPE_SP_UP,		// 特殊上
		MOTIONTYPE_SP_DOWN,		// 特殊下
		MOTIONTYPE_GAUDE,		// ガード
		MOTIONTYPE_MAX			// モーションの最大数
	} MOTIONTYPE;

	typedef struct
	{// キー要素
		D3DXVECTOR3		pos;						// 現在の位置
		D3DXVECTOR3		rot;						// 向き(回転)
	} KEY;

	typedef struct
	{// キー情報
		int				nNumKyeFrame;				// キーフレーム数
		KEY				aKey[MAX_MODEL];			// キー要素
	} KEY_INFO;
	typedef struct
	{// モーション情報
		int				nCntFrame;					// 現在のフレーム数
		int				nNumKey;					// 現在のキー
		int				nMaxKey;					// 最大キー数
		bool			bLoop;						// ループするか
		KEY_INFO		aKeyInfo[MAX_KEY];			// キー情報
		int             nHitIdx;					// 攻撃の部位
		int				nAtkStar;
		int				nAtkEnd;
	} MOTION_INFO;

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

	void SetJump(bool bJumpman);//ジャンプ
	bool GetJump();//ジャンプ

	void PlayerCollisionFloor();//床


protected:
	void PlayerCollisionShape();

	float m_fRadius;
	float m_fAttack;

	int m_nLife;
	int nCountATK;

	PLAYERTYPE m_TypeChara;
	PLAYERSTATE m_PlayerState;					//プレイヤーの状態

	D3DXVECTOR3 m_posOld;
	D3DXVECTOR3 m_pos;
	D3DXVECTOR3	m_move;							// 移動量
	D3DXVECTOR3 m_fDistance;
	D3DXVECTOR3 m_fDiffrot;
	MOTIONTYPE	MotionType;					// 現在のモーション
	bool bWJump;
private:
	void PlayerCollision();
	static MODELNUM m_PlayerType[PLAYERTYPE_MAX];
	static char *TextLoad[PLAYERTYPE_MAX];

	int m_PlayerStateCount;
	static MOTION_INFO aMotionInfo[PLAYERTYPE_MAX][MOTIONTYPE_MAX];
	MOTION_INFO MotionInfo[MOTIONTYPE_MAX];

	bool bJump;


};
#endif
