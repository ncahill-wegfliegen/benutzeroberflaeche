#pragma once

#include "doc_observer.h"
#include "well_subject.h"
#include <memory>

namespace nhill
{
class Uwi;
namespace uwi
{
class List;
}
}

class CWellListBox : public CListBox
{
public:
   CWellListBox() noexcept;
   virtual ~CWellListBox();

   bool Load( const nhill::uwi::List& uwi_list );
   /// <summary>A reference to a UWI in the Document's UWI list.</summary>
   const nhill::Uwi& GetCurUwi() const;


   DECLARE_MESSAGE_MAP()
};

class CWellListPane : public CDockablePane, public nhill::Well_subject, public nhill::Doc_observer
{
public:
   CWellListPane() noexcept;
   virtual ~CWellListPane();


   void UpdateFonts();

protected:
   CWellListBox m_wellListBox;
   CFont m_font;
   static constexpr int m_idWellListBox{ 2 };

   void on_well_list_changed( const nhill::Well_list_changed_event_args& event_args ) final;
   void on_test_changed( const nhill::Test_changed_event_args& event_args ) final;

   void FillCtrl();

   void AdjustHorzScroll( CListBox& wndListBox );

   afx_msg int OnCreate( LPCREATESTRUCT lpCreateStruct );
   afx_msg void OnSize( UINT nType, int cx, int cy );
   afx_msg void OnWellListBoxSelectionChanged();

   DECLARE_MESSAGE_MAP()
};

