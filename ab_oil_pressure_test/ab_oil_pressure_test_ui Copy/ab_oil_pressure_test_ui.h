// ab_oil_pressure_test_ui.h : main header file for the ab_oil_pressure_test_ui DLL
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'pch.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// CaboilpressuretestuiApp
// See ab_oil_pressure_test_ui.cpp for the implementation of this class
//

class CaboilpressuretestuiApp : public CWinApp
{
public:
	CaboilpressuretestuiApp();

// Overrides
public:
	virtual BOOL InitInstance();

	DECLARE_MESSAGE_MAP()
};
