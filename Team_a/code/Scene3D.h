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
#define MAX_MODEL		(64)									// ���f���̐�
#define MAX_KEY		(8)									// ���f���̐�


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
		int nIdxModelModel;
		int nType;

		char cFileName[256];

	} MODEL;

	//=============================================================================
	// ���[�V�����̎��
	//=============================================================================
	typedef enum
	{
		MOTIONTYPE_NEUTRAL = 0,	// �j���[�g����
		MOTIONTYPE_RUNNING,		// �����j���O
		MOTIONTYPE_ACTION,		// �A�N�V����
		MOTIONTYPE_JUMP,		// �W�����v
		MOTIONTYPE_LAND,		// �����h
		MOTIONTYPE_BLOWAWAY,	// �������
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

	void SetLoad(D3DXVECTOR3 pos, D3DXVECTOR3 rot, int nIdxModelModel, int nType);


	D3DXVECTOR3 GetPos(void);
	D3DXVECTOR3 GetRot(void);

protected:

	struct MODELNUM
	{
		MODEL NumModel[MAX_MODEL];
		MOTION_INFO		aMotionInfo[MOTIONTYPE_MAX];// ���[�V�������
		MOTIONTYPE		motionType;					// ���݂̃��[�V����
		int nMaxModel;							// ���f����
		int nMotionMax;
	};
	void BindModel(const MODELNUM *type);
	void SetPosParts(MODELNUM *type);
	static std::string WordLoad(std::ifstream *file, std::string word);
	static void Vector3Load(std::string word,D3DXVECTOR3 *Vec3);

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