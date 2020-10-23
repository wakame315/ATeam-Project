//=============================================================================
//
//タイトル :ナンバーのクラス[number.h]
//Author:伊藤大輝
//
//=============================================================================
#ifndef _NUMBER_H_
#define _NUMBER_H_

#define _CRT_SECURE_NO_WARNINGS_

//=============================================================================
//インクルードファイル
//=============================================================================
#include"main.h"

//=============================================================================
//マクロ定義
//=============================================================================
#define NUMBER_SIZE_X 40  //スコアの縦のサイズ
#define NUMBER_SIZE_Y 50   //スコアの横のサイズ

//=============================================================================
//クラス定義
//=============================================================================
class CNumber
{
public:

    CNumber();  //コンストラクタ
    ~CNumber(); //デストラクタ

                //=========================================
                //メソッド
                //=========================================
    static CNumber *Create(D3DXVECTOR3 pos, int nSizeX, int nSizeY);
    HRESULT Init(D3DXVECTOR3 pos, int nSizeX, int nSizeY);          //初期化処理
    void Update(void);                                              //更新処理
    void Uninit(void);                                              //終了処理
    void Draw(void);                                                //描画処理

    void SetColor(float fColorR, float fColorG, float fColorB, float fColorA);
    void SetNumber(int nNumber);  //ナンバーのセット
    static HRESULT  Load(void);
    static void     Unload(void);

private:
    static LPDIRECT3DTEXTURE9	m_pTexture;   // テクスチャへのポインタ
    LPDIRECT3DVERTEXBUFFER9     m_pVtxBuff;   // バッファへのポインタ
    D3DXVECTOR3                 m_pos;        // 位置
    int                         m_nSizeX;     // サイズ
    int                         m_nSizeY;     // サイズ
};
#endif