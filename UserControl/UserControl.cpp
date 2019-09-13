#include "pch.h"
#include "UserControl.h"
#include "UserControlPanel.h"
#include <exception>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

namespace nhill
{
namespace ctrl
{

IMPLEMENT_DYNAMIC( UserControl, CDialog )

UserControl::UserControl()
: panelBorder( false )
, brushBackground(nullptr)
{
}

UserControl::UserControl( UINT nIDOption, CWnd* pParentWnd /*= NULL*/ )
    : CDialog( nIDOption, pParentWnd )
    , panelBorder( false )
    , brushBackground( nullptr )
{
}

UserControl::UserControl( LPCTSTR lpszOptionName, CWnd* pParentWnd /*= NULL*/ )
    : CDialog( lpszOptionName, pParentWnd )
    , panelBorder( false )
    , brushBackground( nullptr )
{
}

UserControl::~UserControl()
{
    if( brushBackground != nullptr )
    {
        delete brushBackground;
        brushBackground = nullptr;
    }
}

bool UserControl::GetIsWindow()
{
    return TRUE == ::IsWindow( m_hWnd );
}


UserControlPanel& UserControl::GetPanel()
{
    CWnd* parent = GetParent();
    if( parent == nullptr )
        throw std::exception( "The control does not have a parent to act as a panel." );

    UserControlPanel* panel = dynamic_cast<UserControlPanel*>(parent);
    if( panel == nullptr )
        throw std::exception( "The parent is not a UserControlPanel." );

    return *panel;
}

bool UserControl::GetPanelBorder()
{
    return panelBorder;
}

void UserControl::SetPanelBorder( bool value )
{
    panelBorder = value;

    if( !::IsWindow( m_hWnd ) )
        return;

    try
    {
        Panel.SetWindowText( _T( "" ) );

        DWORD styleEx;
        if( panelBorder )
        {
            ModifyStyle( 0, WS_CHILD | WS_BORDER, SWP_FRAMECHANGED | SWP_NOSIZE | SWP_NOMOVE | SWP_NOZORDER | SWP_NOACTIVATE );
            styleEx = Panel.GetExStyle();
            styleEx &= ~WS_BORDER;
            Panel.ModifyStyleEx( styleEx, 0, SWP_FRAMECHANGED | SWP_NOSIZE | SWP_NOMOVE | SWP_NOZORDER | SWP_NOACTIVATE );
        } else
        {
            ModifyStyle( WS_BORDER, WS_CHILD, SWP_FRAMECHANGED | SWP_NOSIZE | SWP_NOMOVE | SWP_NOZORDER | SWP_NOACTIVATE );
            styleEx = Panel.GetExStyle();
            Panel.ModifyStyleEx( styleEx, 0, SWP_FRAMECHANGED | SWP_NOSIZE | SWP_NOMOVE | SWP_NOZORDER | SWP_NOACTIVATE );
        }
    } catch( std::exception )
    {
    } catch( ... )
    {
    }
}


bool UserControl::create()
{
    // Remove/Add styles
    ModifyStyle( WS_POPUP | WS_OVERLAPPED | WS_CAPTION | WS_THICKFRAME | WS_MINIMIZE | WS_MAXIMIZE | WS_SYSMENU | WS_BORDER | WS_SIZEBOX, WS_CHILD, SWP_FRAMECHANGED | SWP_NOSIZE | SWP_NOMOVE | SWP_NOZORDER | SWP_NOACTIVATE );

    // Remove all extended styles
    DWORD styleEx = GetExStyle();
    ModifyStyleEx( styleEx, 0, SWP_FRAMECHANGED | SWP_NOSIZE | SWP_NOMOVE | SWP_NOZORDER | SWP_NOACTIVATE );

    // Force panel border to be reset
    PanelBorder = PanelBorder;
    // Setup the panel
    Panel.SetWindowText( _T("") );
    //ModifyStyle( WS_BORDER, WS_CHILD, SWP_FRAMECHANGED | SWP_NOSIZE | SWP_NOMOVE | SWP_NOZORDER | SWP_NOACTIVATE );
    //styleEx = Panel.GetExStyle();
    //Panel.ModifyStyleEx( styleEx , 0, SWP_FRAMECHANGED | SWP_NOSIZE | SWP_NOMOVE | SWP_NOZORDER | SWP_NOACTIVATE );

    //CRect rc;
    //Panel.GetClientRect( rc );
    //SetWindowPos( nullptr, 0, 0, rc.Width(), rc.Height(), SWP_NOACTIVATE | SWP_NOOWNERZORDER | SWP_NOZORDER );

    return true;
}

BOOL UserControl::Create( LPCTSTR lpszOptionName, CWnd* pParentWnd /*= NULL*/ )
{
    BOOL createDialog = CDialog::Create( lpszOptionName, pParentWnd );
    if( !createDialog )
        return FALSE;



    bool createThis = create();
    return createThis;
}

BOOL UserControl::Create( UINT nIDOption, CWnd* pParentWnd )
{
    BOOL createDialog = CDialog::Create( nIDOption, pParentWnd /*= NULL*/ );
    if( !createDialog )
        return FALSE;

    bool createThis = create();
    return createThis;
}

BOOL UserControl::ShowWindow( int nCmdShow )
{
    BOOL sw = CDialog::ShowWindow( nCmdShow );

    if( nCmdShow == SW_RESTORE || nCmdShow == SW_SHOW || nCmdShow == SW_SHOWNOACTIVATE || nCmdShow == SW_SHOWNA || nCmdShow == SW_SHOWNORMAL )
    {
        Invalidate();
        UpdateWindow();
    }

    return sw;
}

void UserControl::DataPull()
{
    if( ::IsWindow( CDialog::m_hWnd ) )
        CDialog::UpdateData( TRUE );
}

void UserControl::DataPush()
{
    if( ::IsWindow( CDialog::m_hWnd ) )
        CDialog::UpdateData( FALSE );
}

bool UserControl::DoRadioExchange( int idc_radio, int& value, bool pull )
{
    // BOOL CWnd::UpdateData( BOOL bSaveAndValidate ) in wincore.cpp line 4343

    ASSERT( ::IsWindow( m_hWnd ) ); // calling UpdateData before DoModal?

    CDataExchange dx( this, pull );

    // prevent control notifications from being dispatched during UpdateData
    _AFX_THREAD_STATE* pThreadState = AfxGetThreadState();
    HWND hWndOldLockout = pThreadState->m_hLockoutNotifyWindow;
    ASSERT( hWndOldLockout != m_hWnd );   // must not recurse
    pThreadState->m_hLockoutNotifyWindow = m_hWnd;

    BOOL bOK = FALSE;       // assume failure
    try
    {
        DDX_Radio( &dx, idc_radio, value );
        bOK = TRUE;         // it worked
    } catch( CUserException& /*e*/ )
    {
        // validation failed - user already alerted, fall through
        ASSERT( !bOK );
        // Note: DELETE_EXCEPTION_(e) not required
    } catch( ... )
    {
        ASSERT( !bOK );
    }

    pThreadState->m_hLockoutNotifyWindow = hWndOldLockout;
    return bOK == TRUE;
}

bool UserControl::DoRadioPull( int idc_radio, int& value )
{
    return DoRadioExchange( idc_radio, value, true );
}

bool UserControl::DoRadioPush( int idc_radio, int value )
{
    return DoRadioExchange( idc_radio, value, false );
}


bool UserControl::DoTextExchange( int idc_textbox, double& value, bool pull )
{
    // BOOL CWnd::UpdateData( BOOL bSaveAndValidate ) in wincore.cpp line 4343

    ASSERT( ::IsWindow( m_hWnd ) ); // calling UpdateData before DoModal?

    CDataExchange dx( this, pull );

    // prevent control notifications from being dispatched during UpdateData
    _AFX_THREAD_STATE* pThreadState = AfxGetThreadState();
    HWND hWndOldLockout = pThreadState->m_hLockoutNotifyWindow;
    ASSERT( hWndOldLockout != m_hWnd );   // must not recurse
    pThreadState->m_hLockoutNotifyWindow = m_hWnd;

    BOOL bOK = FALSE;       // assume failure
    try
    {
        DDX_Text( &dx, idc_textbox, value );
        bOK = TRUE;         // it worked
    } catch( CUserException& /*e*/ )
    {
        // validation failed - user already alerted, fall through
        ASSERT( !bOK );
        // Note: DELETE_EXCEPTION_(e) not required
    } catch( ... )
    {
        ASSERT( !bOK );
    }

    pThreadState->m_hLockoutNotifyWindow = hWndOldLockout;
    return bOK == TRUE;
}

bool UserControl::DoTextPull( int idc_textbox, double& value )
{
    return DoTextExchange( idc_textbox, value, true );
}

bool UserControl::DoTextPush( int idc_textbox, double value )
{
    return DoTextExchange( idc_textbox, value, false );
}

void UserControl::EnableWindow( bool enable )
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

void UserControl::SetBackgroundColor( COLORREF colorref )
{
    if( brushBackground != nullptr )
    {
        delete brushBackground;
        brushBackground = nullptr;
    }

    brushBackground = new CBrush( colorref );
}

HBRUSH UserControl::OnCtlColor( CDC* pDC, CWnd* pWnd, UINT nCtlColor )
{
	//pDC->SetBkMode( TRANSPARENT );
	//return (HBRUSH)GetStockObject( NULL_BRUSH );
    HBRUSH hbr = NULL;
    
    if( brushBackground == nullptr )
        hbr = __super::OnCtlColor( pDC, pWnd, nCtlColor );
    else
        hbr = (HBRUSH)(brushBackground->GetSafeHandle());

    //// TODO:  Change any attributes of the DC here

    //// TODO:  Return a different brush if the default is not desired
    return hbr;
    //return brushBackground;

}


BEGIN_MESSAGE_MAP( UserControl, CDialog )
    ON_WM_CTLCOLOR()
END_MESSAGE_MAP()

}
}


