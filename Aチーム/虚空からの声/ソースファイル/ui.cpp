//===============================================
//
// UI���� (ui.cpp)
// Author : �㓡�T�V��
//
//===============================================

//========================
// �C���N���[�h�t�@�C��
//========================
#include "ui.h"
#include "manager.h"
#include "renderer.h"
#include "library.h"
#include "game.h"
#include "input.h"
#include "title.h"
//#include "character.h"

//=======================================
// �ÓI�����o�ϐ��錾
//=======================================
LPDIRECT3DTEXTURE9 CUI::m_apTexture[CUI::TYPE_MAX] = {};

//========================================
// UI�̃R���X�g���N�^
//========================================
CUI::CUI() :CScene2D(OBJTYPE::OBJTYPE_UI)
{
    m_move = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
    //m_size = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
    m_col = DEFAULT_COLOR;
    m_type = CUI::TYPE_NONE;
    m_fAngle = 0.0f;
    m_bUse = true;
    m_bBlinking = false;
    m_nCntTime = 0;
    m_bFadeOut = false;
    m_bFirstGetSize = false;
}

//========================================
// UI�̃f�X�g���N�^
//========================================
CUI::~CUI()
{

}

//========================================
// UI�̏���������
//========================================
HRESULT CUI::Init(D3DXVECTOR3 pos, D3DXVECTOR3 size, D3DXVECTOR3 rot)
{
    // ������
    CScene2D::Init(pos, size, D3DXVECTOR3(0.0f, 0.0f, 0.0f));

    // �e�N�X�`�������蓖��
    BindTexture(m_apTexture[m_type]);

    return S_OK;
}

//========================================
// UI�̏I������
//========================================
void CUI::Uninit(void)
{
    // �I������
    CScene2D::Uninit();
}

