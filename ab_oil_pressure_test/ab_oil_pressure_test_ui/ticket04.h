#pragma once

#include "port.h"
#include "../../user_control/block_container.h"

namespace nhill
{
namespace ctrl
{
namespace ab_oil_pressure_test_ui
{

class NHILL_ABOPT_UI_PORT_CLASS Ticket04
{
public:
	Block test_date;
	Block test_type;
	Block historical_well_status				;
	Block casing_pressure						;
	Block mpp_depth								;
	Block gauge_run_depth						;
	Block run_depth_gradient					;
	Block run_depth_pressure					;
	Block reservoir_temperature				;
	Block initial_liquid_level					;
	Block final_liquid_level					;
	Block gas_gradient							;
	Block oil_gradient							;
	Block water_gradient							;
	Block mpp_pressure							;
	Block datum_depth_pressure					;
	Block extrapolated_pressure_indicator	;
	Block extrapolated_mpp_pressure			;
	Block extrapolated_datum_depth_pressure;
	Block shut_in_period							;

	static constexpr char* const default_format_casing_pressure{ "%6.0f" };
	static constexpr char* const default_format_mpp_depth{ "%7.2f" };
	static constexpr char* const default_format_gauge_run_depth{ "%7.2f" };
	static constexpr char* const default_format_run_depth_gradient{ "%6.3f" };
	static constexpr char* const default_format_run_depth_pressure{ "%6.0f" };
	static constexpr char* const default_format_reservoir_temperature{ "%3.0f" };
	static constexpr char* const default_format_initial_liquid_level{ "%7.2f" };
	static constexpr char* const default_format_final_liquid_level{ "%7.2f" };
	static constexpr char* const default_format_gas_gradient{ "%6.3f" };
	static constexpr char* const default_format_oil_gradient{ "%6.3f" };
	static constexpr char* const default_format_water_gradient{ "%6.3f" };
	static constexpr char* const default_format_mpp_pressure{ "%6.0f" };
	static constexpr char* const default_format_datum_depth_pressure{ "%6.0f" };
	static constexpr char* const default_format_extrapolated_mpp_pressure{ "%6.0f" };
	static constexpr char* const default_format_extrapolated_datum_depth_pressure{ "%6.0f" };
	static constexpr char* const default_format_shut_in_period{ "%7.1f" };

	void clear();
	void clear_value_text();
	Block_ptr_container block_ptrs();
};

}
}
}