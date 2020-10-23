//====================================================================
//
// �V�[����̃I�u�W�F�N�g���� (scene.h)
// Author : �㓡�T�V��
//
//====================================================================
#ifndef _SCENE_H_
#define _SCENE_H_

//================================================
// �C���N���[�h�t�@�C��
//================================================
#include "main.h"

//================================================
// �}�N����`
//================================================

//================================================
// �N���X�錾
//================================================

// �I�u�W�F�N�g�̃N���X
class CScene
{
public:
    // �I�u�W�F�N�g�̎��(�`�揇)
    typedef enum
    {
        OBJTYPE_NONE,      // �Ȃ�
        OBJTYPE_BLOCK,     // �u���b�N
        OBJTYPE_BULLET,    // �e
        OBJTYPE_PLAYER,    // �v���C���[
        OBJTYPE_DEBUG,     // �f�o�b�O
        OBJTYPE_EFFECT3D,  // �G�t�F�N�g3D
        OBJTYPE_BG,        // �w�i
        OBJTYPE_UI,        // UI
        OBJTYPE_GAUGE,     // �Q�[�W
        OBJTYPE_EFFECT,    // �G�t�F�N�g
        OBJTYPE_MAX        // �I�u�W�F�N�g�̎�ނ̍ő吔
    }OBJTYPE;

    CScene();
    CScene(OBJTYPE objType);    // �C�j�V�����C�U�ŃI�u�W�F�N�g�^�C�v��R�Â�
    virtual ~CScene();  // �e�N���X�̃f�X�g���N�^��virtual�����邱�ƂŁA���������[�N��}����
    virtual HRESULT Init(D3DXVECTOR3 pos, D3DXVECTOR3 size, D3DXVECTOR3 rot) = 0;
    virtual void Uninit(void) = 0;
    virtual void Update(void) = 0;
    virtual void Draw(void) = 0;
    static void UpdateAll(void);                                    // �S�čX�V
    static void DrawAll(void);                                      // �S�ĕ`��
    static void BubbleSort(CScene*apScene[]);                       // �o�u���\�[�g
    static void QuickSort(CScene*apScene[], int left, int right);   // �N�C�b�N�\�[�g
    static void ReleaseAll(void);                                   // �S�ĊJ��
                                                                    //static void ReleaseStage(void);                               // �S�Ă̔w�i�A�G�A�u���b�N�A�A�C�e�����J��
    OBJTYPE GetObjType(void) { return m_objType; }                  // �I�u�W�F�N�g�^�C�v���擾

    static int GetNumAll(void) { return m_nNumAll; }                // �S�̂̐����擾
    static CScene*GetTopScene(void) { return m_pTop; }               // �擪�̃I�u�W�F�N�g���擾
    CScene* GetNextScene(void) { return m_pNext; }                  // ���̃I�u�W�F�N�g���擾

    void SetObjType(OBJTYPE objtype) { m_objType = objtype; }

protected:
    void Release(void);                 // �P�̂��J��

private:
    static CScene *m_pTop;  // �擪�̃I�u�W�F�N�g�ւ̃|�C���^
    static CScene *m_pCur;  // ���݂ɂ�����ŐV�̃I�u�W�F�N�g�ւ̃|�C���^
    CScene *m_pPrev;        // �O�̃I�u�W�F�N�g�ւ̃|�C���^
    CScene *m_pNext;        // ���̃I�u�W�F�N�g�ւ̃|�C���^

    static int m_nNumAll;   // �V�[����̃I�u�W�F�N�g�̍ő吔
    OBJTYPE m_objType;      // �I�u�W�F�N�g�̎��

    bool m_bUse;            // �g�p���邩�ǂ���
};

#endif