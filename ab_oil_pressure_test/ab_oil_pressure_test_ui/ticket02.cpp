#include "ticket02.h"

void nhill::ctrl::ab_oil_pressure_test_ui::Ticket02::clear()
{
	field_name.clear( 0, 0, "Field Name" );
	pool_name.clear( 0, 1, "Pool Name" );
}

void nhill::ctrl::ab_oil_pressure_test_ui::Ticket02::clear_value_text()
{
	field_name.clear_value_text();
	pool_name.clear_value_text();
}

auto nhill::ctrl::ab_oil_pressure_test_ui::Ticket02::block_ptrs()->Block_ptr_container
{
	return {
		&field_name,
		&pool_name
	};

}
