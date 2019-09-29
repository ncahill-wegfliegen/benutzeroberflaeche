#include "pch.h"
#include "ticket05.h"

void nhill::ctrl::ab_oil_pressure_test_ui::Ticket05::clear()
{
	remark.clear( 0, 0, "Remark" );
}

void nhill::ctrl::ab_oil_pressure_test_ui::Ticket05::clear_value_text()
{
	remark.clear_value_text();
}

auto nhill::ctrl::ab_oil_pressure_test_ui::Ticket05::block_ptrs()->Block_ptr_container
{
	return {
		&remark
	};
}
