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
#include "../ab_oil_pressure_test_ui/ticket_property.h"
#include "../ab_oil_pressure_test_ui/xml_ticket_property.h"
#include "../../../gemeinsam/uwi/dls.h"
#include "../../../datenzugriff/ab_oil_pressure_test/ab_oil_pressure_test/facade.h"

#include <propkey.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

using namespace std;
using namespace nhill;
using namespace nhill::ctrl;
using namespace nhill::ctrl::ab_oil_pressure_test_ui;

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
	, ticket_property_{make_unique<Ticket_property>()}
{
	(*ticket_property_).clear();
}

CABOilPressTestDoc::~CABOilPressTestDoc() = default;

const Ticket_property& CABOilPressTestDoc::ticket_property() const
{
	return *ticket_property_;
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

   // Tell everyone that a new test has been selected.
	notify_test_changed( test_current_ );
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


	//xml::read(*ticket_property, )
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
