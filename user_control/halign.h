#pragma once

namespace nhill
{
namespace ctrl
{

enum class HAlign
{
	none,

	left,
	center,
	right
};

constexpr int HAlign_count{ static_cast<int>( HAlign::right ) + 1 };

}
}
