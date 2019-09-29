#include "pch.h"
#include "grid_helper.h"
#include "block_helper.h"
#include "cell_helper.h"
#include <limits>

using namespace std;

auto nhill::ctrl::to_grid( Block_ptr_container& block_ptrs )->Grid
{
	Pos_size rcnt{ block_ptrs.row_count() };	 // The number of cell rows
	Pos_size ccnt{ static_cast<Pos_size>(3 * block_ptrs.col_count()) }; // The number of cell columns

	Grid grid{ rcnt, ccnt };

	for( Pos_size r{ 0 }; r < rcnt; r++ )
	{
		for( Pos_size c{ 0 }; c < ccnt; c++ )
		{
			grid[r][c] = block_ptrs.cell_at( r, c );
		}
	}

	return grid;
}

auto nhill::ctrl::to_grid( Block_container& blocks )->Grid
{
	Pos_size rcnt{ blocks.row_count() };	 // The number of cell rows
	Pos_size ccnt{ static_cast<Pos_size>(3 * blocks.col_count()) }; // The number of cell columns

	Grid grid{ rcnt, ccnt };

	for( Pos_size r{ 0 }; r < rcnt; r++ )
	{
		for( Pos_size c{ 0 }; c < ccnt; c++ )
		{
			grid[r][c] = blocks.cell_at( r, c );
		}
	}

	return grid;
}


void nhill::ctrl::auto_size( Grid& grid, CDC& dc )
{
	for( Pos_size r{ 0 }; r < grid.row_count(); r++ )
	{
		for( Pos_size c{ 0 }; c < grid.col_count(); c++ )
		{
			Cell* cell{ grid[r][c] };
			if( cell != nullptr )
			{
				auto_size( *cell, dc );
			}
		}
	}
}
void nhill::ctrl::normalize_size( Grid_row& grid_row )
{
	long max_height{ 0 };
	for( Pos_size c{ 0 }; c < grid_row.col_count(); c++ )
	{
		Cell* cell{ grid_row[c] };
		if( cell != nullptr )
		{
			long h{ cell->height() };
			if( max_height < h )
			{
				max_height = h;
			}
		}
	}

	for( Pos_size c{ 0 }; c < grid_row.col_count(); c++ )
	{
		Cell* cell{ grid_row[c] };
		if( cell != nullptr )
		{
			cell->rect.top = 0;
			cell->rect.bottom = max_height;
		}
	}
}

void nhill::ctrl::normalize_size( Grid_col& grid_col )
{
	long max_width{ 0 };
	for( Pos_size r{ 0 }; r < grid_col.row_count(); r++ )
	{
		Cell* cell{ grid_col[r] };
		if( cell != nullptr )
		{
			long w{ cell->width() };
			if( max_width < w )
			{
				max_width = w;
			}
		}
	}

	for( Pos_size r{ 0 }; r < grid_col.row_count(); r++ )
	{
		Cell* cell{ grid_col[r] };
		if( cell != nullptr )
		{
			cell->rect.left = 0;
			cell->rect.right = max_width;
		}
	}
}

void nhill::ctrl::normalize_size( Grid& grid )
{
	for( Pos_size r{ 0 }; r < grid.row_count(); r++ )
	{
		Grid_row grid_row{ grid, r };
		normalize_size( grid_row );
	}

	for( Pos_size c{ 0 }; c < grid.col_count(); c++ )
	{
		Grid_col grid_col{ grid, c };
		normalize_size( grid_col );
	}
}

long nhill::ctrl::layout( Grid_row& grid_row, long top )
{
	// The height of all the cells in the row
	long hgt{ 0 }; 
	for( Pos_size c{ 0 }; c < grid_row.col_count(); c++ )
	{
		Cell* cell{ grid_row[c] };
		if( cell != nullptr )
		{
			hgt = cell->height();
			break; // All cells in the row have the same height
		}
	}

	// The bottom of the row
	long btm{ top + hgt };

	// Set the position of all cells in the row
	for( Pos_size c{ 0 }; c < grid_row.col_count(); c++ )
	{
		Cell* cell{ grid_row[c] };
		if( cell != nullptr )
		{
			cell->rect.top = top;
			cell->rect.bottom = btm;
		}
	}

	// Return the position of the bottom of the row
	return btm;
}

long nhill::ctrl::layout( Grid_col& grid_col, long left )
{
	// The width of the cells in the column
	long wdt{ 0 }; 
	for( Pos_size r{ 0 }; r < grid_col.row_count(); r++ )
	{
		Cell* cell{ grid_col[r] };
		if( cell != nullptr )
		{
			wdt = cell->width();
			break; // All cells in the column have the same width.
		}
	}

	// The right side of the column
	long rgt{ left + wdt };

	// Set the position of all cells in the column
	for( Pos_size r{ 0 }; r < grid_col.row_count(); r++ )
	{
		Cell* cell{ grid_col[r] };
		if( cell != nullptr )
		{
			cell->rect.left = left;
			cell->rect.right = rgt;
		}
	}

	// Return the position of the right side of the column
	return rgt;
}

long nhill::ctrl::layout( Grid& grid, long top, long left, long pad_top, long pad_left )
{
	for( Pos_size r{ 0 }; r < grid.row_count(); r++ )
	{
		Grid_row grid_row{ grid, r };
		top = layout( grid_row, top );
		top += pad_top;
	}

	for( Pos_size c{ 0 }; c < grid.col_count(); c++ )
	{
		Grid_col grid_col{ grid, c };
		left = layout( grid_col, left );
		left += pad_left;
	}

	return top; // This is actually the bottom of the grid
}

void nhill::ctrl::draw( Grid& grid, CDC& dc )
{
	for( Pos_size r{ 0 }; r < grid.row_count(); ++r )
	{
		Grid_row grid_row{ grid, r };
		for( Pos_size c{ 0 }; c < grid.col_count(); ++c )
		{
			Cell* cell{ grid_row[c] };
			if( cell != nullptr )
			{
				draw( *cell, dc );
			}
		}
	}
}
