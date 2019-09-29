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
class Cell;





NHILL_USERCTRL_PORT_FUNCTION std::array<CSize, 3> get_sizes( const Block & block, CDC & dc );
NHILL_USERCTRL_PORT_FUNCTION void draw( const Block& block, CDC& dc );

}
}
