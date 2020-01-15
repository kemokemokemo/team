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

	static void SetPlayerType(CSelectIcon *type);

	static CGame * Create();

private:

	static CManager*m_pManager;
	static CCamera*m_pCamera;
	static CLight*m_pLight;

	static CPlayerBase::PLAYERTYPE m_PlayerType[3];
};
#endif