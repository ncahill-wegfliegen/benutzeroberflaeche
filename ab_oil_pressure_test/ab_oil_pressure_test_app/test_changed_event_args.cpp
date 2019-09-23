#include "test_changed_event_args.h"

nhill::Test_changed_event_args::Test_changed_event_args( const nhill::datenzugriff::ab_oil_pressure_test::Test* test )
   : test{test}
{
}

nhill::Test_changed_event_args::~Test_changed_event_args() = default;
