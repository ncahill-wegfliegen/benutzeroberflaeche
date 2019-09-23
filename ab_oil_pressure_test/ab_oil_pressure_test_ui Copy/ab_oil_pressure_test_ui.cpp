// ab_oil_pressure_test_ui.cpp : Defines the initialization routines for the DLL.
//

#include "pch.h"
#include "framework.h"
#include "ab_oil_pressure_test_ui.h"
#include "../../user_control/dllmain.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

//
//TODO: If this DLL is dynamically linked against the MFC DLLs,
//		any functions exported from this DLL which call into
//		MFC must have the AFX_MANAGE_STATE macro added at the
//		very beginning of the function.
//
//		For example:
//
//		extern "C" BOOL PASCAL EXPORT ExportedFunction()
//		{
//			AFX_MANAGE_STATE(AfxGetStaticModuleState());
//			// normal function body here
//		}
//
//		It is very important that this macro appear in each
//		function, prior to any calls into MFC.  This means that
//		it must appear as the first statement within the
//		function, even before any object variable declarations
//		as their constructors may generate calls into the MFC
//		DLL.
//
//		Please see MFC Technical Notes 33 and 58 for additional
//		details.
//

// CaboilpressuretestuiApp

BEGIN_MESSAGE_MAP(CaboilpressuretestuiApp, CWinApp)
END_MESSAGE_MAP()


// CaboilpressuretestuiApp construction

CaboilpressuretestuiApp::CaboilpressuretestuiApp()
{
	// TODO: add construction code here,
	// Place all significant initialization in InitInstance
}


// The one and only CaboilpressuretestuiApp object

CaboilpressuretestuiApp theApp;


// CaboilpressuretestuiApp initialization

BOOL CaboilpressuretestuiApp::InitInstance()
{
	if( !CWinApp::InitInstance() )
	{
		return FALSE;
	}

	initialize_user_control_dll();

	return TRUE;
}
