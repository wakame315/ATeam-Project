//=============================================================================
//
// ゲーム処理 [game.cpp]
// Author : 後藤慎之助
//
//=============================================================================

#define _CRT_SECURE_NO_WARNINGS

#include "game.h"
#include "manager.h"
#include "sound.h"
#include "ui.h"
//#include "sky.h"
//#include "ui3d.h"
#include "animation.h"
#include "camera.h"
#include "fade.h"
//#include "manual.h"
//#include "button.h"
#include "block.h"
#include "character.h"
#include "input.h"
#include "scene.h"
#include "library.h"
#include "effect3d.h"
#include "field.h"
#include "timer.h"
#include "CreateStage.h"

//========================================
// マクロ定義
//========================================

// ステージのブロック数
#define MAX_BLOCK 256

// スタートでゲーム状態の管理
#define START_ATTACK 210    // 先攻の攻撃開始

// アニメーションでゲーム状態の管理
#define ANIM_SET_CAMERA 2   // カメラセット
#define ANIM_START 60       // アニメーションスタート
#define ANIM_DAMAGE 150     // ダメージ計算、演出
#define ANIM_END 240        // アニメーション終了

//=============================================================================
// 静的メンバ変数宣言
//=============================================================================
CCharacter *CGame::m_pCharacter = {};

bool CGame::m_bFinishBattle = false;

CGame::STATE CGame::m_state = STATE_NORMAL;

CGame::STAGEDATE m_aStageDate[MAX_BLOCK] = {};

//=============================================================================
// ゲームのコンストラクタ
//=============================================================================
CGame::CGame()
{
    m_nCntGameTime = 0;
    m_nCntFinishGame = 0;

    m_pCharacter = NULL;

    // 静的メンバ変数を初期化
    m_bFinishBattle = false;
    m_state = STATE_START;
}

//=============================================================================
// ゲームのデストラクタ
//=============================================================================
CGame::~CGame()
{

}

//=============================================================================
// 初期化処理
//=============================================================================
HRESULT CGame::Init(void)
{
    //// 画面下の背景を生成
    //CUI::Create(GAME_UNDER_POS, GAME_UNDER_SIZE, DEFAULT_COLOR, CUI::TYPE_GAME_UNDER);

    //// UIを生成
    //CUI::Create(UI_HP_PLAYER_POS, UI_HP_PLAYER_SIZE, DEFAULT_COLOR, CUI::TYPE_HP);
    //CUI::Create(UI_HP_ENEMY_POS, UI_HP_ENEMY_SIZE, DEFAULT_COLOR, CUI::TYPE_HP);
    //CUI::Create(UI_YOU_POS, UI_YOU_SIZE, DEFAULT_COLOR, CUI::TYPE_YOU);
    //CUI::Create(UI_ENEMY_POS, UI_ENEMY_SIZE, DEFAULT_COLOR, CUI::TYPE_ENEMY);
    //CUI::Create(UI_CARD_INFO_POS, UI_CARD_INFO_SIZE, DEFAULT_COLOR, CUI::TYPE_CARD_INFO_BG);
    //CUI::Create(UI_MANUAL_POS, UI_MANUAL_SIZE, DEFAULT_COLOR, CUI::TYPE_MANUAL);
    //CUI::Create(UI_WAIT_POS, UI_WAIT_SIZE, DEFAULT_COLOR, CUI::TYPE_WAIT);
    //CUI::Create(UI_NOW_LOADING_IN_GAME_POS, UI_NOW_LOADING_SIZE, DEFAULT_COLOR, CUI::TYPE_TITLE_UI04);

    //// 鬼のゲージ
    //CUI::Create(UI_STAMINA_POS, UI_STAMINA_SIZE, DEFAULT_COLOR, CUI::TYPE_STAMINA);
    //CUI::Create(UI_GAUGE_POS, UI_GAUGE_SIZE, DEFAULT_COLOR, CUI::TYPE_GAUGE);

    //// プレイヤーのUI表示
    //CUI::Create(UI_PLAYER_1_POS, UI_PLAYER_1_SIZE, DEFAULT_COLOR, CUI::TYPE_PLAYER1);
    //CUI::Create(UI_PLAYER_2_POS, UI_PLAYER_2_SIZE, DEFAULT_COLOR, CUI::TYPE_PLAYER2);
    //CUI::Create(UI_PLAYER_3_POS, UI_PLAYER_3_SIZE, DEFAULT_COLOR, CUI::TYPE_PLAYER3);
    //CUI::Create(UI_PLAYER_4_POS, UI_PLAYER_4_SIZE, DEFAULT_COLOR, CUI::TYPE_PLAYER4);

    //// スピーカーのUI表示
    //CUI::Create(UI_SPEAKER_2_POS, UI_SPEAKER_2_SIZE, DEFAULT_COLOR, CUI::TYPE_SPEAKER2);
    //CUI::Create(UI_SPEAKER_3_POS, UI_SPEAKER_3_SIZE, DEFAULT_COLOR, CUI::TYPE_SPEAKER3);
    //CUI::Create(UI_SPEAKER_4_POS, UI_SPEAKER_4_SIZE, DEFAULT_COLOR, CUI::TYPE_SPEAKER4);

    //// 制限時間
    //CUI::Create(UI_TIME_POS, UI_TIME_SIZE, DEFAULT_COLOR, CUI::TYPE_TIME);

    //// タイマーの生成
    //CTimer::Create(TIMER_POS, TIMER_SIZE);

    //// バトルスタート表示
    //CUI::Create(UI_YOUR_TURN_POS, DEFAULT_VECTOR, DEFAULT_COLOR, CUI::TYPE_GAME_START);

    //// キャラクターの生成
    //m_pCharacter = CCharacter::Create(D3DXVECTOR3(PLAYER1_FIRST_POS_X, 0.0f, PLAYER1_FIRST_POS_Z), D3DXVECTOR3(0.0f, 0.0f, 0.0f), CCharacter::TYPE_PLAYER1);

    // ブロック
	CCreateStage::LoadStage();

	// 中心点の生成
	//CUI::Create(D3DXVECTOR3(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2, 0.0f), D3DXVECTOR3(10.0f, 10.0f, 0.0f), DEFAULT_COLOR, CUI::TYPE_CURSOR);

    // フィールドの生成
    //CField::Create();

    // カメラのロックオン場所
    CCamera::SetCameraLookAt(D3DXVECTOR3(0.0f, 0.0f, 0.0f));

    //// スカイボックスの生成
    //CSky::Create();

    // BGM、歓声を再生
    //CSound *pSound = CManager::GetSound();
    //pSound->Play(CSound::LABEL_BGM_GAME);
    //pSound->Play(CSound::LABEL_SE_005);

    return S_OK;
}

