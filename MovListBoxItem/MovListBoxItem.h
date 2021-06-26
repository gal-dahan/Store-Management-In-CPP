
#pragma once

#ifndef __AFXWIN_H__
	#error "incluez 'stdafx.h' avant d'inclure ce fichier pour PCH"
#endif

#include "resource.h"		

class CMovListBoxItemApp : public CWinAppEx
{
public:
	CMovListBoxItemApp();

	public:
	virtual BOOL InitInstance();

	DECLARE_MESSAGE_MAP()
};

extern CMovListBoxItemApp theApp;