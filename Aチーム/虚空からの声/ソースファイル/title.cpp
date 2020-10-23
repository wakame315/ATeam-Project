//=============================================================================
//
// �^�C�g������ [title.cpp]
// Author : �㓡�T�V��
//
//=============================================================================
#include "title.h"
#include "input.h"
#include "manager.h"
#include "sound.h"
#include "ui.h"
#include "fade.h"
#include "game.h"
//#include "bg.h"

//=============================================================================
// �^�C�g���̃R���X�g���N�^
//=============================================================================
CTitle::CTitle()
{
    m_nCntTime = 0;
    m_bNextScene = false;
    m_bStartMatching = false;
}

//=============================================================================
// �^�C�g���̃f�X�g���N�^
//=============================================================================
CTitle::~CTitle()
{
}

//=============================================================================
// ����������
//=============================================================================
HRESULT CTitle::Init(void)
{
    //// �w�i�𐶐�
    //CBg::Create(BG_POS, BG_SIZE, DEFAULT_COLOR, CBg::TYPE_TITLE_BG);

    // ���S�𐶐�
    CUI::Create(TITLE_LOGO_FIRST_POS, TITLE_LOGO_SIZE, DEFAULT_COLOR, CUI::TYPE_TITLE_LOGO);

    // �o�[�W�����𐶐�
    CUI::Create(VERSION_POS, VERSION_SIZE, DEFAULT_COLOR, CUI::TYPE_VERSION);

    // �v���X�X�^�[�g
    CUI::Create(PRESS_START_POS, PRESS_START_SIZE, DEFAULT_COLOR, CUI::TYPE_PRESS_START);

    // BGM���Đ�
    CSound *pSound = CManager::GetSound();
    pSound->Play(CSound::LABEL_BGM_TITLE);

    return S_OK;
}

//=============================================================================
// �I������
//=============================================================================
void CTitle::Uninit(void)
{
    // BGM���~
    CSound *pSound = CManager::GetSound();
    pSound->Stop(CSound::LABEL_BGM_TITLE);
}

//=============================================================================
// �X�V����
//=============================================================================
void CTitle::Update(void)
{
    // �^�C�g���̎��Ԃ��J�E���g
    m_nCntTime++;

    // �^�C�g���̍ő厞��
    if (m_nCntTime > TITLE_MAX_TIME)
    {
        m_nCntTime = TITLE_MAX_TIME;
    }

    //�L�[�{�[�h�̊m�ۂ������������擾
    CInputKeyboard *pInputKeyboard = CManager::GetInputKeyboard();

    // �R���g���[�����擾
    CInputJoypad *pInputJoypad = CManager::GetInputJoypad();
    DIJOYSTATE2 Controller = pInputJoypad->GetController(PLAYER_1);

    // �J�ڂ̃t���O��true�Ȃ�
    if (m_bNextScene == true)
    {
        // �G���^�[�A�܂��̓X�^�[�g�{�^������������
        if (pInputKeyboard->GetKeyboardTrigger(DIK_RETURN) || pInputJoypad->GetJoypadTrigger(PLAYER_1, CInputJoypad::BUTTON_START))
        {
            // �t�F�[�h���Ă��Ȃ��Ȃ�
            if (CFade::GetFade() == CFade::FADE_NONE)
            {
                //// ���艹�Đ�
                //CSound *pSound = CManager::GetSound();
                //pSound->Play(CSound::LABEL_SE_DECISION);

                // �V�ѕ����[�h�Ɉڍs
                CFade::SetFade(CManager::MODE_MANUAL);
            }
        }
    }
    // �J�ڂ̃t���O��false�Ȃ�
    else
    {
        // ��莞�Ԍo�߂őJ�ډ\��
        if (m_nCntTime >= TITLE_NEXT_SCENE)
        {
            m_bNextScene = true;
        }
        // ��莞�Ԍo�߂��Ă��Ȃ��Ă�
        else
        {
            // �G���^�[�A�܂��̓X�^�[�g�{�^������������
            if (pInputKeyboard->GetKeyboardTrigger(DIK_RETURN) || pInputJoypad->GetJoypadTrigger(PLAYER_1, CInputJoypad::BUTTON_START))
            {
                // �J�ډ\��
                m_bNextScene = true;
            }
        }
    }
}
