//=============================================================================
//
// �_���[�W�\������ [damage.h]
// Author : ��{ ��
//
//=============================================================================

// 2�d�C���N���[�h�h�~�p
#ifndef _EFFECT3D_H_
#define _EFFECT3D_H_
//*****************************************************************************
// �C���N���[�h�t�@�C��
//*****************************************************************************
#include "main.h"
#include "billboard.h"

//*****************************************************************************
// �}�N����`
//*****************************************************************************

//*****************************************************************************
// �w�i�N���X��`
//*****************************************************************************
class CEffect3D :public CBillboard
{
public:

    // UI�̎��
    typedef enum
    {
        TYPE_CURSOR,            // �u���ꏊ
        TYPE_MAX			    // ��ނ̍ő吔
    }TYPE;

    CEffect3D();
    ~CEffect3D();
    HRESULT Init(D3DXVECTOR3 pos, D3DXVECTOR3 size, D3DXVECTOR3 rot);
    void Update(void);
    void Draw(void);
    void Uninit(void);
    static HRESULT Load(void);
    static void Unload(void);
    static CEffect3D * Create(D3DXVECTOR3 pos, D3DXVECTOR3 size, D3DXVECTOR3 move, D3DXCOLOR col, TYPE type);

private:
    static LPDIRECT3DTEXTURE9 m_apTexture[TYPE_MAX];
    D3DXVECTOR3 m_pos;
    D3DXVECTOR3 m_size;
    D3DXVECTOR3 m_move;
    D3DXCOLOR m_col;
	int m_nLife;
    TYPE m_type;
};
#endif
