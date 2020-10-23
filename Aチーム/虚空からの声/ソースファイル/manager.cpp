//===============================================
//
// �����̊Ǘ����� (manager.cpp)
// Author : �㓡�T�V��
//
//===============================================

//========================
// �C���N���[�h�t�@�C��
//========================
#include "manager.h"
#include "scene2d.h"
#include "renderer.h"
#include "input.h"
#include "sound.h"
#include "mode.h"
#include "title.h"
#include "game.h"
#include "ui.h"
#include <typeinfo.h>
#include "fade.h"
#include "light.h"
#include "camera.h"
#include "bg.h"
#include "character.h"
#include "block.h"
#include "effect3d.h"
#include "field.h"
#include "effect.h"
#include "number.h"
#include "result.h"
#include "manual.h"
#include "CreateStage.h"

//========================================
// �}�N����`
//========================================

//========================================
// �ÓI�����o�ϐ��錾
//========================================
CRenderer *CManager::m_pRenderer = NULL;
CInputKeyboard *CManager::m_pInputKeyboard = NULL;
CInputJoypad *CManager::m_pInputJoypad = NULL;
CSound *CManager::m_pSound = NULL;
CMode *CManager::m_pMode = NULL;
CFade *CManager::m_pFade = NULL;
CCamera *CManager::m_pCamera = NULL;
CLight *CManager::m_pLight = NULL;
CMouse* CManager::m_pMouse = NULL;
CCreateStage* CManager::m_pCreateStage = NULL;

//========================================
// �����̊Ǘ��̃f�t�H���g�R���X�g���N�^
//========================================
CManager::CManager()
{

}

//========================================
// �����̊Ǘ��̃f�X�g���N�^
//========================================
CManager::~CManager()
{

}

//========================================
// �����̊Ǘ��̏���������
//========================================
HRESULT CManager::Init(HINSTANCE hInstance, HWND hWnd, bool bWindow)
{
	//�X�e�[�W����p�|�C���^�̐���
	m_pCreateStage = new CCreateStage;
	//�}�E�X�̐���
	m_pMouse = new CMouse;
    // �����_���[�̐���(��񂵂��������Ȃ����̂́ACreate��p�ӂ��Ă��Ȃ�)
    m_pRenderer = new CRenderer;

	if (m_pCreateStage->Init() == E_FAIL) {
		return E_FAIL;
	}
	if (m_pMouse->Init(hInstance, hWnd) == E_FAIL)
	{
		return E_FAIL;
	}
    // �����_���[����������
    if (FAILED(m_pRenderer->Init(hWnd, bWindow)))
    {
        return E_FAIL;
    }

    // �L�[�{�[�h�̐���(new��Init�͘A�������ď���)
    m_pInputKeyboard = new CInputKeyboard;

    // �L�[�{�[�h�̏���������
    if (FAILED(m_pInputKeyboard->Init(hInstance, hWnd)))
    {
        return E_FAIL;
    }

    // �R���g���[���̐���
    m_pInputJoypad = new CInputJoypad;

    // �R���g���[���̏���������
    if (FAILED(m_pInputJoypad->Init(hInstance, hWnd)))
    {
        return E_FAIL;
    }

    // �T�E���h�̐���
    m_pSound = new CSound;
    if (FAILED(m_pSound->Init(hWnd)))
    {
        return E_FAIL;
    }

    // ���C�g�̐���
    m_pLight = new CLight;
    if (FAILED(m_pLight->Init()))
    {
        return E_FAIL;
    }

    // �J�����̐���
    m_pCamera = new CCamera;
    if (FAILED(m_pCamera->Init()))
    {
        return E_FAIL;
    }

    // �t�F�[�h�̐���
    m_pFade = CFade::Create(MODE_GAME);    // �ŏ��̓^�C�g��

    // �e�N�X�`���̃��[�h
    CUI::Load();
    CNumber::Load();
    CCharacter::Load();
    CBg::Load();
    CBlock::Load();
    CEffect::Load();
    CEffect3D::Load();
    CField::Load();

    return S_OK;
}

