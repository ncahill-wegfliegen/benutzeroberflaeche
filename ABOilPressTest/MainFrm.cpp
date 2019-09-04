// This MFC Samples source code demonstrates using MFC Microsoft Office Fluent User Interface
// (the "Fluent UI") and is provided only as referential material to supplement the
// Microsoft Foundation Classes Reference and related electronic documentation
// included with the MFC C++ library software.
// License terms to copy, use or distribute the Fluent UI are available separately.
// To learn more about our Fluent UI licensing program, please visit
// https://go.microsoft.com/fwlink/?LinkId=238214.
//
// Copyright (C) Microsoft Corporation
// All rights reserved.

// MainFrm.cpp : implementation of the CMainFrame class
//

#include "pch.h"
#include "framework.h"
#include "ABOilPressTest.h"

#include "MainFrm.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CMainFrame

IMPLEMENT_DYNCREATE(CMainFrame, CFrameWndEx)

BEGIN_MESSAGE_MAP(CMainFrame, CFrameWndEx)
   ON_WM_CREATE()
   ON_COMMAND_RANGE(ID_VIEW_APPLOOK_WIN_2000, ID_VIEW_APPLOOK_WINDOWS_7, &CMainFrame::OnApplicationLook)
   ON_UPDATE_COMMAND_UI_RANGE(ID_VIEW_APPLOOK_WIN_2000, ID_VIEW_APPLOOK_WINDOWS_7, &CMainFrame::OnUpdateApplicationLook)
	ON_COMMAND(ID_VIEW_CAPTION_BAR, &CMainFrame::OnViewCaptionBar)
   ON_UPDATE_COMMAND_UI(ID_VIEW_CAPTION_BAR, &CMainFrame::OnUpdateViewCaptionBar)
   ON_COMMAND(ID_TOOLS_OPTIONS, &CMainFrame::OnOptions)
   ON_COMMAND(ID_VIEW_OUTPUTWND, &CMainFrame::OnViewOutputWindow)
   ON_UPDATE_COMMAND_UI(ID_VIEW_OUTPUTWND, &CMainFrame::OnUpdateViewOutputWindow)
   ON_COMMAND(ID_VIEW_PROPERTIES_PANE, &CMainFrame::OnViewPropertiesWindow)
   ON_UPDATE_COMMAND_UI( ID_VIEW_PROPERTIES_PANE, &CMainFrame::OnUpdateViewPropertiesWindow)
   ON_COMMAND( ID_VIEW_WELL_LIST_PANE, &CMainFrame::OnViewWellListWindow )
   ON_UPDATE_COMMAND_UI( ID_VIEW_WELL_LIST_PANE, &CMainFrame::OnUpdateViewWellListWindow )
   ON_COMMAND(ID_FILE_PRINT, &CMainFrame::OnFilePrint)
   ON_COMMAND(ID_FILE_PRINT_DIRECT, &CMainFrame::OnFilePrint)
   ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CMainFrame::OnFilePrintPreview)
   ON_UPDATE_COMMAND_UI(ID_FILE_PRINT_PREVIEW, &CMainFrame::OnUpdateFilePrintPreview)
   ON_WM_SETTINGCHANGE()
END_MESSAGE_MAP()

// CMainFrame construction/destruction

CMainFrame::CMainFrame() noexcept
{
   // TODO: add member initialization code here
   theApp.m_nAppLook = theApp.GetInt(_T("ApplicationLook"), ID_VIEW_APPLOOK_VS_2008);
}

CMainFrame::~CMainFrame()
{
}

int CMainFrame::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
   if (CFrameWndEx::OnCreate(lpCreateStruct) == -1)
      return -1;

   BOOL bNameValid;

   m_wndRibbonBar.Create(this);
   m_wndRibbonBar.LoadFromResource(IDR_RIBBON);

   if (!m_wndStatusBar.Create(this))
   {
      TRACE0("Failed to create status bar\n");
      return -1;      // fail to create
   }

   CString strTitlePane1;
   CString strTitlePane2;
   bNameValid = strTitlePane1.LoadString(IDS_STATUS_PANE1);
   ASSERT(bNameValid);
   bNameValid = strTitlePane2.LoadString(IDS_STATUS_PANE2);
   ASSERT(bNameValid);
   m_wndStatusBar.AddElement(new CMFCRibbonStatusBarPane(ID_STATUSBAR_PANE1, strTitlePane1, TRUE), strTitlePane1);
   m_wndStatusBar.AddExtendedElement(new CMFCRibbonStatusBarPane(ID_STATUSBAR_PANE2, strTitlePane2, TRUE), strTitlePane2);

   // enable Visual Studio 2005 style docking window behavior
   CDockingManager::SetDockingMode(DT_SMART);
   // enable Visual Studio 2005 style docking window auto-hide behavior
   EnableAutoHidePanes(CBRS_ALIGN_ANY);

   // Create a caption bar:
   if (!CreateCaptionBar())
   {
      TRACE0("Failed to create caption bar\n");
      return -1;      // fail to create
   }

   // create docking windows
   if (!CreateDockingWindows())
   {
      TRACE0("Failed to create docking windows\n");
      return -1;
   }

   m_wndOutput.EnableDocking(CBRS_ALIGN_ANY);
   DockPane(&m_wndOutput);

   m_wndProperties.EnableDocking(CBRS_ALIGN_ANY);
   DockPane(&m_wndProperties);

   m_wndWellList.EnableDocking( CBRS_ALIGN_ANY );
   DockPane( &m_wndWellList );

   // set the visual manager and style based on persisted value
   OnApplicationLook(theApp.m_nAppLook);

   return 0;
}

