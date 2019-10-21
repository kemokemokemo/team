//====================================================================================================
//
// �����_�����O (renderer.cpp)
// Author (Kimura kouta)
//
//====================================================================================================
#include "renderer.h"	//�C���N���[�h�t�@�C��
#include "Scene.h"
#include "camera.h"

//====================================================================================================
// �}�N����`
//==================================================================================================== 

//====================================================================================================
// �v���g�^�C�v�錾
//====================================================================================================

//====================================================================================================
// �O���[�o���ϐ�
//====================================================================================================
CCamera*CRenderer::m_pCamera = NULL;

//====================================================================================================
// �R���X�g���N�^
//====================================================================================================
CRenderer::CRenderer()
{
	LPDIRECT3D9 m_pD3D = NULL;
	LPDIRECT3DDEVICE9 m_pD3DDevice = NULL;
	dwCurrentTime = 0;

	dwFrameCount = 0;
}

//=============================================================================
// ����������
//=============================================================================
HRESULT CRenderer::Init(HWND hWnd, BOOL bWindow)
{
	D3DDISPLAYMODE d3ddm;			// �f�B�X�v���C���[�h
	D3DPRESENT_PARAMETERS d3dpp;	// �v���[���e�[�V�����p�����[�^

	m_pFade = new CFade;

	// Direct3D�I�u�W�F�N�g�̐���
	m_pD3D = Direct3DCreate9(D3D_SDK_VERSION);
	if (m_pD3D == NULL)
	{
		return E_FAIL;
	}

	// ���݂̃f�B�X�v���C���[�h���擾
	if (FAILED(m_pD3D->GetAdapterDisplayMode(D3DADAPTER_DEFAULT, &d3ddm)))
	{
		return E_FAIL;
	}

	// �f�o�C�X�̃v���[���e�[�V�����p�����[�^�̐ݒ�
	ZeroMemory(&d3dpp, sizeof(d3dpp));							// ���[�N���[���N���A
	d3dpp.BackBufferWidth = SCREEN_WIDTH;						// �Q�[����ʃT�C�Y(��)
	d3dpp.BackBufferHeight = SCREEN_HEIGHT;						// �Q�[����ʃT�C�Y(����)
	d3dpp.BackBufferFormat = d3ddm.Format;						// �o�b�N�o�b�t�@�̌`��
	d3dpp.BackBufferCount = 1;									// �o�b�N�o�b�t�@�̐�
	d3dpp.SwapEffect = D3DSWAPEFFECT_DISCARD;					// �_�u���o�b�t�@�̐؂�ւ�(�f���M���ɓ���)
	d3dpp.EnableAutoDepthStencil = TRUE;						// �f�v�X�o�b�t�@(�y�o�b�t�@)�ƃX�e���V���o�b�t�@���쐬
	d3dpp.AutoDepthStencilFormat = D3DFMT_D16;					// �f�v�X�o�b�t�@�Ƃ���16bit���g��
	d3dpp.Windowed = bWindow;									// �E�B���h�E���[�h
	d3dpp.FullScreen_RefreshRateInHz = D3DPRESENT_RATE_DEFAULT;	// ���t���b�V�����[�g(���݂̑��x�ɍ��킹��)
	d3dpp.PresentationInterval = D3DPRESENT_INTERVAL_DEFAULT;	// �C���^�[�o��(VSync��҂��ĕ`��)
	d3dpp.PresentationInterval = D3DPRESENT_INTERVAL_IMMEDIATE;	// �N���C�A���g�̈�𒼂��ɍX�V����Q�����Ȃ�														//	d3dpp.PresentationInterval = D3DPRESENT_INTERVAL_IMMEDIATE;	// �N���C�A���g�̈�𒼂��ɍX�V����

																// Direct3D�f�o�C�X�̐���
																// [�f�o�C�X�쐬����]<�`��>��<���_����>���n�[�h�E�F�A�ōs�Ȃ�
	if (FAILED(m_pD3D->CreateDevice(D3DADAPTER_DEFAULT,			// �f�B�X�v���C�A�_�v�^
		D3DDEVTYPE_HAL,											// �f�o�C�X�^�C�v
		hWnd,													// �t�H�[�J�X����E�C���h�E�ւ̃n���h��
		D3DCREATE_HARDWARE_VERTEXPROCESSING,					// �f�o�C�X�쐬����̑g�ݍ��킹
		&d3dpp,													// �f�o�C�X�̃v���[���e�[�V�����p�����[�^
		&m_pD3DDevice)))										// �f�o�C�X�C���^�[�t�F�[�X�ւ̃|�C���^
	{
		// ��L�̐ݒ肪���s������
		// [�f�o�C�X�쐬����]<�`��>���n�[�h�E�F�A�ōs���A<���_����>��CPU�ōs�Ȃ�
		if (FAILED(m_pD3D->CreateDevice(D3DADAPTER_DEFAULT,
			D3DDEVTYPE_HAL,
			hWnd,
			D3DCREATE_SOFTWARE_VERTEXPROCESSING,
			&d3dpp,
			&m_pD3DDevice)))
		{
			// ��L�̐ݒ肪���s������
			// [�f�o�C�X�쐬����]<�`��>��<���_����>��CPU�ōs�Ȃ�
			if (FAILED(m_pD3D->CreateDevice(D3DADAPTER_DEFAULT,
				D3DDEVTYPE_REF,
				hWnd,
				D3DCREATE_SOFTWARE_VERTEXPROCESSING,
				&d3dpp,
				&m_pD3DDevice)))
			{
				// ���������s
				return E_FAIL;
			}
		}
	}		

	//=====================================================================================================
	//�����_���[�X�e�[�g�p�����[�^�̐ݒ�
	//=====================================================================================================
	m_pD3DDevice->SetRenderState(D3DRS_CULLMODE, D3DCULL_CCW);				//�J�����O�ݒ�(���A�\�����߂鏈��)

	m_pD3DDevice->SetRenderState(D3DRS_ALPHABLENDENABLE, TRUE);				//�A���t�@�u�����h���s��
	m_pD3DDevice->SetRenderState(D3DRS_SRCBLEND, D3DBLEND_SRCALPHA);
	m_pD3DDevice->SetRenderState(D3DRS_DESTBLEND, D3DBLEND_INVSRCALPHA);

	// �e�N�X�`���X�e�[�W�X�e�[�g�p�����[�^�̐ݒ�
	m_pD3DDevice->SetTextureStageState(0, D3DTSS_ALPHAOP, D3DTOP_MODULATE);
	m_pD3DDevice->SetTextureStageState(0, D3DTSS_ALPHAARG1, D3DTA_TEXTURE);
	m_pD3DDevice->SetTextureStageState(0, D3DTSS_ALPHAARG2, D3DTA_CURRENT);

#ifdef _DEBUG
	// �f�o�b�O�\���p�t�H���g��ݒ�
	D3DXCreateFont(m_pD3DDevice, 18, 0, 0, 0, FALSE, SHIFTJIS_CHARSET,
		OUT_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH, "�l�r �S�V�b�N", &m_pFont);
#endif

	m_pFade->InitFade();
	m_pCamera = CCamera::Create();
	return S_OK;
}
//==================================================================================================
//�I������
//===================================================================================================
void CRenderer::Uninit(void)
{	

#ifdef _DEBUG
	if (m_pFont != NULL)
	{// �f�o�b�O�\���p�t�H���g�̊J��
		m_pFont->Release();
		m_pFont = NULL;
	}
#endif
	m_pFade->UninitFade();
	m_pCamera->Uninit();
	CScene::ReleaseAll();
}

