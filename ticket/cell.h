#pragma once

#include "halign.h"
#include "valign.h"
#include <memory>
#include <string>
#include <string_view>

namespace nhill
{
namespace ticket
{
class Item;

class AFX_EXT_CLASS Cell
{
public:
	Cell( const Item* parent );
	~Cell();

	const Item* parent() const;

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

	const CRect& rect() const;
	void rect( const CRect& );

	const std::string& text() const;
	void text( std::string_view );

private:
#pragma warning(push)
#pragma warning(disable:4251)
	const Item* parent_;
	std::unique_ptr<CFont> font_;
	HAlign halign_;
	VAlign valign_;
	COLORREF text_color_;
	COLORREF background_color_;
	CRect rect_;
	std::string text_;
#pragma warning(pop)
};

}
}