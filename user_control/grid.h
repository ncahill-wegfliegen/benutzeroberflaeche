#pragma once

#include "port.h"
#include "block.h"
#include "../../gemeinsam/utility/array2d.h"
#include <vector>

namespace nhill
{
namespace ctrl
{

using Grid = nhill::Array2D<Cell*>;
using Grid_row = nhill::Row2D<Cell*>;
using Grid_col = nhill::Col2D<Cell*>;

}
}