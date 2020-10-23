#define _CRT_SECURE_NO_WARNINGS

#include "CreateStage.h"
#include "block.h"
#include "effect3d.h"
#include "library.h"
#include "camera.h"

CCreateStage::CCreateStage() {

}

CCreateStage::~CCreateStage() {

}

HRESULT CCreateStage::Init(void) {

	return S_OK;
}

void CCreateStage::Uninit(void) {

}

void CCreateStage::Update(void) {
	m_posR = CCamera::GetCameraposR();
	//�L�[�{�[�h�̊m�ۂ������������擾
	m_pInputKeyboard = CManager::GetInputKeyboard();
	//�}�E�X�̊m�ۂ������������擾
	m_pMouse = CManager::GetMouse();

	if (m_nType >= CBlock::TYPE_MAX) {
		m_nType = CBlock::TYPE_MAX - 1;
	}
	if (m_nType < 0) {
		m_nType = 0;
	}

	//=================================================================================================================================================================================================================================================================================================================================================================================================================================================================================================================================================================================================================================================================================================================================
	// �ݒu�I�u�W�F�N�g�̕ύX
	if (m_pInputKeyboard->GetKeyboardTrigger(DIK_1)) {
		m_nType = CBlock::TYPE_BUILDING001;
	}
	if (m_pInputKeyboard->GetKeyboardTrigger(DIK_2)) {
		m_nType = CBlock::TYPE_BUILDING101;
	}
	if (m_pInputKeyboard->GetKeyboardTrigger(DIK_3)) {
		m_nType = CBlock::TYPE_BUILDING201;
	}
	if (m_pInputKeyboard->GetKeyboardTrigger(DIK_4)) {
		m_nType = CBlock::TYPE_BUILDING301;
	}
	if (m_pInputKeyboard->GetKeyboardTrigger(DIK_5)) {
		m_nType = CBlock::TYPE_BUILDING401;
	}
	if (m_pInputKeyboard->GetKeyboardTrigger(DIK_6)) {
		m_nType = CBlock::TYPE_BUILDING501;
	}
	if (m_pInputKeyboard->GetKeyboardTrigger(DIK_7)) {
		m_nType = CBlock::TYPE_SIGNAL;
	}
	if (m_pInputKeyboard->GetKeyboardTrigger(DIK_8)) {
		m_nType = CBlock::TYPE_LIGHT;
	}
	if (m_pInputKeyboard->GetKeyboardTrigger(DIK_9)) {
		m_nType = CBlock::TYPE_DUSTBOX;
	}
	//=================================================================================================================================================================================================================================================================================================================================================================================================================================================================================================================================================================================================================================================================================================================================

	if (m_pInputKeyboard->GetKeyboardPress(DIK_S) && m_pInputKeyboard->GetKeyboardTrigger(DIK_LCONTROL) ||
		m_pInputKeyboard->GetKeyboardPress(DIK_LCONTROL) && m_pInputKeyboard->GetKeyboardTrigger(DIK_S)) {

		//�u���b�N�̍��W��ۑ�
		SaveStage();
	}

	//�ݒu�����I�u�W�F�N�g�̉�]
	if (CBlock::GetSelectBlock() != NULL) {
		D3DXVECTOR3 SelectBlockPos = CBlock::GetSelectBlock()->GetPos();
		D3DXVECTOR3 SelectBlockRot = CBlock::GetSelectBlock()->GetRot();
		int nSelectBlockType = CBlock::GetSelectBlock()->GetType();

		if (m_pInputKeyboard->GetKeyboardTrigger(DIK_Q)) {
			nAddupAngle += -90;
		}
		if (m_pInputKeyboard->GetKeyboardTrigger(DIK_E)) {
			nAddupAngle += 90;
		}

		if (nAddupAngle % 360 == 0) {
			nAddupAngle = 0;
		}

		if (m_pInputKeyboard->GetKeyboardTrigger(DIK_Q) || m_pInputKeyboard->GetKeyboardTrigger(DIK_E)) {
			CBlock::Create(D3DXVECTOR3(SelectBlockPos), D3DXVECTOR3(SelectBlockRot.x, D3DXToRadian(SelectBlockRot.y + nAddupAngle), SelectBlockRot.z), nSelectBlockType);
			CBlock::GetSelectBlock()->Uninit();
		}
	}

	//�E�N���b�N���ꂽ��
	if (m_pMouse->GetMouseTriggerRight()) {
		//�u���b�N��z�u
		CBlock::Create(D3DXVECTOR3(m_posR.x, 0, m_posR.z), D3DXVECTOR3(0.0f, 0.0f, 0.0f), m_nType);
	}
	//���N���b�N���ꂽ��
	if (m_pMouse->GetMouseTriggerLeft()) {
		//�I�u�W�F�N�g��I�����Ă�ꍇ
		if (CBlock::GetSelectBlock() != NULL) {
			//�I�����Ă�I�u�W�F�g����������
			CBlock::GetSelectBlock()->Uninit();
		}
	}

	// �u���ꏊ�𕪂���₷��
	CEffect3D::Create(D3DXVECTOR3(m_posR.x, CURSOR_POS_Y, m_posR.z), CURSOR_SIZE, DEFAULT_VECTOR, DEFAULT_COLOR, CEffect3D::TYPE_CURSOR);

	// �J�[�\���̓����蔻��
	CursorCollision(D3DXVECTOR3(m_posR.x, CURSOR_POS_Y, m_posR.z));
}

