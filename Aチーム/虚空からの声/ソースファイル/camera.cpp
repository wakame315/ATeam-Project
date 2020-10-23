//===============================================
//
// 光源処理 (light.cpp)
// Author : 樋宮匠
//
//===============================================

//========================
// インクルードファイル
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
// 静的メンバ変数宣言
//========================
D3DXVECTOR3 CCamera::m_posRDest = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
D3DXVECTOR3 CCamera::m_posVDest = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
CCamera::CAMERA_STATE CCamera::m_state = CCamera::CAMERA_NORMAL;
float CCamera::m_fR = CAMERA_OFFSET;
float CCamera::m_fΦ = 0;
float CCamera::m_fθ = 0;

D3DXVECTOR3 CCamera::m_posR = D3DXVECTOR3(0, 0, 0);

//=============================================================================
// コンストラクタ
//=============================================================================
CCamera::CCamera()
{
    D3DXMatrixIdentity(&m_mtxView);
    D3DXMatrixIdentity(&m_mtxProjection);
    m_pos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
    m_state = CAMERA_NORMAL;
    m_fR = CAMERA_OFFSET;
    m_fΦ = 1;
    m_fθ = 1;
    m_nCountState = 0;
}

//=============================================================================
// デストラクタ
//=============================================================================
CCamera::~CCamera()
{
}

//=============================================================================
// 初期化処理
//=============================================================================
HRESULT CCamera::Init(void)
{
	InitMouse();

	POINT Point;
	GetCursorPos(&Point);

    LPDIRECT3DDEVICE9 pDevice = CManager::GetRenderer()->GetDevice();

    m_posV = D3DXVECTOR3(0.0f, 30.0f, -30.0f);      //位置
    m_posR = D3DXVECTOR3(0.0f, 0.0f, 0.0f);      //注視点
    m_vecU = D3DXVECTOR3(0.0f, 1.0f, 0.0f);
	m_StartMousePos = D3DXVECTOR3(Point.x, Point.y, 0.0f);
	m_Amount_of_movement = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
    m_state = CAMERA_NORMAL;
    m_fR = CAMERA_OFFSET;
    m_fΦ = 1;
    m_fθ = 1;
    m_nCountState = 0;

    D3DXMatrixLookAtLH(&m_mtxView, &m_posV, &m_posR, &m_vecU);
    pDevice->SetTransform(D3DTS_VIEW, &m_mtxView);

    D3DXMatrixPerspectiveFovLH(&m_mtxProjection, D3DXToRadian(45.0f), (float)SCREEN_WIDTH / (float)SCREEN_HEIGHT, 10.0f, 2000.0f);
    pDevice->SetTransform(D3DTS_PROJECTION, &m_mtxProjection);

    return S_OK;
}

//=============================================================================
// 終了処理
//=============================================================================
void CCamera::Uninit(void)
{
}

//=============================================================================
// 更新処理
//=============================================================================
void CCamera::Update(void)
{
	//マウスの座標取得
	POINT Point;
	GetCursorPos(&Point);
	D3DXVECTOR3 MousePos = D3DXVECTOR3(Point.x, Point.y, 0);

	//キーボードの確保したメモリを取得
	CInputKeyboard *pInputKeyboard = CManager::GetInputKeyboard();

    //  カメラ位置修正処理
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
// インスタンス生成処理
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
// 注視点変更処理
//=============================================================================
void CCamera::SetCameraLookAt(D3DXVECTOR3 pos)
{
    m_posRDest = D3DXVECTOR3(pos.x, pos.y, pos.z);
}

//=============================================================================
// マウスの座標をウィンドウの中心に移動させる
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