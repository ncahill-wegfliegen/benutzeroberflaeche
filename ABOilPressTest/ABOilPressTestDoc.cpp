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
#include "ABOilPressTest.h"
#endif

#include "ABOilPressTestDoc.h"
#include "well_list_changed_event_args.h"
#include "../../dev/gemeinsam/uwi/dls.h"

#include <propkey.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

using namespace std;

IMPLEMENT_DYNCREATE(CABOilPressTestDoc, CDocument)

BEGIN_MESSAGE_MAP(CABOilPressTestDoc, CDocument)
	ON_COMMAND( ID_WELL_LIST_OPEN, &CABOilPressTestDoc::OnWellListOpen )
	ON_UPDATE_COMMAND_UI( ID_WELL_LIST_OPEN, &CABOilPressTestDoc::OnUpdateWellListOpen )
END_MESSAGE_MAP()


// CABOilPressTestDoc construction/destruction

CABOilPressTestDoc::CABOilPressTestDoc() noexcept
	: m_uwiList{make_unique<nhill::uwi::List>()}
	, m_curUwi{ nullptr }
{
}

CABOilPressTestDoc::~CABOilPressTestDoc()
{
}

void CABOilPressTestDoc::on_well_changed( const nhill::Well_changed_event_args& event_args )
{
	const nhill::Uwi& uwi{ event_args.uwi };
	m_curUwi = make_unique<nhill::uwi::Dls>( nhill::uwi::dls::parse_sort( uwi.value() ) );

	// Get the test(s) for this uwi;

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

	m_uwiList->clear();
	m_uwiList->load( static_cast<const char*>(path) );

	notify_well_list_changed( { *m_uwiList } );
}

void CABOilPressTestDoc::OnUpdateWellListOpen( CCmdUI* pCmdUI )
{
	pCmdUI->Enable( TRUE );
}
