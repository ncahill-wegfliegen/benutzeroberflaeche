#pragma once

#include "../../../gemeinsam/utility/event_args.h"
#include "../../../datenzugriff/ab_oil_pressure_test/ab_oil_pressure_test/test.h"
#include <string>
#include <filesystem>

namespace nhill
{

class Test_changed_event_args : public Event_args
{
public:
   Test_changed_event_args( const nhill::datenzugriff::ab_oil_pressure_test::Test* test );
   ~Test_changed_event_args();

   /// <summary>The currently selected test. A reference to a test in the Document.</summary>
   const nhill::datenzugriff::ab_oil_pressure_test::Test* test;
};

}