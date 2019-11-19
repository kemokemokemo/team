//====================================================================================================
//
// レンダリング処理 (Scene.h)
// Author (Kimura kouta)
//
//====================================================================================================
#ifndef _SCENE3D_H_
#define _SCENE3D_H_

//====================================================================================================
//インクリードファイル
//====================================================================================================
#include"main.h"
#include"Scene.h"

#include <sstream>
#include <fstream>

//====================================================================================================
// マクロ定義
//==================================================================================================== 
#define MAX_MODEL		(64)									// モデルの数

//================================================================
// レンダリングクラス
//================================================================
class CScene3D : public CScene
{
public:

	//=============================================================================
	// モデルの種類
	//=============================================================================
	typedef struct
	{
		DWORD nNumMat;							// マテリアル情報の数
		LPD3DXMESH pMesh;						// メッシュ情報へのポインタ
		LPD3DXBUFFER pBuffMat;					// マテリアル情報へのポインタ

		D3DXMATRIX mtxWorld;

		D3DXVECTOR3 startpos;							// ポリゴンの初期位置(オフセット値)
		D3DXVECTOR3 pos;								// ポリゴンの位置
		D3DXVECTOR3 rot;								// ポリゴンの向き
		int nIdxModelModel;

		char cFileName[256];

	} MODEL;

	//================================================================
	// プロトタイプ宣言
	//================================================================
	CScene3D(OBJTYPE nPriority);
	~CScene3D();

	HRESULT Init(void);
	void Uninit(void);
	void Update(void);
	void Draw(void);

	bool ShapeCapsuleCollision(D3DXVECTOR3 *pPosStart, D3DXVECTOR3 *pPosEnd, float Radius, D3DXVECTOR3 *pPos);

	void SetPos(D3DXVECTOR3 pos);
	void SetRot(D3DXVECTOR3 rot);

	D3DXVECTOR3 GetPos(void);
	D3DXVECTOR3 GetRot(void);
protected:

	struct MODELNUM
	{
		MODEL NumModel[MAX_MODEL];
		int nMaxModel;							// モデル数
	};
	void BindModel(const MODELNUM *type);
	static std::string WordLoad(std::ifstream *file, std::string word);

private:


	LPDIRECT3DTEXTURE9 m_pTexturePolygon;

	D3DXVECTOR3 m_pos;						// ポリゴンの位置
	D3DXVECTOR3 m_rot;						// ポリゴンの向き
	D3DXVECTOR3	m_move;						// 移動量
	D3DXMATRIX  m_mtxWorld;					// ワールドマトリックス

	MODELNUM m_Model;						// 親子パーツ

	//MODELNUM	m_type;						// 種類

	D3DXVECTOR3		m_vtxMin;				//最小値
	D3DXVECTOR3		m_vtxMax;				//最大値 

};

//====================================================================================================
// マクロ定義
//==================================================================================================== 
#endif