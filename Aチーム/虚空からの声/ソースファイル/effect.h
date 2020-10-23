//====================================================================
//
// エフェクトの処理 (effect.h)
// Author : 後藤慎之助
//
//====================================================================
#ifndef _EFFECT_H_
#define _EFFECT_H_

//================================================
// インクルードファイル
//================================================
#include "main.h"
#include "scene2d.h"

//================================================
// マクロ定義
//================================================

//================================================
// クラス宣言
//================================================

// エフェクトクラス
class CEffect : public CScene2D
{
public:
    // エフェクトの種類
    typedef enum
    {
        TYPE_COVID = 0,	    // コロナ
        TYPE_MAX			// 種類の最大数
    }TYPE;
    CEffect();
    ~CEffect();
    HRESULT Init(D3DXVECTOR3 pos, D3DXVECTOR3 size, D3DXVECTOR3 rot);
    void Uninit(void);
    void Update(void);
    void Draw(void);
    static HRESULT Load(void);
    static void Unload(void);
    static CEffect *Create(D3DXVECTOR3 pos, D3DXVECTOR3 size, D3DXVECTOR3 move, float fAngle, float fRotSpeed, D3DXCOLOR col, TYPE type);

private:
    static LPDIRECT3DTEXTURE9 m_apTexture[TYPE_MAX];   // 読み込んだテクスチャを保存する
    D3DXVECTOR3 m_move; // 移動量
    D3DXCOLOR m_col;    // 色
    int m_nLife;        // ライフ
    TYPE m_type;        // エフェクトの種類

    bool m_bAlphaDown;  // 透明度を下げるフラグ

    float m_fRotSpeed;  // 回転速度
    float m_fAngle;     // 角度
};

#endif