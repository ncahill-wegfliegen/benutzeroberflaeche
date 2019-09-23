#include "pch.h"
#include "Helper.h"
#include "ab_oil_pressure_test_app.h"
#include "ab_oil_pressure_test_doc.h"
#include "MainFrm.h"
#include "TicketView.h"

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

CTicketView* GetTicketView()
{
	CABOilPressTestDoc* doc{ GetDoc() };
	POSITION pos{ doc->GetFirstViewPosition() };

	while( pos != NULL )
	{
		CView* view{ doc->GetNextView( pos ) };
		if( view->IsKindOf( RUNTIME_CLASS( CTicketView ) ) )
		{
			return dynamic_cast<CTicketView*>(view);
		}
	}

	return nullptr;
}
