#include "pch.h"
#include "item.h"
#include "cell.h"

using namespace std;

nhill::ticket::Item::Item( const Item* parent )
	: parent_{ parent }
	, font_{ nullptr }
	, halign_{ HAlign::none }
	, valign_{ VAlign::none }
	, text_color_{ (numeric_limits<COLORREF>::max)() }
	, background_color_{ (numeric_limits<COLORREF>::max)() }
	, label_{make_unique<Cell>(this)}
	, value_{make_unique<Cell>(this)}
	, uom_{make_unique<Cell>(this)}
{
	label_->halign( HAlign::right );
	label_->valign( VAlign::middle );
	label_->text_color      ( RGB( 128, 128, 128 ) ); // grey
	label_->background_color( RGB( 256, 256, 256 ) ); // white
}

nhill::ticket::Item::~Item() = default;

const CFont& nhill::ticket::Item::font() const
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

void nhill::ticket::Item::font( const LOGFONT* logfont)
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

auto nhill::ticket::Item::halign() const->HAlign
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

void nhill::ticket::Item::halign( HAlign value)
{
	halign_ = value;
}

auto nhill::ticket::Item::valign() const->VAlign
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

void nhill::ticket::Item::valign( VAlign value)
{
	valign_ = value;
}

COLORREF nhill::ticket::Item::text_color() const
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

void nhill::ticket::Item::text_color( COLORREF value )
{
	text_color_ = value;
}

COLORREF nhill::ticket::Item::background_color() const
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

void nhill::ticket::Item::background_color( COLORREF value )
{
	background_color_ = value;
}

