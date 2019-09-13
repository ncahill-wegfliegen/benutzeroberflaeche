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
#include "../../dev/datenzugriff/ab_oil_pressure_test/ab_oil_pressure_test/test_container.h"
#include <memory>

namespace nhill
{
class Uwi;
namespace uwi
{
class Dls;
class List;
}

namespace datenzugriff
{
namespace ab_oil_pressure_test
{
class Facade;
}
}
}

class CABOilPressTestDoc : public CDocument, public nhill::Doc_subject, public nhill::Well_observer
{
public:
   using Facade = nhill::datenzugriff::ab_oil_pressure_test::Facade;
   using Uwi_list = nhill::uwi::List;
   using Dls = nhill::uwi::Dls;
   using Test_container = nhill::datenzugriff::ab_oil_pressure_test::Test_container;
   using Test = nhill::datenzugriff::ab_oil_pressure_test::Test;

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

   /// <summary>The data facade for getting the tests.</summary>
   std::unique_ptr<Facade> facade_;
   /// <summary>The Document's UWI list.</summary>
   std::unique_ptr<Uwi_list> uwis_;
   /// <summary>The currently selected UWI. The DLS UWI of one of the UWIs in the Document's UWI list.</summary>
   /// <remarks>Null if there is no currently selected UWI.</remarks>
   std::unique_ptr<Dls> uwi_current_;
   /// <summary>The current collection of tests associated with the currently selected UWI.</summary>
   std::unique_ptr<Test_container> tests_;
   /// <summary>The currently selected test.  A pointer to one of the tests in the Document's test list.</summary>
   /// <remarks>Null of there is no currently selected test.</remarks>
   /// <remarks>Never allocated. Do not delete!</remarks>
   const Test* test_current_;


   void on_well_changed( const nhill::Well_changed_event_args& event_args ) final;


   afx_msg void OnWellListOpen();
   afx_msg void OnUpdateWellListOpen( CCmdUI* pCmdUI );
   DECLARE_MESSAGE_MAP()

#ifdef SHARED_HANDLERS
   // Helper function that sets search content for a Search Handler
   void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS
};
