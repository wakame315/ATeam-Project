//====================================================================
//
// �t�B�[���h�̏��� (character.h)
// Author : ��{��
//
//====================================================================
#ifndef _FIELD_H_
#define _FIELD_H_

//================================================
// �C���N���[�h�t�@�C��
//================================================
#include "main.h"
#include "scene.h"
#include "tile.h"

//================================================
// �}�N����`
//================================================

#define FIELD_POS (D3DXVECTOR3(2000.0f, 0.0f, 4800.0f))  // �t�B�[���h�̈ʒu
#define FIELD_SCALE (D3DXVECTOR3(100.0f, 1.0f, 100.0f))  // �t�B�[���h�̃X�P�[��

#define MAP_WIDTH	50	// �}�b�v�̕�
#define MAP_HEIGHT	50	// �}�b�v�̉��s

#define NUM_TILE	(MAP_WIDTH * MAP_HEIGHT)

//================================================
// �N���X�錾
//================================================

// �t�B�[���h�N���X
class CField : public CScene
{
public:
    CField();
    ~CField();

    HRESULT Init(D3DXVECTOR3 pos, D3DXVECTOR3 size);
    void Uninit(void);
	void Update(void);
	void Draw(void);

	void LoadMapData(void);

	static CField *Create(void);

    static HRESULT Load(void);
    static void Unload(void);

	static void SetField(void);
private:
    static LPDIRECT3DTEXTURE9		m_pTexture;
	static CTile					*m_pTile[MAP_WIDTH][MAP_HEIGHT];
	static int						m_aGround[MAP_WIDTH][MAP_HEIGHT];
};

#endif