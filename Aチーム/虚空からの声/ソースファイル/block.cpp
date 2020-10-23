//===============================================
//
// �t�B�[���h���� (block.cpp)
// Author : ��{��
//
//===============================================

//========================
// �C���N���[�h�t�@�C��
//========================
#include "block.h"
#include "manager.h"
#include "renderer.h"

//========================================
// �ÓI�����o�ϐ��錾
//========================================
LPD3DXMESH	CBlock::m_apMesh[CBlock::TYPE_MAX] = {};
LPD3DXBUFFER CBlock::m_apBuffMat[CBlock::TYPE_MAX] = {};
DWORD CBlock::m_aNumMat[CBlock::TYPE_MAX] = {};
LPDIRECT3DTEXTURE9 CBlock::m_apTexture[CBlock::TYPE_MAX] = {};

CBlock* CBlock::m_pSelectBlock = NULL;
int CBlock::m_nNumAll = 0;

//=============================================================================
// �R���X�g���N�^
//=============================================================================
CBlock::CBlock() :CScene3D(CScene::OBJTYPE_BLOCK)
{
    m_collisionSize = DEFAULT_VECTOR;
    m_nType = TYPE_BUILDING001;
    m_bWallRun = false;

    m_bBlink = false;
    m_nCntTime = 0;

	m_nNumAll++;
}

//=============================================================================
// �f�X�g���N�^
//=============================================================================
CBlock::~CBlock()
{
	m_nNumAll--;
}

//=============================================================================
// ����������
//=============================================================================
HRESULT CBlock::Init(D3DXVECTOR3 pos, D3DXVECTOR3 size, D3DXVECTOR3 rot, int nType)
{
    CScene3D::Init(pos, size, rot);

    SetScale(size);

    // ���b�V���A�e�N�X�`�����o�C���h
    BindMesh(m_apMesh[m_nType], m_apBuffMat[m_nType], m_aNumMat[m_nType]);
    BindTexture(m_apTexture[m_nType]);

    return S_OK;
}

//=============================================================================
// �I������
//=============================================================================
void CBlock::Uninit(void)
{
    CScene3D::Uninit();
}

//=============================================================================
// �X�V����
//=============================================================================
void CBlock::Update(void)
{
    // 0���傫���Ȃ�A���炷
    if (m_nCntTime > 0)
    {
        m_nCntTime--;
    }

    // �I�����Ă���u���b�N��_�ł�����
    if (this == m_pSelectBlock)
    {
        if (m_nCntTime == 0)
        {
            m_bBlink = !m_bBlink;

            m_nCntTime = BLINK_TIME;
        }
    }
    else
    {
        m_nCntTime = 0;

        m_bBlink = false;
    }

    CScene3D::Update();
}

//=============================================================================
// �`�揈��
//=============================================================================
void CBlock::Draw(void)
{
    LPDIRECT3DDEVICE9 pDevice = CManager::GetRenderer()->GetDevice();

    if (m_bBlink == false)
    {
        CScene3D::Draw();
    }
}