COutputPane* CMainFrame::GetOutputPane()
{
	return &m_wndOutput;
}

CPropertiesPane* CMainFrame::GetPropertiesPane()
{
	return &m_wndProperties;
}

CWellListPane* CMainFrame::GetWellListPane()
{
	return &m_wndWellList;
}

BOOL CMainFrame::PreCreateWindow(CREATESTRUCT& cs)
{
   if( !CFrameWndEx::PreCreateWindow(cs) )
      return FALSE;

	// Remove the document title (currently just "Untitled") from the frame title.
	// This will just leave the App title as the frame title.
	cs.style &= ~(LONG)FWS_ADDTOTITLE;

   return TRUE;
}

BOOL CMainFrame::CreateDockingWindows()
{
   BOOL bNameValid;
   // Create output window
   CString strOutputWnd;
   bNameValid = strOutputWnd.LoadString(IDS_OUTPUT_WND);
   ASSERT(bNameValid);
   if (!m_wndOutput.Create(strOutputWnd, this, CRect(0, 0, 100, 100), TRUE, ID_VIEW_OUTPUTWND, WS_CHILD | WS_VISIBLE | WS_CLIPSIBLINGS | WS_CLIPCHILDREN | CBRS_BOTTOM | CBRS_FLOAT_MULTI))
   {
      TRACE0("Failed to create Output window\n");
      return FALSE; // failed to create
   }

   // Create properties window
   CString strPropertiesWnd;
   bNameValid = strPropertiesWnd.LoadString(IDS_PROPERTIES_WND);
   ASSERT(bNameValid);
   if (!m_wndProperties.Create(strPropertiesWnd, this, CRect(0, 0, 200, 200), TRUE, ID_VIEW_PROPERTIESWND, WS_CHILD | WS_VISIBLE | WS_CLIPSIBLINGS | WS_CLIPCHILDREN | CBRS_RIGHT | CBRS_FLOAT_MULTI))
   {
      TRACE0("Failed to create Properties window\n");
      return FALSE; // failed to create
   }

   // Create well list window
   CString strWellListWnd;
   bNameValid = strWellListWnd.LoadString( IDS_WELL_LIST_PANE );
   ASSERT( bNameValid );
   if( !m_wndWellList.Create( strWellListWnd, this, CRect( 0, 0, 200, 200 ), TRUE, ID_VIEW_WELL_LIST_PANE, WS_CHILD | WS_VISIBLE | WS_CLIPSIBLINGS | WS_CLIPCHILDREN | CBRS_LEFT | CBRS_FLOAT_MULTI ) )
   {
      TRACE0( "Failed to create Well List window\n" );
      return FALSE; // failed to create
   }

   SetDockingWindowIcons(theApp.m_bHiColorIcons);
   return TRUE;
}

void CMainFrame::SetDockingWindowIcons(BOOL bHiColorIcons)
{
   HICON hOutputBarIcon = (HICON) ::LoadImage(::AfxGetResourceHandle(), MAKEINTRESOURCE(bHiColorIcons ? IDI_OUTPUT_WND_HC : IDI_OUTPUT_WND), IMAGE_ICON, ::GetSystemMetrics(SM_CXSMICON), ::GetSystemMetrics(SM_CYSMICON), 0);
   m_wndOutput.SetIcon(hOutputBarIcon, FALSE);

   HICON hPropertiesBarIcon = (HICON) ::LoadImage(::AfxGetResourceHandle(), MAKEINTRESOURCE(bHiColorIcons ? IDI_PROPERTIES_WND_HC : IDI_PROPERTIES_WND), IMAGE_ICON, ::GetSystemMetrics(SM_CXSMICON), ::GetSystemMetrics(SM_CYSMICON), 0);
   m_wndProperties.SetIcon(hPropertiesBarIcon, FALSE);

}

