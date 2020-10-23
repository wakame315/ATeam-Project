//===============================================
//
// �l�X�ȏ������܂Ƃ߂��t�@�C�� (library.cpp)
// Author : �㓡�T�V��
//
//===============================================

//========================
// �C���N���[�h�t�@�C��
//========================
#include "library.h"

//===========================================
// ��ʊO���ǂ���(�񎟌�)
//===========================================
bool OutScreen2D(const D3DXVECTOR3 *pPos, const D3DXVECTOR3 *pSize)
{
    // �ϐ��錾
    bool bOutScreen = false;    // ��ʊO���ǂ���

                                // ��ʂ̒[����o�Ă��邩�ǂ���
    if (pPos->x < -(pSize->x / 2) ||
        pPos->x > SCREEN_WIDTH + pSize->x / 2 ||
        pPos->y < -(pSize->y / 2) ||
        pPos->y > SCREEN_HEIGHT + pSize->y / 2)
    {
        // ��ʊO�̃t���O��true��
        bOutScreen = true;
    }

    return bOutScreen;
}

//===========================================
// �Q�[���O���ǂ���(�񎟌�)
//===========================================
bool OutGame2D(const D3DXVECTOR3 * pPos, const D3DXVECTOR3 * pSize)
{
    // �ϐ��錾
    bool bOutGame = false;    // �Q�[���O���ǂ���

                              // ��ʂ̒[����2�{�̂Ƃ��납��o�Ă��邩�ǂ���
    if (pPos->x < -SCREEN_WIDTH - (pSize->x / 2) ||
        pPos->x >(SCREEN_WIDTH * 2) + pSize->x / 2 ||
        pPos->y < -SCREEN_HEIGHT - (pSize->y / 2) ||
        pPos->y >(SCREEN_HEIGHT * 2) + pSize->y / 2)
    {
        // �Q�[���O�̃t���O��true��
        bOutGame = true;
    }

    return bOutGame;
}

//===========================================
// ��ʓ��ɂƂǂ܂点��(�񎟌�)
//===========================================
bool SteyInScreen2D(D3DXVECTOR3 *pPos, D3DXVECTOR3 *pSize)
{
    // �ϐ��錾
    bool bScreenEdge = false;    // ��ʒ[���ǂ���

                                 // ��ʂ̍�
    if (pPos->x < pSize->x / 2)
    {
        // �Ƃǂ܂点��
        pPos->x = pSize->x / 2;

        // ��ʒ[�̃t���O��true��
        bScreenEdge = true;
    }

    // ��ʂ̉E
    if (pPos->x > SCREEN_WIDTH - pSize->x / 2)
    {
        // �Ƃǂ܂点��
        pPos->x = SCREEN_WIDTH - pSize->x / 2;

        // ��ʒ[�̃t���O��true��
        bScreenEdge = true;
    }

    // ��ʂ̏�
    if (pPos->y < pSize->y / 2)
    {
        // �Ƃǂ܂点��
        pPos->y = pSize->y / 2;

        // ��ʒ[�̃t���O��true��
        bScreenEdge = true;
    }

    // ��ʂ̉�
    if (pPos->y > SCREEN_HEIGHT - pSize->y / 2)
    {
        // �Ƃǂ܂点��
        pPos->y = SCREEN_HEIGHT - pSize->y / 2;

        // ��ʒ[�̃t���O��true��
        bScreenEdge = true;
    }

    return bScreenEdge;
}

//===========================================
// ��`�̓����蔻��2D
//===========================================
bool RectangleCollision2D(const D3DXVECTOR3 *pPos1, const D3DXVECTOR3*pPos2, const D3DXVECTOR3*pSize1, const D3DXVECTOR3*pSize2)
{
    // �ϐ��錾
    bool bHit = false;    // �����������ǂ���

                          // ��̂��̂̓����蔻����v�Z
    if (pPos1->x - pSize1->x / 2 <= pPos2->x + pSize2->x / 2 &&
        pPos1->x + pSize1->x / 2 >= pPos2->x - pSize2->x / 2 &&
        pPos1->y - pSize1->y / 2 <= pPos2->y + pSize2->y / 2 &&
        pPos1->y + pSize1->y / 2 >= pPos2->y - pSize2->y / 2)
    {
        // ���������t���O��true��
        bHit = true;
    }

    return bHit;
}

