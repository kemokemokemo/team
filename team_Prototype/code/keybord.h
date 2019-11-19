//=============================================================================
//
// �L�[�{�[�h���� [keybord.h]
// Author :  Kimura Kouta
//
//=============================================================================
#ifndef _KEYBORD_H_
#define _KEYBORD_H_


//=============================================================================
// �C���N���[�h�t�@�C��
//=============================================================================
#include "main.h"
#include "input.h"

//=============================================================================
// �}�N����`
//=============================================================================
#define	NUM_KEY_MAX			(256)	// �L�[�̍ő吔

//================================================================
// �����_�����O�N���X
//================================================================
class CKeybord : public CInput
{
public:

	// �v���g�^�C�v�錾
	CKeybord();
	~CKeybord();

	HRESULT Init(HINSTANCE hInstance, HWND hWnd);
	void Uninit(void);
	void Update(void);
	bool GetKeyboardPress(int nKey);
	bool GetKeyboardTrigger(int nKey);

private:

	BYTE m_aKeyState[NUM_KEY_MAX] = {};
	BYTE m_aKeystateTrigger[NUM_KEY_MAX] = {};
};


#endif