#include "pch.h"
#include "TicketSection00.h"
#include "../UserControl/abopt_config.h"
#include "../../dev/datenzugriff/ab_oil_pressure_test/ab_oil_pressure_test/record00.h"

using namespace std;
using namespace nhill::ab_oil_pressure_test_ui;

const nhill::ctrl::Cell_index uwi_label{ 0, 0 };
const nhill::ctrl::Cell_index uwi_value{ 0, 1 };

const nhill::ctrl::Cell_index consol_interval_num_label{ 0, 3 };
const nhill::ctrl::Cell_index consol_interval_num_value{ 0, 4 };

const nhill::ctrl::Cell_index well_name_label{ 1, 0 };
const nhill::ctrl::Cell_index well_name_value{ 1, 1 };

const nhill::ctrl::Cell_index on_production_date_label{ 1, 3 };
const nhill::ctrl::Cell_index on_production_date_value{ 1, 4 };

TicketSection00::TicketSection00()
	: rec00_{make_unique<Record00>()}
{
}

TicketSection00::TicketSection00( const Record00& rec00)
	: rec00_{make_unique<Record00>(rec00)}
{
}

TicketSection00::~TicketSection00()
{
}

void TicketSection00::initialize()
{
	const Configuration& config{ Configuration::instance() };

	TicketSectionListCtrl& list_ctrl{ base::list_control() };
	list_ctrl.InsertColumn( 0, _T( "label0" ), LVCFMT_RIGHT );
	list_ctrl.InsertColumn( 1, _T( "value0" ), LVCFMT_LEFT );
	list_ctrl.InsertColumn( 2, _T( "padding" ), LVCFMT_LEFT, 10 );
	list_ctrl.InsertColumn( 3, _T( "label1" ), LVCFMT_RIGHT );
	list_ctrl.InsertColumn( 4, _T( "value1" ), LVCFMT_LEFT );

	LVCOLUMNW lvc{};
	lvc.mask = LVCF_FMT;
	lvc.fmt = LVCFMT_RIGHT;
	list_ctrl.SetColumn( 0, &lvc );

	list_ctrl.InsertItem( 0, _T( "UWI:" ) );
	list_ctrl.SetItemText( 0, 1, _T( "" ) );

	list_ctrl.SetItemText( 0, 3, _T( "Consol Interval:" ) );
	list_ctrl.SetItemText( 0, 4, _T( "" ) );

	list_ctrl.InsertItem( 1, _T( "Well Name:" ) );
	list_ctrl.SetItemText( 1, 1, _T( "" ) );

	list_ctrl.SetItemText( 1, 3, _T( "On Production Date:" ) );
	list_ctrl.SetItemText( 1, 4, _T( "" ) );

	list_ctrl.SetColumnWidth( 0, LVSCW_AUTOSIZE );
	list_ctrl.SetColumnWidth( 1, LVSCW_AUTOSIZE );
	list_ctrl.SetColumnWidth( 3, LVSCW_AUTOSIZE );
	list_ctrl.SetColumnWidth( 4, LVSCW_AUTOSIZE );



	list_ctrl.cell_text_color( 0, 0, RGB( 100, 100, 100 ) );
	list_ctrl.cell_text_color( 0, 3, RGB( 100, 100, 100 ) );
	list_ctrl.cell_text_color( 1, 0, RGB( 100, 100, 100 ) );
	list_ctrl.cell_text_color( 1, 3, RGB( 100, 100, 100 ) );
}

auto TicketSection00::record() const->const Record00 &
{
	return *rec00_;
}

void TicketSection00::record( const Record00& value)
{
	*rec00_ = value;

	if( ::IsWindow( m_hWnd ) )
	{

	}
}
