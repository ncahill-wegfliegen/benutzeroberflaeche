#pragma once

#include "../UserControl/cell_index.h"
#include "../UserControl/TicketSection.h"
#include <memory>

namespace nhill
{
namespace datenzugriff
{
namespace ab_oil_pressure_test
{
class Record00;
}
}
}

class TicketSection00 : public TicketSection
{
public:
	using base = TicketSection;
	using Record00 = nhill::datenzugriff::ab_oil_pressure_test::Record00;

	TicketSection00();
	TicketSection00( const Record00& );
	~TicketSection00();

	void initialize();

	const Record00& record() const;
	void record( const Record00& );

	static const nhill::ctrl::Cell_index uwi_label;
	static const nhill::ctrl::Cell_index uwi_value;

	static const nhill::ctrl::Cell_index consol_interval_num_label;
	static const nhill::ctrl::Cell_index consol_interval_num_value;

	static const nhill::ctrl::Cell_index well_name_label;
	static const nhill::ctrl::Cell_index well_name_value;

	static const nhill::ctrl::Cell_index on_production_date_label;
	static const nhill::ctrl::Cell_index on_production_date_value;

private:
	std::unique_ptr<Record00> rec00_;
};

