#pragma once

#include "port.h"
#include "../../user_control/block_container.h"

namespace nhill
{
namespace ctrl
{
namespace ab_oil_pressure_test_ui
{

class NHILL_ABOPT_UI_PORT_CLASS Ticket05
{
public:
	Block remark;

	void clear();
	void clear_value_text();
	Block_ptr_container block_ptrs();
};

}
}
}