//=============================================================================
// 終了処理
//=============================================================================
void CGame::Uninit(void)
{
    // BGM、歓声を停止
    CSound *pSound = CManager::GetSound();
    pSound->Stop(CSound::LABEL_BGM_GAME);
    pSound->Stop(CSound::LABEL_SE_005);
}

//=============================================================================
// 更新処理
//=============================================================================
void CGame::Update(void)
{
    //// 勝敗判定
    //Judgment();

    //// ゲーム状態の管理
    //ManageState();
}

//=============================================================================
// 勝敗判定
//=============================================================================
void CGame::Judgment(void)
{
    //// 鬼の勝ち
    //if (m_pCharacter[PLAYER2]->GetUse() == false && m_pCharacter[PLAYER3]->GetUse() == false &&
    //    m_pCharacter[PLAYER4]->GetUse() == false)
    //{
    //    // 勝敗がついてないなら
    //    if (m_bFinishBattle == false)
    //    {
    //        // ゴング複数
    //        CSound *pSound = CManager::GetSound();
    //        pSound->Play(CSound::LABEL_SE_007);

    //        // 鬼の勝ち
    //        CUI::Create(UI_JUDGMENT_POS, DEFAULT_VECTOR, DEFAULT_COLOR, CUI::TYPE_YOU_LOSE);
    //        m_bOrgeWin = true;

    //        // 自分勝ちモーション
    //        m_pCharacter[PLAYER1]->GetAnimation()->SetAnimation(CAnimation::ANIM_PLEASURE);

    //        // 勝敗がついた
    //        m_bFinishBattle = true;

    //        // タイトルに行くまでの時間を設定
    //        m_nCntFinishGame = COUNT_WAIT_FINISH;

    //        m_state = STATE_FINISH;
    //    }
    //}

    //// 人の勝ち
    //if (CTimer::GetFinish() == true)
    //{
    //    // 勝敗がついてないなら
    //    if (m_bFinishBattle == false)
    //    {
    //        // ゴング複数
    //        CSound *pSound = CManager::GetSound();
    //        pSound->Play(CSound::LABEL_SE_007);

    //        // 勝ち
    //        CUI::Create(UI_JUDGMENT_POS, DEFAULT_VECTOR, DEFAULT_COLOR, CUI::TYPE_YOU_WIN);
    //        m_bOrgeWin = false;

    //        // 鬼悔しがり
    //        m_pCharacter[PLAYER1]->GetAnimation()->SetAnimation(CAnimation::ANIM_REGRET);

    //        // 自分勝ちモーション
    //        m_pCharacter[PLAYER2]->GetAnimation()->SetAnimation(CAnimation::ANIM_PLEASURE);
    //        m_pCharacter[PLAYER3]->GetAnimation()->SetAnimation(CAnimation::ANIM_PLEASURE);
    //        m_pCharacter[PLAYER4]->GetAnimation()->SetAnimation(CAnimation::ANIM_PLEASURE);

    //        // 勝敗がついた
    //        m_bFinishBattle = true;

    //        // タイトルに行くまでの時間を設定
    //        m_nCntFinishGame = COUNT_WAIT_FINISH;

    //        m_state = STATE_FINISH;
    //    }
    //}

    // リザルトに行くまでのカウンタ
    if (m_nCntFinishGame > 0)
    {
        m_nCntFinishGame--;

        // 0になった時に
        if (m_nCntFinishGame == 0)
        {
            // フェードしていないなら
            if (CFade::GetFade() == CFade::FADE_NONE)
            {
                // リザルトに移行
                CFade::SetFade(CManager::MODE_RESULT);
            }
        }
    }
}

