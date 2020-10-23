//===============================================
//
// �t�B�[���h���� (field.cpp)
// Author : ��{��
//
//===============================================

//========================
// �C���N���[�h�t�@�C��
//========================
#include "field.h"
#include "manager.h"
#include "renderer.h"

//========================================
// �ÓI�����o�ϐ��錾
//========================================
LPD3DXMESH	CField::m_pMesh = NULL;
LPD3DXBUFFER CField::m_pBuffMat = NULL;
DWORD CField::m_nNumMat = NULL;
LPDIRECT3DTEXTURE9 CField::m_pTexture = NULL;

//=============================================================================
// �R���X�g���N�^
//=============================================================================
CField::CField()
{
}

//=============================================================================
// �f�X�g���N�^
//=============================================================================
CField::~CField()
{
}

//=============================================================================
// ����������
//=============================================================================
HRESULT CField::Init(D3DXVECTOR3 pos, D3DXVECTOR3 size)
{
    CScene3D::Init(pos, size, D3DXVECTOR3(0.0f, 0.0f, 0.0f));

    SetScale(size);

    BindMesh(m_pMesh, m_pBuffMat, m_nNumMat);
    BindTexture(m_pTexture);

    return S_OK;
}

//=============================================================================
// �I������
//=============================================================================
void CField::Uninit(void)
{
    CScene3D::Uninit();
}

//=============================================================================
// �X�V����
//=============================================================================
void CField::Update(void)
{
    CScene3D::Update();
}

//=============================================================================
// �`�揈��
//=============================================================================
void CField::Draw(void)
{
    LPDIRECT3DDEVICE9 pDevice = CManager::GetRenderer()->GetDevice();

    CScene3D::Draw();
}

//=============================================================================
// ���f���f�[�^�ǂݍ��ݏ���
//=============================================================================
HRESULT CField::Load(void)
{
    LPDIRECT3DDEVICE9 pDevice = CManager::GetRenderer()->GetDevice();

    D3DXLoadMeshFromX(LPCSTR("./data/MODEL/field.x"), D3DXMESH_SYSTEMMEM, pDevice, NULL, &m_pBuffMat, NULL, &m_nNumMat, &m_pMesh);

    return S_OK;
}

//=============================================================================
// ���f���f�[�^�j������
//=============================================================================
void CField::Unload(void)
{
    if (m_pMesh != NULL)
    {
        m_pMesh->Release();
        m_pMesh = NULL;
    }
    if (m_pBuffMat != NULL)
    {
        m_pBuffMat->Release();
        m_pBuffMat = NULL;
    }
    if (m_pTexture != NULL)
    {
        m_pTexture->Release();
        m_pTexture = NULL;
    }
}

//=============================================================================
// �C���X�^���X��������
//=============================================================================
CField * CField::Create(void)
{
    CField *pField = NULL;
    pField = new CField;
    pField->Init(D3DXVECTOR3((2000.0f) / 2, 0.0f, 700.0f), D3DXVECTOR3(3.0f, 3.0f, 3.0f));
    return pField;
}
