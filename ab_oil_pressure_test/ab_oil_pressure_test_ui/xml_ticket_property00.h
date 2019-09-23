#pragma once

#include "port.h"
#include "../../../gemeinsam/xml/core/make_element.h"
#include "../../../gemeinsam/xml/core/from_handle.h"
#include "../../../gemeinsam/xml/core/from_parent_handle.h"
#include "../../../gemeinsam/xml/core/read.h"
#include "../../../gemeinsam/xml/core/write.h"
#include "ticket00.h"

namespace nhill
{
namespace xml
{

template<> NHILL_ABOPT_UI_PORT_FUNCTION
tinyxml2::XMLElement* make_element( tinyxml2::XMLDocument& doc, const nhill::ctrl::ab_oil_pressure_test_ui::Ticket_property00& ticket_property00, std::string element_name );

template<> NHILL_ABOPT_UI_PORT_FUNCTION
tinyxml2::XMLError from_handle( nhill::ctrl::ab_oil_pressure_test_ui::Ticket_property00& ticket_property00, tinyxml2::XMLHandle handle );

}
}