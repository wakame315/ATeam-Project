//=============================================================================
//
// タイトル処理 [title.cpp]
// Author : 後藤慎之助
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
// タイトルのコンストラクタ
//=============================================================================
CTitle::CTitle()
{
    m_nCntTime = 0;
    m_bNextScene = false;
    m_bStartMatching = false;
}

//=============================================================================
// タイトルのデストラクタ
//=============================================================================
CTitle::~CTitle()
{
}

//=============================================================================
// 初期化処理
//=============================================================================
HRESULT CTitle::Init(void)
{
    //// 背景を生成
    //CBg::Create(BG_POS, BG_SIZE, DEFAULT_COLOR, CBg::TYPE_TITLE_BG);

    // ロゴを生成
    CUI::Create(TITLE_LOGO_FIRST_POS, TITLE_LOGO_SIZE, DEFAULT_COLOR, CUI::TYPE_TITLE_LOGO);

    // バージョンを生成
    CUI::Create(VERSION_POS, VERSION_SIZE, DEFAULT_COLOR, CUI::TYPE_VERSION);

    // プレススタート
    CUI::Create(PRESS_START_POS, PRESS_START_SIZE, DEFAULT_COLOR, CUI::TYPE_PRESS_START);

    // BGMを再生
    CSound *pSound = CManager::GetSound();
    pSound->Play(CSound::LABEL_BGM_TITLE);

    return S_OK;
}

//=============================================================================
// 終了処理
//=============================================================================
void CTitle::Uninit(void)
{
    // BGMを停止
    CSound *pSound = CManager::GetSound();
    pSound->Stop(CSound::LABEL_BGM_TITLE);
}

//=============================================================================
// 更新処理
//=============================================================================
void CTitle::Update(void)
{
    // タイトルの時間をカウント
    m_nCntTime++;

    // タイトルの最大時間
    if (m_nCntTime > TITLE_MAX_TIME)
    {
        m_nCntTime = TITLE_MAX_TIME;
    }

    //キーボードの確保したメモリを取得
    CInputKeyboard *pInputKeyboard = CManager::GetInputKeyboard();

    // コントローラを取得
    CInputJoypad *pInputJoypad = CManager::GetInputJoypad();
    DIJOYSTATE2 Controller = pInputJoypad->GetController(PLAYER_1);

    // 遷移のフラグがtrueなら
    if (m_bNextScene == true)
    {
        // エンター、またはスタートボタンを押したら
        if (pInputKeyboard->GetKeyboardTrigger(DIK_RETURN) || pInputJoypad->GetJoypadTrigger(PLAYER_1, CInputJoypad::BUTTON_START))
        {
            // フェードしていないなら
            if (CFade::GetFade() == CFade::FADE_NONE)
            {
                //// 決定音再生
                //CSound *pSound = CManager::GetSound();
                //pSound->Play(CSound::LABEL_SE_DECISION);

                // 遊び方モードに移行
                CFade::SetFade(CManager::MODE_MANUAL);
            }
        }
    }
    // 遷移のフラグがfalseなら
    else
    {
        // 一定時間経過で遷移可能に
        if (m_nCntTime >= TITLE_NEXT_SCENE)
        {
            m_bNextScene = true;
        }
        // 一定時間経過していなくても
        else
        {
            // エンター、またはスタートボタンを押したら
            if (pInputKeyboard->GetKeyboardTrigger(DIK_RETURN) || pInputJoypad->GetJoypadTrigger(PLAYER_1, CInputJoypad::BUTTON_START))
            {
                // 遷移可能に
                m_bNextScene = true;
            }
        }
    }
}
