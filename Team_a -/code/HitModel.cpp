//=============================================================================
//
// ���f������ [hitmodel.cpp]
// Author : KOUAT KIMURA
//
//=============================================================================

//=============================================================================
// �C���N���[�h�t�@�C��
//=============================================================================
#include "hitmodel.h"
#include "camera.h"
#include "manager.h"
#include "renderer.h"
#include "playerbase.h"

//=============================================================================
// �����o�ϐ�������
//=============================================================================
#define MODELFILE0		"DATA/MODEL/HitModel.x"					// �ǂݍ��ރ��f��
#define MAX_HITMODEL		(1)									// ���f���̐�

DWORD		CHitModel::nNumMat = {};				// �}�e���A�����̐�
LPD3DXMESH	CHitModel::pMesh = {};					// ���b�V�����ւ̃|�C���^
LPD3DXBUFFER	CHitModel::pBuffMat = {};				// �}�e���A�����ւ̃|�C���^

//=============================================================================
// �R���X�g���N�^
//=============================================================================
CHitModel::CHitModel(OBJTYPE type) : CHitModelBase(type)
{
}

//=============================================================================
// �f�X�g���N�^
//=============================================================================
CHitModel::~CHitModel()
{
}

//=============================================================================
// ���f���̐���
//=============================================================================
CHitModel * CHitModel::Create(D3DXVECTOR3 pos, D3DXVECTOR3 scale)
{
	CHitModel *pHitModel;
	pHitModel = new CHitModel(OBJTYPE_BG);
	pHitModel->BindHitModel(nNumMat, pMesh, pBuffMat);
	pHitModel->Init(pos, scale);

	return pHitModel;
}

//=============================================================================
// ����������
//=============================================================================
HRESULT CHitModel::Init(D3DXVECTOR3 pos, D3DXVECTOR3 scale)
{
	CHitModelBase::Init();

	CHitModelBase::SetPos(pos);
	CHitModelBase::Setsize(scale);

	return S_OK;
}

//=============================================================================
// �I������
//=============================================================================
void CHitModel::Uninit(void)
{
	CHitModelBase::Uninit();
}

//=============================================================================
// �X�V����
//=============================================================================
void CHitModel::Update(void)
{
	for (int nCntModel = 0; nCntModel < MAX_POLYGON; nCntModel++)
	{
		CScene *pScene;

		pScene = CScene::GetScene(OBJTYPE_PLAYER, nCntModel);

		if (!pScene)
			continue;

		CPlayerBase *pPlayer = (CPlayerBase*)pScene;

		D3DXVECTOR3 pos;

		D3DXVECTOR3 posp = pPlayer->GetPosParts();

		pos = posp;

		CHitModelBase::SetPos(pos);

		break;
	}
	CHitModelBase::Update();
}

//=============================================================================
// �`�揈��
//=============================================================================
void CHitModel::Draw(void)
{
	CHitModelBase::Draw();
}

//========================================================================================================
// ���f���̓ǂݍ��ݏ���
//========================================================================================================
HRESULT CHitModel::Load(void)
{
	CRenderer *pRenderer = CManager::GetRenderer();
	LPDIRECT3DDEVICE9 pDevice = pRenderer->GetDevice();

	// X�t�@�C���̓ǂݍ���
	D3DXLoadMeshFromX(MODELFILE0, D3DXMESH_SYSTEMMEM, pDevice, NULL,
		&pBuffMat, NULL,
		&nNumMat,
		&pMesh);

	return S_OK;
}

//========================================================================================================
// ���f���̉������
//========================================================================================================
void CHitModel::Unload(void)
{

}
