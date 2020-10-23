//=============================================================================
//
// �V�ѕ����� [manual.cpp]
// Author : �㓡�T�V��
//
//=============================================================================
#include "manual.h"
#include "input.h"
#include "manager.h"
#include "sound.h"
#include "ui.h"
#include "fade.h"

//=============================================================================
// �V�ѕ��̃R���X�g���N�^
//=============================================================================
CManual::CManual()
{
}

//=============================================================================
// �V�ѕ��̃f�X�g���N�^
//=============================================================================
CManual::~CManual()
{
}

//=============================================================================
// ����������
//=============================================================================
HRESULT CManual::Init(void)
{
    // ���̔w�i�𐶐�
    CUI::Create(MANUAL_POS, MANUAL_SIZE, DEFAULT_COLOR, CUI::TYPE_MANUAL);

    //// �w�i�̃C���X�^���X����
    //CBG::Create(CBG::BG_TYPE_MANUAL);

    //// UI�̃C���X�^���X����
    //CUi::Create(D3DXVECTOR3(SCREEN_WIDTH / 2, 250.0f, 0.0f), CTexture::TEXTURE_UI06, D3DXVECTOR3(600.0f, 300.0f, 0.0f), false);
    //CUi::Create(D3DXVECTOR3(SCREEN_WIDTH / 2, SCREEN_HEIGHT - 100.0f, 0.0f), CTexture::TEXTURE_UI07, D3DXVECTOR3(400.0f, UI_SIZE_Y, 0.0f), true);

    //// BGM���Đ�
    //CSound *pSound = CManager::GetSound();
    //pSound->Play(CSound::SOUND_LABEL_BGM002);

    return S_OK;
}

//=============================================================================
// �I������
//=============================================================================
void CManual::Uninit(void)
{
    // BGM���~
    CSound *pSound = CManager::GetSound();
    pSound->Stop(CSound::LABEL_BGM_TITLE);
}

//=============================================================================
// �X�V����
//=============================================================================
void CManual::Update(void)
{
    //�L�[�{�[�h�̊m�ۂ������������擾
    CInputKeyboard *pInputKeyboard = CManager::GetInputKeyboard();

    // �R���g���[�����擾
    CInputJoypad *pInputJoypad = CManager::GetInputJoypad();
    DIJOYSTATE2 Controller = pInputJoypad->GetController(PLAYER_1);

    if (pInputKeyboard->GetKeyboardTrigger(DIK_RETURN) || pInputJoypad->GetJoypadTrigger(PLAYER_1, CInputJoypad::BUTTON_START))
    {
        // �t�F�[�h���Ă��Ȃ��Ȃ�
        if (CFade::GetFade() == CFade::FADE_NONE)
        {
            //// ���艹�Đ�
            //CSound *pSound = CManager::GetSound();
            //pSound->Play(CSound::LABEL_SE_DECISION);

            // �Q�[�����[�h�Ɉڍs
            CFade::SetFade(CManager::MODE_GAME);
        }
    }
}
