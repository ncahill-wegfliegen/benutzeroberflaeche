#include "valign_ex.h"

template<> inline
const nhill::text::Bundle_container<nhill::ctrl::VAlign>& nhill::text::bundle_container<nhill::ctrl::VAlign>()
{
	using namespace nhill::ctrl;
	static const Bundle_container<VAlign> bundles{
		{ VAlign::none  , { "NA", "N/A", "none", "", "None" } },
		//
		{ VAlign::top   , { "top"    } },
		{ VAlign::center, { "center" } },
		{ VAlign::bottom, { "bottom" } },
	};

	return bundles;
}

template<>
nhill::ctrl::VAlign nhill::begin()
{
	return ctrl::VAlign::none;
}

template<>
nhill::ctrl::VAlign nhill::end()
{
	return static_cast<nhill::ctrl::VAlign>(nhill::ctrl::VAlign_count);
}
