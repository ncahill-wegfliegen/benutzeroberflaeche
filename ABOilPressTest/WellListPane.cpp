#include "pch.h"
#include "framework.h"
#include "WellListPane.h"
#include "Resource.h"
#include "MainFrm.h"
#include "Helper.h"
#include "ABOilPressTestDoc.h"
#include "../../dev/gemeinsam/uwi/list.h"
#include "../../dev/gemeinsam/uwi/dls.h"

using namespace std;

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif


#pragma region Well List Box
CWellListBox::CWellListBox() noexcept
{
}

CWellListBox::~CWellListBox()
{
}

bool CWellListBox::Load( const nhill::uwi::List& uwi_list )
{
	CListBox::ResetContent();

	for( const auto& uwi : uwi_list )
	{
		string s;
		switch( uwi.survey_system() )
		{
		case nhill::Survey_system::dls:
		{
			nhill::uwi::Dls dls{ nhill::uwi::dls::parse_sort( uwi.value() ) };
			s = dls.full_dressed();
			break;
		}
		}
		wstring w{ s.cbegin(), s.cend() };
		int index{ CListBox::AddString( w.c_str() ) };
		CListBox::SetItemDataPtr( index, (void*)(&uwi)); // points to a UWI in the Document's UWI list.
	}

	bool ret{ 0 < CListBox::GetCount() }; // return value
	if( ret )
	{
		CListBox::SetCurSel( 0 );
		// Notify the Well List Pane that a new UWI has been selected in the List Box
		::SendMessageA( GetParent()->GetSafeHwnd(), WM_COMMAND, MAKEWPARAM( CListBox::GetDlgCtrlID(), LBN_SELCHANGE ), (LPARAM)m_hWnd );
	}

	return ret;
}

const nhill::Uwi& CWellListBox::GetCurUwi() const
{
	int curSel{ CListBox::GetCurSel() };
	void* uwi{ CListBox::GetItemDataPtr( curSel ) };
	return *(const nhill::Uwi*)uwi;
}

BEGIN_MESSAGE_MAP( CWellListBox, CListBox )
END_MESSAGE_MAP()
#pragma endregion


CWellListPane::CWellListPane() noexcept
{
}

CWellListPane::~CWellListPane()
{
}

void CWellListPane::on_well_list_changed( const nhill::Well_list_changed_event_args& event_args )
{
	m_wellListBox.Load( event_args.uwi_list );
}

BEGIN_MESSAGE_MAP( CWellListPane, CDockablePane )
   ON_WM_CREATE()
   ON_WM_SIZE()
	ON_LBN_SELCHANGE( m_idWellListBox, &CWellListPane::OnWellListBoxSelectionChanged )
END_MESSAGE_MAP()

int CWellListPane::OnCreate( LPCREATESTRUCT lpCreateStruct )
{
   if( CDockablePane::OnCreate( lpCreateStruct ) == -1 )
      return -1;

   m_font.CreatePointFont( 90, _T( "Courier New" ) );

   CRect rectDummy;
   rectDummy.SetRectEmpty();

   // Create output panes:
   const DWORD dwStyle = LBS_NOTIFY | LBS_NOINTEGRALHEIGHT | WS_CHILD | WS_VISIBLE | WS_HSCROLL | WS_VSCROLL ;

   if( !m_wellListBox.Create( dwStyle, rectDummy, this, m_idWellListBox ) )
   {
      TRACE0( "Failed to create output windows\n" );
      return -1;      // fail to create
   }

   UpdateFonts();

   return 0;
}

void CWellListPane::OnSize( UINT nType, int cx, int cy )
{
   CDockablePane::OnSize( nType, cx, cy );

   // Tab control should cover the whole client area:
   m_wellListBox.SetWindowPos( nullptr, -1, -1, cx, cy, SWP_NOMOVE | SWP_NOACTIVATE | SWP_NOZORDER );
}

void CWellListPane::AdjustHorzScroll( CListBox& wndListBox )
{
   CClientDC dc( this );
   CFont* pOldFont = dc.SelectObject( &afxGlobalData.fontRegular );

   int cxExtentMax = 0;

   for( int i = 0; i < wndListBox.GetCount(); i++ )
   {
      CString strItem;
      wndListBox.GetText( i, strItem );

      cxExtentMax = max( cxExtentMax, (int)dc.GetTextExtent( strItem ).cx );
   }

   wndListBox.SetHorizontalExtent( cxExtentMax );
   dc.SelectObject( pOldFont );
}

void CWellListPane::FillCtrl()
{
}

void CWellListPane::UpdateFonts()
{
   m_wellListBox.SetFont( &m_font );
}


void CWellListPane::OnWellListBoxSelectionChanged()
{
	const nhill::Uwi& uwi{ m_wellListBox.GetCurUwi() };
	notify_well_changed( uwi );
}

