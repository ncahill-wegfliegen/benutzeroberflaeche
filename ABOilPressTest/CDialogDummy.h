#pragma once


// CDialogDummy dialog

class CDialogDummy : public CDialogEx
{
	DECLARE_DYNAMIC(CDialogDummy)

public:
	CDialogDummy(CWnd* pParent = nullptr);   // standard constructor
	virtual ~CDialogDummy();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_DUMMY };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	CListBox m_listSomething;
	afx_msg void OnLbnSelchangeListSomething();
};
