#pragma once

#include "halign.h"
#include "valign.h"
#include <memory>

namespace nhill
{
namespace ticket
{
class Cell;

class AFX_EXT_CLASS Item
{
public:
	Item( const Item* parent );
	~Item();

	const CFont& font() const;
	void font( const LOGFONT* );

	HAlign halign() const;
	void halign( HAlign );

	VAlign valign() const;
	void valign( VAlign );

	COLORREF text_color() const;
	void text_color( COLORREF );

	COLORREF background_color() const;
	void background_color( COLORREF );

private:
#pragma warning(push)
#pragma warning(disable:4251)
	const Item* parent_;
	std::unique_ptr<CFont> font_;
	HAlign halign_;
	VAlign valign_;
	COLORREF text_color_;
	COLORREF background_color_;

	std::unique_ptr<Cell> label_;
	std::unique_ptr<Cell> value_;
	std::unique_ptr<Cell> uom_;
#pragma warning(pop)
};

}
}