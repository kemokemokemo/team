//=============================================================================
//
// ���f������ [model.h]
// Author : KOUTA KIMURA
//
//=============================================================================
#ifndef _MODEL_H_
#define _MODEL_H_

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
#define MODELFILE0		"DATA/MODEL/icefence.x"					// �ǂݍ��ރ��f��
#define MODELFILE1		"DATA/MODEL/car_000.x"					// �ǂݍ��ރ��f��

#define MAX_TEXTURE		(21)									// �e�N�X�`����
#define MAX_SET_TEXTURE	(20)									// �ݒu�e�N�X�`����

//================================================================
// �����_�����O�N���X
//================================================================
class CModel : public CScene3D
{
public:

	//=============================================================================
	// �v���g�^�C�v�錾
	//=============================================================================
	CModel(OBJTYPE type);
	~CModel();

	static CModel *Create(D3DXVECTOR3 pos, D3DXVECTOR3 rot, MODELTYPE type);

	HRESULT Init(D3DXVECTOR3 pos, D3DXVECTOR3 rot, MODELTYPE type);
	void Uninit(void);
	void Update(void);
	void Draw(void);

	//void SetModel(D3DXVECTOR3 pos, D3DXVECTOR3 rot, MODELTYPE type);
	//bool CollisionModel(D3DXVECTOR3 *pPos, D3DXVECTOR3 *pPosOld, D3DXVECTOR3 size);

private:

	LPDIRECT3DTEXTURE9	m_pTextureModel[MAX_TEXTURE] = {};			// �e�N�X�`���ւ̃|�C���^
	D3DXVECTOR3 m_pos;
};
#endif
