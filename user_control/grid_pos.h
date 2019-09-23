#pragma once

#include "port.h"
#include "grid_pos_def.h"
#include "../../gemeinsam/utility/compare.h"
#include <cstdint>

namespace nhill
{
namespace ctrl
{

/// <summary>Cell position.  The row and column of the cell in the grid.</summary>
class NHILL_USERCTRL_PORT_CLASS Grid_pos
{
public:
	Pos row{ 0 };
	Pos col{ 0 };
};

}
}

namespace nhill
{

template<> NHILL_USERCTRL_PORT_FUNCTION inline
Compare compare( const ctrl::Grid_pos& a, const ctrl::Grid_pos& b );

namespace ctrl
{

NHILL_USERCTRL_PORT_FUNCTION bool operator==( const Grid_pos& a, const Grid_pos& b );
NHILL_USERCTRL_PORT_FUNCTION bool operator!=( const Grid_pos& a, const Grid_pos& b );

NHILL_USERCTRL_PORT_FUNCTION bool operator<( const Grid_pos& a, const Grid_pos& b );
NHILL_USERCTRL_PORT_FUNCTION bool operator>( const Grid_pos& a, const Grid_pos& b );

NHILL_USERCTRL_PORT_FUNCTION bool operator<=( const Grid_pos& a, const Grid_pos& b );
NHILL_USERCTRL_PORT_FUNCTION bool operator>=( const Grid_pos& a, const Grid_pos& b );

NHILL_USERCTRL_PORT_FUNCTION void clear( Grid_pos& );
NHILL_USERCTRL_PORT_FUNCTION void swap( Grid_pos& a, Grid_pos& b );
}
}
