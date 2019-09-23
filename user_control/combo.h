#pragma once

#include "combo_item_container.h"
#include <algorithm>

namespace nhill
{
namespace ctrl
{

template<typename Value, typename Combo_base>
class Combo : public Combo_base
{
public:
   using base = Combo_base;
   using Items = Combo_item_container<Value>;

   virtual ~Combo();

   const Items& items() const;
   void items(const Items&);
   void items(Items&&);

   Value selected_value();
   void selected_value(const Value&);

   int selected_index();
   void selected_index(int);

   bool load();
   bool load(const Items& items);

   void auto_size();

   int set_dropped_width(unsigned width);
   bool get_info(COMBOBOXINFO& info);

protected:
   Combo();

private:
   Items items_;
   Value selected_value_;
   int selected_index_;
};

}
}


template<typename Value, typename Combo_base> inline 
nhill::ctrl::Combo<Value, Combo_base>::~Combo()
{
}

template<typename Value, typename Combo_base> inline
auto nhill::ctrl::Combo<Value, Combo_base>::items() const->const Items &
{
   return items_;
}

template<typename Value, typename Combo_base> inline 
void nhill::ctrl::Combo<Value, Combo_base>::items(const Items & items)
{
   items_.resize(items.size());
   std::copy(items.begin(), items.end(), items_.begin());

}

template<typename Value, typename Combo_base> inline 
void nhill::ctrl::Combo<Value, Combo_base>::items(Items && items)
{
   items_ = std::move(items);
}

template<typename Value, typename Combo_base> inline 
Value nhill::ctrl::Combo<Value, Combo_base>::selected_value()
{
   if (!::IsWindow(base::m_hWnd))
      return selected_value_;

   int ctrl_index = base::GetCurSel();
   if (ctrl_index == CB_ERR)
      return selected_value_;

   int item_index = base::GetItemData(ctrl_index);
   selected_value_ = items.at(item_index).value();

   return selected_value_;
}

template<typename Value, typename Combo_base> inline 
void nhill::ctrl::Combo<Value, Combo_base>::selected_value(const Value & value)
{
   selected_value_ = value;

   if (!::IsWindow(base::m_hWnd))
      return;

   base::SetCurSel(-1);

   // Find the index of the value in the item collection
   size_t item_index = 0;
   for (; item_index < items_.size(); ++item_index)
   {
      const auto& item = items_.at(item_index);
      if (item.value() == value)
         break;
   }
   if (item_index == items_.size())
      return;

   const auto& selected_item = items.at(item_index);

   // Find the label in the combo box that corresponds to the item
   for (int ctrl_index = 0; ctrl_index < base::GetCount(); ++ctrl_index)
   {
      if (base::::GetItemData(ctrl_index) == item_index)
      {
         base::SetCurSel(ctrl_index);
         break;
      }
   }
}

template<typename Value, typename Combo_base> inline 
int nhill::ctrl::Combo<Value, Combo_base>::selected_index()
{
   if (::IsWindow(base::m_hWnd))
      selected_index_ = base::::GetCurSel();

   return selected_index_;
}

template<typename Value, typename Combo_base> inline 
void nhill::ctrl::Combo<Value, Combo_base>::selected_index(int index)
{
   selected_index_ = index;

   if (::IsWindow(base::m_hWnd))
      selected_index_ = base::SetCurSel(selected_index_);
}

template<typename Value, typename Combo_base> inline 
bool nhill::ctrl::Combo<Value, Combo_base>::load()
{
   if (!::IsWindow(base::m_hWnd))
      return false;

   base::ResetContent();

   for (size_t item_index = 0; item_index < items_.size(); ++item_index)
   {
      const auto& item = items_[item_index];
      int ctrl_index = base::AddString(item.label().c_str());
      base::SetItemData(ctrl_index, item_index);
   }

   return true;
}
template<typename Value, typename Combo_base>
inline bool nhill::ctrl::Combo<Value, Combo_base>::load(const Items & items)
{
   this->items(items);
   return load();
}

template<typename Value, typename Combo_base>
inline void nhill::ctrl::Combo<Value, Combo_base>::auto_size()
{
}

template<typename Value, typename Combo_base> inline
nhill::ctrl::Combo<Value, Combo_base>::Combo()
   : items_{}
   , selected_value_{}
   , selected_index_{ -1 }
{
}
