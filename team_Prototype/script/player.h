//=============================================================================
//
// �v���C���[���� [player.h]
// Author : KOUTA KIMURA
//
//=============================================================================
#ifndef _PLAYER_H_
#define _PLAYER_H_

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
class CPlayer : public CScene3D
{
public:

	//=============================================================================
	// �v���C���[���
	//=============================================================================
	typedef enum
	{
		PLAYERSTATE_NORMAL = 0,
		PLAYERSTATE_DAMAGE,
		PLAYERSTATE_DEATH,
		PLAYERSTATE_MAX,
	} PLAYERSTATE;

	//=============================================================================
	// �v���C���[�l��
	//=============================================================================
	typedef enum
	{
		PLAYER_01= 0,
		PLAYER_02,
		PLAYER_03,
		PLAYER_04,			// ��ނ̍ő吔
	} PLAYERNUM;

	//=============================================================================
	// �v���g�^�C�v�錾
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

	D3DXVECTOR3	m_move;							// �ړ���
	PLAYERNUM	m_PlayerNum;					// �v���C���[�̐l��
	PLAYERSTATE m_PlayerState;					//�v���C���[�̏��

	int m_nLife;
	int m_PlayerStateCount;
	CGauge *pLifeGauge;
	D3DXVECTOR3 Pos01;
	D3DXVECTOR3 Pos02;

	D3DXVECTOR3 m_fDistance;
	D3DXVECTOR3 m_fDiffrot;

	static DWORD		nNumMat[MODELTYPE_MAX];						// �}�e���A�����̐�
	static LPD3DXMESH	pMesh[MODELTYPE_MAX];						// ���b�V�����ւ̃|�C���^
	static LPD3DXBUFFER	pBuffMat[MODELTYPE_MAX];					// �}�e���A�����ւ̃|�C���^
};
#endif
