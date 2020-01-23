//====================================================================================================
//
// �����_�����O���� (renderer.h)
// Author (Kimura kouta)
//
//====================================================================================================
#ifndef _RENDERER_H_
#define _RENDERER_H_

//====================================================================================================
//�C���N���[�h�t�@�C��
//====================================================================================================
#include"main.h"
#include"manager.h"
#include"fade.h"
//====================================================================================================
//�\���̒�`
//=====================================================================================================
class CCamera;

//================================================================
// �����_�����O�N���X
//================================================================
class CRenderer
{
public:

	// �v���g�^�C�v�錾
	CRenderer();
	~CRenderer();

	HRESULT Init(HWND hWnd, BOOL bWindow);
	void Uninit(void);
	void Update(void);
	void Draw(void);
	LPDIRECT3DDEVICE9 GetDevice(void);

#ifdef _DEBUG

	void DrawFPS(void);
#endif

private:

	LPDIRECT3D9 m_pD3D;
	LPDIRECT3DDEVICE9 m_pD3DDevice;
	DWORD dwCurrentTime;

	DWORD dwExeclastTime;

	DWORD dwFrameCount;

	DWORD dwFPSLastTime;

	CManager::MODE m_aManager;

	CFade *m_pFade;
	static CCamera*m_pCamera;
#ifdef _DEBUG
	LPD3DXFONT			m_pFont = NULL;			// �t�H���g�ւ̃|�C���^
	int					m_nCountFPS = 0;		// FPS�J�E���^
	int					m_FPS = 0;		// FPS�J�E���^
#endif
};


//====================================================================================================
// �}�N����`
//==================================================================================================== 
#endif