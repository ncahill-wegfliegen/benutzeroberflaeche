#pragma once

#include "port.h"
#include "../../user_control/block_container.h"

namespace nhill
{
namespace ctrl
{
namespace ab_oil_pressure_test_ui
{

class NHILL_ABOPT_UI_PORT_CLASS Ticket03
{
public:
	//Block field_code;
	//Block pool_code;
	Block consol_interval_top;
	Block consol_interval_bottom;
	Block kb_elevation;
	Block pool_datum_depth;
	Block ground_elevation;
	Block well_datum_depth;
	Block initial_pool_pressure;
	Block reservoir_gradient;

	static constexpr char* const default_format_consol_interval_top{ "%7.2f" };
	static constexpr char* const default_format_consol_interval_bottom{ "%7.2f" };
	static constexpr char* const default_format_kb_elevation{ "%7.2f" };
	static constexpr char* const default_format_pool_datum_depth{ "%7.2f" };
	static constexpr char* const default_format_ground_elevation{ "%7.2f" };
	static constexpr char* const default_format_well_datum_depth{ "%7.2f" };
	static constexpr char* const default_format_initial_pool_pressure{ "%5.0f" };
	static constexpr char* const default_format_reservoir_gradient{ "%6.3f" };

	void clear();
	void clear_value_text();
	Block_ptr_container block_ptrs();
};

}
}
}