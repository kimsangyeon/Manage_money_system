#pragma once


// BDeleteDataDlg ��ȭ �����Դϴ�.

class BDeleteDataDlg : public CDialogEx
{
	DECLARE_DYNAMIC(BDeleteDataDlg)

public:
	BDeleteDataDlg(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~BDeleteDataDlg();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_DELETE };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()

public:
	afx_msg void OnBnClickedOk();

protected:
	CString m_BNO;
};
