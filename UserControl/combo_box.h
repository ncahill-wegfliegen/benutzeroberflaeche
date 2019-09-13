#pragma once

#include "combo.h"

class CBCGPComboBox;

namespace nhill
{
namespace ctrl
{

template<typename Value>
class Combo_box : public Combo<Value, CBCGPComboBox>
{
public:
   ~Combo_box() override;

};

}
}

template<typename Value> inline 
nhill::ctrl::Combo_box<Value>::~Combo_box()
{
}

