#include "cell_index.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

nhill::ctrl::Cell_index::Cell_index()
	: row_{0}
	, col_{0}
{
}

nhill::ctrl::Cell_index::Cell_index( int row, int col )
	: row_{static_cast<value_type>(row)}
	, col_{static_cast<value_type>(col)}
{
}

nhill::ctrl::Cell_index::Cell_index( const Cell_index& ) = default;
auto nhill::ctrl::Cell_index::operator=( const Cell_index& )->Cell_index & = default;

nhill::ctrl::Cell_index::Cell_index( Cell_index&& ) noexcept = default;
auto nhill::ctrl::Cell_index::operator=( Cell_index&& ) noexcept->Cell_index & = default;

nhill::ctrl::Cell_index::~Cell_index() = default;

int nhill::ctrl::Cell_index::row() const
{
	return static_cast<int>(row_);
}

void nhill::ctrl::Cell_index::row( int value)
{
	row_ = static_cast<value_type>(value);
}

int nhill::ctrl::Cell_index::col() const
{
	return static_cast<int>(col_);
}

void nhill::ctrl::Cell_index::col( int value)
{
	col_ = static_cast<value_type>(value);
}

void nhill::ctrl::Cell_index::clear()
{
	row( 0 );
	col( 0 );
}

template<>
auto nhill::compare( const ctrl::Cell_index& a, const ctrl::Cell_index& b )->Compare
{
	if( a.row() < b.row() )
	{
		return Compare::less;
	}
	else if( a.row() == b.row() )
	{
		if( a.col() < b.col() )
		{
			return Compare::less;
		}
		else if( a.col() == b.col() )
		{
			return Compare::equal;
		}
	}
	return Compare::greater;
}

bool nhill::ctrl::operator==( const Cell_index& a, const Cell_index& b )
{
	return compare<const Cell_index&>(a,b) == Compare::equal;
}

bool nhill::ctrl::operator!=( const Cell_index& a, const Cell_index& b )
{
	return !(a == b);
}

bool nhill::ctrl::operator<( const Cell_index& a, const Cell_index& b )
{
	return compare<const Cell_index&>( a, b ) == Compare::less;
}

bool nhill::ctrl::operator>( const Cell_index& a, const Cell_index& b )
{
	return compare<const Cell_index&>( a, b ) == Compare::greater;
}

bool nhill::ctrl::operator<=( const Cell_index& a, const Cell_index& b )
{
	return !(a > b);
}

bool nhill::ctrl::operator>=( const Cell_index& a, const Cell_index& b )
{
	return !(a < b);
}

