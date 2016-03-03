#pragma once


// BModifyDataDlg 대화 상자입니다.

class BModifyDataDlg : public CDialogEx
{
	DECLARE_DYNAMIC(BModifyDataDlg)

public:
	BModifyDataDlg(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~BModifyDataDlg();

// 대화 상자 데이터입니다.
	enum { IDD = IDD_Modify };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()

public:
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedOk();

protected:
	CString m_BMNO;
	CString m_BMNAME;
	CString m_BMPRICE;
	CString m_BMLOCATE;
};
