#include "ticket00.h"
#include "../../user_control/grid_pos.h"
#include "../../user_control/halign.h"
#include "../../user_control/valign.h"

void nhill::ctrl::ab_oil_pressure_test_ui::Ticket00::clear()
{
	uwi                .clear( 0, 0, "UWI" );
	consol_interval_num.clear( 0, 1, "Consol Interval Num" );
	well_name          .clear( 1, 0, "Well Name" );
	on_production_date .clear( 1, 1, "On Production Date" );
}

void nhill::ctrl::ab_oil_pressure_test_ui::Ticket00::clear_value_text()
{
	uwi.clear_value_text();
	consol_interval_num.clear_value_text();
	well_name.clear_value_text();
	on_production_date.clear_value_text();
}

auto nhill::ctrl::ab_oil_pressure_test_ui::Ticket00::block_ptrs()->Block_ptr_container
{
	return{
		&uwi,
		&consol_interval_num,
		&well_name,
		&on_production_date
	};
}


