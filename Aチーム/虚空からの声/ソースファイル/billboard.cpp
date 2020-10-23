//===============================================
//
// �r���{�[�h���� (billboard.cpp)
// Author : ��{��
//
//===============================================

//========================
// �C���N���[�h�t�@�C��
//========================
#include "billboard.h"
#include "manager.h"
#include "renderer.h"

//========================================
// �ÓI�����o�ϐ��錾
//========================================
bool CBillboard::m_bAdditiveSynthesis = false;
bool CBillboard::m_bLay = false;

//=============================================================================
// �R���X�g���N�^
//=============================================================================
CBillboard::CBillboard(CScene::OBJTYPE objtype) :CScene(objtype)
{
    m_pTexture = NULL;
    m_pVtxBuff = NULL;
    D3DXMatrixIdentity(&m_mtxWorld);
    m_pos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
    m_rot = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
    m_scale = D3DXVECTOR3(1.0f, 1.0f, 1.0f);
    m_col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
    m_fTexX1 = 0.0f;
    m_fTexX2 = 1.0f;
}

//=============================================================================
// �f�t�H���g�R���X�g���N�^
//=============================================================================
CBillboard::CBillboard()
{
    m_pTexture = NULL;
    m_pVtxBuff = NULL;
    D3DXMatrixIdentity(&m_mtxWorld);
    m_pos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
    m_size = DEFAULT_VECTOR;
    m_rot = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
    m_scale = D3DXVECTOR3(1.0f, 1.0f, 1.0f);
    m_col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
    m_fTexX1 = 0.0f;
    m_fTexX2 = 1.0f;
}

//=============================================================================
// �f�X�g���N�^
//=============================================================================
CBillboard::~CBillboard()
{
}

//=============================================================================
// ����������
//=============================================================================
HRESULT CBillboard::Init(D3DXVECTOR3 pos, D3DXVECTOR3 size)
{
    LPDIRECT3DDEVICE9 pDevice = CManager::GetRenderer()->GetDevice();

    m_pos = pos;
    m_scale = D3DXVECTOR3(1.0f, 1.0f, 1.0f);
    m_size = size;
    m_col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);

    pDevice->CreateVertexBuffer(sizeof(VERTEX_3D)*NUM_VERTEX, D3DUSAGE_WRITEONLY, FVF_VERTEX_3D, D3DPOOL_MANAGED, &m_pVtxBuff, NULL);
    pDevice->SetTransform(D3DTS_WORLD, &m_mtxWorld);

    VERTEX_3D *pVtx;

    m_pVtxBuff->Lock(0, 0, (void**)&pVtx, 0);

    pVtx[0].pos = D3DXVECTOR3(-m_size.x / 2, +m_size.y / 2, 0.0f);
    pVtx[1].pos = D3DXVECTOR3(+m_size.x / 2, +m_size.y / 2, 0.0f);
    pVtx[2].pos = D3DXVECTOR3(-m_size.x / 2, -m_size.y / 2, 0.0f);
    pVtx[3].pos = D3DXVECTOR3(+m_size.x / 2, -m_size.y / 2, 0.0f);

    pVtx[0].tex = D3DXVECTOR2(m_fTexX1, 0.0f);
    pVtx[1].tex = D3DXVECTOR2(m_fTexX2, 0.0f);
    pVtx[2].tex = D3DXVECTOR2(m_fTexX1, 1.0f);
    pVtx[3].tex = D3DXVECTOR2(m_fTexX2, 1.0f);

    for (int nCount = 0; nCount < NUM_VERTEX; nCount++)
    {
        pVtx[nCount].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
        pVtx[nCount].nor = D3DXVECTOR3(0.0f, 0.0f, -1.0f);
    }

    m_pVtxBuff->Unlock();

    return S_OK;
}

//=============================================================================
// �I������
//=============================================================================
void CBillboard::Uninit(void)
{
    if (m_pVtxBuff != NULL)
    {
        m_pVtxBuff->Release();
        m_pVtxBuff = NULL;
    }

    Release();
}

//=============================================================================
// �X�V����
//=============================================================================
void CBillboard::Update(void)
{
    VERTEX_3D *pVtx;

    m_pVtxBuff->Lock(0, 0, (void**)&pVtx, 0);

    pVtx[0].pos = D3DXVECTOR3(-m_size.x / 2, +m_size.y / 2, 0.0f);
    pVtx[1].pos = D3DXVECTOR3(+m_size.x / 2, +m_size.y / 2, 0.0f);
    pVtx[2].pos = D3DXVECTOR3(-m_size.x / 2, -m_size.y / 2, 0.0f);
    pVtx[3].pos = D3DXVECTOR3(+m_size.x / 2, -m_size.y / 2, 0.0f);

    pVtx[0].tex = D3DXVECTOR2(m_fTexX1, 0.0f);
    pVtx[1].tex = D3DXVECTOR2(m_fTexX2, 0.0f);
    pVtx[2].tex = D3DXVECTOR2(m_fTexX1, 1.0f);
    pVtx[3].tex = D3DXVECTOR2(m_fTexX2, 1.0f);

    for (int nCount = 0; nCount < NUM_VERTEX; nCount++)
    {
        pVtx[nCount].col = m_col;
        pVtx[nCount].nor = D3DXVECTOR3(0.0f, 0.0f, -1.0f);
    }

    m_pVtxBuff->Unlock();
}

