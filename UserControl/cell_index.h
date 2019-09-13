#pragma once

#include "port.h"
#include "../../dev/gemeinsam/utility/compare.h"
#include <cstdint>

namespace nhill
{
namespace ctrl
{

class NHILL_USERCONTROL_PORT_CLASS Cell_index
{
public:
	using value_type = uint8_t;

	Cell_index();
	Cell_index( int row, int col );

	Cell_index( const Cell_index& );
	Cell_index& operator=( const Cell_index& );

	Cell_index( Cell_index&& ) noexcept;
	Cell_index& operator=( Cell_index&& ) noexcept;

	~Cell_index();

	int row() const;
	void row( int );

	int col() const;
	void col( int );

	void clear();

private:
	value_type row_;
	value_type col_;
};

}
}

namespace nhill
{

template<> NHILL_USERCONTROL_PORT_FUNCTION inline
Compare compare( const ctrl::Cell_index& a, const ctrl::Cell_index& b );

namespace ctrl
{

NHILL_USERCONTROL_PORT_FUNCTION bool operator==( const Cell_index& a, const Cell_index& b );
NHILL_USERCONTROL_PORT_FUNCTION bool operator!=( const Cell_index& a, const Cell_index& b );

NHILL_USERCONTROL_PORT_FUNCTION bool operator<( const Cell_index& a, const Cell_index& b );
NHILL_USERCONTROL_PORT_FUNCTION bool operator>( const Cell_index& a, const Cell_index& b );

NHILL_USERCONTROL_PORT_FUNCTION bool operator<=( const Cell_index& a, const Cell_index& b );
NHILL_USERCONTROL_PORT_FUNCTION bool operator>=( const Cell_index& a, const Cell_index& b );

}
}
