//===============================================
//
// フィールド処理 (block.cpp)
// Author : 樋宮匠
//
//===============================================

//========================
// インクルードファイル
//========================
#include "block.h"
#include "manager.h"
#include "renderer.h"

//========================================
// 静的メンバ変数宣言
//========================================
LPD3DXMESH	CBlock::m_apMesh[CBlock::TYPE_MAX] = {};
LPD3DXBUFFER CBlock::m_apBuffMat[CBlock::TYPE_MAX] = {};
DWORD CBlock::m_aNumMat[CBlock::TYPE_MAX] = {};
LPDIRECT3DTEXTURE9 CBlock::m_apTexture[CBlock::TYPE_MAX] = {};

CBlock* CBlock::m_pSelectBlock = NULL;
int CBlock::m_nNumAll = 0;

//=============================================================================
// コンストラクタ
//=============================================================================
CBlock::CBlock() :CScene3D(CScene::OBJTYPE_BLOCK)
{
    m_collisionSize = DEFAULT_VECTOR;
    m_nType = TYPE_BUILDING001;
    m_bWallRun = false;

    m_bBlink = false;
    m_nCntTime = 0;

	m_nNumAll++;
}

//=============================================================================
// デストラクタ
//=============================================================================
CBlock::~CBlock()
{
	m_nNumAll--;
}

//=============================================================================
// 初期化処理
//=============================================================================
HRESULT CBlock::Init(D3DXVECTOR3 pos, D3DXVECTOR3 size, D3DXVECTOR3 rot, int nType)
{
    CScene3D::Init(pos, size, rot);

    SetScale(size);

    // メッシュ、テクスチャをバインド
    BindMesh(m_apMesh[m_nType], m_apBuffMat[m_nType], m_aNumMat[m_nType]);
    BindTexture(m_apTexture[m_nType]);

    return S_OK;
}

//=============================================================================
// 終了処理
//=============================================================================
void CBlock::Uninit(void)
{
    CScene3D::Uninit();
}

//=============================================================================
// 更新処理
//=============================================================================
void CBlock::Update(void)
{
    // 0より大きいなら、減らす
    if (m_nCntTime > 0)
    {
        m_nCntTime--;
    }

    // 選択しているブロックを点滅させる
    if (this == m_pSelectBlock)
    {
        if (m_nCntTime == 0)
        {
            m_bBlink = !m_bBlink;

            m_nCntTime = BLINK_TIME;
        }
    }
    else
    {
        m_nCntTime = 0;

        m_bBlink = false;
    }

    CScene3D::Update();
}

//=============================================================================
// 描画処理
//=============================================================================
void CBlock::Draw(void)
{
    LPDIRECT3DDEVICE9 pDevice = CManager::GetRenderer()->GetDevice();

    if (m_bBlink == false)
    {
        CScene3D::Draw();
    }
}

//=============================================================================
// モデルデータ読み込み処理
//=============================================================================
HRESULT CBlock::Load(void)
{
    LPDIRECT3DDEVICE9 pDevice = CManager::GetRenderer()->GetDevice();

    //==============================
    // ビル001
    //==============================
    // モデル
    D3DXLoadMeshFromX(LPCSTR("data/MODEL/building/building001.x"), D3DXMESH_SYSTEMMEM, pDevice, NULL,
        &m_apBuffMat[TYPE_BUILDING001], NULL, &m_aNumMat[TYPE_BUILDING001], &m_apMesh[TYPE_BUILDING001]);
    // テクスチャ
    D3DXCreateTextureFromFile(pDevice, "data/TEXTURE/building001.jpg", &m_apTexture[TYPE_BUILDING001]);

    //==============================
    // ビル101
    //==============================
    // モデル
    D3DXLoadMeshFromX(LPCSTR("data/MODEL/building/building101.x"), D3DXMESH_SYSTEMMEM, pDevice, NULL,
        &m_apBuffMat[TYPE_BUILDING101], NULL, &m_aNumMat[TYPE_BUILDING101], &m_apMesh[TYPE_BUILDING101]);
    // テクスチャ
    D3DXCreateTextureFromFile(pDevice, "data/TEXTURE/building101.jpg", &m_apTexture[TYPE_BUILDING101]);

    //==============================
    // ビル201
    //==============================
    // モデル
    D3DXLoadMeshFromX(LPCSTR("data/MODEL/building/building201.x"), D3DXMESH_SYSTEMMEM, pDevice, NULL,
        &m_apBuffMat[TYPE_BUILDING201], NULL, &m_aNumMat[TYPE_BUILDING201], &m_apMesh[TYPE_BUILDING201]);
    // テクスチャ
    D3DXCreateTextureFromFile(pDevice, "data/TEXTURE/building201.jpg", &m_apTexture[TYPE_BUILDING201]);

    //==============================
    // ビル301
    //==============================
    // モデル
    D3DXLoadMeshFromX(LPCSTR("data/MODEL/building/building301.x"), D3DXMESH_SYSTEMMEM, pDevice, NULL,
        &m_apBuffMat[TYPE_BUILDING301], NULL, &m_aNumMat[TYPE_BUILDING301], &m_apMesh[TYPE_BUILDING301]);
    // テクスチャ
    D3DXCreateTextureFromFile(pDevice, "data/TEXTURE/building301.jpg", &m_apTexture[TYPE_BUILDING301]);

    //==============================
    // ビル401
    //==============================
    // モデル
    D3DXLoadMeshFromX(LPCSTR("data/MODEL/building/building401.x"), D3DXMESH_SYSTEMMEM, pDevice, NULL,
        &m_apBuffMat[TYPE_BUILDING401], NULL, &m_aNumMat[TYPE_BUILDING401], &m_apMesh[TYPE_BUILDING401]);
    // テクスチャ
    D3DXCreateTextureFromFile(pDevice, "data/TEXTURE/building401.jpg", &m_apTexture[TYPE_BUILDING401]);

    //==============================
    // ビル501
    //==============================
    // モデル
    D3DXLoadMeshFromX(LPCSTR("data/MODEL/building/building501.x"), D3DXMESH_SYSTEMMEM, pDevice, NULL,
        &m_apBuffMat[TYPE_BUILDING501], NULL, &m_aNumMat[TYPE_BUILDING501], &m_apMesh[TYPE_BUILDING501]);
    // テクスチャ
    D3DXCreateTextureFromFile(pDevice, "data/TEXTURE/building501.jpg", &m_apTexture[TYPE_BUILDING501]);

    //==============================
    // 信号機
    //==============================
    // モデル
    D3DXLoadMeshFromX(LPCSTR("data/MODEL/Signal.x"), D3DXMESH_SYSTEMMEM, pDevice, NULL,
        &m_apBuffMat[TYPE_SIGNAL], NULL, &m_aNumMat[TYPE_SIGNAL], &m_apMesh[TYPE_SIGNAL]);

    //==============================
    // 街灯
    //==============================
    // モデル
    D3DXLoadMeshFromX(LPCSTR("data/MODEL/light.x"), D3DXMESH_SYSTEMMEM, pDevice, NULL,
        &m_apBuffMat[TYPE_LIGHT], NULL, &m_aNumMat[TYPE_LIGHT], &m_apMesh[TYPE_LIGHT]);

    //==============================
    // ゴミ箱
    //==============================
    // モデル
    D3DXLoadMeshFromX(LPCSTR("data/MODEL/DustBox.x"), D3DXMESH_SYSTEMMEM, pDevice, NULL,
        &m_apBuffMat[TYPE_DUSTBOX], NULL, &m_aNumMat[TYPE_DUSTBOX], &m_apMesh[TYPE_DUSTBOX]);
    return S_OK;
}

