#include "pch.h"
#include "grid.h"
#include "block_helper.h"



//auto nhill::ctrl::get_row_count( const Grid& grid )->Pos_size
//{
//	Pos_size rcnt{ 0 };
//
//	return rcnt;
//}
//
//auto nhill::ctrl::get_col_count( const Grid& grid )->Pos_size
//{
//	Pos_size ccnt{ 0 };
//	return ccnt;
//}
//
//auto nhill::ctrl::to_grid_array( Blocks& blocks )->Grid
//{
//	Grid grid;
//
//	Pos_size blk_row_cnt{ block_row_count( blocks ) };
//	Pos_size blk_col_cnt{ block_col_count( blocks ) };
//
//	grid.resize( blk_row_cnt );
//	for( auto&& row : grid )
//	{
//		row.resize( blk_col_cnt );
//		for( auto&& block_ptr : row )
//		{
//			block_ptr = nullptr;
//		}
//	}
//
//	for( auto& block : blocks )
//	{
//		Pos row{ block_row( block ) };
//		Pos col{ block_col( block ) };
//
//		grid[row][col] = &block;
//	}
//
//	return grid;
//}
//
//auto nhill::ctrl::to_grid_row( Grid& grid, Pos_size block_row )->Grid_row
//{
//	return grid[block_row];
//}
//
//auto nhill::ctrl::to_grid_col( Grid& grid, Pos_size block_col ) -> Grid_col
//{
//	Grid_col gcol;
//
//	for( auto&& row : grid )
//	{
//		gcol.push_back( row[block_col] );
//	}
//
//	return gcol;
//}
