//====================================================================================================
//
// 3Dポリゴン処理 (Scene3D.cpp)
// Author KOUTA KIMURA
//
//====================================================================================================
#include "Scene3D.h"
#include "renderer.h"
#include "manager.h"
#include "keybord.h"
#include "Game.h"
#include "model.h"

//====================================================================================================
// プロトタイプ宣言
//====================================================================================================


//====================================================================================================
// メンバ変数初期化
//====================================================================================================

//====================================================================================================
// コンストラクタ
//====================================================================================================
CScene3D::CScene3D(OBJTYPE nPriority) : CScene(nPriority)
{

}

//=============================================================================
// 初期化処理
//=============================================================================
HRESULT CScene3D::Init(void)
{
	CRenderer *pRenderer = CManager::GetRenderer();
	LPDIRECT3DDEVICE9 pDevice = pRenderer->GetDevice();

	m_pos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	m_rot = D3DXVECTOR3(0.0f, 0.0f, 0.0f);

	// モデルの頂点数の最大値・最小値の設定
	int		nNumVertices;							// 頂点数
	DWORD	sizeFVF;								// 頂点フォーマットのサイズ
	BYTE	*pVertexBuffer;

	for (int nCntModel = 0; nCntModel < m_Model.nMaxModel; nCntModel++)
	{
		m_vtxMax = D3DXVECTOR3(-1000.0f, -1000.0f, -1000.0f);
		m_vtxMin = D3DXVECTOR3(1000.0f, 1000.0f, 1000.0f);

		// 頂点数を取得
		nNumVertices = m_Model.NumModel[nCntModel].pMesh->GetNumVertices();

		// 頂点フォーマットのサイズを取得
		sizeFVF = D3DXGetFVFVertexSize(m_Model.NumModel[nCntModel].pMesh->GetFVF());

		// 頂点バッファをロック
		m_Model.NumModel[nCntModel].pMesh->LockVertexBuffer(D3DLOCK_READONLY, (void**)&pVertexBuffer);

		for (int nCntVtx = 0; nCntVtx < nNumVertices; nCntVtx++)
		{
			D3DXVECTOR3 vtx = *(D3DXVECTOR3*)pVertexBuffer;

			// 全ての頂点情報を比較して最大値・最小値を抜き出す
			D3DXVec3Minimize(&m_Model.NumModel[nCntModel].vtxMin, &vtx, &m_Model.NumModel[nCntModel].vtxMin);
			D3DXVec3Maximize(&m_Model.NumModel[nCntModel].vtxMax, &vtx, &m_Model.NumModel[nCntModel].vtxMax);

			m_vtxMin = m_Model.NumModel[nCntModel].vtxMin; //最小値
			m_vtxMax = m_Model.NumModel[nCntModel].vtxMax; //最大値 

			m_scale = (m_Model.NumModel[nCntModel].vtxMax - m_Model.NumModel[nCntModel].vtxMin);

			pVertexBuffer += sizeFVF;//	サイズ分ポインタを進める
		}
		// アンロック
		m_Model.NumModel[nCntModel].pMesh->UnlockVertexBuffer();
	}

	Textureload(pDevice);

	return S_OK;
}

//==================================================================================================
// 終了処理
//===================================================================================================
void CScene3D::Uninit(void)
{

}

//====================================================================================================
//更新処理
//=====================================================================================================
void CScene3D::Update(void)
{

}

