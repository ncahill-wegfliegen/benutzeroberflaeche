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

// ABOilPressTestDoc.cpp : implementation of the CABOilPressTestDoc class
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "ab_oil_pressure_test_app.h"
#endif

#include "ab_oil_pressure_test_doc.h"
#include "MainFrm.h"
#include "well_list_changed_event_args.h"
#include "../ab_oil_pressure_test_ui/ticket.h"
#include "../ab_oil_pressure_test_ui/xml_ticket.h"
#include "../../../gemeinsam/uwi/dls.h"
#include "../../../gemeinsam/utility/str.h"
#include "../../../datenzugriff/ab_oil_pressure_test/ab_oil_pressure_test/facade.h"
#include "../../../datenzugriff/ab_oil_pressure_test/ab_oil_pressure_test/test_type_ex.h"

#include <propkey.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

using namespace std;
using namespace nhill;
using namespace nhill::ctrl;
using namespace nhill::ctrl::ab_oil_pressure_test_ui;
using namespace nhill::datenzugriff::ab_oil_pressure_test;

IMPLEMENT_DYNCREATE(CABOilPressTestDoc, CDocument)

BEGIN_MESSAGE_MAP(CABOilPressTestDoc, CDocument)
   ON_COMMAND( ID_WELL_LIST_OPEN, &CABOilPressTestDoc::OnWellListOpen )
   ON_UPDATE_COMMAND_UI( ID_WELL_LIST_OPEN, &CABOilPressTestDoc::OnUpdateWellListOpen )
	//
	ON_COMMAND( ID_PROPERTY_OPEN, &CABOilPressTestDoc::OnPropertyOpen )
	ON_UPDATE_COMMAND_UI( ID_PROPERTY_OPEN, &CABOilPressTestDoc::OnUpdatePropertyOpen )
	//
	ON_COMMAND( ID_PROPERTY_SAVE, &CABOilPressTestDoc::OnPropertySave )
	ON_UPDATE_COMMAND_UI( ID_PROPERTY_SAVE, &CABOilPressTestDoc::OnUpdatePropertySave )
END_MESSAGE_MAP()

CABOilPressTestDoc::CABOilPressTestDoc() noexcept
   : facade_{ make_unique<Facade>()}
   , uwis_{make_unique<nhill::uwi::List>()}
   , uwi_current_{ nullptr }
   , tests_{ make_unique<Test_container>()}
   , test_current_{nullptr}
	, ticket_{make_unique<Ticket>()}
{
	ticket().clear();
}

CABOilPressTestDoc::~CABOilPressTestDoc() = default;

Ticket& CABOilPressTestDoc::ticket() const
{
	return *ticket_;
}

