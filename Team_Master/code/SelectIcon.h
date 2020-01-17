//====================================================================================================
//
// �A�C�R������ (SelectIcon.h)
// Author (Kimura kouta)
//
//====================================================================================================
#ifndef _SELECTICON_H_
#define _SELECTICON_H_

//====================================================================================================
//�C���N���[�h�t�@�C��
//====================================================================================================
#include"playerbase.h"
#include"scene2D.h"


class CPlayerBase;
//================================================================
// �����_�����O�N���X
//================================================================
class CSelectIcon: public CScene2D
{
public:

	//=============================================================================
	// �\���̒�`
	//=============================================================================
	typedef enum
	{
		ICON_1P = 0,
		ICON_2P,
		ICON_3P,
		ICON_4P,
		ICON_MAX,
	} ICON;
	//================================================================
	// �v���g�^�C�v�錾
	//================================================================
	CSelectIcon(OBJTYPE type);
	~CSelectIcon();

	HRESULT Init(D3DXVECTOR3 pos);
	void Uninit(void);
	void Update(void);
	void Draw(void);

	static CSelectIcon *Create(D3DXVECTOR3 pos, ICON Icon);
	static HRESULT Load(void);
	static void Unload(void);

	void SetMove(D3DXVECTOR3 move) { m_move += move; }
	void SetType(CPlayerBase::PLAYERTYPE type) { m_PlayerType = type; }

	CPlayerBase::PLAYERTYPE GetType() { return m_PlayerType; }
private:

	static LPDIRECT3DTEXTURE9 m_pTextureIcon[];

	CPlayerBase::PLAYERTYPE m_PlayerType;

	D3DXVECTOR3 m_move;
	ICON m_Icon;
	float Size;
	int m_nLife;

};

//====================================================================================================
// �}�N����`
//==================================================================================================== 
#endif
