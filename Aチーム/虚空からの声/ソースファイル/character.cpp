//===============================================
//
// �A�j���[�V�������� (animation.cpp)
// Author : ��{��
//
//===============================================
#define _CRT_SECURE_NO_WARNINGS

//========================
// �C���N���[�h�t�@�C��
//========================
#include "character.h"
#include "manager.h"
#include "renderer.h"
#include "input.h"
#include "animation.h"
#include "scene3d.h"
#include "library.h"
#include "game.h"

//========================================
// �ÓI�����o�ϐ��錾
//========================================
//LPD3DXMESH CCharacter::m_pMesh[PARTS_MAX] = {};
//LPD3DXBUFFER CCharacter::m_pBuffMat[PARTS_MAX] = {};
//DWORD CCharacter::m_nNumMat[PARTS_MAX] = {};
LPD3DXMESH CCharacter::m_pMesh[TYPE_MAX][PARTS_MAX] = {};
LPD3DXBUFFER CCharacter::m_pBuffMat[TYPE_MAX][PARTS_MAX] = {};
DWORD CCharacter::m_nNumMat[TYPE_MAX][PARTS_MAX] = {};
int CCharacter::m_nIndexParent[PARTS_MAX] = {};
D3DXVECTOR3	CCharacter::m_posDefault[PARTS_MAX] = {};

//=============================================================================
// �R���X�g���N�^
//=============================================================================
CCharacter::CCharacter() :CScene(OBJTYPE::OBJTYPE_PLAYER)
{
    m_pos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
    m_posOld = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
    m_move = DEFAULT_VECTOR;
    m_rot = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
    m_type = TYPE_PLAYER1;
    memset(m_apModel, 0, sizeof(m_apModel));
    m_bUse = true;
    m_nWave = WAVE_MAX;
}

//=============================================================================
// �f�X�g���N�^
//=============================================================================
CCharacter::~CCharacter()
{
}

//=============================================================================
// ����������
//=============================================================================
HRESULT CCharacter::Init(D3DXVECTOR3 pos, D3DXVECTOR3 size, D3DXVECTOR3 rot)
{
    m_pos = pos;
    m_posOld = pos;
    memset(m_apModel, 0, sizeof(m_apModel));

    for (int nCount = 0; nCount < PARTS_MAX; nCount++)
    {
        m_apModel[nCount] = new CModel;
        m_apModel[nCount]->SetPos(pos);
        m_apModel[nCount]->SetRot(m_rot);
        m_apModel[nCount]->SetScale(size);
        m_apModel[nCount]->BindMesh(m_pMesh[m_type][nCount], m_pBuffMat[m_type][nCount], m_nNumMat[m_type][nCount]);
    }

    LoadModelData();

    m_pAnimation = CAnimation::Create(this);

    return S_OK;
}

//=============================================================================
// �I������
//=============================================================================
void CCharacter::Uninit(void)
{
    Release();
}

//=============================================================================
// �X�V����
//=============================================================================
void CCharacter::Update(void)
{
    // �A�j���[�V����
    m_pAnimation->Update();
}

//=============================================================================
// �`�揈��
//=============================================================================
void CCharacter::Draw(void)
{
    // �g�p�t���O��true�Ȃ�
    if (m_bUse == true)
    {
        for (int nCount = 0; nCount < PARTS_MAX; nCount++)
        {
            if (nCount == 0)
            {
                m_apModel[nCount]->Draw(m_pos, m_rot);
            }
            else
            {
                m_apModel[nCount]->Draw(m_apModel[m_nIndexParent[nCount]]);
            }
        }
    }
}

