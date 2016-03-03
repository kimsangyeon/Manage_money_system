#pragma once


// BInsertDataDlg 대화 상자입니다.

class BInsertDataDlg : public CDialogEx
{
	DECLARE_DYNAMIC(BInsertDataDlg)

public:
	BInsertDataDlg(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~BInsertDataDlg();

// 대화 상자 데이터입니다.
	enum { IDD = IDD_INSERT };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()

public:

	afx_msg void OnBnClickedOk();
protected:
	CString m_BNAME;
	CString m_BPRICE;
	CString m_BLOCATE;
};
