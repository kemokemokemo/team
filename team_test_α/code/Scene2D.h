//====================================================================================================
//
// �����_�����O���� (Scene.h)
// Author (Kimura kouta)
//
//====================================================================================================
#ifndef _SCENE2D_H_
#define _SCENE2D_H_

//====================================================================================================
//�C���N���[�h�t�@�C��
//====================================================================================================
#include"main.h"
#include"Scene.h"

//====================================================================================================
// �}�N����`
//====================================================================================================

//================================================================
// �����_�����O�N���X
//================================================================
class CScene2D : public CScene
{
public:

	//================================================================
	// �v���g�^�C�v�錾
	//================================================================
	CScene2D(OBJTYPE nPriority);
	CScene2D();
	~CScene2D();

	HRESULT Init(void);			//������
	void Uninit(void);			//�I��
	void Update(void);			//�X�V
	void Draw(void);			//�`��

	D3DXVECTOR3 GetPos(void);	//�|�W�V�����̎擾

	void UIUpdate(int nLife,int size); //�Q�[�W�̏���

	void SetPos(D3DXVECTOR3 pos);											//�|�W�V�����̐ݒ�
	void SetColor(D3DXCOLOR Color);											//�F�̐ݒ�
	void SetSize(float Size_x, float Size_y);								//�傫���̐ݒ�
	void SetTex(int nDigits);												//�e�N�X�`���̐ݒ�
	void SetAnim(float fHeight, float fWidht, float fWidht2, int fChange);	//�A�j���[�V�����̐ݒ�

	void BindTexture(LPDIRECT3DTEXTURE9 cName);	//�e�N�X�`���̐ݒ�

private:

	VERTEX_2D m_Vertex[4];

	LPDIRECT3DVERTEXBUFFER9 m_pVtxBuffScene;		// ���_�o�b�t�@�ւ̃|�C���^
	LPDIRECT3DTEXTURE9 m_pTexturePolygon;

	D3DXVECTOR3 m_pos;		//�|�W�V����
	D3DXCOLOR m_Col;		//�F

	int m_nCounterAnim;		//�A�j���[�V�����J�E���g
	int m_nPatternAnim;		//�A�j���[�V�����p�^�[��

	float m_PosSize_X;
	float m_PosSize_Y;
	float m_fHeight;
	float m_fWidht;
	float m_fWidht2;
};

//====================================================================================================
// �}�N����`
//==================================================================================================== 
#endif