#include "xml_ticket.h"
#include "xml_ticket00.h"
#include "xml_ticket01.h"

using namespace std;
using namespace tinyxml2;
using namespace nhill::ctrl::ab_oil_pressure_test_ui;

template<>
tinyxml2::XMLElement* nhill::xml::make_element( tinyxml2::XMLDocument& doc, const Ticket& ticket, std::string element_name )
{
	// Create an element name if none was provided.
	if( element_name.empty() )
	{
		element_name = "ticket";
	}

	XMLElement* element = doc.NewElement( element_name.c_str() );

	XMLElement* child{ make_element( doc, ticket.ticket00, "ticket00" ) };
	element->LinkEndChild( child );

	child = make_element( doc, ticket.ticket01, "ticket01" );
	element->LinkEndChild( child );

	return element;
}

template<>
tinyxml2::XMLError nhill::xml::from_handle( Ticket& ticket, tinyxml2::XMLHandle handle )
{
	XMLError retrn = XMLError::XML_NO_ERROR;
	XMLError error = XMLError::XML_NO_ERROR;

	Ticket00 ticket00;
	error = from_parent_handle( ticket00, handle, "ticket00" );
	if( error == XMLError::XML_NO_ERROR )
		ticket.ticket00 = ticket00;
	else
		retrn = error;

	return retrn;
}
