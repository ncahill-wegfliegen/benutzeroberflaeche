#pragma once

#include "port.h"

namespace nhill
{
namespace ctrl
{

class UserControl;

class NHILL_USERCONTROL_PORT_CLASS UserControlPanel : public CStatic
{
public:
    UserControlPanel( nhill::ctrl::UserControl* userControl = nullptr );
    virtual ~UserControlPanel();

public:
    nhill::ctrl::UserControl* GetUserControl() const;
    void SetUserControl( nhill::ctrl::UserControl* value );
    __declspec(property(get = GetUserControl,put=SetUserControl)) nhill::ctrl::UserControl* UserControl;

public:
    void SetBackgroundColor( COLORREF colorref );

private:
    nhill::ctrl::UserControl* userControl;
    CBrush* brushBackground;

public:
    DECLARE_MESSAGE_MAP()
    afx_msg void OnEnable( BOOL bEnable );
    //afx_msg HBRUSH OnCtlColor( CDC* pDC, CWnd* pWnd, UINT nCtlColor );
    afx_msg HBRUSH CtlColor( CDC* pDC, UINT nCtlColor );
};

}
}