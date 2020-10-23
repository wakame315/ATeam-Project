//========================================================
//
//           number�̃N���X[number.cpp]
//           Author:�ɓ���P
//
//========================================================

//========================================================
//�C���N���[�h�t�@�C��
//========================================================
#include "number.h"
#include "manager.h"
#include "renderer.h"

//========================================================
//�ÓI�����o�ϐ��̏�����
//========================================================
LPDIRECT3DTEXTURE9 CNumber::m_pTexture = NULL;

//========================================================
//�R���X�g���N�^
//========================================================
CNumber::CNumber(void)
{
    m_pVtxBuff = NULL;
    m_pos = D3DXVECTOR3(0, 0, 0);
    m_nSizeX = 0;
    m_nSizeY = 0;
}

//========================================================
//�f�X�g���N�^
//========================================================
CNumber::~CNumber(void)
{

}

//========================================================
//����������
//========================================================
CNumber *CNumber::Create(D3DXVECTOR3 pos, int nSizeX, int nSizeY)
{
    //�ϐ��錾
    CNumber *pNumber;

    //����������
    pNumber = new CNumber;

    //����������
    pNumber->Init(pos, nSizeX, nSizeY);

    return pNumber;
}

//========================================================
//������
//========================================================
HRESULT CNumber::Init(D3DXVECTOR3 pos, int nSizeX, int nSizeY)
{
    //�f�o�C�X�̎擾
    CRenderer *pRenderer = CManager::GetRenderer();
    LPDIRECT3DDEVICE9 pD3DDevice = pRenderer->GetDevice();

    // �|���S���̈ʒu��ݒ�
    m_pos = pos;

    //�|���S���̃T�C�Y��ݒ�
    m_nSizeX = nSizeX;
    m_nSizeY = nSizeY;

    // ���_�o�b�t�@�̐���
    pD3DDevice->CreateVertexBuffer(sizeof(VERTEX_2D) * NUM_VERTEX, D3DUSAGE_WRITEONLY, FVF_VERTEX_2D, D3DPOOL_MANAGED, &m_pVtxBuff, NULL);

    //���_���ւ̃|�C���^
    VERTEX_2D *pVtx;

    //���_�f�[�^�͈̔͂����b�N�����_�o�b�t�@�ւ̃|�C���^�擾
    m_pVtxBuff->Lock(0, 0, (void**)&pVtx, 0);

    // ���_����ݒ�
    pVtx[0].pos = D3DXVECTOR3(m_pos.x - (m_nSizeX / 2), m_pos.y - (m_nSizeY / 2), 0);
    pVtx[1].pos = D3DXVECTOR3(m_pos.x + (m_nSizeX / 2), m_pos.y - (m_nSizeY / 2), 0);
    pVtx[2].pos = D3DXVECTOR3(m_pos.x - (m_nSizeX / 2), m_pos.y + (m_nSizeY / 2), 0);
    pVtx[3].pos = D3DXVECTOR3(m_pos.x + (m_nSizeX / 2), m_pos.y + (m_nSizeY / 2), 0);

    //�e�N�X�`�����W�̐ݒ�
    pVtx[0].tex = D3DXVECTOR2(0.0f, 0.0f);
    pVtx[1].tex = D3DXVECTOR2(0.1f, 0.0f);
    pVtx[2].tex = D3DXVECTOR2(0.0f, 1.0f);
    pVtx[3].tex = D3DXVECTOR2(0.1f, 1.0f);

    //rhw�̐ݒ�
    pVtx[0].rhw = 1.0f;
    pVtx[1].rhw = 1.0f;
    pVtx[2].rhw = 1.0f;
    pVtx[3].rhw = 1.0f;

    //���_�J���[�̐ݒ�(0�`255�̐��l�Őݒ�)
    pVtx[0].col = D3DXCOLOR(255, 255, 255, 255);
    pVtx[1].col = D3DXCOLOR(255, 255, 255, 255);
    pVtx[2].col = D3DXCOLOR(255, 255, 255, 255);
    pVtx[3].col = D3DXCOLOR(255, 255, 255, 255);

    //���_�f�[�^���A�����b�N
    m_pVtxBuff->Unlock();
    return S_OK;
}