//=============================================================================
// �`�揈��
//=============================================================================
void CBillboard::Draw(void)
{
    LPDIRECT3DDEVICE9 pDevice = CManager::GetRenderer()->GetDevice();
    D3DXMATRIX mtxRot, mtxTrans, mtxScale;

    // ���Z����
    if (m_bAdditiveSynthesis == true)
    {
        // �����_�[�X�e�[�g(���Z�����ɂ���)
        pDevice->SetRenderState(D3DRS_BLENDOP, D3DBLENDOP_ADD);
        pDevice->SetRenderState(D3DRS_SRCBLEND, D3DBLEND_SRCALPHA);
        pDevice->SetRenderState(D3DRS_DESTBLEND, D3DBLEND_ONE);
    }

    pDevice->SetRenderState(D3DRS_LIGHTING, FALSE);

    //�A���t�@�e�X�g��L����
    pDevice->SetRenderState(D3DRS_ALPHATESTENABLE, TRUE);

    //�A���t�@�e�X�g��l�̐ݒ�
    pDevice->SetRenderState(D3DRS_ALPHAREF, 25);

    //�A���t�@�e�X�g�̔�r���@�̐ݒ�
    pDevice->SetRenderState(D3DRS_ALPHAFUNC, D3DCMP_GREATER);

    D3DXMatrixIdentity(&m_mtxWorld);

    if (m_bLay == false)
    {
        D3DXMatrixScaling(&mtxScale, m_scale.x, m_scale.y, m_scale.z);
        D3DXMatrixMultiply(&m_mtxWorld, &m_mtxWorld, &mtxScale);
        pDevice->GetTransform(D3DTS_VIEW, &mtxRot);
        D3DXMatrixInverse(&mtxRot, NULL, &mtxRot);

        mtxRot._41 = 0.0f;
        mtxRot._42 = 0.0f;
        mtxRot._43 = 0.0f;

        D3DXMatrixMultiply(&m_mtxWorld, &m_mtxWorld, &mtxRot);

        D3DXMatrixTranslation(&mtxTrans, m_pos.x, m_pos.y, m_pos.z);
        D3DXMatrixMultiply(&m_mtxWorld, &m_mtxWorld, &mtxTrans);
    }
    else
    {
        // ���ɂ����]
        float fRot = D3DXToRadian(90.0f);

        // �����𔽉f
        D3DXMatrixRotationYawPitchRoll(&mtxRot, m_rot.y, fRot, m_rot.z);
        D3DXMatrixMultiply(&m_mtxWorld, &m_mtxWorld, &mtxRot);

        // �ʒu�𔽉f
        D3DXMatrixTranslation(&mtxTrans, m_pos.x, m_pos.y, m_pos.z);
        D3DXMatrixMultiply(&m_mtxWorld, &m_mtxWorld, &mtxTrans);

        m_bLay = false;
    }

    pDevice->SetTransform(D3DTS_WORLD, &m_mtxWorld);

    pDevice->SetStreamSource(0, m_pVtxBuff, 0, sizeof(VERTEX_3D));

    pDevice->SetFVF(FVF_VERTEX_3D);

    pDevice->SetTexture(0, m_pTexture);

    pDevice->DrawPrimitive(D3DPT_TRIANGLESTRIP, 0, NUM_POLYGON);

    pDevice->SetRenderState(D3DRS_LIGHTING, TRUE);

    pDevice->SetTexture(0, NULL);

    //�A���t�@�e�X�g�𖳌���
    pDevice->SetRenderState(D3DRS_ALPHATESTENABLE, FALSE);

    // ���Z������߂�
    if (m_bAdditiveSynthesis == true)
    {
        // �����_�[�X�e�[�g(���Z������߂�)
        pDevice->SetRenderState(D3DRS_BLENDOP, D3DBLENDOP_ADD);
        pDevice->SetRenderState(D3DRS_SRCBLEND, D3DBLEND_SRCALPHA);
        pDevice->SetRenderState(D3DRS_DESTBLEND, D3DBLEND_INVSRCALPHA);

        // ���Z�����̃t���O��false�ɖ߂�
        m_bAdditiveSynthesis = false;
    }
}
