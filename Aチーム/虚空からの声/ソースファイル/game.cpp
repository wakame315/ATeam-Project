//=============================================================================
//
// �Q�[������ [game.cpp]
// Author : �㓡�T�V��
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
// �}�N����`
//========================================

// �X�e�[�W�̃u���b�N��
#define MAX_BLOCK 256

// �X�^�[�g�ŃQ�[����Ԃ̊Ǘ�
#define START_ATTACK 210    // ��U�̍U���J�n

// �A�j���[�V�����ŃQ�[����Ԃ̊Ǘ�
#define ANIM_SET_CAMERA 2   // �J�����Z�b�g
#define ANIM_START 60       // �A�j���[�V�����X�^�[�g
#define ANIM_DAMAGE 150     // �_���[�W�v�Z�A���o
#define ANIM_END 240        // �A�j���[�V�����I��

//=============================================================================
// �ÓI�����o�ϐ��錾
//=============================================================================
CCharacter *CGame::m_pCharacter = {};

bool CGame::m_bFinishBattle = false;

CGame::STATE CGame::m_state = STATE_NORMAL;

CGame::STAGEDATE m_aStageDate[MAX_BLOCK] = {};

//=============================================================================
// �Q�[���̃R���X�g���N�^
//=============================================================================
CGame::CGame()
{
    m_nCntGameTime = 0;
    m_nCntFinishGame = 0;

    m_pCharacter = NULL;

    // �ÓI�����o�ϐ���������
    m_bFinishBattle = false;
    m_state = STATE_START;
}

//=============================================================================
// �Q�[���̃f�X�g���N�^
//=============================================================================
CGame::~CGame()
{

}

