//=============================================================================
//
// �J�������� [camera.h]
// Author : 
//
//=============================================================================
#ifndef _CAMERA_H_
#define _CAMERA_H_

#define _CRT_SECURE_NO_WARNINGS

//=============================================================================
// �C���N���[�h�t�@�C��
//=============================================================================
#include "main.h"


//================================================================
// �����_�����O�N���X
//================================================================
class CCamera
{
public:

	//=============================================================================
	// �J�����̍\����
	//=============================================================================
	typedef struct
	{
		D3DXVECTOR3 posV;
		D3DXVECTOR3 posVDest;
		D3DXVECTOR3 posR;
		D3DXVECTOR3 posRDest;
		D3DXVECTOR3 vecU;
		D3DXVECTOR3 rot;
		D3DXVECTOR3 rotDest;
		D3DXMATRIX mtxProjection;
		D3DXMATRIX mtxView;

	}CAMERA;

	//=============================================================================
	// �v���g�^�C�v�錾
	//=============================================================================
	CCamera();
	~CCamera();

	static CCamera *Create();

	void Init(void);
	void Uninit(void);
	void Update(void);

	static void SetCamera(void);
	static CAMERA *GetCamera(void);

	static void SetCameraPos(D3DXVECTOR3 pos, D3DXVECTOR3 *dis);

private:

	static CAMERA m_Camera;
	float m_fDistance;

	int m_time;
};
#endif
