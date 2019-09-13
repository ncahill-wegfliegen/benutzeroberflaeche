#include "doc_subject.h"
#include "doc_observer.h"
#include <algorithm>

using namespace std;

void nhill::Doc_subject::attach( Doc_observer& observer )
{
   observers_.push_back( &observer );
}

void nhill::Doc_subject::detach( Doc_observer& observer )
{
   auto itr{ find( observers_.cbegin(), observers_.cend(), &observer) };
   if( itr != observers_.cend() )
   {
      observers_.erase( itr );
   }
}

void nhill::Doc_subject::notify_well_list_changed( const Well_list_changed_event_args& event_args )
{
   for( auto&& observer : observers_ )
   {
      observer->on_well_list_changed( event_args );
   }
}

void nhill::Doc_subject::notify_test_changed( const Test_changed_event_args& event_args )
{
   for( auto&& observer : observers_ )
   {
      observer->on_test_changed( event_args );
   }
}
