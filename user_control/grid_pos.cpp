#include "grid_pos.h"
#include <utility>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

template<>
auto nhill::compare( const ctrl::Grid_pos& a, const ctrl::Grid_pos& b )->Compare
{
	if( a.row < b.row )
	{
		return Compare::less;
	}
	else if( a.row == b.row )
	{
		if( a.col < b.col )
		{
			return Compare::less;
		}
		else if( a.col == b.col )
		{
			return Compare::equal;
		}
	}
	return Compare::greater;
}

bool nhill::ctrl::operator==( const Grid_pos& a, const Grid_pos& b )
{
	return compare<const Grid_pos&>( a, b ) == Compare::equal;
}

bool nhill::ctrl::operator!=( const Grid_pos& a, const Grid_pos& b )
{
	return !(a == b);
}

bool nhill::ctrl::operator<( const Grid_pos& a, const Grid_pos& b )
{
	return compare<const Grid_pos&>( a, b ) == Compare::less;
}

bool nhill::ctrl::operator>( const Grid_pos& a, const Grid_pos& b )
{
	return compare<const Grid_pos&>( a, b ) == Compare::greater;
}

bool nhill::ctrl::operator<=( const Grid_pos& a, const Grid_pos& b )
{
	return !(a > b);
}

bool nhill::ctrl::operator>=( const Grid_pos& a, const Grid_pos& b )
{
	return !(a < b);
}

void nhill::ctrl::clear( Grid_pos& pos )
{
	pos.row = 0;
	pos.col = 0;
}

void nhill::ctrl::swap( Grid_pos& a, Grid_pos& b )
{
	std::swap( a.row, b.row );
	std::swap( a.col, b.col );
}
