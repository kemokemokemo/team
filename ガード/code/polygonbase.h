//====================================================================================================
//
// �|���S������ (Polygonbase.h)
// Author KOUTA KIMURA
//
//====================================================================================================
#ifndef _POLYGONBASE_H_
#define _POLYGONBASE_H_

//====================================================================================================
//�C���N���[�h�t�@�C��
//====================================================================================================
#include"main.h"
#include"Scene.h"

//====================================================================================================
// �}�N����`
//==================================================================================================== 

//================================================================
// �����_�����O�N���X
//================================================================
class CPolygonBase : public CScene
{
public:
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
		MOTIONTYPE_UPATK,		// ��U��
		MOTIONTYPE_CROUCHATK,	// ���Ⴊ�ݍU��
		MOTIONTYPE_CROUCHWAIT,	// ���Ⴊ�ݒ�
		MOTIONTYPE_DAMAGE,		// �_���[�W
		MOTIONTYPE_JUMP,		// ��
		MOTIONTYPE_DOUBLEJUMP,	// ��i�W�����v
		MOTIONTYPE_RAND,		// ���n
		MOTIONTYPE_AIR_N,		// �󒆃j���[�g����
		MOTIONTYPE_AIR_F,		// �󒆑O
		MOTIONTYPE_AIR_B,		// �󒆌��
		MOTIONTYPE_AIR_U,		// �󒆏�
		MOTIONTYPE_AIR_D,		// �󒆉�
		MOTIONTYPE_SP_N,		// ����j���[�g����
		MOTIONTYPE_SP_UP,		// �����
		MOTIONTYPE_SP_DOWN,		// ���ꉺ
		MOTIONTYPE_GAUDE,		// �K�[�h
		MOTIONTYPE_MAX			// ���[�V�����̍ő吔
	} MOTIONTYPE;

	//================================================================
	// �v���g�^�C�v�錾
	//================================================================
	CPolygonBase(OBJTYPE nPriority);
	~CPolygonBase();

	HRESULT Init(void);
	void Uninit(void);
	void Update(void);
	void Draw(void);

private:
	LPDIRECT3DTEXTURE9 m_pTexturePolygon;
	LPDIRECT3DVERTEXBUFFER9 m_pVtxBuffScene;
	D3DXMATRIX m_mtxWorldPolygon;
	D3DXVECTOR3 m_rotPolygon;
	D3DXVECTOR3 m_PosPolygon;
	D3DXVECTOR3 m_pos;
};

//====================================================================================================
// �}�N����`
//==================================================================================================== 
#endif