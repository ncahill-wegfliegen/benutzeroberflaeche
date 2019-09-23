#include "pch.h"
#include "block_helper.h"
#include "cell_helper.h"

using namespace std;

auto nhill::ctrl::block_row_count( const Blocks& blocks )->Pos_size
{
	auto itr{
		max_element(
			blocks.cbegin(),
			blocks.cend(),
			[]( const Block& a, const Block& b )
			{
				return block_row( a ) < block_row( b );
			}
		)
	};

	if( itr == blocks.cend() )
	{
		return 0;
	}
	else
	{
		return block_row( *itr ) + 1;
	}
}

auto nhill::ctrl::block_col_count( const Blocks& blocks )->Pos_size
{
	auto itr{
		max_element(
			blocks.cbegin(),
			blocks.cend(),
			[]( const Block& a, const Block& b )
			{
				return block_col( a ) < block_col( b );
			}
		)
	};

	if( itr == blocks.cend() )
	{
		return 0;
	}
	else
	{
		return block_col( *itr ) + 1;
	}
}

std::array<CSize, 3> nhill::ctrl::get_text_extent( const Block & block, CDC & dc )
{
	return { 
		get_text_extent( block.label, dc ), 
		get_text_extent( block.value, dc ),
		get_text_extent( block.uom  , dc ) 
	};
}

void nhill::ctrl::set_text_extent( Block& block, const std::array<CSize, 3> & extents )
{
	set_text_extent( block.label, get<0>( extents ) );
	set_text_extent( block.value, get<1>( extents ) );
	set_text_extent( block.uom  , get<2>( extents ) );
}

void nhill::ctrl::auto_size( Block& block, CDC& dc )
{
	array<CSize, 3> extents{ get_text_extent( block, dc ) };
	set_text_extent( block, extents );
}

void nhill::ctrl::draw( const Block& block, CDC& dc )
{
}
