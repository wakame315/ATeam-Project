//====================================================================
//
// UI�̏��� (ui.h)
// Author : �㓡�T�V��
//
//====================================================================
#ifndef _UI_H_
#define _UI_H_

//================================================
// �C���N���[�h�t�@�C��
//================================================
#include "main.h"
#include "scene2d.h"

//================================================
// �}�N����`
//================================================

// �o�[�W�����\�L
#define VERSION_POS D3DXVECTOR3(1150.0f, 675.0f, 0.0f)
#define VERSION_SIZE D3DXVECTOR3(150.0f,75.0f,0.0f)           

// �Q�[���̉��̗΂̂��
#define GAME_UNDER_POS (D3DXVECTOR3(SCREEN_WIDTH / 2, SCREEN_HEIGHT - 80.0f, 0.0f))
#define GAME_UNDER_SIZE (D3DXVECTOR3(SCREEN_WIDTH, 160.0f , 0.0f))

// ������HP�\�L
#define UI_HP_PLAYER_POS (D3DXVECTOR3(220.0f, 80.0f, 0.0f))
#define UI_HP_PLAYER_SIZE (D3DXVECTOR3(300.0f, 100.0f, 0.0f))

// �G��HP�\�L
#define UI_HP_ENEMY_POS (D3DXVECTOR3(SCREEN_WIDTH - 220.0f, 80.0f, 0.0f))
#define UI_HP_ENEMY_SIZE (D3DXVECTOR3(300.0f, 100.0f, 0.0f))

// ���Ȃ��\�L
#define UI_YOU_POS (D3DXVECTOR3(450.0f, 80.0f, 0.0f))
#define UI_YOU_SIZE (D3DXVECTOR3(100.0f, 100.0f, 0.0f))

// �����ĕ\�L
#define UI_ENEMY_POS (D3DXVECTOR3(SCREEN_WIDTH - 450.0f, 80.0f, 0.0f))
#define UI_ENEMY_SIZE (D3DXVECTOR3(100.0f, 100.0f, 0.0f))

// ��U��U
#define UI_ORDER_POS (D3DXVECTOR3(0.0f, 75.0f, 0.0f))   // ���炷�l
#define UI_ORDER_SIZE (D3DXVECTOR3(100.0f, 80.0f, 0.0f))

// YOUR ATTACK / DEFENCE TURN�\�L
#define UI_YOUR_TURN_POS (D3DXVECTOR3(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2 - 25.0f, 0.0f))  // YOUR TURN�̈ʒu
#define UI_YOUR_TURN_MAX_SIZE_X (400.0f)                                                   // YOUR TURN�̉��̍ő�T�C�Y
#define UI_YOUR_TURN_MAX_SIZE_Y (200.0f)                                                   // YOUR TURN�̏c�̍ő�T�C�Y
#define UI_YOUR_TURN_EXTEND_RATE_X (10.0f)                                                 // YOUR TURN�̉��̊g�劄��
#define UI_YOUR_TURN_EXTEND_RATE_Y (5.0f)                                                  // YOUR TURN�̏c�̊g�劄��
#define UI_YOUR_TURN_FADE_OUT_COUNT (180)                                                  // YOUR TURN�̃t�F�[�h���n�܂�J�E���^
#define UI_YOUR_TURN_FADE_OUT_RATE (0.05f)                                                 // YOUR TURN�̃t�F�[�h�A�E�g����

// �ؒf�\�L
#define UI_DISCONNECT_POS (D3DXVECTOR3(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2 - 100.0f, 0.0f)) // �ؒf�̈ʒu
#define UI_DISCONNECT_MAX_SIZE_X (600.0f)                                                   // �ؒf�̉��̍ő�T�C�Y
#define UI_DISCONNECT_MAX_SIZE_Y (300.0f)                                                   // �ؒf�̏c�̍ő�T�C�Y
#define UI_DISCONNECT_EXTEND_RATE_X (15.0f)                                                 // �ؒf�̉��̊g�劄��
#define UI_DISCONNECT_EXTEND_RATE_Y (7.5f)                                                  // �ؒf�̏c�̊g�劄��

// ���[�h���̉�]
#define UI_NOW_LOADING_IN_GAME_POS (D3DXVECTOR3(SCREEN_WIDTH / 2 + 180.0f, SCREEN_HEIGHT / 2, 0.0f))
#define UI_NOW_LOADING_SIZE D3DXVECTOR3(50.0f, 50.0f, 0.0f)
#define UI_NOW_LOADING_ROT_SPEED 0.03f  // ��]���x

// �J�[�h���̔w�i
#define UI_CARD_INFO_POS (D3DXVECTOR3(150.0f, 340.0f, 0.0f))
#define UI_CARD_INFO_SIZE (D3DXVECTOR3(225.0f, 325.0f, 0.0f))

// WIN / LOSE �\�L
#define UI_JUDGMENT_POS (D3DXVECTOR3(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2, 0.0f))
#define UI_JUDGMENT_SIZE (D3DXVECTOR3(560.0f , 80.0f, 0.0f))

