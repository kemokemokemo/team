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
		MODELTYPE_CAT,
		MODELTYPE_MAX				// ��ނ̍ő吔
	} MODELTYPE;

	//=============================================================================
	// ���f���̎��
	//=============================================================================
	typedef struct
	{
		D3DXMATRIX  mtxWorld;
		D3DXVECTOR3 pos;								// �|���S���̈ʒu
		D3DXVECTOR3 rot;								// �|���S���̌���
		int nIdxModelParent;
		int nType;
	} PARENT;

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

	void BindModel(DWORD NumMat, LPD3DXMESH Mesh, LPD3DXBUFFER BuffMat);
	bool CScene3D::ShapeCapsuleCollision(D3DXVECTOR3 *pPosStart, D3DXVECTOR3 *pPosEnd, float Radius, D3DXVECTOR3 *pPos);
	D3DXVECTOR3 GetPos(void);
	void SetPos(D3DXVECTOR3 pos);
	D3DXVECTOR3 GetRot(void);
	static int GetLife(void);

	void SetRot(D3DXVECTOR3 rot);
	void SetType(MODELTYPE Type);

	void SetLife(int nLife);

private:

	static int m_Life;

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

	PARENT m_Parent[MAX_MODEL];				// �e�q�p�[�c

	MODELTYPE	m_type;						// ���

	DWORD		nNumMat;					// �}�e���A�����̐�
	LPD3DXMESH	pMesh;						// ���b�V�����ւ̃|�C���^
	LPD3DXBUFFER	pBuffMat;				// �}�e���A�����ւ̃|�C���^

	D3DXVECTOR3		m_vtxMin;				//�ŏ��l
	D3DXVECTOR3		m_vtxMax;				//�ő�l 

};

//====================================================================================================
// �}�N����`
//==================================================================================================== 
#endif