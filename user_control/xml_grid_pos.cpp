#include "xml_grid_pos.h"

using namespace nhill::ctrl;

template<>
tinyxml2::XMLElement* nhill::xml::make_element( tinyxml2::XMLDocument& doc, const Grid_pos& grid_pos, std::string element_name )
{
	using namespace tinyxml2;

	// Create an element name if none was provided.
	if( element_name.empty() )
		element_name = type::to_name<Grid_pos>();

	XMLElement* element = doc.NewElement( element_name.c_str() );

	XMLElement* child = nullptr;

	child = make_element( doc, grid_pos.row, "row" );
	element->LinkEndChild( child );

	child = make_element( doc, grid_pos.col, "col" );
	element->LinkEndChild( child );

	return element;
}

template<>
tinyxml2::XMLError nhill::xml::from_handle( Grid_pos& grid_pos, tinyxml2::XMLHandle handle )
{
	using namespace tinyxml2;

	XMLError retrn = XMLError::XML_NO_ERROR;
	XMLError error = XMLError::XML_NO_ERROR;

	int row;
	error = from_parent_handle( row, handle, "row" );
	if( error == XMLError::XML_NO_ERROR )
		grid_pos.row = row;
	else
		retrn = error;

	int col;
	error = from_parent_handle( col, handle, "col" );
	if( error == XMLError::XML_NO_ERROR )
		grid_pos.col = col;
	else
		retrn = error;

	return retrn;
}