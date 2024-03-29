#pragma once

#include "well_list_changed_event_args.h"
#include "test_changed_event_args.h"

namespace nhill
{

class Doc_observer
{
public:
   Doc_observer();
   virtual ~Doc_observer();

   virtual void on_well_list_changed( const Well_list_changed_event_args& event_args ) = 0;
   virtual void on_test_changed( const Test_changed_event_args& event_args ) = 0;
};

}
