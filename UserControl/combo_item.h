#pragma once

#include <string>

namespace nhill
{
namespace ctrl
{

template<typename Value>
class Combo_item
{
public:
   using value_type = Value;

   Combo_item();
   Combo_item(const Value& value, const std::string& label );

   Combo_item(const Combo_item&);
   Combo_item& operator=(const Combo_item&);

   Combo_item(Combo_item&&);
   Combo_item& operator=(Combo_item&&);

   virtual ~Combo_item();

   virtual Value value() const;
   virtual void value(const Value&);

   virtual std::string label() const;
   virtual void label(const std::string&);

private:
   Value value_;
   std::string label_;
};

}
}


template<typename Value> inline
nhill::ctrl::Combo_item<Value>::Combo_item() = default;

template<typename Value> inline 
nhill::ctrl::Combo_item<Value>::Combo_item(const Value & value, const std::string & label)
   : value_{ value }
   , label_{ label }
{
}

template<typename Value> inline
nhill::ctrl::Combo_item<Value>::Combo_item(const Combo_item &) = default;

template<typename Value> inline
auto nhill::ctrl::Combo_item<Value>::operator=(const Combo_item &)->Combo_item & = default;

template<typename Value> inline 
nhill::ctrl::Combo_item<Value>::Combo_item(Combo_item &&) = default;

template<typename Value> inline
auto nhill::ctrl::Combo_item<Value>::operator=(Combo_item &&)->Combo_item & = default;

template<typename Value> inline
nhill::ctrl::Combo_item<Value>::~Combo_item() = default;

template<typename Value> inline
Value nhill::ctrl::Combo_item<Value>::value() const
{
   return value_;
}

template<typename Value> inline
void nhill::ctrl::Combo_item<Value>::value(const Value & value)
{
   value_ = value;
}

template<typename Value> inline 
std::string nhill::ctrl::Combo_item<Value>::label() const
{
   return label_;
}

template<typename Value> inline 
void nhill::ctrl::Combo_item<Value>::label(const std::string & label)
{
   label_ = label;
}

