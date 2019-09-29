#include "block_container.h"
#include <algorithm>

using namespace std;

nhill::ctrl::Block_ptr_container::Block_ptr_container() = default;

nhill::ctrl::Block_ptr_container::Block_ptr_container( initializer_list<Block*> init )
	: base{ init }
{
}

nhill::ctrl::Block_ptr_container::~Block_ptr_container() = default;

auto nhill::ctrl::Block_container::row_count() const->Pos_size
{
	auto itr{
		max_element(
			cbegin(),
			cend(),
			[]( const Block& a, const Block& b )
			{
				return a.row() < b.row();
			}
		)
	};

	if( itr == cend() )
	{
		return 0;
	}
	else
	{
		return itr->row() + 1;
	}
}

auto nhill::ctrl::Block_container::col_count() const->Pos_size
{
	auto itr{
		max_element(
			cbegin(),
			cend(),
			[]( const Block& a, const Block& b )
			{
				return a.col() < b.col();
			}
		)
	};

	if( itr == cend() )
	{
		return 0;
	}
	else
	{
		return itr->col() + 1;
	}
}

auto nhill::ctrl::Block_container::at(Pos_size brow, Pos_size bcol )->Block*
{
	auto itr{
		find_if(
			begin(),
			end(),
			[&brow,&bcol]( const Block& block )
			{
				return block.row() == brow && block.col() == bcol;
			}
		)
	};

	if( itr == end() )
	{
		return nullptr;
	}
	else
	{
		return &(*itr);
	}
}

auto nhill::ctrl::Block_container::cell_at(Pos_size crow, Pos_size ccol )->Cell*
{
	Pos_size brow{ crow };
	Pos_size bcol{ static_cast<Pos_size>(ccol / static_cast<Pos_size>(3)) };

	Block* blk{ at(brow, bcol ) };

	if( blk == nullptr )
	{
		return nullptr;
	}
	else
	{
		Pos_size c{ static_cast<Pos_size>(ccol % 3) };
		switch( c )
		{
		case 0: return &(blk->label);
		case 1: return &(blk->value);
		case 2: return &(blk->uom);
		default: return nullptr;
		}
	}
}

auto nhill::ctrl::Block_ptr_container::row_count() const->Pos_size
{
	auto itr{
		max_element(
			cbegin(),
			cend(),
			[]( const Block* a, const Block* b )
			{
				Pos arow{ a == nullptr ? NPos : a->row() };
				Pos brow{ b == nullptr ? NPos : b->row() };
				return arow < brow;
			}
		)
	};

	if( itr == cend() )
	{
		return 0;
	}
	else
	{
		return (*itr)->row() + 1;
	}
}

auto nhill::ctrl::Block_ptr_container::col_count() const->Pos_size
{
	auto itr{
		max_element(
			cbegin(),
			cend(),
			[]( const Block* a, const Block* b )
			{
				Pos acol{ a == nullptr ? NPos : a->col() };
				Pos bcol{ b == nullptr ? NPos : b->col() };
				return acol < bcol;
			}
		)
	};

	if( itr == cend() )
	{
		return 0;
	}
	else
	{
		return (*itr)->col() + 1;
	}
}

auto nhill::ctrl::Block_ptr_container::at( Pos_size brow, Pos_size bcol )->Block*
{
	auto itr{
		find_if(
			begin(),
			end(),
			[&brow,&bcol]( const Block* blk )
			{
				Pos blkrow{ blk == nullptr ? NPos : blk->row()};
				Pos blkcol{ blk == nullptr ? NPos : blk->col() };
				return blkrow == brow && blkcol == bcol;
			}
		)
	};

	if( itr == end() )
	{
		return nullptr;
	}
	else
	{
		return *itr;
	}
}

auto nhill::ctrl::Block_ptr_container::cell_at( Pos_size crow, Pos_size ccol )->Cell*
{
	Pos_size brow{ crow };
	Pos_size bcol{ static_cast<Pos_size>(ccol / static_cast<Pos_size>(3)) };

	Block* blk{ at( brow, bcol ) };

	if( blk == nullptr )
	{
		return nullptr;
	}
	else
	{
		Pos_size c{ static_cast<Pos_size>(ccol % 3) };
		switch( c )
		{
		case 0: return &(blk->label);
		case 1: return &(blk->value);
		case 2: return &(blk->uom);
		default: return nullptr;
		}
	}
}
