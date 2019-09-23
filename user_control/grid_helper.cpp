#include "pch.h"
#include "grid_helper.h"
#include "block_helper.h"
#include <limits>

using namespace std;

auto nhill::ctrl::get_cell_extent( const Grid_row& grow, CDC& dc )->Row_cell_size
{
	Row_cell_size ext;

	ext.resize( 3 * grow.size() );

	for( size_t blk_col{ 0 }; blk_col < grow.size(); blk_col++ )
	{
		const Block* block{ grow[blk_col] };
		
		if( block == nullptr )
		{
			ext[blk_col] = { 0, 0 };
			ext[blk_col + 1] = { 0,0 };
			ext[blk_col + 2] = { 0,0 };
		}
		else
		{
			array<CSize, 3> blk_ext{ get_text_extent( *block, dc ) };
			ext[blk_col] = get<0>( blk_ext );
			ext[blk_col + 1] = get<1>( blk_ext );
			ext[blk_col + 2] = get<2>( blk_ext );
		}
	}

	return ext;
}

auto nhill::ctrl::get_cell_extent( const Grid& grid, CDC& dc )->Grid_cell_size
{
	Grid_cell_size gsz;
	gsz.reserve( grid.size() );

	for( const auto& grid_row : grid )
	{
		gsz.push_back( get_cell_extent( grid_row, dc ) );
	}

	return gsz;
}

auto nhill::ctrl::calculate_layout( const Grid_cell_size& extent )->Grid_cell_rect
{
	Grid_cell_rect grid_cell_rect;


	return grid_cell_rect;
}

void nhill::ctrl::calculate_layout_rows( Grid_cell_rect& grid_cell_rect, const Grid_cell_size& extent )
{
	// Calculate the top and bottom of every cell
	for( const auto& row_cell_size : extent )
	{
		Pos_size row_height{ 0 };
		for( const auto& col_cell_size : row_cell_size )
		{
			if( row_height < col_cell_size.cy )
			{
				row_height = col_cell_size.cy;
				and then what?
			}
		}
	}
}
