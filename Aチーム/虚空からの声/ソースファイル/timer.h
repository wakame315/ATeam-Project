//=============================================================================
//
//           タイトル :タイマーのクラス[timer.h]
//           Author:伊藤大輝
//
//=============================================================================
#ifndef _TIMER_H_
#define _TIMER_H_

#define _CRT_SECURE_NO_WARNINGS_

//=============================================================================
//インクルードファイル
//=============================================================================
#include"main.h"
#include "scene.h"
#include "number.h"

class CScene;
class CNumber;

//=============================================================================
//マクロ定義
//=============================================================================
// タイマーの位置とサイズ
#define TIMER_POS D3DXVECTOR3(SCREEN_WIDTH / 2,SCREEN_HEIGHT - 45.0f,0.0f)
#define TIMER_SIZE D3DXVECTOR3(NUMBER_SIZE_X,NUMBER_SIZE_Y,0.0f)

#define MAX_SECONDS_DIGIT 2 //タイマーの秒の桁の数
#define MAX_MINUTES_DIGIT 1 //タイマーの分の桁の数

// 秒の時間
#define SECONDS_TIMER 30

// 分の時間
#define MINUTES_TIMER 1

//=============================================================================
//クラス定義
//=============================================================================
class CTimer :public CScene
{
public:

    CTimer();  //コンストラクタ
    ~CTimer(); //デストラクタ

               //=========================================
               //メソッド
               //=========================================
    static CTimer *Create(D3DXVECTOR3 pos, D3DXVECTOR3 size);
    HRESULT Init(D3DXVECTOR3 pos, D3DXVECTOR3 size, D3DXVECTOR3 rot); // 初期化処理
    void Update(void);                               // 更新処理
    void Uninit(void);                               // 終了処理
    void Draw(void);                                 // 描画処理

    static bool GetFinish(void) { return m_bFinish; }

private:
    static bool m_bFinish;
    CNumber *m_apMinutesNumber;
    CNumber *m_apSecondsNumber[MAX_SECONDS_DIGIT];
    int m_nSeconds;  // タイマーの秒のカウンター
    int m_nMinutes;  // タイマーの分のカウンター
    int m_nCntFrame; // フレームをカウント
};
#endif