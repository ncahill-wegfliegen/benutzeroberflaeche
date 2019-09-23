#include "pch.h"
#include "ticket_section_listctrl.h"
#include "ticket_section00_listctrl.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

using namespace std;

nhill::ctrl::ab_oil_pressure_test_ui::TicketSectionListCtrl::TicketSectionListCtrl( Record_type record_type )
	: record_type_{record_type}
{

}

nhill::ctrl::ab_oil_pressure_test_ui::TicketSectionListCtrl::~TicketSectionListCtrl() = default;

auto nhill::ctrl::ab_oil_pressure_test_ui::TicketSectionListCtrl::record_type() const->Record_type
{
	return record_type_;
}

auto nhill::ctrl::ab_oil_pressure_test_ui::TicketSectionListCtrl::create( Record_type record_type )->std::unique_ptr<TicketSectionListCtrl>
{
	switch( record_type )
	{
	case Record_type::well_id: return make_unique<TicketSection00ListCtrl>();
	default: return nullptr;
	}
}
