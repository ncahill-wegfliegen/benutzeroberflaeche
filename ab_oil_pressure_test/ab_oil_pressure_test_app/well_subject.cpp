#include "well_subject.h"
#include "well_observer.h"
#include <algorithm>

using namespace std;

void nhill::Well_subject::attach( Well_observer& observer )
{
	observers_.push_back( &observer );
}

void nhill::Well_subject::detach( Well_observer& observer )
{
	auto itr{ find( observers_.cbegin(), observers_.cend(), &observer ) };
	if( itr != observers_.cend() )
	{
		observers_.erase( itr );
	}
}

void nhill::Well_subject::notify_well_changed( const Well_changed_event_args& event_args )
{
	for( auto&& observer : observers_ )
	{
		observer->on_well_changed( event_args );
	}
}
