#include "xml_ticket_property.h"
#include "xml_ticket_property00.h"

using namespace std;
using namespace nhill::ctrl::ab_oil_pressure_test_ui;

template<>
tinyxml2::XMLElement* nhill::xml::make_element( tinyxml2::XMLDocument& doc, const Ticket_property& ticket_property, std::string element_name )
{
	using namespace tinyxml2;

	// Create an element name if none was provided.
	if( element_name.empty() )
		element_name = type::to_name<Ticket_property00>();

	XMLElement* element = doc.NewElement( element_name.c_str() );

	XMLElement* child = nullptr;

	child = make_element( doc, ticket_property.ticket_property00, "ticket_property00" );
	element->LinkEndChild( child );

	return element;
}

template<>
tinyxml2::XMLError nhill::xml::from_handle( Ticket_property& ticket_property, tinyxml2::XMLHandle handle )
{
	using namespace tinyxml2;

	XMLError retrn = XMLError::XML_NO_ERROR;
	XMLError error = XMLError::XML_NO_ERROR;

	Ticket_property00 ticket_property00;
	error = from_parent_handle( ticket_property00, handle, "ticket_property00" );
	if( error == XMLError::XML_NO_ERROR )
		ticket_property.ticket_property00 = ticket_property00;
	else
		retrn = error;

	return retrn;
}
