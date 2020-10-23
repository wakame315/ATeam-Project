//====================================================================
//
// �w�i�̏��� (bg.h)
// Author : �㓡�T�V��
//
//====================================================================
#ifndef _BG_H_
#define _BG_H_

//================================================
// �C���N���[�h�t�@�C��
//================================================
#include "main.h"
#include "scene2d.h"

//================================================
// �}�N����`
//================================================
#define BG_POS (D3DXVECTOR3(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2, 0.0f))   // �w�i�̈ʒu
#define BG_SIZE (D3DXVECTOR3(SCREEN_WIDTH, SCREEN_HEIGHT, 0.0f))          // �w�i�̑傫��

//================================================
// �N���X�錾
//================================================

// �w�i�N���X
class CBg : public CScene2D
{
public:
    // �w�i�̎��
    typedef enum
    {
        TYPE_TITLE_BG,          // �^�C�g���̔w�i
        TYPE_MAX			    // ��ނ̍ő吔
    }TYPE;
    CBg();
    ~CBg();
    HRESULT Init(D3DXVECTOR3 pos, D3DXVECTOR3 size, D3DXVECTOR3 rot);
    void Uninit(void);
    void Update(void);
    void Draw(void);
    static HRESULT Load(void);
    static void Unload(void);
    static CBg *Create(D3DXVECTOR3 pos, D3DXVECTOR3 size, D3DXCOLOR col, TYPE type);

private:
    static LPDIRECT3DTEXTURE9 m_apTexture[TYPE_MAX];   // �ǂݍ��񂾃e�N�X�`����ۑ�����
    D3DXCOLOR m_col;    // �F
    TYPE m_type;        // �w�i�̎��
};

#endif