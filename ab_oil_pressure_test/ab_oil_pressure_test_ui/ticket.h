#pragma once

#include "port.h"
#include "ticket00.h"
#include "ticket01.h"
#include "ticket02.h"
#include "ticket03.h"
#include "ticket04.h"
#include "ticket05.h"
#include <filesystem>
#include <vector>

namespace nhill
{
namespace ctrl
{
namespace ab_oil_pressure_test_ui
{


class NHILL_ABOPT_UI_PORT_CLASS Ticket
{
public:
	Ticket00 ticket00;
	Ticket01 ticket01;
	Ticket02 ticket02;
	Ticket03 ticket03;
	std::vector<Ticket04> ticket04c;
	std::vector<Ticket05> ticket05c;

	void clear();
	void clear_value_text();
};

}
}
}

namespace nhill
{
namespace ctrl
{
namespace ab_oil_pressure_test_ui
{

NHILL_ABOPT_UI_PORT_FUNCTION bool read ( Ticket& ticket, const std::filesystem::path& path );
NHILL_ABOPT_UI_PORT_FUNCTION bool write( const std::filesystem::path& path, const Ticket& ticket );

}
}
}