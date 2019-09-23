#pragma once

#include "halign.h"

#pragma region Extensions: to_code, to_abbreviation, etc.; stream operators << and >>.
#include "port.h"
#include "../../gemeinsam/enum/core/text/bundle_container.h"
#include "../../gemeinsam/enum/core/values.h"

#pragma region Specialize bundle_container: do not use directly; use text methods to_code, to_abbreviation, etc. instead.
template<> NHILL_USERCTRL_PORT_FUNCTION
const nhill::text::Bundle_container<nhill::ctrl::HAlign>& nhill::text::bundle_container<nhill::ctrl::HAlign>();
#pragma endregion

#pragma region Values
template<> NHILL_USERCTRL_PORT_FUNCTION nhill::ctrl::HAlign nhill::begin();
template<> NHILL_USERCTRL_PORT_FUNCTION nhill::ctrl::HAlign nhill::end();
#pragma endregion

#include "../../gemeinsam/enum/core/text/methods.h"
#include "../../gemeinsam/enum/core/text/stream_in.h"
#include "../../gemeinsam/enum/core/text/stream_out.h"
#pragma endregion

