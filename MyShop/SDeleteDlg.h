#pragma once


// SDeleteDlg ��ȭ �����Դϴ�.

class SDeleteDlg : public CDialogEx
{
	DECLARE_DYNAMIC(SDeleteDlg)

public:
	SDeleteDlg(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~SDeleteDlg();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_SDELETE };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
public:
	int m_SNO;
	afx_msg void OnBnClickedOk();
};
