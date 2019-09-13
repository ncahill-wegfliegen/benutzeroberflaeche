#include "pch.h"
#include "cell.h"
#include "item.h"
#include <limits>

using namespace std;

nhill::ticket::Cell::Cell( const Item* parent )
	: parent_{parent}
	, font_{nullptr}
	, halign_{HAlign::none }
	, valign_{ VAlign::none }
	, text_color_{(numeric_limits<COLORREF>::max)()}
	, background_color_{ (numeric_limits<COLORREF>::max)() }
	, rect_{}
	, text_{}
{
}

nhill::ticket::Cell::~Cell() = default;

auto nhill::ticket::Cell::parent() const->const Item*
{
	return parent_;
}

const CFont& nhill::ticket::Cell::font() const
{
	if( font_ )
	{
		return *font_;
	}
	else
	{
		return parent_->font();
	}
}

void nhill::ticket::Cell::font( const LOGFONT* logfont)
{
	if( logfont == nullptr )
	{
		font_ = nullptr;
	}
	else
	{
		if( !font_ )
		{
			font_ = make_unique<CFont>();
		}
		font_->CreateFontIndirect( logfont );
	}
}

auto nhill::ticket::Cell::halign() const->HAlign
{
	if( halign_ == HAlign::none )
	{
		return parent_->halign();
	}
	else
	{
		return halign_;
	}
}

void nhill::ticket::Cell::halign( HAlign value)
{
	halign_ = value;
}

auto nhill::ticket::Cell::valign() const->VAlign
{
	if( valign_ == VAlign::none )
	{
		return parent_->valign();
	}
	else
	{
		return valign_;
	}
}

void nhill::ticket::Cell::valign( VAlign value)
{
	valign_ = value;
}

COLORREF nhill::ticket::Cell::text_color() const
{
	if( text_color_ == (numeric_limits<COLORREF>::max)() )
	{
		return parent_->text_color();
	}
	else
	{
		return text_color_;
	}
}

void nhill::ticket::Cell::text_color( COLORREF value )
{
	text_color_ = value;
}

COLORREF nhill::ticket::Cell::background_color() const
{
	if( background_color_ == (numeric_limits<COLORREF>::max)() )
	{
		return parent_->background_color();
	}
	else
	{
		return background_color_;
	}
}

void nhill::ticket::Cell::background_color( COLORREF value )
{
	background_color_ = value;
}

const CRect& nhill::ticket::Cell::rect() const
{
	return rect_;
}

void nhill::ticket::Cell::rect( const CRect& value)
{
	rect_ = value;
}

const std::string& nhill::ticket::Cell::text() const
{
	return text_;
}

void nhill::ticket::Cell::text( std::string_view value)
{
	text_ = value;
}
