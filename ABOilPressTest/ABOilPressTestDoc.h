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

// ABOilPressTestDoc.h : interface of the CABOilPressTestDoc class
//


#pragma once

#include "doc_subject.h"
#include "well_observer.h"
#include <memory>

namespace nhill
{
class Uwi;
namespace uwi
{
class Dls;
class List;
}
}

class CABOilPressTestDoc : public CDocument, public nhill::Doc_subject, public nhill::Well_observer
{
public:
	void on_well_changed( const nhill::Well_changed_event_args& event_args ) final;

	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

	virtual ~CABOilPressTestDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:
	CABOilPressTestDoc() noexcept; // create from serialization only
	DECLARE_DYNCREATE( CABOilPressTestDoc )

	/// <summary>The Document's UWI list.</summary>
	std::unique_ptr<nhill::uwi::List> m_uwiList;
	/// <summary>The currently selected UWI.</summary>
	std::unique_ptr<nhill::uwi::Dls> m_curUwi;

	afx_msg void OnWellListOpen();
	afx_msg void OnUpdateWellListOpen( CCmdUI* pCmdUI );
	DECLARE_MESSAGE_MAP()

#ifdef SHARED_HANDLERS
	// Helper function that sets search content for a Search Handler
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS
};