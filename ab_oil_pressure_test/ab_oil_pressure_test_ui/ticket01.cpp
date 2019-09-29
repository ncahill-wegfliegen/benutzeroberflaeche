#include "ticket01.h"

void nhill::ctrl::ab_oil_pressure_test_ui::Ticket01::clear()
{
	licensee.clear( 0, 0, "Licensee" );
	survey_coord.clear( 1, 0, "Survey Coordinator" );
	well_status.clear( 0, 1, "Well Status" );
}

void nhill::ctrl::ab_oil_pressure_test_ui::Ticket01::clear_value_text()
{
	licensee.clear_value_text();
	survey_coord.clear_value_text();
	well_status.clear_value_text();
}

auto nhill::ctrl::ab_oil_pressure_test_ui::Ticket01::block_ptrs()->Block_ptr_container
{
	return{
		&licensee,
		& survey_coord,
		& well_status,
	};
}
