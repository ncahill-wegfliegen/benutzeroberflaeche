#pragma once

#include "port.h"
#include "grid.h"
#include "block_container.h"
#include <array>

namespace nhill
{
namespace ctrl
{

NHILL_USERCTRL_PORT_FUNCTION Grid to_grid( Block_ptr_container& block_ptrs );
NHILL_USERCTRL_PORT_FUNCTION Grid to_grid( Block_container& blocks );
NHILL_USERCTRL_PORT_FUNCTION void auto_size( Grid& grid, CDC& dc );

NHILL_USERCTRL_PORT_FUNCTION void normalize_size( Grid_row& grid_row );
NHILL_USERCTRL_PORT_FUNCTION void normalize_size( Grid_col& grid_col );
NHILL_USERCTRL_PORT_FUNCTION void normalize_size( Grid& grid );

NHILL_USERCTRL_PORT_FUNCTION long layout( Grid_row& grid_row, long top );
NHILL_USERCTRL_PORT_FUNCTION long layout( Grid_col& grid_col, long left );
NHILL_USERCTRL_PORT_FUNCTION long layout( Grid& grid, long top = 0, long left = 0, long pad_top = 0, long pad_left = 0 );

NHILL_USERCTRL_PORT_FUNCTION void draw( Grid& grid, CDC& dc );

}
}
