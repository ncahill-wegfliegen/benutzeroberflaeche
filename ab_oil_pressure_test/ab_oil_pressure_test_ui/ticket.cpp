#include "ticket.h"
#include "xml_ticket.h"

using namespace std;

void nhill::ctrl::ab_oil_pressure_test_ui::Ticket::clear()
{
	ticket00.clear();
	ticket01.clear();
	ticket02.clear();
	ticket03.clear();
	ticket04c.clear();
	ticket05c.clear();

	Ticket04 ticket04;
	ticket04.clear();
	ticket04c.push_back( ticket04 );
}

void nhill::ctrl::ab_oil_pressure_test_ui::Ticket::clear_value_text()
{
	ticket00.clear_value_text();
	ticket01.clear_value_text();
	ticket02.clear_value_text();
	ticket03.clear_value_text();

	for( auto&& ticket04 : ticket04c )
	{
		ticket04.clear_value_text();
	}

	for( auto&& ticket05 : ticket05c )
	{
		ticket05.clear_value_text();
	}
}


bool nhill::ctrl::ab_oil_pressure_test_ui::read( Ticket& ticket,  const filesystem::path& path )
{
	tinyxml2::XMLError error{ xml::read( ticket, path.string(), "ticket" ) };
	return error == tinyxml2::XMLError::XML_NO_ERROR;
}

bool nhill::ctrl::ab_oil_pressure_test_ui::write( const filesystem::path& path, const Ticket& ticket )
{
	tinyxml2::XMLError error{ xml::write( path.string(), ticket, "ticket" ) };
	return error == tinyxml2::XMLError::XML_NO_ERROR;
}

