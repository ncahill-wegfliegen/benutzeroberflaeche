// TicketSection.cpp : implementation file
//

#include "pch.h"
#include "UserControl.h"
#include "TicketSection.h"
#include "../../dev/gemeinsam/utility/str.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

using namespace std;

IMPLEMENT_DYNAMIC(TicketSection, nhill::ctrl::UserControl )

TicketSection::TicketSection(CWnd* pParent /*=nullptr*/)
{
}

TicketSection::~TicketSection()
{
	title_font_.DeleteObject();
	list_ctrl_font_.DeleteObject();
}

bool TicketSection::create()
{
	base::create();

	SetBackgroundColor( RGB( 255, 255, 255 ) );

	CFont* font{ title_ctrl_.GetFont() };
	LOGFONT logfont{};
	font->GetLogFont( &logfont );
	HDC hdc{ title_ctrl_.GetDC()->GetSafeHdc() };
	logfont.lfHeight = -MulDiv( 10, GetDeviceCaps( hdc, LOGPIXELSY ), 72 );
	logfont.lfWeight = FW_BOLD;
	title_font_.CreateFontIndirect( &logfont );
	title_ctrl_.SetFont( &title_font_ );
	

	font = list_ctrl_.GetFont();
	font->GetLogFont( &logfont );
	hdc = list_ctrl_.GetDC()->GetSafeHdc();
	logfont.lfHeight = -MulDiv( 10, GetDeviceCaps( hdc, LOGPIXELSY ), 72 );
	list_ctrl_font_.CreateFontIndirect( &logfont );
	list_ctrl_.SetFont( &list_ctrl_font_ );

	return true;

}

string TicketSection::title() const
{
	if( ::IsWindow( title_ctrl_.GetSafeHwnd() ) )
	{
		CString wstr;
		title_ctrl_.GetWindowTextW( wstr );
		title_ = nhill::str::to_string( static_cast<const wchar_t*>(wstr) );
	}

	return std::string();
}

void TicketSection::title( std::string_view value)
{
	title_ = value;

	if( ::IsWindow( title_ctrl_.GetSafeHwnd() ) )
	{
		std::wstring wstr{ nhill::str::to_wstring( title_ ) };
		title_ctrl_.SetWindowTextW( wstr.c_str() );
	}
}

TicketSectionListCtrl& TicketSection::list_control()
{
	return list_ctrl_;
}

void TicketSection::DoDataExchange(CDataExchange* pDX)
{
	base::DoDataExchange( pDX );
	DDX_Control( pDX, IDC_TICKET_SECTION_TITLE, title_ctrl_ );
	DDX_Control( pDX, IDC_TICKET_SECTION_LIST, list_ctrl_ );
}


BEGIN_MESSAGE_MAP(TicketSection, nhill::ctrl::UserControl )
	ON_WM_CREATE()
END_MESSAGE_MAP()


// TicketSection message handlers


int TicketSection::OnCreate( LPCREATESTRUCT lpCreateStruct )
{
	if( UserControl::OnCreate( lpCreateStruct ) == -1 )
		return -1;

	return 0;
}
