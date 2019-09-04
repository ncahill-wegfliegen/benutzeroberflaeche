#include "pch.h"
#include "Helper.h"
#include "ABOilPressTest.h"
#include "ABOilPressTestDoc.h"
#include "MainFrm.h"

CABOilPressTestApp* GetApp()
{
	return dynamic_cast<CABOilPressTestApp*>(::AfxGetApp());
}

CABOilPressTestDoc* GetDoc()
{
	CABOilPressTestApp* pApp{ GetApp() };
	POSITION pos{ pApp->GetFirstDocTemplatePosition() };
	CDocTemplate* pDocTemplate{ pApp->GetNextDocTemplate( pos ) };
	
	pos = pDocTemplate->GetFirstDocPosition();

	CDocument* pDoc{ pDocTemplate->GetNextDoc( pos ) };

	return dynamic_cast<CABOilPressTestDoc*>(pDoc);
}

CMainFrame* GetMainFrame()
{
	return dynamic_cast<CMainFrame*>(::AfxGetMainWnd());
}

COutputPane* GetOutputPane()
{
	CMainFrame* pMainFrame{ GetMainFrame() };
	return pMainFrame->GetOutputPane();
}

CPropertiesPane* GetPropertiesPane()
{
	CMainFrame* pMainFrame{ GetMainFrame() };
	return pMainFrame->GetPropertiesPane();
}

CWellListPane* GetWellListPane()
{
	CMainFrame* pMainFrame{ GetMainFrame() };
	return pMainFrame->GetWellListPane();
}
