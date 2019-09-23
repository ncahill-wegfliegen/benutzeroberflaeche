#include "pch.h"
#include "ticket_section00_listctrl.h"
#include "config.h"
#include "ticket_property.h"
#include "ticket00.h"
#include "../../user_control/grid_pos_def.h"

using namespace std;

namespace nhill
{
namespace ctrl
{
namespace ab_oil_pressure_test_ui
{

BEGIN_MESSAGE_MAP( TicketSection00ListCtrl, TicketSectionListCtrl )
END_MESSAGE_MAP()

}
}
}

nhill::ctrl::ab_oil_pressure_test_ui::TicketSection00ListCtrl::TicketSection00ListCtrl()
	: base{Record_type::well_id}
{
}

nhill::ctrl::ab_oil_pressure_test_ui::TicketSection00ListCtrl::~TicketSection00ListCtrl()
{
}

bool nhill::ctrl::ab_oil_pressure_test_ui::TicketSection00ListCtrl::create()
{
	const Ticket_property00& ticket_property00{ this->ticket_property00() };

	InsertColumn( 0, _T( "label0" ), LVCFMT_RIGHT );
	InsertColumn( 1, _T( "value0" ), LVCFMT_LEFT );
	InsertColumn( 2, _T( "label1" ), LVCFMT_RIGHT );
	InsertColumn( 3, _T( "value1" ), LVCFMT_LEFT );

	LVCOLUMNW lvc{};
	lvc.mask = LVCF_FMT;
	lvc.fmt = LVCFMT_RIGHT;
	SetColumn( 0, &lvc );

	// Alway assume that the value is:
	// value row = label row (in same row as label)
	// value col = label col + 1 (in the col just to the right of the label)

	int row{ ticket_property00.uwi_label.row };
	int col{ ticket_property00.uwi_label.col };
	string text{ ticket_property00.uwi_label.text };
	InsertItem( row, wstring{ text.cbegin(), text.cend() }.c_str() );
	SetItemText( row, col + 1, _T( "" ) );

	row = ticket_property00.consol_interval_num_label.row;
	col = ticket_property00.consol_interval_num_label.col;
	text = ticket_property00.consol_interval_num_label.text;
	SetItemText( row, col, wstring{ text.cbegin(), text.cend() }.c_str() );
	SetItemText( row, col + 1, _T( "" ) );

	row = ticket_property00.well_name_label.row;
	col = ticket_property00.well_name_label.col;
	text = ticket_property00.well_name_label.text;
	InsertItem( row, wstring{ text.cbegin(), text.cend() }.c_str() );
	SetItemText( row, col + 1, _T( "" ) );

	row = ticket_property00.on_production_date_label.row;
	col = ticket_property00.on_production_date_label.col;
	text = ticket_property00.on_production_date_label.text;
	SetItemText( row, col, wstring{ text.cbegin(), text.cend() }.c_str() );
	SetItemText( row, col + 1, _T( "" ) );

	SetColumnWidth( 0, LVSCW_AUTOSIZE );
	SetColumnWidth( 1, LVSCW_AUTOSIZE );
	SetColumnWidth( 2, LVSCW_AUTOSIZE );
	SetColumnWidth( 3, LVSCW_AUTOSIZE );

	return false;
}

auto nhill::ctrl::ab_oil_pressure_test_ui::TicketSection00ListCtrl::ticket_property00()->const Ticket_property00 &
{
	Configuration& config{ Configuration::instance() };
	const Ticket_property& ticket_property{ config.ticket_property() };
	return ticket_property.ticket_property00;
}

auto nhill::ctrl::ab_oil_pressure_test_ui::TicketSection00ListCtrl::cell( int row, int col )->const Cell &
{
	return ticket_property00().cell( {static_cast<Pos>(row), static_cast<Pos>(col)} );
}

COLORREF nhill::ctrl::ab_oil_pressure_test_ui::TicketSection00ListCtrl::OnGetCellTextColor( int row, int col )
{
	return cell(row,col).text_color;
}

COLORREF nhill::ctrl::ab_oil_pressure_test_ui::TicketSection00ListCtrl::OnGetCellBkColor( int row, int col )
{
	return cell(row, col).background_color;
}

HFONT nhill::ctrl::ab_oil_pressure_test_ui::TicketSection00ListCtrl::OnGetCellFont( int row, int col, DWORD /*data*/ )
{
	return ::CreateFontIndirect( &cell( row, col ).logfont );
}

