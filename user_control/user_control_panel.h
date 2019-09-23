#pragma once

#include "port.h"
#include <memory>

namespace nhill
{
namespace ctrl
{

class User_control;

class NHILL_USERCTRL_PORT_CLASS User_control_panel : public CStatic
{
public:
    User_control_panel( User_control* user_control = nullptr );
    virtual ~User_control_panel();

    User_control* user_control() const;
    void user_control( User_control* );

    void background_color( COLORREF  );

protected:
	 afx_msg void OnEnable( BOOL bEnable );
	 afx_msg HBRUSH CtlColor( CDC* pDC, UINT nCtlColor );

private:
	User_control* user_control_;
	std::unique_ptr<CBrush> brush_background_;

public:
    DECLARE_MESSAGE_MAP()
};

}
}