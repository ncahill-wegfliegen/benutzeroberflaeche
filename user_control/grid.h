#pragma once

#include "port.h"
#include "block.h"
#include <vector>

namespace nhill
{
namespace ctrl
{

using Grid = std::vector<std::vector<Block*>>;
using Grid_row = std::vector<Block*>;
using Grid_col = std::vector<Block*>;

using Grid_cell_size = std::vector<std::vector<CSize>>;
using Grid_cell_rect = std::vector<std::vector<RECT>>;

using Row_cell_size = std::vector<CSize>;

NHILL_USERCTRL_PORT_FUNCTION Grid to_grid_array( Blocks& blocks );
NHILL_USERCTRL_PORT_FUNCTION Grid_row to_grid_row( Grid& grid, Pos_size block_row );
NHILL_USERCTRL_PORT_FUNCTION Grid_col to_grid_col( Grid& grid, Pos_size block_col );


}
}