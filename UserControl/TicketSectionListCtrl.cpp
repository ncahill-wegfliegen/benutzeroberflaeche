#include "pch.h"
#include "TicketSectionListCtrl.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

COLORREF TicketSectionListCtrl::cell_text_color( int row, int col ) const
{
	auto itr{ cell_text_colors_.find( { row, col } ) };
	if( itr == cell_text_colors_.end() )
	{
		return RGB( 0, 0, 0 );
	}
	else
	{
		return itr->second;
	}
}

void TicketSectionListCtrl::cell_text_color( int row, int col, COLORREF color )
{
	cell_text_colors_[{row, col}] = color;
}

COLORREF TicketSectionListCtrl::OnGetCellTextColor( int row, int col )
{
	auto itr{ cell_text_colors_.find( { row, col } ) };
	if( itr == cell_text_colors_.end() )
	{
		return CMFCListCtrl::OnGetCellTextColor( row, col );
	}
	else
	{
		return itr->second;
	}
}
