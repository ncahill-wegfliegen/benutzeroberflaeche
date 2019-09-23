#include "pch.h"
#include "user_control_panel.h"
#include "user_control.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

using namespace std;

namespace nhill
{
namespace ctrl
{

BEGIN_MESSAGE_MAP( User_control_panel, CStatic )
	ON_WM_ENABLE()
	//{{AFX_MSG_MAP( User_control_panel )
	ON_WM_CTLCOLOR_REFLECT()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

}
}

nhill::ctrl::User_control_panel::User_control_panel( nhill::ctrl::User_control* user_control )
	: user_control_{ user_control }
	, brush_background_{ nullptr }
{
}

nhill::ctrl::User_control_panel::~User_control_panel() = default;

auto nhill::ctrl::User_control_panel::user_control() const->nhill::ctrl::User_control*
{
	return user_control_;
}

void nhill::ctrl::User_control_panel::user_control( nhill::ctrl::User_control* value )
{
	user_control_ = value;
}

void nhill::ctrl::User_control_panel::background_color( COLORREF colorref )
{
	brush_background_ = make_unique<CBrush>( colorref );
}

void nhill::ctrl::User_control_panel::OnEnable( BOOL bEnable )
{
	CStatic::OnEnable( bEnable );

	if( user_control() != nullptr )
	{
		user_control()->enable_window( bEnable == TRUE );
	}
}

HBRUSH nhill::ctrl::User_control_panel::CtlColor( CDC* dc, UINT ctl_color )
{
	if( brush_background_ == nullptr )
	{
		return NULL;
	}
	else
	{
		return (HBRUSH)(brush_background_->GetSafeHandle());
	}
}
