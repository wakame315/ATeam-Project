//====================================================================
//
// キャラクターの処理 (character.h)
// Author : 樋宮匠
//
//====================================================================
#ifndef _CHARACTER_H_
#define _CHARACTER_H_

//================================================
// インクルードファイル
//================================================
#include "main.h"
#include "scene.h"
#include "model.h"

//================================================
// マクロ定義
//================================================
#define PLAYER_COLLISION_SIZE D3DXVECTOR3(51.0f, 200.0f, 51.0f)
#define BLOCK_COLLISION_SIZE D3DXVECTOR3(100.0f, 100.0f, 100.0f)

//================================================
// クラス宣言
//================================================
class CAnimation;

// キャラクタークラス
class CCharacter : public CScene
{
public:
    CCharacter();
    ~CCharacter();

    //種類
    typedef enum
    {
        TYPE_PLAYER1 = 0,	    // プレイヤー1
        TYPE_PLAYER2,           // プレイヤー2
        TYPE_PLAYER3,           // プレイヤー3
        TYPE_PLAYER4,           // プレイヤー4
        TYPE_MAX			    // 種類の最大数
    }TYPE;

    // 列挙型宣言（親→子→孫の順で宣言）
    typedef enum
    {
        PARTS_BODY = 0,
        PARTS_HEAD,
        PARTS_RARM,
        PARTS_RHAND,
        PARTS_LARM,
        PARTS_LHAND,
        PARTS_RLEG,
        PARTS_RFOOT,
        PARTS_LLEG,
        PARTS_LFOOT,
        //PARTS_WEAPON,
        //PARTS_SHIELD,
        PARTS_MAX,
    }PARTS;

    HRESULT Init(D3DXVECTOR3 pos, D3DXVECTOR3 size, D3DXVECTOR3 rot);
    void Uninit(void);
    void Update(void);
    void Draw(void);
    static HRESULT Load(void);
    HRESULT LoadModelData(void);
    static void Unload(void);
    static CCharacter *Create(D3DXVECTOR3 pos, D3DXVECTOR3 rot, TYPE type);
    static D3DXVECTOR3 GetDefaultPos(int index) { return m_posDefault[index]; }
    D3DXVECTOR3 GetPartsRot(int index) { return m_apModel[index]->GetRot(); }
    CModel * GetParts(int index) { return m_apModel[index]; }
    void SetPartPos(int index, D3DXVECTOR3 pos) { m_apModel[index]->SetPos(pos); }
    void SetPartRot(int index, D3DXVECTOR3 rot) { m_apModel[index]->SetRot(rot); }
    void SetPos(D3DXVECTOR3 pos) { m_pos = pos; }
    void SetPosOld(D3DXVECTOR3 posOld) { m_posOld = posOld; }
    void SetRot(D3DXVECTOR3 rot) { m_rot = rot; }
    D3DXVECTOR3 GetPos(void) { return m_pos; }
    D3DXVECTOR3 GetPosOld(void) { return m_posOld; }
    D3DXVECTOR3 GetRot(void) { return m_rot; }

    CAnimation * GetAnimation(void) { return m_pAnimation; }

    void Move(void);
    void CollisionBlock(D3DXVECTOR3 pos, D3DXVECTOR3 posOld);

    bool GetUse(void) { return m_bUse; }
    void SetUseFalse(void) { m_bUse = false; }

    int GetWave(void) { return m_nWave; }
    void UseWave(void) { m_nWave--; }

    D3DXVECTOR3 GetMove(void) { return m_move; }
    void SetMove(D3DXVECTOR3 move) { m_move = move; }

private:
    //static LPD3DXMESH		m_pMesh[PARTS_MAX];
    //static LPD3DXBUFFER		m_pBuffMat[PARTS_MAX];
    //static DWORD			m_nNumMat[PARTS_MAX];
    static LPD3DXMESH		m_pMesh[TYPE_MAX][PARTS_MAX];
    static LPD3DXBUFFER		m_pBuffMat[TYPE_MAX][PARTS_MAX];
    static DWORD			m_nNumMat[TYPE_MAX][PARTS_MAX];
    static D3DXVECTOR3		m_posDefault[PARTS_MAX];
    static 	int				m_nIndexParent[PARTS_MAX];
    D3DXMATRIX		m_mtxWorld;
    D3DXVECTOR3		m_pos;
    D3DXVECTOR3		m_posOld;
    D3DXVECTOR3		m_move;
    D3DXVECTOR3		m_rot;
    TYPE            m_type;

    CModel			*m_apModel[PARTS_MAX];
    CAnimation		*m_pAnimation;

    int m_nWave;
    bool m_bUse;
};

#endif