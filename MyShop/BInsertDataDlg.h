#pragma once


// BInsertDataDlg ��ȭ �����Դϴ�.

class BInsertDataDlg : public CDialogEx
{
	DECLARE_DYNAMIC(BInsertDataDlg)

public:
	BInsertDataDlg(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~BInsertDataDlg();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_INSERT };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()

public:

	afx_msg void OnBnClickedOk();
protected:
	CString m_BNAME;
	CString m_BPRICE;
	CString m_BLOCATE;
};
