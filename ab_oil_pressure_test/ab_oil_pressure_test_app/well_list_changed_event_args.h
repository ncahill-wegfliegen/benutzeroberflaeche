#pragma once

#include "../../../gemeinsam/utility/event_args.h"
#include "../../../gemeinsam/uwi/list.h"
#include <string>
#include <filesystem>

namespace nhill
{

class Well_list_changed_event_args : public Event_args
{
public:
	Well_list_changed_event_args( const nhill::uwi::List& uwi_list );
	~Well_list_changed_event_args();

	/// <summary>A reference to the Document's UWI list.</summary>
	const nhill::uwi::List& uwi_list;
};

}