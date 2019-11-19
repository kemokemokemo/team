//====================================================================================================
//
// ���͏��� (input.cpp)
// Author (Kimura kouta)
//
//====================================================================================================
#include "input.h"
#include "keybord.h"

//====================================================================================================
// �}�N����`
//==================================================================================================== 

//====================================================================================================
// �v���g�^�C�v�錾
//====================================================================================================

//====================================================================================================
// �����o�ϐ�
//====================================================================================================
LPDIRECTINPUT8 CInput::m_pInput = NULL;

//====================================================================================================
// �R���X�g���N�^
//====================================================================================================
CInput::CInput()
{

}

HRESULT CInput::Init(HINSTANCE hInstance, HWND hWnd)
{
	// DirectInput�I�u�W�F�N�g�̍쐬
	if (FAILED(DirectInput8Create(hInstance, DIRECTINPUT_VERSION, IID_IDirectInput8, (void**)&m_pInput, NULL)))
	{
		return E_FAIL;
	}

	// ���̓f�o�C�X�i�L�[�{�[�h�j�̍쐬
	if (FAILED(m_pInput->CreateDevice(GUID_SysKeyboard, &m_pDevKeyboard, NULL)))
	{
		return E_FAIL;
	}

	// �f�[�^�t�H�[�}�b�g��ݒ�
	if (FAILED(m_pDevKeyboard->SetDataFormat(&c_dfDIKeyboard)))
	{
		return E_FAIL;
	}

	// �������[�h��ݒ�i�t�H�A�O���E���h����r�����[�h�j
	if (FAILED(m_pDevKeyboard->SetCooperativeLevel(hWnd, (DISCL_FOREGROUND | DISCL_NONEXCLUSIVE))))
	{
		return E_FAIL;
	}

	// �L�[�{�[�h�ւ̃A�N�Z�X�����l��(���͐���J�n)
	m_pDevKeyboard->Acquire();

	return S_OK;
}

void CInput::Uninit(void)
{
	// ���̓f�o�C�X(�L�[�{�[�h)�̊J��
	if (m_pDevKeyboard != NULL)
	{
		m_pDevKeyboard->Unacquire();
		m_pDevKeyboard->Release();
		m_pDevKeyboard = NULL;
	}

	// DirectInput�I�u�W�F�N�g�̊J��
	if (m_pInput != NULL)
	{
		m_pInput->Release();
		m_pInput = NULL;
	}
}

//====================================================================================================
// �C���v�b�g�̎擾
//====================================================================================================
LPDIRECTINPUT8 CInput::GetInput(void)
{
	return m_pInput;
}

//====================================================================================================
// �L�[�{�[�h�̎擾
//====================================================================================================
LPDIRECTINPUTDEVICE8 CInput::GetDevKeyboard(void)
{
	return m_pDevKeyboard;
}

//====================================================================================================
// �f�X�g���N�^
//====================================================================================================
CInput::~CInput()
{

}