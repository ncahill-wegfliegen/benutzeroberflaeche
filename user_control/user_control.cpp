#include "pch.h"
#include "user_control.h"
#include "user_control_panel.h"
#include <exception>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

using namespace std;

namespace nhill
{
namespace ctrl
{

IMPLEMENT_DYNAMIC( User_control, CDialog )

BEGIN_MESSAGE_MAP( User_control, CDialog )
	ON_WM_CTLCOLOR()
END_MESSAGE_MAP()

}
}


nhill::ctrl::User_control::User_control()
: panel_border_( false )
, brush_background_(nullptr)
{
}

nhill::ctrl::User_control::User_control( UINT id_option, CWnd* parent_wnd /*= NULL*/ )
    : CDialog( id_option, parent_wnd )
    , panel_border_( false )
    , brush_background_( nullptr )
{
}

nhill::ctrl::User_control::User_control( LPCTSTR option_name, CWnd* parent_wnd /*= NULL*/ )
	: CDialog{ option_name, parent_wnd }
	, panel_border_{ false }
	, brush_background_{ nullptr }
{
}

nhill::ctrl::User_control::~User_control() = default;

bool nhill::ctrl::User_control::is_window()
{
    return TRUE == ::IsWindow( m_hWnd );
}

auto nhill::ctrl::User_control::panel()->User_control_panel &
{
    CWnd* parent = GetParent();
    if( parent == nullptr )
        throw std::exception( "The control does not have a parent to act as a panel." );

    User_control_panel* panel = dynamic_cast<User_control_panel*>(parent);
    if( panel == nullptr )
        throw std::exception( "The parent is not a User_control_panel." );

    return *panel;
}

bool nhill::ctrl::User_control::panel_border()
{
    return panel_border_;
}

void nhill::ctrl::User_control::panel_border( bool value )
{
    panel_border_ = value;

    if( !::IsWindow( m_hWnd ) )
        return;

    try
    {
		 panel().SetWindowText( _T( "" ) );

        DWORD styleEx;
        if( panel_border_ )
        {
            ModifyStyle( 0, WS_CHILD | WS_BORDER, SWP_FRAMECHANGED | SWP_NOSIZE | SWP_NOMOVE | SWP_NOZORDER | SWP_NOACTIVATE );
            styleEx = panel().GetExStyle();
            styleEx &= ~WS_BORDER;
				panel().ModifyStyleEx( styleEx, 0, SWP_FRAMECHANGED | SWP_NOSIZE | SWP_NOMOVE | SWP_NOZORDER | SWP_NOACTIVATE );
        } else
        {
            ModifyStyle( WS_BORDER, WS_CHILD, SWP_FRAMECHANGED | SWP_NOSIZE | SWP_NOMOVE | SWP_NOZORDER | SWP_NOACTIVATE );
            styleEx = panel().GetExStyle();
				panel().ModifyStyleEx( styleEx, 0, SWP_FRAMECHANGED | SWP_NOSIZE | SWP_NOMOVE | SWP_NOZORDER | SWP_NOACTIVATE );
        }
    } catch( std::exception )
    {
    } catch( ... )
    {
    }
}


bool nhill::ctrl::User_control::create()
{
    // Remove/Add styles
    ModifyStyle( WS_POPUP | WS_OVERLAPPED | WS_CAPTION | WS_THICKFRAME | WS_MINIMIZE | WS_MAXIMIZE | WS_SYSMENU | WS_BORDER | WS_SIZEBOX, WS_CHILD, SWP_FRAMECHANGED | SWP_NOSIZE | SWP_NOMOVE | SWP_NOZORDER | SWP_NOACTIVATE );

    // Remove all extended styles
    DWORD style_ex = GetExStyle();
    ModifyStyleEx( style_ex, 0, SWP_FRAMECHANGED | SWP_NOSIZE | SWP_NOMOVE | SWP_NOZORDER | SWP_NOACTIVATE );

    // Force panel border to be reset
    panel_border( panel_border() );
    // Setup the panel
	 panel().SetWindowText( _T("") );

    return true;
}

BOOL nhill::ctrl::User_control::Create( LPCTSTR option_name, CWnd* parent_wnd /*= NULL*/ )
{
    BOOL created_dialog = CDialog::Create( option_name, parent_wnd );
    if( !created_dialog )
        return FALSE;

    bool created_this = create();
    return created_this;
}

BOOL nhill::ctrl::User_control::Create( UINT id_option, CWnd* parent_wnd )
{
    BOOL created_dialog = CDialog::Create( id_option, parent_wnd /*= NULL*/ );
    if( !created_dialog )
        return FALSE;

    bool created_this = create();
    return created_this;
}

