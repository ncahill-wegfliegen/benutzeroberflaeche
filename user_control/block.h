#pragma once

#include "port.h"
#include "cell.h"
#include <vector>

namespace nhill
{
namespace ctrl
{

class Block
{
public:
	Cell label;
	Cell value;
	Cell uom;
};

using Blocks = std::vector<Block>;

}
}

namespace nhill
{
namespace ctrl
{

NHILL_USERCTRL_PORT_FUNCTION unsigned short block_row( const Block& block);
NHILL_USERCTRL_PORT_FUNCTION void block_row( Block& block, Pos block_row );

NHILL_USERCTRL_PORT_FUNCTION unsigned short block_col( const Block& block );
NHILL_USERCTRL_PORT_FUNCTION void block_col( Block& block, Pos block_col );

NHILL_USERCTRL_PORT_FUNCTION long width( const Block& block );
NHILL_USERCTRL_PORT_FUNCTION long height( const Block& block );

NHILL_USERCTRL_PORT_FUNCTION void clear( Block& block );
NHILL_USERCTRL_PORT_FUNCTION void swap( Block& a, Block& b ) noexcept;
}
}
