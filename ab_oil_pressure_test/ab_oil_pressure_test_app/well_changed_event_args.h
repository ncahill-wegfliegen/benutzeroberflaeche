#pragma once

#include "../../../gemeinsam/utility/event_args.h"
#include "../../../gemeinsam/uwi/uwi.h"
#include <string>
#include <filesystem>

namespace nhill
{

class Well_changed_event_args : public Event_args
{
public:
	Well_changed_event_args( const Uwi* uwi );
	~Well_changed_event_args();

	/// <summary>The currently selected UWI. A pointer to a UWI in the Document's UWI list.</summary>
	const Uwi* uwi;
};

}