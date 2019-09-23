#pragma once

#include "port.h"
#include "grid_pos.h"
#include "halign.h"
#include "valign.h"
#include <string>
#include <wtypes.h>

namespace nhill
{
namespace ctrl
{

class Cell
{
public:
	Pos row{ 0 };
	Pos col{ 0 };
	HAlign halign{ HAlign::left };
	VAlign valign{ VAlign::bottom };
	RECT rect{};

	COLORREF text_color{ RGB( 0,0,0 ) };
	COLORREF background_color{ RGB( 255,255,255 ) };
	LOGFONT logfont{};
	
	std::string text{};
};

}
}


namespace nhill
{
namespace ctrl
{

NHILL_USERCTRL_PORT_FUNCTION Grid_pos pos( const Cell& c );
NHILL_USERCTRL_PORT_FUNCTION void pos( Cell& c, const Grid_pos& pos );

NHILL_USERCTRL_PORT_FUNCTION long width( const Cell& c );
NHILL_USERCTRL_PORT_FUNCTION long height( const Cell& c );

NHILL_USERCTRL_PORT_FUNCTION void clear( Cell& c );
NHILL_USERCTRL_PORT_FUNCTION void swap( Cell& a, Cell& b ) noexcept;

}
}