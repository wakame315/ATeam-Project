//===============================================
//
// �G�t�F�N�g���� (effect.cpp)
// Author : �㓡�T�V��
//
//===============================================

//========================
// �C���N���[�h�t�@�C��
//========================
#include "effect.h"
#include "manager.h"
#include "input.h"
#include "renderer.h"
#include "library.h"
#include "game.h"
#include "bg.h"

//=======================================
// �}�N����`
//=======================================
#define ESCAPE_CHARGE_LOOP 1000 // �v���C���[���`���[�W���Ȃ�����ꂽ���́A�`���[�W�̃��[�v�𔲂���

//=======================================
// �ÓI�����o�ϐ��錾
//=======================================
LPDIRECT3DTEXTURE9 CEffect::m_apTexture[CEffect::TYPE_MAX] = {};

//========================================
// �G�t�F�N�g�̃R���X�g���N�^
//========================================
CEffect::CEffect() :CScene2D(OBJTYPE::OBJTYPE_EFFECT)
{
    m_move = DEFAULT_VECTOR;
    m_col = DEFAULT_COLOR;
    m_nLife = 1;    // 0���Ə����邽��
    m_type = CEffect::TYPE_MAX;
    m_bAlphaDown = false;

    m_fAngle = 0.0f;
    m_fRotSpeed = 0.0f;
}

//========================================
// �G�t�F�N�g�̃f�X�g���N�^
//========================================
CEffect::~CEffect()
{

}

//========================================
// �G�t�F�N�g�̏���������
//========================================
HRESULT CEffect::Init(D3DXVECTOR3 pos, D3DXVECTOR3 size, D3DXVECTOR3 rot)
{
    // ������
    CScene2D::Init(pos, size, D3DXVECTOR3(0.0f, 0.0f, 0.0f));

    // �e�N�X�`�������蓖��
    BindTexture(m_apTexture[m_type]);

    return S_OK;
}

//========================================
// �G�t�F�N�g�̏I������
//========================================
void CEffect::Uninit(void)
{
    // �I������
    CScene2D::Uninit();
}

//========================================
// �G�t�F�N�g�̍X�V����
//========================================
void CEffect::Update(void)
{
    // �ϐ��錾
    D3DXVECTOR3 pos = GetPosition();                   // �ʒu���擾
    D3DXVECTOR3 size = GetSize();                      // �T�C�Y���擾
    bool bUse = true;                                  // �g�p���Ă��邩�ǂ���

                                                       // ��ނɉ������ꍇ����
    switch (m_type)
    {
        // �R���i
    case CEffect::TYPE_COVID:

        // �ړ��ʔ��f
        pos += m_move;

        // ��]
        m_fAngle += m_fRotSpeed;

        // �F��ύX
        CScene2D::SetColor(m_col);

        break;
    }

    // �ʒu�𔽉f
    SetPosition(pos);

    // �T�C�Y�𔽉f
    SetSize(size);

    // ���_���W��ύX
    SetRotVertex(m_fAngle);

    // �T�C�Y���Ȃ��Ȃ�A�����ɂȂ�A���C�t���Ȃ��Ȃ����疢�g�p��
    if (size.x < 0 || size.y < 0 || m_col.a < 0 || m_nLife <= 0)
    {
        bUse = false;
    }

    // ���̒e�A�X�e�[�W3�̉��A�_�ȊO�́A��ʊO�Ŗ��g�p��
    // �Q�[���O�Ȃ�
    if (OutGame2D(&pos, &size) == true)
    {
        // ���g�p��
        bUse = false;
    }

    // �g�p�̃t���O��false�Ȃ����
    if (bUse == false)
    {
        Uninit(); // �����艺�ɃR�[�h�͏����Ȃ�
    }
}

//========================================
// �G�t�F�N�g�̕`�揈��
//========================================
void CEffect::Draw(void)
{
    // �`�揈��
    CScene2D::Draw();
}

//========================================
// �G�t�F�N�g�̉摜���[�h����
//========================================
HRESULT CEffect::Load(void)
{
    // �����_���[����f�o�C�X�̎擾
    LPDIRECT3DDEVICE9 pDevice = CManager::GetRenderer()->GetDevice();

    //�e�N�X�`���̓ǂݍ���
    D3DXCreateTextureFromFile(pDevice, "data/TEXTURE/covid.png", &m_apTexture[CEffect::TYPE_COVID]);	    // �R���i

    return S_OK;
}

//========================================
// �G�t�F�N�g�̉摜�j������
//========================================
void CEffect::Unload(void)
{
    // �e�N�X�`���̔j��
    for (int nCntTexture = 0; nCntTexture < CEffect::TYPE_MAX; nCntTexture++)
    {
        if (m_apTexture[nCntTexture] != NULL)
        {
            m_apTexture[nCntTexture]->Release();
            m_apTexture[nCntTexture] = NULL;
        }
    }
}

//================================
// �G�t�F�N�g�̍쐬
//================================
CEffect *CEffect::Create(D3DXVECTOR3 pos, D3DXVECTOR3 size, D3DXVECTOR3 move, float fAngle, float fRotSpeed, D3DXCOLOR col, CEffect::TYPE type)
{
    // �ϐ��錾
    CEffect *pEffect = NULL;

    // ���������m��
    pEffect = new CEffect;

    // �^�C�v�̂݁A�e�N�X�`�������蓖�Ă̂��߂Ɍ��т��Ă���
    pEffect->m_type = type;

    // ������
    pEffect->Init(pos, size, D3DXVECTOR3(0.0f, 0.0f, 0.0f));

    // �����o�ϐ������т���
    pEffect->m_move = move;
    pEffect->m_fAngle = fAngle;
    pEffect->m_fRotSpeed = fRotSpeed;
    pEffect->m_col = col;

    return pEffect;
}