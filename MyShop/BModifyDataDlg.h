#pragma once


// BModifyDataDlg ��ȭ �����Դϴ�.

class BModifyDataDlg : public CDialogEx
{
	DECLARE_DYNAMIC(BModifyDataDlg)

public:
	BModifyDataDlg(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~BModifyDataDlg();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_Modify };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

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