//=============================================================================
// モデルデータ破棄処理
//=============================================================================
void CBlock::Unload(void)
{
    for (int nCnt = 0; nCnt < CBlock::TYPE_MAX; nCnt++)
    {
        if (m_apMesh[nCnt] != NULL)
        {
            m_apMesh[nCnt]->Release();
            m_apMesh[nCnt] = NULL;
        }
        if (m_apBuffMat[nCnt] != NULL)
        {
            m_apBuffMat[nCnt]->Release();
            m_apBuffMat[nCnt] = NULL;
        }
        if (m_apTexture[nCnt] != NULL)
        {
            m_apTexture[nCnt]->Release();
            m_apTexture[nCnt] = NULL;
        }
    }
}

//=============================================================================
// インスタンス生成処理
//=============================================================================
CBlock * CBlock::Create(D3DXVECTOR3 pos, D3DXVECTOR3 rot, int nType)
{
    CBlock *pBlock = NULL;
	pBlock = new CBlock;
    pBlock->m_nType = nType;
    pBlock->Init(pos, D3DXVECTOR3(1.0f, 1.0f, 1.0f), rot, nType);

    // 種類ごとに、結びつける値を変える
    switch (nType)
    {
    case TYPE_BUILDING001:

        pBlock->m_collisionSize = BLOCK_BUILDING_COLLISION_SIZE;
        pBlock->m_bWallRun = true;

        break;

    case TYPE_BUILDING101:

        pBlock->m_collisionSize = BLOCK_BUILDING_COLLISION_SIZE;
        pBlock->m_bWallRun = true;

        break;

    case TYPE_BUILDING201:

        pBlock->m_collisionSize = BLOCK_BUILDING_COLLISION_SIZE;
        pBlock->m_bWallRun = true;

        break;

    case TYPE_BUILDING301:

        pBlock->m_collisionSize = BLOCK_BUILDING_COLLISION_SIZE;
        pBlock->m_bWallRun = true;

        break;

    case TYPE_BUILDING401:

        pBlock->m_collisionSize = BLOCK_BUILDING_COLLISION_SIZE;
        pBlock->m_bWallRun = true;

        break;

    case TYPE_BUILDING501:

        pBlock->m_collisionSize = BLOCK_BUILDING_COLLISION_SIZE;
        pBlock->m_bWallRun = true;

        break;

    case TYPE_SIGNAL:

        pBlock->m_collisionSize = BLOCK_SIGNAL_COLLISION_SIZE;
        pBlock->m_bWallRun = true;

        break;

    case TYPE_LIGHT:

        pBlock->m_collisionSize = BLOCK_LIGHT_COLLISION_SIZE;
        pBlock->m_bWallRun = true;

        break;

    case TYPE_DUSTBOX:

        pBlock->m_collisionSize = BLOCK_DUSTBOX_COLLISION_SIZE;

        break;
    }

    return pBlock;
}
