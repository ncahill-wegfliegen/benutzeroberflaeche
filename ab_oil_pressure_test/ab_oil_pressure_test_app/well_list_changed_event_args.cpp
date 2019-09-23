#include "well_list_changed_event_args.h"

nhill::Well_list_changed_event_args::Well_list_changed_event_args( const nhill::uwi::List& uwi_list )
	: uwi_list{ uwi_list }
{
}

nhill::Well_list_changed_event_args::~Well_list_changed_event_args() = default;
