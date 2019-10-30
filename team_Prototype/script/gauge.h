//====================================================================================================
//
// �Q�[�W���� (gauge.h)
// Author (Kimura kouta)
//
//====================================================================================================
#ifndef _GAUGE_H_
#define _GAUGE_H_

//====================================================================================================
//�C���N���[�h�t�@�C��
//====================================================================================================
#include"main.h"
#include"Scene2D.h"
#include "player.h"


//class CPlayer;

#define MAX_TEXGAUGE (1)	//�ǂݍ��ރe�N�X�`���t�@�C����

//================================================================
// �����_�����O�N���X
//================================================================
class CGauge : public CScene2D
{
public:


	//================================================================
	// �v���g�^�C�v�錾
	//================================================================
	CGauge(OBJTYPE type);
	CGauge();
	~CGauge();

	HRESULT Init(D3DXVECTOR3 pos);
	void Uninit(void);
	void Update(void);
	void Draw(void);

	void SetLife(int nLife);
	int GetLife();
	static CGauge *Create(D3DXVECTOR3 pos);
	static HRESULT Load(void);
	static void Unload(void);


private:

	VERTEX_2D m_Vertex[4];
	static LPDIRECT3DTEXTURE9 m_pTextureGauge[MAX_TEXGAUGE];
	D3DXVECTOR3 m_pos;
	CPlayer *pPlayer;
	float Size;
	int m_nLife;
};

//====================================================================================================
// �}�N����`
//==================================================================================================== 
#endif
