//====================================================================================================
//
// �w�i���� (SelectionScreen.cpp)
// Author  Kimura Kouta
//
//====================================================================================================
#ifndef _SELECTIONSCREEN_H_
#define _SELECTIONSCREEN_H_

//====================================================================================================
//�C���N���[�h�t�@�C��
//====================================================================================================
#include"main.h"
#include"manager.h"
#include"SelectIcon.h"
#include "Texture.h"

class CLight;

//====================================================================================================
// �v���g�^�C�v�錾
//=====================================================================================================

//================================================================
// �����_�����O�N���X
//================================================================
class CSelectionScreen
{
public:

	// �v���g�^�C�v�錾
	CSelectionScreen();
	~CSelectionScreen();

	HRESULT Init(void);
	void Uninit(void);
	void Update(void);
	void Draw(void);

	static CSelectionScreen * Create();

private:

	static CManager*m_pManager;
	static CLight*m_pLight;

	CSelectIcon *m_pPlayerIcon[2];
	CTexture *pTexture[2] = {};
};
#endif