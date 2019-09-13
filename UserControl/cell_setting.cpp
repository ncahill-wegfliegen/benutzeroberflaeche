#include "pch.h"
#include "cell_setting.h"

nhill::ctrl::Cell_setting::Cell_setting( const Cell_index& cell_index, COLORREF text_color, const LOGFONT* logfont, std::string_view text )
	: cell_index_{cell_index}
	, text_color_{text_color}
	, font_{}
	, text_{text}
{
	if( logfont == nullptr )
	{
		LOGFONT lf{};
		font_.CreateFontIndirect( &lf );
	}
	else
	{
		font_.CreateFontIndirect( logfont );
	}
}

nhill::ctrl::Cell_setting::~Cell_setting()
{
	font_.DeleteObject();
}

auto nhill::ctrl::Cell_setting::cell_index() const->const Cell_index &
{
	return cell_index_;
}

auto nhill::ctrl::Cell_setting::text_color() const->COLORREF
{
	return text_color_;
}

void nhill::ctrl::Cell_setting::text_color( COLORREF value)
{
	text_color_ = value;
}

auto nhill::ctrl::Cell_setting::font() const->const CFont &
{
	return font_;
}

void nhill::ctrl::Cell_setting::font( const LOGFONT* lf)
{
	font_.DeleteObject();
	font_.CreateFontIndirect( lf );
}

auto nhill::ctrl::Cell_setting::text() const->const std::string &
{
	return text_;
}

void nhill::ctrl::Cell_setting::text( std::string_view value )
{
	text_ = value;
}
