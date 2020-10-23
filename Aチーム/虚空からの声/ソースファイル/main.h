//=============================================================================
//
// ���C������ [main.h]
// Author : �㓡�T�V���@//�}�T���^�E���̃T�g�V
//
//=============================================================================
#ifndef _MAIN_H_
#define _MAIN_H_

//*****************************************************************************
// �w�b�_�t�@�C���̃C���N���[�h
//*****************************************************************************
#include <WinSock2.h>
#include <windows.h>
#include "d3dx9.h"
#define DIRECTINPUT_VERSION (0x0800)
#include <dinput.h>
#include <xaudio2.h>
#include <thread>

//*****************************************************************************
// ���C�u�����t�@�C���̃����N
//*****************************************************************************
#pragma comment(lib, "d3d9.lib")    // �`�揈���ɕK�v
#pragma comment(lib, "d3dx9.lib")   // �g�����C�u����
#pragma comment(lib, "dxguid.lib")  // �R���|�[�l���g�g�p�ɕK�v
#pragma comment(lib,"dinput8.lib")  // ���͏����ɕK�v
#pragma comment(lib,"winmm.lib")
#pragma comment(lib,"ws2_32.lib")

//*****************************************************************************
// �}�N����`
//*****************************************************************************

// �E�C���h�E�̈ʒu
#define	WINDOW_POS_X	(0)
#define	WINDOW_POS_Y	(0)

// ��ʂ̕�
#define SCREEN_WIDTH	(1280)
#define SCREEN_HEIGHT	(720)

// ���_�ƃ|���S��
#define NUM_VERTEX	(4)
#define NUM_POLYGON	(2)

//���_�t�H�[�}�b�g		(���_���W|���_�J���[|�e�N�X�`�����W)
#define FVF_VERTEX_2D	(D3DFVF_XYZRHW|D3DFVF_DIFFUSE|D3DFVF_TEX1)
#define FVF_VERTEX_3D   (D3DFVF_XYZ|D3DFVF_NORMAL|D3DFVF_DIFFUSE|D3DFVF_TEX1)

// �f�t�H���g�ݒ�
#define DEFAULT_COLOR (D3DXCOLOR(1.0f,1.0f,1.0f,1.0f))
#define DEFAULT_VECTOR (D3DXVECTOR3(0.0f,0.0f,0.0f))

// �d��
#define GRAVITY (1.1f)

// �_�Ŏ���
#define BLINK_TIME 15

//�~����
#define M_PI 3.14159265358979

//*****************************************************************************
// �\���̒�`
//*****************************************************************************

typedef struct
{
    D3DXVECTOR3 pos;
    float rhw;
    D3DCOLOR col;
    D3DXVECTOR2 tex;
}VERTEX_2D;

typedef struct
{
    D3DXVECTOR3 pos;
    D3DXVECTOR3 nor;
    D3DCOLOR    col;
    D3DXVECTOR2 tex;
}VERTEX_3D;

//*****************************************************************************
// �v���g�^�C�v�錾
//*****************************************************************************
#ifdef _DEBUG
int GetFPS(void);    // FPS�擾
#endif

#endif