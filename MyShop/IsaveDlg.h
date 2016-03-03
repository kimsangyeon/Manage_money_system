#pragma once


// IsaveDlg 대화 상자입니다.

class IsaveDlg : public CDialogEx
{
	DECLARE_DYNAMIC(IsaveDlg)

public:
	IsaveDlg(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~IsaveDlg();

// 대화 상자 데이터입니다.
	enum { IDD = IDD_ISAVE };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
	CString m_SINO;
	CString m_SIPRICE;
	CString m_SILOCATE;
public:
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedOk();
};
