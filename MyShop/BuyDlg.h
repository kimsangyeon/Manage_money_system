#pragma once
#include "afxcmn.h"


// CBuyDlg ��ȭ �����Դϴ�.

class CBuyDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CBuyDlg)

public:
	CBuyDlg(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CBuyDlg();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_EXPENSE };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()

public:
	CListCtrl m_BList;

	int ShowTable();

	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedButton1();
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton4();
	afx_msg void OnBnClickedButton3();
	afx_msg void OnLvnItemchangedList1(NMHDR *pNMHDR, LRESULT *pResult);

public:
	CString m_ENAME;
	CString m_EPRICE;
	CString m_ELOCATE;
	CString m_ENO;
	afx_msg void OnBnClickedButton5();
};
