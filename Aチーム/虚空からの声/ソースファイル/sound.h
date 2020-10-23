//====================================================================
//
// �T�E���h���� (sound.h)
// Author : �㓡�T�V��
//
//====================================================================
#ifndef _SOUND_H_
#define _SOUND_H_

//================================================
// �C���N���[�h�t�@�C��
//================================================
#include "main.h"

//================================================
// �N���X�錾
//================================================

// �T�E���h�̃N���X
class CSound
{
public:
    typedef enum
    {
        LABEL_BGM_TITLE = 0,	    // BGM �^�C�g��
        LABEL_BGM_GAME,             // BGM �Q�[��
        LABEL_SE_000,               // SE �^�C�g����ʌ��艹
        LABEL_SE_001,               // SE �}�b�`���O��
        LABEL_SE_002,               // SE �a����
        LABEL_SE_003,               // SE �a����
        LABEL_SE_004,               // SE ���S�h�䉹
        LABEL_SE_005,               // SE ����(���[�v)
        LABEL_SE_006,               // SE �S���O1��
        LABEL_SE_007,               // SE �S���O����
        LABEL_SE_008,               // SE �J�[�h���艹
        LABEL_MAX,
    } LABEL;
    CSound();
    ~CSound();  // �e�N���X�̃f�X�g���N�^��virtual�����邱�ƂŁA���������[�N��}����
    HRESULT Init(HWND hWnd);
    void Uninit(void);
    HRESULT Play(LABEL label);
    void Stop(LABEL label);
    void StopAll(void);

private:
    typedef struct
    {
        char *pFilename;	// �t�@�C����
        int nCntLoop;		// ���[�v�J�E���g (-1�Ń��[�v�A0�Ń��[�v�Ȃ�)
    }PARAM;
    HRESULT CheckChunk(HANDLE hFile, DWORD format, DWORD *pChunkSize, DWORD *pChunkDataPosition);
    HRESULT ReadChunkData(HANDLE hFile, void *pBuffer, DWORD dwBuffersize, DWORD dwBufferoffset);

    IXAudio2 *m_pXAudio2;								// XAudio2�I�u�W�F�N�g�ւ̃C���^�[�t�F�C�X
    IXAudio2MasteringVoice *m_pMasteringVoice;			// �}�X�^�[�{�C�X
    IXAudio2SourceVoice *m_apSourceVoice[LABEL_MAX];	// �\�[�X�{�C�X
    BYTE *m_apDataAudio[LABEL_MAX];					    // �I�[�f�B�I�f�[�^
    DWORD m_aSizeAudio[LABEL_MAX];					    // �I�[�f�B�I�f�[�^�T�C�Y
    static PARAM m_aParam[LABEL_MAX];                   // �e���f�ނ̃p�����[�^
};

#endif