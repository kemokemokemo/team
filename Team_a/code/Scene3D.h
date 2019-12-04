//====================================================================================================
//
// レンダリング処理 (Scene.h)
// Author KOUTA KIMURA
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
#define MAX_MODEL		(32)									// モデルの数
#define MAX_KEY			(10)									// キーの数


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
		LPDIRECT3DTEXTURE9	*pTexture;			// テクスチャへのポイント

		D3DXMATRIX mtxWorld;

		D3DXVECTOR3 startpos;							// ポリゴンの初期位置(オフセット値)
		D3DXVECTOR3 pos;								// ポリゴンの位置
		D3DXVECTOR3 rot;								// ポリゴンの向き
		int nIdxModel;
		int nType;

		char cFileName[256];

	} MODEL;

	//=============================================================================
	// モーションの種類
	//=============================================================================
	typedef enum
	{
		MOTIONTYPE_WAIT = 0,	// ニュートラル
		MOTIONTYPE_RUN,			// ランニング
		MOTIONTYPE_LIGHT0,		// 弱攻撃1段目
		MOTIONTYPE_LIGHT1,		// 2段目
		MOTIONTYPE_LIGHT2,		// 3段目
		MOTIONTYPE_DASHATK,		// ダッシュ攻撃
		MOTIONTYPE_UPATK,		// サマソ
		MOTIONTYPE_CROUCHATK,
		MOTIONTYPE_CROUCHWAIT,
		MOTIONTYPE_DAMAGE,	// 吹き飛ぶ
		MOTIONTYPE_JUMP,		// ジャンプ
		MOTIONTYPE_MAX			// モーションの最大数
	} MOTIONTYPE;

	typedef struct
	{// キー要素
		D3DXVECTOR3		pos;						// 現在の位置
		D3DXVECTOR3		rot;						// 向き(回転)
	} KEY;

	typedef struct
	{// キー情報
		int				nNumKyeFrame;				// キーフレーム数
		KEY				aKey[MAX_MODEL];			// キー要素
	} KEY_INFO;

	typedef struct
	{// モーション情報
		int				nCntFrame;					// 現在のフレーム数
		int				nNumKey;					// 現在のキー
		int				nMaxKey;					// 最大キー数
		bool			bLoop;						// ループするか
		KEY_INFO		aKeyInfo[MAX_KEY];			// キー情報
		int             nHitIdx;					// 攻撃の部位
		int				nAtkStar;
		int				nAtkEnd;
	} MOTION_INFO;

	//================================================================
	// プロトタイプ宣言
	//================================================================
	CScene3D(OBJTYPE nPriority);
	~CScene3D();

	HRESULT Init(void);
	void Uninit(void);
	void Update(void);
	void Draw(void);

	void Textureload(LPDIRECT3DDEVICE9 pDevice);

	bool ShapeCapsuleCollision(D3DXVECTOR3 *pPosStart, D3DXVECTOR3 *pPosEnd, float Radius, D3DXVECTOR3 *pPos);

	void SetPos(D3DXVECTOR3 pos);
	void SetRot(D3DXVECTOR3 rot);
	void SetScale(D3DXVECTOR3 scale) { m_scale = scale; }

	void SetLoad(D3DXVECTOR3 pos, D3DXVECTOR3 rot, int nIdxModel, int nType);


	D3DXVECTOR3 GetPos();
	D3DXVECTOR3 GetRot();
	D3DXVECTOR3 GetScale() { return m_scale; }

	struct MODELNUM
	{
		MODEL NumModel[MAX_MODEL];
		MOTION_INFO		aMotionInfo[MOTIONTYPE_MAX];// モーション情報
		MOTIONTYPE		motionType;					// 現在のモーション
		int nMaxModel;								// モデル数
		int nMotionMax;
	};

	void SetModel(MODELNUM model);
	CScene3D::MODELNUM GetModel();
protected:

	void BindModel(const MODELNUM *type);
	void BindMotion(const MOTION_INFO *type);

	void SetPosParts(MODELNUM *type);
	static std::string WordLoad(std::ifstream *file, std::string word, int linenum = 0);
	static void Vector3Load(std::string word,D3DXVECTOR3 *Vec3);

private:

	MODELNUM m_Model;						// 親子パーツ

	LPDIRECT3DTEXTURE9 m_pTexturePolygon;

	D3DXVECTOR3 m_pos;						// ポリゴンの位置
	D3DXVECTOR3 m_rot;						// ポリゴンの向き
	D3DXVECTOR3	m_scale;

	D3DXVECTOR3	m_move;						// 移動量
	D3DXMATRIX  m_mtxWorld;					// ワールドマトリックス


	D3DXVECTOR3		m_vtxMin;				//最小値
	D3DXVECTOR3		m_vtxMax;				//最大値 
};

//====================================================================================================
// マクロ定義
//==================================================================================================== 
#endif