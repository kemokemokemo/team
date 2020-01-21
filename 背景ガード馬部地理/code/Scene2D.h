//====================================================================================================
//
// レンダリング処理 (Scene.h)
// Author (Kimura kouta)
//
//====================================================================================================
#ifndef _SCENE2D_H_
#define _SCENE2D_H_

//====================================================================================================
//インクリードファイル
//====================================================================================================
#include"main.h"
#include"Scene.h"

//====================================================================================================
// マクロ定義
//==================================================================================================== 



//================================================================
// レンダリングクラス
//================================================================
class CScene2D : public CScene
{
public:

	typedef enum
	{
		MODE_NORMAL = 0,
		MODE_BATTLE,
		MODE_MAX,
	} MODESTATE;

	//================================================================
	// プロトタイプ宣言
	//================================================================
	CScene2D(OBJTYPE nPriority);
	CScene2D();
	~CScene2D();

	HRESULT Init(void);
	void Uninit(void);
	void Update(void);
	void Draw(void);

	D3DXVECTOR3 GetPos(void);
	void SetPos(D3DXVECTOR3 pos);
	void SetSize(float Size_x, float Size_y);
	void SetColor(D3DXCOLOR Color);
	void SetSpeed(float tex);
	void UIUpdate(int nLife, float size_X, float size_Y);
	void TexMove();
	void SetTex(int nDigits);
	//void CollisionTest2();
	void SetModeState(MODESTATE mode);
	MODESTATE GetModeState(void);
	void BgUpdate();

	void BindTexture(LPDIRECT3DTEXTURE9 cName);
	void SetAnim(float fHeight, float fWidht,float fWidht2,int fChange);
	void SetInitTex(float fHeight, float fWidht);
	void SetRadius(float fRadius);


private:

	LPDIRECT3DTEXTURE9 m_pTexturePolygon;
	D3DXVECTOR3 m_pos = D3DXVECTOR3(0.0f,0.0f,0.0f);	//ポジション
	D3DXVECTOR3 m_posmove;
	D3DXVECTOR2 m_tex;
	float m_PosSize_X;
	float m_PosSize_Y;
	float m_Rot = D3DX_PI*0.25f;
	float m_CountRot = 0.0f;
	float m_RotRand = 0.0f;
	D3DXCOLOR m_Col = D3DXCOLOR(1.0f,1.0f,1.0f,1.0f);
	LPDIRECT3DVERTEXBUFFER9 m_pVtxBuffScene = NULL;		// 頂点バッファへのポインタ
	int m_nCounterAnim;
	int m_nPatternAnim;
	float m_TexMove;
	float m_Speed;
	float m_fHeight;
	float m_fWidht;
	float m_fWidht2;
	MODESTATE m_ModeState;

};

//====================================================================================================
// マクロ定義
//==================================================================================================== 
#endif