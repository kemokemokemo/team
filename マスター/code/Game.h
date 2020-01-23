//====================================================================================================
//
// �Q�[������ (Game.h)
// Author  Kimura Kouta
//
//====================================================================================================
#ifndef _GAME_H_
#define _GAME_H_

#define DIRECTINPUT_VERSION	(0x0800)
//====================================================================================================
//�C���N���[�h�t�@�C��
//====================================================================================================
#include"PlayerBase.h"
#include "SelectIcon.h"

class CManager;
class CRenderer;
class CCamera;
class CLight;
class CTime;
class CTexture;
class CNumber;
//================================================================
// �����_�����O�N���X
//================================================================
class CGame
{
public:

	// �v���g�^�C�v�錾
	CGame();
	~CGame();

	HRESULT Init(void);
	void Uninit(void);
	void Update(void);
	void Draw(void);

	static void SetPlayerType(CTexture *type[]);

	static CGame * Create();
	static void DeletePlayer(int cnt);

private:

	enum COUNTSTATE
	{
		COUNTSTATE_READY,
		COUNTSTATE_NORMAL
	};

	static CCamera*m_pCamera;
	static CLight*m_pLight;
	static CTime *pTime;

	static CPlayerBase::PLAYERTYPE m_PlayerType[];

	static CPlayerBase *m_Player[2];

	CNumber *m_Count;
	COUNTSTATE m_nCntState;
	int m_nCnt;
};
#endif