//=============================================================================
// �J�[�\���̓����蔻��
//=============================================================================
void CCreateStage::CursorCollision(D3DXVECTOR3 pos)
{
	// �u���b�N�Ƃ̓����蔻��
	CScene *pScene = CScene::GetTopScene();
	bool bSelect = false;   // �I�����Ă��邩�ǂ����̃t���O
	for (int nCntScene = 0; nCntScene < CScene::GetNumAll(); nCntScene++)
	{
		// ���g������Ȃ�
		if (pScene != NULL)
		{
			// ���̃V�[�����L��
			CScene*pNextScene = pScene->GetNextScene();

			// �^�C�v���擾
			CScene::OBJTYPE objType = pScene->GetObjType();

			// �u���b�N�Ȃ�A
			if (objType == CScene::OBJTYPE_BLOCK)
			{
				// �u���b�N�ɃL���X�g
				CBlock *pBlock = (CBlock*)pScene;

				// �J�[�\���̓����蔻��̃T�C�Y��ݒ�
				D3DXVECTOR3 cursorCollisionSize = CURSOR_COLLISION_SIZE;

				// �J�[�\���̓����蔻����v�Z
				if (RectangleCollision3D(&pos, &pBlock->GetPos(),
					&cursorCollisionSize, &pBlock->GetCollisionSize()) == true)
				{
					// �������Ă���Ȃ�A�I�����Ă���u���b�N�ɂ���
					CBlock::SetSelectBlock(pBlock);

					// �I�����Ă���
					bSelect = true;
				}
			}

			// ���̃V�[���ɂ���
			pScene = pNextScene;
		}
		else
		{
			// ���g���Ȃ��Ȃ�A�����ŏ������I����
			break;
		}
	}

	// �I�����Ă�����̂��Ȃ��Ȃ�
	if (bSelect == false)
	{
		// �I�����Ă���u���b�N��NULL
		CBlock::SetSelectBlock(NULL);
	}
}