//========================================
// UI�̍X�V����
//========================================
void CUI::Update(void)
{
    // �ϐ��錾
    D3DXVECTOR3 pos = GetPosition();                   // �ʒu���擾
    D3DXVECTOR3 size = GetSize();                      // �T�C�Y���擾
    int nPatternAnim = 0;                              // �p�^�[���A�j���̃J�E���^�𗘗p����Ƃ�

                                                       //�L�[�{�[�h�̊m�ۂ������������擾
    CInputKeyboard *pInputKeyboard = CManager::GetInputKeyboard();

    // �R���g���[�����擾
    CInputJoypad *pInputJoypad = CManager::GetInputJoypad();
    DIJOYSTATE2 Controller = pInputJoypad->GetController(PLAYER_1);

    int nPlayer2Wave = 0;
    int nPlayer3Wave = 0;
    int nPlayer4Wave = 0;

    if (CManager::GetMode() == CManager::MODE_GAME)
    {
        //nPlayer2Wave = CGame::GetPlayer(PLAYER2)->GetWave();
        //nPlayer3Wave = CGame::GetPlayer(PLAYER3)->GetWave();
        //nPlayer4Wave = CGame::GetPlayer(PLAYER4)->GetWave();
    }

    switch (m_type)
    {
    case TYPE_TITLE_LOGO:

        // ���ꗎ����
        pos.y += TITLE_LOGO_FLOW_DOWN_SPEED;

        // ���̒l�Ŏ~�߂Ă���
        if (pos.y >= TITLE_LOGO_TARGET_POS_Y)
        {
            pos.y = TITLE_LOGO_TARGET_POS_Y;
        }

        // �G���^�[�A�܂��̓X�^�[�g�{�^������������
        if (pInputKeyboard->GetKeyboardTrigger(DIK_RETURN) || pInputJoypad->GetJoypadTrigger(PLAYER_1, CInputJoypad::BUTTON_START))
        {
            // �^�C�g�����S�������ɉ���
            pos.y = TITLE_LOGO_TARGET_POS_Y;
        }

        break;

    case TYPE_PRESS_START:

        // �^�C�g���̎��Ԃ��J�E���g
        m_nCntTime++;

        // �^�C�g���̍ő厞��
        if (m_nCntTime > TITLE_MAX_TIME)
        {
            m_nCntTime = TITLE_MAX_TIME;
        }

        // �F��ς���
        if (m_bFadeOut == true)
        {
            m_col.r -= PRESS_START_FADE_RATE;
            m_col.g -= PRESS_START_FADE_RATE;
            m_col.b -= PRESS_START_FADE_RATE;
        }
        else
        {
            m_col.r += PRESS_START_FADE_RATE;
            m_col.g += PRESS_START_FADE_RATE;
            m_col.b += PRESS_START_FADE_RATE;
        }
        if (m_col.r <= PRESS_START_FADE_OUT_MIN)
        {
            m_bFadeOut = false;
        }
        else if (m_col.r >= 1.0f)
        {
            m_bFadeOut = true;
        }

        // �G���^�[�A�܂��̓X�^�[�g�{�^������������
        if (pInputKeyboard->GetKeyboardTrigger(DIK_RETURN) || pInputJoypad->GetJoypadTrigger(PLAYER_1, CInputJoypad::BUTTON_START))
        {
            // ��莞�Ԍo�߂œ_�ŉ\��
            if (m_nCntTime >= TITLE_NEXT_SCENE)
            {
                // �_�ł̃t���O��true��
                m_bBlinking = true;
            }
            // ����ȊO�́A�J�E���^��J�ډ\�܂ň�C�ɐi�߂�
            else
            {
                m_nCntTime = TITLE_NEXT_SCENE;
            }
        }

        // �_�ł���Ȃ�
        if (m_bBlinking == true)
        {
            // �}�b�`���O�ҋ@���A�ڂ��`�J�`�J����̂ł�߂�
            //// �J�E���^�[��i�߂āA�p�^�[����؂�ւ���
            //nPatternAnim = CountAnimation(2, 2);

            //// �F��2�p�^�[���Ő؂�ւ���
            //if (nPatternAnim == 1)
            //{
            //    m_col.r = PRESS_START_FADE_OUT_MIN;
            //    m_col.g = PRESS_START_FADE_OUT_MIN;
            //    m_col.b = PRESS_START_FADE_OUT_MIN;
            //}
            //else
            //{
            //    m_col.r = 1.0f;
            //    m_col.g = 1.0f;
            //    m_col.b = 1.0f;
            //}
        }

        break;

    case TYPE_GAME_UNDER:

        // �퓬�I�����A����
        GameFinishFade();

        break;

    case TYPE_CARD_INFO_BG:

        // �퓬�I�����A����
        GameFinishFade();

        break;

    case TYPE_GAME_START:

        // �g��
        size = Extend(size);

        // �퓬�I�����A����
        GameFinishFade();

        break;

    case TYPE_ATTACK_START:

        // �g��
        size = Extend(size);

        // �퓬�I�����A����
        GameFinishFade();

        break;

    case TYPE_DEFENCE_START:

        // �g��
        size = Extend(size);

        // �퓬�I�����A����
        GameFinishFade();

        break;

    case TYPE_YOU_LOSE:

        // �g��
        size = Extend(size);

        break;

    case TYPE_YOU_WIN:

        // �g��
        size = Extend(size);

        break;

    case TYPE_DISCONNECT:

        // �g��
        size = Extend(size);

        break;

    case TYPE_TITLE_UI04:

        // ��
        m_fAngle += UI_NOW_LOADING_ROT_SPEED;

        break;

    case TYPE_WAIT:

        break;

    case TYPE_ENEMY_USE_ATTACK:

        // �퓬�I�����A����
        GameFinishFade();

        break;

    case TYPE_ENEMY_USE_DEFENCE:

        // �퓬�I�����A����
        GameFinishFade();

        break;

    case TYPE_MANUAL:

        //// �퓬�I�����A����
        //GameFinishFade();

        break;

    case TYPE_GAUGE:

        // �I�u�W�F�N�g�^�C�v���Q�[�W��
        SetObjType(CScene::OBJTYPE_GAUGE);

        if (!m_bFirstGetSize)
        {
            m_size = GetSize();
            m_bFirstGetSize = true;
        }

        //m_size.x = (float)CGame::GetStamina();

        CScene2D::SetGauge(pos, m_size);

        break;

    case TYPE_PLAYER1:

        break;

    case TYPE_PLAYER2:

        break;

    case TYPE_PLAYER3:

        break;

    case TYPE_PLAYER4:

        break;

    case TYPE_SPEAKER2:

        // �I�u�W�F�N�g�^�C�v���Q�[�W��
        SetObjType(CScene::OBJTYPE_GAUGE);

        // ���T�C�Y����
        size.x = UI_SPEAKER_SIZE_X / ((float)WAVE_MAX / (float)nPlayer2Wave);

        // �摜�̕`��͈͂𒲐�
        SetTextureRange(nPlayer2Wave, WAVE_MAX);

        break;

    case TYPE_SPEAKER3:

        // �I�u�W�F�N�g�^�C�v���Q�[�W��
        SetObjType(CScene::OBJTYPE_GAUGE);

        // ���T�C�Y����
        size.x = UI_SPEAKER_SIZE_X / ((float)WAVE_MAX / (float)nPlayer3Wave);

        // �摜�̕`��͈͂𒲐�
        SetTextureRange(nPlayer3Wave, WAVE_MAX);

        break;

    case TYPE_SPEAKER4:

        // �I�u�W�F�N�g�^�C�v���Q�[�W��
        SetObjType(CScene::OBJTYPE_GAUGE);

        // ���T�C�Y����
        size.x = UI_SPEAKER_SIZE_X / ((float)WAVE_MAX / (float)nPlayer4Wave);

        // �摜�̕`��͈͂𒲐�
        SetTextureRange(nPlayer4Wave, WAVE_MAX);

        break;

    case TYPE_TIME:

        break;
    }

    // �F�𔽉f
    SetColor(m_col);

    // �ʒu�𔽉f
    SetPosition(pos);

    // �T�C�Y�𔽉f
    SetSize(size);

    if (m_type != TYPE_GAUGE)
    {
        // ���_���W��ݒ�
        if (m_type == TYPE_TITLE_UI04)
        {
            // ���[�h���̉�]
            SetRotVertex(m_fAngle);
        }
        else
        {
            SetVertex();
        }
    }

    // �g�p�t���O��false�Ȃ����
    if (m_bUse == false)
    {
        Uninit();
    }
}

