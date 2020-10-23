//===============================================
//
// �w�i���� (bg.cpp)
// Author : �㓡�T�V��
//
//===============================================

//========================
// �C���N���[�h�t�@�C��
//========================
#include "bg.h"
#include "manager.h"
#include "renderer.h"

//=======================================
// �}�N����`
//=======================================

//=======================================
// �ÓI�����o�ϐ��錾
//=======================================
LPDIRECT3DTEXTURE9 CBg::m_apTexture[CBg::TYPE_MAX] = {};

//========================================
// �w�i�̃R���X�g���N�^
//========================================
CBg::CBg() :CScene2D(OBJTYPE::OBJTYPE_BG)
{
    m_col = DEFAULT_COLOR;
    m_type = CBg::TYPE_MAX;
}

//========================================
// �w�i�̃f�X�g���N�^
//========================================
CBg::~CBg()
{

}

//========================================
// �w�i�̏���������
//========================================
HRESULT CBg::Init(D3DXVECTOR3 pos, D3DXVECTOR3 size, D3DXVECTOR3 rot)
{
    // ������
    CScene2D::Init(pos, size, D3DXVECTOR3(0.0f, 0.0f, 0.0f));

    // �e�N�X�`�������蓖��
    BindTexture(m_apTexture[m_type]);

    return S_OK;
}

//========================================
// �w�i�̏I������
//========================================
void CBg::Uninit(void)
{
    // �I������
    CScene2D::Uninit();
}

//========================================
// �w�i�̍X�V����
//========================================
void CBg::Update(void)
{
    // �ϐ��錾
    D3DXVECTOR3 pos = GetPosition();                   // �ʒu���擾
    D3DXVECTOR3 size = GetSize();                      // �T�C�Y���擾

                                                       // �F�𔽉f
    SetColor(m_col);

    // �ʒu�𔽉f
    SetPosition(pos);

    // �T�C�Y�𔽉f
    SetSize(size);

    // ���_���W��ݒ�
    SetVertex();
}

//========================================
// �w�i�̕`�揈��
//========================================
void CBg::Draw(void)
{
    // �`�揈��
    CScene2D::Draw();
}

//========================================
// �w�i�̉摜���[�h����
//========================================
HRESULT CBg::Load(void)
{
    // �����_���[����f�o�C�X�̎擾
    LPDIRECT3DDEVICE9 pDevice = CManager::GetRenderer()->GetDevice();

    // �e�N�X�`���̓ǂݍ���
    D3DXCreateTextureFromFile(pDevice, "data/TEXTURE/title000.jpg", &m_apTexture[CBg::TYPE_TITLE_BG]);

    return S_OK;
}

//========================================
// �w�i�̉摜�j������
//========================================
void CBg::Unload(void)
{
    // �e�N�X�`���̔j��
    for (int nCntTexture = 0; nCntTexture < CBg::TYPE_MAX; nCntTexture++)
    {
        if (m_apTexture[nCntTexture] != NULL)
        {
            m_apTexture[nCntTexture]->Release();
            m_apTexture[nCntTexture] = NULL;
        }
    }
}

//================================
// �w�i�̍쐬
//================================
CBg *CBg::Create(D3DXVECTOR3 pos, D3DXVECTOR3 size, D3DXCOLOR col, CBg::TYPE type)
{
    CBg *pBg = NULL;

    // ���������m��
    pBg = new CBg;

    // �^�C�v�̂݁A�e�N�X�`�������蓖�Ă̂��߂Ɍ��т��Ă���
    pBg->m_type = type;

    // ������
    pBg->Init(pos, size, D3DXVECTOR3(0.0f, 0.0f, 0.0f));

    // �����o�ϐ������т���
    pBg->m_col = col;

    return pBg;
}