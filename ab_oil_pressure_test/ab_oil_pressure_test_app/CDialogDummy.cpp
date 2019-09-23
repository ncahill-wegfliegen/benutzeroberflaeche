// CDialogDummy.cpp : implementation file
//

#include "pch.h"
#include "ab_oil_pressure_test_app.h"
#include "CDialogDummy.h"
#include "afxdialogex.h"


// CDialogDummy dialog

IMPLEMENT_DYNAMIC(CDialogDummy, CDialogEx)

CDialogDummy::CDialogDummy(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG_DUMMY, pParent)
{

}

CDialogDummy::~CDialogDummy()
{
}

void CDialogDummy::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange( pDX );
	DDX_Control( pDX, IDC_LIST_SOMETHING, m_listSomething );
}


BEGIN_MESSAGE_MAP(CDialogDummy, CDialogEx)
	ON_LBN_SELCHANGE( IDC_LIST_SOMETHING, &CDialogDummy::OnLbnSelchangeListSomething )
	ON_CBN_SELCHANGE( IDC_COMBO_DUMMY, &CDialogDummy::OnCbnSelchangeComboDummy )
END_MESSAGE_MAP()


// CDialogDummy message handlers


void CDialogDummy::OnLbnSelchangeListSomething()
{
	// TODO: Add your control notification handler code here
}


void CDialogDummy::OnCbnSelchangeComboDummy()
{
	// TODO: Add your control notification handler code here
}
