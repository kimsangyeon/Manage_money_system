#pragma once


// IDeleteDataDlg 대화 상자입니다.

class IDeleteDataDlg : public CDialogEx
{
	DECLARE_DYNAMIC(IDeleteDataDlg)

public:
	IDeleteDataDlg(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~IDeleteDataDlg();

// 대화 상자 데이터입니다.
	enum { IDD = IDD_IDELETE };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
	CString m_INO;
public:
	afx_msg void OnBnClickedOk();
};
