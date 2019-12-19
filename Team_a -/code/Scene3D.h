//====================================================================================================
//
// �����_�����O���� (Scene.h)
// Author KOUTA KIMURA
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
#define MAX_MODEL		(32)									// ���f���̐�
#define MAX_KEY			(10)									// �L�[�̐�


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
		LPDIRECT3DTEXTURE9	*pTexture;			// �e�N�X�`���ւ̃|�C���g

		D3DXMATRIX mtxWorld;

		D3DXVECTOR3 startpos;							// �|���S���̏����ʒu(�I�t�Z�b�g�l)
		D3DXVECTOR3 pos;								// �|���S���̈ʒu
		D3DXVECTOR3 rot;								// �|���S���̌���
		D3DXVECTOR3 vtxMin;							//�ŏ��l
		D3DXVECTOR3 vtxMax;							//�ő�l 
		int nIdxModel;
		int nType;

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


	void Textureload(LPDIRECT3DDEVICE9 pDevice);

	bool ShapeCapsuleCollision(D3DXVECTOR3 *pPosStart, D3DXVECTOR3 *pPosEnd, float Radius, D3DXVECTOR3 *pPos);

	void SetPos(D3DXVECTOR3 pos);
	void SetRot(D3DXVECTOR3 rot);
	void SetScale(D3DXVECTOR3 scale) { m_scale = scale; }
	D3DXVECTOR3 SetvtxMin(D3DXVECTOR3 vtxMin) { return m_vtxMin = vtxMin; }
	D3DXVECTOR3 SetvtxMax(D3DXVECTOR3 vtxMax) { return m_vtxMax = vtxMax; }
	void SetHight(float Hight);
	void SetLoad(D3DXVECTOR3 pos, D3DXVECTOR3 rot, int nIdxModel, int nType);


	D3DXVECTOR3 GetPos();
	D3DXVECTOR3 GetRot();
	D3DXVECTOR3 GetScale() { return m_scale; }
	D3DXVECTOR3 GetvtxMin() { return m_vtxMin; }
	D3DXVECTOR3 GetvtxMax() { return m_vtxMax; }

	struct MODELNUM
	{
		MODEL NumModel[MAX_MODEL];
		int nMaxModel;								// ���f����
		int nMotionMax;
	};

	void SetModel(MODELNUM model);
	CScene3D::MODELNUM GetModel();
protected:

	void BindModel(const MODELNUM *type);
	//void BindMotion(const MOTION_INFO *type);

	void SetPosParts(MODELNUM *type);
	static std::string WordLoad(std::ifstream *file, std::string word, int linenum = 0);
	static void Vector3Load(std::string word,D3DXVECTOR3 *Vec3);

private:

	MODELNUM m_Model;						// �e�q�p�[�c

	D3DXVECTOR3 m_pos;						// �|���S���̈ʒu
	D3DXVECTOR3 m_rot;						// �|���S���̌���
	D3DXVECTOR3	m_scale;

	D3DXVECTOR3	m_move;						// �ړ���
	D3DXMATRIX  m_mtxWorld;					// ���[���h�}�g���b�N�X

	D3DXVECTOR3	m_vtxMin;				//�ŏ��l
	D3DXVECTOR3	m_vtxMax;				//�ő�l 

	LPDIRECT3DVERTEXBUFFER9 m_pVtxBuffScene;
};

//====================================================================================================
// �}�N����`
//==================================================================================================== 
#endif