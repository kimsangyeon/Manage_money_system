#pragma once


// CBsaveDlg ��ȭ �����Դϴ�.

class CBsaveDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CBsaveDlg)

public:
	CBsaveDlg(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CBsaveDlg();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_BSAVE };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

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
