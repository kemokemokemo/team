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

//================================================================
// �����_�����O�N���X
//================================================================
class CPlayer : public CScene3D
{
public:

	//=============================================================================
	// ���f���̎��
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

	static HRESULT Load(void);
	static void Unload(void);

	//bool CollisionModel(D3DXVECTOR3 *pPos, D3DXVECTOR3 *pPosOld, D3DXVECTOR3 size);

private:

	D3DXVECTOR3	m_move;						// �ړ���
	MODELTYPE	m_type;						// ���
	PLAYERNUM	m_PlayerNum;					// �v���C���[�̐l��

	static DWORD		nNumMat;						// �}�e���A�����̐�
	static LPD3DXMESH	pMesh;						// ���b�V�����ւ̃|�C���^
	static LPD3DXBUFFER	pBuffMat;					// �}�e���A�����ւ̃|�C���^
};
#endif