void CABOilPressTestDoc::on_well_changed( const nhill::Well_changed_event_args& event_args )
{
   // Remove all of the current tests
   tests_->clear();

   // The currently selected UWI
   const nhill::Uwi* uwi{ event_args.uwi };
   if( uwi == nullptr )
   {
      // No well selected
      uwi_current_ = nullptr;
   }
   else
   {
      // Convert to DLS format
      Dls dls{ nhill::uwi::dls::parse_sort( uwi->value() ) };
      // If the new uwi is the same as the current uwi, then don't do anything
      if( uwi_current_ != nullptr && *uwi_current_ == dls )
      {
         return;
      }
      // Change to the new uwi
      if( uwi_current_ == nullptr )
      {
         // Create and copy the new uwi
         uwi_current_ = make_unique<Dls>( dls );
      }
      else
      {
         // Copy the new uwi
         *uwi_current_ = dls;
      }
      // Get the test(s) for this uwi;
      *tests_ = facade_->find_test_by_uwi( *uwi_current_ );
   }

   // Set the currently selected test
   if( tests_->size() == 0 )
   {
      // No test selected
      test_current_ = nullptr;
   }
   else
   {
      test_current_ = &(tests_->front());
   }

	// Set the test values
	Ticket00& ticket00{ ticket_->ticket00 };
	Ticket01& ticket01{ ticket_->ticket01 };
	Ticket02& ticket02{ ticket_->ticket02 };
	Ticket03& ticket03{ ticket_->ticket03 };
	std::vector<Ticket04>& ticket04c{ ticket_->ticket04c };
	std::vector<Ticket05>& ticket05c{ ticket_->ticket05c };

	if( test_current_ == nullptr )
	{
		ticket().clear_value_text();
	}
	else
	{
		ticket00.uwi.value.text = test_current_->key.uwi.full_dressed();
		ticket00.consol_interval_num.value.text = to_string(test_current_->key.consol_interval_num);
		ticket00.well_name.value.text = test_current_->rec00.well_name;
		ticket00.on_production_date.value.text = to_string( test_current_->rec00.on_production_date, "%Y %b %d" );

		ticket01.licensee.value.text = test_current_->rec01.licensee_abbrev;
		if( !test_current_->rec01.licensee_code.empty() )
		{
			ticket01.licensee.value.text.append( " (" ).append( test_current_->rec01.licensee_code ).append( ")" );
		}
		ticket01.survey_coord.value.text = test_current_->rec01.survey_coord_abbrev ;
		if( !test_current_->rec01.survey_coord_oper_code.empty() )
		{
			ticket01.survey_coord.value.text.append( " (" ).append( test_current_->rec01.survey_coord_oper_code ).append( ")" );
		}
		ticket01.well_status.value.text = to_string( test_current_->rec01.well_status_date, "%Y %b %d" );
		if( !test_current_->rec01.well_status_code.empty() )
		{
			ticket01.well_status.value.text.append( " (" ).append( test_current_->rec01.well_status_code ).append( ")" );
		}

		ticket02.field_name.value.text = test_current_->rec02.field_name;
		ticket02.field_name.value.text.append( " (" ).append( test_current_->rec03.field_code ).append( ")" );
		ticket02.pool_name.value.text = test_current_->rec02.pool_name;
		ticket02.pool_name.value.text.append( " (" ).append( test_current_->rec03.pool_code ).append( ")" );

		ticket03.consol_interval_top.value.text = nhill::str::string_format( Ticket03::default_format_consol_interval_top, test_current_->rec03.consol_interval_top );
		ticket03.consol_interval_bottom.value.text = nhill::str::string_format( Ticket03::default_format_consol_interval_bottom, test_current_->rec03.consol_interval_bottom );
		ticket03.kb_elevation.value.text = nhill::str::string_format( Ticket03::default_format_kb_elevation, test_current_->rec03.kb_elevation );
		ticket03.pool_datum_depth.value.text = nhill::str::string_format( Ticket03::default_format_pool_datum_depth, test_current_->rec03.pool_datum_depth );
		ticket03.ground_elevation.value.text = nhill::str::string_format( Ticket03::default_format_ground_elevation, test_current_->rec03.ground_elevation );
		ticket03.well_datum_depth.value.text = nhill::str::string_format( Ticket03::default_format_well_datum_depth, test_current_->rec03.well_datum_depth );
		ticket03.initial_pool_pressure.value.text = nhill::str::string_format( Ticket03::default_format_initial_pool_pressure, test_current_->rec03.initial_pool_pressure );
		ticket03.reservoir_gradient.value.text = nhill::str::string_format( Ticket03::default_format_reservoir_gradient, test_current_->rec03.reservoir_gradient );

		ticket04c.clear();
		for( const Record04& rec04 : test_current_->rec04c )
		{
			Ticket04 ticket04;
			ticket04.clear();

			ticket04.test_date.value.text = to_string( rec04.test_date, "%Y %b %d" );
			ticket04.test_type.value.text = to_string( rec04.test_type );
			ticket04.historical_well_status.value.text = to_string( rec04.historical_well_status_date, "%Y %b %d" );
			if( !rec04.historical_well_status_code.empty() )
			{
				ticket04.historical_well_status.value.text.append( " (" ).append( rec04.historical_well_status_code ).append( ")" );
			}
			ticket04.casing_pressure.value.text = nhill::str::string_format( Ticket04::default_format_casing_pressure, rec04.casing_pressure );
			ticket04.mpp_depth.value.text = nhill::str::string_format( Ticket04::default_format_mpp_depth, rec04.mpp_depth );
			ticket04.gauge_run_depth.value.text = nhill::str::string_format( Ticket04::default_format_gauge_run_depth, rec04.gauge_run_depth );
			ticket04.run_depth_gradient.value.text = nhill::str::string_format( Ticket04::default_format_run_depth_gradient, rec04.run_depth_gradient );
			ticket04.run_depth_pressure.value.text = nhill::str::string_format( Ticket04::default_format_run_depth_pressure, rec04.run_depth_pressure );
			ticket04.reservoir_temperature.value.text = nhill::str::string_format( Ticket04::default_format_reservoir_temperature, rec04.reservoir_temperature );
			ticket04.initial_liquid_level.value.text = nhill::str::string_format( Ticket04::default_format_initial_liquid_level, rec04.initial_liquid_level );
			ticket04.final_liquid_level.value.text = nhill::str::string_format( Ticket04::default_format_final_liquid_level, rec04.final_liquid_level );
			ticket04.gas_gradient.value.text = nhill::str::string_format( Ticket04::default_format_gas_gradient, rec04.gas_gradient );
			ticket04.oil_gradient.value.text = nhill::str::string_format( Ticket04::default_format_oil_gradient, rec04.oil_gradient );
			ticket04.water_gradient.value.text = nhill::str::string_format( Ticket04::default_format_water_gradient, rec04.water_gradient );
			ticket04.mpp_pressure.value.text = nhill::str::string_format( Ticket04::default_format_mpp_pressure, rec04.mpp_pressure );
			ticket04.datum_depth_pressure.value.text = nhill::str::string_format( Ticket04::default_format_datum_depth_pressure, rec04.datum_depth_pressure );
			ticket04.extrapolated_pressure_indicator.value.text = rec04.extrapolated_pressure_indicator;
			ticket04.extrapolated_mpp_pressure.value.text = nhill::str::string_format( Ticket04::default_format_extrapolated_mpp_pressure, rec04.extrapolated_mpp_pressure );
			ticket04.extrapolated_datum_depth_pressure.value.text = nhill::str::string_format( Ticket04::default_format_extrapolated_datum_depth_pressure, rec04.extrapolated_datum_depth_pressure );
			ticket04.shut_in_period.value.text = nhill::str::string_format( Ticket04::default_format_shut_in_period, rec04.shut_in_period );

			ticket04c.push_back( ticket04 );
		}

		ticket05c.clear();
		for( const Record05& rec05 : test_current_->rec05c )
		{
			Ticket05 ticket05;
			ticket05.clear();

			ticket05.remark.value.text = rec05.remark;

			ticket05c.push_back( ticket05 );
		}
	}

   // Tell everyone that a new test has been selected.
	notify_test_changed( test_current_ );

	UpdateAllViews(nullptr);
}

