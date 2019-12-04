//====================================================================================================
//
// �����_�����O���� (Scene.h)
// Author (Kimura kouta)
//
//====================================================================================================
#ifndef _SCENE_H_
#define _SCENE_H_

//====================================================================================================
//�C���N���[�h�t�@�C��
//====================================================================================================
#include"main.h"

//====================================================================================================
// �}�N����`
//==================================================================================================== 
#define MAX_POLYGON		(30)
#define MAX_PRIPRI	(7)

//================================================================
// �����_�����O�N���X
//================================================================
class CScene
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

	//====================================================================================================
	// �񋓌^��`
	//=====================================================================================================
	typedef enum
	{
		OBJTYPE_BG,
		OBJTYPE_RANKING,
		OBJTYPE_PLAYER,
		OBJTYPE_ENEMY,
		OBJTYPE_BOSS,
		OBJTYPE_BULLET,
		OBJTYPE_EFFECT,
		OBJTYPE_NEUTRAL,
		OBJTYPE_ITEM,
		OBJTYPE_EXPLOSION,
		OBJTYPE_SCORE,
		OBJTYPE_LIFE,
		OBJTYPE_ANIMATION,
		OBJTYPE_MAX,
	} OBJTYPE;

	//================================================================
	// �v���g�^�C�v�錾
	//================================================================
	CScene(OBJTYPE nPriority);
	CScene();
	virtual ~CScene();

	virtual HRESULT Init(void) =0;
	virtual void Uninit(void) = 0;
	virtual void Update(void) = 0;
	virtual void Draw(void) = 0;

	static void ReleaseAll(void);
	static void UpdateAll(void);
	static void DrawAll(void);

	int GetID() { return m_nID; }
	OBJTYPE GetObjType(void);
	void Release(void);

protected:


	 void SetObjType(OBJTYPE Type);
	 CScene *GetScene(OBJTYPE nPriority,int bID);
	 
private:

	//�X�^�e�B�b�N�ϐ�
	static CScene *m_apScene[OBJTYPE_MAX][MAX_POLYGON];
	static int nNumAll;		//����

	OBJTYPE objType;

	//�ϐ�
	int m_nID;	//�����̔ԍ�

	int m_nPriority;	//�D�揇��

};


//====================================================================================================
// �}�N����`
//==================================================================================================== 
#endif