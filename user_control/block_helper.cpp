#include "pch.h"
#include "block_helper.h"
#include "cell_helper.h"

using namespace std;



std::array<CSize, 3> nhill::ctrl::get_sizes( const Block & block, CDC & dc )
{
	return { 
		get_size( block.label, dc ), 
		get_size( block.value, dc ),
		get_size( block.uom  , dc ) 
	};
}

void nhill::ctrl::draw( const Block& block, CDC& dc )
{
	draw( block.label, dc );
	draw( block.value, dc );
	draw( block.uom  , dc );
}
