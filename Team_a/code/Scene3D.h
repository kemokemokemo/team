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
		int nIdxModel;
		int nType;

		char cFileName[256];

	} MODEL;

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
		MOTIONTYPE_UPATK,		// �T�}�\
		MOTIONTYPE_CROUCHATK,
		MOTIONTYPE_CROUCHWAIT,
		MOTIONTYPE_DAMAGE,	// �������
		MOTIONTYPE_JUMP,		// �W�����v
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

	void SetLoad(D3DXVECTOR3 pos, D3DXVECTOR3 rot, int nIdxModel, int nType);


	D3DXVECTOR3 GetPos();
	D3DXVECTOR3 GetRot();
	D3DXVECTOR3 GetScale() { return m_scale; }

	struct MODELNUM
	{
		MODEL NumModel[MAX_MODEL];
		MOTION_INFO		aMotionInfo[MOTIONTYPE_MAX];// ���[�V�������
		MOTIONTYPE		motionType;					// ���݂̃��[�V����
		int nMaxModel;								// ���f����
		int nMotionMax;
	};

	void SetModel(MODELNUM model);
	CScene3D::MODELNUM GetModel();
protected:

	void BindModel(const MODELNUM *type);
	void BindMotion(const MOTION_INFO *type);

	void SetPosParts(MODELNUM *type);
	static std::string WordLoad(std::ifstream *file, std::string word, int linenum = 0);
	static void Vector3Load(std::string word,D3DXVECTOR3 *Vec3);

private:

	MODELNUM m_Model;						// �e�q�p�[�c

	LPDIRECT3DTEXTURE9 m_pTexturePolygon;

	D3DXVECTOR3 m_pos;						// �|���S���̈ʒu
	D3DXVECTOR3 m_rot;						// �|���S���̌���
	D3DXVECTOR3	m_scale;

	D3DXVECTOR3	m_move;						// �ړ���
	D3DXMATRIX  m_mtxWorld;					// ���[���h�}�g���b�N�X


	D3DXVECTOR3		m_vtxMin;				//�ŏ��l
	D3DXVECTOR3		m_vtxMax;				//�ő�l 
};

//====================================================================================================
// �}�N����`
//==================================================================================================== 
#endif