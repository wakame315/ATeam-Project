//====================================================================
//
// フィールドの処理 (character.h)
// Author : 樋宮匠
//
//====================================================================
#ifndef _FIELD_H_
#define _FIELD_H_

//================================================
// インクルードファイル
//================================================
#include "main.h"
#include "scene.h"
#include "tile.h"

//================================================
// マクロ定義
//================================================

#define FIELD_POS (D3DXVECTOR3(2000.0f, 0.0f, 4800.0f))  // フィールドの位置
#define FIELD_SCALE (D3DXVECTOR3(100.0f, 1.0f, 100.0f))  // フィールドのスケール

#define MAP_WIDTH	50	// マップの幅
#define MAP_HEIGHT	50	// マップの奥行

#define NUM_TILE	(MAP_WIDTH * MAP_HEIGHT)

//================================================
// クラス宣言
//================================================

// フィールドクラス
class CField : public CScene
{
public:
    CField();
    ~CField();

    HRESULT Init(D3DXVECTOR3 pos, D3DXVECTOR3 size);
    void Uninit(void);
	void Update(void);
	void Draw(void);

	void LoadMapData(void);

	static CField *Create(void);

    static HRESULT Load(void);
    static void Unload(void);

	static void SetField(void);
private:
    static LPDIRECT3DTEXTURE9		m_pTexture;
	static CTile					*m_pTile[MAP_WIDTH][MAP_HEIGHT];
	static int						m_aGround[MAP_WIDTH][MAP_HEIGHT];
};

#endif