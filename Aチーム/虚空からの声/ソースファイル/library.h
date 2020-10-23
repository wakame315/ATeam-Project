//===============================================
//
// �l�X�ȏ������܂Ƃ߂��t�@�C�� [library.h]
// Author : �㓡�T�V��
//
//===============================================
#ifndef _LIBRARY_H_
#define _LIBRARY_H_

//========================
// �C���N���[�h�t�@�C��
//========================
#include "main.h"

//========================
// �}�N����`
//========================
#define HIT_TOP D3DXVECTOR3(D3DXToRadian(90.0f), 0.0f, 0.0f)
#define HIT_LEFT D3DXVECTOR3(0.0f, D3DXToRadian(90.0f), 0.0f)
#define HIT_BACK D3DXVECTOR3(0.0f, D3DXToRadian(180.0f)
#define HIT_RIGHT D3DXVECTOR3(0.0f, D3DXToRadian(270.0f), 0.0f)
#define HIT_FRONT D3DXVECTOR3(0.0f, 0.0f, D3DXToRadian(0.0001f))

//========================
// �񋓌^��`
//========================
// �u���b�N�ɓ����������̖�
typedef enum
{
    HIT_SURFACE_NONE = 0,     // �������Ă��Ȃ�
    HIT_SURFACE_RIGHT,        // �E
    HIT_SURFACE_LEFT,         // ��
    HIT_SURFACE_FRONT,        // ��O
    HIT_SURFACE_BACK,         // ��
    HIT_SURFACE_TOP,          // ���
    HIT_SURFACE_BOTTOM,       // ��
}HIT_SURFACE;

//========================
// �\���̒�`
//========================
// �u���b�N�ɓ����������̏��
typedef struct
{
    HIT_SURFACE hitSurface;     // ����������
    D3DXVECTOR3 pos;            // �ʒu
}BLOCK_HIT_INFO;

//===========================================
// �v���g�^�C�v�錾
//===========================================
bool OutScreen2D(const D3DXVECTOR3 *pPos, const D3DXVECTOR3 *pSize);
bool OutGame2D(const D3DXVECTOR3 *pPos, const D3DXVECTOR3 *pSize);
bool SteyInScreen2D(D3DXVECTOR3 *pPos, D3DXVECTOR3 *pSize);
bool RectangleCollision2D(const D3DXVECTOR3 *pPos1, const D3DXVECTOR3*pPos2, const D3DXVECTOR3*pSize1, const D3DXVECTOR3*pSize2);
bool RectangleCollision3D(const D3DXVECTOR3 *pPos1, const D3DXVECTOR3*pPos2, const D3DXVECTOR3*pSize1, const D3DXVECTOR3*pSize2);
BLOCK_HIT_INFO BlockCollision3D(D3DXVECTOR3 *pPos1, D3DXVECTOR3 *pPos1Old, const D3DXVECTOR3*pPos2, const D3DXVECTOR3*pSize1, const D3DXVECTOR3*pSize2);
int GetRandNum(int nMax, int nMin);

#endif