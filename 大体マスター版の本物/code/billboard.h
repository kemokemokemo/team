//====================================================================================================
//
// Billboard処理 (Billboard.h)
// Author KOUTA KIMURA
//
//====================================================================================================
#ifndef _BILLBOARD_H_
#define _BILLBOARD_H_

//====================================================================================================
//インクリードファイル
//====================================================================================================
#include"main.h"
#include"Scene3D.h"

//====================================================================================================
// マクロ定義
//==================================================================================================== 

//================================================================
// レンダリングクラス
//================================================================
class CBillboard : public CScene3D
{
public:

	//================================================================
	// プロトタイプ宣言
	//================================================================
	CBillboard(OBJTYPE nPriority);
	~CBillboard();

	HRESULT Init(void);
	void Uninit(void);
	void Update(void);
	void Draw(void);

	void BindTexture(LPDIRECT3DTEXTURE9 cName);
	D3DXVECTOR3 GetPos(void);
	void SetPos(D3DXVECTOR3 pos);
	void SetMove(D3DXVECTOR3 move);
	void SetColor(D3DXCOLOR color);
	void SetSize(float Size_x, float Size_y, float Size_z);
	void CBillboard::SetAnim(int fHeight, int fWidht, int fChange);

protected:

	D3DXVECTOR3 m_pos;
	D3DXVECTOR3 m_rot;
	D3DXVECTOR3 m_move;
	float m_size_x;
	float m_size_y;
	float m_size_z;

private:

	LPDIRECT3DTEXTURE9 m_pTextureBillBoard;
	LPDIRECT3DVERTEXBUFFER9 m_pVtxBuffBillBoard;
	D3DXMATRIX m_mtxWorldBillBoard;
	int m_nCounterAnim;
	int m_nPatternAnim;

	D3DXCOLOR m_Color;

};

//====================================================================================================
// マクロ定義
//==================================================================================================== 
#endif