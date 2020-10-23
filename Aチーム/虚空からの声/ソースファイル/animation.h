//====================================================================
//
// �A�j���[�V�������� (animation.h)
// Author : ��{��
//
//====================================================================
#ifndef _ANIMATION_H_
#define _ANIMATION_H_

//================================================
// �C���N���[�h�t�@�C��
//================================================
#include "main.h"
#include "character.h"

//*****************************************************************************
// �}�N����`
//*****************************************************************************
#define KEY_MAX 10

//================================================
// �N���X�錾
//================================================

//�A�j���[�V�����N���X
class CAnimation
{
public:
    CAnimation();
    ~CAnimation();

    //�񋓌^�錾
    typedef enum
    {
        ANIM_IDLE = 0,  // �ҋ@
        ANIM_MOVE,      // �ړ�
        ANIM_REGRET,    // ��������
        ANIM_PLEASURE,  // ���
        ANIM_ATTACK,    // �U��
        ANIM_MAX,
    }ANIMATION;

    // �\���̐錾
    typedef struct
    {
        D3DXVECTOR3 pos[KEY_MAX];
        D3DXVECTOR3 rot[KEY_MAX];
    }PARTS_INFO;

    typedef struct
    {
        PARTS_INFO  parts[CCharacter::PARTS_MAX];
        int			nFrame[KEY_MAX];
        int			nLoop;
        int			nKeyNum;
    }KEY_INFO;

    HRESULT Init(CCharacter *pCharacter);
    void Uninit(void);
    void Update(void);
    void Draw(void);
    static CAnimation * Create(CCharacter *pCharacter);
    void LoadAnimation(void);
    void SetAnimation(ANIMATION anim) { m_animation = anim; }

    ANIMATION GetAnimation(void) { return m_animation; }

private:
    KEY_INFO				m_keyInfo[ANIM_MAX];
    ANIMATION				m_animation;

    D3DXVECTOR3				m_pos[CCharacter::PARTS_MAX];			// ���W
    D3DXVECTOR3				m_posDest[CCharacter::PARTS_MAX];
    D3DXVECTOR3				m_rot[CCharacter::PARTS_MAX];			// ��]
    D3DXVECTOR3				m_rotDest[CCharacter::PARTS_MAX];
    D3DXVECTOR3				m_scale;
    ANIMATION				m_animationOld;
    CCharacter				*m_pCharacter;
    int						m_nFrame;
    int						m_nKey;
};

#endif