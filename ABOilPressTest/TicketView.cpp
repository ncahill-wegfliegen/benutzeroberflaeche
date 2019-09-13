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

// ABOilPressTestView.cpp : implementation of the CABOilPressTestView class
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "ABOilPressTest.h"
#endif

#include "ABOilPressTestDoc.h"
#include "TicketView.h"
#include "../UserControl/TicketSection.h"
#include "../UserControl/UserControlPanel.h"
#include "../../dev/datenzugriff/ab_oil_pressure_test/ab_oil_pressure_test/test.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

using namespace std;

IMPLEMENT_DYNCREATE(CTicketView, CView)

BEGIN_MESSAGE_MAP(CTicketView, CView)
   ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
   ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
   ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CTicketView::OnFilePrintPreview)
   ON_WM_CONTEXTMENU()
   ON_WM_RBUTTONUP()
   ON_WM_CREATE()
END_MESSAGE_MAP()

CTicketView::CTicketView() noexcept
   : section_well_id_{make_unique<TicketSection>()}
   , section_well_id_panel_{ make_unique<nhill::ctrl::UserControlPanel>(&(*section_well_id_)) }
{
}

CTicketView::~CTicketView()
{
}

// CABOilPressTestView drawing

void CTicketView::on_well_list_changed( const nhill::Well_list_changed_event_args& )
{
   // Ignore this notification.
}

void CTicketView::on_test_changed( const nhill::Test_changed_event_args& event_args )
{
	const nhill::datenzugriff::ab_oil_pressure_test::Test* test{ event_args.test };
	if( test == nullptr )
	{
		// Clear the ticket
		return;
	}

   // Display the ticket for the new test.
	TicketSectionListCtrl& list_ctrl{ section_well_id_->list_control() };
	
	string str{ test->key.uwi.full_dressed() };
	wstring wstr{ str.cbegin(), str.cend() };
	list_ctrl.SetItemText( 0, 1, wstr.c_str() );

	str = std::to_string( test->key.consol_interval_num );
	wstr = { str.cbegin(), str.cend() };
	list_ctrl.SetItemText( 0, 4, wstr.c_str() );

	list_ctrl.SetItemText( 1, 1, _T( "Hoola Hoop" ) );
	list_ctrl.SetItemText( 1, 4, _T( "7 Sep 2019" ) );

}

BOOL CTicketView::PreCreateWindow(CREATESTRUCT& cs)
{
   // TODO: Modify the Window class or styles here by modifying
   //  the CREATESTRUCT cs

   return CView::PreCreateWindow(cs);
}

int CTicketView::OnCreate( LPCREATESTRUCT lpCreateStruct )
{
   if( __super::OnCreate( lpCreateStruct ) == -1 )
      return -1;

   if( !section_well_id_panel_->Create( _T( "" ), WS_VISIBLE | WS_BORDER, CRect{ 10,10, 500,500 }, this, section_well_id_id_ ) )
   {
      return FALSE;
   }
	section_well_id_panel_->SetBackgroundColor( RGB( 255, 255, 255 ) );
	
	if( !section_well_id_->Create( IDD_TICKET_SECTION, &(*section_well_id_panel_) ) )
   {
      return FALSE;
   }
	   section_well_id_->title( "WELL ID" );
   TicketSectionListCtrl& list_ctrl{ section_well_id_->list_control() };
   list_ctrl.InsertColumn( 0, _T("label0"), LVCFMT_RIGHT );
   list_ctrl.InsertColumn( 1, _T("value0"), LVCFMT_LEFT);
   list_ctrl.InsertColumn( 2, _T( "padding" ), LVCFMT_LEFT, 10);
   list_ctrl.InsertColumn( 3, _T( "label1" ), LVCFMT_RIGHT );
   list_ctrl.InsertColumn( 4, _T( "value1" ), LVCFMT_LEFT );

   LVCOLUMNW lvc{};
   lvc.mask = LVCF_FMT;
   lvc.fmt = LVCFMT_RIGHT;
   list_ctrl.SetColumn( 0, &lvc );

   list_ctrl.InsertItem( 0, _T( "UWI:" ) );
   list_ctrl.SetItemText( 0, 1, _T( "100/01-01-001-01W1/00" ));

   list_ctrl.SetItemText( 0, 3, _T( "Consol Interval:" ) );
   list_ctrl.SetItemText( 0, 4, _T( "1" ) );

   list_ctrl.InsertItem( 1, _T( "Well Name:" ) );
   list_ctrl.SetItemText( 1, 1, _T( "Hoola Hoop" ) );

   list_ctrl.SetItemText( 1, 3, _T( "On Production Date:" ) );
   list_ctrl.SetItemText( 1, 4, _T( "7 Sep 2019" ) );

   list_ctrl.SetColumnWidth( 0, LVSCW_AUTOSIZE );
   list_ctrl.SetColumnWidth( 1, LVSCW_AUTOSIZE );
   list_ctrl.SetColumnWidth( 3, LVSCW_AUTOSIZE );
   list_ctrl.SetColumnWidth( 4, LVSCW_AUTOSIZE );



	list_ctrl.cell_text_color( 0, 0, RGB( 100, 100, 100 ) );
	list_ctrl.cell_text_color( 0, 3, RGB( 100, 100, 100 ) );
	list_ctrl.cell_text_color( 1, 0, RGB( 100, 100, 100 ) );
	list_ctrl.cell_text_color( 1, 3, RGB( 100, 100, 100 ) );
	return 0;
}


void CTicketView::OnDraw(CDC* /*pDC*/)
{
   CABOilPressTestDoc* pDoc = GetDocument();
   ASSERT_VALID(pDoc);
   if (!pDoc)
      return;

   // TODO: add draw code for native data here
}


// CABOilPressTestView printing


void CTicketView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
   AFXPrintPreview(this);
#endif
}

BOOL CTicketView::OnPreparePrinting(CPrintInfo* pInfo)
{
   // default preparation
   return DoPreparePrinting(pInfo);
}

void CTicketView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
   // TODO: add extra initialization before printing
}

void CTicketView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
   // TODO: add cleanup after printing
}

void CTicketView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
   ClientToScreen(&point);
   OnContextMenu(this, point);
}

void CTicketView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
   theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CABOilPressTestView diagnostics

#ifdef _DEBUG
void CTicketView::AssertValid() const
{
   CView::AssertValid();
}

void CTicketView::Dump(CDumpContext& dc) const
{
   CView::Dump(dc);
}

CABOilPressTestDoc* CTicketView::GetDocument() const // non-debug version is inline
{
   ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CABOilPressTestDoc)));
   return (CABOilPressTestDoc*)m_pDocument;
}
#endif //_DEBUG


// CABOilPressTestView message handlers