//========================================================================================================
// 描画処理
//========================================================================================================
void CScene3D::Draw(void)
{
	LPDIRECT3DDEVICE9 pDevice = CManager::GetRenderer()->GetDevice();

	D3DXMATRIX mtxRot, mtxTrans, mtxScale;				// 計算用マトリックス
	D3DXMATERIAL *pMat;							// 現在のマテリアル保存用
	D3DMATERIAL9 matDef;						// マテリアルデータへのポインタ
	D3DXMATRIX	mtxModel;						// 親のマトリックス

	// ワールドマトリックスの初期化
	D3DXMatrixIdentity(&m_mtxWorld);

	// 回転を反映
	D3DXMatrixRotationYawPitchRoll(&mtxRot, m_rot.y, m_rot.x, m_rot.z);
	D3DXMatrixMultiply(&m_mtxWorld, &m_mtxWorld, &mtxRot);

	// 位置を反映
	D3DXMatrixTranslation(&mtxTrans, m_pos.x, m_pos.y, m_pos.z);
	D3DXMatrixMultiply(&m_mtxWorld, &m_mtxWorld, &mtxTrans);

	// ワールドマトリックスの設定
	pDevice->SetTransform(D3DTS_WORLD, &m_mtxWorld);

	for (int nCntModel = 0; nCntModel < m_Model.nMaxModel; nCntModel++)
	{
		if (m_Model.NumModel[nCntModel].nIdxModel == -1)
		{
			mtxModel = m_mtxWorld;
		}
		else
		{
			mtxModel = m_Model.NumModel[m_Model.NumModel[nCntModel].nIdxModel].mtxWorld;
		}

		// ワールドマトリックスの初期化
		D3DXMatrixIdentity(&m_Model.NumModel[nCntModel].mtxWorld);

		// 回転を反映
		D3DXMatrixRotationYawPitchRoll(&mtxRot, m_Model.NumModel[nCntModel].rot.y, m_Model.NumModel[nCntModel].rot.x, m_Model.NumModel[nCntModel].rot.z);
		D3DXMatrixMultiply(&m_Model.NumModel[nCntModel].mtxWorld, &m_Model.NumModel[nCntModel].mtxWorld, &mtxRot);

		// 位置を反映
		D3DXMatrixTranslation(&mtxTrans, m_Model.NumModel[nCntModel].pos.x, m_Model.NumModel[nCntModel].pos.y, m_Model.NumModel[nCntModel].pos.z);
		D3DXMatrixMultiply(&m_Model.NumModel[nCntModel].mtxWorld, &m_Model.NumModel[nCntModel].mtxWorld, &mtxTrans);

		// 親モデルのマトリックスをかけ合わせる
		D3DXMatrixMultiply(&m_Model.NumModel[nCntModel].mtxWorld, &m_Model.NumModel[nCntModel].mtxWorld, &mtxModel);

		// ワールドマトリックスの設定
		pDevice->SetTransform(D3DTS_WORLD, &m_Model.NumModel[nCntModel].mtxWorld);

		// 現在のマテリアルを取得
		pDevice->GetMaterial(&matDef);

		// マテリアル情報に対するポインタを取得
		pMat = (D3DXMATERIAL*)m_Model.NumModel[nCntModel].pBuffMat->GetBufferPointer();

		for (int nCntMat = 0; nCntMat < (int)m_Model.NumModel[m_Model.NumModel[nCntModel].nType].nNumMat; nCntMat++)
		{
			// マテリアルの設定
			pDevice->SetMaterial(&pMat[nCntMat].MatD3D);

			// テクスチャの反映
			pDevice->SetTexture(0, m_Model.NumModel[m_Model.NumModel[nCntModel].nType].pTexture[nCntMat]);

			// 描画
			m_Model.NumModel[m_Model.NumModel[nCntModel].nType].pMesh->DrawSubset(nCntMat);
		}


		// マテリアルをデフォルトに戻す
		pDevice->SetMaterial(&matDef);
	}
}
//=============================================================================
// テクスチャの読み込み
//=============================================================================
void CScene3D::Textureload(LPDIRECT3DDEVICE9 pDevice)
{
	for (int nCount = 0; nCount <m_Model.nMaxModel; nCount++)
	{
		//テクスチャの読み込み
		D3DXMATERIAL *pMat;							// Xファイルから取り出したマテリアル情報を入れる

		// Xファイルからマテリアル情報を取得
		pMat = (D3DXMATERIAL*)m_Model.NumModel[nCount].pBuffMat->GetBufferPointer();

		// テクスチャのポインタをマテリアル情報の数分配列化
		m_Model.NumModel[nCount].pTexture = new LPDIRECT3DTEXTURE9[(int)m_Model.NumModel[nCount].nNumMat];	// int型に直す

		// 取得したファイル名を入力
		for (int nCntNumMat = 0; nCntNumMat < (int)m_Model.NumModel[nCount].nNumMat; nCntNumMat++)	// DWORD型からint型に変換する
		{
			// テクスチャのポインタ初期化
			m_Model.NumModel[nCount].pTexture[nCntNumMat] = NULL;

			// テクスチャファイル名が入っている場合、読み込む
			if (pMat[nCntNumMat].pTextureFilename != NULL)
			{
				D3DXCreateTextureFromFile(pDevice, pMat[nCntNumMat].pTextureFilename,
					&m_Model.NumModel[nCount].pTexture[nCntNumMat]);
			}
		}
	}

}