//====================================================================================================
//�X�V����
//=====================================================================================================
void CRenderer::Update(void)
{
	m_pFade->UpdateFade();
	m_pCamera->Update();
	CScene::UpdateAll();
}

//========================================================================================================
//�`�揈��
//========================================================================================================
void CRenderer::Draw(void)
{

	m_pD3DDevice->Clear(0, NULL,
		(D3DCLEAR_TARGET | D3DCLEAR_ZBUFFER),
		D3DCOLOR_RGBA(0, 0, 0, 0), 1.0f, 255);

	if (SUCCEEDED(m_pD3DDevice->BeginScene()))
	{//Direct3D�ɂ��`��J�n

	CCamera::SetCamera();

	CScene::DrawAll();

#ifdef _DEBUG
	// FPS�\��
	DrawFPS();
#endif

	}
	m_pFade->DrawFade();

	//�o�b�N�o�b�t�@&Z�o�b�t�@�̃N���A
	m_pD3DDevice->EndScene();

	//�o�b�N�o�b�t�@�ƃt�����g�o�b�t�@�̓���ւ�
	m_pD3DDevice->Present(NULL, NULL, NULL, NULL);
}

//=============================================================================
// ����
//=============================================================================
LPDIRECT3DDEVICE9 CRenderer::GetDevice(void)
{
	return m_pD3DDevice;
}

//=============================================================================
// FPS�\������
//=============================================================================
#ifdef _DEBUG
void CRenderer::DrawFPS(void)
{
	RECT rect = { 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT };
	char aStr[256];

	m_nCountFPS = GetFPS();		// FPS�J�E���^

	sprintf(&aStr[0], "FPS:%d\n", m_nCountFPS);

	// �e�L�X�g�`��
	m_pFont->DrawText(NULL, &aStr[0], -1, &rect, DT_LEFT, D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f));
}
#endif

//====================================================================================================
// �f�X�g���N�^
//=====================================================================================================
CRenderer::~CRenderer()
{

}