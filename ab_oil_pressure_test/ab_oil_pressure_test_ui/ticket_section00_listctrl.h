#pragma once

#include "port.h"
#include "ticket_section_listctrl.h"

namespace nhill
{
namespace ctrl
{
class Cell;
namespace ab_oil_pressure_test_ui
{
class Ticket_property00;
}
}
}
namespace nhill
{
namespace ctrl
{
namespace ab_oil_pressure_test_ui
{

class NHILL_ABOPT_UI_PORT_CLASS TicketSection00ListCtrl : public TicketSectionListCtrl
{
public:
	using base = TicketSectionListCtrl;

	TicketSection00ListCtrl();
	virtual ~TicketSection00ListCtrl();

	virtual bool create() override;

protected:
	static const Ticket_property00& ticket_property00();
	static const Cell& cell( int row, int col );

	virtual COLORREF OnGetCellTextColor( int row, int col ) override;
	virtual COLORREF OnGetCellBkColor( int row, int col ) override;
	virtual HFONT OnGetCellFont( int row, int col, DWORD data = 0 ) override;

public:
	DECLARE_MESSAGE_MAP()
};

}
}
}