//====================================================================================================
// モデルの取得
//====================================================================================================
void CScene3D::BindModel(const MODELNUM *type)
{
	m_Model.nMaxModel = type->nMaxModel;

	m_Model = *type;
}

//void CScene3D::BindMotion(const MOTION_INFO * type)
//{
//	for (int nCnt = 0; nCnt < m_Model.nMotionMax; nCnt++)
//	{
//		m_Model.aMotionInfo[nCnt] = type[nCnt];
//	}
//}

//====================================================================================================
// キャラクター情報読み込み
//====================================================================================================
std::string CScene3D::WordLoad(std::ifstream *file, std::string word, int linenum)
{
	std::string sWord;
	std::string sLine;
	std::string sData = "-";
	std::stringstream sSeparate(sData);
	std::string s;
	int nCnt = 0;

	while (std::getline(*file, sLine))
	{
		// 文字列の操作（追加、取り出しなど）
		std::stringstream sString(sLine);
		std::string sName;
		sString >> sName;
		
		nCnt++;

		if (sName == word)
		{
			// ＝がなかったら
			if (sLine.find('=') == std::string::npos)
			{
				sWord = sName;
				break;
			}

			sString.ignore(sLine.size(), '=');

			sString >> sWord;

			if (word == "POS" || word == "ROT")
			{
				s += sData;
				s = sWord;
				s += sData;

				sSeparate >> sWord;
				sString >> sWord;
				s += sWord; // "abcd" (std::string型の文字列を追加)
				s += sData;

				sSeparate >> sWord;
				sString >> sWord;
				s += sWord; // "abcd" (std::string型の文字列を追加)
				sWord = s;
			}
			break;
		}
		else if (linenum != 0 && linenum == nCnt)
		{
			break;
		}
	}
	return sWord;
}

void CScene3D::Vector3Load(std::string word, D3DXVECTOR3 *Vec3)
{	
	float fVec;

	// 文字列の操作（追加、取り出しなど）
	std::stringstream sString(word);

	sString >> fVec;

	Vec3->x = fVec;

	sString.ignore(word.size(), '-');

	sString >> fVec;

	Vec3->y = fVec;

	sString.ignore(word.size(), '-');

	sString >> fVec;

	Vec3->z = fVec;
}

//====================================================================================================
// ポジションの取得
//====================================================================================================
D3DXVECTOR3 CScene3D::GetPos(void)
{
	return m_pos;
}

//====================================================================================================
// ポジションのセット
//====================================================================================================
void CScene3D::SetPos(D3DXVECTOR3 pos)
{
	m_pos = pos;
}

//====================================================================================================
// 回転量の取得
//====================================================================================================
D3DXVECTOR3 CScene3D::GetRot(void)
{
	return m_rot;
}

void CScene3D::SetModel(MODELNUM model)
{
	m_Model = model;
}

//====================================================================================================
// 回転量の取得
//====================================================================================================
CScene3D::MODELNUM CScene3D::GetModel()
{
	return m_Model;
}

//====================================================================================================
// 回転量のセット
//====================================================================================================
void CScene3D::SetRot(D3DXVECTOR3 rot)
{
	m_rot = rot;
}

//====================================================================================================
// パーツごとのポジション
//====================================================================================================
void CScene3D::SetPosParts(MODELNUM *type)
{
	for (int nCnt = 0; nCnt < m_Model.nMaxModel; nCnt++)
	{
		m_Model.NumModel[nCnt].pos = type->NumModel[nCnt].pos;
		m_Model.NumModel[nCnt].rot = type->NumModel[nCnt].rot;
	}
}

void CScene3D::SetLoad(D3DXVECTOR3 pos, D3DXVECTOR3 rot, int nIdxModel, int nType)
{
	for (int nCnt = 0; nCnt < m_Model.nMaxModel; nCnt++)
	{
		m_Model.NumModel[nCnt].pos = pos;
		m_Model.NumModel[nCnt].rot = rot;
		m_Model.NumModel[nCnt].nIdxModel = nIdxModel;
		m_Model.NumModel[nCnt].nType = nType;
	}
}

//====================================================================================================
// 高さのセット
//====================================================================================================
void CScene3D::SetHight(float Hight)
{
	m_pos.y = Hight;
}
//====================================================================================================
// デストラクタ
//====================================================================================================
CScene3D::~CScene3D()
{

}