bool nhill::ctrl::User_control::show_window( int cmd_show )
{
	bool sw{ CDialog::ShowWindow( cmd_show ) != FALSE };

    if( cmd_show == SW_RESTORE || cmd_show == SW_SHOW || cmd_show == SW_SHOWNOACTIVATE || cmd_show == SW_SHOWNA || cmd_show == SW_SHOWNORMAL )
    {
        Invalidate();
        UpdateWindow();
    }

    return sw;
}

void nhill::ctrl::User_control::enable_window( bool enable )
{
	CDialog::EnableWindow( enable );
	// http://www.codeproject.com/Articles/11262/Enumerate-Controls-In-a-Dialog-Box-or-FormView

	// get the top-most window in the 
	// chain of child windows
	HWND hwnd = ::GetTopWindow( this->GetSafeHwnd() );
	// while we have a valid hwnd, 
	// loop through all child windows
	while( hwnd )
	{
		// (dis)enable the child
		::EnableWindow( hwnd, enable );

		// and get the next child control's hwnd
		hwnd = ::GetNextWindow( hwnd, GW_HWNDNEXT );
	}
}

void nhill::ctrl::User_control::pull()
{
    if( ::IsWindow( CDialog::m_hWnd ) )
        CDialog::UpdateData( TRUE );
}

void nhill::ctrl::User_control::push()
{
    if( ::IsWindow( CDialog::m_hWnd ) )
        CDialog::UpdateData( FALSE );
}

bool nhill::ctrl::User_control::radio_exchange( int idc_radio, int& value, bool pull )
{
    // BOOL CWnd::UpdateData( BOOL bSaveAndValidate ) in wincore.cpp line 4343

    ASSERT( ::IsWindow( m_hWnd ) ); // calling UpdateData before DoModal?

    CDataExchange dx( this, pull );

    // prevent control notifications from being dispatched during UpdateData
    _AFX_THREAD_STATE* thread_state = AfxGetThreadState();
    HWND hwnd_old_lockout = thread_state->m_hLockoutNotifyWindow;
    ASSERT( hwnd_old_lockout != m_hWnd );   // must not recurse
    thread_state->m_hLockoutNotifyWindow = m_hWnd;

    BOOL ok = FALSE;       // assume failure
    try
    {
        DDX_Radio( &dx, idc_radio, value );
        ok = TRUE;         // it worked
    } catch( CUserException& /*e*/ )
    {
        // validation failed - user already alerted, fall through
        ASSERT( !ok );
        // Note: DELETE_EXCEPTION_(e) not required
    } catch( ... )
    {
        ASSERT( !ok );
    }

    thread_state->m_hLockoutNotifyWindow = hwnd_old_lockout;
    return ok == TRUE;
}

bool nhill::ctrl::User_control::radio_pull( int idc_radio, int& value )
{
    return radio_exchange( idc_radio, value, true );
}

bool nhill::ctrl::User_control::radio_push( int idc_radio, int value )
{
    return radio_exchange( idc_radio, value, false );
}

bool nhill::ctrl::User_control::text_exchange( int idc_textbox, double& value, bool pull )
{
    // BOOL CWnd::UpdateData( BOOL bSaveAndValidate ) in wincore.cpp line 4343

    ASSERT( ::IsWindow( m_hWnd ) ); // calling UpdateData before DoModal?

    CDataExchange dx( this, pull );

    // prevent control notifications from being dispatched during UpdateData
    _AFX_THREAD_STATE* thread_state = AfxGetThreadState();
    HWND hwnd_old_lockout = thread_state->m_hLockoutNotifyWindow;
    ASSERT( hwnd_old_lockout != m_hWnd );   // must not recurse
    thread_state->m_hLockoutNotifyWindow = m_hWnd;

    BOOL ok = FALSE;       // assume failure
    try
    {
        DDX_Text( &dx, idc_textbox, value );
        ok = TRUE;         // it worked
    } catch( CUserException& /*e*/ )
    {
        // validation failed - user already alerted, fall through
        ASSERT( !ok );
        // Note: DELETE_EXCEPTION_(e) not required
    } catch( ... )
    {
        ASSERT( !ok );
    }

    thread_state->m_hLockoutNotifyWindow = hwnd_old_lockout;
    return ok == TRUE;
}

bool nhill::ctrl::User_control::text_pull( int idc_textbox, double& value )
{
    return text_exchange( idc_textbox, value, true );
}

bool nhill::ctrl::User_control::text_push( int idc_textbox, double value )
{
    return text_exchange( idc_textbox, value, false );
}

void nhill::ctrl::User_control::background_color( COLORREF colorref )
{
	brush_background_ = make_unique<CBrush>( colorref );
}

HBRUSH nhill::ctrl::User_control::OnCtlColor( CDC* dc, CWnd* wnd, UINT ctl_color )
{
	if( brush_background_ == nullptr )
	{
		return __super::OnCtlColor( dc, wnd, ctl_color );
	}
	else
	{
		return (HBRUSH)(brush_background_->GetSafeHandle());
	}
}

