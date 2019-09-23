#include "ticket_property.h"
#include "xml_ticket_property.h"

using namespace std;

void nhill::ctrl::ab_oil_pressure_test_ui::Ticket_property::clear()
{
	ticket_property00.clear();
}

bool nhill::ctrl::ab_oil_pressure_test_ui::Ticket_property::load( const filesystem::path& path )
{
	Ticket_property ticket_property;
	tinyxml2::XMLError error{ xml::read( ticket_property, path.string(), "ticket_property" ) };
	if( error == tinyxml2::XMLError::XML_NO_ERROR )
	{
		*this = ticket_property;
	}
	return error == tinyxml2::XMLError::XML_NO_ERROR;
}

bool nhill::ctrl::ab_oil_pressure_test_ui::Ticket_property::save( const filesystem::path& path )
{
	tinyxml2::XMLError error{ xml::write( path.string(), *this, "ticket_property" ) };
	return error == tinyxml2::XMLError::XML_NO_ERROR;
}
