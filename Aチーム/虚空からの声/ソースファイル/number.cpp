//========================================================
//
//           numberのクラス[number.cpp]
//           Author:伊藤大輝
//
//========================================================

//========================================================
//インクルードファイル
//========================================================
#include "number.h"
#include "manager.h"
#include "renderer.h"

//========================================================
//静的メンバ変数の初期化
//========================================================
LPDIRECT3DTEXTURE9 CNumber::m_pTexture = NULL;

//========================================================
//コンストラクタ
//========================================================
CNumber::CNumber(void)
{
    m_pVtxBuff = NULL;
    m_pos = D3DXVECTOR3(0, 0, 0);
    m_nSizeX = 0;
    m_nSizeY = 0;
}

//========================================================
//デストラクタ
//========================================================
CNumber::~CNumber(void)
{

}

//========================================================
//メモリ生成
//========================================================
CNumber *CNumber::Create(D3DXVECTOR3 pos, int nSizeX, int nSizeY)
{
    //変数宣言
    CNumber *pNumber;

    //メモリ生成
    pNumber = new CNumber;

    //初期化処理
    pNumber->Init(pos, nSizeX, nSizeY);

    return pNumber;
}

//========================================================
//初期化
//========================================================
HRESULT CNumber::Init(D3DXVECTOR3 pos, int nSizeX, int nSizeY)
{
    //デバイスの取得
    CRenderer *pRenderer = CManager::GetRenderer();
    LPDIRECT3DDEVICE9 pD3DDevice = pRenderer->GetDevice();

    // ポリゴンの位置を設定
    m_pos = pos;

    //ポリゴンのサイズを設定
    m_nSizeX = nSizeX;
    m_nSizeY = nSizeY;

    // 頂点バッファの生成
    pD3DDevice->CreateVertexBuffer(sizeof(VERTEX_2D) * NUM_VERTEX, D3DUSAGE_WRITEONLY, FVF_VERTEX_2D, D3DPOOL_MANAGED, &m_pVtxBuff, NULL);

    //頂点情報へのポインタ
    VERTEX_2D *pVtx;

    //頂点データの範囲をロックし頂点バッファへのポインタ取得
    m_pVtxBuff->Lock(0, 0, (void**)&pVtx, 0);

    // 頂点情報を設定
    pVtx[0].pos = D3DXVECTOR3(m_pos.x - (m_nSizeX / 2), m_pos.y - (m_nSizeY / 2), 0);
    pVtx[1].pos = D3DXVECTOR3(m_pos.x + (m_nSizeX / 2), m_pos.y - (m_nSizeY / 2), 0);
    pVtx[2].pos = D3DXVECTOR3(m_pos.x - (m_nSizeX / 2), m_pos.y + (m_nSizeY / 2), 0);
    pVtx[3].pos = D3DXVECTOR3(m_pos.x + (m_nSizeX / 2), m_pos.y + (m_nSizeY / 2), 0);

    //テクスチャ座標の設定
    pVtx[0].tex = D3DXVECTOR2(0.0f, 0.0f);
    pVtx[1].tex = D3DXVECTOR2(0.1f, 0.0f);
    pVtx[2].tex = D3DXVECTOR2(0.0f, 1.0f);
    pVtx[3].tex = D3DXVECTOR2(0.1f, 1.0f);

    //rhwの設定
    pVtx[0].rhw = 1.0f;
    pVtx[1].rhw = 1.0f;
    pVtx[2].rhw = 1.0f;
    pVtx[3].rhw = 1.0f;

    //頂点カラーの設定(0～255の数値で設定)
    pVtx[0].col = D3DXCOLOR(255, 255, 255, 255);
    pVtx[1].col = D3DXCOLOR(255, 255, 255, 255);
    pVtx[2].col = D3DXCOLOR(255, 255, 255, 255);
    pVtx[3].col = D3DXCOLOR(255, 255, 255, 255);

    //頂点データをアンロック
    m_pVtxBuff->Unlock();
    return S_OK;
}

//========================================================
//終了処理
//========================================================
void CNumber::Uninit(void)
{
    // 頂点バッファの破棄
    if (m_pVtxBuff != NULL)
    {
        m_pVtxBuff->Release();
        m_pVtxBuff = NULL;
    }

}

//========================================================
//更新処理
//========================================================
void CNumber::Update(void)
{

}

//========================================================
//描画処理
//========================================================
void CNumber::Draw(void)
{
    //デバイスの取得
    CRenderer *pRenderer = CManager::GetRenderer();
    LPDIRECT3DDEVICE9 pD3DDevice = pRenderer->GetDevice();

    // 頂点バッファをデータストリームに設定
    pD3DDevice->SetStreamSource(0, m_pVtxBuff, 0, sizeof(VERTEX_2D));

    // 頂点フォーマットの設定
    pD3DDevice->SetFVF(FVF_VERTEX_2D);

    // テクスチャの設定
    pD3DDevice->SetTexture(0, m_pTexture);

    // ポリゴンの描画
    pD3DDevice->DrawPrimitive(D3DPT_TRIANGLESTRIP, 0, NUM_POLYGON);
}

//========================================================
//テクスチャ読み込み
//========================================================
HRESULT CNumber::Load(void)
{
    //デバイスの取得
    CRenderer *pRenderer = CManager::GetRenderer();
    LPDIRECT3DDEVICE9 pD3DDevice = pRenderer->GetDevice();

    // テクスチャの生成
    D3DXCreateTextureFromFile(pD3DDevice, "data/TEXTURE/number000.png", &m_pTexture);

    return S_OK;
}

//========================================================
//テクスチャの破棄
//========================================================
void CNumber::Unload(void)
{
    // テクスチャの破棄
    if (m_pTexture != NULL)
    {
        m_pTexture->Release();
        m_pTexture = NULL;
    }
}

//========================================================
//ナンバーをセット
//========================================================
void CNumber::SetNumber(int nNumber)
{
    //頂点情報へのポインタ
    VERTEX_2D *pVtx;

    //頂点データの範囲をロックし頂点バッファへのポインタ取得
    m_pVtxBuff->Lock(0, 0, (void**)&pVtx, 0);

    //テクスチャ座標の設定
    pVtx[0].tex = D3DXVECTOR2((float)nNumber / 10, 0.0f);
    pVtx[1].tex = D3DXVECTOR2((float)(nNumber + 1) / 10, 0.0f);
    pVtx[2].tex = D3DXVECTOR2((float)nNumber / 10, 1.0f);
    pVtx[3].tex = D3DXVECTOR2((float)(nNumber + 1) / 10, 1.0f);

    //頂点データをアンロック
    m_pVtxBuff->Unlock();

}

//========================================================
//ナンバーをセット
//========================================================
void CNumber::SetColor(float fColorR, float fColorG, float fColorB, float fColorA)
{
    //頂点情報へのポインタ
    VERTEX_2D *pVtx;

    //頂点データの範囲をロックし頂点バッファへのポインタ取得
    m_pVtxBuff->Lock(0, 0, (void**)&pVtx, 0);

    //テクスチャ座標の設定
    pVtx[0].col = D3DXCOLOR(fColorR, fColorG, fColorB, fColorA);
    pVtx[1].col = D3DXCOLOR(fColorR, fColorG, fColorB, fColorA);
    pVtx[2].col = D3DXCOLOR(fColorR, fColorG, fColorB, fColorA);
    pVtx[3].col = D3DXCOLOR(fColorR, fColorG, fColorB, fColorA);

    //頂点データをアンロック
    m_pVtxBuff->Unlock();

}