BOOL CMainFrame::CreateCaptionBar()
{
   if (!m_wndCaptionBar.Create(WS_CHILD | WS_VISIBLE | WS_CLIPSIBLINGS, this, ID_VIEW_CAPTION_BAR, -1, TRUE))
   {
      TRACE0("Failed to create caption bar\n");
      return FALSE;
   }

   BOOL bNameValid;

   CString strTemp, strTemp2;
   bNameValid = strTemp.LoadString(IDS_CAPTION_BUTTON);
   ASSERT(bNameValid);
   m_wndCaptionBar.SetButton(strTemp, ID_TOOLS_OPTIONS, CMFCCaptionBar::ALIGN_LEFT, FALSE);
   bNameValid = strTemp.LoadString(IDS_CAPTION_BUTTON_TIP);
   ASSERT(bNameValid);
   m_wndCaptionBar.SetButtonToolTip(strTemp);

   bNameValid = strTemp.LoadString(IDS_CAPTION_TEXT);
   ASSERT(bNameValid);
   m_wndCaptionBar.SetText(strTemp, CMFCCaptionBar::ALIGN_LEFT);

   m_wndCaptionBar.SetBitmap(IDB_INFO, RGB(255, 255, 255), FALSE, CMFCCaptionBar::ALIGN_LEFT);
   bNameValid = strTemp.LoadString(IDS_CAPTION_IMAGE_TIP);
   ASSERT(bNameValid);
   bNameValid = strTemp2.LoadString(IDS_CAPTION_IMAGE_TEXT);
   ASSERT(bNameValid);
   m_wndCaptionBar.SetImageToolTip(strTemp, strTemp2);

   return TRUE;
}

// CMainFrame diagnostics

#ifdef _DEBUG
void CMainFrame::AssertValid() const
{
   CFrameWndEx::AssertValid();
}

void CMainFrame::Dump(CDumpContext& dc) const
{
   CFrameWndEx::Dump(dc);
}
#endif //_DEBUG


// CMainFrame message handlers

void CMainFrame::OnApplicationLook(UINT id)
{
   CWaitCursor wait;

   theApp.m_nAppLook = id;

   switch (theApp.m_nAppLook)
   {
   case ID_VIEW_APPLOOK_WIN_2000:
      CMFCVisualManager::SetDefaultManager(RUNTIME_CLASS(CMFCVisualManager));
      m_wndRibbonBar.SetWindows7Look(FALSE);
      break;

   case ID_VIEW_APPLOOK_OFF_XP:
      CMFCVisualManager::SetDefaultManager(RUNTIME_CLASS(CMFCVisualManagerOfficeXP));
      m_wndRibbonBar.SetWindows7Look(FALSE);
      break;

   case ID_VIEW_APPLOOK_WIN_XP:
      CMFCVisualManagerWindows::m_b3DTabsXPTheme = TRUE;
      CMFCVisualManager::SetDefaultManager(RUNTIME_CLASS(CMFCVisualManagerWindows));
      m_wndRibbonBar.SetWindows7Look(FALSE);
      break;

   case ID_VIEW_APPLOOK_OFF_2003:
      CMFCVisualManager::SetDefaultManager(RUNTIME_CLASS(CMFCVisualManagerOffice2003));
      CDockingManager::SetDockingMode(DT_SMART);
      m_wndRibbonBar.SetWindows7Look(FALSE);
      break;

   case ID_VIEW_APPLOOK_VS_2005:
      CMFCVisualManager::SetDefaultManager(RUNTIME_CLASS(CMFCVisualManagerVS2005));
      CDockingManager::SetDockingMode(DT_SMART);
      m_wndRibbonBar.SetWindows7Look(FALSE);
      break;

   case ID_VIEW_APPLOOK_VS_2008:
      CMFCVisualManager::SetDefaultManager(RUNTIME_CLASS(CMFCVisualManagerVS2008));
      CDockingManager::SetDockingMode(DT_SMART);
      m_wndRibbonBar.SetWindows7Look(FALSE);
      break;

   case ID_VIEW_APPLOOK_WINDOWS_7:
      CMFCVisualManager::SetDefaultManager(RUNTIME_CLASS(CMFCVisualManagerWindows7));
      CDockingManager::SetDockingMode(DT_SMART);
      m_wndRibbonBar.SetWindows7Look(TRUE);
      break;

   default:
      switch (theApp.m_nAppLook)
      {
      case ID_VIEW_APPLOOK_OFF_2007_BLUE:
         CMFCVisualManagerOffice2007::SetStyle(CMFCVisualManagerOffice2007::Office2007_LunaBlue);
         break;

      case ID_VIEW_APPLOOK_OFF_2007_BLACK:
         CMFCVisualManagerOffice2007::SetStyle(CMFCVisualManagerOffice2007::Office2007_ObsidianBlack);
         break;

      case ID_VIEW_APPLOOK_OFF_2007_SILVER:
         CMFCVisualManagerOffice2007::SetStyle(CMFCVisualManagerOffice2007::Office2007_Silver);
         break;

      case ID_VIEW_APPLOOK_OFF_2007_AQUA:
         CMFCVisualManagerOffice2007::SetStyle(CMFCVisualManagerOffice2007::Office2007_Aqua);
         break;
      }

      CMFCVisualManager::SetDefaultManager(RUNTIME_CLASS(CMFCVisualManagerOffice2007));
      CDockingManager::SetDockingMode(DT_SMART);
      m_wndRibbonBar.SetWindows7Look(FALSE);
   }

   m_wndOutput.UpdateFonts();
   RedrawWindow(nullptr, nullptr, RDW_ALLCHILDREN | RDW_INVALIDATE | RDW_UPDATENOW | RDW_FRAME | RDW_ERASE);

   theApp.WriteInt(_T("ApplicationLook"), theApp.m_nAppLook);
}