//===========================================
// ��`�̓����蔻��3D
//===========================================
bool RectangleCollision3D(const D3DXVECTOR3 *pPos1, const D3DXVECTOR3*pPos2, const D3DXVECTOR3*pSize1, const D3DXVECTOR3*pSize2)
{
    // �ϐ��錾
    bool bHit = false;  // �����������ǂ���

    D3DXVECTOR3 box1Max = D3DXVECTOR3(pSize1->x / 2, pSize1->y, pSize1->z / 2) + *pPos1;    //�Ԃ��鑤�̍ő�l
    D3DXVECTOR3 box1Min = D3DXVECTOR3(-pSize1->x / 2, 0.0f, -pSize1->z / 2) + *pPos1;       //�Ԃ��鑤�̍ŏ��l
    D3DXVECTOR3 box2Max = D3DXVECTOR3(pSize2->x / 2, pSize2->y, pSize2->z / 2) + *pPos2;    //�Ԃ����鑤�̍ő�l
    D3DXVECTOR3 box2Min = D3DXVECTOR3(-pSize2->x / 2, 0.0f, -pSize2->z / 2) + *pPos2;       //�Ԃ����鑤�̍ŏ��l

                                                                                            // �����蔻����v�Z
    if (box1Max.y > box2Min.y&&
        box1Min.y < box2Max.y&&
        box1Max.x > box2Min.x&&
        box1Min.x < box2Max.x&&
        box1Max.z > box2Min.z&&
        box1Min.z < box2Max.z)
    {
        bHit = true;
    }

    return bHit;
}

//===========================================
// �u���b�N�̓����蔻��3D
//===========================================
BLOCK_HIT_INFO BlockCollision3D(D3DXVECTOR3 * pPos1, D3DXVECTOR3 * pPos1Old, const D3DXVECTOR3 * pPos2, const D3DXVECTOR3 * pSize1, const D3DXVECTOR3 * pSize2)
{
    // �u���b�N�ɓ����������
    BLOCK_HIT_INFO blockHitInfo;
    blockHitInfo.hitSurface = HIT_SURFACE_NONE;
    blockHitInfo.pos = *pPos1;

    D3DXVECTOR3 box1Max = D3DXVECTOR3(pSize1->x / 2, pSize1->y, pSize1->z / 2) + *pPos1;      //�Ԃ��鑤�̍ő�l
    D3DXVECTOR3 box1Min = D3DXVECTOR3(-pSize1->x / 2, 0.0f, -pSize1->z / 2) + *pPos1;         //�Ԃ��鑤�̍ŏ��l
    D3DXVECTOR3 box2Max = D3DXVECTOR3(pSize2->x / 2, pSize2->y, pSize2->z / 2) + *pPos2;      //�Ԃ����鑤�̍ő�l
    D3DXVECTOR3 box2Min = D3DXVECTOR3(-pSize2->x / 2, 0.0f, -pSize2->z / 2) + *pPos2;         //�Ԃ����鑤�̍ŏ��l

                                                                                              // �����蔻����v�Z
    if (box1Max.y > box2Min.y&&
        box1Min.y <= box2Max.y&&
        box1Max.x > box2Min.x&&
        box1Min.x < box2Max.x&&
        box1Max.z > box2Min.z&&
        box1Min.z < box2Max.z)
    {
        if (box1Max.y > box2Min.y&&
            pPos1Old->y + pSize1->y / 2 < box2Min.y)
        {// Y���̉�
            blockHitInfo.hitSurface = HIT_SURFACE_BOTTOM;
            blockHitInfo.pos.y = box2Min.y - pSize1->y;
        }
        if (box1Min.y <= box2Max.y&&
            pPos1Old->y >= box2Max.y)
        {// Y���̏�
            blockHitInfo.hitSurface = HIT_SURFACE_TOP;
            blockHitInfo.pos.y = box2Max.y;
        }
        if (box1Max.x > box2Min.x&&
            pPos1Old->x + pSize1->x / 2 <= box2Min.x)
        {// X���̍�
            blockHitInfo.hitSurface = HIT_SURFACE_LEFT;
            blockHitInfo.pos.x = box2Min.x - pSize1->x / 2;
        }
        if (box1Min.x < box2Max.x&&
            pPos1Old->x - pSize1->x / 2 >= box2Max.x)
        {// X���̉E
            blockHitInfo.hitSurface = HIT_SURFACE_RIGHT;
            blockHitInfo.pos.x = box2Max.x + pSize1->x / 2;
        }
        if (box1Max.z > box2Min.z&&
            pPos1Old->z + pSize1->z / 2 <= box2Min.z)
        {// Z���̎�O
            blockHitInfo.hitSurface = HIT_SURFACE_FRONT;
            blockHitInfo.pos.z = box2Min.z - pSize1->z / 2;
        }
        if (box1Min.z < box2Max.z&&
            pPos1Old->z - pSize1->z / 2 >= box2Max.z)
        {// Z���̉�
            blockHitInfo.hitSurface = HIT_SURFACE_BACK;
            blockHitInfo.pos.z = box2Max.z + pSize1->z / 2;
        }
    }

    return blockHitInfo;
}

//===========================================
// �͈͓��ŁA�����_���Ȑ����𓾂�
//===========================================
int GetRandNum(int nMax, int nMin)
{
    int nRandNum = rand() % (nMax - nMin + 1) + nMin;

    return nRandNum;
}
