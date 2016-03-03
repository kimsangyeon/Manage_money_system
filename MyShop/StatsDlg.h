#pragma once
#include "afxcmn.h"
#include "afxdtctl.h"


// CStatsDlg 대화 상자입니다.

class CStatsDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CStatsDlg)

public:
	CStatsDlg(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~CStatsDlg();

// 대화 상자 데이터입니다.
	enum { IDD = IDD_STATS };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

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
