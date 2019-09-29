#include "xml_ticket00.h"
#include "../../user_control/xml_block.h"

using namespace std;
using namespace nhill::ctrl;
using namespace nhill::ctrl::ab_oil_pressure_test_ui;

template<>
tinyxml2::XMLElement* nhill::xml::make_element( tinyxml2::XMLDocument& doc, const Ticket00& ticket00, std::string element_name )
{
	using namespace tinyxml2;

	// Create an element name if none was provided.
	if( element_name.empty() )
		element_name = type::to_name<Ticket00>();

	XMLElement* element = doc.NewElement( element_name.c_str() );

	XMLElement* child = nullptr;

	child = make_element( doc, ticket00.uwi, "uwi" );
	element->LinkEndChild( child );

	child = make_element( doc, ticket00.consol_interval_num, "consol_interval_num" );
	element->LinkEndChild( child );

	child = make_element( doc, ticket00.well_name, "well_name" );
	element->LinkEndChild( child );

	child = make_element( doc, ticket00.on_production_date, "on_production_date" );
	element->LinkEndChild( child );

	return element;
}

template<>
tinyxml2::XMLError nhill::xml::from_handle( Ticket00& ticket00, tinyxml2::XMLHandle handle )
{
	using namespace tinyxml2;

	XMLError retrn = XMLError::XML_NO_ERROR;
	XMLError error = XMLError::XML_NO_ERROR;

	Block block;
	error = from_parent_handle( block, handle, "uwi" );
	if( error == XMLError::XML_NO_ERROR )
		ticket00.uwi = block;
	else
		retrn = error;

	block.clear();
	error = from_parent_handle( block, handle, "consol_interval_num" );
	if( error == XMLError::XML_NO_ERROR )
		ticket00.consol_interval_num = block;
	else
		retrn = error;

	block.clear();
	error = from_parent_handle( block, handle, "well_name" );
	if( error == XMLError::XML_NO_ERROR )
		ticket00.well_name = block;
	else
		retrn = error;

	block.clear();
	error = from_parent_handle( block, handle, "on_production_date" );
	if( error == XMLError::XML_NO_ERROR )
		ticket00.on_production_date = block;
	else
		retrn = error;

	return retrn;
}
