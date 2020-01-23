//=============================================================================
//
// �����蔻��p���f������ [hitmodel.h]
// Author : KOUTA KIMURA
//
//=============================================================================
#ifndef _HITMODEL_H_
#define _HITMODEL_H_

#define _CRT_SECURE_NO_WARNINGS

//=============================================================================
// �C���N���[�h�t�@�C��
//=============================================================================
#include "main.h"
#include "HitModelBase.h"

//=============================================================================
// �\���̒�`
//=============================================================================

//=============================================================================
// �}�N����`
//=============================================================================
#define MAX_TEXTURE		(21)									// �e�N�X�`����
#define MAX_SET_TEXTURE	(20)									// �ݒu�e�N�X�`����

//================================================================
// �����_�����O�N���X
//================================================================
class CHitModel : public CHitModelBase
{
public:
	enum UNITTYPE
	{
		UNITTYPE_FLOOR,
		UNITTYPE_MAX
	};

	//=============================================================================
	// �v���g�^�C�v�錾
	//=============================================================================
	CHitModel(OBJTYPE type);
	~CHitModel();

	static CHitModel *Create(D3DXVECTOR3 pos, D3DXVECTOR3 scale);

	HRESULT Init(D3DXVECTOR3 pos, D3DXVECTOR3 scale);
	void Uninit(void);
	void Update(void);
	void Draw(void);


	static HRESULT Load(void);
	static void Unload(void);

private:

	static DWORD		nNumMat;				// �}�e���A�����̐�
	static LPD3DXMESH	pMesh;					// ���b�V�����ւ̃|�C���^
	static LPD3DXBUFFER	pBuffMat;				// �}�e���A�����ւ̃|�C���^

};
#endif
