#pragma once
#include "afxcmn.h"
#include "afxdtctl.h"


// CStatsDlg ��ȭ �����Դϴ�.

class CStatsDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CStatsDlg)

public:
	CStatsDlg(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CStatsDlg();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_STATS };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
public:
	CListCtrl m_SList;

public:
	int ShowTable();
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedButton1();
protected:
	CString m_TIncome;
	CString m_TExpense;
	CString m_MONEY;
public:
	afx_msg void OnBnClickedButton2();
	CDateTimeCtrl m_Starttime;
	CDateTimeCtrl m_Endtime;
	afx_msg void OnBnClickedButton3();
};
