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
#include "ab_oil_pressure_test_app.h"
#endif

#include "ab_oil_pressure_test_doc.h"
#include "TicketView.h"
#include "Helper.h"
#include "../ab_oil_pressure_test_ui/config.h"

#include "../ab_oil_pressure_test_ui/ticket_section.h"
#include "../ab_oil_pressure_test_ui/ticket_property.h"
#include "../ab_oil_pressure_test_ui/ticket00.h"
#include "../ab_oil_pressure_test_ui/resource.h"
#include "../../user_control/user_control_panel.h"
#include "../../../datenzugriff/ab_oil_pressure_test/ab_oil_pressure_test/test.h"
#include "../../../gemeinsam/utility/str.h"

#include <wchar.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

using namespace std;
using namespace nhill;
using namespace nhill::ctrl;
using namespace nhill::ctrl::ab_oil_pressure_test_ui;
using namespace nhill::datenzugriff::ab_oil_pressure_test;

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
   : section_well_id_{make_unique<TicketSection>(Record_type::well_id)}
   , section_well_id_panel_{ make_unique<nhill::ctrl::User_control_panel>(&(*section_well_id_)) }
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

	const Configuration& config{ Configuration::instance() };

	// Get the properties from the document
	const Ticket_property& ticket_property{ GetDoc()->ticket_property() };
	// Get the properties for the 00 (well id) section
	const Ticket_property00& prop00{ ticket_property.ticket_property00 };

   // Display the ticket for the new test.
	TicketSectionListCtrl& list_ctrl{ section_well_id_->list_control() };
	
	string str{ test->key.uwi.full_dressed() };
	wstring wstr{ str.cbegin(), str.cend() };
	list_ctrl.SetItemText( prop00.uwi_value.row, prop00.uwi_value.col, wstr.c_str() );

	str = std::to_string( test->key.consol_interval_num );
	wstr = { str.cbegin(), str.cend() };
	list_ctrl.SetItemText( prop00.consol_interval_num_value.row, prop00.consol_interval_num_value.col, wstr.c_str() );

	str = test->rec00.well_name;
	wstr = { str.cbegin(), str.cend() };
	list_ctrl.SetItemText( prop00.well_name_value.row, prop00.well_name_value.col, wstr.c_str() );

	str = str::trim_start( to_string( test->rec00.on_production_date, "%e %b %Y" ) );
	wstr = { str.cbegin(), str.cend() };
	list_ctrl.SetItemText( prop00.on_production_date_value.row, prop00.on_production_date_value.col, wstr.c_str() );

	list_ctrl.SetColumnWidth( 0, LVSCW_AUTOSIZE );
	list_ctrl.SetColumnWidth( 1, LVSCW_AUTOSIZE );
	list_ctrl.SetColumnWidth( 2, LVSCW_AUTOSIZE );
	list_ctrl.SetColumnWidth( 3, LVSCW_AUTOSIZE );

	CDC* dc{ list_ctrl.GetDC() };
	dc->SelectObject( ::CreateFontIndirect( &prop00.uwi_label.logfont) );

	str = prop00.uwi_label.text;
	wstr = { str.cbegin(), str.cend() };
	//CSize sz{ dc->GetTextExtent( prop00.uwi_label.text().c_str(), prop00.uwi_label.text().size() ) };
	
	
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



	//LOGFONT lf{};
	//lf.lfHeight = -14;
	//lf.lfWeight = FW_BOLD;
	//wcscpy_s( lf.lfFaceName, L"Arial" );

	//font_section_title_.CreateFontIndirect( &lf );

	//ZeroMemory( &lf, sizeof( LOGFONT ) );
	//lf.lfHeight = -12;
	//_tcscpy_s( lf.lfFaceName, _T( "Verdana" ) );

   if( !section_well_id_panel_->Create( _T( "" ), WS_VISIBLE | WS_BORDER, CRect{ 10,10, 750, 250 }, this, section_well_id_id_ ) )
   {
      return FALSE;
   }
	section_well_id_panel_->background_color( RGB( 255, 255, 255 ) );
	
	if( !section_well_id_->Create( IDD_ABOPT_UI_TICKET_SECTION, &(*section_well_id_panel_) ) )
   {
      return FALSE;
   }
   section_well_id_->title( "WELL ID" );

	return 0;
}


void CTicketView::OnDraw(CDC* dc)
{
   CABOilPressTestDoc* doc = GetDocument();
   ASSERT_VALID( doc );
   if (!doc )
      return;



	//CFont* font_old{ dc->SelectObject(&font_section_title_) };

	//int x{ 10 };
	//int y{ 10 };
	//dc->TextOut( 10, 10, _T("WELL ID") );
	//CSize sz{ dc->GetTextExtent( _T( "WELL ID" ) ) };

	//y += sz.cy;

	//dc->SelectObject( &font_label_ );
	//dc->SetTextColor( RGB( 125, 125, 125 ) );
	//dc->TextOut( x, y, _T( "UWI" ) );

	//dc->SelectObject( font_old );

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