//========================================
// UI�̕`�揈��
//========================================
void CUI::Draw(void)
{
    // �`�揈��
    CScene2D::Draw();
}

//========================================
// UI�̉摜���[�h����
//========================================
HRESULT CUI::Load(void)
{
    // �����_���[����f�o�C�X�̎擾
    LPDIRECT3DDEVICE9 pDevice = CManager::GetRenderer()->GetDevice();

    //�e�N�X�`���̓ǂݍ���
    D3DXCreateTextureFromFile(pDevice, "data/TEXTURE/ver.png", &m_apTexture[CUI::TYPE_VERSION]);	             // �o�[�W����
    D3DXCreateTextureFromFile(pDevice, "data/TEXTURE/ui014.png", &m_apTexture[CUI::TYPE_TITLE_LOGO]);	         // �^�C�g�����S
    D3DXCreateTextureFromFile(pDevice, "data/TEXTURE/ui015.png", &m_apTexture[CUI::TYPE_PRESS_START]);	         // �X�^�[�g�{�^���������Ă�
    D3DXCreateTextureFromFile(pDevice, "data/TEXTURE/game000.png", &m_apTexture[CUI::TYPE_GAME_UNDER]);	         // �Q�[���̉��̃o�[
    D3DXCreateTextureFromFile(pDevice, "data/TEXTURE/ui000.png", &m_apTexture[CUI::TYPE_HP]);	                 // HP
    D3DXCreateTextureFromFile(pDevice, "data/TEXTURE/ui001.png", &m_apTexture[CUI::TYPE_YOU]);	                 // ���Ȃ�
    D3DXCreateTextureFromFile(pDevice, "data/TEXTURE/ui002.png", &m_apTexture[CUI::TYPE_ENEMY]);	             // ������
    D3DXCreateTextureFromFile(pDevice, "data/TEXTURE/ui003.png", &m_apTexture[CUI::TYPE_FIRST]);	             // ��U
    D3DXCreateTextureFromFile(pDevice, "data/TEXTURE/ui004.png", &m_apTexture[CUI::TYPE_SECOND]);	             // ��U
    D3DXCreateTextureFromFile(pDevice, "data/TEXTURE/ui016.png", &m_apTexture[CUI::TYPE_GAME_START]);	         // �Q�[���J�n
    D3DXCreateTextureFromFile(pDevice, "data/TEXTURE/ui005.png", &m_apTexture[CUI::TYPE_ATTACK_START]);	         // �U���J�n
    D3DXCreateTextureFromFile(pDevice, "data/TEXTURE/ui006.png", &m_apTexture[CUI::TYPE_DEFENCE_START]);         // �h��J�n
    D3DXCreateTextureFromFile(pDevice, "data/TEXTURE/ui007.png", &m_apTexture[CUI::TYPE_CARD_INFO_BG]);	         // �J�[�h���̔w�i
    D3DXCreateTextureFromFile(pDevice, "data/TEXTURE/ui008.png", &m_apTexture[CUI::TYPE_YOU_WIN]);               // ����
    D3DXCreateTextureFromFile(pDevice, "data/TEXTURE/ui009.png", &m_apTexture[CUI::TYPE_YOU_LOSE]);	             // ����
    D3DXCreateTextureFromFile(pDevice, "data/TEXTURE/ui010.png", &m_apTexture[CUI::TYPE_ENEMY_USE_ATTACK]);      // �G�̍U��
    D3DXCreateTextureFromFile(pDevice, "data/TEXTURE/ui011.png", &m_apTexture[CUI::TYPE_ENEMY_USE_DEFENCE]);	 // �G�̖h��
    D3DXCreateTextureFromFile(pDevice, "data/TEXTURE/manual.png", &m_apTexture[CUI::TYPE_MANUAL]);	             // �V�ѕ�
    D3DXCreateTextureFromFile(pDevice, "data/TEXTURE/ui013.png", &m_apTexture[CUI::TYPE_WAIT]);	                 // �����ҋ@��
    D3DXCreateTextureFromFile(pDevice, "data/TEXTURE/ui017.png", &m_apTexture[CUI::TYPE_DISCONNECT]);	         // �ؒf
    D3DXCreateTextureFromFile(pDevice, "data/TEXTURE/stamina001.png", &m_apTexture[CUI::TYPE_STAMINA]);          // �X�^�~�i(�g)
    D3DXCreateTextureFromFile(pDevice, "data/TEXTURE/gauge001.png", &m_apTexture[CUI::TYPE_GAUGE]);              // �Q�[�W
    D3DXCreateTextureFromFile(pDevice, "data/TEXTURE/1P.png", &m_apTexture[CUI::TYPE_PLAYER1]);                  // �v���C���[1
    D3DXCreateTextureFromFile(pDevice, "data/TEXTURE/2P.png", &m_apTexture[CUI::TYPE_PLAYER2]);                  // �v���C���[2
    D3DXCreateTextureFromFile(pDevice, "data/TEXTURE/3P.png", &m_apTexture[CUI::TYPE_PLAYER3]);                  // �v���C���[3
    D3DXCreateTextureFromFile(pDevice, "data/TEXTURE/4P.png", &m_apTexture[CUI::TYPE_PLAYER4]);                  // �v���C���[4
    D3DXCreateTextureFromFile(pDevice, "data/TEXTURE/speaker.png", &m_apTexture[CUI::TYPE_SPEAKER2]);            // �X�s�[�J�[2
    D3DXCreateTextureFromFile(pDevice, "data/TEXTURE/speaker.png", &m_apTexture[CUI::TYPE_SPEAKER3]);            // �X�s�[�J�[3
    D3DXCreateTextureFromFile(pDevice, "data/TEXTURE/speaker.png", &m_apTexture[CUI::TYPE_SPEAKER4]);            // �X�s�[�J�[4
    D3DXCreateTextureFromFile(pDevice, "data/TEXTURE/time001.png", &m_apTexture[CUI::TYPE_TIME]);                // ��������
	D3DXCreateTextureFromFile(pDevice, "data/TEXTURE/cursor001.png", &m_apTexture[CUI::TYPE_CURSOR]);

    D3DXCreateTextureFromFile(pDevice, "data/TEXTURE/titleUI000.png", &m_apTexture[CUI::TYPE_TITLE_UI00]);// �ΐ푊���T���Ă��܂��E�E�E
    D3DXCreateTextureFromFile(pDevice, "data/TEXTURE/titleUI001.png", &m_apTexture[CUI::TYPE_TITLE_UI01]);// �ΐ푊�肪������܂����I
    D3DXCreateTextureFromFile(pDevice, "data/TEXTURE/titleUI002.png", &m_apTexture[CUI::TYPE_TITLE_UI02]);// �ΐ푊�肪������܂���ł���
    D3DXCreateTextureFromFile(pDevice, "data/TEXTURE/titleUI003.png", &m_apTexture[CUI::TYPE_TITLE_UI03]);// �����o��
    D3DXCreateTextureFromFile(pDevice, "data/TEXTURE/titleUI004.png", &m_apTexture[CUI::TYPE_TITLE_UI04]);// ���[�h���ɉ�]������

    D3DXCreateTextureFromFile(pDevice, "data/TEXTURE/result000.png", &m_apTexture[CUI::TYPE_RESULT1]);            // �X�s�[�J�[4
    D3DXCreateTextureFromFile(pDevice, "data/TEXTURE/result001.png", &m_apTexture[CUI::TYPE_RESULT2]);                // ��������

    return S_OK;
}

