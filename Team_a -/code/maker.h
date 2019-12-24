//====================================================================================================
//
// �}�[�J�[���� (maker.h)
// Author (Kimura kouta)
//
//====================================================================================================
#ifndef _MAKER_H_
#define _MAKER_H_

//====================================================================================================
//�C���N���[�h�t�@�C��
//====================================================================================================
#include"main.h"
#include"billboard.h"

#define MAX_TEXMAKER (2)	//�ǂݍ��ރe�N�X�`���t�@�C����

class CPlayerBase;
//================================================================
// �����_�����O�N���X
//================================================================
class CMaker : public CBillboard
{
public:
	//=============================================================================
	// UI�̎��
	//=============================================================================
	typedef enum
	{
		MAKERTYPE_1P = 0,
		MAKERTYPE_2P,
		MAKERTYPE_MAX
	} MAKERTYPE;

	//================================================================
	// �v���g�^�C�v�錾
	//================================================================
	CMaker(OBJTYPE type);
	~CMaker();

	HRESULT Init(D3DXVECTOR3 pos, MAKERTYPE makertype, int life);
	void Uninit(void);
	void Update(void);
	void Draw(void);

	static CMaker *Create(D3DXVECTOR3 pos,MAKERTYPE makertype, int life);
	static HRESULT Load(void);
	static void Unload(void);


	void MakerLife(int nDamage);

	int GetMakerLife();


private:

	static LPDIRECT3DTEXTURE9 m_pTextureMaker[MAX_TEXMAKER];
	float Size;
	MAKERTYPE MakerType;
	int m_nLife;
};

//====================================================================================================
// �}�N����`
//==================================================================================================== 
#endif
