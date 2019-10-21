//=============================================================================
//
// プレイヤー処理 [player.cpp]
// Author : KOUTA KIMURA
//
//=============================================================================

//=============================================================================
// インクルードファイル
//=============================================================================
#include "player.h"
#include "camera.h"
#include "manager.h"
#include "renderer.h"
#include "keybord.h"

//====================================================================================================
// マクロ定義
//==================================================================================================== 
#define PLAYER_SPEED			(10.0f)	//プレイヤーの速さ

//=============================================================================
// コンストラクタ
//=============================================================================
CPlayer::CPlayer(OBJTYPE type) : CScene3D(type)
{

	m_move = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	
}

//=============================================================================
// デストラクタ
//=============================================================================
CPlayer::~CPlayer()
{

}

//=============================================================================
// モデルの生成
//=============================================================================
CPlayer * CPlayer::Create(D3DXVECTOR3 pos, D3DXVECTOR3 rot, MODELTYPE type)
{
	CPlayer *pPlayer;
	pPlayer = new CPlayer(OBJTYPE_PLAYER);
	pPlayer->Init(pos, rot, type);

	return pPlayer;
}

//=============================================================================
// 初期化処理
//=============================================================================
HRESULT CPlayer::Init(D3DXVECTOR3 pos, D3DXVECTOR3 rot, MODELTYPE type)
{
	CScene3D::Init();

	CScene3D::SetPos(pos);

	CScene3D::SetType(type);

	return S_OK;
}

//=============================================================================
// 終了処理
//=============================================================================
void CPlayer::Uninit(void)
{
	CScene3D::Uninit();
}

//=============================================================================
// 更新処理
//=============================================================================
void CPlayer::Update(void)
{

	CScene3D::Update();
	
	PlayerMove();
}

//=============================================================================
// 描画処理
//=============================================================================
void CPlayer::Draw(void)
{
	CScene3D::DrawModel();
}

//========================================================================================================
// プレイヤーの移動処理
//========================================================================================================
void CPlayer::PlayerMove(void)
{
	CKeybord *pKetybord = CManager::GetKeybord();

	//カメラの取得
	CCamera::CAMERA *pCamera;
	pCamera = CCamera::GetCamera();

	D3DXVECTOR3 pos;

	pos = CScene3D::GetPos();

	pos += m_move;

		if (pKetybord->GetKeyboardPress(DIK_A))
		{//  A キー操作
			if (pKetybord->GetKeyboardPress(DIK_S))
			{// 左上
			m_move.x += sinf(pCamera->rot.y - D3DX_PI*0.75f) * PLAYER_SPEED;
			m_move.z += cosf(pCamera->rot.y - D3DX_PI*0.75f) * PLAYER_SPEED;
			}
			else if (pKetybord->GetKeyboardPress(DIK_W))
			{// 右下
				m_move.x += sinf(pCamera->rot.y - D3DX_PI*0.25f) * PLAYER_SPEED;
				m_move.z += cosf(pCamera->rot.y - D3DX_PI*0.25f) * PLAYER_SPEED;
			}
			else
			{// 左
				m_move.x += cosf(pCamera->rot.y + D3DX_PI*1.0f) * PLAYER_SPEED;
			}
		}

		else if (pKetybord->GetKeyboardPress(DIK_D))
		{//  D キー操作

			if (pKetybord->GetKeyboardPress(DIK_S))
			{// 右上
				m_move.x += sinf(pCamera->rot.y + D3DX_PI*0.75f) * PLAYER_SPEED;
				m_move.z += cosf(pCamera->rot.y + D3DX_PI*0.75f) * PLAYER_SPEED;
			}
			else if (pKetybord->GetKeyboardPress(DIK_W))
			{// 右下 
				m_move.x += sinf(pCamera->rot.y + D3DX_PI*0.25f) * PLAYER_SPEED;
				m_move.z += cosf(pCamera->rot.y + D3DX_PI*0.25f) * PLAYER_SPEED;
			}
			else
			{// 右
				m_move.x += sinf(pCamera->rot.y + D3DX_PI*0.5f) * PLAYER_SPEED;
			}
		}

		else if (pKetybord->GetKeyboardPress(DIK_W))
		{//  S キー操作
			m_move.z += cosf(pCamera->rot.y + D3DX_PI*0.0f) * PLAYER_SPEED;
		}

		else if (pKetybord->GetKeyboardPress(DIK_S))
		{//  W キー操作
			m_move.z += cosf(pCamera->rot.y + D3DX_PI*1.0f) * PLAYER_SPEED;
		}

		if (pKetybord->GetKeyboardPress(DIK_O))
		{// 左上
			m_move.y += cosf(pCamera->rot.y + D3DX_PI*0.0f) * PLAYER_SPEED;
		}

		if (pKetybord->GetKeyboardPress(DIK_P))
		{// 左上
			m_move.y += cosf(pCamera->rot.y + D3DX_PI*1.0f) * PLAYER_SPEED;
		}

		CScene3D::SetPos(pos);
}

