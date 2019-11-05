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
#define TEXTUER_001 "DATA/TEX/player000.png"				//�ǂݍ��ރe�N�X�`���t�@�C����
#define TEXTUER_002 "DATA/TEX/bullet001.png"				//�ǂݍ��ރe�N�X�`���t�@�C����
#define TEXTUER_003 "DATA/TEX/explosion000.png"				//�ǂݍ��ރe�N�X�`���t�@�C����
#define TEXTUER_004 "DATA/TEX/enemy01.png"					//�ǂݍ��ރe�N�X�`���t�@�C����
#define TEXTUER_005 "DATA/TEX/bg100.png"					//�ǂݍ��ރe�N�X�`���t�@�C����
#define TEXTUER_006 "DATA/TEX/bg101.png"					//�ǂݍ��ރe�N�X�`���t�@�C����
#define TEXTUER_007 "DATA/TEX/bg102.png"					//�ǂݍ��ރe�N�X�`���t�@�C����
#define TEXTUER_008 "DATA/TEX/Neutral01.png"				//�ǂݍ��ރe�N�X�`���t�@�C����
#define TEXTUER_009 "DATA/TEX/pipo-btleffect044.png"		//�ǂݍ��ރe�N�X�`���t�@�C����
#define TEXTUER_010 "DATA/TEX/pipo-btleffect018.png"		//�ǂݍ��ރe�N�X�`���t�@�C����
#define TEXTUER_011 "DATA/TEX/Life001.png"					//�ǂݍ��ރe�N�X�`���t�@�C����
#define TEXTUER_012 "DATA/TEX/pipo-btleffect134.png"		//�ǂݍ��ރe�N�X�`���t�@�C����
#define TEXTUER_013 "DATA/TEX/Item000.png"					//�ǂݍ��ރe�N�X�`���t�@�C����
#define TEXTUER_014 "DATA/TEX/pipo-btleffect019.png"		//�ǂݍ��ރe�N�X�`���t�@�C����
#define TEXTUER_015 "DATA/TEX/title.png"					//�ǂݍ��ރe�N�X�`���t�@�C����
#define TEXTUER_016 "DATA/TEX/result.JPG"					//�ǂݍ��ރe�N�X�`���t�@�C����
#define TEXTUER_017 "DATA/TEX/1HPbar.png"					//�ǂݍ��ރe�N�X�`���t�@�C����
#define TEXTUER_018 "DATA/TEX/boss001.png"					//�ǂݍ��ރe�N�X�`���t�@�C����
#define TEXTUER_019 "DATA/TEX/OVER.png"						//�ǂݍ��ރe�N�X�`���t�@�C����
#define TEXTUER_020 "DATA/TEX/Neutral002.png"				//�ǂݍ��ރe�N�X�`���t�@�C����
#define TEXTUER_021 "DATA/TEX/press_enter.png"				//�ǂݍ��ރe�N�X�`���t�@�C����
#define TEXTUER_022 "DATA/TEX/titlelog.png"					//�ǂݍ��ރe�N�X�`���t�@�C����
#define TEXTUER_023 "DATA/TEX/tutorial.png"					//�ǂݍ��ރe�N�X�`���t�@�C����
#define TEXTUER_024 "DATA/TEX/RankBG.png"					//�ǂݍ��ރe�N�X�`���t�@�C����
#define TEXTUER_025 "DATA/TEX/bariya.png"					//�ǂݍ��ރe�N�X�`���t�@�C����
#define TEXTUER_026 "DATA/TEX/BulletMove000.png"			//�ǂݍ��ރe�N�X�`���t�@�C����
#define TEXTUER_027 "DATA/TEX/tutorial2.png"				//�ǂݍ��ރe�N�X�`���t�@�C����
#define TEXTUER_028 "DATA/TEX/bg100.png"					//�ǂݍ��ރe�N�X�`���t�@�C����
#define TEXTUER_029 "DATA/TEX/bg101.png"					//�ǂݍ��ރe�N�X�`���t�@�C����


//================================================================
// �����_�����O�N���X
//================================================================
class CScene2D : public CScene
{
public:

	typedef enum
	{
		MODE_NORMAL = 0,
		MODE_BATTLE,
		MODE_MAX,
	} MODESTATE;

	//================================================================
	// �v���g�^�C�v�錾
	//================================================================
	CScene2D(OBJTYPE nPriority);
	CScene2D();
	~CScene2D();

	HRESULT Init(void);
	void Uninit(void);
	void Update(void);
	void Draw(void);

	D3DXVECTOR3 GetPos(void);
	void SetPos(D3DXVECTOR3 pos);
	void SetSize(float Size_x, float Size_y);
	void SetColor(D3DXCOLOR Color);
	void SetSpeed(float tex);
	void UIUpdate(int nLife,int size);
	void TexMove();
	void SetTex(int nDigits);
	//void CollisionTest2();
	void SetModeState(MODESTATE mode);
	MODESTATE GetModeState(void);
	void BgUpdate();

	void BindTexture(LPDIRECT3DTEXTURE9 cName);
	void SetAnim(float fHeight, float fWidht,float fWidht2,int fChange);
	void SetInitTex(float fHeight, float fWidht);
	void SetRadius(float fRadius);


private:

	VERTEX_2D m_Vertex[4];
	LPDIRECT3DTEXTURE9 m_pTexturePolygon;
	D3DXVECTOR3 m_pos = D3DXVECTOR3(0.0f,0.0f,0.0f);	//�|�W�V����
	D3DXVECTOR3 m_posmove;
	D3DXVECTOR2 m_tex;
	float m_PosSize_X;
	float m_PosSize_Y;
	float m_Rot = D3DX_PI*0.25f;
	float m_CountRot = 0.0f;
	float m_RotRand = 0.0f;
	D3DXCOLOR m_Col = D3DXCOLOR(1.0f,1.0f,1.0f,1.0f);
	LPDIRECT3DVERTEXBUFFER9 m_pVtxBuffScene = NULL;		// ���_�o�b�t�@�ւ̃|�C���^
	int m_nCounterAnim;
	int m_nPatternAnim;
	float m_TexMove;
	float m_Speed;
	float m_fHeight;
	float m_fWidht;
	float m_fWidht2;
	MODESTATE m_ModeState;

};

//====================================================================================================
// �}�N����`
//==================================================================================================== 
#endif