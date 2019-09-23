#pragma once

#include "port.h"
#include "block.h"
#include "halign.h"
#include "valign.h"
#include <array>

namespace nhill
{
namespace ctrl
{


NHILL_USERCTRL_PORT_FUNCTION Pos_size block_row_count( const Blocks& blocks );
NHILL_USERCTRL_PORT_FUNCTION Pos_size block_col_count( const Blocks& blocks );

NHILL_USERCTRL_PORT_FUNCTION std::array<CSize, 3> get_text_extent( const Block & block, CDC & dc );
NHILL_USERCTRL_PORT_FUNCTION void set_text_extent( Block& block, const std::array<CSize, 3>& extents );
NHILL_USERCTRL_PORT_FUNCTION void auto_size( Block& block, CDC& dc );

NHILL_USERCTRL_PORT_FUNCTION void draw( const Block& block, CDC& dc );

}
}
