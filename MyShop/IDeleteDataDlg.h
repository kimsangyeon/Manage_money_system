#pragma once


// IDeleteDataDlg ��ȭ �����Դϴ�.

class IDeleteDataDlg : public CDialogEx
{
	DECLARE_DYNAMIC(IDeleteDataDlg)

public:
	IDeleteDataDlg(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~IDeleteDataDlg();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_IDELETE };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
	CString m_INO;
public:
	afx_msg void OnBnClickedOk();
};
