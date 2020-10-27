//===============================================
//
// フィールド処理 (field.cpp)
// Author : 樋宮匠
//
//===============================================

//========================
// インクルードファイル
//========================
#include "field.h"
#include "manager.h"
#include "renderer.h"

//========================================
// 静的メンバ変数宣言
//========================================
LPDIRECT3DTEXTURE9 CField::m_pTexture = NULL;
CTile *CField::m_pTile[MAP_WIDTH][MAP_HEIGHT] = {};
int CField::m_aGround[MAP_WIDTH][MAP_HEIGHT] = {};

//=============================================================================
// コンストラクタ
//=============================================================================
CField::CField()
{
}

//=============================================================================
// デストラクタ
//=============================================================================
CField::~CField()
{
}

//=============================================================================
// 初期化処理
//=============================================================================
HRESULT CField::Init(D3DXVECTOR3 pos, D3DXVECTOR3 size)
{
	LoadMapData();

    return S_OK;
}

//=============================================================================
// 終了処理
//=============================================================================
void CField::Uninit(void)
{
	if (m_pTexture != NULL)
	{
		m_pTexture->Release();
		m_pTexture = NULL;
	}
}

//=============================================================================
// 更新処理
//=============================================================================
void CField::Update(void)
{
}

//=============================================================================
// 描画処理
//=============================================================================
void CField::Draw(void)
{
	for (int nCountHeight = 0; nCountHeight < MAP_HEIGHT; nCountHeight++)
	{
		for (int nCountWidth = 0; nCountWidth < MAP_WIDTH; nCountWidth++)
		{
			m_pTile[nCountHeight][nCountWidth]->Draw();
		}
	}
}

//=============================================================================
// モデルデータ読み込み処理
//=============================================================================
void CField::LoadMapData(void)
{
	FILE *pFile = fopen("./data/MAPS/Map_001.csv", "r");;
	int nHeight = 0;
	int nWidth = 0;

	for (int nCountMap = 0; nCountMap < NUM_TILE; nCountMap++)
	{
		if (pFile != NULL)
		{
			while (fscanf(pFile, "%d,", &m_aGround[nHeight][nWidth]) != EOF)
			{
				nWidth++;
				if (nWidth >= MAP_WIDTH)
				{
					nWidth = 0;
					nHeight++;
				}
			}
		}
	}

	fclose(pFile);
}

//=============================================================================
// インスタンス生成処理
//=============================================================================
CField * CField::Create(void)
{
	CField *m_pField;

	m_pField = new CField;
	m_pField->Init(D3DXVECTOR3(0.0f, 0.0f, 0.0f), D3DXVECTOR3(1.0f, 1.0f, 1.0f));
	m_pField->SetField();

	return m_pField;
}

//=============================================================================
// モデルデータ読み込み処理
//=============================================================================
HRESULT CField::Load(void)
{
    LPDIRECT3DDEVICE9 pDevice = CManager::GetRenderer()->GetDevice();

    // テクスチャ
    D3DXCreateTextureFromFile(pDevice, "data/TEXTURE/field000.jpg", &m_pTexture);

    return S_OK;
}

//=============================================================================
// モデルデータ破棄処理
//=============================================================================
void CField::Unload(void)
{
    if (m_pTexture != NULL)
    {
        m_pTexture->Release();
        m_pTexture = NULL;
    }
}

//=============================================================================
// フィールド生成処理
//=============================================================================
void CField::SetField(void)
{
	int nHeight = 0;

	for (int nCountHeight = MAP_HEIGHT - 1; nCountHeight > -1; nCountHeight--)
	{
		for (int nCountWidth = 0; nCountWidth < MAP_WIDTH; nCountWidth++)
		{
			switch (m_aGround[nHeight][nCountWidth])
			{
			case CTile::TILE_BLACK:
				m_pTile[nCountHeight][nCountWidth] = new CTile;
				m_pTile[nCountHeight][nCountWidth]->Init();
				m_pTile[nCountHeight][nCountWidth]->SetPos(D3DXVECTOR3(nCountWidth * TILE_SIZE / 2, 0.0f, nCountHeight * TILE_SIZE / 2));
				m_pTile[nCountHeight][nCountWidth]->SetCol(D3DCOLOR_RGBA(0, 0, 0, 255));
				m_pTile[nCountHeight][nCountWidth]->Update();
				break;
			case CTile::TILE_WHITE:
				m_pTile[nCountHeight][nCountWidth] = new CTile;
				m_pTile[nCountHeight][nCountWidth]->Init();
				m_pTile[nCountHeight][nCountWidth]->SetPos(D3DXVECTOR3(nCountWidth * TILE_SIZE / 2, 0.0f, nCountHeight * TILE_SIZE / 2));
				m_pTile[nCountHeight][nCountWidth]->SetCol(D3DCOLOR_RGBA(255, 255, 255, 255));
				m_pTile[nCountHeight][nCountWidth]->BindTexture(m_pTexture);
				m_pTile[nCountHeight][nCountWidth]->Update();
				break;
			default:
				break;
			}
		}

		nHeight++;
	}
}
