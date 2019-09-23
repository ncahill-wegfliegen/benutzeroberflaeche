#include "pch.h"
#include "xml_cell.h"
#include "xml_grid_pos.h"
#include "xml_logfont.h"
#include "halign_ex.h"
#include "valign_ex.h"

using namespace std;
using namespace nhill::ctrl;

template<>
tinyxml2::XMLElement* nhill::xml::make_element( tinyxml2::XMLDocument& doc, const Cell& cell, std::string element_name )
{
	using namespace tinyxml2;

	// Create an element name if none was provided.
	if( element_name.empty() )
		element_name = type::to_name<Cell>();

	XMLElement* element = doc.NewElement( element_name.c_str() );

	XMLElement* child = nullptr;

	child = make_element( doc, cell.row, "row" );
	element->LinkEndChild( child );

	child = make_element( doc, cell.col, "col" );
	element->LinkEndChild( child );

	child = make_element( doc, cell.halign, "halign" );
	element->LinkEndChild( child );

	child = make_element( doc, cell.valign, "valign" );
	element->LinkEndChild( child );

	// Do not store the rect.  It must be calculated from the device context.

	child = make_element( doc, cell.text_color, "text_color" );
	element->LinkEndChild( child );

	child = make_element( doc, cell.background_color, "background_color" );
	element->LinkEndChild( child );

	child = make_element( doc, cell.logfont, "logfont" );
	element->LinkEndChild( child );

	child = make_element( doc, cell.text, "text" );
	element->LinkEndChild( child );

	return element;
}

template<>
tinyxml2::XMLError nhill::xml::from_handle( Cell& cell, tinyxml2::XMLHandle handle )
{
	using namespace tinyxml2;

	XMLError retrn = XMLError::XML_NO_ERROR;
	XMLError error = XMLError::XML_NO_ERROR;

	int row;
	error = from_parent_handle( row, handle, "row" );
	if( error == XMLError::XML_NO_ERROR )
		cell.row = row;
	else
		retrn = error;

	int col;
	error = from_parent_handle( col, handle, "col" );
	if( error == XMLError::XML_NO_ERROR )
		cell.col = col;
	else
		retrn = error;

	HAlign halign;
	error = from_parent_handle( halign, handle, "halign" );
	if( error == XMLError::XML_NO_ERROR )
		cell.halign = halign;
	else
		retrn = error;

	VAlign valign;
	error = from_parent_handle( valign, handle, "valign" );
	if( error == XMLError::XML_NO_ERROR )
		cell.valign = valign;
	else
		retrn = error;

	COLORREF text_color;
	error = from_parent_handle( text_color, handle, "text_color" );
	if( error == XMLError::XML_NO_ERROR )
		cell.text_color = text_color;
	else
		retrn = error;

	COLORREF background_color;
	error = from_parent_handle( background_color, handle, "background_color" );
	if( error == XMLError::XML_NO_ERROR )
		cell.background_color = background_color;
	else
		retrn = error;

	LOGFONT logfont;
	error = from_parent_handle( logfont, handle, "logfont" );
	if( error == XMLError::XML_NO_ERROR )
		cell.logfont = logfont;
	else
		retrn = error;

	string text;
	error = from_parent_handle( text, handle, "text" );
	if( error == XMLError::XML_NO_ERROR )
		cell.text = text;
	else
		retrn = error;

	return retrn;
}