//=============================================================================
// ���f���f�[�^�ǂݍ��ݏ���
//=============================================================================
HRESULT CCharacter::Load(void)
{
    LPDIRECT3DDEVICE9 pDevice = CManager::GetRenderer()->GetDevice();

    // �v���C���[1
    D3DXLoadMeshFromX(LPCSTR("./data/MODEL/player/00_body.x"), D3DXMESH_SYSTEMMEM, pDevice, NULL, &m_pBuffMat[TYPE_PLAYER1][PARTS_BODY], NULL, &m_nNumMat[TYPE_PLAYER1][PARTS_BODY], &m_pMesh[TYPE_PLAYER1][PARTS_BODY]);
    D3DXLoadMeshFromX(LPCSTR("./data/MODEL/player/01_head.x"), D3DXMESH_SYSTEMMEM, pDevice, NULL, &m_pBuffMat[TYPE_PLAYER1][PARTS_HEAD], NULL, &m_nNumMat[TYPE_PLAYER1][PARTS_HEAD], &m_pMesh[TYPE_PLAYER1][PARTS_HEAD]);
    D3DXLoadMeshFromX(LPCSTR("./data/MODEL/player/02_armR.x"), D3DXMESH_SYSTEMMEM, pDevice, NULL, &m_pBuffMat[TYPE_PLAYER1][PARTS_RARM], NULL, &m_nNumMat[TYPE_PLAYER1][PARTS_RARM], &m_pMesh[TYPE_PLAYER1][PARTS_RARM]);
    D3DXLoadMeshFromX(LPCSTR("./data/MODEL/player/03_handR.x"), D3DXMESH_SYSTEMMEM, pDevice, NULL, &m_pBuffMat[TYPE_PLAYER1][PARTS_RHAND], NULL, &m_nNumMat[TYPE_PLAYER1][PARTS_RHAND], &m_pMesh[TYPE_PLAYER1][PARTS_RHAND]);
    D3DXLoadMeshFromX(LPCSTR("./data/MODEL/player/04_armL.x"), D3DXMESH_SYSTEMMEM, pDevice, NULL, &m_pBuffMat[TYPE_PLAYER1][PARTS_LARM], NULL, &m_nNumMat[TYPE_PLAYER1][PARTS_LARM], &m_pMesh[TYPE_PLAYER1][PARTS_LARM]);
    D3DXLoadMeshFromX(LPCSTR("./data/MODEL/player/05_handL.x"), D3DXMESH_SYSTEMMEM, pDevice, NULL, &m_pBuffMat[TYPE_PLAYER1][PARTS_LHAND], NULL, &m_nNumMat[TYPE_PLAYER1][PARTS_LHAND], &m_pMesh[TYPE_PLAYER1][PARTS_LHAND]);
    D3DXLoadMeshFromX(LPCSTR("./data/MODEL/player/06_legR.x"), D3DXMESH_SYSTEMMEM, pDevice, NULL, &m_pBuffMat[TYPE_PLAYER1][PARTS_RLEG], NULL, &m_nNumMat[TYPE_PLAYER1][PARTS_RLEG], &m_pMesh[TYPE_PLAYER1][PARTS_RLEG]);
    D3DXLoadMeshFromX(LPCSTR("./data/MODEL/player/07_footR.x"), D3DXMESH_SYSTEMMEM, pDevice, NULL, &m_pBuffMat[TYPE_PLAYER1][PARTS_RFOOT], NULL, &m_nNumMat[TYPE_PLAYER1][PARTS_RFOOT], &m_pMesh[TYPE_PLAYER1][PARTS_RFOOT]);
    D3DXLoadMeshFromX(LPCSTR("./data/MODEL/player/08_legL.x"), D3DXMESH_SYSTEMMEM, pDevice, NULL, &m_pBuffMat[TYPE_PLAYER1][PARTS_LLEG], NULL, &m_nNumMat[TYPE_PLAYER1][PARTS_LLEG], &m_pMesh[TYPE_PLAYER1][PARTS_LLEG]);
    D3DXLoadMeshFromX(LPCSTR("./data/MODEL/player/09_footL.x"), D3DXMESH_SYSTEMMEM, pDevice, NULL, &m_pBuffMat[TYPE_PLAYER1][PARTS_LFOOT], NULL, &m_nNumMat[TYPE_PLAYER1][PARTS_LFOOT], &m_pMesh[TYPE_PLAYER1][PARTS_LFOOT]);

    //// �v���C���[2
    //D3DXLoadMeshFromX(LPCSTR("./data/MODEL/player2/00_body.x"), D3DXMESH_SYSTEMMEM, pDevice, NULL, &m_pBuffMat[TYPE_PLAYER2][PARTS_BODY], NULL, &m_nNumMat[TYPE_PLAYER2][PARTS_BODY], &m_pMesh[TYPE_PLAYER2][PARTS_BODY]);
    //D3DXLoadMeshFromX(LPCSTR("./data/MODEL/player2/01_head.x"), D3DXMESH_SYSTEMMEM, pDevice, NULL, &m_pBuffMat[TYPE_PLAYER2][PARTS_HEAD], NULL, &m_nNumMat[TYPE_PLAYER2][PARTS_HEAD], &m_pMesh[TYPE_PLAYER2][PARTS_HEAD]);
    //D3DXLoadMeshFromX(LPCSTR("./data/MODEL/player2/02_armR.x"), D3DXMESH_SYSTEMMEM, pDevice, NULL, &m_pBuffMat[TYPE_PLAYER2][PARTS_RARM], NULL, &m_nNumMat[TYPE_PLAYER2][PARTS_RARM], &m_pMesh[TYPE_PLAYER2][PARTS_RARM]);
    //D3DXLoadMeshFromX(LPCSTR("./data/MODEL/player2/03_handR.x"), D3DXMESH_SYSTEMMEM, pDevice, NULL, &m_pBuffMat[TYPE_PLAYER2][PARTS_RHAND], NULL, &m_nNumMat[TYPE_PLAYER2][PARTS_RHAND], &m_pMesh[TYPE_PLAYER2][PARTS_RHAND]);
    //D3DXLoadMeshFromX(LPCSTR("./data/MODEL/player2/04_armL.x"), D3DXMESH_SYSTEMMEM, pDevice, NULL, &m_pBuffMat[TYPE_PLAYER2][PARTS_LARM], NULL, &m_nNumMat[TYPE_PLAYER2][PARTS_LARM], &m_pMesh[TYPE_PLAYER2][PARTS_LARM]);
    //D3DXLoadMeshFromX(LPCSTR("./data/MODEL/player2/05_handL.x"), D3DXMESH_SYSTEMMEM, pDevice, NULL, &m_pBuffMat[TYPE_PLAYER2][PARTS_LHAND], NULL, &m_nNumMat[TYPE_PLAYER2][PARTS_LHAND], &m_pMesh[TYPE_PLAYER2][PARTS_LHAND]);
    //D3DXLoadMeshFromX(LPCSTR("./data/MODEL/player2/06_legR.x"), D3DXMESH_SYSTEMMEM, pDevice, NULL, &m_pBuffMat[TYPE_PLAYER2][PARTS_RLEG], NULL, &m_nNumMat[TYPE_PLAYER2][PARTS_RLEG], &m_pMesh[TYPE_PLAYER2][PARTS_RLEG]);
    //D3DXLoadMeshFromX(LPCSTR("./data/MODEL/player2/07_footR.x"), D3DXMESH_SYSTEMMEM, pDevice, NULL, &m_pBuffMat[TYPE_PLAYER2][PARTS_RFOOT], NULL, &m_nNumMat[TYPE_PLAYER2][PARTS_RFOOT], &m_pMesh[TYPE_PLAYER2][PARTS_RFOOT]);
    //D3DXLoadMeshFromX(LPCSTR("./data/MODEL/player2/08_legL.x"), D3DXMESH_SYSTEMMEM, pDevice, NULL, &m_pBuffMat[TYPE_PLAYER2][PARTS_LLEG], NULL, &m_nNumMat[TYPE_PLAYER2][PARTS_LLEG], &m_pMesh[TYPE_PLAYER2][PARTS_LLEG]);
    //D3DXLoadMeshFromX(LPCSTR("./data/MODEL/player2/09_footL.x"), D3DXMESH_SYSTEMMEM, pDevice, NULL, &m_pBuffMat[TYPE_PLAYER2][PARTS_LFOOT], NULL, &m_nNumMat[TYPE_PLAYER2][PARTS_LFOOT], &m_pMesh[TYPE_PLAYER2][PARTS_LFOOT]);

    //// �v���C���[3
    //D3DXLoadMeshFromX(LPCSTR("./data/MODEL/player3/00_body.x"), D3DXMESH_SYSTEMMEM, pDevice, NULL, &m_pBuffMat[TYPE_PLAYER3][PARTS_BODY], NULL, &m_nNumMat[TYPE_PLAYER3][PARTS_BODY], &m_pMesh[TYPE_PLAYER3][PARTS_BODY]);
    //D3DXLoadMeshFromX(LPCSTR("./data/MODEL/player3/01_head.x"), D3DXMESH_SYSTEMMEM, pDevice, NULL, &m_pBuffMat[TYPE_PLAYER3][PARTS_HEAD], NULL, &m_nNumMat[TYPE_PLAYER3][PARTS_HEAD], &m_pMesh[TYPE_PLAYER3][PARTS_HEAD]);
    //D3DXLoadMeshFromX(LPCSTR("./data/MODEL/player3/02_armR.x"), D3DXMESH_SYSTEMMEM, pDevice, NULL, &m_pBuffMat[TYPE_PLAYER3][PARTS_RARM], NULL, &m_nNumMat[TYPE_PLAYER3][PARTS_RARM], &m_pMesh[TYPE_PLAYER3][PARTS_RARM]);
    //D3DXLoadMeshFromX(LPCSTR("./data/MODEL/player3/03_handR.x"), D3DXMESH_SYSTEMMEM, pDevice, NULL, &m_pBuffMat[TYPE_PLAYER3][PARTS_RHAND], NULL, &m_nNumMat[TYPE_PLAYER3][PARTS_RHAND], &m_pMesh[TYPE_PLAYER3][PARTS_RHAND]);
    //D3DXLoadMeshFromX(LPCSTR("./data/MODEL/player3/04_armL.x"), D3DXMESH_SYSTEMMEM, pDevice, NULL, &m_pBuffMat[TYPE_PLAYER3][PARTS_LARM], NULL, &m_nNumMat[TYPE_PLAYER3][PARTS_LARM], &m_pMesh[TYPE_PLAYER3][PARTS_LARM]);
    //D3DXLoadMeshFromX(LPCSTR("./data/MODEL/player3/05_handL.x"), D3DXMESH_SYSTEMMEM, pDevice, NULL, &m_pBuffMat[TYPE_PLAYER3][PARTS_LHAND], NULL, &m_nNumMat[TYPE_PLAYER3][PARTS_LHAND], &m_pMesh[TYPE_PLAYER3][PARTS_LHAND]);
    //D3DXLoadMeshFromX(LPCSTR("./data/MODEL/player3/06_legR.x"), D3DXMESH_SYSTEMMEM, pDevice, NULL, &m_pBuffMat[TYPE_PLAYER3][PARTS_RLEG], NULL, &m_nNumMat[TYPE_PLAYER3][PARTS_RLEG], &m_pMesh[TYPE_PLAYER3][PARTS_RLEG]);
    //D3DXLoadMeshFromX(LPCSTR("./data/MODEL/player3/07_footR.x"), D3DXMESH_SYSTEMMEM, pDevice, NULL, &m_pBuffMat[TYPE_PLAYER3][PARTS_RFOOT], NULL, &m_nNumMat[TYPE_PLAYER3][PARTS_RFOOT], &m_pMesh[TYPE_PLAYER3][PARTS_RFOOT]);
    //D3DXLoadMeshFromX(LPCSTR("./data/MODEL/player3/08_legL.x"), D3DXMESH_SYSTEMMEM, pDevice, NULL, &m_pBuffMat[TYPE_PLAYER3][PARTS_LLEG], NULL, &m_nNumMat[TYPE_PLAYER3][PARTS_LLEG], &m_pMesh[TYPE_PLAYER3][PARTS_LLEG]);
    //D3DXLoadMeshFromX(LPCSTR("./data/MODEL/player3/09_footL.x"), D3DXMESH_SYSTEMMEM, pDevice, NULL, &m_pBuffMat[TYPE_PLAYER3][PARTS_LFOOT], NULL, &m_nNumMat[TYPE_PLAYER3][PARTS_LFOOT], &m_pMesh[TYPE_PLAYER3][PARTS_LFOOT]);

    //// �v���C���[4
    //D3DXLoadMeshFromX(LPCSTR("./data/MODEL/player4/00_body.x"), D3DXMESH_SYSTEMMEM, pDevice, NULL, &m_pBuffMat[TYPE_PLAYER4][PARTS_BODY], NULL, &m_nNumMat[TYPE_PLAYER4][PARTS_BODY], &m_pMesh[TYPE_PLAYER4][PARTS_BODY]);
    //D3DXLoadMeshFromX(LPCSTR("./data/MODEL/player4/01_head.x"), D3DXMESH_SYSTEMMEM, pDevice, NULL, &m_pBuffMat[TYPE_PLAYER4][PARTS_HEAD], NULL, &m_nNumMat[TYPE_PLAYER4][PARTS_HEAD], &m_pMesh[TYPE_PLAYER4][PARTS_HEAD]);
    //D3DXLoadMeshFromX(LPCSTR("./data/MODEL/player4/02_armR.x"), D3DXMESH_SYSTEMMEM, pDevice, NULL, &m_pBuffMat[TYPE_PLAYER4][PARTS_RARM], NULL, &m_nNumMat[TYPE_PLAYER4][PARTS_RARM], &m_pMesh[TYPE_PLAYER4][PARTS_RARM]);
    //D3DXLoadMeshFromX(LPCSTR("./data/MODEL/player4/03_handR.x"), D3DXMESH_SYSTEMMEM, pDevice, NULL, &m_pBuffMat[TYPE_PLAYER4][PARTS_RHAND], NULL, &m_nNumMat[TYPE_PLAYER4][PARTS_RHAND], &m_pMesh[TYPE_PLAYER4][PARTS_RHAND]);
    //D3DXLoadMeshFromX(LPCSTR("./data/MODEL/player4/04_armL.x"), D3DXMESH_SYSTEMMEM, pDevice, NULL, &m_pBuffMat[TYPE_PLAYER4][PARTS_LARM], NULL, &m_nNumMat[TYPE_PLAYER4][PARTS_LARM], &m_pMesh[TYPE_PLAYER4][PARTS_LARM]);
    //D3DXLoadMeshFromX(LPCSTR("./data/MODEL/player4/05_handL.x"), D3DXMESH_SYSTEMMEM, pDevice, NULL, &m_pBuffMat[TYPE_PLAYER4][PARTS_LHAND], NULL, &m_nNumMat[TYPE_PLAYER4][PARTS_LHAND], &m_pMesh[TYPE_PLAYER4][PARTS_LHAND]);
    //D3DXLoadMeshFromX(LPCSTR("./data/MODEL/player4/06_legR.x"), D3DXMESH_SYSTEMMEM, pDevice, NULL, &m_pBuffMat[TYPE_PLAYER4][PARTS_RLEG], NULL, &m_nNumMat[TYPE_PLAYER4][PARTS_RLEG], &m_pMesh[TYPE_PLAYER4][PARTS_RLEG]);
    //D3DXLoadMeshFromX(LPCSTR("./data/MODEL/player4/07_footR.x"), D3DXMESH_SYSTEMMEM, pDevice, NULL, &m_pBuffMat[TYPE_PLAYER4][PARTS_RFOOT], NULL, &m_nNumMat[TYPE_PLAYER4][PARTS_RFOOT], &m_pMesh[TYPE_PLAYER4][PARTS_RFOOT]);
    //D3DXLoadMeshFromX(LPCSTR("./data/MODEL/player4/08_legL.x"), D3DXMESH_SYSTEMMEM, pDevice, NULL, &m_pBuffMat[TYPE_PLAYER4][PARTS_LLEG], NULL, &m_nNumMat[TYPE_PLAYER4][PARTS_LLEG], &m_pMesh[TYPE_PLAYER4][PARTS_LLEG]);
    //D3DXLoadMeshFromX(LPCSTR("./data/MODEL/player4/09_footL.x"), D3DXMESH_SYSTEMMEM, pDevice, NULL, &m_pBuffMat[TYPE_PLAYER4][PARTS_LFOOT], NULL, &m_nNumMat[TYPE_PLAYER4][PARTS_LFOOT], &m_pMesh[TYPE_PLAYER4][PARTS_LFOOT]);

    return S_OK;
}

