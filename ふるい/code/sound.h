//=============================================================================
//
// サウンド処理 [sound.h]
// Author : tanaka rikiya
//
//=============================================================================
#ifndef _SOUND_H_
#define _SOUND_H_

//=============================================================================
//インクルード
//=============================================================================
#include "main.h"

//=============================================================================
//サウンドのクラス
//=============================================================================
class CSound
{
public:
	//=============================================================================
	//サウンドファイル
	//=============================================================================
	typedef enum
	{
		SOUND_LABEL_TITLE = 0,		// BGMタイトル	
		SOUND_LABEL_BATTLE,			// BGM戦闘		
		SOUND_LABEL_VICTORY,		// BGMリザルト
		SOUND_LABEL_SE_ATK,			// 攻撃			
		SOUND_LABEL_MAX,
	} SOUND_LABEL;
	//=============================================================================
	//パラメータ構造体定義
	//=============================================================================
	typedef struct
	{
		char *pFilename;	// ファイル名
		int nCntLoop;		// ループカウント
	} SOUNDPARAM;

	// 各音素材のパラメータ
	SOUNDPARAM m_aParam[SOUND_LABEL_MAX] =
	{
		{ "DATA/BGM/bgm000.wav", -1 },		// BGM0(-1で繰り返し）
		{ "DATA/BGM/bgm001.wav", -1 },		// BGM1
		{ "DATA/BGM/bgm001.wav", -1 },	// BGM2
		{ "DATA/SE/punch-high1.wav", 0 },	// 撃破
	};

	HRESULT InitSound(HWND hWnd);
	void UninitSound(void);

	HRESULT PlaySound(SOUND_LABEL label);
	void StopSound(SOUND_LABEL label);
	void StopSound(void);

private:
	HRESULT CheckChunk(HANDLE hFile, DWORD format, DWORD *pChunkSize, DWORD *pChunkDataPosition);
	HRESULT ReadChunkData(HANDLE hFile, void *pBuffer, DWORD dwBuffersize, DWORD dwBufferoffset);

	IXAudio2 *m_pXAudio2 = NULL;								// XAudio2オブジェクトへのインターフェイス
	IXAudio2MasteringVoice *m_pMasteringVoice = NULL;			// マスターボイス
	IXAudio2SourceVoice *m_apSourceVoice[SOUND_LABEL_MAX] = {};	// ソースボイス
	BYTE *m_apDataAudio[SOUND_LABEL_MAX] = {};					// オーディオデータ
	DWORD m_aSizeAudio[SOUND_LABEL_MAX] = {};					// オーディオデータサイズ
};
#endif
