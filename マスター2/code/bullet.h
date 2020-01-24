//====================================================================================================
//
// 弾処理 (bullet.h)
// Author (Kimura kouta)
//
//====================================================================================================
#ifndef _BULLET_H_
#define _BULLET_H_

//====================================================================================================
//インクリードファイル
//====================================================================================================
#include"main.h"
#include"billboard.h"
#include"maker.h"

#define MAX_TEXBULLET (2)	//読み込むテクスチャファイル名
class CBullet;

//================================================================
// レンダリングクラス
//================================================================
class CBullet : public CBillboard
{
public:

	typedef enum
	{
		BULLETTEX_KEN = 0,
		BULLETTEX_KANGAROO,
		BULLETTEX_MAX,
	} BULLETTEX;

	//================================================================
	// プロトタイプ宣言
	//================================================================
	CBullet(OBJTYPE type);
	~CBullet();

	HRESULT Init(D3DXVECTOR3 pos, D3DXVECTOR3 move, BULLETTEX BulletTex, CMaker::MAKERTYPE makertype,int nLife);
	void Uninit(void);
	void Update(void);
	void Draw(void);

	void SetMove(D3DXVECTOR3 move);
	int GetLife();

	static CBullet *Create(D3DXVECTOR3 pos, D3DXVECTOR3 move, BULLETTEX BulletTex, CMaker::MAKERTYPE makertype,int nLife);
	static HRESULT Load(void);
	static void Unload(void);
	void PlayerCollision();


private:

	static LPDIRECT3DTEXTURE9 m_pTextureBullet[MAX_TEXBULLET];
	D3DXVECTOR3 m_move;
	D3DXVECTOR3 m_pos;
	float Size;
	int m_nLife;
	int m_nBulletDamage;
	BULLETTEX m_BulletTex;
	CMaker::MAKERTYPE m_MakerType;
};

//====================================================================================================
// マクロ定義
//==================================================================================================== 
#endif
