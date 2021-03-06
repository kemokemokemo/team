//====================================================================================================
//
// ゲージ処理 (gauge.h)
// Author (Kimura kouta)
//
//====================================================================================================
#ifndef _GAUGE_H_
#define _GAUGE_H_

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
class CGauge : public CScene2D
{
public:


	//================================================================
	// プロトタイプ宣言
	//================================================================
	CGauge(OBJTYPE type);
	CGauge();
	~CGauge();

	HRESULT Init(D3DXVECTOR3 pos, int Life, CMaker::MAKERTYPE MAKERTYPE);
	void Uninit(void);
	void Update(void);
	void Draw(void);

	static CGauge *Create(D3DXVECTOR3 pos, int Life, CMaker::MAKERTYPE MAKERTYPE);
	static HRESULT Load(void);
	static void Unload(void);

	void GaugeLife(int nDamage);


private:

	VERTEX_2D m_Vertex[4];
	static LPDIRECT3DTEXTURE9 m_pTextureGauge[MAX_TEXGAUGE];
	D3DXVECTOR3 m_pos;
	CPlayer_KEN *pPlayer;
	CMaker::MAKERTYPE PlayerType;
	float Size;
	int m_nLife;
};

//====================================================================================================
// マクロ定義
//==================================================================================================== 
#endif