BOOL CABOilPressTestDoc::OnNewDocument()
{
   if (!CDocument::OnNewDocument())
      return FALSE;

   // TODO: add reinitialization code here
   // (SDI documents will reuse this document)

   return TRUE;
}




// CABOilPressTestDoc serialization

void CABOilPressTestDoc::Serialize(CArchive& ar)
{
   if (ar.IsStoring())
   {
      // TODO: add storing code here
   }
   else
   {
      // TODO: add loading code here
   }
}

#ifdef SHARED_HANDLERS

// Support for thumbnails
void CABOilPressTestDoc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
{
   // Modify this code to draw the document's data
   dc.FillSolidRect(lprcBounds, RGB(255, 255, 255));

   CString strText = _T("TODO: implement thumbnail drawing here");
   LOGFONT lf;

   CFont* pDefaultGUIFont = CFont::FromHandle((HFONT) GetStockObject(DEFAULT_GUI_FONT));
   pDefaultGUIFont->GetLogFont(&lf);
   lf.lfHeight = 36;

   CFont fontDraw;
   fontDraw.CreateFontIndirect(&lf);

   CFont* pOldFont = dc.SelectObject(&fontDraw);
   dc.DrawText(strText, lprcBounds, DT_CENTER | DT_WORDBREAK);
   dc.SelectObject(pOldFont);
}

