#include "block.h"
#include <algorithm>

using namespace std;

unsigned short nhill::ctrl::block_row( const Block& block )
{
	return block.label.row;
}

void nhill::ctrl::block_row( Block& block, Pos block_row )
{
	block.label.row = block_row;
	block.value.row = block_row;
	block.uom.row   = block_row;
}

unsigned short nhill::ctrl::block_col( const Block& block )
{
	return block.label.col / 3;
}

void nhill::ctrl::block_col( Block& block, Pos block_col )
{
	block.label.col = 3 * block_col;
	block.value.col = block.label.col + 1;
	block.uom.col   = block.label.col + 2;
}

long nhill::ctrl::width( const Block& block )
{
	return width( block.label ) + width( block.value ) + width( block.uom );
}

long nhill::ctrl::height( const Block& block )
{
	return (std::max)({ height( block.label ), height( block.value ), height( block.uom ) } );
}

void nhill::ctrl::clear( Block& block )
{
	clear( block.label );
	clear( block.value );
	clear( block.uom );
}

void nhill::ctrl::swap( Block& a, Block& b ) noexcept
{
	swap( a.label, b.label );
	swap( a.value, b.value );
	swap( a.uom, b.uom );
}
