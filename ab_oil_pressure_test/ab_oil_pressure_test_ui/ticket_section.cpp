#include "pch.h"
#include "ticket_section.h"
#include "../../user_control/user_control.h"
#include "../../../gemeinsam/utility/str.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

using namespace std;

namespace nhill
{
namespace ctrl
{
namespace ab_oil_pressure_test_ui
{

IMPLEMENT_DYNAMIC( TicketSection, User_control )

BEGIN_MESSAGE_MAP( TicketSection, User_control )
	ON_WM_CREATE()
END_MESSAGE_MAP()

}
}
}

nhill::ctrl::ab_oil_pressure_test_ui::TicketSection::TicketSection( Record_type record_type, CWnd* pParent /*=nullptr*/)
	: list_ctrl_{TicketSectionListCtrl::create(record_type)}
{
}

nhill::ctrl::ab_oil_pressure_test_ui::TicketSection::~TicketSection()
{
	title_font_.DeleteObject();
	list_ctrl_font_.DeleteObject();
}

bool nhill::ctrl::ab_oil_pressure_test_ui::TicketSection::create()
{
	base::create();

	background_color( RGB( 255, 255, 255 ) );

	CFont* font{ title_ctrl_.GetFont() };
	LOGFONT logfont{};
	font->GetLogFont( &logfont );
	HDC hdc{ title_ctrl_.GetDC()->GetSafeHdc() };
	logfont.lfHeight = -MulDiv( 10, GetDeviceCaps( hdc, LOGPIXELSY ), 72 );
	logfont.lfWeight = FW_BOLD;
	title_font_.CreateFontIndirect( &logfont );
	title_ctrl_.SetFont( &title_font_ );
	

	font = list_ctrl_->GetFont();
	font->GetLogFont( &logfont );
	hdc = list_ctrl_->GetDC()->GetSafeHdc();
	logfont.lfHeight = -MulDiv( 10, GetDeviceCaps( hdc, LOGPIXELSY ), 72 );
	list_ctrl_font_.CreateFontIndirect( &logfont );
	list_ctrl_->SetFont( &list_ctrl_font_ );

	list_ctrl_->create();

	return true;

}

string nhill::ctrl::ab_oil_pressure_test_ui::TicketSection::title() const
{
	if( ::IsWindow( title_ctrl_.GetSafeHwnd() ) )
	{
		CString wstr;
		title_ctrl_.GetWindowTextW( wstr );
		title_ = nhill::str::to_string( static_cast<const wchar_t*>(wstr) );
	}

	return std::string();
}

void nhill::ctrl::ab_oil_pressure_test_ui::TicketSection::title( std::string_view value)
{
	title_ = value;

	if( ::IsWindow( title_ctrl_.GetSafeHwnd() ) )
	{
		std::wstring wstr{ nhill::str::to_wstring( title_ ) };
		title_ctrl_.SetWindowTextW( wstr.c_str() );
	}
}

auto nhill::ctrl::ab_oil_pressure_test_ui::TicketSection::list_control()->TicketSectionListCtrl &
{
	return *list_ctrl_;
}

void nhill::ctrl::ab_oil_pressure_test_ui::TicketSection::DoDataExchange(CDataExchange* dx)
{
	base::DoDataExchange( dx );
	DDX_Control( dx, IDC_ABOPT_UI_TICKET_SECTION_TITLE, title_ctrl_ );
	DDX_Control( dx, IDC_ABOPT_UI_TICKET_SECTION_LIST, *list_ctrl_ );
}

int nhill::ctrl::ab_oil_pressure_test_ui::TicketSection::OnCreate( LPCREATESTRUCT lpCreateStruct )
{
	if( User_control::OnCreate( lpCreateStruct ) == -1 )
		return -1;

	return 0;
}
