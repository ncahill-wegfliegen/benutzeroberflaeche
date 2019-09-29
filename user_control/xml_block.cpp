#include "pch.h"
#include "xml_block.h"
#include "xml_cell.h"

using namespace std;
using namespace nhill::ctrl;

template<>
tinyxml2::XMLElement* nhill::xml::make_element( tinyxml2::XMLDocument& doc, const Block& block, std::string element_name )
{
	using namespace tinyxml2;

	// Create an element name if none was provided.
	if( element_name.empty() )
		element_name = "block";

	XMLElement* element = doc.NewElement( element_name.c_str() );

	XMLElement* child = nullptr;

	child = make_element( doc, block.label, "label" );
	element->LinkEndChild( child );

	child = make_element( doc, block.value, "value" );
	element->LinkEndChild( child );

	child = make_element( doc, block.uom, "uom" );
	element->LinkEndChild( child );

	return element;
}

template<>
tinyxml2::XMLError nhill::xml::from_handle( Block& block, tinyxml2::XMLHandle handle )
{
	using namespace tinyxml2;

	XMLError retrn = XMLError::XML_NO_ERROR;
	XMLError error = XMLError::XML_NO_ERROR;

	Cell cell;
	error = from_parent_handle( cell, handle, "label" );
	if( error == XMLError::XML_NO_ERROR )
		block.label = cell;
	else
		retrn = error;

	cell.clear();
	error = from_parent_handle( cell, handle, "value" );
	if( error == XMLError::XML_NO_ERROR )
		block.value = cell;
	else
		retrn = error;

	cell.clear();
	error = from_parent_handle( cell, handle, "uom" );
	if( error == XMLError::XML_NO_ERROR )
		block.uom = cell;
	else
		retrn = error;

	return retrn;
}