//===============================================
//
// �������� (light.cpp)
// Author : ��{��
//
//===============================================

//========================
// �C���N���[�h�t�@�C��
//========================
#include "camera.h"
#include "manager.h"
#include "renderer.h"
#include "input.h"
#include "game.h"
#include "character.h"
#include "block.h"
#include "effect3d.h"
#include "library.h"

//========================
// �ÓI�����o�ϐ��錾
//========================
D3DXVECTOR3 CCamera::m_posRDest = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
D3DXVECTOR3 CCamera::m_posVDest = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
CCamera::CAMERA_STATE CCamera::m_state = CCamera::CAMERA_NORMAL;
float CCamera::m_fR = CAMERA_OFFSET;
float CCamera::m_f�� = 0;
float CCamera::m_f�� = 0;

D3DXVECTOR3 CCamera::m_posR = D3DXVECTOR3(0, 0, 0);

//=============================================================================
// �R���X�g���N�^
//=============================================================================
CCamera::CCamera()
{
    D3DXMatrixIdentity(&m_mtxView);
    D3DXMatrixIdentity(&m_mtxProjection);
    m_pos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
    m_state = CAMERA_NORMAL;
    m_fR = CAMERA_OFFSET;
    m_f�� = 1;
    m_f�� = 1;
    m_nCountState = 0;
}

//=============================================================================
// �f�X�g���N�^
//=============================================================================
CCamera::~CCamera()
{
}

//=============================================================================
// ����������
//=============================================================================
HRESULT CCamera::Init(void)
{
	InitMouse();

	POINT Point;
	GetCursorPos(&Point);

    LPDIRECT3DDEVICE9 pDevice = CManager::GetRenderer()->GetDevice();

    m_posV = D3DXVECTOR3(0.0f, 30.0f, -30.0f);      //�ʒu
    m_posR = D3DXVECTOR3(0.0f, 0.0f, 0.0f);      //�����_
    m_vecU = D3DXVECTOR3(0.0f, 1.0f, 0.0f);
	m_StartMousePos = D3DXVECTOR3(Point.x, Point.y, 0.0f);
	m_Amount_of_movement = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
    m_state = CAMERA_NORMAL;
    m_fR = CAMERA_OFFSET;
    m_f�� = 1;
    m_f�� = 1;
    m_nCountState = 0;

    D3DXMatrixLookAtLH(&m_mtxView, &m_posV, &m_posR, &m_vecU);
    pDevice->SetTransform(D3DTS_VIEW, &m_mtxView);

    D3DXMatrixPerspectiveFovLH(&m_mtxProjection, D3DXToRadian(45.0f), (float)SCREEN_WIDTH / (float)SCREEN_HEIGHT, 10.0f, 2000.0f);
    pDevice->SetTransform(D3DTS_PROJECTION, &m_mtxProjection);

    return S_OK;
}

//=============================================================================
// �I������
//=============================================================================
void CCamera::Uninit(void)
{
}

//=============================================================================
// �X�V����
//=============================================================================
void CCamera::Update(void)
{
	//�}�E�X�̍��W�擾
	POINT Point;
	GetCursorPos(&Point);
	D3DXVECTOR3 MousePos = D3DXVECTOR3(Point.x, Point.y, 0);

	//�L�[�{�[�h�̊m�ۂ������������擾
	CInputKeyboard *pInputKeyboard = CManager::GetInputKeyboard();

    //  �J�����ʒu�C������
    LPDIRECT3DDEVICE9 pDevice = CManager::GetRenderer()->GetDevice();

	m_Amount_of_movement.y += (m_StartMousePos.y - MousePos.y) * CAMERA_SENSITIVITY;
	m_Amount_of_movement.x += (MousePos.x - m_StartMousePos.x) * CAMERA_SENSITIVITY;

	if (m_Amount_of_movement.y >= 89) {
		m_Amount_of_movement.y = 89;
	}
	if (m_Amount_of_movement.y <= -89) {
		m_Amount_of_movement.y = -89;
	}

	if (pInputKeyboard->GetKeyboardPress(DIK_W)) {
		m_posV.x += sinf(D3DXToRadian(m_Amount_of_movement.x))*5.0f;
		m_posV.z += cosf(D3DXToRadian(m_Amount_of_movement.x))*5.0f;
	}
	if (pInputKeyboard->GetKeyboardPress(DIK_S)) {
		m_posV.x -= sinf(D3DXToRadian(m_Amount_of_movement.x))*5.0f;
		m_posV.z -= cosf(D3DXToRadian(m_Amount_of_movement.x))*5.0f;
	}
	if (pInputKeyboard->GetKeyboardPress(DIK_A)) {
		m_posV.x -= sinf(D3DXToRadian(m_Amount_of_movement.x + 90))*5.0f;
		m_posV.z -= cosf(D3DXToRadian(m_Amount_of_movement.x + 90))*5.0f;
	}
	if (pInputKeyboard->GetKeyboardPress(DIK_D)) {
		m_posV.x += sinf(D3DXToRadian(m_Amount_of_movement.x + 90))*5.0f;
		m_posV.z += cosf(D3DXToRadian(m_Amount_of_movement.x + 90))*5.0f;
	}
	if (pInputKeyboard->GetKeyboardPress(DIK_LSHIFT)) {
		m_posV.y -= 5.0f;
	}
	if (pInputKeyboard->GetKeyboardPress(DIK_SPACE)) {
		m_posV.y += 5.0f;
	}

	m_posR.x = m_posV.x + sinf(D3DXToRadian(m_Amount_of_movement.x)) * DISTANCE;
	m_posR.y = m_posV.y + tanf(D3DXToRadian(m_Amount_of_movement.y)) * DISTANCE;
	m_posR.z = m_posV.z + cosf(D3DXToRadian(m_Amount_of_movement.x)) * DISTANCE; 

    D3DXMatrixLookAtLH(&m_mtxView, &m_posV, &m_posR, &m_vecU);
    pDevice->SetTransform(D3DTS_VIEW, &m_mtxView);

    D3DXMatrixPerspectiveFovLH(&m_mtxProjection, D3DXToRadian(90), (float)SCREEN_WIDTH / (float)SCREEN_HEIGHT, 10.0f, 10000.0f);
    pDevice->SetTransform(D3DTS_PROJECTION, &m_mtxProjection);

	InitMouse();
}
//=============================================================================
// �C���X�^���X��������
//=============================================================================
CCamera * CCamera::Create(void)
{
    CCamera *pCamera = NULL;
    pCamera = new CCamera;
    pCamera->Init();
	pCamera->m_nType = 0;
    return pCamera;
}

//=============================================================================
// �����_�ύX����
//=============================================================================
void CCamera::SetCameraLookAt(D3DXVECTOR3 pos)
{
    m_posRDest = D3DXVECTOR3(pos.x, pos.y, pos.z);
}

//=============================================================================
// �}�E�X�̍��W���E�B���h�E�̒��S�Ɉړ�������
//=============================================================================
void CCamera::InitMouse(void) {
	HWND hDesktop = GetDesktopWindow();

	WINDOWINFO windowInfo;
	LONG pos_x, pos_y;
	windowInfo.cbSize = sizeof(WINDOWINFO);

	GetWindowInfo(hDesktop, &windowInfo);
	pos_x = windowInfo.rcWindow.left;
	pos_y = windowInfo.rcWindow.top;
	SetCursorPos(SCREEN_WIDTH / 2 + pos_x, SCREEN_HEIGHT / 2 + pos_y);
}