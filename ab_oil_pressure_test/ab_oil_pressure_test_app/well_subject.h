#pragma once

#include "well_changed_event_args.h"
#include <vector>
#include <functional>

namespace nhill
{
class Well_observer;

class Well_subject
{
public:
	void attach( Well_observer& observer );
	void detach( Well_observer& observer );

	void notify_well_changed( const Well_changed_event_args& event_args );

private:
	std::vector<Well_observer*> observers_;
};

}