//=============================================================================
// ���f���f�[�^�i���W,�e�q�֌W�j�ǂݍ��ݏ���
//=============================================================================
HRESULT CCharacter::LoadModelData(void)
{
    // �t�@�C���|�C���g
    FILE *pFile;

    // �ϐ��錾
    int  nCntLoad = 0;
    char cReedText[128];	// �����Ƃ��ēǂݎ��p
    char cHeadText[256];	//
    char cDie[128];
    D3DXVECTOR3 pos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
    D3DXVECTOR3 rot = D3DXVECTOR3(0.0f, 0.0f, 0.0f);

    // �t�@�C���J
    pFile = fopen("./data/MODEL/motion_weapon.txt", "r");

    // �J����
    if (pFile != NULL)
    {
        while (strcmp(cHeadText, "CHARACTERSET") != 0)
        {
            fgets(cReedText, sizeof(cReedText), pFile);
            sscanf(cReedText, "%s", &cHeadText);
        }

        if (strcmp(cHeadText, "CHARACTERSET") == 0)
        {
            while (strcmp(cHeadText, "END_CHARACTERSET") != 0)
            {

                fgets(cReedText, sizeof(cReedText), pFile);
                sscanf(cReedText, "%s", &cHeadText);

                if (strcmp(cHeadText, "\n") == 0)
                {
                }
                else if (strcmp(cHeadText, "PARTSSET") == 0)
                {
                    while (strcmp(cHeadText, "END_PARTSSET") != 0)
                    {

                        fgets(cReedText, sizeof(cReedText), pFile);
                        sscanf(cReedText, "%s", &cHeadText);

                        if (strcmp(cHeadText, "INDEX") == 0)
                        {
                            int nNum;
                            sscanf(cReedText, "%s %s %d", &cDie, &cDie, &nNum);
                        }

                        if (strcmp(cHeadText, "PARENT") == 0)
                        {
                            sscanf(cReedText, "%s %s %d", &cDie, &cDie, &m_nIndexParent[nCntLoad]);
                        }

                        if (strcmp(cHeadText, "POS") == 0)
                        {
                            sscanf(cReedText, "%s %s %f %f %f", &cDie, &cDie, &pos.x, &pos.y, &pos.z);

                            m_apModel[nCntLoad]->SetPos(pos);
                            m_posDefault[nCntLoad] = pos;
                        }

                        if (strcmp(cHeadText, "ROT") == 0)
                        {
                            //sscanf(cReedText, "%s %s %f %f %f", &cDie, &cDie, &rot.x, rot.y, &rot.z);

                            m_apModel[nCntLoad]->SetRot(rot);
                        }
                    }
                    nCntLoad++;
                }
            }
        }
        // �t�@�C����
        fclose(pFile);
    }

    // �J���Ȃ�
    else
    {
        printf("�J����܂���ł���\n");
    }
    return E_NOTIMPL;
}

