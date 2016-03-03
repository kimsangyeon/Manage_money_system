#pragma once


// SDeleteDlg 대화 상자입니다.

class SDeleteDlg : public CDialogEx
{
	DECLARE_DYNAMIC(SDeleteDlg)

public:
	SDeleteDlg(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~SDeleteDlg();

// 대화 상자 데이터입니다.
	enum { IDD = IDD_SDELETE };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	int m_SNO;
	afx_msg void OnBnClickedOk();
};
