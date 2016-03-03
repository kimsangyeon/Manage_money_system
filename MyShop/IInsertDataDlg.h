#pragma once


// IInsertDataDlg 대화 상자입니다.

class IInsertDataDlg : public CDialogEx
{
	DECLARE_DYNAMIC(IInsertDataDlg)

public:
	IInsertDataDlg(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~IInsertDataDlg();

// 대화 상자 데이터입니다.
	enum { IDD = IDD_IINSERT };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
	CString m_IPRICE;
	CString m_ILOCATE;
public:
	afx_msg void OnBnClickedOk();
};
