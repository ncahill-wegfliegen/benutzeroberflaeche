#pragma once

namespace nhill
{
namespace ctrl
{

enum class VAlign
{
	none,

	top,
	center,
	bottom
};

constexpr int VAlign_count{ static_cast<int>(VAlign::bottom) + 1 };

}
}

