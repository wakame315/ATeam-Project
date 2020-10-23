#ifndef CREATSTAGE_H
#define CREATSTAGE_H

#include "main.h"
#include "manager.h"
#include "input.h"
#include "scene.h"

#include <stdio.h>
#include <string.h>

class CCreateStage {
public:
	CCreateStage();
	~CCreateStage();

	HRESULT Init(void);
	void Uninit(void);
	void Update(void);

	static HRESULT LoadStage(void);
	static HRESULT SaveStage(void);
	void CursorCollision(D3DXVECTOR3 pos);

private:
	D3DXVECTOR3 m_posR;
	int m_nType;
	CMouse* m_pMouse;
	CInputKeyboard* m_pInputKeyboard;

	bool m_bJudge = false;
	int nAddupAngle = 0;
	int nAddY = 0;
};

#endif