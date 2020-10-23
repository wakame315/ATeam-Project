//===============================================
//
// �V�[����̃I�u�W�F�N�g���� (scene.cpp)
// Author : �㓡�T�V��
//
//===============================================

//========================
// �C���N���[�h�t�@�C��
//========================
#include "scene.h"
#include "renderer.h"

//========================================
// �ÓI�����o�ϐ��錾
//========================================
int CScene::m_nNumAll = 0;

CScene *CScene::m_pTop = NULL;
CScene *CScene::m_pCur = NULL;

//========================================
// �V�[����̃I�u�W�F�N�g�̃f�t�H���g�R���X�g���N�^
//========================================
CScene::CScene()
{
    // �擪���Ȃ��Ȃ�A�擪��
    if (m_pTop == NULL)
    {
        m_pTop = this;
    }

    // ���݂ɂ�����ŐV�̃I�u�W�F�N�g���Ȃ��Ȃ�A�ŐV��
    if (m_pCur == NULL)
    {
        m_pCur = this;
    }

    // ���݂̃I�u�W�F�N�g�̎��̃I�u�W�F�N�g���A�����ɂ���
    m_pCur->m_pNext = this;

    // ���݂̃I�u�W�F�N�g�������̏ꍇ
    if (m_pCur == this)
    {
        // �����̑O�̃I�u�W�F�N�g���ANULL�ɂ���
        m_pPrev = NULL;
    }
    else
    {
        // �����̑O�̃I�u�W�F�N�g���A���݂̃I�u�W�F�N�g�ɂ���
        m_pPrev = m_pCur;
    }

    // ���݂̃I�u�W�F�N�g���A�����ɂ���
    m_pCur = this;

    // �����̎��̃I�u�W�F�N�g���ANULL�ɂ���
    m_pNext = NULL;

    // �������I�u�W�F�N�g���J�E���g
    m_nNumAll++;

    // �I�u�W�F�N�g�̎�ނ�NULL�ɂ���
    m_objType = OBJTYPE_NONE;

    // �g�p����t���O��true��
    m_bUse = true;
}

//========================================
// �V�[����̃I�u�W�F�N�g�̃I�[�o�[���C�h���ꂽ�R���X�g���N�^
//========================================
CScene::CScene(OBJTYPE objType)
{
    // �擪���Ȃ��Ȃ�A�擪��
    if (m_pTop == NULL)
    {
        m_pTop = this;
    }

    // ���݂ɂ�����ŐV�̃I�u�W�F�N�g���Ȃ��Ȃ�A�ŐV��
    if (m_pCur == NULL)
    {
        m_pCur = this;
    }

    // ���݂̃I�u�W�F�N�g�̎��̃I�u�W�F�N�g���A�����ɂ���
    m_pCur->m_pNext = this;

    // ���݂̃I�u�W�F�N�g�������̏ꍇ
    if (m_pCur == this)
    {
        // �����̑O�̃I�u�W�F�N�g���ANULL�ɂ���
        m_pPrev = NULL;
    }
    else
    {
        // �����̑O�̃I�u�W�F�N�g���A���݂̃I�u�W�F�N�g�ɂ���
        m_pPrev = m_pCur;
    }

    // ���݂̃I�u�W�F�N�g���A�����ɂ���
    m_pCur = this;

    // �����̎��̃I�u�W�F�N�g���ANULL�ɂ���
    m_pNext = NULL;

    // �������I�u�W�F�N�g���J�E���g
    m_nNumAll++;

    // �I�u�W�F�N�g�̎�ނ������ƌ��т���
    m_objType = objType;

    // �g�p����t���O��true��
    m_bUse = true;
}

//========================================
// �V�[����̃I�u�W�F�N�g�̃f�X�g���N�^
//========================================
CScene::~CScene()
{

}

