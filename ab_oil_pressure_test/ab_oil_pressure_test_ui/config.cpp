#include "pch.h"
#include "config.h"
#include "ticket_property.h"
#include "xml_config.h"
#include <shlobj_core.h >

using namespace std;
namespace std
{
namespace fs = std::filesystem;
}

auto nhill::ctrl::ab_oil_pressure_test_ui::Configuration::instance()->Configuration &
{
	static Configuration inst;
	return inst;
}

nhill::ctrl::ab_oil_pressure_test_ui::Configuration::Configuration()
	: ticket_property_{ make_unique<Ticket_property>()}
{
	clear();

	PWSTR wpath_ptr{ nullptr };
	::SHGetKnownFolderPath( FOLDERID_LocalAppData, KF_FLAG_DEFAULT_PATH, NULL, &wpath_ptr );

	path_ = wpath_ptr;

	path_ /= company_name;
	if( !fs::exists( path_ ) )
	{
		error_code err{};
		bool created{ fs::create_directory( path_, err ) };
		if( !created )
		{
			string msg{ err.message() };
		}
	}
	
	path_ /= product_name;
	if( !fs::exists( path_ ) )
	{
		error_code err{};
		bool created{ fs::create_directory( path_, err ) };
		if( !created )
		{
			string msg{ err.message() };
		}
	}
	
	path_ /= config_subdir;
	if( !fs::exists( path_ ) )
	{
		error_code err{};
		bool created{ fs::create_directory( path_, err ) };
		if( !created )
		{
			string msg{ err.message() };
		}
	}

	path_ /= file_name;
	if( fs::exists( path_ ) )
	{
		tinyxml2::XMLError error{ xml::read( *this, path_.string(), root_name ) };
	}
}

nhill::ctrl::ab_oil_pressure_test_ui::Configuration::~Configuration()
{
	xml::write( path_.string(), *this, root_name );
}

auto nhill::ctrl::ab_oil_pressure_test_ui::Configuration::path() const->const fs::path &
{
	return path_;
}

auto nhill::ctrl::ab_oil_pressure_test_ui::Configuration::ticket_property() const->Ticket_property &
{
	return *ticket_property_;
}

void nhill::ctrl::ab_oil_pressure_test_ui::Configuration::clear()
{
	ticket_property_->clear();
}
