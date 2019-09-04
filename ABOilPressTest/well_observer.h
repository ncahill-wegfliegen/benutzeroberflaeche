#pragma once

#include "well_changed_event_args.h"

namespace nhill
{

class Well_observer
{
public:
	Well_observer();
	virtual ~Well_observer();

	virtual void on_well_changed( const Well_changed_event_args& event_args ) = 0;
};

}
