#pragma once

#include "port.h"
#include <memory>

namespace nhill
{
namespace ctrl
{

#pragma region Foreward Declarations
class User_control_panel;
#pragma endregion

/// <summary>In the resource properties set Border=None and Style=Child and Visible=true.</summary>
class NHILL_USERCTRL_PORT_CLASS User_control : public CDialog
{
    DECLARE_DYNAMIC( User_control )

#pragma region Constructors/Destructor
public:
    /// <summary>The default constructor is only called if you are going to call the Create method after.</summary>
    User_control();

    /// <summary>Construct a resource-based dialog box. Called in the constructor of the derived class.</summary>
    /// <param name="nIdOption">Contains the ID number of a dialog-box option resource.</param>
    /// <param name="parent_wnd">Points to the Panel to which the dialog object belongs. Cannot be NULL.</param>
    explicit User_control( UINT id_option, CWnd* parent_wnd = NULL );

    /// <summary>Construct a resource-based dialog box. Called in the constructor of the derived class.</summary>
    /// <param name="option_name">Contains a null-terminated string that is the name of a dialog-box option resource.</param>
    /// <param name="parent_wnd">Points to the Panel upon which the control object is placed. Cannot be NULL.</param>
    explicit User_control( LPCTSTR option_name, CWnd* parent_wnd = NULL );

    /// <summary>Crush, kill, destroy the instance of this object.</summary>
    virtual ~User_control();
#pragma endregion

#pragma region Properties
    bool is_window();

	 /// <summary>The panel upon which this control is placed.  This is the parent of the User_control.</summary>
	 User_control_panel& panel();

    bool panel_border();
    void panel_border( bool value );
#pragma endregion

#pragma region Methods
    /// <summary>Create a control using a dialog-box option from a resource.</summary>
    /// <param name="option_name">Contains a null-terminated string that is the name of a dialog-box option resource.</param>
    /// <param name="parent_wnd">Points to the Panel to which the dialog object belongs. Cannot be NULL. The control is resized to fit the panel.</param>
    virtual BOOL Create( LPCTSTR option_name, CWnd* parent_wnd = NULL ) override;

    /// <summary>Create a control using a dialog-box option from a resource.</summary>
    /// <param name="nIdOption">Contains the ID number of a dialog-box option resource.</param>
    /// <param name="parent_wnd">Points to the Panel to which the dialog object belongs. Cannot be NULL. The control is resized to fit the panel.</param>
    virtual BOOL Create( UINT id_option, CWnd* parent_wnd = NULL ) override;

    /// <summary>Sets the visibility state of the control.</summary>
    /// <param name="nCmdShow">Specifies how the control is to be shown.</param>
    /// <returns>Nonzero if the control was previously visible; 0 if the control was previously hidden.</returns>
    virtual bool show_window( int cmd_show );

    /// <summary>(Dis)able the control.</summary>
    /// <param name="enable">Set to true to enable the window and set to false to disable the window</param>
    virtual void enable_window( bool enable );

    virtual void background_color( COLORREF colorref );
#pragma endregion

#pragma region Private Methods
protected:
    virtual bool create();

    void push();
    void pull();

    bool radio_exchange( int idc_radio, int& value, bool pull );
    bool radio_pull( int idc_radio, int& value );
    bool radio_push( int idc_radio, int value );

    bool text_exchange( int idc_textbox, double& value, bool pull );
    bool text_pull( int idc_textbox, double& value );
    bool text_push( int idc_textbox, double value );

    virtual void DoDataExchange( CDataExchange* dx ) override {}
    afx_msg HBRUSH OnCtlColor( CDC* dc, CWnd* wnd, UINT ctl_color );
#pragma endregion

#pragma region Fields
private:
    bool panel_border_;
    std::unique_ptr<CBrush> brush_background_;
#pragma endregion

    DECLARE_MESSAGE_MAP()
};

}
}