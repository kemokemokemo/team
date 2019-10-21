//====================================================================================================
//
// �����_�����O���� (Scene.h)
// Author (Kimura kouta)
//
//====================================================================================================
#ifndef _SCENE3D_H_
#define _SCENE3D_H_

//====================================================================================================
//�C���N���[�h�t�@�C��
//====================================================================================================
#include"main.h"
#include"Scene.h"

//====================================================================================================
// �}�N����`
//==================================================================================================== 
#define MAX_MODEL		(128)									// ���f���̐�

//================================================================
// �����_�����O�N���X
//================================================================
class CScene3D : public CScene
{
public:

	//=============================================================================
	// ���f���̎��
	//=============================================================================
	typedef enum
	{
		MODELTYPE_BILL0 = 0,		// �r��0			[0]
		MODELTYPE_CAR,
		MODELTYPE_MAX				// ��ނ̍ő吔
	} MODELTYPE;

	//================================================================
	// �v���g�^�C�v�錾
	//================================================================
	CScene3D(OBJTYPE nPriority);
	~CScene3D();

	HRESULT Init(void);
	void Uninit(void);
	void Update(void);
	void Draw(void);
	void DrawModel(void);
	void ModelInit(void);

	D3DXVECTOR3 GetPos(void);
	void SetPos(D3DXVECTOR3 pos);
	void SetType(MODELTYPE Type);

private:

	VERTEX_3D m_Vertex[4];
	LPDIRECT3DTEXTURE9 m_pTexturePolygon;
	LPDIRECT3DVERTEXBUFFER9 m_pVtxBuffScene;		// ���_�o�b�t�@�ւ̃|�C���^
	D3DXVECTOR3 m_rotPolygon;
	D3DXMATRIX m_mtxWorldPolygon;
	D3DXVECTOR3 m_PosPolygon;

	D3DXVECTOR3 m_pos;						// �|���S���̈ʒu
	D3DXVECTOR3 m_rot;						// �|���S���̌���
	D3DXVECTOR3	m_move;						// �ړ���
	D3DXMATRIX  m_mtxWorld;					// ���[���h�}�g���b�N�X
	bool		m_bUse;						// �g�p���Ă��邩
	MODELTYPE	m_type;						// ���

	static DWORD		nNumMat;						// �}�e���A�����̐�
	static LPD3DXMESH	pMesh;						// ���b�V�����ւ̃|�C���^
	static LPD3DXBUFFER	pBuffMat;					// �}�e���A�����ւ̃|�C���^

	D3DXVECTOR3		vtxMin;						// �ő�l
	D3DXVECTOR3		vtxMax;						// �ŏ��l

};

//====================================================================================================
// �}�N����`
//==================================================================================================== 
#endif