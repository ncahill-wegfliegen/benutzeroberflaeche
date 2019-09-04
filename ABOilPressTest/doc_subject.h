#pragma once

#include "well_list_changed_event_args.h"
#include <vector>
#include <functional>

namespace nhill
{
class Doc_observer;

class Doc_subject
{
public:
	void attach( Doc_observer& observer);
	void detach( Doc_observer& observer );

	void notify_well_list_changed( const Well_list_changed_event_args& event_args );

private:
	std::vector<Doc_observer*> observers_;
};

}