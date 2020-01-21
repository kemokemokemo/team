//====================================================================================================
//
// ガード処理 (guard.h)
// Author (Kimura kouta)
//
//====================================================================================================
#ifndef _GUARD_H_
#define _GUARD_H_

//====================================================================================================
//インクリードファイル
//====================================================================================================
#include"main.h"
#include"Scene2D.h"
#include"player_ken.h"
#include"maker.h"


class CScene3D;

#define MAX_TEXGAUGE (1)	//読み込むテクスチャファイル名


//================================================================
// レンダリングクラス
//================================================================
class CGuard : public CBillboard
{
public:


	//================================================================
	// プロトタイプ宣言
	//================================================================
	CGuard(OBJTYPE type);
	~CGuard();

	HRESULT Init(D3DXVECTOR3 pos, int Life, CMaker::MAKERTYPE makertype);
	void Uninit(void);
	void Update(void);
	void Draw(void);

	static CGuard *Create(D3DXVECTOR3 pos, int Life, CMaker::MAKERTYPE makertype);
	static HRESULT Load(void);
	static void Unload(void);

	void GuardLife(int nDamage);


private:

	VERTEX_2D m_Vertex[4];
	static LPDIRECT3DTEXTURE9 m_pTextureGuard[1];
	D3DXVECTOR3 m_pos;
	CPlayer_KEN *pPlayer;
	CMaker::MAKERTYPE PlayerType;
	CMaker::MAKERTYPE Makertype;
	float Size;
	int m_nLife;
	int m_nLifeOld;
};

//====================================================================================================
// マクロ定義
//==================================================================================================== 
#endif
