#include "pch.h"
#include "ticket03.h"

void nhill::ctrl::ab_oil_pressure_test_ui::Ticket03::clear()
{
	//field_code.clear( 0, 0, "Field Code");
	//pool_code.clear ( 1, 0, "Pool Code" );

	consol_interval_top   .clear(0, 0,"Consol Interval Top", "m");
	consol_interval_bottom.clear(1, 0, "Consol Interval Bottom", "m");

	kb_elevation    .clear( 2, 0, "KB Elevation", "m");
	pool_datum_depth.clear( 3, 0, "Pool Datum Depth", "m" );

	ground_elevation.clear( 0, 1, "Ground Elevation", "m");
	well_datum_depth.clear( 1, 1, "Well Datum Depth", "m");

	initial_pool_pressure.clear(2, 1, "Initial Pool Pressure", "kPa");
	reservoir_gradient   .clear(3, 1, "Reservoir Gradient", "kPa/m");

	consol_interval_top.value.halign = HAlign::right;
	consol_interval_bottom.value.halign = HAlign::right;
	kb_elevation.value.halign = HAlign::right;
	pool_datum_depth.value.halign = HAlign::right;
	ground_elevation.value.halign = HAlign::right;
	initial_pool_pressure.value.halign = HAlign::right;
	reservoir_gradient.value.halign = HAlign::right;
}

void nhill::ctrl::ab_oil_pressure_test_ui::Ticket03::clear_value_text()
{
	//field_code.clear_value_text();
	//pool_code.clear_value_text();
	consol_interval_top.clear_value_text();
	consol_interval_bottom.clear_value_text();
	kb_elevation.clear_value_text();
	pool_datum_depth.clear_value_text();
	ground_elevation.clear_value_text();
	well_datum_depth.clear_value_text();
	initial_pool_pressure.clear_value_text();
	reservoir_gradient.clear_value_text();
}

auto nhill::ctrl::ab_oil_pressure_test_ui::Ticket03::block_ptrs()->Block_ptr_container
{
	return{
		//&field_code,
		//&pool_code,
		&consol_interval_top,
		&consol_interval_bottom,
		&kb_elevation,
		&pool_datum_depth,
		&ground_elevation,
		&well_datum_depth,
		&initial_pool_pressure,
		&reservoir_gradient,
	};

}
