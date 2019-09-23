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

// MainFrm.h : interface of the CMainFrame class
//

#pragma once
#include "OutputPane.h"
#include "PropertiesPane.h"
#include "WellListPane.h"

class CMainFrame : public CFrameWndEx
{
public:
	virtual ~CMainFrame();

	COutputPane*		GetOutputPane();
	CPropertiesPane*  GetPropertiesPane();
	CWellListPane*    GetWellListPane();
	
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);

#ifdef _DEBUG
   virtual void AssertValid() const;
   virtual void Dump(CDumpContext& dc) const;
#endif

protected: // create from serialization only
	CMainFrame() noexcept;
	DECLARE_DYNCREATE( CMainFrame )
	
	CMFCRibbonBar     m_wndRibbonBar;
   CMFCRibbonApplicationButton m_MainButton;
   CMFCToolBarImages m_PanelImages;
   CMFCRibbonStatusBar  m_wndStatusBar;
   COutputPane        m_wndOutput;
   CPropertiesPane    m_wndProperties;
   CWellListPane   m_wndWellList;
   CMFCCaptionBar    m_wndCaptionBar;

   afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
   afx_msg void OnApplicationLook(UINT id);
   afx_msg void OnUpdateApplicationLook(CCmdUI* pCmdUI);
   afx_msg void OnViewOutputWindow();
   afx_msg void OnUpdateViewOutputWindow(CCmdUI* pCmdUI);
   afx_msg void OnViewPropertiesWindow();
   afx_msg void OnUpdateViewPropertiesWindow(CCmdUI* pCmdUI);
   afx_msg void OnViewWellListWindow();
   afx_msg void OnUpdateViewWellListWindow( CCmdUI* pCmdUI );
   afx_msg void OnViewCaptionBar();
   afx_msg void OnUpdateViewCaptionBar(CCmdUI* pCmdUI);
   afx_msg void OnOptions();
   afx_msg void OnFilePrint();
   afx_msg void OnFilePrintPreview();
   afx_msg void OnUpdateFilePrintPreview(CCmdUI* pCmdUI);
   afx_msg void OnSettingChange(UINT uFlags, LPCTSTR lpszSection);
   DECLARE_MESSAGE_MAP()

   BOOL CreateDockingWindows();
   void SetDockingWindowIcons(BOOL bHiColorIcons);
   BOOL CreateCaptionBar();
};


