//====================================================================================================
//
// アイコン処理 (SelectIcon.h)
// Author (Kimura kouta)
//
//====================================================================================================
#ifndef _TEXTURE_H_
#define _TEXTURE_H_

//====================================================================================================
//インクリードファイル
//====================================================================================================
#include"playerbase.h"
#include"scene2D.h"


//================================================================
// レンダリングクラス
//================================================================
class CTexture : public CScene2D
{
public:
	typedef enum
	{
		TYPE_BG,
		TYPE_LOGO,
		TYPE_ENTER,
		TYPE_START,
		TYPE_SELECT_BG,
		TYPE_SELECT1,
		TYPE_SELECT2,
		TYPE_LIFE1,
		TYPE_LIFE2,
		TYPE_TIME,
		TYPE_KENICON,
		TYPE_KANGAROOICON,
		TYPE_SWORDICON,
		TYPE_SELECTKENICON,
		TYPE_SELECTKANGAROOICON,
		TYPE_SELECTSWORDICON,
		TYPE_TITLEBG,
		TYPE_TITLELOG,
		TYPE_WIN1P,
		TYPE_WIN2P,
		TYPE_READY,
		TYPE_MAX
	}TEXTURE_TYPE;

	//================================================================
	// プロトタイプ宣言
	//================================================================
	CTexture(OBJTYPE type);
	~CTexture();

	HRESULT Init(TEXTURE_TYPE type);
	void Uninit(void);
	void Update(void);
	void Draw(void);

	static CTexture *Create(D3DXVECTOR3 pos, D3DXVECTOR3 move, D3DXCOLOR col, float Weight, float Height, TEXTURE_TYPE type);
	static HRESULT Load(void);
	static void Unload(void);

	void SetMove(D3DXVECTOR3 move) { m_move += move; }
	void SetType(CPlayerBase::PLAYERTYPE type) { m_PlayerType = type; }

	CPlayerBase::PLAYERTYPE GetType() { return m_PlayerType; }
private:

	static LPDIRECT3DTEXTURE9 m_pTextureIcon[];

	CPlayerBase::PLAYERTYPE m_PlayerType;

	TEXTURE_TYPE TexType;

	D3DXVECTOR3 m_move;
	float Size;
	int m_nLife;
};

//====================================================================================================
// マクロ定義
//==================================================================================================== 
#endif
