#pragma once
#include "afxcmn.h"


// CIncomeDlg 대화 상자입니다.

class CIncomeDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CIncomeDlg)

public:
	CIncomeDlg(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~CIncomeDlg();

// 대화 상자 데이터입니다.
	enum { IDD = IDD_INCOME };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

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
