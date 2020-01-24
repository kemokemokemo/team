//====================================================================================================
//
// ���C�� (main.cpp)
// Author (Kimura kouta)
//
//====================================================================================================
#include"main.h"
#include"manager.h"

//====================================================================================================
// �}�N����`
//==================================================================================================== 
#define CLASS_NAME	"WindowClass"    //�E�B���h�E�N���X�̖��O
#define WINDOW_NAME	"�łウ�鉤"//�L���v�V����

//================================================================
// �v���g�^�C�v�錾
//================================================================
LRESULT CALLBACK WindowsProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

//=====================================================================================================
// �O���[�o���ϐ�
//=====================================================================================================
#ifdef _DEBUG
LPD3DXFONT			m_pFont = NULL;			// �t�H���g�ւ̃|�C���^
int					m_nCountFPS = 0;		// FPS�J�E���^
#endif

//====================================================================================================
//  ���C���֐�
//====================================================================================================
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hInstaPer, LPSTR lpCnd, int nCandShow)
{
	RECT rect{ 0,0,SCREEN_WIDTH,SCREEN_HEIGHT };
		// �w�肳�ꂽ�N���C�A���g�̈���m�ۂ��邽�߂̌v�Z
	AdjustWindowRect(&rect, WS_OVERLAPPEDWINDOW, false);

	WNDCLASSEX wcex =
	{
		sizeof(WNDCLASSEX),					//WNDCLASSEX�̃������T�C�Y
		CS_CLASSDC,							//�\������E�B���h�E�̃X�^�C��������
		WindowsProc,						//�E�B���h�E�v���V�[�W���̃A�h���X���w��
		0,									//�ʒ�͎g�p���Ȃ��̂�0
		0,									//�ʒ�͎g�p���Ȃ��̂�0
		hInstance,							//windows�̈����̃C���v�b�g

		LoadIcon(NULL,IDI_APPLICATION),		//�^�X�N�o�[��
		LoadCursor(NULL,IDC_ARROW),			//�g�p�}�E�X�J�[�\���̐F����Q�ύX�Ȃ�
		(HBRUSH)(COLOR_WINDOW + 1),
		NULL,								//���j���[���w��
		CLASS_NAME,							//�E�B���h�E�N���X�̖��O
		LoadIcon(NULL,IDI_APPLICATION)		//�������A�C�R���̑[��Q������\������


	};
	HWND hwnd;
	MSG msg;
	DWORD dwCurrentTime;//
	DWORD dwExeclastTime;//

	DWORD dwFrameCount;
	DWORD dwFPSLastTime;

		//�E�B���h�E�N���X�̓o�^
		RegisterClassEx(&wcex);

		//�E�B���h�E�N���X�̓o�^
		hwnd = CreateWindowEx(0,
			CLASS_NAME,						//�E�B���h�E�N���X��
			WINDOW_NAME,					//�E�B���h�E�̖��O
			WS_OVERLAPPEDWINDOW,			//�E�B���h�E�X�^�C��
			CW_USEDEFAULT,					//�E�B���h�E�̍���X��_�ύX�̉\������
			CW_USEDEFAULT,					//�E�B���h�E�̍���Y��_�ύX�̉\������
			(rect.right - rect.left),			//�E�B���h�E�̕�
			(rect.bottom - rect.top),			//�E�B���h�E�̍���
			NULL,							//�e�E�B���h�E�̃n���h��
			NULL,							//���j���[�n���h���܂��͎q�E�B���h�E
			hInstance,					    //�C���X�^���X�n���h��
			NULL);						    //�E�B���h�E�쐬�f�[�^

		CManager*pManager;

		pManager = new CManager;

	//����������
	if (FAILED(pManager->Init(hInstance,hwnd, FALSE)))
	{
		return-1;
	}


	//�E�B���h�E�̕\��
	ShowWindow(hwnd, nCandShow);		//�w�肳�ꂽ�E�B���h�E�̕\���ݒ�
	UpdateWindow(hwnd);					//�E�B���h�E�̃N���C�A���g�̈�X�V

										//���b�Z�[�W���[�v(���b�Z�[�W�L���[���烁�b�Z�[�W���擾)
	dwCurrentTime = 0;
	dwExeclastTime = timeGetTime();

	dwFrameCount = 0;
	dwFPSLastTime = timeGetTime();		// �V�X�e���������~���b�P�ʂŎ擾

	//���b�Z�[�W���[�v
	while (1)
	{//���b�Z�[�W���擾���Ȃ�������0��Ԃ�
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE) != 0)
		{//Window����
			if (msg.message == WM_QUIT)
			{//WM_QUIT���b�Z�[�W�������Ă���ƏI��
				break;
			}
			else
			{//���b�Z�[�W�̖|��
				TranslateMessage(&msg);
				DispatchMessage(&msg);
			}
		}
		else
		{//Directx�̏���
			dwCurrentTime = timeGetTime();
			dwCurrentTime = timeGetTime();		// �V�X�e���������擾

			if ((dwCurrentTime - dwFPSLastTime) >= 500)	// 0.5�b���ƂɎ��s
			{
#ifdef _DEBUG
				m_nCountFPS = (dwFrameCount * 1000) / (dwCurrentTime - dwFPSLastTime);		// FPS�𑪒�
#endif

				dwFPSLastTime = dwCurrentTime;		// FPS�𑪒肵��������ۑ�
				dwFrameCount = 0;					// �J�E���g���N���A
			}
			if ((dwCurrentTime - dwExeclastTime) >= (1000 / 60))
			{
				dwExeclastTime = dwCurrentTime;

				//�X�V����
				pManager->Update();
				//�`�揈��
				pManager->Draw();

				dwFrameCount++;			// �J�E���g�����Z
			}
		}
	}

	//�I������
	if (pManager != NULL)
	{
		pManager->Uninit();
		delete pManager;
		pManager = NULL;
	}

	//�E�B���h�E�N���X�̓o�^����
	UnregisterClass(CLASS_NAME, wcex.hInstance);

	return(int)msg.wParam;
}

//===========================================================================================
//�E�B���h�E�v���V�[�W���[�֐�
//===========================================================================================
LRESULT CALLBACK WindowsProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch (uMsg)
	{
	case WM_DESTROY:			  //�E�B���h�E�m�����b�Z�[�W
								  //�E�B���h�E��j��(WM_DESTROY���b�Z�[�W�̔���)
		PostQuitMessage(0);		  //���鏈��
		break;

	case WM_KEYDOWN:			  //�L�[�������ꂽ�ۂ̃��b�Z�[�W�\��
		switch (wParam)
		{
		case VK_ESCAPE:
			DestroyWindow(hWnd);  //[ESC]�L�[�������ꂽ�ۂ̃��b�Z�[�W�\��
			break;
		}
		break;
	case WM_CLOSE:

		DestroyWindow(hWnd);	  //[ESC]�L�[�������ꂽ�ۂ̃��b�Z�[�W�\��
		break;
	default:
		break;
	}
	return DefWindowProc(hWnd, uMsg, wParam, lParam);
}

#ifdef _DEBUG
int GetFPS()
{
	return m_nCountFPS;
}
#endif
