#include "pch.h"
#include "cell.h"

using namespace std;

namespace
{

COLORREF gray{ RGB( 125, 125, 125 ) };
COLORREF black{ RGB( 0,0,0 ) };
COLORREF white{ RGB( 255, 255, 255 ) };

// Reset all cell properties to default
LOGFONT default_logfont()
{
	static LOGFONT lf{};
	if( lf.lfHeight == 0 )
	{
		lf.lfHeight = -14;
		wcscpy_s( lf.lfFaceName, L"Arial" );
	}
	return lf;
}

}

auto nhill::ctrl::Cell::pos() const ->Grid_pos
{
	return { row, col };
}

void nhill::ctrl::Cell::pos(const Grid_pos& pos )
{
	row = pos.row;
	col = pos.col;
}

long nhill::ctrl::Cell::width() const
{
	return std::abs( rect.right - rect.left );
}

long nhill::ctrl::Cell::height() const
{
	return std::abs( rect.bottom - rect.top );
}

void nhill::ctrl::Cell::clear()
{
	row = 0;
	col = 0;
	halign = HAlign::left;
	valign = VAlign::bottom;
	rect = {};
	text_color = black;
	background_color = white;
	logfont = default_logfont();
	text.clear();
}

void nhill::ctrl::Cell::clear_label( Pos_size r, Pos_size c, const char* const txt )
{
	row = r;
	col = c;
	halign = HAlign::right;
	valign = VAlign::bottom;
	rect = {};
	text_color = gray;
	background_color = white;
	logfont = default_logfont();
	if( txt == nullptr )
	{
		text.clear();
	}
	else
	{
		text = txt;
	}
}

void nhill::ctrl::Cell::clear_value( Pos_size r, Pos_size c )
{
	row = r;
	col = c;
	halign = HAlign::left;
	valign = VAlign::bottom;
	rect = {};
	text_color = black;
	background_color = white;
	logfont = default_logfont();
	text.clear();
}

void nhill::ctrl::Cell::clear_uom( Pos_size r, Pos_size c, const char* const txt )
{
	row = r;
	col = c;
	halign = HAlign::left;
	valign = VAlign::bottom;
	rect = {};
	text_color = black;
	background_color = white;
	logfont = default_logfont();
	if( txt == nullptr )
	{
		text.clear();
	}
	else
	{
		text = txt;
	}
}

void nhill::ctrl::Cell::swap( Cell& other ) noexcept
{
	std::swap( row, other.row );
	std::swap( col, other.col );
	std::swap( halign, other.halign );
	std::swap( valign, other.valign );
	std::swap( rect, other.rect );
	std::swap( text_color, other.text_color );
	std::swap( background_color, other.background_color );
	std::swap( logfont, other.logfont );
	std::swap( text, other.text );
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
