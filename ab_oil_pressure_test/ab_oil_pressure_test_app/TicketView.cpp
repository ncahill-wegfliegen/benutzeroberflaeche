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
#include "../ab_oil_pressure_test_ui/ticket.h"
#include "../ab_oil_pressure_test_ui/ticket00.h"
#include "../ab_oil_pressure_test_ui/ticket01.h"
#include "../ab_oil_pressure_test_ui/resource.h"
#include "../../user_control/grid_helper.h"
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
	: grid00_{nullptr}
	, grid01_{ nullptr }
	, grid02_{ nullptr }
	, grid03_{ nullptr }
	, grid04c_{ nullptr }
	, grid05c_{ nullptr }
{
}

CTicketView::~CTicketView()
{
}

#ifdef _DEBUG
void CTicketView::AssertValid() const
{
	CView::AssertValid();
}

void CTicketView::Dump( CDumpContext& dc ) const
{
	CView::Dump( dc );
}

CABOilPressTestDoc* CTicketView::GetDocument() const // non-debug version is inline
{
	ASSERT( m_pDocument->IsKindOf( RUNTIME_CLASS( CABOilPressTestDoc ) ) );
	return (CABOilPressTestDoc*)m_pDocument;
}
#endif //_DEBUG

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

	// Get the properties from the document
	Ticket& ticket{ GetDoc()->ticket() };
	Block_ptr_container block_ptrs;

	grid04c_ = make_unique<vector<Grid>>();
	for( auto&& ticket04 : ticket.ticket04c )
	{
		block_ptrs = ticket04.block_ptrs();
		grid04c_->push_back( to_grid( block_ptrs ) );
	}

	if( 0 < ticket.ticket05c.size() )
	{
		grid05c_ = make_unique<vector<Grid>>();
		for( auto&& ticket05 : ticket.ticket05c )
		{
			block_ptrs = ticket05.block_ptrs();
			grid05c_->push_back( to_grid( block_ptrs ) );
		}
	}

	// Force the view to redraw
	Invalidate();
	UpdateWindow();
}

BOOL CTicketView::PreCreateWindow(CREATESTRUCT& cs)
{
   // TODO: Modify the Window class or styles here by modifying
   //  the CREATESTRUCT cs

   return CView::PreCreateWindow(cs);
}

void CTicketView::OnInitialUpdate()
{
	__super::OnInitialUpdate();

	// Get the properties from the document
	Ticket& ticket{ GetDoc()->ticket() };

	Block_ptr_container block_ptrs{ ticket.ticket00.block_ptrs() };
	grid00_ = make_unique<Grid>( to_grid( block_ptrs ) );

	block_ptrs = ticket.ticket01.block_ptrs();
	grid01_ = make_unique<Grid>( to_grid( block_ptrs ) );

	block_ptrs = ticket.ticket02.block_ptrs();
	grid02_ = make_unique<Grid>( to_grid( block_ptrs ) );

	block_ptrs = ticket.ticket03.block_ptrs();
	grid03_ = make_unique<Grid>( to_grid( block_ptrs ) );

	// 4 and 5 are handled in on_test_changed handler
	grid04c_ = nullptr;
	grid05c_ = nullptr;

}


void CTicketView::OnUpdate( CView* /*pSender*/, LPARAM /*lHint*/, CObject* /*pHint*/ )
{
}

void CTicketView::OnDraw( CDC* dc )
{
	CABOilPressTestDoc* doc = GetDocument();
	ASSERT_VALID( doc );
	if( !doc )
		return;

	if( !grid00_ || !grid01_ )
	{
		return;
	}


	long top{ 10 };
	long left{ 10 };
	long pad_top{ 5 };
	long pad_left{ 5 };

	auto_size( *grid00_, *dc );
	normalize_size( *grid00_ );
	top = layout( *grid00_, top, left, pad_top, pad_left );
	top += 2*pad_top;
	draw( *grid00_, *dc );

	auto_size( *grid01_, *dc );
	normalize_size( *grid01_ );
	top = layout( *grid01_, top, left, pad_top, pad_left );
	top += 2 * pad_top;
	draw( *grid01_, *dc );

	auto_size( *grid02_, *dc );
	normalize_size( *grid02_ );
	top = layout( *grid02_, top, left, pad_top, pad_left );
	top += 2 * pad_top;
	draw( *grid02_, *dc );

	auto_size( *grid03_, *dc );
	normalize_size( *grid03_ );
	top = layout( *grid03_, top, left, pad_top, pad_left );
	top += 2 * pad_top;
	draw( *grid03_, *dc );

	if( grid04c_ != nullptr )
	{
		for( auto&& grid04 : *grid04c_ )
		{
			auto_size( grid04, *dc );
			normalize_size( grid04 );
			top = layout( grid04, top, left, pad_top, pad_left );
			top += 2 * pad_top;
			draw( grid04, *dc );
		}
	}

	//if( grid05c_ != nullptr )
	//{
	//	for( auto&& grid05 : *grid05c_ )
	//	{
	//		auto_size( grid05, *dc );
	//		normalize_size( grid05 );
	//		top = layout( grid05, top, left, pad_top, pad_left );
	//		top += 2 * pad_top;
	//		draw( grid05, *dc );
	//	}
	//}
}


BOOL CTicketView::OnPreparePrinting( CPrintInfo* pInfo )
{
	// default preparation
	return DoPreparePrinting( pInfo );
}

void CTicketView::OnBeginPrinting( CDC* /*pDC*/, CPrintInfo* /*pInfo*/ )
{
	// TODO: add extra initialization before printing
}

void CTicketView::OnEndPrinting( CDC* /*pDC*/, CPrintInfo* /*pInfo*/ )
{
	// TODO: add cleanup after printing
}


int CTicketView::OnCreate( LPCREATESTRUCT lpCreateStruct )
{
	if( __super::OnCreate( lpCreateStruct ) == -1 )
		return -1;

	return 0;
}

void CTicketView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
   AFXPrintPreview(this);
#endif
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



// CABOilPressTestView message handlers




