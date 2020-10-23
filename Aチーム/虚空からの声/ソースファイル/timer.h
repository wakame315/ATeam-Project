//=============================================================================
//
//           �^�C�g�� :�^�C�}�[�̃N���X[timer.h]
//           Author:�ɓ���P
//
//=============================================================================
#ifndef _TIMER_H_
#define _TIMER_H_

#define _CRT_SECURE_NO_WARNINGS_

//=============================================================================
//�C���N���[�h�t�@�C��
//=============================================================================
#include"main.h"
#include "scene.h"
#include "number.h"

class CScene;
class CNumber;

//=============================================================================
//�}�N����`
//=============================================================================
// �^�C�}�[�̈ʒu�ƃT�C�Y
#define TIMER_POS D3DXVECTOR3(SCREEN_WIDTH / 2,SCREEN_HEIGHT - 45.0f,0.0f)
#define TIMER_SIZE D3DXVECTOR3(NUMBER_SIZE_X,NUMBER_SIZE_Y,0.0f)

#define MAX_SECONDS_DIGIT 2 //�^�C�}�[�̕b�̌��̐�
#define MAX_MINUTES_DIGIT 1 //�^�C�}�[�̕��̌��̐�

// �b�̎���
#define SECONDS_TIMER 30

// ���̎���
#define MINUTES_TIMER 1

//=============================================================================
//�N���X��`
//=============================================================================
class CTimer :public CScene
{
public:

    CTimer();  //�R���X�g���N�^
    ~CTimer(); //�f�X�g���N�^

               //=========================================
               //���\�b�h
               //=========================================
    static CTimer *Create(D3DXVECTOR3 pos, D3DXVECTOR3 size);
    HRESULT Init(D3DXVECTOR3 pos, D3DXVECTOR3 size, D3DXVECTOR3 rot); // ����������
    void Update(void);                               // �X�V����
    void Uninit(void);                               // �I������
    void Draw(void);                                 // �`�揈��

    static bool GetFinish(void) { return m_bFinish; }

private:
    static bool m_bFinish;
    CNumber *m_apMinutesNumber;
    CNumber *m_apSecondsNumber[MAX_SECONDS_DIGIT];
    int m_nSeconds;  // �^�C�}�[�̕b�̃J�E���^�[
    int m_nMinutes;  // �^�C�}�[�̕��̃J�E���^�[
    int m_nCntFrame; // �t���[�����J�E���g
};
#endif