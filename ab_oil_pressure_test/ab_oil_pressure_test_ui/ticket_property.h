#pragma once

#include "port.h"
#include "ticket00.h"
#include <filesystem>

namespace nhill
{
namespace ctrl
{
namespace ab_oil_pressure_test_ui
{


class NHILL_ABOPT_UI_PORT_CLASS Ticket_property
{
public:
	Ticket_property00 ticket_property00;

	void clear();

	bool load( const std::filesystem::path& path );
	bool save( const std::filesystem::path& path );
};

}
}
}