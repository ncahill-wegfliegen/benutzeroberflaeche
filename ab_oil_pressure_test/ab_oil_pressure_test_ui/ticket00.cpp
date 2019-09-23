#include "ticket00.h"
#include "../../user_control/grid_pos.h"
#include "../../user_control/halign.h"
#include "../../user_control/valign.h"

void nhill::ctrl::ab_oil_pressure_test_ui::Ticket_property00::clear()
{
	using namespace nhill::ctrl;

	// Reset all cell properties to default
	LOGFONT lf{};
	lf.lfHeight = -14;
	wcscpy_s( lf.lfFaceName, L"Arial" );

	//uwi_label.clear( 0, 0, HAlign::right, VAlign::top, RGB( 125, 125, 125 ), RGB(255, 255, 255), lf, "UWI" );
	//uwi_value.clear( 0, 1, HAlign::left, VAlign::top, RGB( 0, 0, 0 ), RGB( 255, 255, 255 ), lf, "" );

	//consol_interval_num_label.clear( 0, 2, HAlign::right, VAlign::top, RGB( 125, 125, 125 ), RGB( 255, 255, 255 ), lf, "Consol Interval Num" );
	//consol_interval_num_value.clear( 0, 3, HAlign::left, VAlign::top, RGB( 0, 0, 0 ), RGB( 255, 255, 255 ), lf, "" );

	//well_name_label.clear( 1, 0, HAlign::right, VAlign::top, RGB( 125, 125, 125 ), RGB( 255, 255, 255 ), lf, "Well Name" );
	//well_name_value.clear( 1, 1, HAlign::left, VAlign::top, RGB( 0, 0, 0 ), RGB( 255, 255, 255 ), lf, "" );

	//on_production_date_label.clear( 1, 2, HAlign::right, VAlign::top, RGB( 125, 125, 125 ), RGB( 255, 255, 255 ), lf, "On Production Date" );
	//on_production_date_value.clear( 1, 3, HAlign::left, VAlign::top, RGB( 0, 0, 0 ), RGB( 255, 255, 255 ), lf, "" );

	//uwi.row( 0 );
	//uwi.col( 0 );
}

auto nhill::ctrl::ab_oil_pressure_test_ui::Ticket_property00::cell( const ctrl::Grid_pos& pos ) const->const ctrl::Cell &
{
	if( ctrl::pos(uwi_label) == pos )
	{
		return uwi_label;
	}

	if( ctrl::pos( uwi_value) == pos )
	{
		return uwi_value;
	}

	if( ctrl::pos( consol_interval_num_label) == pos )
	{
		return consol_interval_num_label;
	}

	if( ctrl::pos( consol_interval_num_value) == pos )
	{
		return consol_interval_num_value;
	}

	if( ctrl::pos( well_name_label) == pos )
	{
		return well_name_label;
	}

	if( ctrl::pos( well_name_value) == pos )
	{
		return well_name_value;
	}

	if( ctrl::pos( on_production_date_label) == pos )
	{
		return on_production_date_label;
	}

	if( ctrl::pos( on_production_date_value) == pos )
	{
		return on_production_date_value;
	}

	throw std::exception( "Cannot find the cell index." );
}

