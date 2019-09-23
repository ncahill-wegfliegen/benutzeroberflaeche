#pragma once

#include "port.h"
#include "ticket_section_listctrl.h"
#include "../../user_control/user_control.h"
#include "../../../datenzugriff/ab_oil_pressure_test/ab_oil_pressure_test/record_type.h"
#include "resource.h"
#include <string>
#include <string_view>
#include <memory>

namespace nhill
{
namespace ctrl
{
namespace ab_oil_pressure_test_ui
{

class NHILL_ABOPT_UI_PORT_CLASS TicketSection : public nhill::ctrl::User_control
{
	DECLARE_DYNAMIC( TicketSection )

public:
	using base = nhill::ctrl::User_control;
	using Record_type = nhill::datenzugriff::ab_oil_pressure_test::Record_type;

#ifdef AFX_DESIGN_TIME
	enum
	{
		IDD = IDD_TICKET_SECTION
	};
#endif

	TicketSection( Record_type record_type, CWnd* pParent = nullptr );   // standard constructor
	virtual ~TicketSection();

	std::string title() const;
	void title( std::string_view );

	TicketSectionListCtrl& list_control();

protected:
	mutable std::string title_;
	CStatic title_ctrl_;
	CFont title_font_;

	std::unique_ptr<TicketSectionListCtrl> list_ctrl_;
	CFont list_ctrl_font_;

	virtual bool create() override;

	virtual void DoDataExchange( CDataExchange* pDX );    // DDX/DDV support

	afx_msg int OnCreate( LPCREATESTRUCT lpCreateStruct );

	DECLARE_MESSAGE_MAP()
};

}
}
}