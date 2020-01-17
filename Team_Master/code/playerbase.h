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
#include "maker.h"
#include "HitModel.h"


//=============================================================================
// �\���̒�`
//=============================================================================

//=============================================================================
// �}�N����`
//=============================================================================
#define MAX_PLAYER	(2)

class CGauge;
class CMaker;

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
		PLAYERSTATE_AIRATK,
		PLAYERSTATE_GAUDE,
		PLAYERSTATE_MAX,
	} PLAYERSTATE;

	//=============================================================================
	// ���[�V�����̎��
	//=============================================================================

	////=============================================================================
	//// �v���C���[�l��
	////=============================================================================
	//typedef enum
	//{
	//	PLAYER_01= 0,
	//	PLAYER_02,
	//	PLAYER_03,
	//	PLAYER_04,			// �l�̍ő吔
	//} PLAYERNUM;

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
	// ���[�V�����̎��
	//=============================================================================
	typedef enum
	{
		MOTIONTYPE_WAIT = 0,	// �j���[�g����
		MOTIONTYPE_RUN,			// �����j���O
		MOTIONTYPE_LIGHT0,		// ��U��1�i��
		MOTIONTYPE_LIGHT1,		// 2�i��
		MOTIONTYPE_LIGHT2,		// 3�i��
		MOTIONTYPE_DASHATK,		// �_�b�V���U��
		MOTIONTYPE_UPATK,		// ��U��
		MOTIONTYPE_CROUCHATK,	// ���Ⴊ�ݍU��
		MOTIONTYPE_CROUCHWAIT,	// ���Ⴊ�ݒ�
		MOTIONTYPE_DAMAGE,		// �_���[�W
		MOTIONTYPE_JUMP,		// ��
		MOTIONTYPE_DOUBLEJUMP,	// ��i�W�����v
		MOTIONTYPE_RAND,		// ���n
		MOTIONTYPE_AIR_N,		// �󒆃j���[�g����
		MOTIONTYPE_AIR_F,		// �󒆑O
		MOTIONTYPE_AIR_B,		// �󒆌��
		MOTIONTYPE_AIR_U,		// �󒆏�
		MOTIONTYPE_AIR_D,		// �󒆉�
		MOTIONTYPE_SP_N,		// ����j���[�g����
		MOTIONTYPE_SP_UP,		// �����
		MOTIONTYPE_SP_DOWN,		// ���ꉺ
		MOTIONTYPE_GAUDE,		// �K�[�h
		MOTIONTYPE_MAX			// ���[�V�����̍ő吔
	} MOTIONTYPE;

	typedef struct
	{// �L�[�v�f
		D3DXVECTOR3		pos;						// ���݂̈ʒu
		D3DXVECTOR3		rot;						// ����(��])
	} KEY;

	typedef struct
	{// �L�[���
		int				nNumKyeFrame;				// �L�[�t���[����
		KEY				aKey[MAX_MODEL];			// �L�[�v�f
	} KEY_INFO;
	typedef struct
	{// ���[�V�������
		int				nCntFrame;					// ���݂̃t���[����
		int				nNumKey;					// ���݂̃L�[
		int				nMaxKey;					// �ő�L�[��
		bool			bLoop;						// ���[�v���邩
		KEY_INFO		aKeyInfo[MAX_KEY];			// �L�[���
		int             nHitIdx;					// �U���̕���
		int				nAtkStar;
		int				nAtkEnd;
	} MOTION_INFO;

	//=============================================================================
	// �v���g�^�C�v�錾
	//=============================================================================
	CPlayerBase(OBJTYPE type);
	~CPlayerBase();

	HRESULT Init(D3DXVECTOR3 pos, D3DXVECTOR3 rot, CMaker::MAKERTYPE MokerType);

	void Uninit();
	void Update();
	void Draw();
	void PlayerMove();
	void PlayerDamage(CPlayerBase *pPlayer);
	void Damage(CPlayerBase *pPlayer, int nDamage);
	void MoveLimit(void);
	void MotionPlayer();
	void MotionChangePlayer(MOTIONTYPE motionType);

	void KenDamage(CPlayerBase *pPlayer);
	void KangarooDamage(CPlayerBase *pPlayer);
	void SwordDamage(CPlayerBase *pPlayer);

	void SetMove(D3DXVECTOR3 move) { m_move += move; }

	int GetLife();
	D3DXVECTOR3 GetMove() { return m_move; }
	PLAYERTYPE GetTypeChara() { return m_TypeChara; }

	CMaker::MAKERTYPE GetMaker();

	static HRESULT Load();
	static HRESULT MotionLoad(std::ifstream *file, int nCnt);
	static void Unload();

	void SetJump(bool bJumpman);//�W�����v
	bool GetJump();//�W�����v

	void PlayerCollisionFloor();//��


protected:
	void PlayerCollisionShape();

	float m_fRadius;
	float m_fAttack;

	int m_nLife;
	int nCountATK;

	PLAYERTYPE m_TypeChara;
	PLAYERSTATE m_PlayerState;					//�v���C���[�̏��

	D3DXVECTOR3 m_posOld;
	D3DXVECTOR3 m_pos;
	D3DXVECTOR3	m_move;							// �ړ���
	D3DXVECTOR3 m_fDistance;
	D3DXVECTOR3 m_fDiffrot;
	MOTIONTYPE	m_MotionType;					// ���݂̃��[�V����
	bool bWJump;
private:

	void PlayerCollision();
	void NocBack();

	static MODELNUM m_PlayerType[PLAYERTYPE_MAX];
	static char *TextLoad[PLAYERTYPE_MAX];
	
	MOTIONTYPE m_MotionOld;

	int m_PlayerStateCount;
	static MOTION_INFO aMotionInfo[PLAYERTYPE_MAX][MOTIONTYPE_MAX];
	MOTION_INFO MotionInfo[MOTIONTYPE_MAX];

	bool bJump;
	CMaker::MAKERTYPE m_MokerType;

	CHitModel *m_Hitmodel;
	CMaker *pMaker;
	CGauge *pGauge;
};
#endif