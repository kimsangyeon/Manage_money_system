#pragma once
#include "afxcmn.h"


// CIncomeDlg ��ȭ �����Դϴ�.

class CIncomeDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CIncomeDlg)

public:
	CIncomeDlg(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CIncomeDlg();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_INCOME };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
public:
	CListCtrl m_IList;

	int ShowTable();
	afx_msg void OnBnClickedButton1();
	virtual BOOL OnInitDialog();
	afx_msg void OnLvnItemchangedList1(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton4();
	
	CString m_EINO;
	CString m_EIPRICE;
	CString m_EILOCATE;
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButton5();
};
