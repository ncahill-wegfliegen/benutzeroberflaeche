#pragma once

#include "port.h"
#include "../../gemeinsam/xml/core/make_element.h"
#include "../../gemeinsam/xml/core/from_handle.h"
#include "../../gemeinsam/xml/core/from_parent_handle.h"
#include "../../gemeinsam/xml/core/read.h"
#include "../../gemeinsam/xml/core/write.h"

namespace nhill
{
namespace xml
{

template<> NHILL_USERCTRL_PORT_FUNCTION
tinyxml2::XMLElement* make_element( tinyxml2::XMLDocument& doc, const LOGFONT& logfont, std::string element_name );

template<> NHILL_USERCTRL_PORT_FUNCTION
tinyxml2::XMLError from_handle( LOGFONT& logfont, tinyxml2::XMLHandle handle );

}
}