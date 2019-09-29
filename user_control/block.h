#pragma once

#include "port.h"
#include "cell.h"
#include <vector>

namespace nhill
{
namespace ctrl
{

class NHILL_USERCTRL_PORT_CLASS Block
{
public:
	Cell label;
	Cell value;
	Cell uom;

	Pos row() const;
	void row( Pos block_row );

	Pos col() const;
	void col( Pos block_col );

	long width() const;
	long height() const;

	void clear( Pos block_row = 0, Pos block_col = 0, const char* const label_text = nullptr, const char* const uom_text = nullptr);
	void clear_value_text();
	void swap( Block& other ) noexcept;
};

}
}

namespace nhill
{
namespace ctrl
{

NHILL_USERCTRL_PORT_FUNCTION void swap( Block& a, Block& b ) noexcept;

}
}
