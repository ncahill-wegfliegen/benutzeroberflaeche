#include "xml_ticket01.h"
#include "../../user_control/xml_block.h"

using namespace std;
using namespace nhill::ctrl;
using namespace nhill::ctrl::ab_oil_pressure_test_ui;

template<>
tinyxml2::XMLElement* nhill::xml::make_element( tinyxml2::XMLDocument& doc, const Ticket01& ticket01, std::string element_name )
{
	using namespace tinyxml2;

	// Create an element name if none was provided.
	if( element_name.empty() )
	{
		element_name = "ticket01";
	}

	XMLElement* element = doc.NewElement( element_name.c_str() );

	XMLElement* child = nullptr;

	child = make_element( doc, ticket01.licensee, "licensee" );
	element->LinkEndChild( child );

	child = make_element( doc, ticket01.survey_coord, "survey_coord" );
	element->LinkEndChild( child );

	child = make_element( doc, ticket01.well_status, "well_status" );
	element->LinkEndChild( child );

	return element;
}

template<>
tinyxml2::XMLError nhill::xml::from_handle( Ticket01& ticket01, tinyxml2::XMLHandle handle )
{
	using namespace tinyxml2;

	XMLError retrn = XMLError::XML_NO_ERROR;
	XMLError error = XMLError::XML_NO_ERROR;

	Block block;
	error = from_parent_handle( block, handle, "licensee" );
	if( error == XMLError::XML_NO_ERROR )
		ticket01.licensee = block;
	else
		retrn = error;

	block.clear();
	error = from_parent_handle( block, handle, "survey_coord" );
	if( error == XMLError::XML_NO_ERROR )
		ticket01.survey_coord = block;
	else
		retrn = error;

	block.clear();
	error = from_parent_handle( block, handle, "well_status" );
	if( error == XMLError::XML_NO_ERROR )
		ticket01.well_status = block;
	else
		retrn = error;

	return retrn;
}
