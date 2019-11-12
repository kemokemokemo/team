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

#include <sstream>
#include <fstream>

//====================================================================================================
// �}�N����`
//==================================================================================================== 
#define MAX_MODEL		(64)									// ���f���̐�

//================================================================
// �����_�����O�N���X
//================================================================
class CScene3D : public CScene
{
public:

	//=============================================================================
	// ���f���̎��
	//=============================================================================
	typedef struct
	{
		DWORD nNumMat;							// �}�e���A�����̐�
		LPD3DXMESH pMesh;						// ���b�V�����ւ̃|�C���^
		LPD3DXBUFFER pBuffMat;					// �}�e���A�����ւ̃|�C���^

		D3DXMATRIX mtxWorld;

		D3DXVECTOR3 startpos;							// �|���S���̏����ʒu(�I�t�Z�b�g�l)
		D3DXVECTOR3 pos;								// �|���S���̈ʒu
		D3DXVECTOR3 rot;								// �|���S���̌���
		int nIdxModelModel;

		char cFileName[256];

	} MODEL;

	//================================================================
	// �v���g�^�C�v�錾
	//================================================================
	CScene3D(OBJTYPE nPriority);
	~CScene3D();

	HRESULT Init(void);
	void Uninit(void);
	void Update(void);
	void Draw(void);

	bool ShapeCapsuleCollision(D3DXVECTOR3 *pPosStart, D3DXVECTOR3 *pPosEnd, float Radius, D3DXVECTOR3 *pPos);

	void SetPos(D3DXVECTOR3 pos);
	void SetRot(D3DXVECTOR3 rot);

	D3DXVECTOR3 GetPos(void);
	D3DXVECTOR3 GetRot(void);
protected:

	struct MODELNUM
	{
		MODEL NumModel[MAX_MODEL];
		int nMaxModel;							// ���f����
	};
	void BindModel(const MODELNUM *type);
	static std::string WordLoad(std::ifstream *file, std::string word);

private:


	LPDIRECT3DTEXTURE9 m_pTexturePolygon;

	D3DXVECTOR3 m_pos;						// �|���S���̈ʒu
	D3DXVECTOR3 m_rot;						// �|���S���̌���
	D3DXVECTOR3	m_move;						// �ړ���
	D3DXMATRIX  m_mtxWorld;					// ���[���h�}�g���b�N�X

	MODELNUM m_Model;						// �e�q�p�[�c

	//MODELNUM	m_type;						// ���

	D3DXVECTOR3		m_vtxMin;				//�ŏ��l
	D3DXVECTOR3		m_vtxMax;				//�ő�l 

};

//====================================================================================================
// �}�N����`
//==================================================================================================== 
#endif