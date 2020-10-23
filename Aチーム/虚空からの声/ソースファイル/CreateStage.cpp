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
	//キーボードの確保したメモリを取得
	m_pInputKeyboard = CManager::GetInputKeyboard();
	//マウスの確保したメモリを取得
	m_pMouse = CManager::GetMouse();

	if (m_nType >= CBlock::TYPE_MAX) {
		m_nType = CBlock::TYPE_MAX - 1;
	}
	if (m_nType < 0) {
		m_nType = 0;
	}

	//=================================================================================================================================================================================================================================================================================================================================================================================================================================================================================================================================================================================================================================================================================================================================
	// 設置オブジェクトの変更
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

		//ブロックの座標を保存
		SaveStage();
	}

	//設置したオブジェクトの回転
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

	//右クリックされた時
	if (m_pMouse->GetMouseTriggerRight()) {
		//ブロックを配置
		CBlock::Create(D3DXVECTOR3(m_posR.x, 0, m_posR.z), D3DXVECTOR3(0.0f, 0.0f, 0.0f), m_nType);
	}
	//左クリックされた時
	if (m_pMouse->GetMouseTriggerLeft()) {
		//オブジェクトを選択してる場合
		if (CBlock::GetSelectBlock() != NULL) {
			//選択してるオブジェトを消去する
			CBlock::GetSelectBlock()->Uninit();
		}
	}

	// 置く場所を分かりやすく
	CEffect3D::Create(D3DXVECTOR3(m_posR.x, CURSOR_POS_Y, m_posR.z), CURSOR_SIZE, DEFAULT_VECTOR, DEFAULT_COLOR, CEffect3D::TYPE_CURSOR);

	// カーソルの当たり判定
	CursorCollision(D3DXVECTOR3(m_posR.x, CURSOR_POS_Y, m_posR.z));
}

//=============================================================================
// カーソルの当たり判定
//=============================================================================
void CCreateStage::CursorCollision(D3DXVECTOR3 pos)
{
	// ブロックとの当たり判定
	CScene *pScene = CScene::GetTopScene();
	bool bSelect = false;   // 選択しているかどうかのフラグ
	for (int nCntScene = 0; nCntScene < CScene::GetNumAll(); nCntScene++)
	{
		// 中身があるなら
		if (pScene != NULL)
		{
			// 次のシーンを記憶
			CScene*pNextScene = pScene->GetNextScene();

			// タイプを取得
			CScene::OBJTYPE objType = pScene->GetObjType();

			// ブロックなら、
			if (objType == CScene::OBJTYPE_BLOCK)
			{
				// ブロックにキャスト
				CBlock *pBlock = (CBlock*)pScene;

				// カーソルの当たり判定のサイズを設定
				D3DXVECTOR3 cursorCollisionSize = CURSOR_COLLISION_SIZE;

				// カーソルの当たり判定を計算
				if (RectangleCollision3D(&pos, &pBlock->GetPos(),
					&cursorCollisionSize, &pBlock->GetCollisionSize()) == true)
				{
					// 当たっているなら、選択しているブロックにする
					CBlock::SetSelectBlock(pBlock);

					// 選択している
					bSelect = true;
				}
			}

			// 次のシーンにする
			pScene = pNextScene;
		}
		else
		{
			// 中身がないなら、そこで処理を終える
			break;
		}
	}

	// 選択しているものがないなら
	if (bSelect == false)
	{
		// 選択しているブロックがNULL
		CBlock::SetSelectBlock(NULL);
	}
}

HRESULT CCreateStage::LoadStage(void) {
	// ファイルポイント
	FILE *pFile = NULL;

	// 変数宣言
	int  nCntLoad = 0;
	char cReedText[128];	// 文字として読み取り用
	char cHeadText[256];	//
	char cDie[128];

	// デバッグ用の変数
	int nType[256];
	D3DXVECTOR3 pos[256];
	D3DXVECTOR3 rot[256];

	// ファイル開
	pFile = fopen("data/TXT/model.txt", "r");

	// 開けた
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

						// ブロックを生成
						CBlock::Create(pos[nCntLoad], D3DXVECTOR3(D3DXToRadian(rot[nCntLoad].x),
							D3DXToRadian(rot[nCntLoad].y), D3DXToRadian(rot[nCntLoad].z)), nType[nCntLoad]);

						nCntLoad++;
					}
				}
			}

		}
		// ファイル閉
		fclose(pFile);

		return S_OK;
	}

	// 開けない
	else
	{
		printf("開けれませんでした\n");
	}

	return E_FAIL;
}

HRESULT CCreateStage::SaveStage(void) {
	FILE* fp;
	fp = fopen("data/TXT/model.txt", "w");

	if (fp != NULL) {
		// ブロックとの当たり判定
		CScene *pScene = CScene::GetTopScene();

		fprintf(fp, "SCRIPT			# この行は絶対消さないこと！\n\n");

		fprintf(fp, "#------------------------------------------------------------------------------\n");
		fprintf(fp, "# 読み込むモデル数\n");
		fprintf(fp, "#------------------------------------------------------------------------------\n");
		fprintf(fp, "NUM_MODEL = %d\n\n", CBlock::GetBlockNumAll());

		fprintf(fp, "#------------------------------------------------------------------------------\n");
		fprintf(fp, "# 読み込むモデルファイル名\n");
		fprintf(fp, "#------------------------------------------------------------------------------\n");
		fprintf(fp, "\n\n");

		fprintf(fp, "#------------------------------------------------------------------------------\n");
		fprintf(fp, "# 表示するモデルの配置情報\n");
		fprintf(fp, "#------------------------------------------------------------------------------\n");

		for (int nCntScene = 0; nCntScene < CBlock::GetBlockNumAll(); nCntScene++)
		{
			// 中身があるなら
			if (pScene != NULL)
			{
				// 次のシーンを記憶
				CScene*pNextScene = pScene->GetNextScene();

				// タイプを取得
				CScene::OBJTYPE objType = pScene->GetObjType();

					// ブロックにキャスト
					CBlock *pBlock = (CBlock*)pScene;

					fprintf(fp, "MODELSET\n");

					fprintf(fp, "	TYPE = %d\n", pBlock->GetType());
					fprintf(fp, "	POS = %d %d %d\n", (int)pBlock->GetPos().x, (int)pBlock->GetPos().y, (int)pBlock->GetPos().z);
					fprintf(fp, "	ROT = %d %d %d\n", (int)D3DXToDegree(pBlock->GetRot().x), (int)D3DXToDegree(pBlock->GetRot().y), (int)D3DXToDegree(pBlock->GetRot().z));

					fprintf(fp, "END_MODELSET\n\n");

				// 次のシーンにする
				pScene = pNextScene;
			}
			else
			{
				// 中身がないなら、そこで処理を終える
				break;
			}
		}

		fprintf(fp, "END_SCRIPT		# この行は絶対消さないこと！");

		fclose(fp);

		return S_OK;
	}
	else {

	}

	return E_FAIL;
}