#pragma once

#include <vector>

namespace nhill
{
namespace ctrl
{

template<typename Value>
class Combo_item;

template<typename Value>
using Combo_item_container = std::vector<Combo_item<Value>>;

}
}