//=============================================================================
// モデルとの当たり判定
//=============================================================================
//bool CollisionModel(D3DXVECTOR3 *pPos, D3DXVECTOR3 *pPosOld, D3DXVECTOR3 size)
//{
//	bool bRand = false;// 着地判定
//
//	// 当たり判定
//	for (int nCountBlock = 0; nCountBlock < MAX_MODEL; nCountBlock++)
//	{
//		if (m_aModel[nCountBlock].bUse)// ブロックが使用されている場合
//		{
//			if (pPos->y <= m_aModel[nCountBlock].pos.y + m_aModelModel[m_aModel[nCountBlock].type].vtxMax.y&&
//				pPosOld->y >= m_aModel[nCountBlock].pos.y + m_aModelModel[m_aModel[nCountBlock].type].vtxMax.y)
//			{// 乗っているか
//				if (pPos->x + size.x > m_aModel[nCountBlock].pos.x + m_aModelModel[m_aModel[nCountBlock].type].vtxMin.x&&
//					pPos->x - size.x < m_aModel[nCountBlock].pos.x + m_aModelModel[m_aModel[nCountBlock].type].vtxMax.x&&
//					pPos->z + size.z > m_aModel[nCountBlock].pos.z + m_aModelModel[m_aModel[nCountBlock].type].vtxMin.z&&
//					pPos->z - size.z < m_aModel[nCountBlock].pos.z + m_aModelModel[m_aModel[nCountBlock].type].vtxMax.z)
//				{// X,Z座標が範囲内の場合
//					pPos->y = m_aModel[nCountBlock].pos.y + m_aModelModel[m_aModel[nCountBlock].type].vtxMax.y;
//					bRand = true;
//				}
//			}
//			else if (pPos->y + size.y > m_aModel[nCountBlock].pos.y + m_aModelModel[m_aModel[nCountBlock].type].vtxMin.y &&
//				pPos->y < m_aModel[nCountBlock].pos.y + m_aModelModel[m_aModel[nCountBlock].type].vtxMax.y)
//			{// Y座標が範囲内の場合
//				if (pPos->x + size.x > m_aModel[nCountBlock].pos.x + m_aModelModel[m_aModel[nCountBlock].type].vtxMin.x&&
//					pPos->x - size.x < m_aModel[nCountBlock].pos.x + m_aModelModel[m_aModel[nCountBlock].type].vtxMax.x)
//				{// 上下
//					if (pPos->z - size.z <= m_aModel[nCountBlock].pos.z + m_aModelModel[m_aModel[nCountBlock].type].vtxMax.z&&
//						pPosOld->z - size.z >= m_aModel[nCountBlock].pos.z + m_aModelModel[m_aModel[nCountBlock].type].vtxMax.z)
//					{// プレイヤーがブロックに上からぶつかって
//						pPos->z = size.z + m_aModel[nCountBlock].pos.z + m_aModelModel[m_aModel[nCountBlock].type].vtxMax.z;
//					}
//					else if (pPos->z + size.z >= m_aModel[nCountBlock].pos.z + m_aModelModel[m_aModel[nCountBlock].type].vtxMin.z&&
//						pPosOld->z + size.z <= m_aModel[nCountBlock].pos.z + m_aModelModel[m_aModel[nCountBlock].type].vtxMin.z)
//					{// プレイヤーがブロックに下からぶつかって
//						pPos->z = m_aModel[nCountBlock].pos.z + m_aModelModel[m_aModel[nCountBlock].type].vtxMin.z - size.z;
//					}
//				}
//
//				if (pPos->z + size.z > m_aModel[nCountBlock].pos.z + m_aModelModel[m_aModel[nCountBlock].type].vtxMin.z&&
//					pPos->z - size.z < m_aModel[nCountBlock].pos.z + m_aModelModel[m_aModel[nCountBlock].type].vtxMax.z)
//				{// 左右
//					if (pPos->x - size.x <= m_aModel[nCountBlock].pos.x + m_aModelModel[m_aModel[nCountBlock].type].vtxMax.x&&
//						pPosOld->x - size.x >= m_aModel[nCountBlock].pos.x + m_aModelModel[m_aModel[nCountBlock].type].vtxMax.x)
//					{// プレイヤーがブロックに右からぶつかって
//						pPos->x = size.x + m_aModel[nCountBlock].pos.x + m_aModelModel[m_aModel[nCountBlock].type].vtxMax.x;
//					}
//					else if (pPos->x + size.x >= m_aModel[nCountBlock].pos.x + m_aModelModel[m_aModel[nCountBlock].type].vtxMin.x&&
//						pPosOld->x + size.x <= m_aModel[nCountBlock].pos.x + m_aModelModel[m_aModel[nCountBlock].type].vtxMin.x)
//					{// プレイヤーがブロックに左からぶつかって
//						pPos->x = m_aModel[nCountBlock].pos.x + m_aModelModel[m_aModel[nCountBlock].type].vtxMin.x - size.x;
//					}
//				}
//			}
//		}
//	}
//
//	return bRand;
//}