//==============================================
// �V�[����̃I�u�W�F�N�g��S�čX�V
//==============================================
void CScene::UpdateAll(void)
{
    // �擪�A�ŐV�̂��̂�����Ȃ�
    if (m_pTop != NULL && m_pCur != NULL)
    {
        // �L���p�̕ϐ�
        CScene*pScene = m_pTop;

        do
        {
            // �L���p�̕ϐ�(Update���ɁAUninit����邱�Ƃ��l��)
            CScene*pNextScene = pScene->m_pNext;

            // �X�V����
            pScene->Update();

            // �g�p�t���O��false�Ȃ�
            if (pScene->m_bUse == false)
            {
                // �������̊J��
                //delete pScene;
                pScene = NULL;
            }

            // ���̃V�[���ɕς��Ă���
            pScene = pNextScene;

        } while (pScene != NULL);
    }
}

//==============================================
// �V�[����̃I�u�W�F�N�g��S�ĕ`��
//==============================================
void CScene::DrawAll(void)
{
    // �擪�A�ŐV�̂��̂�����Ȃ�
    if (m_pTop != NULL && m_pCur != NULL)
    {
        // �ϐ��錾
        CScene *pScene = m_pTop;                        // �V�[���̃|�C���^�L���p
        CScene**apSceneOrder = new CScene*[m_nNumAll];  // �`��̏��Ԃ�ς��邽�߁A�z��ɏ����L��

                                                        // �z��̏�����
        for (int nCntObject = 0; nCntObject < m_nNumAll; nCntObject++)
        {
            // �V�[����̃I�u�W�F�N�g�̏����L��
            apSceneOrder[nCntObject] = pScene;

            // �V�[���̃|�C���^��i�߂�
            pScene = pScene->m_pNext;
        }

        // �o�u���\�[�g�͒x��
        //BubbleSort(&apSceneOrder[0]);

        // �N�C�b�N�\�[�g�Ŕz����A�`�揇�ɕ��ёւ���
        QuickSort(&apSceneOrder[0], 0, m_nNumAll - 1);

        // �f�o�b�O�p
        int nNullData = 0;

        // ���Ԃɕ`��
        for (int nCnt = 0; nCnt < m_nNumAll; nCnt++)
        {
            if (apSceneOrder[nCnt] != NULL)
            {
                apSceneOrder[nCnt]->Draw();

                nNullData = m_nNumAll;
            }
            else
            {
                nNullData = nCnt;
            }
        }

        // �p�ӂ����z��̏���
        delete[] apSceneOrder;
    }
}

//==============================================
// �o�u���\�[�g
//==============================================
void CScene::BubbleSort(CScene * apScene[])
{
    // �`�揇���\�[�g(�I��@)���g���āA�^�C�v���ɕ��ёւ���i�����j
    for (int nNum01 = 0; nNum01 < m_nNumAll - 1; nNum01++)
    {
        for (int nNum02 = nNum01 + 1; nNum02 < m_nNumAll; nNum02++)
        {
            // �ǂ�������g������Ȃ�
            if (apScene[nNum01] != NULL && apScene[nNum02] != NULL)
            {
                // �Ⴂ�ԍ��̃^�C�v�̂ق����傫���Ȃ�
                if (apScene[nNum01]->m_objType > apScene[nNum02]->m_objType)
                {
                    // �Ⴂ�ԍ����L��
                    CScene *pScene = apScene[nNum01];

                    // �Ⴂ�ԍ��Ɏ��̔ԍ�����
                    apScene[nNum01] = apScene[nNum02];

                    // ���̔ԍ��ɋL���������̂���
                    apScene[nNum02] = pScene;
                }
            }
        }
    }
}

