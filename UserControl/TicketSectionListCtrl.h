#pragma once

#include "port.h"
#include "cell_index.h"
#include <map>

class NHILL_USERCONTROL_PORT_CLASS TicketSectionListCtrl :  public CMFCListCtrl
{
public:
	using Cell_text_colors = std::map<nhill::ctrl::Cell_index, COLORREF>;

	COLORREF cell_text_color( int row, int col ) const;
	void cell_text_color( int row, int col, COLORREF color );

protected:
	Cell_text_colors cell_text_colors_;

   virtual COLORREF OnGetCellTextColor( int row, int col ) override;
};