//=============================================================================
// ����������
//=============================================================================
HRESULT CGame::Init(void)
{
    //// ��ʉ��̔w�i�𐶐�
    //CUI::Create(GAME_UNDER_POS, GAME_UNDER_SIZE, DEFAULT_COLOR, CUI::TYPE_GAME_UNDER);

    //// UI�𐶐�
    //CUI::Create(UI_HP_PLAYER_POS, UI_HP_PLAYER_SIZE, DEFAULT_COLOR, CUI::TYPE_HP);
    //CUI::Create(UI_HP_ENEMY_POS, UI_HP_ENEMY_SIZE, DEFAULT_COLOR, CUI::TYPE_HP);
    //CUI::Create(UI_YOU_POS, UI_YOU_SIZE, DEFAULT_COLOR, CUI::TYPE_YOU);
    //CUI::Create(UI_ENEMY_POS, UI_ENEMY_SIZE, DEFAULT_COLOR, CUI::TYPE_ENEMY);
    //CUI::Create(UI_CARD_INFO_POS, UI_CARD_INFO_SIZE, DEFAULT_COLOR, CUI::TYPE_CARD_INFO_BG);
    //CUI::Create(UI_MANUAL_POS, UI_MANUAL_SIZE, DEFAULT_COLOR, CUI::TYPE_MANUAL);
    //CUI::Create(UI_WAIT_POS, UI_WAIT_SIZE, DEFAULT_COLOR, CUI::TYPE_WAIT);
    //CUI::Create(UI_NOW_LOADING_IN_GAME_POS, UI_NOW_LOADING_SIZE, DEFAULT_COLOR, CUI::TYPE_TITLE_UI04);

    //// �S�̃Q�[�W
    //CUI::Create(UI_STAMINA_POS, UI_STAMINA_SIZE, DEFAULT_COLOR, CUI::TYPE_STAMINA);
    //CUI::Create(UI_GAUGE_POS, UI_GAUGE_SIZE, DEFAULT_COLOR, CUI::TYPE_GAUGE);

    //// �v���C���[��UI�\��
    //CUI::Create(UI_PLAYER_1_POS, UI_PLAYER_1_SIZE, DEFAULT_COLOR, CUI::TYPE_PLAYER1);
    //CUI::Create(UI_PLAYER_2_POS, UI_PLAYER_2_SIZE, DEFAULT_COLOR, CUI::TYPE_PLAYER2);
    //CUI::Create(UI_PLAYER_3_POS, UI_PLAYER_3_SIZE, DEFAULT_COLOR, CUI::TYPE_PLAYER3);
    //CUI::Create(UI_PLAYER_4_POS, UI_PLAYER_4_SIZE, DEFAULT_COLOR, CUI::TYPE_PLAYER4);

    //// �X�s�[�J�[��UI�\��
    //CUI::Create(UI_SPEAKER_2_POS, UI_SPEAKER_2_SIZE, DEFAULT_COLOR, CUI::TYPE_SPEAKER2);
    //CUI::Create(UI_SPEAKER_3_POS, UI_SPEAKER_3_SIZE, DEFAULT_COLOR, CUI::TYPE_SPEAKER3);
    //CUI::Create(UI_SPEAKER_4_POS, UI_SPEAKER_4_SIZE, DEFAULT_COLOR, CUI::TYPE_SPEAKER4);

    //// ��������
    //CUI::Create(UI_TIME_POS, UI_TIME_SIZE, DEFAULT_COLOR, CUI::TYPE_TIME);

    //// �^�C�}�[�̐���
    //CTimer::Create(TIMER_POS, TIMER_SIZE);

    //// �o�g���X�^�[�g�\��
    //CUI::Create(UI_YOUR_TURN_POS, DEFAULT_VECTOR, DEFAULT_COLOR, CUI::TYPE_GAME_START);

    //// �L�����N�^�[�̐���
    //m_pCharacter = CCharacter::Create(D3DXVECTOR3(PLAYER1_FIRST_POS_X, 0.0f, PLAYER1_FIRST_POS_Z), D3DXVECTOR3(0.0f, 0.0f, 0.0f), CCharacter::TYPE_PLAYER1);

    // �u���b�N
	CCreateStage::LoadStage();

	// ���S�_�̐���
	//CUI::Create(D3DXVECTOR3(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2, 0.0f), D3DXVECTOR3(10.0f, 10.0f, 0.0f), DEFAULT_COLOR, CUI::TYPE_CURSOR);

    // �t�B�[���h�̐���
    //CField::Create();

    // �J�����̃��b�N�I���ꏊ
    CCamera::SetCameraLookAt(D3DXVECTOR3(0.0f, 0.0f, 0.0f));

    //// �X�J�C�{�b�N�X�̐���
    //CSky::Create();

    // BGM�A�������Đ�
    //CSound *pSound = CManager::GetSound();
    //pSound->Play(CSound::LABEL_BGM_GAME);
    //pSound->Play(CSound::LABEL_SE_005);

    return S_OK;
}

//=============================================================================
// �I������
//=============================================================================
void CGame::Uninit(void)
{
    // BGM�A�������~
    CSound *pSound = CManager::GetSound();
    pSound->Stop(CSound::LABEL_BGM_GAME);
    pSound->Stop(CSound::LABEL_SE_005);
}

//=============================================================================
// �X�V����
//=============================================================================
void CGame::Update(void)
{
    //// ���s����
    //Judgment();

    //// �Q�[����Ԃ̊Ǘ�
    //ManageState();
}

