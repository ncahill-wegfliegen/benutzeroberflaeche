#include "pch.h"
#include "cell.h"

using namespace std;

auto nhill::ctrl::pos( const Cell& c )->Grid_pos
{
	return { c.row, c.col };
}

void nhill::ctrl::pos( Cell& c, const Grid_pos& pos )
{
	c.row = pos.row;
	c.col = pos.col;
}

long nhill::ctrl::width( const Cell& c )
{
	return std::abs( c.rect.right - c.rect.left );
}

long nhill::ctrl::height( const Cell& c )
{
	return std::abs( c.rect.bottom - c.rect.top );
}

void nhill::ctrl::clear( Cell& c )
{
	c.row = 0;
	c.col = 0;
	c.halign = HAlign::left;
	c.valign = VAlign::bottom;
	c.rect = {};
	c.text_color = RGB( 0, 0, 0 );
	c.background_color = RGB( 255, 255, 255 );
	c.logfont = {};
	c.text.clear();
}

void nhill::ctrl::swap( Cell& a, Cell& b ) noexcept
{
	std::swap( a.row, b.row );
	std::swap( a.col, b.col );
	std::swap( a.halign, b.halign );
	std::swap( a.valign, b.valign );
	std::swap( a.rect, b.rect );
	std::swap( a.text_color, b.text_color );
	std::swap( a.background_color, b.background_color );
	std::swap( a.logfont, b.logfont );
	std::swap( a.text, b.text );
}
