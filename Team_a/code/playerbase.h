//=============================================================================
//
// �v���C���[���� [playerbase.h]
// Author : KOTA KIMURA
//
//=============================================================================
#ifndef _PLAYERBASE_H_
#define _PLAYERBASE_H_

#define _CRT_SECURE_NO_WARNINGS

//=============================================================================
// �C���N���[�h�t�@�C��
//=============================================================================
#include "main.h"
#include "Scene3D.h"

//=============================================================================
// �\���̒�`
//=============================================================================

//=============================================================================
// �}�N����`
//=============================================================================
#define MAX_PLAYER	(2)

class CGauge;
//================================================================
// �����_�����O�N���X
//================================================================
class CPlayerBase : public CScene3D
{
public:

	//=============================================================================
	// �v���C���[���
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
	// ���[�V�����̎��
	//=============================================================================
	typedef enum
	{
		MOTIONSTATE_WAIT = 0,	// �j���[�g����
		MOTIONSTATE_RUN,		// �����j���O
		MOTIONSTATE_LIGHT0,		// ��U��1�i��
		MOTIONSTATE_LIGHT1,		// 2�i��
		MOTIONSTATE_LIGHT2,		// 3�i��
		MOTIONSTATE_DASHATK,	// �_�b�V���U��
		MOTIONSTATE_UPATK,		// �T�}�\
		MOTIONSTATE_CROUCHATK,
		MOTIONSTATE_CROUCHWAIT,
		MOTIONSTATE_DAMAGE,	// �������
		MOTIONSTATE_JUMP,		// �W�����v
		MOTIONSTATE_MAX			// ���[�V�����̍ő吔
	} MOTIONSTATE;

	//=============================================================================
	// �v���C���[�l��
	//=============================================================================
	typedef enum
	{
		PLAYER_01= 0,
		PLAYER_02,
		PLAYER_03,
		PLAYER_04,			// �l�̍ő吔
	} PLAYERNUM;

	//=============================================================================
	// �v���C���[���
	//=============================================================================
	typedef enum
	{
		PLAYERTYPE_KEN = 0,
		PLAYERTYPE_KANGAROO,
		PLAYERTYPE_SWORD,
		PLAYERTYPE_MAX
	} PLAYERTYPE;

	//=============================================================================
	// �v���g�^�C�v�錾
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
	D3DXVECTOR3	m_move;							// �ړ���
	PLAYERSTATE m_PlayerState;					//�v���C���[�̏��
	MOTIONSTATE m_MotionState;

private:
	static MODELNUM m_PlayerType[PLAYERTYPE_MAX];


	PLAYERNUM	m_PlayerNum;					// �v���C���[�̐l��

	int m_PlayerStateCount;

	static char *TextLoad[PLAYERTYPE_MAX];

	CGauge *pLifeGauge;
	D3DXVECTOR3 m_pos;


	MODELNUM m_TypeSelect;
	D3DXVECTOR3 m_fDistance;
	D3DXVECTOR3 m_fDiffrot;
};
#endif