// �G�̎g�p�J�[�h
#define UI_ENEMY_USE_POS (D3DXVECTOR3(SCREEN_WIDTH - 150.0f, 340.0f, 0.0f))
#define UI_ENEMY_USE_SIZE (D3DXVECTOR3(225.0f, 200.0f, 0.0f))

// �V�ѕ��\�L
#define UI_MANUAL_POS (D3DXVECTOR3(SCREEN_WIDTH / 2, 530.0f, 0.0f))
#define UI_MANUAL_SIZE (D3DXVECTOR3(300.0f, 70.0f, 0.0f))

// �ҋ@���\�L
#define UI_WAIT_POS (D3DXVECTOR3(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2, 0.0f))
#define UI_WAIT_SIZE (D3DXVECTOR3(300.0f, 70.0f, 0.0f))

// �^�C�g�����S
#define TITLE_LOGO_FIRST_POS (D3DXVECTOR3(SCREEN_WIDTH / 2, -150.0f, 0.0f))  // �^�C�g�����S�̍ŏ��̈ʒu
#define TITLE_LOGO_TARGET_POS_Y 150.0f                                       // �^�C�g�����S�̖ڕW�ʒu 
#define TITLE_LOGO_SIZE (D3DXVECTOR3(500.0f, 250.0f, 0.0f))                  // �^�C�g�����S�̃T�C�Y
#define TITLE_LOGO_FLOW_DOWN_SPEED 2.0f                                      // �^�C�g�����S�̗��ꗎ���鑬�x

// PLEASE PRESS START
#define PRESS_START_POS D3DXVECTOR3(SCREEN_WIDTH / 2, 650.0f, 0.0f)                 // �X�^�[�g�{�^���������Ă˂̈ʒu
#define PRESS_START_SIZE D3DXVECTOR3(500.0f,100.0f,0.0f)                            // �X�^�[�g�{�^���������Ă˂̃T�C�Y
#define PRESS_START_INACTIVE_COLOR D3DXCOLOR(0.431f, 0.431f, 0.388f, 1.0f)          // �X�^�[�g�{�^���������Ă˂̔�A�N�e�B�u�F
#define PRESS_START_FADE_RATE 0.01f                                                 // �X�^�[�g�{�^���������Ă˂̓_�Ŋ���
#define PRESS_START_FADE_OUT_MIN 0.6f                                               // �X�^�[�g�{�^���������Ă˂̃t�F�[�h�A�E�g�̍ŏ��l

// �X�^�~�i(�g)
#define UI_STAMINA_POS (D3DXVECTOR3(340.0f - (200.0f / 2), 75.0f, 0.0f))
#define UI_STAMINA_SIZE (D3DXVECTOR3(220.0f , 65.0f, 0.0f))

// �Q�[�W
#define UI_GAUGE_POS (D3DXVECTOR3(340.0f - (200.0 / 2), 75.0f, 0.0f))
#define UI_GAUGE_SIZE (D3DXVECTOR3(200.0f , 40.0f, 0.0f))

// �v���C���[1
#define UI_PLAYER_1_POS (D3DXVECTOR3(85.0f, 75.0f, 0.0f))
#define UI_PLAYER_1_SIZE (D3DXVECTOR3(95.0f , 100.0f, 0.0f))

// �v���C���[2
#define UI_PLAYER_2_POS (D3DXVECTOR3(650.0f - (250.0f / 2), 75.0f, 0.0f))
#define UI_PLAYER_2_SIZE (D3DXVECTOR3(250.0f , 100.0f, 0.0f))

// �v���C���[3
#define UI_PLAYER_3_POS (D3DXVECTOR3(950.0f - (250.0f / 2), 75.0f, 0.0f))
#define UI_PLAYER_3_SIZE (D3DXVECTOR3(250.0f , 100.0f, 0.0f))

// �v���C���[4
#define UI_PLAYER_4_POS (D3DXVECTOR3(1250.0f - (250.0f / 2), 75.0f, 0.0f))
#define UI_PLAYER_4_SIZE (D3DXVECTOR3(250.0f , 100.0f, 0.0f))

// �X�s�[�J�[
#define UI_SPEAKER_2_POS (D3DXVECTOR3(570.0f, 75.0f, 0.0f)) // UI�v���C���[2��X������+45
#define UI_SPEAKER_2_SIZE (D3DXVECTOR3(100.0f , 50.0f, 0.0f))
#define UI_SPEAKER_SIZE_X 100.0f

#define UI_SPEAKER_3_POS (D3DXVECTOR3(870.0f, 75.0f, 0.0f)) // UI�v���C���[3��X������+45
#define UI_SPEAKER_3_SIZE (D3DXVECTOR3(100.0f , 50.0f, 0.0f))

#define UI_SPEAKER_4_POS (D3DXVECTOR3(1170.0f, 75.0f, 0.0f)) // UI�v���C���[4��X������+45
#define UI_SPEAKER_4_SIZE (D3DXVECTOR3(100.0f , 50.0f, 0.0f))

