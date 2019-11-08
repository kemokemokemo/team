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

	//================================================================
	// プロトタイプ宣言
	//================================================================
	CScene2D(OBJTYPE nPriority);
	CScene2D();
	~CScene2D();

	HRESULT Init(void);			//初期化
	void Uninit(void);			//終了
	void Update(void);			//更新
	void Draw(void);			//描画

	D3DXVECTOR3 GetPos(void);	//ポジションの取得

	void UIUpdate(int nLife,int size); //ゲージの処理

	void SetPos(D3DXVECTOR3 pos);											//ポジションの設定
	void SetColor(D3DXCOLOR Color);											//色の設定
	void SetSize(float Size_x, float Size_y);								//大きさの設定
	void SetTex(int nDigits);												//テクスチャの設定
	void SetAnim(float fHeight, float fWidht, float fWidht2, int fChange);	//アニメーションの設定

	void BindTexture(LPDIRECT3DTEXTURE9 cName);	//テクスチャの設定

private:

	VERTEX_2D m_Vertex[4];

	LPDIRECT3DVERTEXBUFFER9 m_pVtxBuffScene;		// 頂点バッファへのポインタ
	LPDIRECT3DTEXTURE9 m_pTexturePolygon;

	D3DXVECTOR3 m_pos;		//ポジション
	D3DXCOLOR m_Col;		//色

	int m_nCounterAnim;		//アニメーションカウント
	int m_nPatternAnim;		//アニメーションパターン

	float m_PosSize_X;
	float m_PosSize_Y;
	float m_fHeight;
	float m_fWidht;
	float m_fWidht2;
};

//====================================================================================================
// マクロ定義
//==================================================================================================== 
#endif