//=============================================================================
// �R���X�g���N�^
//=============================================================================
void CCharacter::Unload(void)
{
    for (int nCountType = 0; nCountType < TYPE_MAX; nCountType++)
    {
        for (int nCount = 0; nCount < PARTS_MAX; nCount++)
        {
            if (m_pBuffMat[nCountType][nCount] != NULL)
            {
                m_pBuffMat[nCountType][nCount] = NULL;
            }

            if (m_nNumMat[nCountType][nCount] != NULL)
            {
                m_nNumMat[nCountType][nCount] = NULL;
            }

            if (m_pMesh[nCountType][nCount] != NULL)
            {
                m_pMesh[nCountType][nCount] = NULL;
            }
        }
    }
}

//=============================================================================
// �C���X�^���X��������
//=============================================================================
CCharacter * CCharacter::Create(D3DXVECTOR3 pos, D3DXVECTOR3 rot, TYPE type)
{
    CCharacter *pCharacter = NULL;
    pCharacter = new CCharacter;
    pCharacter->m_rot = rot;
    pCharacter->m_type = type;
    pCharacter->Init(pos, D3DXVECTOR3(1.0f, 1.0f, 1.0f), rot);
    return pCharacter;
}

void CCharacter::Move(void)
{
    //// �R���g���[�����擾
    //CInputJoypad *pInputJoypad = CManager::GetInputJoypad();
    //DIJOYSTATE2 Controller = pInputJoypad->GetController(PLAYER_1);

    //// �ʒu�ƌ������擾
    //D3DXVECTOR3 pos = DEFAULT_VECTOR;
    //D3DXVECTOR3 rot = DEFAULT_VECTOR;
    //pos = GetPos();
    //rot = GetRot();

    //// �v���C���[�������Ă��Ȃ��Ƃ�
    //D3DXVECTOR3 lengthCheckVec = DEFAULT_VECTOR;
    //lengthCheckVec.y = 0;
    //if (D3DXVec3Length(&lengthCheckVec) <= 1.5f)
    //{
    //    GetAnimation()->SetAnimation(CAnimation::ANIM_IDLE);//���[�V������ҋ@�ɂ���
    //}

    //if (Controller.lY != 0 || Controller.lX != 0)
    //{// �X�e�B�b�N���|��Ă���Ȃ�ړ�

    //    float fAngle = atan2(Controller.lX, Controller.lY*-1);//�X�e�B�b�N�̊p�x�����߂�
    //    float fPlayer1Angle = atan2(Controller.lX*-1, Controller.lY);//�X�e�B�b�N�̊p�x�����߂�

    //    pos.x += sinf(fAngle)*PLAYER_SPEED;
    //    pos.z += cosf(fAngle)*PLAYER_SPEED;
    //    GetAnimation()->SetAnimation(CAnimation::ANIM_MOVE);//���[�V����������ɂ���

    //                                                                                //�L�����̌�����ς���
    //    rot.y = fPlayer1Angle;
    //}

    //// �ʒu�ƌ����𔽉f
    //m_pos = pos;
    //m_rot = rot;
}

