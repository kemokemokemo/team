//=============================================================================
//
// �����蔻��p���f������ [hitmodel.h]
// Author : KOUTA KIMURA
//
//=============================================================================
#ifndef _HITMODELBASE_H_
#define _HITMODELBASE_H_

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
#define MAX_TEXTURE		(21)									// �e�N�X�`����
#define MAX_SET_TEXTURE	(20)									// �ݒu�e�N�X�`����

//================================================================
// �����_�����O�N���X
//================================================================
class CHitModelBase : public CScene
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
	CHitModelBase(OBJTYPE type);
	~CHitModelBase();


	HRESULT Init();
	void Uninit(void);
	void Update(void);
	void Draw(void);

	D3DXVECTOR3 GetPos();
	D3DXVECTOR3 GetSize();
	void SetPos(D3DXVECTOR3 pos);
	void Setsize(D3DXVECTOR3 scale);

	void BindHitModel(DWORD NumMat, LPD3DXMESH Mesh, LPD3DXBUFFER BuffMat);

private:

	LPDIRECT3DVERTEXBUFFER9 m_pVtxBuffScene;		// ���_�o�b�t�@�ւ̃|�C���^
	LPDIRECT3DTEXTURE9 m_pTextureModel;
	D3DXVECTOR3 m_pos;
	D3DXVECTOR3 m_rot;						// �|���S���̌���
	D3DXVECTOR3	m_scale;						
	D3DXMATRIX  m_mtxWorld;					// ���[���h�}�g���b�N�X
	D3DXVECTOR3		m_vtxMin;				//�ŏ��l
	D3DXVECTOR3		m_vtxMax;				//�ő�l 

	DWORD		nNumMat;				// �}�e���A�����̐�
	LPD3DXMESH	pMesh;					// ���b�V�����ւ̃|�C���^
	LPD3DXBUFFER	pBuffMat;				// �}�e���A�����ւ̃|�C���^

};
#endif