//========================================
// UI�̉摜�j������
//========================================
void CUI::Unload(void)
{
    // �e�N�X�`���̔j��
    for (int nCntTexture = 0; nCntTexture < CUI::TYPE_MAX; nCntTexture++)
    {
        if (m_apTexture[nCntTexture] != NULL)
        {
            m_apTexture[nCntTexture]->Release();
            m_apTexture[nCntTexture] = NULL;
        }
    }
}

//================================
// UI�̍쐬
//================================
CUI *CUI::Create(D3DXVECTOR3 pos, D3DXVECTOR3 size, D3DXCOLOR col, CUI::TYPE type)
{
    CUI *pUI = NULL;

    // ���������m��
    pUI = new CUI;

    // �^�C�v�̂݁A�e�N�X�`�������蓖�Ă̂��߂Ɍ��т��Ă���
    pUI->m_type = type;

    // ������
    pUI->Init(pos, size, D3DXVECTOR3(0.0f, 0.0f, 0.0f));

    // �����o�ϐ������т���
    pUI->m_col = col;

    return pUI;
}

//================================
// �Q�[���I�����A����UI
//================================
void CUI::GameFinishFade(void)
{
    if (CGame::GetFinishBattle() == true)
    {
        m_col.a = 0.0f;
    }
}

