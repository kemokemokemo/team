//=============================================================================
//
// �t�F�[�h���� [fade.h]
// Author :KIMURA KOUTA
//
//=============================================================================
#ifndef _FADE_H_
#define _FADE_H_

#define _CRT_SECURE_NO_WARNINGS

//=============================================================================
// �C���N���[�h�t�@�C��
//=============================================================================
#include "main.h"
#include "manager.h"

//================================================================
// �����_�����O�N���X
//================================================================
class CFade
{
public:

	//=============================================================================
	// �t�F�[�h�̏��
	//=============================================================================
	typedef enum
	{
		FADE_NONE = 0,		// �����Ȃ����
		FADE_IN,			// �t�F�[�h�C������
		FADE_OUT,			// �t�F�[�h�A�E�g����
		FADE_MAX
	} FADE;

	//====================================================================================================
	// �\���̒�`
	//=====================================================================================================
	typedef struct
	{
		D3DXVECTOR3 pos;	//�|�W�V����
		float       rhw;	//1�ŌŒ肷��
		D3DCOLOR    col;	//�F
		D3DXVECTOR2 tex;	//�e�N�X�`�����
	}VERTEX_2D;

	//=============================================================================
	// �v���g�^�C�v�錾
	//=============================================================================
	void InitFade(void);
	void UninitFade(void);
	void UpdateFade(void);
	void DrawFade(void);

	static void SetFade(CManager::MODE modeNext);
	static FADE GetFade(void);
	CFade *Create(void);

private:

	LPDIRECT3DTEXTURE9		m_pTextureFade = NULL;		// �e�N�X�`���ւ̃|�C���^
	LPDIRECT3DVERTEXBUFFER9 m_pVtxBuffFade = NULL;		// ���_�o�b�t�@�ւ̃|�C���^
	static FADE				m_fade;						// �t�F�[�h���
	static CManager::MODE	m_modeNext;					// ���̉�ʁi���[�h�j
	static D3DXCOLOR		m_colorFade;				// �t�F�[�h�F

	int nCntDelay = 0;
};
#endif
