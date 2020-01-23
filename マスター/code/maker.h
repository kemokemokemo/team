//====================================================================================================
//
// マーカー処理 (maker.h)
// Author (Kimura kouta)
//
//====================================================================================================
#ifndef _MAKER_H_
#define _MAKER_H_

//====================================================================================================
//インクリードファイル
//====================================================================================================
#include"main.h"
#include"billboard.h"

#define MAX_TEXMAKER (2)	//読み込むテクスチャファイル名

class CPlayerBase;
//================================================================
// レンダリングクラス
//================================================================
class CMaker : public CBillboard
{
public:
	//=============================================================================
	// UIの種類
	//=============================================================================
	typedef enum
	{
		MAKERTYPE_1P = 0,
		MAKERTYPE_2P,
		MAKERTYPE_MAX
	} MAKERTYPE;

	//================================================================
	// プロトタイプ宣言
	//================================================================
	CMaker(OBJTYPE type);
	~CMaker();

	HRESULT Init(D3DXVECTOR3 pos, MAKERTYPE makertype, int life);
	void Uninit(void);
	void Update(void);
	void Draw(void);

	static CMaker *Create(D3DXVECTOR3 pos,MAKERTYPE makertype, int life);
	static HRESULT Load(void);
	static void Unload(void);


	void MakerLife(int nDamage);

	int GetMakerLife();


private:

	static LPDIRECT3DTEXTURE9 m_pTextureMaker[MAX_TEXMAKER];
	float Size;
	MAKERTYPE MakerType;
	int m_nLife;
};

//====================================================================================================
// マクロ定義
//==================================================================================================== 
#endif