//========================================
// �����̊Ǘ��̏I������
//========================================
void CManager::Uninit(void)
{
    // �S�ẴI�u�W�F�N�g��j��
    CScene::ReleaseAll();

    // �e�N�X�`���̃A�����[�h
    CUI::Unload();
    CNumber::Unload();
    CCharacter::Unload();
    CBg::Unload();
    CBlock::Unload();
    CEffect::Unload();
    CEffect3D::Unload();
    CField::Unload();

    // ���[�h�j��
    if (m_pMode != NULL)
    {
        // ���[�h�̏I������
        m_pMode->Uninit();

        // ���[�h�̃������̊J��
        delete m_pMode;
        m_pMode = NULL;
    }

    // �t�F�[�h�j��
    if (m_pFade != NULL)
    {
        // �t�F�[�h�̏I������
        m_pFade->Uninit();

        // �t�F�[�h�̃������̊J��
        delete m_pFade;
        m_pFade = NULL;
    }

    // �T�E���h�j��
    if (m_pSound != NULL)
    {
        // �T�E���h�I������
        m_pSound->Uninit();

        // �T�E���h�̃������̊J��
        delete m_pSound;
        m_pSound = NULL;
    }

    // �R���g���[���j��
    if (m_pInputJoypad != NULL)
    {
        // �R���g���[���I������
        m_pInputJoypad->Uninit();

        // �R���g���[���̃������̊J��
        delete m_pInputJoypad;
        m_pInputJoypad = NULL;
    }

    // �L�[�{�[�h�j���iInit�Ő��������t���Ŕj������j
    if (m_pInputKeyboard != NULL)
    {
        // �L�[�{�[�h�I������
        m_pInputKeyboard->Uninit();

        // �L�[�{�[�h�̃������̊J��
        delete m_pInputKeyboard;
        m_pInputKeyboard = NULL;
    }

    // �����_���[�j��
    if (m_pRenderer != NULL)
    {
        // �����_���[�I������
        m_pRenderer->Uninit();

        // �����_���[�̃������̊J��
        delete m_pRenderer;
        m_pRenderer = NULL;
    }

	//�}�E�X�̔j��
	if (m_pMouse != NULL) {
		// �}�E�X�I������
		m_pMouse->Uninit();

		// �}�E�X�̃������̊J��
		delete m_pMouse;
		m_pMouse = NULL;
	}

	//�X�e�[�W����p�|�C���^�̔j��
	if (m_pCreateStage != NULL) {
		// �X�e�[�W����p�|�C���^�I������
		m_pCreateStage->Uninit();

		// �X�e�[�W����p�|�C���^�̃������̊J��
		delete m_pCreateStage;
		m_pCreateStage = NULL;
	}

}

//========================================
// �����̊Ǘ��̍X�V����
//========================================
void CManager::Update(void)
{
	//�}�E�X�̍X�V����
	if (m_pMouse != NULL) {
		m_pMouse->Update();
	}

	// �R���g���[���X�V����
	if (m_pInputJoypad != NULL)
	{
		m_pInputJoypad->Update();
	}
    // �L�[�{�[�h�X�V����
    if (m_pInputKeyboard != NULL)
    {
        m_pInputKeyboard->Update();
    }

    // �����_���[�X�V����
    if (m_pRenderer != NULL)
    {
        m_pRenderer->Update();
    }
	//�X�e�[�W����p�|�C���^�̍X�V
	if (m_pCreateStage != NULL) {
		m_pCreateStage->Update();
	}
	// �t�F�[�h�̍X�V����
	if (m_pFade != NULL)
	{
		m_pFade->Update();
	}
    // ���[�h�̍X�V����
    if (m_pMode != NULL)
    {
        m_pMode->Update();
    }
    // �J�����̍X�V����
    if (m_pCamera != NULL)
    {
        // �Q�[�����Ȃ�
        if (typeid(*m_pMode) == typeid(CGame))
        {
            m_pCamera->Update();
        }
    }
}

//========================================
// �����̊Ǘ��̕`�揈��
//========================================
void CManager::Draw(void)
{
    // �`�揈��
    if (m_pRenderer != NULL)
    {
        m_pRenderer->Draw();
    }
}

//========================================
// ���[�h�̎擾
//========================================
CManager::MODE CManager::GetMode(void)
{
    // �Ԃ�l�Ɏg�����[�h
    MODE mode = MODE_NONE;

    // ���̃��[�h�������Ă��邩���āA�^�����Ƃɏꍇ����
    if (typeid(*m_pMode) == typeid(CTitle))
    {
        mode = MODE_TITLE;
    }
    else if (typeid(*m_pMode) == typeid(CManual))
    {
        mode = MODE_MANUAL;
    }
    else if (typeid(*m_pMode) == typeid(CGame))
    {
        mode = MODE_GAME;
    }
    else if (typeid(*m_pMode) == typeid(CResult))
    {
        mode = MODE_RESULT;
    }

    return mode;
}

//========================================
// ���[�h�̐ݒ�
// mode	:	�ݒ肷�郂�[�h
//========================================
void CManager::SetMode(MODE mode)
{
    // ���[�h�̒��g������Ȃ�
    if (m_pMode != NULL)
    {
        // �I������
        m_pMode->Uninit();

        // �������̔j��
        delete m_pMode;
        m_pMode = NULL;
    }

    // �V�[����̃I�u�W�F�N�g��S�ďI������
    CScene::ReleaseAll();

    // �󂯎�������[�h�ɉ�ʑJ��
    switch (mode)
    {
    case MODE_TITLE:
        m_pMode = new CTitle;
        break;

    case MODE_MANUAL:
        m_pMode = new CManual;
        break;

    case MODE_GAME:
        m_pMode = new CGame;
        break;

    case MODE_RESULT:
        m_pMode = new CResult;
        break;
    }

    // �m�ۂ������[�h�̏�����
    m_pMode->Init();
}