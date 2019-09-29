#include "xml_config.h"
#include "xml_ticket.h"

using namespace std;
using namespace nhill::ctrl::ab_oil_pressure_test_ui;

template<>
tinyxml2::XMLElement* nhill::xml::make_element( tinyxml2::XMLDocument& doc, const Configuration& config, std::string element_name )
{
	using namespace tinyxml2;

	// Create an element name if none was provided.
	if( element_name.empty() )
		element_name = "configuration";

	XMLElement* element = doc.NewElement( element_name.c_str() );

	XMLElement* child = nullptr;

	child = make_element( doc, config.ticket(), "ticket" );
	element->LinkEndChild( child );

	return element;
}

template<>
tinyxml2::XMLError nhill::xml::from_handle( Configuration& config, tinyxml2::XMLHandle handle )
{
	using namespace tinyxml2;

	XMLError retrn = XMLError::XML_NO_ERROR;
	XMLError error = XMLError::XML_NO_ERROR;

	Ticket ticket;
	error = from_parent_handle( ticket, handle, "ticket" );
	if( error == XMLError::XML_NO_ERROR )
		config.ticket() = ticket;
	else
		retrn = error;

	return retrn;
}
