#pragma once

#include "port.h"
#include "block.h"
#include <initializer_list>

namespace nhill
{
namespace ctrl
{

class NHILL_USERCTRL_PORT_CLASS Block_container : public std::vector<Block>
{
public:
	Pos_size row_count() const;
	Pos_size col_count() const;

	Block* at(Pos_size block_row, Pos_size block_col );
	Cell* cell_at(Pos_size cell_row, Pos_size cell_col );

};

}
}

namespace nhill
{
namespace ctrl
{

class NHILL_USERCTRL_PORT_CLASS Block_ptr_container : public std::vector<Block*>
{
public:
	using base = std::vector<Block*>;

	Block_ptr_container();
	Block_ptr_container( std::initializer_list<Block*> init );
	~Block_ptr_container();

	Pos_size row_count() const;
	Pos_size col_count() const;

	Block* at( Pos_size block_row, Pos_size block_col );
	Cell* cell_at( Pos_size cell_row, Pos_size cell_col );
};

}
}
