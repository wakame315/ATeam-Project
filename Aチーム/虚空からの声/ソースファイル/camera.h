//=============================================================================
//
// �J�������� [camera.h]
// Author : ��{��
//
//=============================================================================
#ifndef _CAMERA_H_
#define _CAMERA_H_

//*****************************************************************************
// �w�b�_�t�@�C���̃C���N���[�h
//*****************************************************************************
#include "main.h"
#include "input.h"

//================================================
// �}�N����`
//================================================
#define CAMERA_OFFSET 200
#define CAMERA_STATE_LENGTH 180

#define CAMERA_MOVE (7)

#define DISTANCE (80)

//�J�����̈ʒu
#define CAMERA_POS_X ((2000.0f) / 2)
#define CAMERA_POS_Y (800.0f)
#define CAMERA_POS_Z (-50.0f)

//�J�����̒����_
#define CAMERA_ROT_X ((2000.0f) / 2)
#define CAMERA_ROT_Y (-1200.0f)
#define CAMERA_ROT_Z (1000.0f)

// �������̃J�����̈ʒu�̔�����
#define CAMERA_WIN_POS D3DXVECTOR3(0.0f, 150.0f, 0.0f)
#define CAMERA_WIN_OFFSET 200
#define CAMERA_SENSITIVITY (0.23f)

// �J�[�\������
#define CURSOR_POS_Y 5.0f                                          
#define CURSOR_SIZE D3DXVECTOR3(50.0f, 50.0f, 0.0f)	               // �u���ꏊ�̑傫��
#define CURSOR_COLLISION_SIZE D3DXVECTOR3(10.0f, 10000.0f, 10.0f)  // �u���ꏊ�̓����蔻��̑傫��

//================================================
// ���C�g�N���X�錾
//================================================
class CCamera
{
public:
    CCamera();
    ~CCamera();

    typedef enum
    {
        CAMERA_NORMAL = 0,
        CAMERA_PLAYER,
    }CAMERA_STATE;

    HRESULT Init(void);
    void Uninit(void);
    void Update(void);
    CCamera *Create(void);
	void InitMouse(void);
    static void SetCameraLookAt(D3DXVECTOR3 pos);
    static void SetCameraState(CAMERA_STATE state) { m_state = state; }

	static D3DXVECTOR3 GetCameraposR(void) { return m_posR; }

private:
    static D3DXVECTOR3	m_posRDest;
    static D3DXVECTOR3	m_posVDest;
	D3DXVECTOR3         m_Amount_of_movement;
	D3DXVECTOR3         m_StartMousePos;
	int                 m_nType;
    static CAMERA_STATE m_state;
    D3DXVECTOR3			m_posV;
    static D3DXVECTOR3  m_posR;
    D3DXVECTOR3			m_vecU;
    D3DXVECTOR3			m_pos;
    D3DXMATRIX			m_mtxProjection;
    D3DXMATRIX			m_mtxView;
    static float		m_fR;
    static float		m_f��;
    static float		m_f��;
    int					m_nCountState;
};

#endif