#pragma once

#include "port.h"
#include "../../user_control/cell.h"
#include "../../user_control/block.h"

namespace nhill
{
namespace ctrl
{
namespace ab_oil_pressure_test_ui
{

class NHILL_ABOPT_UI_PORT_CLASS Ticket_property00
{
public:
	ctrl::Block uwi;
	ctrl::Block consol_interval_num;
	ctrl::Block well_name;
	ctrl::Block on_production_date;

	ctrl::Cell uwi_label;
	ctrl::Cell uwi_value;

	ctrl::Cell consol_interval_num_label;
	ctrl::Cell consol_interval_num_value;

	ctrl::Cell well_name_label;
	ctrl::Cell well_name_value;

	ctrl::Cell on_production_date_label;
	ctrl::Cell on_production_date_value;

	void clear();

	const ctrl::Cell& cell( const ctrl::Grid_pos& pos ) const;
};

}
}
}