//=============================================================================
// ���f���f�[�^�ǂݍ��ݏ���
//=============================================================================
HRESULT CBlock::Load(void)
{
    LPDIRECT3DDEVICE9 pDevice = CManager::GetRenderer()->GetDevice();

    //==============================
    // �r��001
    //==============================
    // ���f��
    D3DXLoadMeshFromX(LPCSTR("data/MODEL/building/building001.x"), D3DXMESH_SYSTEMMEM, pDevice, NULL,
        &m_apBuffMat[TYPE_BUILDING001], NULL, &m_aNumMat[TYPE_BUILDING001], &m_apMesh[TYPE_BUILDING001]);
    // �e�N�X�`��
    D3DXCreateTextureFromFile(pDevice, "data/TEXTURE/building001.jpg", &m_apTexture[TYPE_BUILDING001]);

    //==============================
    // �r��101
    //==============================
    // ���f��
    D3DXLoadMeshFromX(LPCSTR("data/MODEL/building/building101.x"), D3DXMESH_SYSTEMMEM, pDevice, NULL,
        &m_apBuffMat[TYPE_BUILDING101], NULL, &m_aNumMat[TYPE_BUILDING101], &m_apMesh[TYPE_BUILDING101]);
    // �e�N�X�`��
    D3DXCreateTextureFromFile(pDevice, "data/TEXTURE/building101.jpg", &m_apTexture[TYPE_BUILDING101]);

    //==============================
    // �r��201
    //==============================
    // ���f��
    D3DXLoadMeshFromX(LPCSTR("data/MODEL/building/building201.x"), D3DXMESH_SYSTEMMEM, pDevice, NULL,
        &m_apBuffMat[TYPE_BUILDING201], NULL, &m_aNumMat[TYPE_BUILDING201], &m_apMesh[TYPE_BUILDING201]);
    // �e�N�X�`��
    D3DXCreateTextureFromFile(pDevice, "data/TEXTURE/building201.jpg", &m_apTexture[TYPE_BUILDING201]);

    //==============================
    // �r��301
    //==============================
    // ���f��
    D3DXLoadMeshFromX(LPCSTR("data/MODEL/building/building301.x"), D3DXMESH_SYSTEMMEM, pDevice, NULL,
        &m_apBuffMat[TYPE_BUILDING301], NULL, &m_aNumMat[TYPE_BUILDING301], &m_apMesh[TYPE_BUILDING301]);
    // �e�N�X�`��
    D3DXCreateTextureFromFile(pDevice, "data/TEXTURE/building301.jpg", &m_apTexture[TYPE_BUILDING301]);

    //==============================
    // �r��401
    //==============================
    // ���f��
    D3DXLoadMeshFromX(LPCSTR("data/MODEL/building/building401.x"), D3DXMESH_SYSTEMMEM, pDevice, NULL,
        &m_apBuffMat[TYPE_BUILDING401], NULL, &m_aNumMat[TYPE_BUILDING401], &m_apMesh[TYPE_BUILDING401]);
    // �e�N�X�`��
    D3DXCreateTextureFromFile(pDevice, "data/TEXTURE/building401.jpg", &m_apTexture[TYPE_BUILDING401]);

    //==============================
    // �r��501
    //==============================
    // ���f��
    D3DXLoadMeshFromX(LPCSTR("data/MODEL/building/building501.x"), D3DXMESH_SYSTEMMEM, pDevice, NULL,
        &m_apBuffMat[TYPE_BUILDING501], NULL, &m_aNumMat[TYPE_BUILDING501], &m_apMesh[TYPE_BUILDING501]);
    // �e�N�X�`��
    D3DXCreateTextureFromFile(pDevice, "data/TEXTURE/building501.jpg", &m_apTexture[TYPE_BUILDING501]);

    //==============================
    // �M���@
    //==============================
    // ���f��
    D3DXLoadMeshFromX(LPCSTR("data/MODEL/Signal.x"), D3DXMESH_SYSTEMMEM, pDevice, NULL,
        &m_apBuffMat[TYPE_SIGNAL], NULL, &m_aNumMat[TYPE_SIGNAL], &m_apMesh[TYPE_SIGNAL]);

    //==============================
    // �X��
    //==============================
    // ���f��
    D3DXLoadMeshFromX(LPCSTR("data/MODEL/light.x"), D3DXMESH_SYSTEMMEM, pDevice, NULL,
        &m_apBuffMat[TYPE_LIGHT], NULL, &m_aNumMat[TYPE_LIGHT], &m_apMesh[TYPE_LIGHT]);

    //==============================
    // �S�~��
    //==============================
    // ���f��
    D3DXLoadMeshFromX(LPCSTR("data/MODEL/DustBox.x"), D3DXMESH_SYSTEMMEM, pDevice, NULL,
        &m_apBuffMat[TYPE_DUSTBOX], NULL, &m_aNumMat[TYPE_DUSTBOX], &m_apMesh[TYPE_DUSTBOX]);
    return S_OK;
}

//=============================================================================
// ���f���f�[�^�j������
//=============================================================================
void CBlock::Unload(void)
{
    for (int nCnt = 0; nCnt < CBlock::TYPE_MAX; nCnt++)
    {
        if (m_apMesh[nCnt] != NULL)
        {
            m_apMesh[nCnt]->Release();
            m_apMesh[nCnt] = NULL;
        }
        if (m_apBuffMat[nCnt] != NULL)
        {
            m_apBuffMat[nCnt]->Release();
            m_apBuffMat[nCnt] = NULL;
        }
        if (m_apTexture[nCnt] != NULL)
        {
            m_apTexture[nCnt]->Release();
            m_apTexture[nCnt] = NULL;
        }
    }
}

//=============================================================================
// �C���X�^���X��������
//=============================================================================
CBlock * CBlock::Create(D3DXVECTOR3 pos, D3DXVECTOR3 rot, int nType)
{
    CBlock *pBlock = NULL;
	pBlock = new CBlock;
    pBlock->m_nType = nType;
    pBlock->Init(pos, D3DXVECTOR3(1.0f, 1.0f, 1.0f), rot, nType);

    // ��ނ��ƂɁA���т���l��ς���
    switch (nType)
    {
    case TYPE_BUILDING001:

        pBlock->m_collisionSize = BLOCK_BUILDING_COLLISION_SIZE;
        pBlock->m_bWallRun = true;

        break;

    case TYPE_BUILDING101:

        pBlock->m_collisionSize = BLOCK_BUILDING_COLLISION_SIZE;
        pBlock->m_bWallRun = true;

        break;

    case TYPE_BUILDING201:

        pBlock->m_collisionSize = BLOCK_BUILDING_COLLISION_SIZE;
        pBlock->m_bWallRun = true;

        break;

    case TYPE_BUILDING301:

        pBlock->m_collisionSize = BLOCK_BUILDING_COLLISION_SIZE;
        pBlock->m_bWallRun = true;

        break;

    case TYPE_BUILDING401:

        pBlock->m_collisionSize = BLOCK_BUILDING_COLLISION_SIZE;
        pBlock->m_bWallRun = true;

        break;

    case TYPE_BUILDING501:

        pBlock->m_collisionSize = BLOCK_BUILDING_COLLISION_SIZE;
        pBlock->m_bWallRun = true;

        break;

    case TYPE_SIGNAL:

        pBlock->m_collisionSize = BLOCK_SIGNAL_COLLISION_SIZE;
        pBlock->m_bWallRun = true;

        break;

    case TYPE_LIGHT:

        pBlock->m_collisionSize = BLOCK_LIGHT_COLLISION_SIZE;
        pBlock->m_bWallRun = true;

        break;

    case TYPE_DUSTBOX:

        pBlock->m_collisionSize = BLOCK_DUSTBOX_COLLISION_SIZE;

        break;
    }

    return pBlock;
}
