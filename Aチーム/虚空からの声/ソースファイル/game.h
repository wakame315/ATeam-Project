//=============================================================================
//
// �Q�[������ [game.h]
// Author : �㓡�T�V��
//
//=============================================================================
#ifndef _GAME_H_
#define _GAME_H_

//*****************************************************************************
// �w�b�_�t�@�C���̃C���N���[�h
//*****************************************************************************
#include "main.h"
#include "mode.h"

//*****************************************************************************
// �O���錾
//*****************************************************************************
class CCharacter;

//*****************************************************************************
// �}�N����`
//*****************************************************************************
//�Q�[����Ԃ̊Ǘ��t���[��
#define COUNT_WAIT_FINISH 300	    // �Q�[���I�����ɁA�^�C�g����ʂ֍s���܂ł̎���

#define PLAYER1 0

#define PLAYER_SPEED 6.0f

#define WAVE_MAX 2

#define VALUE_KNOCKBACK 50.0f

//�v���C���[�̏����ʒu
#define PLAYER1_FIRST_POS_X (100.0f)
#define PLAYER1_FIRST_POS_Z (1100.0f)

#define MAX_CHARACTER 1

//*****************************************************************************
// �N���X��`
//*****************************************************************************
class CGame : public CMode
{
public:

    // �Q�[���̏��
    typedef enum
    {
        STATE_START = 0,        // �J�n
        STATE_NORMAL,           // �ʏ�
        STATE_FINISH,	        // �I��
        STATE_PAUSE,	        // �|�[�Y
        STATE_MAX			    // ��Ԃ̍ő吔
    }STATE;

	typedef struct
	{
		int nType;
		D3DXVECTOR3 pos;
		D3DXVECTOR3 rot;
	} STAGEDATE;

    CGame();
    ~CGame();
    HRESULT Init(void);
    void Uninit(void);
    void Update(void);
    void Judgment(void);                                                    // ���s����

    static bool GetFinishBattle(void) { return m_bFinishBattle; }           // �킢���I��������ǂ������擾

    void ManageState(void);                                                 // �Q�[����Ԃ̊Ǘ�
    static STATE GetState(void) { return m_state; }                         // �Q�[���̏�Ԃ��擾
    static void SetState(STATE state) { m_state = state; }                  // �Q�[���̏�Ԃ�ݒ�
    static CCharacter* GetPlayer(void) { return m_pCharacter; }  // �v���C���[���擾

	void LoadMapData(void);

    void PlayerMovement(void);                // �v���C���[1�̍s��
    void SetAura(D3DXVECTOR3 pos);            // �I�[������
    void SetExplosion(D3DXVECTOR3 pos);       // ����
    void Movement(int nCnt, float fSpeed);

private:
    int m_nCntGameTime;                              // �Q�[�����Ԃ̃J�E���^
    int m_nCntFinishGame;                            // �Q�[�����I���܂ł̃J�E���^

    static CCharacter *m_pCharacter;                 // �L�����N�^�[�̃|�C���^
    static bool m_bFinishBattle;                     // �킢���I��������ǂ���

    static STATE m_state;                            // ���
};

#endif