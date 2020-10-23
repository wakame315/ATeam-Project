//=============================================================================
//
//�^�C�g�� :�i���o�[�̃N���X[number.h]
//Author:�ɓ���P
//
//=============================================================================
#ifndef _NUMBER_H_
#define _NUMBER_H_

#define _CRT_SECURE_NO_WARNINGS_

//=============================================================================
//�C���N���[�h�t�@�C��
//=============================================================================
#include"main.h"

//=============================================================================
//�}�N����`
//=============================================================================
#define NUMBER_SIZE_X 40  //�X�R�A�̏c�̃T�C�Y
#define NUMBER_SIZE_Y 50   //�X�R�A�̉��̃T�C�Y

//=============================================================================
//�N���X��`
//=============================================================================
class CNumber
{
public:

    CNumber();  //�R���X�g���N�^
    ~CNumber(); //�f�X�g���N�^

                //=========================================
                //���\�b�h
                //=========================================
    static CNumber *Create(D3DXVECTOR3 pos, int nSizeX, int nSizeY);
    HRESULT Init(D3DXVECTOR3 pos, int nSizeX, int nSizeY);          //����������
    void Update(void);                                              //�X�V����
    void Uninit(void);                                              //�I������
    void Draw(void);                                                //�`�揈��

    void SetColor(float fColorR, float fColorG, float fColorB, float fColorA);
    void SetNumber(int nNumber);  //�i���o�[�̃Z�b�g
    static HRESULT  Load(void);
    static void     Unload(void);

private:
    static LPDIRECT3DTEXTURE9	m_pTexture;   // �e�N�X�`���ւ̃|�C���^
    LPDIRECT3DVERTEXBUFFER9     m_pVtxBuff;   // �o�b�t�@�ւ̃|�C���^
    D3DXVECTOR3                 m_pos;        // �ʒu
    int                         m_nSizeX;     // �T�C�Y
    int                         m_nSizeY;     // �T�C�Y
};
#endif