//========================================================
//�I������
//========================================================
void CNumber::Uninit(void)
{
    // ���_�o�b�t�@�̔j��
    if (m_pVtxBuff != NULL)
    {
        m_pVtxBuff->Release();
        m_pVtxBuff = NULL;
    }

}

//========================================================
//�X�V����
//========================================================
void CNumber::Update(void)
{

}

//========================================================
//�`�揈��
//========================================================
void CNumber::Draw(void)
{
    //�f�o�C�X�̎擾
    CRenderer *pRenderer = CManager::GetRenderer();
    LPDIRECT3DDEVICE9 pD3DDevice = pRenderer->GetDevice();

    // ���_�o�b�t�@���f�[�^�X�g���[���ɐݒ�
    pD3DDevice->SetStreamSource(0, m_pVtxBuff, 0, sizeof(VERTEX_2D));

    // ���_�t�H�[�}�b�g�̐ݒ�
    pD3DDevice->SetFVF(FVF_VERTEX_2D);

    // �e�N�X�`���̐ݒ�
    pD3DDevice->SetTexture(0, m_pTexture);

    // �|���S���̕`��
    pD3DDevice->DrawPrimitive(D3DPT_TRIANGLESTRIP, 0, NUM_POLYGON);
}

//========================================================
//�e�N�X�`���ǂݍ���
//========================================================
HRESULT CNumber::Load(void)
{
    //�f�o�C�X�̎擾
    CRenderer *pRenderer = CManager::GetRenderer();
    LPDIRECT3DDEVICE9 pD3DDevice = pRenderer->GetDevice();

    // �e�N�X�`���̐���
    D3DXCreateTextureFromFile(pD3DDevice, "data/TEXTURE/number000.png", &m_pTexture);

    return S_OK;
}

//========================================================
//�e�N�X�`���̔j��
//========================================================
void CNumber::Unload(void)
{
    // �e�N�X�`���̔j��
    if (m_pTexture != NULL)
    {
        m_pTexture->Release();
        m_pTexture = NULL;
    }
}

//========================================================
//�i���o�[���Z�b�g
//========================================================
void CNumber::SetNumber(int nNumber)
{
    //���_���ւ̃|�C���^
    VERTEX_2D *pVtx;

    //���_�f�[�^�͈̔͂����b�N�����_�o�b�t�@�ւ̃|�C���^�擾
    m_pVtxBuff->Lock(0, 0, (void**)&pVtx, 0);

    //�e�N�X�`�����W�̐ݒ�
    pVtx[0].tex = D3DXVECTOR2((float)nNumber / 10, 0.0f);
    pVtx[1].tex = D3DXVECTOR2((float)(nNumber + 1) / 10, 0.0f);
    pVtx[2].tex = D3DXVECTOR2((float)nNumber / 10, 1.0f);
    pVtx[3].tex = D3DXVECTOR2((float)(nNumber + 1) / 10, 1.0f);

    //���_�f�[�^���A�����b�N
    m_pVtxBuff->Unlock();

}

//========================================================
//�i���o�[���Z�b�g
//========================================================
void CNumber::SetColor(float fColorR, float fColorG, float fColorB, float fColorA)
{
    //���_���ւ̃|�C���^
    VERTEX_2D *pVtx;

    //���_�f�[�^�͈̔͂����b�N�����_�o�b�t�@�ւ̃|�C���^�擾
    m_pVtxBuff->Lock(0, 0, (void**)&pVtx, 0);

    //�e�N�X�`�����W�̐ݒ�
    pVtx[0].col = D3DXCOLOR(fColorR, fColorG, fColorB, fColorA);
    pVtx[1].col = D3DXCOLOR(fColorR, fColorG, fColorB, fColorA);
    pVtx[2].col = D3DXCOLOR(fColorR, fColorG, fColorB, fColorA);
    pVtx[3].col = D3DXCOLOR(fColorR, fColorG, fColorB, fColorA);

    //���_�f�[�^���A�����b�N
    m_pVtxBuff->Unlock();

}