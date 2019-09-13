#include "pch.h"
#include "UserControlPanel.h"
#include "UserControl.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

namespace nhill
{
namespace ctrl
{

UserControlPanel::UserControlPanel( nhill::ctrl::UserControl* userControl )
    : userControl(userControl)
    , brushBackground( nullptr )
{
}

UserControlPanel::~UserControlPanel()
{
    if( brushBackground != nullptr )
    {
        delete brushBackground;
        brushBackground = nullptr;
    }
}

nhill::ctrl::UserControl* UserControlPanel::GetUserControl() const
{
    return userControl;
}

void UserControlPanel::SetUserControl( nhill::ctrl::UserControl* value )
{
    userControl = value;
}

void UserControlPanel::SetBackgroundColor( COLORREF colorref )
{
    if( brushBackground != nullptr )
    {
        delete brushBackground;
        brushBackground = nullptr;
    }

    brushBackground = new CBrush( colorref );
}


BEGIN_MESSAGE_MAP( UserControlPanel, CStatic )
    ON_WM_ENABLE()
    //{{AFX_MSG_MAP( UserControlPanel )
    ON_WM_CTLCOLOR_REFLECT()
    //}}AFX_MSG_MAP
END_MESSAGE_MAP()


void UserControlPanel::OnEnable( BOOL bEnable )
{
    CStatic::OnEnable( bEnable );

    if( UserControl != nullptr )
        UserControl->EnableWindow( bEnable ==TRUE );
}

//HBRUSH UserControlPanel::OnCtlColor( CDC* pDC, CWnd* pWnd, UINT nCtlColor )
//{
//    HBRUSH hbr = NULL;
//
//    if( brushBackground == nullptr )
//        hbr = __super::OnCtlColor( pDC, pWnd, nCtlColor );
//    else
//        hbr = (HBRUSH)(brushBackground->GetSafeHandle());
//
//    //// TODO:  Change any attributes of the DC here
//
//    //// TODO:  Return a different brush if the default is not desired
//    return hbr;
//    //return brushBackground;
//
//}

HBRUSH UserControlPanel::CtlColor( CDC* pDC, UINT nCtlColor )
{
	//pDC->SetBkMode( TRANSPARENT );
	//return (HBRUSH)GetStockObject( NULL_BRUSH );
    HBRUSH hbr = NULL;

    if( brushBackground == nullptr )
        hbr = NULL; //hbr = __super::CtlColor( pDC, pWnd, nCtlColor );
    else
        hbr = (HBRUSH)(brushBackground->GetSafeHandle());

    //// TODO:  Change any attributes of the DC here

    //// TODO:  Return a different brush if the default is not desired
    return hbr;
    //return brushBackground;

}


}
}
