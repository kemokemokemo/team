//=============================================================================
//
// �T�E���h���� [sound.h]
// Author : tanaka rikiya
//
//=============================================================================
#ifndef _SOUND_H_
#define _SOUND_H_

//=============================================================================
//�C���N���[�h
//=============================================================================
#include "main.h"

//=============================================================================
//�T�E���h�̃N���X
//=============================================================================
class CSound
{
public:
	//=============================================================================
	//�T�E���h�t�@�C��
	//=============================================================================
	typedef enum
	{
		SOUND_LABEL_TITLE = 0,		// BGM�^�C�g��	
		SOUND_LABEL_BATTLE,			// BGM�퓬		
		SOUND_LABEL_VICTORY,		// BGM���U���g
		SOUND_LABEL_SE_ATK,			// �U��			
		SOUND_LABEL_MAX,
	} SOUND_LABEL;
	//=============================================================================
	//�p�����[�^�\���̒�`
	//=============================================================================
	typedef struct
	{
		char *pFilename;	// �t�@�C����
		int nCntLoop;		// ���[�v�J�E���g
	} SOUNDPARAM;

	// �e���f�ނ̃p�����[�^
	SOUNDPARAM m_aParam[SOUND_LABEL_MAX] =
	{
		{ "DATA/BGM/bgm000.wav", -1 },		// BGM0(-1�ŌJ��Ԃ��j
		{ "DATA/BGM/bgm001.wav", -1 },		// BGM1
		{ "DATA/BGM/bgm001.wav", -1 },	// BGM2
		{ "DATA/SE/punch-high1.wav", 0 },	// ���j
	};

	HRESULT InitSound(HWND hWnd);
	void UninitSound(void);

	HRESULT PlaySound(SOUND_LABEL label);
	void StopSound(SOUND_LABEL label);
	void StopSound(void);

private:
	HRESULT CheckChunk(HANDLE hFile, DWORD format, DWORD *pChunkSize, DWORD *pChunkDataPosition);
	HRESULT ReadChunkData(HANDLE hFile, void *pBuffer, DWORD dwBuffersize, DWORD dwBufferoffset);

	IXAudio2 *m_pXAudio2 = NULL;								// XAudio2�I�u�W�F�N�g�ւ̃C���^�[�t�F�C�X
	IXAudio2MasteringVoice *m_pMasteringVoice = NULL;			// �}�X�^�[�{�C�X
	IXAudio2SourceVoice *m_apSourceVoice[SOUND_LABEL_MAX] = {};	// �\�[�X�{�C�X
	BYTE *m_apDataAudio[SOUND_LABEL_MAX] = {};					// �I�[�f�B�I�f�[�^
	DWORD m_aSizeAudio[SOUND_LABEL_MAX] = {};					// �I�[�f�B�I�f�[�^�T�C�Y
};
#endif