// Support for Search Handlers
void CABOilPressTestDoc::InitializeSearchContent()
{
   CString strSearchContent;
   // Set search contents from document's data.
   // The content parts should be separated by ";"

   // For example:  strSearchContent = _T("point;rectangle;circle;ole object;");
   SetSearchContent(strSearchContent);
}

void CABOilPressTestDoc::SetSearchContent(const CString& value)
{
   if (value.IsEmpty())
   {
      RemoveChunk(PKEY_Search_Contents.fmtid, PKEY_Search_Contents.pid);
   }
   else
   {
      CMFCFilterChunkValueImpl *pChunk = nullptr;
      ATLTRY(pChunk = new CMFCFilterChunkValueImpl);
      if (pChunk != nullptr)
      {
         pChunk->SetTextValue(PKEY_Search_Contents, value, CHUNK_TEXT);
         SetChunkValue(pChunk);
      }
   }
}

#endif // SHARED_HANDLERS

// CABOilPressTestDoc diagnostics

#ifdef _DEBUG
void CABOilPressTestDoc::AssertValid() const
{
   CDocument::AssertValid();
}

void CABOilPressTestDoc::Dump(CDumpContext& dc) const
{
   CDocument::Dump(dc);
}
#endif //_DEBUG


// CABOilPressTestDoc commands
void CABOilPressTestDoc::OnWellListOpen()
{
   CFileDialog dlg{ TRUE };
   dlg.m_ofn.Flags |= OFN_FILEMUSTEXIST;
   dlg.m_ofn.lpstrFilter = _T( "Bemühen Well List Files (*.bwl)\0*.bwl\0All Files (*.*)\0*.*\0\0" ); // filter

   if( dlg.DoModal() == IDCANCEL )
   {
      return;
   }

   CStringA path{ dlg.GetPathName() };

   uwis_->clear();
   size_t count{ uwis_->load( static_cast<const char*>(path) ) };

   if( count == 0 )
   {
      string test{ "The file '" + path + "' does not contain any Unique Well Identifiers." };
      ::MessageBoxA( ::AfxGetMainWnd()->GetSafeHwnd(), test.c_str(), "No Wells Loaded", MB_ICONEXCLAMATION | MB_OK );
      return;
   }

   notify_well_list_changed( { *uwis_ } );
}

void CABOilPressTestDoc::OnUpdateWellListOpen( CCmdUI* pCmdUI )
{
   pCmdUI->Enable( TRUE );
}

void CABOilPressTestDoc::OnPropertyOpen()
{
	CMainFrame* main_frame{ dynamic_cast<CMainFrame*>(::AfxGetMainWnd()) };

	CFileDialog dlg{ TRUE };
	dlg.m_ofn.Flags |= (OFN_FILEMUSTEXIST | OFN_PATHMUSTEXIST);
	dlg.m_ofn.lpstrFilter = _T( "ABOPT TicketProperty (*.tkp)\0*.tkp\0All Files (*.*)\0*.*\0\0" ); // filter
	dlg.m_ofn.hwndOwner = main_frame->GetSafeHwnd();

	if( dlg.DoModal() != IDOK )
	{
		return;
	}


	//xml::read(*ticket, )
}

void CABOilPressTestDoc::OnUpdatePropertyOpen( CCmdUI* pCmdUI )
{
	pCmdUI->Enable( TRUE );
}

void CABOilPressTestDoc::OnPropertySave()
{
	CMainFrame* main_frame{ dynamic_cast<CMainFrame*>(::AfxGetMainWnd()) };

	CFileDialog dlg{ FALSE };
	dlg.m_ofn.Flags |= (OFN_PATHMUSTEXIST);
	dlg.m_ofn.lpstrFilter = _T( "ABOPT TicketProperty (*.tkp)\0*.tkp\0All Files (*.*)\0*.*\0\0" ); // filter
	dlg.m_ofn.hwndOwner = main_frame->GetSafeHwnd();

	if( dlg.DoModal() != IDOK )
	{
		return;
	}
}

void CABOilPressTestDoc::OnUpdatePropertySave( CCmdUI* pCmdUI )
{
	pCmdUI->Enable( TRUE );
}
