#pragma once


// CBsaveDlg 대화 상자입니다.

class CBsaveDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CBsaveDlg)

public:
	CBsaveDlg(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~CBsaveDlg();

// 대화 상자 데이터입니다.
	enum { IDD = IDD_BSAVE };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
protected:
	CString m_SBNO;
	CString m_SBNAME;
	CString m_SBPRICE;
	CString m_SBLOCATE;

	CString m_BDAY;
public:
	afx_msg void OnBnClickedOk();
	
};