HRESULT CCreateStage::LoadStage(void) {
	// �t�@�C���|�C���g
	FILE *pFile = NULL;

	// �ϐ��錾
	int  nCntLoad = 0;
	char cReedText[128];	// �����Ƃ��ēǂݎ��p
	char cHeadText[256];	//
	char cDie[128];

	// �f�o�b�O�p�̕ϐ�
	int nType[256];
	D3DXVECTOR3 pos[256];
	D3DXVECTOR3 rot[256];

	// �t�@�C���J
	pFile = fopen("data/TXT/model.txt", "r");

	// �J����
	if (pFile != NULL)
	{
		while (strcmp(cHeadText, "MODELSET") != 0)
		{
			fgets(cReedText, sizeof(cReedText), pFile);
			sscanf(cReedText, "%s", &cHeadText);
		}

		if (strcmp(cHeadText, "MODELSET") == 0)
		{
			while (strcmp(cHeadText, "END_SCRIPT") != 0)
			{
				fgets(cReedText, sizeof(cReedText), pFile);
				sscanf(cReedText, "%s", &cHeadText);

				if (strcmp(cHeadText, "\n") == 0)
				{
				}
				else if (strcmp(cHeadText, "END_MODELSET") != 0)
				{
					if (strcmp(cHeadText, "TYPE") == 0)
					{
						sscanf(cReedText, "%s %s %d", &cDie, &cDie, &nType[nCntLoad]);
					}

					if (strcmp(cHeadText, "POS") == 0)
					{
						sscanf(cReedText, "%s %s %f %f %f", &cDie, &cDie, &pos[nCntLoad].x, &pos[nCntLoad].y, &pos[nCntLoad].z);
					}

					if (strcmp(cHeadText, "ROT") == 0)
					{
						sscanf(cReedText, "%s %s %f %f %f", &cDie, &cDie, &rot[nCntLoad].x, &rot[nCntLoad].y, &rot[nCntLoad].z);

						// �u���b�N�𐶐�
						CBlock::Create(pos[nCntLoad], D3DXVECTOR3(D3DXToRadian(rot[nCntLoad].x),
							D3DXToRadian(rot[nCntLoad].y), D3DXToRadian(rot[nCntLoad].z)), nType[nCntLoad]);

						nCntLoad++;
					}
				}
			}

		}
		// �t�@�C����
		fclose(pFile);

		return S_OK;
	}

	// �J���Ȃ�
	else
	{
		printf("�J����܂���ł���\n");
	}

	return E_FAIL;
}

HRESULT CCreateStage::SaveStage(void) {
	FILE* fp;
	fp = fopen("data/TXT/model.txt", "w");

	if (fp != NULL) {
		// �u���b�N�Ƃ̓����蔻��
		CScene *pScene = CScene::GetTopScene();

		fprintf(fp, "SCRIPT			# ���̍s�͐�Ώ����Ȃ����ƁI\n\n");

		fprintf(fp, "#------------------------------------------------------------------------------\n");
		fprintf(fp, "# �ǂݍ��ރ��f����\n");
		fprintf(fp, "#------------------------------------------------------------------------------\n");
		fprintf(fp, "NUM_MODEL = %d\n\n", CBlock::GetBlockNumAll());

		fprintf(fp, "#------------------------------------------------------------------------------\n");
		fprintf(fp, "# �ǂݍ��ރ��f���t�@�C����\n");
		fprintf(fp, "#------------------------------------------------------------------------------\n");
		fprintf(fp, "\n\n");

		fprintf(fp, "#------------------------------------------------------------------------------\n");
		fprintf(fp, "# �\�����郂�f���̔z�u���\n");
		fprintf(fp, "#------------------------------------------------------------------------------\n");

		for (int nCntScene = 0; nCntScene < CBlock::GetBlockNumAll(); nCntScene++)
		{
			// ���g������Ȃ�
			if (pScene != NULL)
			{
				// ���̃V�[�����L��
				CScene*pNextScene = pScene->GetNextScene();

				// �^�C�v���擾
				CScene::OBJTYPE objType = pScene->GetObjType();

					// �u���b�N�ɃL���X�g
					CBlock *pBlock = (CBlock*)pScene;

					fprintf(fp, "MODELSET\n");

					fprintf(fp, "	TYPE = %d\n", pBlock->GetType());
					fprintf(fp, "	POS = %d %d %d\n", (int)pBlock->GetPos().x, (int)pBlock->GetPos().y, (int)pBlock->GetPos().z);
					fprintf(fp, "	ROT = %d %d %d\n", (int)D3DXToDegree(pBlock->GetRot().x), (int)D3DXToDegree(pBlock->GetRot().y), (int)D3DXToDegree(pBlock->GetRot().z));

					fprintf(fp, "END_MODELSET\n\n");

				// ���̃V�[���ɂ���
				pScene = pNextScene;
			}
			else
			{
				// ���g���Ȃ��Ȃ�A�����ŏ������I����
				break;
			}
		}

		fprintf(fp, "END_SCRIPT		# ���̍s�͐�Ώ����Ȃ����ƁI");

		fclose(fp);

		return S_OK;
	}
	else {

	}

	return E_FAIL;
}