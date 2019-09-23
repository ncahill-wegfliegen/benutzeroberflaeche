#pragma once

#include "port.h"
#include <filesystem>
#include <memory>

namespace nhill
{
namespace ctrl
{
namespace ab_oil_pressure_test_ui
{
class Ticket_property;

class NHILL_ABOPT_UI_PORT_CLASS Configuration final
{
public:
	static Configuration& instance();

	~Configuration();

	static constexpr const char* const company_name{ "Bemühen" };
	static constexpr const char* const product_name{ "ab_oil_pressure_test" };
	static constexpr const char* const config_subdir{ "config" };
	static constexpr const char* const file_name{ "Benutzeroberfläche.config" };
	static constexpr const char* const root_name{ "configuration" };

	const std::filesystem::path& path() const;

	Ticket_property& ticket_property() const;

private:
	Configuration();

	std::filesystem::path path_;
	std::unique_ptr<Ticket_property> ticket_property_;

	void clear();
};

}
}
}