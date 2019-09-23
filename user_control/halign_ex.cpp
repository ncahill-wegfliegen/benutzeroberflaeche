#include "halign_ex.h"

template<> inline
const nhill::text::Bundle_container<nhill::ctrl::HAlign>& nhill::text::bundle_container<nhill::ctrl::HAlign>()
{
	using namespace nhill::ctrl;
	static const Bundle_container<HAlign> bundles{
		{ HAlign::none  , { "NA", "N/A", "none", "", "None" } },
		//
		{ HAlign::left  , { "left"   } },
		{ HAlign::center, { "center" } },
		{ HAlign::right , { "right"  } },
	};

	return bundles;
}

template<>
nhill::ctrl::HAlign nhill::begin()
{
	return ctrl::HAlign::none;
}

template<>
nhill::ctrl::HAlign nhill::end()
{
	return static_cast<nhill::ctrl::HAlign>(nhill::ctrl::HAlign_count);
}
