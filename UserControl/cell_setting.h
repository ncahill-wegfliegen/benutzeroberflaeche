#pragma once

#include "cell_index.h"
#include <string>
#include <string_view>

namespace nhill
{
namespace ctrl
{

class Cell_setting
{
public:
	Cell_setting( const Cell_index& cell_index, COLORREF text_color = RGB(0,0,0), const LOGFONT* logfont = nullptr, std::string_view text = "" );
	~Cell_setting();

	const Cell_index& cell_index() const;

	COLORREF text_color() const;
	void text_color( COLORREF );

	const CFont& font() const;
	void font( const LOGFONT* );

	const std::string& text() const;
	void text( std::string_view );

private:
	const Cell_index cell_index_;
	COLORREF text_color_;
	CFont font_;
	std::string text_;
};

}
}