//==============================================
// �N�C�b�N�\�[�g
//==============================================
void CScene::QuickSort(CScene * apScene[], int left, int right)
{
    // �ϐ���`
    int Left;
    int Right;
    CScene* pivot;
    int nPivotAnswer = (left + right) / 2;

    // �����l�͈�������
    Left = left;
    Right = right;

    // �s�{�b�g����Ȃ�A�J�艺����
    if (nPivotAnswer % 2 != 0)
    {
        nPivotAnswer = nPivotAnswer - (1 / 2);
    }

    // �s�{�b�g�͈̔͂�ݒ�(����)
    if (nPivotAnswer < 0)
    {
        nPivotAnswer = 0;
    }

    // �s�{�b�g�͈̔͂�ݒ�(���)
    if (nPivotAnswer > m_nNumAll - 1)
    {
        nPivotAnswer = m_nNumAll - 1;
    }

    // ��͐^�񒆂ɐݒ�
    pivot = apScene[nPivotAnswer];

    // �\�[�e�B���O
    while (1)
    {
        // ���菬�����l�������猩���Ă���
        while (apScene[Left]->m_objType < pivot->m_objType)
        {
            Left++;

            // �ő�l�̐���
            if (Left > m_nNumAll - 1)
            {
                Left = m_nNumAll - 1;

                break;
            }
        }

        // ����傫���l���E���猩���Ă���
        while (pivot->m_objType < apScene[Right]->m_objType)
        {
            Right--;

            // �ŏ��l�̐���
            if (Right < 0)
            {
                Right = 0;

                break;
            }
        }

        // ���������l�̏������t�ɂȂ�����I�� 
        if (Left >= Right)
        {
            break;
        }

        // ��������
        if (apScene[Left] != NULL && apScene[Right] != NULL)
        {
            // �Ⴂ�ԍ����L��
            CScene *pScene = apScene[Left];

            // �Ⴂ�ԍ��Ɏ��̔ԍ�����
            apScene[Left] = apScene[Right];

            // ���̔ԍ��ɋL���������̂���
            apScene[Right] = pScene;
        }

        // ���̒l�Ɉړ�
        Left++;
        Right--;

        // �ő�l�̐���
        if (Left > m_nNumAll - 1)
        {
            break;
        }

        // �ŏ��l�̐���
        if (Right < 0)
        {
            break;
        }
    }

    //���̃f�[�^�Q��ΏۂƂ��ăN�C�b�N�\�[�g���ċA
    if (left < Left - 1)
    {
        QuickSort(apScene, left, Left - 1);
    }

    //�E�̃f�[�^�Q��ΏۂƂ��ăN�C�b�N�\�[�g���ċA
    if (Right + 1 < right)
    {
        QuickSort(apScene, Right + 1, right);
    }
}

//==============================================
// �V�[����̃I�u�W�F�N�g��S�ĊJ��
//==============================================
void CScene::ReleaseAll(void)
{
    // �擪�A�ŐV�̂��̂�����Ȃ�
    if (m_pTop != NULL && m_pCur != NULL)
    {
        // �L���p�̕ϐ�
        CScene*pScene = m_pTop;

        do
        {
            // �L���p�̕ϐ�
            CScene*pNextScene = pScene->m_pNext;

            // �I������
            pScene->Uninit();

            // �g�p�t���O��false�Ȃ�
            if (pScene->m_bUse == false)
            {
                // �������̊J��
                //delete pScene;
                pScene = NULL;
            }

            // ���̃V�[���ɕς��Ă���
            pScene = pNextScene;

        } while (pScene != NULL);
    }
}

//==============================================
// �V�[����̃I�u�W�F�N�g��S�ĊJ��
//==============================================
void CScene::Release(void)
{
    // ���g������Ȃ�A
    if (this != NULL)
    {
        // �擪�Ȃ�
        if (this == m_pTop)
        {
            // ���̒��g������Ȃ�
            if (m_pNext != NULL)
            {
                // ���̂��̂̑O�̏����ANULL��
                m_pNext->m_pPrev = NULL;

                // �����擪��
                m_pTop = m_pNext;
            }
            else
            {
                // �擪�̎����Ȃ��Ȃ�A�擪�ƌ��݂������|�C���^��NULL��
                m_pTop = NULL;
                m_pCur = NULL;
            }
        }
        // �擪�łȂ��Ȃ�
        else
        {
            // ���̒��g������Ȃ�
            if (m_pNext != NULL)
            {
                // �O�̂��̂̎��̏����A���g�̎��̏���
                m_pPrev->m_pNext = m_pNext;

                // ���̂��̂̑O�̏����A���g�̑O�̏���
                m_pNext->m_pPrev = m_pPrev;
            }
            else
            {
                // �O�̂��̂̎��̏����A�Ȃ���
                m_pPrev->m_pNext = NULL;

                // ���݂̍ŐV�̂��̂��A�O�̏���
                m_pCur = m_pPrev;
            }
        }

        // �������̊J��
        delete this;

        // �g�p�t���O��false��
        m_bUse = false;

        // ���������炷
        m_nNumAll--;
    }
}
