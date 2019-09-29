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

class NHILL_USERCTRL_PORT_CLASS Cell
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

	Grid_pos pos() const;
	void pos(const Grid_pos& pos );

	long width() const;
	long height() const;

	void clear();
	void clear_label(Pos_size row = 0, Pos_size col = 0, const char* const text = nullptr );
	void clear_value(Pos_size row = 0, Pos_size col = 0 );
	void clear_uom(Pos_size row = 0, Pos_size col = 0, const char* const text = nullptr );

	void swap( Cell& other ) noexcept;
};

}
}


namespace nhill
{
namespace ctrl
{


NHILL_USERCTRL_PORT_FUNCTION void swap( Cell& a, Cell& b ) noexcept;

}
}