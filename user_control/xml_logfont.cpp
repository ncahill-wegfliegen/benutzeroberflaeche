#include "pch.h"
#include "xml_logfont.h"

using namespace std;


template<>
tinyxml2::XMLElement* nhill::xml::make_element( tinyxml2::XMLDocument& doc, const LOGFONT& logfont, std::string element_name )
{
	using namespace tinyxml2;

	// Create an element name if none was provided.
	if( element_name.empty() )
		element_name = "LOGFONT";

	XMLElement* element = doc.NewElement( element_name.c_str() );

	XMLElement* child = nullptr;

	child = make_element( doc, logfont.lfHeight, "lfHeight" );
	element->LinkEndChild( child );

	child = make_element( doc, logfont.lfWidth, "lfWidth" );
	element->LinkEndChild( child );

	child = make_element( doc, logfont.lfEscapement, "lfEscapement" );
	element->LinkEndChild( child );

	child = make_element( doc, logfont.lfOrientation, "lfOrientation" );
	element->LinkEndChild( child );

	child = make_element( doc, logfont.lfWeight, "lfWeight" );
	element->LinkEndChild( child );

	child = make_element( doc, static_cast<unsigned short int>(logfont.lfItalic), "lfItalic" );
	element->LinkEndChild( child );

	child = make_element( doc, static_cast<unsigned short int>(logfont.lfUnderline), "lfUnderline" );
	element->LinkEndChild( child );

	child = make_element( doc, static_cast<unsigned short int>(logfont.lfStrikeOut), "lfStrikeOut" );
	element->LinkEndChild( child );

	child = make_element( doc, static_cast<unsigned short int>(logfont.lfCharSet), "lfCharSet" );
	element->LinkEndChild( child );

	child = make_element( doc, static_cast<unsigned short int>(logfont.lfOutPrecision), "lfOutPrecision" );
	element->LinkEndChild( child );

	child = make_element( doc, static_cast<unsigned short int>(logfont.lfClipPrecision), "lfClipPrecision" );
	element->LinkEndChild( child );

	child = make_element( doc, static_cast<unsigned short int>(logfont.lfQuality), "lfQuality" );
	element->LinkEndChild( child );

	child = make_element( doc, static_cast<unsigned short int>(logfont.lfPitchAndFamily), "lfPitchAndFamily" );
	element->LinkEndChild( child );

	child = make_element( doc, wstring{ logfont.lfFaceName }, "lfFaceName" );
	element->LinkEndChild( child );


	return element;
}

template<>
tinyxml2::XMLError nhill::xml::from_handle( LOGFONT& logfont, tinyxml2::XMLHandle handle )
{
	using namespace tinyxml2;

	XMLError retrn = XMLError::XML_NO_ERROR;
	XMLError error = XMLError::XML_NO_ERROR;

	LONG lfHeight;
	error = from_parent_handle( lfHeight, handle, "lfHeight" );
	if( error == XMLError::XML_NO_ERROR )
		logfont.lfHeight = lfHeight;
	else
		retrn = error;

	LONG lfWidth;
	error = from_parent_handle( lfWidth, handle, "lfWidth" );
	if( error == XMLError::XML_NO_ERROR )
		logfont.lfWidth = lfWidth;
	else
		retrn = error;

	LONG lfEscapement;
	error = from_parent_handle( lfEscapement, handle, "lfEscapement" );
	if( error == XMLError::XML_NO_ERROR )
		logfont.lfEscapement = lfEscapement;
	else
		retrn = error;

	LONG lfOrientation;
	error = from_parent_handle( lfOrientation, handle, "lfOrientation" );
	if( error == XMLError::XML_NO_ERROR )
		logfont.lfOrientation = lfOrientation;
	else
		retrn = error;

	LONG lfWeight;
	error = from_parent_handle( lfWeight, handle, "lfWeight" );
	if( error == XMLError::XML_NO_ERROR )
		logfont.lfWeight = lfWeight;
	else
		retrn = error;

	unsigned short int lfItalic;
	error = from_parent_handle( lfItalic, handle, "lfItalic" );
	if( error == XMLError::XML_NO_ERROR )
		logfont.lfItalic = static_cast<BYTE>( lfItalic );
	else
		retrn = error;

	unsigned short int lfUnderline;
	error = from_parent_handle( lfUnderline, handle, "lfUnderline" );
	if( error == XMLError::XML_NO_ERROR )
		logfont.lfUnderline = static_cast<BYTE>(lfUnderline);
	else
		retrn = error;

	unsigned short int lfStrikeOut;
	error = from_parent_handle( lfStrikeOut, handle, "lfStrikeOut" );
	if( error == XMLError::XML_NO_ERROR )
		logfont.lfStrikeOut = static_cast<BYTE>(lfStrikeOut);
	else
		retrn = error;

	unsigned short int lfCharSet;
	error = from_parent_handle( lfCharSet, handle, "lfCharSet" );
	if( error == XMLError::XML_NO_ERROR )
		logfont.lfCharSet = static_cast<BYTE>(lfCharSet);
	else
		retrn = error;

	unsigned short int lfOutPrecision;
	error = from_parent_handle( lfOutPrecision, handle, "lfOutPrecision" );
	if( error == XMLError::XML_NO_ERROR )
		logfont.lfOutPrecision = static_cast<BYTE>(lfOutPrecision);
	else
		retrn = error;

	unsigned short int lfClipPrecision;
	error = from_parent_handle( lfClipPrecision, handle, "lfClipPrecision" );
	if( error == XMLError::XML_NO_ERROR )
		logfont.lfClipPrecision = static_cast<BYTE>(lfClipPrecision);
	else
		retrn = error;

	unsigned short int lfQuality;
	error = from_parent_handle( lfQuality, handle, "lfQuality" );
	if( error == XMLError::XML_NO_ERROR )
		logfont.lfQuality = static_cast<BYTE>(lfQuality);
	else
		retrn = error;

	unsigned short int lfPitchAndFamily;
	error = from_parent_handle( lfPitchAndFamily, handle, "lfPitchAndFamily" );
	if( error == XMLError::XML_NO_ERROR )
		logfont.lfPitchAndFamily = static_cast<BYTE>(lfPitchAndFamily);
	else
		retrn = error;

	string lfFaceName;
	error = from_parent_handle( lfFaceName, handle, "lfFaceName" );
	if( error == XMLError::XML_NO_ERROR )
	{
		wstring wstr{ lfFaceName.cbegin(), lfFaceName.cend() };
		wcscpy_s( logfont.lfFaceName, wstr.c_str() );
	}
	else
		retrn = error;

	return retrn;
}