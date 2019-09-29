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

// TicketView.h : interface of the CABOilPressTestView class
//

#pragma once

#include "doc_observer.h"
#include "../../user_control/grid.h"

class CTicketView : public CView, public nhill::Doc_observer
{
public:

   virtual ~CTicketView();
#ifdef _DEBUG
   virtual void AssertValid() const;
   virtual void Dump( CDumpContext& dc ) const;
#endif
	   CABOilPressTestDoc* GetDocument() const;

protected:
   CTicketView() noexcept;
   DECLARE_DYNCREATE( CTicketView )

	std::unique_ptr<nhill::ctrl::Grid> grid00_;
	std::unique_ptr<nhill::ctrl::Grid> grid01_;
	std::unique_ptr<nhill::ctrl::Grid> grid02_;
	std::unique_ptr<nhill::ctrl::Grid> grid03_;
	std::unique_ptr<std::vector<nhill::ctrl::Grid>> grid04c_;
	std::unique_ptr<std::vector<nhill::ctrl::Grid>> grid05c_;

   void on_well_list_changed( const nhill::Well_list_changed_event_args& event_args ) final;
   void on_test_changed( const nhill::Test_changed_event_args& event_args ) final;

	virtual BOOL PreCreateWindow( CREATESTRUCT& cs );
	virtual void OnInitialUpdate();
	virtual void OnUpdate( CView* /*pSender*/, LPARAM /*lHint*/, CObject* /*pHint*/ );
	virtual void OnDraw( CDC* pDC );  // overridden to draw this view
   virtual BOOL OnPreparePrinting( CPrintInfo* pInfo );
   virtual void OnBeginPrinting( CDC* pDC, CPrintInfo* pInfo );
   virtual void OnEndPrinting( CDC* pDC, CPrintInfo* pInfo );

   afx_msg int OnCreate( LPCREATESTRUCT lpCreateStruct );
   afx_msg void OnFilePrintPreview();
   afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
   afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
   DECLARE_MESSAGE_MAP()
public:
};

#ifndef _DEBUG  // debug version in ABOilPressTestView.cpp
inline CABOilPressTestDoc* CTicketView::GetDocument() const
   { return reinterpret_cast<CABOilPressTestDoc*>(m_pDocument); }
#endif

