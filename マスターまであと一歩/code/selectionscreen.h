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

	CSelectIcon *m_pPlayerIcon[2];
	CTexture *m_pTexture[2] = {};

	CTexture *m_pTextureIcon[3];

	CTexture *m_Ready;
};
#endif