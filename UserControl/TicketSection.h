#pragma once

#include "port.h"
#include "UserControl.h"
#include "TicketSectionListCtrl.h"
#include "resource.h"
#include <string>
#include <string_view>

class NHILL_USERCONTROL_PORT_CLASS TicketSection : public nhill::ctrl::UserControl
{
   DECLARE_DYNAMIC(TicketSection)

public:
   using base = nhill::ctrl::UserControl;

#ifdef AFX_DESIGN_TIME
   enum { IDD = IDD_TICKET_SECTION };
#endif

   TicketSection(CWnd* pParent = nullptr);   // standard constructor
   virtual ~TicketSection();

   std::string title() const;
   void title( std::string_view );

   TicketSectionListCtrl& list_control();

protected:
   mutable std::string title_;
   CStatic title_ctrl_;
	CFont title_font_;
   
	TicketSectionListCtrl list_ctrl_;
	CFont list_ctrl_font_;

	virtual bool create() override;

   virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	afx_msg int OnCreate( LPCREATESTRUCT lpCreateStruct );

   DECLARE_MESSAGE_MAP()
};
