//========================================================
//
//           timer�̃N���X[timer.cpp]
//           Author:�ɓ���P
//
//========================================================

//========================================================
//�C���N���[�h�t�@�C��
//========================================================
#include "timer.h"
#include "manager.h"
#include "renderer.h"
#include "game.h"

bool CTimer::m_bFinish = false;

//========================================================
//�R���X�g���N�^
//========================================================
CTimer::CTimer() :CScene()
{
    //�����o�ϐ��̏�����
    m_nSeconds = 0;
    m_nMinutes = 0;
    m_nCntFrame = 0;

    for (int nCnt = 0; nCnt < MAX_SECONDS_DIGIT; nCnt++)
    {
        m_apSecondsNumber[nCnt] = NULL;
    }

    m_apMinutesNumber = NULL;

    m_bFinish = false;
}

//========================================================
//�f�X�g���N�^
//========================================================
CTimer::~CTimer(void)
{

}

//========================================================
//����������
//========================================================
CTimer *CTimer::Create(D3DXVECTOR3 pos, D3DXVECTOR3 size)
{
    //�ϐ��錾
    CTimer *pTimer;

    //����������
    pTimer = new CTimer;

    //����������
    pTimer->Init(pos, size, D3DXVECTOR3(0.0f, 0.0f, 0.0f));

    return pTimer;
}

//========================================================
//������
//========================================================
HRESULT CTimer::Init(D3DXVECTOR3 pos, D3DXVECTOR3 size, D3DXVECTOR3 rot)
{

    // ���̎���
    m_nMinutes = MINUTES_TIMER;

    // �b�̎���
    m_nSeconds = SECONDS_TIMER;

    // ���̐���
    m_apMinutesNumber = CNumber::Create(D3DXVECTOR3(pos.x, pos.y, 0.0f), size.x, size.y);

    for (int nCnt = 0; nCnt < MAX_SECONDS_DIGIT; nCnt++)
    {
        // �b�̐���
        m_apSecondsNumber[nCnt] = CNumber::Create(D3DXVECTOR3(pos.x + (nCnt * size.x) + 75.0f, pos.y, 0.0f), size.x, size.y);
    }

    // �I�u�W�F�N�g�^�C�v�̃Z�b�g
    CScene::SetObjType(OBJTYPE_UI);

    return S_OK;
}

//========================================================
//�I������
//========================================================
void CTimer::Uninit(void)
{
    for (int nCnt = 0; nCnt < MAX_SECONDS_DIGIT; nCnt++)
    {
        if (m_apSecondsNumber[nCnt] != NULL)
        {
            m_apSecondsNumber[nCnt]->Uninit();
            delete m_apSecondsNumber[nCnt];
            m_apSecondsNumber[nCnt] = NULL;
        }

    }

    if (m_apMinutesNumber != NULL)
    {
        m_apMinutesNumber->Uninit();
        delete m_apMinutesNumber;
        m_apMinutesNumber = NULL;
    }

    Release();
}

//========================================================
//�X�V����
//========================================================
void CTimer::Update(void)
{

    if (CGame::GetState() == CGame::STATE_NORMAL)
    {
        // �t���[�����J�E���g
        m_nCntFrame++;

        if (m_nCntFrame % 60 == 0)
        {
            //�^�C�}�[��������
            m_nSeconds--;
        }

        // �b��0�ȉ��ɂȂ�����
        if (m_nSeconds <= -1)
        {
            if (m_nMinutes >= 1)
            {
                // �b��59�ɖ߂�
                m_nSeconds = 59;

                // ����������
                m_nMinutes--;
            }
        }
    }

    // �Q�[���̏I��
    if (m_nMinutes <= 0 && m_nSeconds <= -1)
    {
        m_nCntFrame = 0;
        m_nMinutes = 0;
        m_nSeconds = 0;

        m_bFinish = true;
    }

    // �����̕ύX
    // �ϐ��錾
    float fRadix = 10.0f; //��@(�X�R�A�\���p)

    for (int nCnt = 0; nCnt < MAX_SECONDS_DIGIT; nCnt++)
    {
        int nScore = (int)powf(fRadix, MAX_SECONDS_DIGIT - (float)nCnt);
        int nScore2 = (int)powf(fRadix, MAX_SECONDS_DIGIT - (float)nCnt - 1);
        int nAnswer = m_nSeconds % nScore / nScore2;

        //�b�̃e�N�X�`���̍��W
        m_apSecondsNumber[nCnt]->SetNumber(nAnswer);

    }

    // ���̃e�N�X�`�����W
    m_apMinutesNumber->SetNumber(m_nMinutes);
}

//========================================================
//�`�揈��
//========================================================
void CTimer::Draw(void)
{
    for (int nCnt = 0; nCnt < MAX_SECONDS_DIGIT; nCnt++)
    {
        // �b�̕`��
        m_apSecondsNumber[nCnt]->Draw();
    }

    // ���̕`��
    m_apMinutesNumber->Draw();

}