//=============================================================================
// ���s����
//=============================================================================
void CGame::Judgment(void)
{
    //// �S�̏���
    //if (m_pCharacter[PLAYER2]->GetUse() == false && m_pCharacter[PLAYER3]->GetUse() == false &&
    //    m_pCharacter[PLAYER4]->GetUse() == false)
    //{
    //    // ���s�����ĂȂ��Ȃ�
    //    if (m_bFinishBattle == false)
    //    {
    //        // �S���O����
    //        CSound *pSound = CManager::GetSound();
    //        pSound->Play(CSound::LABEL_SE_007);

    //        // �S�̏���
    //        CUI::Create(UI_JUDGMENT_POS, DEFAULT_VECTOR, DEFAULT_COLOR, CUI::TYPE_YOU_LOSE);
    //        m_bOrgeWin = true;

    //        // �����������[�V����
    //        m_pCharacter[PLAYER1]->GetAnimation()->SetAnimation(CAnimation::ANIM_PLEASURE);

    //        // ���s������
    //        m_bFinishBattle = true;

    //        // �^�C�g���ɍs���܂ł̎��Ԃ�ݒ�
    //        m_nCntFinishGame = COUNT_WAIT_FINISH;

    //        m_state = STATE_FINISH;
    //    }
    //}

    //// �l�̏���
    //if (CTimer::GetFinish() == true)
    //{
    //    // ���s�����ĂȂ��Ȃ�
    //    if (m_bFinishBattle == false)
    //    {
    //        // �S���O����
    //        CSound *pSound = CManager::GetSound();
    //        pSound->Play(CSound::LABEL_SE_007);

    //        // ����
    //        CUI::Create(UI_JUDGMENT_POS, DEFAULT_VECTOR, DEFAULT_COLOR, CUI::TYPE_YOU_WIN);
    //        m_bOrgeWin = false;

    //        // �S��������
    //        m_pCharacter[PLAYER1]->GetAnimation()->SetAnimation(CAnimation::ANIM_REGRET);

    //        // �����������[�V����
    //        m_pCharacter[PLAYER2]->GetAnimation()->SetAnimation(CAnimation::ANIM_PLEASURE);
    //        m_pCharacter[PLAYER3]->GetAnimation()->SetAnimation(CAnimation::ANIM_PLEASURE);
    //        m_pCharacter[PLAYER4]->GetAnimation()->SetAnimation(CAnimation::ANIM_PLEASURE);

    //        // ���s������
    //        m_bFinishBattle = true;

    //        // �^�C�g���ɍs���܂ł̎��Ԃ�ݒ�
    //        m_nCntFinishGame = COUNT_WAIT_FINISH;

    //        m_state = STATE_FINISH;
    //    }
    //}

    // ���U���g�ɍs���܂ł̃J�E���^
    if (m_nCntFinishGame > 0)
    {
        m_nCntFinishGame--;

        // 0�ɂȂ�������
        if (m_nCntFinishGame == 0)
        {
            // �t�F�[�h���Ă��Ȃ��Ȃ�
            if (CFade::GetFade() == CFade::FADE_NONE)
            {
                // ���U���g�Ɉڍs
                CFade::SetFade(CManager::MODE_RESULT);
            }
        }
    }
}

//=============================================================================
// �Q�[����Ԃ̊Ǘ�
//=============================================================================
void CGame::ManageState(void)
{
    // �����擾
    CSound *pSound = CManager::GetSound();

    switch (m_state)
    {
    case STATE_START:

        // �J�E���^�����Z
        m_nCntGameTime++;

        if (m_nCntGameTime == START_ATTACK)
        {
            //// �U���^�[����UI�𐶐�
            //CUI::Create(UI_YOUR_TURN_POS, DEFAULT_VECTOR, DEFAULT_COLOR, CUI::TYPE_ATTACK_START);

            // �S���O�P��
            CSound *pSound = CManager::GetSound();
            pSound->Play(CSound::LABEL_SE_006);

            // �J�E���^���Z�b�g
            m_nCntGameTime = 0;

            // ��ԃ��Z�b�g
            m_state = STATE_NORMAL;
        }

        break;

    case STATE_NORMAL:

        // �v���C���[�̍s��
        PlayerMovement();

        break;

    case STATE_FINISH:

        break;
    }
}

//=============================================================================
// �v���C���[1�̍s��
//=============================================================================
void CGame::PlayerMovement(void)
{
    // ���������߂�
    float fSpeed = PLAYER_SPEED;

    Movement(PLAYER1, fSpeed);

    // �I�[������
    SetAura(m_pCharacter->GetPos());
}

