#pragma once

#include "cell_setting.h"

namespace nhill
{
namespace ctrl
{

class Ticket_setting_00
{
public:
	Cell_setting uwi_label;
	Cell_setting uwi_value;

	Cell_setting consol_interval_num_label;
	Cell_setting consol_interval_num_value;

	Cell_setting well_name_label;
	Cell_setting well_name_value;

	Cell_setting on_production_date_label;
	Cell_setting on_production_date_value;
};

}
}