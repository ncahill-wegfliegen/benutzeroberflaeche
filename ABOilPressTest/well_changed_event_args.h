#pragma once

#include "../../dev/gemeinsam/utility/event_args.h"
#include "../../dev/gemeinsam/uwi/uwi.h"
#include <string>
#include <filesystem>

namespace nhill
{

class Well_changed_event_args : public Event_args
{
public:
	Well_changed_event_args( const Uwi& uwi );
	~Well_changed_event_args();

	/// <summary>The currently selected UWI. A reference to a UWI in the Document's UWI list.</summary>
	const Uwi& uwi;
};

}