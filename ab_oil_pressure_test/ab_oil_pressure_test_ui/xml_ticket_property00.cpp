#include "xml_ticket_property00.h"
#include "../../user_control/xml_cell.h"

using namespace std;
using namespace nhill::ctrl;
using namespace nhill::ctrl::ab_oil_pressure_test_ui;

template<>
tinyxml2::XMLElement* nhill::xml::make_element( tinyxml2::XMLDocument& doc, const Ticket_property00& ticket_property00, std::string element_name )
{
	using namespace tinyxml2;

	// Create an element name if none was provided.
	if( element_name.empty() )
		element_name = type::to_name<Ticket_property00>();

	XMLElement* element = doc.NewElement( element_name.c_str() );

	XMLElement* child = nullptr;

	child = make_element( doc, ticket_property00.uwi_label, "uwi_label" );
	element->LinkEndChild( child );

	child = make_element( doc, ticket_property00.uwi_value, "uwi_value" );
	element->LinkEndChild( child );

	child = make_element( doc, ticket_property00.consol_interval_num_label, "consol_interval_num_label" );
	element->LinkEndChild( child );

	child = make_element( doc, ticket_property00.consol_interval_num_value, "consol_interval_num_value" );
	element->LinkEndChild( child );

	child = make_element( doc, ticket_property00.well_name_label, "well_name_label" );
	element->LinkEndChild( child );

	child = make_element( doc, ticket_property00.well_name_value, "well_name_value" );
	element->LinkEndChild( child );

	child = make_element( doc, ticket_property00.on_production_date_label, "on_production_date_label" );
	element->LinkEndChild( child );

	child = make_element( doc, ticket_property00.on_production_date_value, "on_production_date_value" );
	element->LinkEndChild( child );

	return element;
}

template<>
tinyxml2::XMLError nhill::xml::from_handle( Ticket_property00& ticket_property00, tinyxml2::XMLHandle handle )
{
	using namespace tinyxml2;

	XMLError retrn = XMLError::XML_NO_ERROR;
	XMLError error = XMLError::XML_NO_ERROR;

	Cell cell;
	error = from_parent_handle( cell, handle, "uwi_label" );
	if( error == XMLError::XML_NO_ERROR )
		ticket_property00.uwi_label = cell;
	else
		retrn = error;

	clear( cell );
	error = from_parent_handle( cell, handle, "uwi_value" );
	if( error == XMLError::XML_NO_ERROR )
		ticket_property00.uwi_value = cell;
	else
		retrn = error;

	clear( cell );
	error = from_parent_handle( cell, handle, "consol_interval_num_label" );
	if( error == XMLError::XML_NO_ERROR )
		ticket_property00.consol_interval_num_label = cell;
	else
		retrn = error;

	clear( cell );
	error = from_parent_handle( cell, handle, "consol_interval_num_value" );
	if( error == XMLError::XML_NO_ERROR )
		ticket_property00.consol_interval_num_value = cell;
	else
		retrn = error;

	clear( cell );
	error = from_parent_handle( cell, handle, "well_name_label" );
	if( error == XMLError::XML_NO_ERROR )
		ticket_property00.well_name_label = cell;
	else
		retrn = error;

	clear( cell );
	error = from_parent_handle( cell, handle, "well_name_value" );
	if( error == XMLError::XML_NO_ERROR )
		ticket_property00.well_name_value = cell;
	else
		retrn = error;

	clear( cell );
	error = from_parent_handle( cell, handle, "on_production_date_label" );
	if( error == XMLError::XML_NO_ERROR )
		ticket_property00.on_production_date_label = cell;
	else
		retrn = error;

	clear( cell );
	error = from_parent_handle( cell, handle, "on_production_date_value" );
	if( error == XMLError::XML_NO_ERROR )
		ticket_property00.on_production_date_value = cell;
	else
		retrn = error;

	return retrn;
}
