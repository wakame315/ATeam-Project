//====================================================================
//
// �u���b�N�̏��� (character.h)
// Author : ��{��
//
//====================================================================
#ifndef _BLOCK_H_
#define _BLOCK_H_

//================================================
// �C���N���[�h�t�@�C��
//================================================
#include "main.h"
#include "scene3d.h"

//========================================
// �}�N����`
//========================================
#define BLOCK_BUILDING_COLLISION_SIZE D3DXVECTOR3(625.0f, 1650.0f, 625.0f)   // �r���̓����蔻��̑傫��
#define BLOCK_SIGNAL_COLLISION_SIZE D3DXVECTOR3(80.0f, 1100.0f, 80.0f)       // �M���̓����蔻��̑傫��
#define BLOCK_LIGHT_COLLISION_SIZE D3DXVECTOR3(80.0f, 1050.0f, 80.0f)        // �X���̓����蔻��̑傫��
#define BLOCK_DUSTBOX_COLLISION_SIZE D3DXVECTOR3(80.0f, 120.0f, 80.0f)       // �S�~���̓����蔻��̑傫��

//================================================
// �N���X�錾
//================================================

// �u���b�N�N���X
class CBlock : public CScene3D
{
public:

    // �u���b�N�̎��
    typedef enum
    {
        TYPE_BUILDING001,   // �r��1
        TYPE_BUILDING101,   // �r��2
        TYPE_BUILDING201,   // �r��3
        TYPE_BUILDING301,   // �r��4
        TYPE_BUILDING401,   // �r��5
        TYPE_BUILDING501,   // �r��6
        TYPE_SIGNAL,        // �M���@
        TYPE_LIGHT,         // �X��
        TYPE_DUSTBOX,       // �S�~��
        TYPE_MAX            // ��ނ̍ő吔
    }TYPE;

    CBlock();
    ~CBlock();
    HRESULT Init(D3DXVECTOR3 pos, D3DXVECTOR3 size, D3DXVECTOR3 rot, int nType);
    void Uninit(void);
    void Update(void);
    void Draw(void);
    static HRESULT Load(void);
    static void Unload(void);
    static CBlock *Create(D3DXVECTOR3 pos, D3DXVECTOR3 rot, int nType);

    D3DXVECTOR3 GetCollisionSize(void) { return m_collisionSize; }          // �Փ˂̑傫����Ԃ�
    bool GetWallRun(void) { return m_bWallRun; }                            // �Ǒ���ł��邩�ǂ�����Ԃ�

    static CBlock*GetSelectBlock(void) { return m_pSelectBlock; }           // �I�����Ă���u���b�N���擾
    static void SetSelectBlock(CBlock* pBlock) { m_pSelectBlock = pBlock; } // �I�����Ă���u���b�N��ݒ�

	int GetType(void) { return m_nType; }
	static int GetBlockNumAll(void) { return m_nNumAll; }

private:
    static LPDIRECT3DTEXTURE9		m_apTexture[TYPE_MAX];  // �ǂݍ��ރe�N�X�`��
    static LPD3DXMESH				m_apMesh[TYPE_MAX];     // �ǂݍ��ރ��b�V��
    static LPD3DXBUFFER				m_apBuffMat[TYPE_MAX];  // �ǂݍ��ރ}�e���A���̃o�b�t�@
    static DWORD					m_aNumMat[TYPE_MAX];    // �ǂݍ��ރ}�e���A����

    static CBlock *m_pSelectBlock;                          // ���ݑI�����Ă���u���b�N�̃|�C���^

    D3DXVECTOR3 m_collisionSize;                            // �����蔻��̑傫��
    bool m_bWallRun;                                        // �Ǒ���ł��邩�ǂ���
    bool m_bBlink;                                          // �u�����ǂ���
    int m_nCntTime;                                         // ���Ԃ𐔂���
	static int m_nNumAll;                                   // �u���b�N�̑���

    int m_nType;                                            // ���
};

#endif