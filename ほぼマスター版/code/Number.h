//=============================================================================
//
// �������� [number.h]
// Author :KIMURA KOUTA
//
//=============================================================================
#ifndef _NUMBER_H_
#define _NUMBER_H_

//=============================================================================
// �C���N���[�h�t�@�C��
//=============================================================================
#include "main.h"

//================================================================
// �����_�����O�N���X
//================================================================
class CNumber
{
public:

	//====================================================================================================
	// �\���̒�`
	//=====================================================================================================
	typedef struct
	{
		D3DXVECTOR3 pos;	//�|�W�V����
		float       rhw;	//1�ŌŒ肷��
		D3DCOLOR    col;	//�F
		D3DXVECTOR2 tex;	//�e�N�X�`�����
	}VERTEX_2D;

	//================================================================
	// �v���g�^�C�v�錾
	//================================================================
	CNumber();
	~CNumber();

	HRESULT Init();
	void Uninit(void);
	void Update(void);
	void Draw(void);

	static CNumber *Create(D3DXVECTOR3 pos, float size_x, float size_y, int nNumber);
	static HRESULT Load(void);
	static void Unload(void);
	void SetNumber(int nNumber);
	void SetPosition(D3DXVECTOR3 pos);
	void SetSize(float size_x, float size_y);
	void SetTex(int nDigits);

private:

	static LPDIRECT3DTEXTURE9 m_pTextureNumber;
	LPDIRECT3DVERTEXBUFFER9 m_pVtxBuffNumber;		// ���_�o�b�t�@�ւ̃|�C���^
	D3DXVECTOR3 m_pos;
	float m_Size_X;
	float m_Size_Y;
	int m_nNumber;
};

//====================================================================================================
// �}�N����`
//==================================================================================================== 

#endif
