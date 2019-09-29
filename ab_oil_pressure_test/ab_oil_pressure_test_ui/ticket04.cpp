#include "pch.h"
#include "ticket04.h"

void nhill::ctrl::ab_oil_pressure_test_ui::Ticket04::clear()
{
	test_date.clear(0,0, "Test Date");
	test_type.clear(0,1, "Test Type");
	historical_well_status.clear(0,2, "Historical Well Status");

	casing_pressure.clear(1, 0, "Casing Pressure", "kPa") ;
	mpp_depth.clear(1, 1, "MPP Depth", "m");
	gauge_run_depth.clear(1, 2, "Gauge Run Depth", "m");

	run_depth_gradient.clear(2, 0, "Run Depth Gradient", "kPa/m");
	run_depth_pressure.clear(2, 1, "Run Depth Pressure", "kPa" );
	reservoir_temperature.clear(2, 2, "Reservoir Temperature", "°C");

	initial_liquid_level.clear( 3, 0, "Initial Liquid Level", "m");
	final_liquid_level.clear( 3, 1, "Final Liquid Level", "m");
	gas_gradient.clear(3, 2, "Gas Gradient", "kPa/m");

	oil_gradient.clear( 4, 0, "Oil Gradient", "kPa/m");
	water_gradient.clear(4, 1, "Water Gradient", "kPa/m");
	mpp_pressure.clear(4, 2, "MPP Pressure", "kPa");

	datum_depth_pressure.clear(5, 0, "Datum Depth Pressure", "kPa");
	extrapolated_pressure_indicator.clear(5, 1, "Extrapolated Pressure Indicator");
	extrapolated_mpp_pressure.clear(5, 2, "Extrapolated MPP Pressure", "kPa");

	extrapolated_datum_depth_pressure.clear( 6, 0, "Extrapolated Datum Depth Pressure", "kPa");
	shut_in_period.clear(6, 1, "Shut-In Period", "hrs");
}

void nhill::ctrl::ab_oil_pressure_test_ui::Ticket04::clear_value_text()
{
	test_date.clear_value_text();
	test_type.clear_value_text();
	historical_well_status.clear_value_text();
	casing_pressure.clear_value_text();
	mpp_depth.clear_value_text();
	gauge_run_depth.clear_value_text();
	run_depth_gradient.clear_value_text();
	run_depth_pressure.clear_value_text();
	reservoir_temperature.clear_value_text();
	initial_liquid_level.clear_value_text();
	final_liquid_level.clear_value_text();
	gas_gradient.clear_value_text();
	oil_gradient.clear_value_text();
	water_gradient.clear_value_text();
	mpp_pressure.clear_value_text();
	datum_depth_pressure.clear_value_text();
	extrapolated_pressure_indicator.clear_value_text();
	extrapolated_mpp_pressure.clear_value_text();
	extrapolated_datum_depth_pressure.clear_value_text();
	shut_in_period.clear_value_text();
}

auto nhill::ctrl::ab_oil_pressure_test_ui::Ticket04::block_ptrs()->Block_ptr_container
{
	return {
		&test_date,
		&test_type,
		&historical_well_status,
		&casing_pressure,
		&mpp_depth,
		&gauge_run_depth,
		&run_depth_gradient,
		&run_depth_pressure,
		&reservoir_temperature,
		&initial_liquid_level,
		&final_liquid_level,
		&gas_gradient,
		&oil_gradient,
		&water_gradient,
		&mpp_pressure,
		&datum_depth_pressure,
		&extrapolated_pressure_indicator,
		&extrapolated_mpp_pressure,
		&extrapolated_datum_depth_pressure,
		&shut_in_period
	};
}
