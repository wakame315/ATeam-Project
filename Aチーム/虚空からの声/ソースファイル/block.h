//====================================================================
//
// ブロックの処理 (character.h)
// Author : 樋宮匠
//
//====================================================================
#ifndef _BLOCK_H_
#define _BLOCK_H_

//================================================
// インクルードファイル
//================================================
#include "main.h"
#include "scene3d.h"

//========================================
// マクロ定義
//========================================
#define BLOCK_BUILDING_COLLISION_SIZE D3DXVECTOR3(625.0f, 1650.0f, 625.0f)   // ビルの当たり判定の大きさ
#define BLOCK_SIGNAL_COLLISION_SIZE D3DXVECTOR3(80.0f, 1100.0f, 80.0f)       // 信号の当たり判定の大きさ
#define BLOCK_LIGHT_COLLISION_SIZE D3DXVECTOR3(80.0f, 1050.0f, 80.0f)        // 街灯の当たり判定の大きさ
#define BLOCK_DUSTBOX_COLLISION_SIZE D3DXVECTOR3(80.0f, 120.0f, 80.0f)       // ゴミ箱の当たり判定の大きさ

//================================================
// クラス宣言
//================================================

// ブロッククラス
class CBlock : public CScene3D
{
public:

    // ブロックの種類
    typedef enum
    {
        TYPE_BUILDING001,   // ビル1
        TYPE_BUILDING101,   // ビル2
        TYPE_BUILDING201,   // ビル3
        TYPE_BUILDING301,   // ビル4
        TYPE_BUILDING401,   // ビル5
        TYPE_BUILDING501,   // ビル6
        TYPE_SIGNAL,        // 信号機
        TYPE_LIGHT,         // 街灯
        TYPE_DUSTBOX,       // ゴミ箱
        TYPE_MAX            // 種類の最大数
    }TYPE;

    CBlock();
    ~CBlock();
    HRESULT Init(D3DXVECTOR3 pos, D3DXVECTOR3 size, D3DXVECTOR3 rot, int nType);
    void Uninit(void);
    void Update(void);
    void Draw(void);
    static HRESULT Load(void);
    static void Unload(void);
    static CBlock *Create(D3DXVECTOR3 pos, D3DXVECTOR3 rot, int nType);

    D3DXVECTOR3 GetCollisionSize(void) { return m_collisionSize; }          // 衝突の大きさを返す
    bool GetWallRun(void) { return m_bWallRun; }                            // 壁走りできるかどうかを返す

    static CBlock*GetSelectBlock(void) { return m_pSelectBlock; }           // 選択しているブロックを取得
    static void SetSelectBlock(CBlock* pBlock) { m_pSelectBlock = pBlock; } // 選択しているブロックを設定

	int GetType(void) { return m_nType; }
	static int GetBlockNumAll(void) { return m_nNumAll; }

private:
    static LPDIRECT3DTEXTURE9		m_apTexture[TYPE_MAX];  // 読み込むテクスチャ
    static LPD3DXMESH				m_apMesh[TYPE_MAX];     // 読み込むメッシュ
    static LPD3DXBUFFER				m_apBuffMat[TYPE_MAX];  // 読み込むマテリアルのバッファ
    static DWORD					m_aNumMat[TYPE_MAX];    // 読み込むマテリアル数

    static CBlock *m_pSelectBlock;                          // 現在選択しているブロックのポインタ

    D3DXVECTOR3 m_collisionSize;                            // 当たり判定の大きさ
    bool m_bWallRun;                                        // 壁走りできるかどうか
    bool m_bBlink;                                          // 瞬くかどうか
    int m_nCntTime;                                         // 時間を数える
	static int m_nNumAll;                                   // ブロックの総数

    int m_nType;                                            // 種類
};

#endif