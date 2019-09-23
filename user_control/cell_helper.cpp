#include "pch.h"
#include "cell_helper.h"
#include "../../gemeinsam/utility/str.h"

using namespace std;

CSize nhill::ctrl::get_text_extent( const Cell& cell, CDC& dc )
{
	// Set the properties 
	CFont font;
	font.CreateFontIndirect( &cell.logfont );
	CFont* font_orig{ dc.SelectObject( &font ) };

	COLORREF text_color_orig{ dc.SetTextColor( cell.text_color ) };
	COLORREF background_color_orig{ dc.SetBkColor( cell.background_color ) };

	// Determine the dimensions of the text
	wstring wtext{ str::to_wstring( cell.text ) };
	CRect rc{};
	dc.DrawText( wtext.c_str(), -1, &rc, DT_CALCRECT );

	// Set all properties back to original values
	dc.SetBkColor( background_color_orig );
	dc.SetTextColor( text_color_orig );
	dc.SelectObject( font_orig );

	// We don't need the font anymore
	font.DeleteObject();

	// Return the size of the text
	return { rc.Width(), rc.Height() };
}

void nhill::ctrl::set_text_extent( Cell& cell, CSize extent )
{
	cell.rect.left = 0;
	cell.rect.top = 0;
	cell.rect.right = extent.cx;
	cell.rect.bottom = extent.cy;
}

void nhill::ctrl::auto_size( Cell& cell, CDC& dc )
{
	CSize sz{ get_text_extent( cell,dc ) };
	set_text_extent( cell, sz );
}

void nhill::ctrl::draw( const Cell& cell, CDC& dc )
{
	// Set the properties 
	CFont font;
	font.CreateFontIndirect( &cell.logfont );
	CFont* font_orig{ dc.SelectObject( &font ) };

	COLORREF text_color_orig{ dc.SetTextColor( cell.text_color ) };
	COLORREF background_color_orig{ dc.SetBkColor( cell.background_color ) };

	// Setup the format flag for the drawing method
	UINT format{};
	switch( cell.halign )
	{
	case HAlign::left  : format |= DT_LEFT  ; break;
	case HAlign::center: format |= DT_CENTER; break;
	case HAlign::right : format |= DT_RIGHT ; break;
	}
	switch( cell.valign )
	{
	case VAlign::top	 : format |= DT_TOP    ; break;
	case VAlign::center: format |= DT_VCENTER; break;
	case VAlign::bottom: format |= DT_BOTTOM ; break;
	}

	// Draw the text
	wstring wtext{ str::to_wstring( cell.text ) };
	RECT rc{ cell.rect };
	dc.DrawText( wtext.c_str(), -1, &rc, format );

	// Set all properties back to original values
	dc.SetBkColor( background_color_orig );
	dc.SetTextColor( text_color_orig );
	dc.SelectObject( font_orig );

	// We don't need the font anymore
	font.DeleteObject();
}
