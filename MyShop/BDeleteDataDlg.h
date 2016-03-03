#pragma once


// BDeleteDataDlg 대화 상자입니다.

class BDeleteDataDlg : public CDialogEx
{
	DECLARE_DYNAMIC(BDeleteDataDlg)

public:
	BDeleteDataDlg(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~BDeleteDataDlg();

// 대화 상자 데이터입니다.
	enum { IDD = IDD_DELETE };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()

public:
	afx_msg void OnBnClickedOk();

protected:
	CString m_BNO;
};
