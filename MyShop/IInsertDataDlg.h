#pragma once


// IInsertDataDlg ��ȭ �����Դϴ�.

class IInsertDataDlg : public CDialogEx
{
	DECLARE_DYNAMIC(IInsertDataDlg)

public:
	IInsertDataDlg(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~IInsertDataDlg();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_IINSERT };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
	CString m_IPRICE;
	CString m_ILOCATE;
public:
	afx_msg void OnBnClickedOk();
};
