#pragma once

#include "port.h"
#include "cell.h"

namespace nhill
{
namespace ctrl
{

NHILL_USERCTRL_PORT_FUNCTION CSize get_size( const Cell& cell, CDC& dc );
NHILL_USERCTRL_PORT_FUNCTION void auto_size( Cell& cell, CDC& dc );
NHILL_USERCTRL_PORT_FUNCTION void draw( const Cell& cell, CDC& dc );

}
}