#pragma once


// IsaveDlg ��ȭ �����Դϴ�.

class IsaveDlg : public CDialogEx
{
	DECLARE_DYNAMIC(IsaveDlg)

public:
	IsaveDlg(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~IsaveDlg();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_ISAVE };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
	CString m_SINO;
	CString m_SIPRICE;
	CString m_SILOCATE;
public:
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedOk();
};
