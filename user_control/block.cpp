#include "block.h"
#include "cell.h"
#include <algorithm>

using namespace std;

auto nhill::ctrl::Block::row() const->Pos
{
	return label.row;
}

void nhill::ctrl::Block::row( Pos block_row )
{
	label.row = block_row;
	value.row = block_row;
	uom.row   = block_row;
}

auto nhill::ctrl::Block::col() const->Pos
{
	return label.col / 3;
}

void nhill::ctrl::Block::col( Pos block_col )
{
	label.col = 3 * block_col;
	value.col = label.col + 1;
	uom.col   = label.col + 2;
}

long nhill::ctrl::Block::width() const
{
	return label.width() + value.width() + uom.width();
}

long nhill::ctrl::Block::height() const
{
	return (std::max)({ label.height(), value.height(), uom.height() } );
}

void nhill::ctrl::Block::clear( Pos brow, Pos bcol, const char* const label_text, const char* const uom_text )
{
	Pos crow{ brow };
	Pos ccol{ static_cast<Pos>(3 * bcol) };
	label.clear_label(crow, ccol, label_text);
	value.clear_value(crow, ccol + 1);
	uom  .clear_uom  (crow, ccol + 2, uom_text);
}

void nhill::ctrl::Block::clear_value_text()
{
	value.text.clear();
}

void nhill::ctrl::Block::swap( Block& other ) noexcept
{
	ctrl::swap( *this, other );
}

void nhill::ctrl::swap( Block& a, Block& b ) noexcept
{
	swap( a.label, b.label );
	swap( a.value, b.value );
	swap( a.uom  , b.uom );
}