//================================
// �g�傷��UI
//================================
D3DXVECTOR3 CUI::Extend(D3DXVECTOR3 size)
{
    // �ϐ��錾
    D3DXVECTOR3 returnSize = size;  // �Ԃ��T�C�Y
    int nCnt = 0;                   // �J�E���^

                                    // �ؒf�ȊO�Ȃ�
    if (m_type != TYPE_DISCONNECT)
    {
        // ���T�C�Y�g��
        returnSize.x += UI_DISCONNECT_EXTEND_RATE_X;

        // �c�T�C�Y�g��
        returnSize.y += UI_DISCONNECT_EXTEND_RATE_Y;

        // ���T�C�Y�̐���
        if (returnSize.x >= UI_DISCONNECT_MAX_SIZE_X)
        {
            returnSize.x = UI_DISCONNECT_MAX_SIZE_X;
        }

        // �c�T�C�Y�̐���
        if (returnSize.y >= UI_DISCONNECT_MAX_SIZE_Y)
        {
            returnSize.y = UI_DISCONNECT_MAX_SIZE_Y;
        }
    }
    else
    {
        // ���T�C�Y�g��
        returnSize.x += UI_YOUR_TURN_EXTEND_RATE_X;

        // �c�T�C�Y�g��
        returnSize.y += UI_YOUR_TURN_EXTEND_RATE_Y;

        // ���T�C�Y�̐���
        if (returnSize.x >= UI_YOUR_TURN_MAX_SIZE_X)
        {
            returnSize.x = UI_YOUR_TURN_MAX_SIZE_X;
        }

        // �c�T�C�Y�̐���
        if (returnSize.y >= UI_YOUR_TURN_MAX_SIZE_Y)
        {
            returnSize.y = UI_YOUR_TURN_MAX_SIZE_Y;
        }
    }

    // �^�[���\���́A�e���̃^�[�����I����������
    switch (m_type)
    {
    case TYPE_GAME_START:

        // �A�j���[�V�����̃J�E���^�𗘗p���āAUI�̃t�F�[�h�A�E�g�ɂȂ���
        nCnt = CountAnimation(1, MAX_ANIM_COUNTER);

        // �t�F�[�h�A�E�g���n�߂�J�E���g�𒴂�����A���l�������Ă���
        if (nCnt >= UI_YOUR_TURN_FADE_OUT_COUNT)
        {
            m_col.a -= UI_YOUR_TURN_FADE_OUT_RATE;
        }

        break;
    }

    // �����x��0�����������A����
    if (m_col.a <= 0.0f)
    {
        m_bUse = false;
    }

    return returnSize;
}