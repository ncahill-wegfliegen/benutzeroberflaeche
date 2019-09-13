#pragma once

#include "port.h"

namespace nhill
{
namespace ctrl
{

#pragma region Foreward Declarations
class UserControlPanel;
#pragma endregion

/// <summary>In the resource properties set Border=None and Style=Child and Visible=true.</summary>
class NHILL_USERCONTROL_PORT_CLASS UserControl : public CDialog
{
    DECLARE_DYNAMIC( UserControl )

#pragma region Constructors/Destructor
public:
    /// <summary>The default constructor is only called if you are going to call the Create method after.</summary>
    UserControl();

    /// <summary>Construct a resource-based dialog box. Called in the constructor of the derived class.</summary>
    /// <param name="nIdOption">Contains the ID number of a dialog-box option resource.</param>
    /// <param name="pParentWnd">Points to the Panel to which the dialog object belongs. Cannot be NULL.</param>
    explicit UserControl( UINT nIDOption, CWnd* pParentWnd = NULL );

    /// <summary>Construct a resource-based dialog box. Called in the constructor of the derived class.</summary>
    /// <param name="lpszOptionName">Contains a null-terminated string that is the name of a dialog-box option resource.</param>
    /// <param name="pParentWnd">Points to the Panel upon which the control object is placed. Cannot be NULL.</param>
    explicit UserControl( LPCTSTR lpszOptionName, CWnd* pParentWnd = NULL );

    /// <summary>Crush, kill, destroy the instance of this object.</summary>
    virtual ~UserControl();
#pragma endregion

#pragma region Properties
public:
    bool GetIsWindow();
    __declspec(property(get = GetIsWindow)) bool IsWindow;

    UserControlPanel& GetPanel();
    /// <summary>The panel upon which this control is placed.  This is the parent of the UserControl.</summary>
    __declspec(property(get = GetPanel, put = SetPanel)) UserControlPanel& Panel;

    bool GetPanelBorder();
    void SetPanelBorder( bool value );
    __declspec(property(get = GetPanelBorder, put = SetPanelBorder)) bool PanelBorder;
#pragma endregion

#pragma region Methods
public:
    /// <summary>Create a control using a dialog-box option from a resource.</summary>
    /// <param name="lpszOptionName">Contains a null-terminated string that is the name of a dialog-box option resource.</param>
    /// <param name="pParentWnd">Points to the Panel to which the dialog object belongs. Cannot be NULL. The control is resized to fit the panel.</param>
    virtual BOOL Create( LPCTSTR lpszOptionName, CWnd* pParentWnd = NULL );

    /// <summary>Create a control using a dialog-box option from a resource.</summary>
    /// <param name="nIdOption">Contains the ID number of a dialog-box option resource.</param>
    /// <param name="pParentWnd">Points to the Panel to which the dialog object belongs. Cannot be NULL. The control is resized to fit the panel.</param>
    virtual BOOL Create( UINT nIDOption, CWnd* pParentWnd = NULL );

    /// <summary>Sets the visibility state of the control.</summary>
    /// <param name="nCmdShow">Specifies how the control is to be shown.</param>
    /// <returns>Nonzero if the control was previously visible; 0 if the control was previously hidden.</returns>
    virtual BOOL ShowWindow( int nCmdShow );

    /// <summary>(Dis)able the control.</summary>
    /// <param name="enable">Set to true to enable the window and set to false to disable the window</param>
    virtual void EnableWindow( bool enable );

    virtual void SetBackgroundColor( COLORREF colorref );
#pragma endregion

#pragma region Private Methods
protected:
    virtual bool create();

    //void UpdateDataFromControlToParameters();
    //void UpdateDataFromParametersToControl();

    void DataPush();
    void DataPull();

    bool DoRadioExchange( int idc_radio, int& value, bool pull );
    bool DoRadioPull( int idc_radio, int& value );
    bool DoRadioPush( int idc_radio, int value );

    bool DoTextExchange( int idc_textbox, double& value, bool pull );
    bool DoTextPull( int idc_textbox, double& value );
    bool DoTextPush( int idc_textbox, double value );

    virtual void DoDataExchange( CDataExchange* pDX ) override {}
    afx_msg HBRUSH OnCtlColor( CDC* pDC, CWnd* pWnd, UINT nCtlColor );
#pragma endregion

#pragma region Fields
private:
    bool panelBorder;
    CBrush* brushBackground;
#pragma endregion

    DECLARE_MESSAGE_MAP()
};

}
}