//=============================================================================
// �u���b�N�Ƃ̓����蔻��
//=============================================================================
void CCharacter::CollisionBlock(D3DXVECTOR3 pos, D3DXVECTOR3 posOld)
{
    //// �u���b�N�Ƃ̓����蔻��
    //for (int nCntScene = 0; nCntScene < MAX_OBJECT; nCntScene++)
    //{
    //    // �V�[�����擾
    //    CScene *pScene = GetScene(nCntScene);

    //    // ���g������Ȃ�
    //    if (pScene != NULL)
    //    {
    //        // �^�C�v���擾
    //        OBJTYPE objType = pScene->GetObjType();

    //        // �u���b�N�Ȃ�A
    //        if (objType == CScene::OBJTYPE_BLOCK)
    //        {
    //            // �V�[��3D�ɃL���X�g
    //            CScene3D *pScene3D = (CScene3D*)pScene;

    //            // �L�����N�^�[�̓����蔻��̃T�C�Y��ݒ�
    //            D3DXVECTOR3 playerCollisionSize = PLAYER_COLLISION_SIZE;
    //            D3DXVECTOR3 blockCollisionSize = BLOCK_COLLISION_SIZE;

    //            // �����蔻����v�Z
    //            SetPos(BlockCollision3D(&pos, &posOld, &pScene3D->GetPos(),
    //                &playerCollisionSize, &blockCollisionSize));
    //        }
    //    }
    //}
}
