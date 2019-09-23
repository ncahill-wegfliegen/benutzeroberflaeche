#pragma once

#include "port.h"
#include "../../../datenzugriff/ab_oil_pressure_test/ab_oil_pressure_test/record_type.h"
#include <afxlistctrl.h>
#include <map>
#include <memory>


namespace nhill
{
namespace ctrl
{
namespace ab_oil_pressure_test_ui
{

class NHILL_ABOPT_UI_PORT_CLASS TicketSectionListCtrl : public CMFCListCtrl
{
public:
	using Record_type = nhill::datenzugriff::ab_oil_pressure_test::Record_type;

	TicketSectionListCtrl( Record_type record_type );
	virtual ~TicketSectionListCtrl();

	Record_type record_type() const;

	virtual bool create() = 0;

	static std::unique_ptr<TicketSectionListCtrl> create( Record_type record_type );

private:
	const Record_type record_type_;
};

}
}
}