#pragma once

#include "port.h"
#include "grid.h"
#include <array>

namespace nhill
{
namespace ctrl
{

NHILL_USERCTRL_PORT_FUNCTION Row_cell_size get_cell_extent( const Grid_row& grow, CDC& dc );
NHILL_USERCTRL_PORT_FUNCTION Grid_cell_size get_cell_extent( const Grid& grid, CDC& dc );

NHILL_USERCTRL_PORT_FUNCTION Grid_cell_rect calculate_layout( const Grid_cell_size& extent );
NHILL_USERCTRL_PORT_FUNCTION void calculate_layout_rows( Grid_cell_rect& grid_cell_rect, const Grid_cell_size& extent );
NHILL_USERCTRL_PORT_FUNCTION void calculate_layout_cols( Grid_cell_rect& grid_cell_rect, const Grid_cell_size& extent );


}
}
