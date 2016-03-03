#pragma once


// IModifyDataDlg 대화 상자입니다.

class IModifyDataDlg : public CDialogEx
{
	DECLARE_DYNAMIC(IModifyDataDlg)

public:
	IModifyDataDlg(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~IModifyDataDlg();

// 대화 상자 데이터입니다.
	enum { IDD = IDD_IModify };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
	CString m_IMNO;
	CString m_IMPRICE;
	CString m_IMLOCATE;
public:
	afx_msg void OnBnClickedOk();
	virtual BOOL OnInitDialog();
};
