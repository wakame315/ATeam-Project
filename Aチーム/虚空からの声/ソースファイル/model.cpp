//===============================================
//
// 3D���f������ (scene3d.cpp)
// Author : ��{��
//
//===============================================

//========================
// �C���N���[�h�t�@�C��
//========================
#include "model.h"
#include "manager.h"
#include "renderer.h"

//=============================================================================
// �R���X�g���N�^
//=============================================================================
CModel::CModel()
{
    m_pBuffMat = NULL;
    m_pMesh = NULL;
    m_nNumMat = 0;
    D3DXMatrixIdentity(&m_mtxWorld);
    m_pos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
    m_rot = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
    m_scale = D3DXVECTOR3(5.0f, 5.0f, 5.0f);
}

//=============================================================================
// �f�X�g���N�^
//=============================================================================
CModel::~CModel()
{
}

//=============================================================================
// ����������
//=============================================================================
HRESULT CModel::Init(D3DXVECTOR3 pos, D3DXVECTOR3 size)
{
    return S_OK;
}

//=============================================================================
// �I������
//=============================================================================
void CModel::Uninit(void)
{
}

//=============================================================================
// �X�V����
//=============================================================================
void CModel::Update(void)
{
}

//=============================================================================
// �`�揈��
//=============================================================================
void CModel::Draw(CModel *model)
{
    LPDIRECT3DDEVICE9 pDevice = CManager::GetRenderer()->GetDevice();
    D3DXMATRIX mtxRot, mtxTrans, mtxScale;
    D3DMATERIAL9 matDef;
    D3DXMATERIAL *pMat;

    // �}�g���b�N�X�v�Z
    D3DXMatrixIdentity(&m_mtxWorld);

    D3DXMatrixScaling(&mtxScale, m_scale.x, m_scale.y, m_scale.z);
    D3DXMatrixMultiply(&m_mtxWorld, &m_mtxWorld, &mtxScale);

    D3DXMatrixRotationYawPitchRoll(&mtxRot, m_rot.y, m_rot.x, m_rot.z);
    D3DXMatrixMultiply(&m_mtxWorld, &m_mtxWorld, &mtxRot);

    D3DXMatrixTranslation(&mtxTrans, m_pos.x, m_pos.y, m_pos.z);
    D3DXMatrixMultiply(&m_mtxWorld, &m_mtxWorld, &mtxTrans);

    // �e�Ƃ̃}�g���b�N�X�v�Z
    if (model != NULL)
    {
        D3DXMatrixMultiply(&m_mtxWorld, &m_mtxWorld, &model->m_mtxWorld);
    }

    pDevice->SetTransform(D3DTS_WORLD, &m_mtxWorld);

    pDevice->GetMaterial(&matDef);

    ZeroMemory(&matDef, sizeof(D3DMATERIAL9));

    pMat = (D3DXMATERIAL*)m_pBuffMat->GetBufferPointer();

    for (int nCntMat = 0; nCntMat < m_nNumMat; nCntMat++)
    {
        pDevice->SetMaterial(&pMat[nCntMat].MatD3D);

        m_pMesh->DrawSubset(nCntMat);
    }

    pDevice->SetMaterial(&matDef);
}

//=============================================================================
// �`�揈��
//=============================================================================
void CModel::Draw(D3DXVECTOR3 pos, D3DXVECTOR3 rot)
{
    LPDIRECT3DDEVICE9 pDevice = CManager::GetRenderer()->GetDevice();
    D3DXMATRIX mtxParent, mtxRot, mtxTrans, mtxScale;
    D3DMATERIAL9 matDef;
    D3DXMATERIAL *pMat;

    // �}�g���b�N�X�v�Z
    D3DXMatrixIdentity(&m_mtxWorld);

    D3DXMatrixScaling(&mtxScale, m_scale.x, m_scale.y, m_scale.z);
    D3DXMatrixMultiply(&m_mtxWorld, &m_mtxWorld, &mtxScale);

    D3DXMatrixRotationYawPitchRoll(&mtxRot, m_rot.y, m_rot.x, m_rot.z);
    D3DXMatrixMultiply(&m_mtxWorld, &m_mtxWorld, &mtxRot);

    D3DXMatrixTranslation(&mtxTrans, m_pos.x, m_pos.y, m_pos.z);
    D3DXMatrixMultiply(&m_mtxWorld, &m_mtxWorld, &mtxTrans);

    // �e�Ƃ̃}�g���b�N�X�v�Z
    D3DXMatrixIdentity(&mtxParent);

    D3DXMatrixRotationYawPitchRoll(&mtxRot, rot.y, rot.x, rot.z);
    D3DXMatrixMultiply(&mtxParent, &mtxParent, &mtxRot);

    D3DXMatrixTranslation(&mtxTrans, pos.x, pos.y, pos.z);
    D3DXMatrixMultiply(&mtxParent, &mtxParent, &mtxTrans);

    D3DXMatrixMultiply(&m_mtxWorld, &m_mtxWorld, &mtxParent);

    pDevice->SetTransform(D3DTS_WORLD, &m_mtxWorld);

    pDevice->GetMaterial(&matDef);

    ZeroMemory(&matDef, sizeof(D3DMATERIAL9));

    pMat = (D3DXMATERIAL*)m_pBuffMat->GetBufferPointer();

    for (int nCntMat = 0; nCntMat < m_nNumMat; nCntMat++)
    {
        pDevice->SetMaterial(&pMat[nCntMat].MatD3D);

        m_pMesh->DrawSubset(nCntMat);
    }

    pDevice->SetMaterial(&matDef);
}

//=============================================================================
// ���b�V�����蓖��
//=============================================================================
void CModel::BindMesh(const LPD3DXMESH pMesh, const LPD3DXBUFFER pBuffMat, const DWORD nNumMat)
{
    m_pMesh = pMesh;
    m_pBuffMat = pBuffMat;
    m_nNumMat = nNumMat;
}