// ��������
#define UI_TIME_POS (D3DXVECTOR3(SCREEN_WIDTH / 2 - 50.0f, SCREEN_HEIGHT - 45.0f, 0.0f))
#define UI_TIME_SIZE (D3DXVECTOR3(300.0f , 45.0f, 0.0f))


#define MANUAL_POS (D3DXVECTOR3(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2, 0.0f))  // �V�ѕ��̈ʒu
#define MANUAL_SIZE (D3DXVECTOR3(SCREEN_WIDTH, SCREEN_HEIGHT, 0.0f))         // �V�ѕ��̃T�C�Y

#define RESULT_POS (D3DXVECTOR3(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2, 0.0f)) // ���U���g�̈ʒu
#define RESULT_SIZE (D3DXVECTOR3(SCREEN_WIDTH, SCREEN_HEIGHT, 0.0f))        // ���U���g�̃T�C�Y

//================================================
// �N���X�錾
//================================================

// UI�N���X
class CUI : public CScene2D
{
public:
    // UI�̎��
    typedef enum
    {
        TYPE_NONE = 0,	        // ����
        TYPE_VERSION,           // �o�[�W����
        TYPE_TITLE_LOGO,        // �^�C�g���̃��S
        TYPE_PRESS_START,       // �X�^�[�g�{�^���������Ă�
        TYPE_GAME_UNDER,        // �Q�[���̉��̃o�[
        TYPE_HP,                // HP�o�[
        TYPE_YOU,               // ���Ȃ�
        TYPE_ENEMY,             // ������
        TYPE_FIRST,             // ��U
        TYPE_SECOND,            // ��U
        TYPE_GAME_START,        // �Q�[���J�n
        TYPE_ATTACK_START,      // �U���J�n
        TYPE_DEFENCE_START,     // �h��J�n
        TYPE_CARD_INFO_BG,      // �J�[�h���̔w�i
        TYPE_YOU_WIN,           // ����
        TYPE_YOU_LOSE,          // ����
        TYPE_TITLE_UI00,		// �ΐ푊���T���Ă��܂��E�E�E
        TYPE_TITLE_UI01,		// �ΐ푊�肪������܂����I
        TYPE_TITLE_UI02,		// �ΐ푊�肪������܂���ł���
        TYPE_TITLE_UI03,		// �����o��
        TYPE_TITLE_UI04,        // ���[�h���ɉ�]������
        TYPE_ENEMY_USE_ATTACK,  // �G�̍U��
        TYPE_ENEMY_USE_DEFENCE, // �G�̖h��
        TYPE_RESULT1,           // ���U���g1
        TYPE_RESULT2,           // ���U���g2
        TYPE_MANUAL,            // �V�ѕ��\�L
        TYPE_WAIT,              // �����ҋ@��
        TYPE_DISCONNECT,        // �ؒf
        TYPE_STAMINA,           // �X�^�~�i(�g)
        TYPE_GAUGE,             // �Q�[�W
        TYPE_PLAYER1,           // �v���C���[1
        TYPE_PLAYER2,           // �v���C���[2
        TYPE_PLAYER3,           // �v���C���[3
        TYPE_PLAYER4,           // �v���C���[4
        TYPE_SPEAKER2,          // �X�s�[�J�[2
        TYPE_SPEAKER3,          // �X�s�[�J�[3
        TYPE_SPEAKER4,          // �X�s�[�J�[4
        TYPE_TIME,              // ��������
		TYPE_CURSOR,            //�J�[�\��
        TYPE_MAX			    // ��ނ̍ő吔
    }TYPE;

    CUI();
    ~CUI();
    HRESULT Init(D3DXVECTOR3 pos, D3DXVECTOR3 size, D3DXVECTOR3 rot);
    void Uninit(void);
    void Update(void);
    void Draw(void);
    static HRESULT Load(void);
    static void Unload(void);
    static CUI *Create(D3DXVECTOR3 pos, D3DXVECTOR3 size, D3DXCOLOR col, TYPE type);

    void GameFinishFade(void);              // �Q�[���I�����ɁA����UI
    D3DXVECTOR3 Extend(D3DXVECTOR3 size);   // �g�傷��UI

    TYPE GetType(void) { return m_type; }           // �^�C�v�̎擾
    void SetDontUse(void) { m_bUse = false; }       // �g��Ȃ����̂̔j��

private:
    static LPDIRECT3DTEXTURE9 m_apTexture[TYPE_MAX];   // �ǂݍ��񂾃e�N�X�`����ۑ�����
    D3DXVECTOR3 m_move;                                // �ړ���
    D3DXCOLOR m_col;                                   // �F
    TYPE m_type;                                       // UI�̎��
    D3DXVECTOR3 m_size;                                // �T�C�Y
    float m_fAngle;                                    // �p�x
    bool m_bFadeOut;                                   // �t�F�[�h�A�E�g���ǂ���
    bool m_bBlinking;                                  // �_�Œ����ǂ���
    int m_nCntTime;                                    // ���Ԃ��J�E���g
    bool m_bFirstGetSize;
    bool m_bUse;                                       // �g�p���邩�ǂ���
};

#endif