//=============================================================================
// ゲーム状態の管理
//=============================================================================
void CGame::ManageState(void)
{
    // 音を取得
    CSound *pSound = CManager::GetSound();

    switch (m_state)
    {
    case STATE_START:

        // カウンタを加算
        m_nCntGameTime++;

        if (m_nCntGameTime == START_ATTACK)
        {
            //// 攻撃ターンのUIを生成
            //CUI::Create(UI_YOUR_TURN_POS, DEFAULT_VECTOR, DEFAULT_COLOR, CUI::TYPE_ATTACK_START);

            // ゴング単発
            CSound *pSound = CManager::GetSound();
            pSound->Play(CSound::LABEL_SE_006);

            // カウンタリセット
            m_nCntGameTime = 0;

            // 状態リセット
            m_state = STATE_NORMAL;
        }

        break;

    case STATE_NORMAL:

        // プレイヤーの行動
        PlayerMovement();

        break;

    case STATE_FINISH:

        break;
    }
}

//=============================================================================
// プレイヤー1の行動
//=============================================================================
void CGame::PlayerMovement(void)
{
    // 速さを決める
    float fSpeed = PLAYER_SPEED;

    Movement(PLAYER1, fSpeed);

    // オーラ発生
    SetAura(m_pCharacter->GetPos());
}

//=============================================================================
// オーラ発生
//=============================================================================
void CGame::SetAura(D3DXVECTOR3 pos)
{

}

//=============================================================================
// 爆発発生
//=============================================================================
void CGame::SetExplosion(D3DXVECTOR3 pos)
{
}

//=============================================================================
// 行動
//=============================================================================
void CGame::Movement(int nCnt, float fSpeed)
{
    // コントローラを取得
    CInputJoypad *pInputJoypad = CManager::GetInputJoypad();
    DIJOYSTATE2 Controller = pInputJoypad->GetController(nCnt);

    // 位置と向きと移動量を取得
    D3DXVECTOR3 pos = DEFAULT_VECTOR;
    D3DXVECTOR3 rot = DEFAULT_VECTOR;
    D3DXVECTOR3 move = DEFAULT_VECTOR;
    pos = m_pCharacter->GetPos();
    rot = m_pCharacter->GetRot();
    move = m_pCharacter->GetMove();

    // 1F前の位置を記憶
    m_pCharacter->SetPosOld(pos);

    //ノックバックを制御
    if (move.x != 0.0f || move.z != 0.0f)
    {
        move.x *= 0.8f;
        move.z *= 0.8f;
    }

    // 移動量と位置を結びつける
    pos += move;

    // プレイヤーが動いていないとき
    D3DXVECTOR3 lengthCheckVec = DEFAULT_VECTOR;
    lengthCheckVec.y = 0;
    if (D3DXVec3Length(&lengthCheckVec) <= 1.5f)
    {
        m_pCharacter->GetAnimation()->SetAnimation(CAnimation::ANIM_IDLE);//モーションを待機にする
    }

    if (Controller.lY != 0 || Controller.lX != 0)
    {// スティックが倒れているなら移動

        float fAngle = atan2(Controller.lX, Controller.lY*-1);//スティックの角度を求める
        float fPlayerAngle = atan2(Controller.lX*-1, Controller.lY);//スティックの角度を求める

        pos.x += sinf(fAngle)*fSpeed;
        pos.z += cosf(fAngle)*fSpeed;
        m_pCharacter->GetAnimation()->SetAnimation(CAnimation::ANIM_MOVE);   //モーションを歩きにする

        //キャラの向きを変える
        rot.y = fPlayerAngle;
    }

    //// ブロックとの当たり判定
    //for (int nCntScene = 0; nCntScene < MAX_OBJECT; nCntScene++)
    //{
    //    // シーンを取得
    //    CScene *pScene = CScene::GetScene(nCntScene);

    //    // 中身があるなら
    //    if (pScene != NULL)
    //    {
    //        // タイプを取得
    //        CScene::OBJTYPE objType = pScene->GetObjType();

    //        // ブロックなら、
    //        if (objType == CScene::OBJTYPE_BLOCK)
    //        {
    //            // シーン3Dにキャスト
    //            CScene3D *pScene3D = (CScene3D*)pScene;

    //            // キャラクターの当たり判定のサイズを設定
    //            D3DXVECTOR3 playerCollisionSize = PLAYER_COLLISION_SIZE;
    //            D3DXVECTOR3 blockCollisionSize = BLOCK_COLLISION_SIZE;

    //            // 当たり判定を計算
    //            pos = (BlockCollision3D(&pos, &m_apCharacter[nCnt]->GetPosOld(), &pScene3D->GetPos(),
    //                &playerCollisionSize, &blockCollisionSize));
    //        }
    //    }
    //}

    // 位置と向きと移動量を反映
    m_pCharacter->SetPos(pos);
    m_pCharacter->SetRot(rot);
    m_pCharacter->SetMove(move);
}