void CMainFrame::OnUpdateApplicationLook(CCmdUI* pCmdUI)
{
   pCmdUI->SetRadio(theApp.m_nAppLook == pCmdUI->m_nID);
}


void CMainFrame::OnViewCaptionBar()
{
   m_wndCaptionBar.ShowWindow(m_wndCaptionBar.IsVisible() ? SW_HIDE : SW_SHOW);
   RecalcLayout(FALSE);
}

void CMainFrame::OnUpdateViewCaptionBar(CCmdUI* pCmdUI)
{
   pCmdUI->SetCheck(m_wndCaptionBar.IsVisible());
}

void CMainFrame::OnOptions()
{
   CMFCRibbonCustomizeDialog *pOptionsDlg = new CMFCRibbonCustomizeDialog(this, &m_wndRibbonBar);
   ASSERT(pOptionsDlg != nullptr);

   pOptionsDlg->DoModal();
   delete pOptionsDlg;
}

void CMainFrame::OnViewOutputWindow()
{
   // Show or activate the pane, depending on current state.  The
   // pane can only be closed via the [x] button on the pane frame.
   m_wndOutput.ShowPane(!m_wndOutput.IsVisible(), FALSE, TRUE);
   m_wndOutput.SetFocus();
}

void CMainFrame::OnUpdateViewOutputWindow(CCmdUI* pCmdUI)
{
   pCmdUI->SetCheck( m_wndOutput.IsVisible() );
}

void CMainFrame::OnViewPropertiesWindow()
{
	// Show or activate the pane, depending on current state.  The
	// pane can only be closed via the [x] button on the pane frame.
	m_wndProperties.ShowPane( !m_wndProperties.IsVisible(), FALSE, TRUE );
	m_wndProperties.SetFocus();
}

void CMainFrame::OnUpdateViewPropertiesWindow( CCmdUI* pCmdUI )
{
	pCmdUI->SetCheck( m_wndProperties.IsVisible() );
}

void CMainFrame::OnViewWellListWindow()
{
   // Show or activate the pane, depending on current state.  The
   // pane can only be closed via the [x] button on the pane frame.
   m_wndWellList.ShowPane( !m_wndWellList.IsVisible(), FALSE, TRUE);
   m_wndWellList.SetFocus();
}

void CMainFrame::OnUpdateViewWellListWindow(CCmdUI* pCmdUI)
{
   pCmdUI->SetCheck( m_wndWellList.IsVisible() );
}



void CMainFrame::OnFilePrint()
{
   if (IsPrintPreview())
   {
      PostMessage(WM_COMMAND, AFX_ID_PREVIEW_PRINT);
   }
}

void CMainFrame::OnFilePrintPreview()
{
   if (IsPrintPreview())
   {
      PostMessage(WM_COMMAND, AFX_ID_PREVIEW_CLOSE);  // force Print Preview mode closed
   }
}

void CMainFrame::OnUpdateFilePrintPreview(CCmdUI* pCmdUI)
{
   pCmdUI->SetCheck(IsPrintPreview());
}

void CMainFrame::OnSettingChange(UINT uFlags, LPCTSTR lpszSection)
{
   CFrameWndEx::OnSettingChange(uFlags, lpszSection);
   m_wndOutput.UpdateFonts();
}
