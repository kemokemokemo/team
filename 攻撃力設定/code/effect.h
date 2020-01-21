//=============================================================================
//
// �G�t�F�N�g�̏��� [effect.h]
// Author : KIMURA KOUTA
//
//=============================================================================
#ifndef _EFFECT_H_
#define _EFFECT_H_

#define _CRT_SECURE_NO_WARNINGS

//=============================================================================
// �C���N���[�h�t�@�C��
//=============================================================================
#include "main.h"
#include "billboard.h"

//=============================================================================
// �}�N����`
//=============================================================================
#define	MAX_EFFECT			(256)							// �G�t�F�N�g�̍ő吔
#define	MAX_EFFECTTEX		(1)							// �G�t�F�N�g�̍ő吔


//================================================================
// �����_�����O�N���X
//================================================================
class CEffect :public CBillboard
{
public:

	//=============================================================================
	// UI�̎��
	//=============================================================================
	typedef enum
	{
		EFFECTTYPE_DAMAGE = 0,
		EFFECTTYPE_EXPLOSION,
		EFFECTTYPE_MAX
	} EFFECTTYPE;

	//=============================================================================
	// �v���g�^�C�v�錾
	//=============================================================================
	CEffect(OBJTYPE type);
	~CEffect();

	HRESULT Init(D3DXVECTOR3 pos, D3DXVECTOR3 move, int nLife, EFFECTTYPE EffectType);
	void Uninit(void);
	void Update(void);
	void Draw(void);

	static CEffect *Create(D3DXVECTOR3 pos, D3DXVECTOR3 move, int nLife, EFFECTTYPE EffectType);
	static HRESULT Load(void);
	static void Unload(void);

	static void SetParticle(D3DXVECTOR3 pos, D3DXVECTOR3 move, int nLife, EFFECTTYPE EffectType);

private:

	static LPDIRECT3DTEXTURE9 m_pTextureEffect[MAX_EFFECTTEX];		// �e�N�X�`���ւ̃|�C���^
	LPDIRECT3DVERTEXBUFFER9 m_pVtxBuffEffect;				// ���_�o�b�t�@�ւ̃|�C���^
	EFFECTTYPE EffectType;
	float size;
	D3DXVECTOR3 m_move;
	int m_nLife;
};

#endif