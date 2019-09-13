#pragma once

#include "combo.h"

namespace nhill
{
namespace ctrl
{

template<typename Value>
class Combo_gallery : public Combo<Value, CgsRibbonComboGalleryCtrl>
{
public:
   ~Combo_gallery() override;

};

}
}

template<typename Value> inline 
nhill::ctrl::Combo_gallery<Value>::~Combo_gallery()
{
}