//=============================================================================
// �I�[������
//=============================================================================
void CGame::SetAura(D3DXVECTOR3 pos)
{

}

//=============================================================================
// ��������
//=============================================================================
void CGame::SetExplosion(D3DXVECTOR3 pos)
{
}

//=============================================================================
// �s��
//=============================================================================
void CGame::Movement(int nCnt, float fSpeed)
{
    // �R���g���[�����擾
    CInputJoypad *pInputJoypad = CManager::GetInputJoypad();
    DIJOYSTATE2 Controller = pInputJoypad->GetController(nCnt);

    // �ʒu�ƌ����ƈړ��ʂ��擾
    D3DXVECTOR3 pos = DEFAULT_VECTOR;
    D3DXVECTOR3 rot = DEFAULT_VECTOR;
    D3DXVECTOR3 move = DEFAULT_VECTOR;
    pos = m_pCharacter->GetPos();
    rot = m_pCharacter->GetRot();
    move = m_pCharacter->GetMove();

    // 1F�O�̈ʒu���L��
    m_pCharacter->SetPosOld(pos);

    //�m�b�N�o�b�N�𐧌�
    if (move.x != 0.0f || move.z != 0.0f)
    {
        move.x *= 0.8f;
        move.z *= 0.8f;
    }

    // �ړ��ʂƈʒu�����т���
    pos += move;

    // �v���C���[�������Ă��Ȃ��Ƃ�
    D3DXVECTOR3 lengthCheckVec = DEFAULT_VECTOR;
    lengthCheckVec.y = 0;
    if (D3DXVec3Length(&lengthCheckVec) <= 1.5f)
    {
        m_pCharacter->GetAnimation()->SetAnimation(CAnimation::ANIM_IDLE);//���[�V������ҋ@�ɂ���
    }

    if (Controller.lY != 0 || Controller.lX != 0)
    {// �X�e�B�b�N���|��Ă���Ȃ�ړ�

        float fAngle = atan2(Controller.lX, Controller.lY*-1);//�X�e�B�b�N�̊p�x�����߂�
        float fPlayerAngle = atan2(Controller.lX*-1, Controller.lY);//�X�e�B�b�N�̊p�x�����߂�

        pos.x += sinf(fAngle)*fSpeed;
        pos.z += cosf(fAngle)*fSpeed;
        m_pCharacter->GetAnimation()->SetAnimation(CAnimation::ANIM_MOVE);   //���[�V����������ɂ���

        //�L�����̌�����ς���
        rot.y = fPlayerAngle;
    }

    //// �u���b�N�Ƃ̓����蔻��
    //for (int nCntScene = 0; nCntScene < MAX_OBJECT; nCntScene++)
    //{
    //    // �V�[�����擾
    //    CScene *pScene = CScene::GetScene(nCntScene);

    //    // ���g������Ȃ�
    //    if (pScene != NULL)
    //    {
    //        // �^�C�v���擾
    //        CScene::OBJTYPE objType = pScene->GetObjType();

    //        // �u���b�N�Ȃ�A
    //        if (objType == CScene::OBJTYPE_BLOCK)
    //        {
    //            // �V�[��3D�ɃL���X�g
    //            CScene3D *pScene3D = (CScene3D*)pScene;

    //            // �L�����N�^�[�̓����蔻��̃T�C�Y��ݒ�
    //            D3DXVECTOR3 playerCollisionSize = PLAYER_COLLISION_SIZE;
    //            D3DXVECTOR3 blockCollisionSize = BLOCK_COLLISION_SIZE;

    //            // �����蔻����v�Z
    //            pos = (BlockCollision3D(&pos, &m_apCharacter[nCnt]->GetPosOld(), &pScene3D->GetPos(),
    //                &playerCollisionSize, &blockCollisionSize));
    //        }
    //    }
    //}

    // �ʒu�ƌ����ƈړ��ʂ𔽉f
    m_pCharacter->SetPos(pos);
    m_pCharacter->SetRot(rot);
    m_pCharacter->SetMove(move);
}